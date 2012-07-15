#include "Renderer.h"
#include "Ray.h"
Renderer::Renderer()
{
	samples = 0;
	curDepth = 0;
	distance = 1;
	mci = new MonteCarloImage();
}

void Renderer::setBackgroundColor(Vec3<float>& vec)
{
	backgroundColor = vec;
}

void Renderer::setPathDepth(int n)
{
	pathDepth = n;
}

Vec3<float>& Renderer::getBackgroundColor()
{
	return backgroundColor;
}

int Renderer::getPathDepth()
{
	return pathDepth;
}

void Renderer::render(Camera & camera, Scene & scene)
{
	for(int y = 0; y < camera.getDpiY(); y++)
		for(int x = 0; x < camera.getDpiX(); x++)
		{
			vec3 curVec(x,y,distance);
			Ray ray(camera.getPos(), curVec);
			Vec3 color = pathTrace(ray, scene);
			mci->add(y,x,color);
			samples++;
		}
}

int Renderer::getSamples()
{
	return samples;
}

Vec3<float> pathTrace(Ray & ray, Scene & scene)
{
	if(curDepth > pathDepth)
	{
		curDepth = 0;
		return Vec3<float>(0,0,0);
	}
	Vec3<float> point;
	ISurface* surf = scene.getSurface(ray);
	if(surf->getIntersection(ray, &point))
	{
		Vec3<float> normal = surf->getNormal(point);
		float x = (rand()%normal.x)/100, y = (rand()%normal.y)/100, z = sqrt(1 - x*x - y*y);
		Vec3<float> randVec(x, y, z);
		Ray ray(point, randVec);
		pathTrace(ray,scene);
		curDepth++;
	}
	else {
		curDepth = 0;
		return Vec3<float>(0,0,0);
	}
	
}
