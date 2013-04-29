#ifndef __CONSOLE_H__
#define __CONSOLE_H__

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

class Console {
    private:
        bool running;
		int samples;

		Parser * parser;
		Scene * scene;
		Camera * camera;
		Renderer * renderer;
        SDL_Surface * surfDisplay;

	public:
        Console();
		int execute(std::string sceneN, int iterations, int samplesC, std::string output);

    public:
		bool onInit(std::string sceneN, int iterations, int samplesC);
        void onLoop();
        void onRender();
        void onCleanup();
};

#endif
