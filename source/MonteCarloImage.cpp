#include "MonteCarloImage.h"
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <assert.h>
MonteCarloImage::MonteCarloImage(int x, int y) {
	this->x = x;
	this->y = y;

	pixels = new Vec3<float>*[x];

	for(int i = 0; i < x; i++) {
		
		pixels[i] = new Vec3<float>[y];
		
	}
	
}

void MonteCarloImage::add(int tx, int ty, Vec3<float> color) {
	
	pixels[tx][ty] = pixels[tx][ty] + color;
}

Vec3<float> & MonteCarloImage::get(int tx, int ty) const {
	return pixels[tx][ty];
}

void MonteCarloImage::save(int samp) const
{
	std::ofstream f("Debug/img.bmp", std::ios::out | std::ios::binary);

	unsigned char *img = NULL;
	int w = x, h = y;
	int filesize = 54 + 3*w*h;

	img = new unsigned char[3*w*h];
	for(int i = 0; i < 3*w*h; i++)
		img[i] = 0;

	for(int i = 0; i < w; i++) {
		for(int j = 0; j < h; j++) {
			float r = static_cast<float>(pixels[i][j].x / static_cast<float>(samp * 255));
			float g = static_cast<float>(pixels[i][j].y / static_cast<float>(samp * 255));
			float b = static_cast<float>(pixels[i][j].z / static_cast<float>(samp * 255));
			if (r > 255) r = 255;
			if (g > 255) g = 255;
			if (b > 255) b = 255;
			img[(i+j*w)*3+2] = static_cast<unsigned char>(r);
			img[(i+j*w)*3+1] = static_cast<unsigned char>(g);
			img[(i+j*w)*3+0] = static_cast<unsigned char>(b);
		}
	}

	unsigned char bmpfileheader[14] = {'B','M', 0,0,0,0, 0,0, 0,0, 54,0,0,0};
	unsigned char bmpinfoheader[40] = {40,0,0,0, 0,0,0,0, 0,0,0,0, 1,0, 24,0};
	unsigned char bmppad[3] = {0,0,0};

	bmpfileheader[ 2] = static_cast<unsigned char>(filesize    );
	bmpfileheader[ 3] = static_cast<unsigned char>(filesize>> 8);
	bmpfileheader[ 4] = static_cast<unsigned char>(filesize>>16);
	bmpfileheader[ 5] = static_cast<unsigned char>(filesize>>24);

	bmpinfoheader[ 4] = static_cast<unsigned char>(       w    );
	bmpinfoheader[ 5] = static_cast<unsigned char>(       w>> 8);
	bmpinfoheader[ 6] = static_cast<unsigned char>(       w>>16);
	bmpinfoheader[ 7] = static_cast<unsigned char>(       w>>24);
	bmpinfoheader[ 8] = static_cast<unsigned char>(       h    );
	bmpinfoheader[ 9] = static_cast<unsigned char>(       h>> 8);
	bmpinfoheader[10] = static_cast<unsigned char>(       h>>16);
	bmpinfoheader[11] = static_cast<unsigned char>(       h>>24);

	f.write(reinterpret_cast<const char*>(bmpfileheader), 14);
	f.write(reinterpret_cast<const char*>(bmpinfoheader), 40);
	for(int i = 0; i < h; i++)
	{
		f.write(reinterpret_cast<const char*>(img + (w * (h - i - 1) * 3)),3*w);
		f.write(reinterpret_cast<const char*>(bmppad), (4 - (w * 3) % 4) % 4);
	}
	f.close();
}

int MonteCarloImage::getHeight() const
{
	return y;
}

int MonteCarloImage::getWidth() const
{
	return x;
}

MonteCarloImage::~MonteCarloImage()
{
	for(int i = 0; i < x; i++)
		delete [] pixels[i];

	delete [] pixels;
}
