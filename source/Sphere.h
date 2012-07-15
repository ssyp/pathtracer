#ifndef __SPHERE_H__
#define __SPHERE_H__

#include <cmath>

class Sphere : ISurface {
	public:
		Vec3<float> position;
		float radious;
		
		Vec3<float> getNormal(const Vec3<float> & ip) const;
		
		bool getIntersection(const Ray & r, Vec3<float> & ip) const ;
};

#endif
