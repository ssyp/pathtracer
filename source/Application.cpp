#include "Application.h"
 
Application::Application() {
    Surf_Display = NULL;
	Surf_Test = NULL;
    
    Running = true;
}

bool Application::OnInit() {
    if(SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        return false;
    }
 
    if((Surf_Display = SDL_SetVideoMode(640, 480, 32, SDL_HWSURFACE | SDL_DOUBLEBUF)) == NULL) {
        return false;
    }

	if((Surf_Test = Surface::OnLoad("img.bmp")) == NULL) {
        return false;
    }
 
    return true;
}

void Application::OnCleanup() {
	SDL_FreeSurface(Surf_Test);
    SDL_FreeSurface(Surf_Display);
    SDL_Quit();
}

void Application::OnEvent(SDL_Event* Event) {
    if(Event->type == SDL_QUIT) {
        Running = false;
    }
}

int Application::OnExecute() {
    if(OnInit() == false) {
        return -1;
    }
 
    SDL_Event Event;
 
    while(Running) {
        while(SDL_PollEvent(&Event)) {
            OnEvent(&Event);
        }
 
        OnLoop();
        OnRender();
    }
 
    OnCleanup();
 
    return 0;
}

void Application::OnRender() {
	Surface::OnDraw(Surf_Display, Surf_Test, 0, 0);
 
    SDL_Flip(Surf_Display);
}

void Application::OnLoop() {}