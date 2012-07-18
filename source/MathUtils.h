#ifndef __MATHUTILS_H__ 
#define __MATHUTILS_H__

#include "Vec3.h"
#include "Vec2.h"

namespace Math {

	extern Vec3<float> getRandromPointOnPlane(const Vec3<float> & n);
	extern Vec3<float> getRandomPointOnHemisphere(const Vec3<float> & n);

	const float inf = 100000000.0f;
	const float eps = 0.001f;

	extern bool f_eq(float v1, float v2);
}

#endif

