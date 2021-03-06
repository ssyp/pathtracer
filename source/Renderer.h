#ifndef _RENDERER_H_
#define _RENDERER_H_

#include "Camera.h"
#include "Scene.h"
#include "Vec3.h"
#include "MonteCarloImage.h"
#include "Ray.h"

class IBackground;

using namespace Math;

class Renderer {
	public:
		Renderer(const int x, const int y, const int samples);
		
		MonteCarloImage* mci;

		void setPathDepth(const int n);
		int getPathDepth() const;

		void setBackgroundColor(const Vec3<float> & vec);
		Vec3<float> getBackgroundColor() const;

		void setBackground(IBackground * bg);

		void render(Camera & camera, Scene & scene);

		int getSamples() const;
		
		Vec3<float> pathTrace(Ray & ray, Scene & scene, int depth);
	
	private:
		int samples;

		int pathDepth, curDepth, distance;

		IBackground * background;
		
		Vec3<float> backgroundColor;
		
};

#endif
