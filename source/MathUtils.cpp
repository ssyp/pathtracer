#include "MathUtils.h"

#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <ctime>

namespace Math { 

	Vec3<float> getRandomPointOnHemisphere(const Vec3<float> & n) {
		Vec3<float> vec;
		Vec3<float> randV;
		Vec3<float> dirX;
		Vec3<float> dirY;
		Vec3<float> randVe;

		if (n == vec) {
			return vec;
		}

		float infRandMax = 1.0f / RAND_MAX;

		float alpha = static_cast<float>(rand() * infRandMax) * pi2;
		float phi = static_cast<float>(rand() * infRandMax) * 2 * pi;

		randVe.x = cos(alpha) * cos(phi);
		randVe.y = cos(alpha) * sin(phi);
		randVe.z = sin(alpha);

		do {
			randV.x = static_cast<float> (rand() * infRandMax) * 2 - 1; 
			randV.y = static_cast<float> (rand() * infRandMax) * 2 - 1;
			randV.z = static_cast<float> (rand() * infRandMax) * 2 - 1;
		} while (n.cross(randV) == vec);
		
		dirX = randV.cross(n);  
		dirY = dirX.cross(n);
		dirX.normalize();
		dirY.normalize();
		return (dirX * randVe.x + dirY * randVe.y + n * randVe.z);
	} 

	bool f_eq(float v1, float v2){
		if (fabs(v1 - v2) < eps) {return true;}
		else {return false;}
	}

	Vec3<float> getColor(const Vec3<float> & rgb){
		Vec3<float> vec;

		vec.z=static_cast<float>(rgb.x) / 255.0f;
		vec.y=static_cast<float>(rgb.y) / 255.0f;
		vec.x=static_cast<float>(rgb.z) / 255.0f;

		return vec;
	}

	float radian (float grad) {
		return (grad * 180 / pi);
	}

	float grad (float radian) {
		return (radian * pi / 180);	
	}
}
