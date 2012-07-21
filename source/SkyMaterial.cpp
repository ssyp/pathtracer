#include "SkyMaterial.h"
#include "MathUtils.h"
#include <fstream>
#include <algorithm>
#include <cmath>

float SkyMaterial::getBRDF(const Vec3<float> & in, const Vec3<float> & out, const Vec3<float> & n) const {
	return 1.0f;
}

Vec3<float> SkyMaterial::getColor(const Vec3<float> & color, const Vec3<float> & point) {
	return getTextureColor(static_cast<int>(point.x),static_cast<int>(point.x));
}

Vec3<float> SkyMaterial::interact(const Vec3<float> & in, const Vec3<float> & ip, const Vec3<float> & n) const {
	return getRandomPointOnHemisphere(n);
}

void SkyMaterial::init(const Block & block) {
	file = block.getVariable("file").stringValue;
	surf1 = NULL;
	surf1 = SDL_LoadBMP(file.c_str());
	//if(surf1 == NULL) 
	surf = SDL_DisplayFormat(surf1);
	SDL_FreeSurface(surf1);
};

Vec3<float> SkyMaterial::getTextureColor(const int x, const int y)
{
	Vec3<float> color;
	Uint32 pix = getPixel(surf, x, y);
	std::string binPix = toBin(pix);
	color.x = getBinColor(binPix.substr(0,8));
	color.y = getBinColor(binPix.substr(8,8));
	color.z = getBinColor(binPix.substr(16,8));
	return color;
}

float SkyMaterial::getBinColor(std::string & str) {
	int col = 0;
	for(int i = 0; i < str.size(); i++) {
		if(str[i] == '1') {
			col += pow(2.0, (int)str.size() - i - 1);
		}
	}
	col /= 255.0f;
	return col;
}

Uint32 SkyMaterial::getPixel(SDL_Surface *surface, int x, int y) {
    Uint8 *p;
     
    if(!surface->pixels) return 0;
     
    p = (Uint8 *)surface->pixels
        + y * surface->pitch
        + x * surface->format->BytesPerPixel;
     
    if(x < 0 || y < 0 || x >= surface->w || y >= surface->h) return 0;
 
    switch(surface->format->BytesPerPixel) {
    case 1:
        return *p;
    case 2:
        return *(Uint16 *)p;
    case 3:
        if(SDL_BYTEORDER == SDL_BIG_ENDIAN) {
            return p[0] << 16 | p[1] << 8 | p[2];
        }
        else return p[0] | p[1] << 8 | p[2] << 16;
    case 4:
        return *(Uint32 *)p;
    default:
        return 0;
    }
}

std::string SkyMaterial::toBin(Uint32 n) {
	std::string rez="";
	while(n) {
		(n % 2 == 0) ? rez += '0' : rez += '1';
		n /= 2;
	}
	while(rez.size() != 32) {
		rez += '0';
	}
	std::reverse(rez.begin(), rez.end());
	return rez;
}