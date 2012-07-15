#include "MonteCarloImage.h"

MonteCarloImage::MonteCarloImage(int x, int y)
{
	pixels = new Vec3<float>*[y];
	for(int i = 0; i < y; i++) {
		pixels[i] = new Vec3<float>[x];
		for(int j = 0; j < x; j++) {
			pixels[i][j].x = 0; pixels[i][j].y = 0; pixels[i][j].z = 0;
		}
	}
	
}

void MonteCarloImage::add(int x, int y, Vec3<float> color) {
	pixels[y][x] += color;
}

Vec3<float>& MonteCarloImage::get(int x, int y) const {
	return pixels[y][x];
}
