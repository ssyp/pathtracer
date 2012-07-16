#ifndef __MATHUTILS_H__ 
#define __MATHUTILS_H__
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <ctime>
#include "Vec3.h"
#include "Vec2.h"

namespace Math {
	
	Vec3<float> GetRandromPointOnPlane(const Vec3<float> & n) {
		Vec3<float> randV;
		Vec3<float> dirX;
		Vec3<float> dirY;
		Vec3<float> randVe;
		srand(time(0));
		randVe.x = RAND_MAX / RAND_MAX * 2 - 1;
		randVe.y = RAND_MAX / RAND_MAX * 2 - 1;

		randV.x = rand() % 10;
		randV.y = rand() % 10;
		randV.z = rand() % 10;
		dirX = randV.cross(n);  
		dirY = dirX.cross(n);
		dirX.normalize();
		dirY.normalize();
		return (dirX * randVe.x + dirY * randVe.y);
	} 

	Vec3<float> GetRandomPointOnHemisphere(const Vec3<float> & n) {
		Vec3<float> randV;
		Vec3<float> dirX;
		Vec3<float> dirY;
		Vec3<float> randVe;

		randVe.x = RAND_MAX / RAND_MAX * 2 - 1;
		randVe.y = RAND_MAX / RAND_MAX * 2 - 1;
		randVe.z = sqrt(1 - randVe.x * randVe.x - randVe.y * randVe.y);

		randV.x = rand() % 10;
		randV.y = rand() % 10;
		randV.z = rand() % 10;
		dirX = randV.cross(n);  
		dirY = dirX.cross(n);
		dirX.normalize();
		dirY.normalize();
		return (dirX * randVe.x + dirY * randVe.y + n * randVe.z);
	} 

	const float inf = 100000000.0f;
	const float eps = 0.001f;

	bool f_eq(float v1, float v2) {
		if (fabs(v1 - v2) < eps) {return true;}
		else {return false;}
	}
}

#endif

