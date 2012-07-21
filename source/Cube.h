#ifndef __CUBE_H__
#define __CUBE_H__

#include "ISurface.h"
#include "Plane.h"
#include "MathUtils.h"

class Cube : public ISurface {
	public:
		Cube();
		Cube(const Vec3<float> & minP, const Vec3<float> & maxP);
		
		bool getIntersection(const Ray & ray, float & t, Vec3<float> & normal) const;

		void init(const Block & block);
	
	private:
		Vec3<float> min;
		Vec3<float> max;
};
#endif
