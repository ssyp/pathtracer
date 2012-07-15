#ifndef _RENDERER_H_
#define _RENDERER_H_
#include "Camera.h"
#include "Scene.h"
#include "vec3.h"
#include "MonteCarloImage.h"
class Renderer {
	public:
		Renderer(int x, int y);
		void setBackgroundColor(Vec3<float> & vec);
		void setPathDepth(int n);
		Vec3<float> getBackgroundColor() const;
		int getPathDepth() const;
		void render(Camera & camera, Scene & scene);
		int getSamples() const;
		Vec3<float> pathTrace(Ray & ray, Scene & scene, Vec3<float> & color);
	
	private:
		int brdf(Vec3<float> & v1, Vec3<float> & v2);
		int samples;
		int pathDepth, curDepth, distance;
		Vec3<float> backgroundColor;
		MonteCarloImage* mci;
};

#endif
