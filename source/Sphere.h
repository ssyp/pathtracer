#ifndef __SPHERE_H__
#define __SPHERE_H__

#include "ISurface.h"
#include <cmath>
#include <algorithm>

class Sphere : public ISurface {
	public:
		Sphere();
		Sphere(const Vec3<float> & pos, const float & r);
	
		bool getIntersection(const Ray & ray, float & t, Vec3<float> & normal) const;
		
	private:
		Vec3<float> position;
		float radius;
};

#endif
