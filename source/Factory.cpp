#include "Factory.h"
#include "SimpleMaterial.h"


ISurface * Factory::createSurface(const Block & block) {
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

IMaterial * Factory::createMaterial(const Block & block) {
	IMaterial * mater;

	if (block.surface == "simple") {
		mater = new SimpleMaterial();
		mater -> init(block);
	}
	return mater;
}


