#include "Renderer.h"
#include "MathUtils.h"

Renderer::Renderer(const int x, const int y, const int samp) {
	samples = samp;
	curDepth = 0;
	distance = 1;
	mci = new MonteCarloImage(x,y);
}

void Renderer::setBackgroundColor(const Vec3<float>& vec) {
	backgroundColor = vec;
}

void Renderer::setPathDepth(const int n) {
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
				
				Ray ray(camera.genRay(x-camera.getDpiX() / 2, camera.getDpiY() / 2 - y));

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

	ISurface* surf;
	float pointRay;
	Vec3<float> normal;

	if(!scene.getIntersection(ray, surf, pointRay, normal)) {
		return backgroundColor;
	}

	if(depth > pathDepth) {
		return Vec3<float>(0, 0, 0);
	}

	Vec3<float> point = ray.eval(pointRay);

	IMaterial* material = surf->getMaterial();

	if(material == NULL) return Vec3<float>(0, 0, 0);

	Vec3<float> newVec = material->interact(ray.direction, point, normal);
	Ray newRay(point, newVec);

	newRay.prevSurface = surf;

	float brdf = material->getBRDF(ray.direction, newRay.direction, normal);

	Vec3<float> color = pathTrace(newRay, scene, ++depth);
	Vec3<float> finalColor = material->getColor(color * brdf, newRay.position);
	
	return finalColor;
}
