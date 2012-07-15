#include "Ray.h"

Vec3<float> Ray::eval(const float & t) const {
	return (position + direction * t);
}
