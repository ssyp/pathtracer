#ifndef __ISURFACE_H__
#define __ISURFACE_H__

#include "Vec3.h"
#include "Ray.h"

class ISurface {
	public:
		virtual bool getIntersection(const Ray & ray, float & t, Vec3<float> & normal) const = 0;
};

#endif
