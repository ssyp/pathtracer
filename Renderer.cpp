#include "Renderer.h"

void Renderer::setBackgroundColor(Vector& vec)
{
	backgroundColor = vec;
}

void Renderer::setPathDepth(int n)
{
	pathDepth = n;
}

Vector& Renderer::getBackgroundColor()
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
			Vector vec(
		}
}