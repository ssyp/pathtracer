#ifndef __IMATERIAL_H__
#define __IMATERIAL_H__

#include "Vec3.h"

using namespace Math;

class IMaterial {
	public:
		virtual float getBRDF(Vec3<float> in, Vec3<float> out, Vec3<float> n) = 0;
		virtual Vec3<float> interact(Vec3<float> in, Vec3<float> ip, Vec3<float> n) = 0;
};	


#endif
