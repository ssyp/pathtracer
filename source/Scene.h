#ifndef __SCENE_H__
#define __SCENE_H__

#include <vector>
#include "ISurface.h"
#include "MathUtils.h"


class Scene {
	public:
			std::vector<ISurface*> nodes;
	
			void addSurface(ISurface* surface);
			void deleteSurface(const int index);
			void deleteSurface(const ISurface* surface);
	
			int getNumSurfaces() const;	
			ISurface* getSurface(const int index) const;
	
			int getIntersection(const Ray & ray) const;
};

#endif
