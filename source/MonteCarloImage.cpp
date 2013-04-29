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

void MonteCarloImage::save(const int samp, const std::string & path) const
{
/*	std::ofstream f(path.c_str, std::ios::out | std::ios::binary);

	unsigned char *img = NULL;
	int w = x, h = y;
	int filesize = 54 + 3 * w * h;

	img = new unsigned char[3 * w * h];
	for(int i = 0; i < 3 * w * h; i++)
		img[i] = 0;

	for(int i = 0; i < w; i++) {
		for(int j = 0; j < h; j++) {
			Vec3<float> color(pixels[i * w + j].x * (255.0f / static_cast<float>(samp)), pixels[i * w + j].y * (255.0f / static_cast<float>(samp)), pixels[i * w + j].z * (255.0f / static_cast<float>(samp)));
			color.clamp(0.0,255.0);
			img[(i + j * w) * 3 + 2] = static_cast<unsigned char>(color.x);
			img[(i + j * w) * 3 + 1] = static_cast<unsigned char>(color.y);
			img[(i + j * w) * 3 + 0] = static_cast<unsigned char>(color.z);
		}
	}

	unsigned char bmpfileheader[14] = {'B', 'M', 0, 0, 0, 0, 0, 0, 0, 0, 54, 0, 0, 0};
	unsigned char bmpinfoheader[40] = {40, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 24, 0};
	unsigned char bmppad[3] = {0, 0, 0};

	bmpfileheader[2] = static_cast<unsigned char>(filesize);
	bmpfileheader[3] = static_cast<unsigned char>(filesize >> 8);
	bmpfileheader[4] = static_cast<unsigned char>(filesize >> 16);
	bmpfileheader[5] = static_cast<unsigned char>(filesize >> 24);

	bmpinfoheader[4] = static_cast<unsigned char>(w);
	bmpinfoheader[5] = static_cast<unsigned char>(w >> 8);
	bmpinfoheader[6] = static_cast<unsigned char>(w >> 16);
	bmpinfoheader[7] = static_cast<unsigned char>(w >> 24);
	bmpinfoheader[8] = static_cast<unsigned char>(h);
	bmpinfoheader[9] = static_cast<unsigned char>(h >> 8);
	bmpinfoheader[10] = static_cast<unsigned char>(h >> 16);
	bmpinfoheader[11] = static_cast<unsigned char>(h >> 24);

	f.write(reinterpret_cast<const char*>(bmpfileheader), 14);
	f.write(reinterpret_cast<const char*>(bmpinfoheader), 40);
	for(int i = 0; i < h; i++)
	{
		f.write(reinterpret_cast<const char*>(img + (w * (h - i - 1) * 3)),3*w);
		f.write(reinterpret_cast<const char*>(bmppad), (4 - (w * 3) % 4) % 4);
	}
	f.close();
*/
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
