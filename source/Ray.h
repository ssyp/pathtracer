#ifndef __RAY_H__ 
#define __RAY_H__

#include "Vec3.h"

class ISurface;

namespace Math {
	class Ray {
	public:
		Vec3<float> position;
		Vec3<float> direction;
		Vec3<float> eval(const float & t) const;
		Ray();
		Ray(Vec3<float> pos, Vec3<float> dir);
		void operator = (Ray & r);

		ISurface * prevSurface; 
	};
}
#endif
