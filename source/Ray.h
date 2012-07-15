#ifndef __RAY_H__ 
#define __RAY_H__
#include "Vec3.h"

class Ray {
	public:
		Vec3<float> position;
		Vec3<float> direction;
		Vec3<float> eval(const float & t) const;
		Vec3<float> eval();
		Vec3<float> eval(T x, T y, T z);
		
};
#endif
