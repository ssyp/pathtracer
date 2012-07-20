#include "Application.h"
 
Application::Application() {
    surfDisplay = NULL;
	surfTest = NULL;

    running = true;
}

bool Application::onInit() {
    if(SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        return false;
    }
 
    if((surfDisplay = SDL_SetVideoMode(640, 480, 32, SDL_HWSURFACE | SDL_DOUBLEBUF)) == NULL) {
        return false;
    }
	
	parser = new Parser();
	parser -> parse("source/Scene1.txt");

	scene = new Scene();
	camera = new Camera(Vec3<float>(-10, -67, 40),Vec3<float>(0, 1, 0), 0.5f, 400, 400, 10, 10); 
	renderer = new Renderer(camera->getDpiX(), camera->getDpiY(), 10); 

	Block block;
	ISurface * surf;

	MaterialManager::init(*parser);

	for (int i = 0; i < parser ->getNumSurfaceBlocks(); i++) {
		block = parser -> getSurfaceBlock(i);
		surf = Factory::createSurface(block);
		surf -> init(block);
		scene -> addSurface(surf);
	}

	renderer -> setPathDepth(5);
	renderer->setBackgroundColor(Vec3<float>(0.5,0.5,0.5));
	renderer -> render(*camera, *scene);
	renderer->mci->save(renderer->getSamples());

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
 
    SDL_Flip(surfDisplay);
}

void Application::onLoop() {}