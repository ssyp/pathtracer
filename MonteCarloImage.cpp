#include "MonteCarloImage.h"

MonteCarloImage::MonteCarloImage(int x, int y)
{
	pixels = new Vector*[y];
	for(int i = 0; i < y; i++)
		pixels[i] = new Vector[x];
}

void MonteCarloImage::add(int x, int y, Vector& color)
{
	pixels[y][x] = color;
}

Vector& MonteCarloImage::get(int x, int y) const
{
	return pixels[y][x];
}