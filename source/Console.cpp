#include "Console.h"
#include "MaterialManager.h"

int Console::consoleInit(std::string sceneN, int iterations, int samplesC, std::string output) {
	samples = samplesC;
	parser = new Parser();
	parser->parse(sceneN);

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

	for(int i = 0; i < iterations; i++) {
		renderer->render(*camera, *scene);
		samples+=renderer->getSamples();
	}

	renderer->mci->save(samples, output);

	delete parser;
	delete scene;
	delete camera;
	delete renderer;
	return 0;
}