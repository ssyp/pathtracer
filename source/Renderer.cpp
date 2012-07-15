#include "Renderer.h"
#include "Ray.h"
Renderer::Renderer(int x, int y) {
	samples = 0;
	curDepth = 0;
	distance = 1;
	mci = new MonteCarloImage(x,y);
	//backgroundColor = NULL;
}

void Renderer::setBackgroundColor(Vec3<float>& vec) {
	backgroundColor = vec;
}

void Renderer::setPathDepth(int n) {
	pathDepth = n;
}

Vec3<float> Renderer::getBackgroundColor() const {
	return backgroundColor;
}

int Renderer::getPathDepth() const {
	return pathDepth;
}

void Renderer::render(Camera & camera, Scene & scene) {
	for(int y = 0; y < camera.getDpiY(); y++)
		for(int x = 0; x < camera.getDpiX(); x++) {
			Vec3<float> curVec(x,y,distance);
			Ray ray(camera.getPos(), curVec);
			Vec3<float> color = pathTrace(ray, scene);
			mci->add(y,x,color);
			samples++;
		}
}

int Renderer::getSamples() const {
	return samples;
}

Vec3<float> Renderer::pathTrace(Ray & ray, Scene & scene) {
	if(curDepth > pathDepth) {
		curDepth = 0;
		return Vec3<float>(0, 0, 0);
	}
	float pointRay;
	int ind = scene.getIntersection(ray);
	ISurface* surf = scene.getSurface(ind);
	
	if(surf->getIntersection(ray, pointRay)) {
		Vec3<float> point = ray.eval(pointRay);
		Vec3<float> normal = surf->getNormal(point);
		float x = (rand() % static_cast<int>(normal.x)) / 100, y = (rand() % static_cast<int>(normal.y)) / 100, z = sqrt(1 - x * x - y * y);
		Vec3<float> randVec(x, y, z);
		
		
		Ray randRay(point,randVec);
		pathTrace(randRay,scene);
		curDepth++;
	}
	else {
		curDepth = 0;
		return Vec3<float>(0, 0, 0);
	}
	
}
