#ifndef __PLANE_H__
#define __PLANE_H__

#include "ISurface.h"
#include <cmath>

class Plane : ISurface {
	public:
		Vec3<float> abc;
		float d;
		
		Vec3<float> getNormal(const Vec3<float> & ip) const;
		
		bool getIntersection(const Ray & ray, Vec3<float> & ip) const;
};

#endif
