#include "Ray.h"

namespace Math {
	Vec3<float> Ray::eval(const float & t) const {
		return (position + direction * t);
	}

	Ray::Ray() {
		position.x = 0;
		position.y = 0;
		position.z = 0;
		direction.x = 0;
		direction.y = 0;
		direction.z = 0;
	}

	Ray::Ray(Vec3<float> pos, Vec3<float> dir) {
		position = pos;
		direction = dir;
	}
}
