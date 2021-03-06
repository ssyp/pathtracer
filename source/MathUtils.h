#ifndef __MATHUTILS_H__ 
#define __MATHUTILS_H__

#include "Vec3.h"
#include "Vec2.h"

namespace Math {

	extern Vec3<float> getRandomPointOnPlane(const Vec3<float> & n);
	extern Vec3<float> getRandomPointOnHemisphere(const Vec3<float> & n);

	extern Vec3<float> getColor(const Vec3<float> & rgb);

	const float inf = 100000000.0f;
	const float eps = 0.001f;
	const float pi = 3.14159265f;
	const float pi2 = 1.57079632f;
	const float pi4 = 0.78539816f;

	extern bool f_eq(float v1, float v2);

	extern float grad(const float & radian);
	extern float radian(const float & rad);

	extern Vec3<float> toDecard(const float & radius, const float & zenit, const float & azimut);
	extern Vec3<float> toSpherical(const Vec3<float> & point);

	extern float dot(const Vec3<float> & vec, const Vec3<float> & vec1);
	extern Vec3<float> cross(const Vec3<float> & vec, const Vec3<float> & vec1);
}

#endif
