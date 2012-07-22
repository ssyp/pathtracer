#include "SkyMaterial.h"
#include "MathUtils.h"
#include <fstream>
#include <algorithm>
#include <cmath>

float SkyMaterial::getBRDF(const Vec3<float> & in, const Vec3<float> & out, const Vec3<float> & n) const {
	return 1.0f;
}

Vec3<float> SkyMaterial::getColor(const Vec3<float> & color, const Vec3<float> & point) {
	return getTextureColor(static_cast<int>(point.x)+1500,static_cast<int>(point.y)+1500)*0.2f;
}

Vec3<float> SkyMaterial::interact(const Vec3<float> & in, const Vec3<float> & ip, const Vec3<float> & n) const {
	return Vec3<float>(0,0,1);
}

void SkyMaterial::init(const Block & block) {
	file = "Debug/_sky.bmp"; //block.getVariable("file").stringValue;
	surf = SDL_LoadBMP(file.c_str());
	//if(surf == NULL) 
};

Vec3<float> SkyMaterial::getTextureColor(const int x, const int y)
{
	Vec3<float> color;
	Uint32 pix=0;
	SDL_LockSurface(surf);
	SDL_LockSurface(surf);
	pix = getPixel(surf, x, y);
	SDL_UnlockSurface(surf);
	Uint8 r, g, b;
	SDL_GetRGB(pix, surf->format, &r, &g, &b);
	color.x = static_cast<float>(r);
	color.y = static_cast<float>(g);
	color.z = static_cast<float>(b);
	return color;
}

Uint32 SkyMaterial::getPixel(SDL_Surface *surface, int x, int y) {
    Uint8 *p;
     
    if(!surface->pixels) return 0;
     
    p = static_cast<Uint8 *>(surface->pixels)
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