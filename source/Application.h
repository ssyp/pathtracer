#ifndef __APP_H__
#define __APP_H__

#if (defined __linux__)
#include <SDL/SDL.h>
#elif (defined _WIN32)
#include "SDL.h"
#endif

#include "Parser.h"
#include "ISurface.h"
#include "Scene.h"
#include "Camera.h"
#include "Renderer.h"
#include "Factory.h"

class Application {
    private:
        bool running;
		int samples;

		Parser * parser;
		Scene * scene;
		Camera * camera;
		Renderer * renderer;
        SDL_Surface * surfDisplay;
        SDL_Surface * surfTest;

    public:
        Application();
        int onExecute();
 
    public:
        bool onInit();
        void onEvent(SDL_Event * Event);
        void onLoop();
        void onRender();
        void onCleanup();
};

#endif
