#ifndef _RENDERER_H_
#define _RENDERER_H_
#include "Camera.h"
#include "Scene.h"
#include "vec3.h"
#include "MonteCarloImage.h"
#include "Ray.h"
using namespace Math;

class Renderer {
	public:
		Renderer(int x, int y, int samples);
		
		MonteCarloImage* mci;

		void setPathDepth(int n);
		int getPathDepth() const;

		void setBackgroundColor(const Vec3<float> & vec);
		Vec3<float> getBackgroundColor() const;
		
		void render(Camera & camera, Scene & scene);

		int getSamples() const;
		
		Vec3<float> pathTrace(Ray & ray, Scene & scene, int depth);
	
	private:
		int samples;

		int pathDepth, curDepth, distance;
		
		Vec3<float> backgroundColor;
		
};

#endif
