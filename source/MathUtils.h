#ifndef __MATHUTILS_H__ 
#define __MATHUTILS_H__
#include <algorithm>
#include <cmath>

const float inf = 100000000.0f;
const float eps = 0.001f;

bool f_eq(float v1, float v2) {
	if (f_abs(v1 - v2) < eps) {return true;}
	else {return false;}
};

#endif
