#ifndef __PLANE_H__
#define __PLANE_H__

#include "ISurface.h"
#include <cmath>

class Plane : public ISurface {
	public:
		Plane();
		Plane(const Vec3<float> & vec, const float & d1);

		Vec3<float> getNormal(const Vec3<float> & ip) const;
		
		bool getIntersection(const Ray & ray, float & t) const;
		
	private:
		Vec3<float> abc;
		float d;
};

#endif
