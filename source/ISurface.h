#ifndef __ISURFACE_H__
#define __ISURFACE_H__

#include "Vec3.h"
#include "Ray.h"

class ISurface {
	public:
		virtual Vec3<float> getNormal(const Vec3<float> & ip) const = 0;
		virtual bool getIntersection(const Ray & ray, float & t) const = 0;
};

#endif
