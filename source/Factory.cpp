#include "Factory.h"
#include "SimpleMaterial.h"


ISurface * Factory::createSurface(const Block & block) {
	ISurface * surf = NULL;

	if (block.surface == "plane") {
		surf = new Plane();
	}

	/*if (block.surface == "mesh") {
		surf = new Mesh();
		surf -> init(block);
	} */

	if (block.surface == "sphere") {
		surf = new Sphere();
	}

	if(surf != NULL) {
		surf->init(block);
	}
	return surf;
}

IMaterial * Factory::createMaterial(const Block & block) {
	IMaterial * mater = NULL;
	if (block.surface == "simple") {
		mater = new SimpleMaterial();
		mater -> init(block);
	}
	return mater;
}


