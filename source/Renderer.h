#ifndef _RENDERER_H_
#define _RENDERER_H_
#include "Camera.h"
#include "Scene.h"
class Renderer {
	public:
		void setBackgroundColor(Vector& vec);
		void setPathDepth(int n);
		Vector& getBackgroundColor();
		int getPathDepth();
		void render(Camera & camera, Scene & scene);
	private:
		int pathDepth;
		Vector& backgroundColor;
};

#endif