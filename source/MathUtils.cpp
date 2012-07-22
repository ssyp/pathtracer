#include "MathUtils.h"

#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <ctime>

namespace Math { 

	Vec3<float> getRandomPointOnHemisphere(const Vec3<float> & n) {
		Vec3<float> randV;

		float infRandMax = 1.0f / RAND_MAX;

		do {
			randV.x = static_cast<float> (rand() * infRandMax) * 2 - 1; 
			randV.y = static_cast<float> (rand() * infRandMax) * 2 - 1;
			randV.z = static_cast<float> (rand() * infRandMax) * 2 - 1;
		} while (dot(n, randV) < 0);

		randV.normalize();
		return randV;
	} 

	bool f_eq(float v1, float v2){
		if (fabs(v1 - v2) < eps) return true;
	return false;
	}

	Vec3<float> getColor(const Vec3<float> & rgb){
		Vec3<float> vec;

		vec.z = static_cast<float>(rgb.x) / 255.0f;
		vec.y = static_cast<float>(rgb.y) / 255.0f;
		vec.x = static_cast<float>(rgb.z) / 255.0f;

		return vec;
	}

	float radian (const float & grad) {
		return (grad * 180 / pi);
	}

	float grad (const float & radian) {
		return (radian * pi / 180);	
	}

	float dot (const Vec3<float> & vec, const Vec3<float> & vec1) {
			return (vec.x * vec1.x + vec.y * vec1.y + vec.z * vec1.z);
	}

	Vec3<float> toDecard(const float & radius, const float & zenit, const float & azimut) {
		Vec3<float> result;
		result.x = radius * sin(zenit) * cos(azimut);
		result.y = radius * sin(zenit) * cos(azimut);
		result.z = radius * cos(zenit);
		return result;
	}

	Vec3<float> cross(const Vec3<float> & vec, const Vec3<float> & vec1) {
		Vec3<float> rezVec;		
		rezVec.x = vec1.y * vec.z - vec.y * vec1.z;
		rezVec.y = vec.x * vec1.z - vec1.x * vec.z;
		rezVec.z = vec1.x * vec.y - vec.x * vec1.y;
		return rezVec;
	}
}
