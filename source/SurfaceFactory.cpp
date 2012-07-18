#include "SurfaceFactory.h"



ISurface * SurfaceFactory::createSurface(const Block & block) {
	ISurface * surf;

	if (block.surface == "plane") {
		surf = new Plane();
		surf -> init(block); 
	}

	/*if (block.surface == "mesh") {
		surf = new Mesh();
		surf -> init(block);
	} */

	if (block.surface == "sphere") {
		surf = new Sphere();
		surf->init(block);
	}
	return surf;
}

