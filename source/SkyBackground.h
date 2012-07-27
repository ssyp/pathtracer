#ifndef __SKYBACKGROUND_H__
#define __SKYBACKGROUND_H__

#include "IBackground.h"
#include "Block.h"
#include "Sphere.h"

#include "SDL.h"

#include <string>

class SkyBackground : public IBackground {
		public:
			Vec3<float> getColor(const Ray & ray);

			void init(const Block & block);
			
			Vec3<float> getTextureColor(const int & x, const int & y);
		
		protected:
			SDL_Surface* surf;
			std::string file;

			Uint32 getPixel(SDL_Surface *surface, int x, int y);

			Sphere sphere;
};

#endif
