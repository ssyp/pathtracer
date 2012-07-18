#include "SurfaceFactory.h"


ISurface * SurfaceFactory::createSurface(const Block & block) {

	ISurface * surf;
	switch (block.surface) {
	case "plane": {
		surf = new Plane();
		surf->init(block);
		break; 
				  }

	case "mesh": {
		surf = new Mesh();
		surf->init(block);
		break; 
				 }

	case "sphere": {
		surf = new Sphere();
		surf->init(block);
		break; 
				  }
	}

	return surf;
}

