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

	if((surfTest = Surface::OnLoad("img.bmp")) == NULL) {
        return false;
    }
	
	parser = new Parser();
	parser -> parse("Scene1.txt");

	surfaceFactory = new SurfaceFactory(); 
	scene = new Scene();
	camera = new Camera(Vec3<float>(0, 0, 0),Vec3<float>(0, 0, 1), 0.5f, 640, 480); 
	renderer = new Renderer(camera->getDpiX(), camera->getDpiY(), 100); 


	Block block;
	ISurface * surf;

	for (int i = 0; i < parser -> getNumBlocks(); i++) {
		block = parser -> getBlock(i);
		surf = surfaceFactory -> createSurface(block);
		surf -> init(block);
		scene -> addSurface(surf);
	}
	renderer -> render(*camera, *scene);

    return true;
}

void Application::onCleanup() {
	SDL_FreeSurface(surfTest);
    SDL_FreeSurface(surfDisplay);
	delete parser;
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
	Surface::OnDraw(surfDisplay, surfTest, 0, 0);
 
    SDL_Flip(surfDisplay);
}

void Application::onLoop() {}