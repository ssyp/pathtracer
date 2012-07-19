#ifndef __FACTORY_H__
#define __FACTORY_H__

#include "Block.h"
#include "ISurface.h"
#include "Sphere.h"
#include "Plane.h"

class Factory {
	public:
		static ISurface * createSurface(const Block & block);
		static IMaterial * createMaterial(const Block & block);
};

#endif
