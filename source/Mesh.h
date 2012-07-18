#ifndef __MESH_H__
#define __MESH_H__

#include "ISurface.h"
#include <cmath>
#include <string>
#include <vector>

class Mesh : public ISurface {		
	public:		
		bool getIntersection(const Ray & ray, float & t, Vec3<float> & normal) const;
		
		void load(const std::string & fileName);

		void init(const Block & block);
		
	private:
		std::vector<Vec3<float>> poligon;
};

#endif
