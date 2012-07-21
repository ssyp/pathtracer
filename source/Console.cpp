#include "Console.h"

/*void Console::parseStr(int n, char** str) {
	std::string sceneN, output;
	float iterations, samples;
	char* sceneC = "--scene";
	char* iterationsC = "--iterations";
	char* samplesC = "--samples";
	char* outputC = "--output";
	for(int i = 0; i < n; i++) {
		if(str[i] == sceneC) {
			sceneN = str[i + 1];
			sceneN = sceneN.substr(1, (sceneN.length() - 2));
		}
		else if(str[i] == iterationsC) 
			iterations = static_cast<float>(atof(str[i + 1]));
		else if(str[i] == samplesC) 
			samples = static_cast<float>(atof(str[i + 1]));
		else if(str[i] == outputC) {
			output = str[i + 1];
			output = output.substr(1, (output.length() - 2));
		}
	}
	consoleInit();
}*/

int Console::consoleInit() {
	samples = 0;
	parser = new Parser();
	parser->parse("scenes/Stable.scene");

	Block blockS, blockCamera, blockRender;

	for (int i = 0; i < parser ->getNumSettingBlocks(); i++) {
		blockS = parser -> getSettingBlock(i);
		if(blockS.surface == "camera")
			blockCamera = blockS;
		else if(blockS.surface == "render")
			blockRender = blockS;
	}

	scene = new Scene();
	camera = new Camera(blockCamera.getVariable("pos").vectorValue,blockCamera.getVariable("focus").vectorValue, radian(blockCamera.getVariable("angle").floatValue), static_cast<int>(blockCamera.getVariable("imagesize").vectorValue.x), static_cast<int>(blockCamera.getVariable("imagesize").vectorValue.y), static_cast<int>(blockCamera.getVariable("realsize").vectorValue.x), static_cast<int>(blockCamera.getVariable("realsize").vectorValue.y)); 
	renderer = new Renderer(camera->getDpiX(), camera->getDpiY(), static_cast<int>(blockRender.getVariable("samplesPerIteration").floatValue)); 
		
	Block block;
	ISurface * surf;

	MaterialManager::init(*parser);

	for (int i = 0; i < parser ->getNumSurfaceBlocks(); i++) {
		block = parser -> getSurfaceBlock(i);
		surf = Factory::createSurface(block);
		surf -> init(block);
		scene -> addSurface(surf);
	}

	renderer->setPathDepth(5);
	renderer->setBackgroundColor(getColor(blockRender.getVariable("backgroundColor").vectorValue));

	for(int i = 0; i < 10; i++) {
		renderer->render(*camera, *scene);
		samples+=renderer->getSamples();
	}

	renderer->mci->save(samples,"source/test.bmp");

	delete parser;
	delete scene;
	delete camera;
	delete renderer;
	return 0;
}