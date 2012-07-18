#ifndef __APP_H__
#define __APP_H__
 
#include "SDL.h"
#include "Surface.h"
#include "Parser.h"
#include "ISurface.h"
#include "Scene.h"
#include "Camera.h"
#include "Renderer.h"
#include "SurfaceFactory.h"

class Application {
    private:
        bool Running;
		
		Parser * parser;
		SurfaceFactory * surfaceFactory;
		Scene * scene;
		Camera * camera;
		Renderer * renderer;

        SDL_Surface* Surf_Display;
 
        SDL_Surface* Surf_Test;
 
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
