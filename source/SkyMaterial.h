#ifndef __SKYMATERIAL_H__
#define __SKYMATERIAL_H__

#include "IMaterial.h"
#include "Block.h"
#include <string>
#include "SDL.h"

class SkyMaterial : public IMaterial {
	public:
		float getBRDF(const Vec3<float> & in, const Vec3<float> & out, const Vec3<float> & n) const;
		Vec3<float> interact(const Vec3<float> & in, const Vec3<float> & ip, const Vec3<float> & n) const;
		Vec3<float> getColor(const Vec3<float> & color, const Vec3<float> & point);
		void init(const Block & block);
		Vec3<float> getTextureColor(const int x, const int y);
	private:
		SDL_Surface* surf;
		std::string file;
		Uint32 getPixel(SDL_Surface *surface, int x, int y);
		//  getPixel(SDL_Surface *surface, int x, int y);
		std::string toBin(Uint8 n);
};

#endif
