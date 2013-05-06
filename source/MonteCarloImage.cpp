#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <assert.h>
#include "MonteCarloImage.h"

MonteCarloImage::MonteCarloImage(const int x, const int y) {
	this->x = x;
	this->y = y;

	pixels = new Vec3<float>[(x + 1) * (y + 1)];
	
}

void MonteCarloImage::add(const int tx, const int ty, const Vec3<float> color) {
	
	pixels[tx * y + ty] += color;
}

Vec3<float> & MonteCarloImage::get(const int tx, const int ty) const {
	return pixels[tx * y + ty];
}

int MonteCarloImage::getHeight() const {
	return y;
}

int MonteCarloImage::getWidth() const {
	return x;
}

MonteCarloImage::~MonteCarloImage() {
	delete [] pixels;
}
