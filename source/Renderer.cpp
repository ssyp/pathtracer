#include "Renderer.h"

Renderer::Renderer(int x, int y, int samp) {
	samples = samp;
	curDepth = 0;
	distance = 1;
	mci = new MonteCarloImage(x,y);
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
	for(int k = 0; k < samples; k++) 
	{
		for(int y = 0; y < camera.getDpiY(); ++y) {
			for(int x = 0; x < camera.getDpiX(); ++x) {
				
				Ray ray(camera.genRay(x-camera.getDpiX() / 2, y-camera.getDpiY() / 2, distance));

				Vec3<float> color = pathTrace(ray, scene, 0);
				
				mci->add(x, y, color);
				
			}
		}
		
	}

}

int Renderer::getSamples() const {
	return samples;
}

Vec3<float> Renderer::pathTrace(Ray & ray, Scene & scene, int depth) {
	
	int ind = scene.getIntersection(ray);
	ISurface* surf = scene.getSurface(ind);
	
	float pointRay;
	Vec3<float> normal;

	if(!surf->getIntersection(ray, pointRay, normal)) {
		return backgroundColor;
	}

	if(depth > pathDepth) {
		return Vec3<float>(0,0,0);
	}
		
	Vec3<float> point = ray.eval(pointRay);

	IMaterial* material = surf->getMaterial();

	if(material == 0) return Vec3<float>(0,0,0);

	Vec3<float> newVec = material->interact(ray.direction, point, normal);
	Ray newRay(point, newVec);

	float brdf = material->getBRDF(ray.direction, newRay.direction, normal);
	float cosOmega = normal.dot(newRay.direction);

	Vec3<float> color = pathTrace(newRay, scene, ++depth);

	Vec3<float> finalColor = material->getColor(color * (brdf * cosOmega));
	
	return finalColor;
	
}
