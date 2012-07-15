#include "Renderer.h"

Renderer::Renderer()
{
	samples = 0;
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
			Ray<float> ray(camera.getPos(), camera.getDir().normalize());
			scene.push(ray);
			samples++;
		}
}

int Renderer::getSamples()
{
	return samples;
}

Vec3<float> pathTrace(Ray & ray, Scene & scene)
{
	Vec3<float> point;
	if(scene.getIntersection(ray, &point))
	{
		
	}
	else {
		return Vec3<float>(0,0,0);
	}
	
}
