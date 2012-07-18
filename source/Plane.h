#ifndef __PLANE_H__
#define __PLANE_H__

#include "ISurface.h"
#include <cmath>

class Plane : public ISurface {
	public:
		Plane();
		Plane(const Vec3<float> & vec, const float & d1);
		
		void setAbcd(const Vec3<float> & vec, const float & d1);
		
		bool getIntersection(const Ray & ray, float & t, Vec3<float> & normal) const;

		void init(const Block & block);
		
	private:
		Vec3<float> abc;
		float d;
};

#endif
