#include "Console.h"
#include "MaterialManager.h"

Console::Console() {
    surfDisplay = NULL;

    running = true;
}

bool Console::onInit(std::string sceneN, int iterations, int samplesC) {
    samples = samplesC;
	parser = new Parser();
	parser->parse(sceneN);

	Block blockS, blockCamera, blockRender;
 
	for (int i = 0; i < parser->getNumSettingBlocks(); i++) {
		blockS = parser->getSettingBlock(i);
		if(blockS.surface == "camera")
			blockCamera = blockS;
		else if(blockS.surface == "render")
			blockRender = blockS;
	}

	scene = new Scene();
	camera = new Camera(blockCamera.getVariable("pos").vectorValue, blockCamera.getVariable("focus").vectorValue, radian(blockCamera.getVariable("angle").floatValue), static_cast<int>(blockCamera.getVariable("imagesize").vectorValue.x), static_cast<int>(blockCamera.getVariable("imagesize").vectorValue.y), static_cast<int>(blockCamera.getVariable("realsize").vectorValue.x), static_cast<int>(blockCamera.getVariable("realsize").vectorValue.y)); 
	renderer = new Renderer(camera->getDpiX(), camera->getDpiY(), iterations); 
	
	/*if(SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        return false;
    }*/
	
    if((surfDisplay = SDL_CreateRGBSurface(SDL_HWSURFACE, renderer->mci->getWidth(), renderer->mci->getHeight(), 32, 0xFF0000, 0x00FF00, 0x0000FF, 0)) == NULL) {
    //if((surfDisplay = SDL_SetVideoMode(renderer->mci->getWidth(), renderer->mci->getHeight(), 32, SDL_HWSURFACE | SDL_DOUBLEBUF)) == NULL) {
        return false;
    }

	Block block;
	ISurface * surf;

	MaterialManager::init(*parser);

	for (int i = 0; i < parser->getNumSurfaceBlocks(); i++) {
		block = parser->getSurfaceBlock(i);
		surf = Factory::createSurface(block);
		surf->init(block);
		scene->addSurface(surf);
	}

	renderer->setPathDepth(10);
	renderer->setBackgroundColor(getColor(blockRender.getVariable("backgroundColor").vectorValue));

    return true;
}

int Console::execute(std::string sceneN, int iterations, int samplesC, std::string output) {
    if(onInit(sceneN, iterations, samplesC ) == false) {
        return -1;
    }

    for(int i = 0; i < iterations; i++) {
        onRender();
    }

    SDL_SaveBMP(surfDisplay, output.c_str());

    onCleanup();

    return 0;
}

void Console::onCleanup() {
    SDL_FreeSurface(surfDisplay);
	delete parser;
	delete scene;
	delete camera;
	delete renderer;

    SDL_Quit();
}

void Console::onRender() {
	renderer->render(*camera, *scene);
	samples += renderer->getSamples();

	for(int x = 0; x < renderer->mci->getWidth(); x++)
		for(int y = 0; y < renderer->mci->getHeight(); y++)
		{
			Vec3<float> color = renderer->mci->get(x,y);
			color *= 255.0f / static_cast<float>(samples);

			color.clamp(0.0, 255.0);

			unsigned char * pixel = static_cast<unsigned char *>(surfDisplay->pixels) + y * surfDisplay->pitch + x * surfDisplay->format->BytesPerPixel;
			*pixel++ = static_cast<unsigned char>(color.x);
			*pixel++ = static_cast<unsigned char>(color.y);
			*pixel++ = static_cast<unsigned char>(color.z);
		}
}

