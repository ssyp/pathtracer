#include "MonteCarloImage.h"
#include <cstdio>
#include <cstdlib>
#include <fstream>

MonteCarloImage::MonteCarloImage(int x, int y) {

	this->x = x;
	this->y = y;

	pixels = new Vec3<float>*[y];

	for(int i = 0; i < y; i++) {
		
		pixels[i] = new Vec3<float>[x];
		
	}
	
}

void MonteCarloImage::add(int x, int y, Vec3<float> color) {
	pixels[y][x] += color;
}

Vec3<float> & MonteCarloImage::get(int x, int y) const {
	return pixels[y][x];
}

void MonteCarloImage::save() const {
	
	FILE *f;
	unsigned char *img = NULL;
	int w = x, h = y;
	int filesize = 54 + 3*w*h;  //w is your image width, h is image height, both int
	if( img )
		free( img );
	img = (unsigned char *)malloc(3*w*h);
	memset(img,0,sizeof(img));

	for(int i=0; i<w; i++) {
		for(int j=0; j<h; j++) {
			//x=i; y=(yres-1)-j;
			int r = static_cast<int>(pixels[i][j].x * 255);
			int g = static_cast<int>(pixels[i][j].y * 255);
			int b = static_cast<int>(pixels[i][j].z * 255);
			if (r > 255) r = 255;
			if (g > 255) g = 255;
			if (b > 255) b = 255;
			img[(i+j*w)*3+2] = (unsigned char)(r);
			img[(i+j*w)*3+1] = (unsigned char)(g);
			img[(i+j*w)*3+0] = (unsigned char)(b);
		}
	}

	unsigned char bmpfileheader[14] = {'B','M', 0,0,0,0, 0,0, 0,0, 54,0,0,0};
	unsigned char bmpinfoheader[40] = {40,0,0,0, 0,0,0,0, 0,0,0,0, 1,0, 24,0};
	unsigned char bmppad[3] = {0,0,0};

	bmpfileheader[ 2] = (unsigned char)(filesize    );
	bmpfileheader[ 3] = (unsigned char)(filesize>> 8);
	bmpfileheader[ 4] = (unsigned char)(filesize>>16);
	bmpfileheader[ 5] = (unsigned char)(filesize>>24);

	bmpinfoheader[ 4] = (unsigned char)(       w    );
	bmpinfoheader[ 5] = (unsigned char)(       w>> 8);
	bmpinfoheader[ 6] = (unsigned char)(       w>>16);
	bmpinfoheader[ 7] = (unsigned char)(       w>>24);
	bmpinfoheader[ 8] = (unsigned char)(       h    );
	bmpinfoheader[ 9] = (unsigned char)(       h>> 8);
	bmpinfoheader[10] = (unsigned char)(       h>>16);
	bmpinfoheader[11] = (unsigned char)(       h>>24);

	f = fopen("img.bmp","wb");
	fwrite(bmpfileheader,1,14,f);
	fwrite(bmpinfoheader,1,40,f);
	for(int i=0; i<h; i++)
	{
		fwrite(img + (w * (h - i - 1) * 3), 3, w, f);
		fwrite(bmppad, 1, (4 - (w * 3) % 4) % 4, f);
	}
	fclose(f);

}

void MonteCarloImage::save_cpp() const
{
	std::ofstream f("img.bmp", std::ios::out | std::ios::binary);
	//FILE *f;
	unsigned char *img = NULL;
	int w = x, h = y;
	int filesize = 54 + 3*w*h;  //w is your image width, h is image height, both int
	
	//if( img )
	//	free( img );
	img = new unsigned char[3*w*h];
	for(int i = 0; i < 3*w*h; i++)
		img[i] = 0;
	//memset(img,0,sizeof(img));

	for(int i=0; i<w; i++) {
		for(int j=0; j<h; j++) {
			//x=i; y=(yres-1)-j;
			int r = static_cast<int>(pixels[i][j].x * 255);
			int g = static_cast<int>(pixels[i][j].y * 255);
			int b = static_cast<int>(pixels[i][j].z * 255);
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

	//f = fopen("img.bmp","wb");
	//fwrite(bmpfileheader,1,14,f);
	//fwrite(bmpinfoheader,1,40,f);
	f.write(reinterpret_cast<const char*>(bmpfileheader),14);
	f.write(reinterpret_cast<const char*>(bmpinfoheader),40);
	for(int i = 0; i < h; i++)
	{
		f.write(reinterpret_cast<const char*>(img + (w * (h - i - 1) * 3)),w);
		f.write(reinterpret_cast<const char*>(bmppad), (4 - (w * 3) % 4) % 4);
		// << bmppad;
		//fwrite(img + (w * (h - i - 1) * 3), 3, w, f);
		//fwrite(bmppad, 1, (4 - (w * 3) % 4) % 4, f);
	}
	f.close();
}

MonteCarloImage::~MonteCarloImage()
{
	for(int i = 0; i < y; i++)
		delete pixels[y];

	delete pixels;
}
