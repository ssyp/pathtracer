#ifndef __CONSOLE_H__
#define __CONSOLE_H__

#include "Parser.h"
#include "ISurface.h"
#include "Scene.h"
#include "Camera.h"
#include "Renderer.h"
#include "Factory.h"

class Console {
    private:
		int samples;
		Parser * parser;
		Scene * scene;
		Camera * camera;
		Renderer * renderer;
	public:
		/*void parseStr(int n, char** str);*/
		int consoleInit();
};

#endif
