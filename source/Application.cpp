#include "Application.h"
 
Application::Application() {
    surfDisplay = NULL;
	surfTest = NULL;

    running = true;
}

bool Application::onInit() {
    samples=0;
	parser = new Parser();
	parser -> parse("source/Scene1.txt");

	scene = new Scene();
	camera = new Camera(Vec3<float>(-10,-77, 60),Vec3<float>(0, 1, 0), 0.5f, 300, 300, 2, 2); 
	renderer = new Renderer(camera->getDpiX(), camera->getDpiY(), 2);
	
	if(SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        return false;
    }
 
    if((surfDisplay = SDL_SetVideoMode(renderer->mci->getWidth(), renderer->mci->getHeight(), 32, SDL_HWSURFACE | SDL_DOUBLEBUF)) == NULL) {
        return false;
    }
	

	samples=0;
	parser = new Parser();
	parser -> parse("source/Scene1.txt");

	Block blockS, blockCamera, blockRender;

	for (int i = 0; i < parser ->getNumSettingBlocks(); i++) {
		blockS = parser -> getSettingBlock(i);
		if(blockS.surface == "camera")
			blockCamera = blockS;
		else if(blockS.surface == "render")
			blockRender = blockS;
	}

	scene = new Scene();
	camera = new Camera(blockCamera.getVariable("pos").vectorValue,blockCamera.getVariable("focus").vectorValue, blockCamera.getVariable("angle").floatValue, static_cast<int>(blockCamera.getVariable("imagesize").vectorValue.x), static_cast<int>(blockCamera.getVariable("imagesize").vectorValue.y), static_cast<int>(blockCamera.getVariable("realsize").vectorValue.x), static_cast<int>(blockCamera.getVariable("realsize").vectorValue.y)); 
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
	//renderer->mci->save(renderer->getSamples());

    return true;
}

void Application::onCleanup() {
	SDL_FreeSurface(surfTest);
    SDL_FreeSurface(surfDisplay);
	delete parser;
	delete scene;
	delete camera;
	delete renderer;

    SDL_Quit();
}

void Application::onEvent(SDL_Event * Event) {
    if(Event -> type == SDL_QUIT) {
        running = false;
    }
}

int Application::onExecute() {
    if(onInit() == false) {
        return -1;
    }
 
    SDL_Event Event;
 
    while(running) {
        while(SDL_PollEvent(&Event)) {
            onEvent(&Event);
        }
 
        onLoop();
        onRender();
    }
 
    onCleanup();
 
    return 0;
}

void Application::onRender() {
	renderer->render(*camera, *scene);
	samples+=renderer->getSamples();

	for(int x = 0; x < renderer->mci->getWidth(); x++)
		for(int y = 0; y < renderer->mci->getHeight(); y++)
		{
			Vec3<float> color = renderer->mci->get(x,y);
			color *= 255.0f / static_cast<float>(samples);

			color.clamp(0.0,255.0);

			unsigned char * pixel = static_cast<unsigned char *>(surfDisplay->pixels) + y * surfDisplay->pitch + x * surfDisplay->format->BytesPerPixel;
			*pixel++ = static_cast<unsigned char>(color.x);
			*pixel++ = static_cast<unsigned char>(color.y);
			*pixel++ = static_cast<unsigned char>(color.z);
		}

	SDL_Flip(surfDisplay);
}

void Application::onLoop() {}