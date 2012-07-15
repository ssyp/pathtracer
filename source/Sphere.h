#ifndef __SPHERE_H__
#define __SPHERE_H__

#include <cmath>

class Sphere : ISurface {
	public:
		Vec3<float> pos;
		float radious;
		
		Vec3<float> getNormal(Vec3<float> ip);
		
		bool getIntersection(Ray r, Vec3<float> &ip);
};

#endif
