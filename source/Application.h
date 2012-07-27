#ifndef __APP_H__
#define __APP_H__
 
#include "SDL.h"

#include "Parser.h"
#include "ISurface.h"
#include "Scene.h"
#include "Camera.h"
#include "Renderer.h"
#include "Factory.h"
#include "IBackground.h"

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

		IBackground * background;

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
