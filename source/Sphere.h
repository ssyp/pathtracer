#ifndef __SPHERE_H__
#define __SPHERE_H__

#include "ISurface.h"
#include <cmath>
#include <algorithm>

class Sphere : public ISurface {
	public:
		Vec3<float> position;
		float radious;
		
		Vec3<float> getNormal(const Vec3<float> & ip) const;
		
		bool getIntersection(const Ray & ray, float & t) const;
};

#endif
