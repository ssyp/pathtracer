#ifndef __MESH_H__
#define __MESH_H__

#include "ISurface.h"
#include <cmath>
#include <string>
#include <vector>

class Mesh : public ISurface {		
	public:
	
		Vec3<float> getNormal(const Vec3<float> & ip) const;
		
		bool getIntersection(const Ray & ray, float & t) const;
		
		void load(const std::string & fileName);
		
	private:
		vector<Vec3<float>> poligon;
};

#endif
