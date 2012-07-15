#ifndef __RAY_H__ 
#define __RAY_H__
#include "Vec.3"

class Ray {
	Vec3<float> position;
	Vec3<float> direction;
	Vec3<float> eval(float t);
};
#endif
