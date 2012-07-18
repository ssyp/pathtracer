#ifndef __SURFACEFACTORY_H__
#define __SURFACEFACTORY_H__

#include "Block.h"
#include "ISurface.h"
#include "Sphere.h"
#include "Plane.h"

class SurfaceFactory {
	public:
		
		ISurface * createSurface(const Block & block);

};

#endif
