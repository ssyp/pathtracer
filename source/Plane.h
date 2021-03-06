#ifndef __PLANE_H__
#define __PLANE_H__

#include <cmath>
#include "ISurface.h"
#include "MaterialManager.h"
#include "MathUtils.h"

class Plane : public ISurface {
	public:
		Plane();
		Plane(const Vec3<float> & vec, const float & d1);
		Plane(const Vec3<float> & a, const Vec3<float> & b, const Vec3<float> & c);
		
		void setAbcd(const Vec3<float> & vec, const float & d1);
		void setPlane(const Vec3<float> & a, const Vec3<float> & b, const Vec3<float> & c);

		bool getIntersection(const Ray & ray, float & t, Vec3<float> & normal) const;

		void init(const Block & block);
		
		Vec3<float> normalV;
	private:
		Vec3<float> abc;
		float d;
};

#endif
