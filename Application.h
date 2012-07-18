#ifndef __APP_H__
#define __APP_H__
 
#include "SDL.h"
#include "Surface.h"
 
class Application {
    private:
        bool            Running;
 
        SDL_Surface*    Surf_Display;
 
        SDL_Surface*    Surf_Test;
 
    public:
        Application();
 
        int OnExecute();
 
    public:
        bool OnInit();
 
        void OnEvent(SDL_Event* Event);
 
        void OnLoop();
 
        void OnRender();
 
        void OnCleanup();
};

#endif
