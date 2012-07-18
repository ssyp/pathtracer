#ifndef __VEC3_H__ 
#define __VEC3_H__
#include <cmath>

namespace Math {
	template <class T>
	class Vec3 {
	public:
		T x;
		T y;
		T z;

		Vec3() {
			x = 0;
			y = 0;
			z = 0;
		}

		Vec3(T newX, T newY, T newZ) {
			x = newX;
			y = newY;
			z = newZ;
		}
  
		Vec3(const Vec3<T> & vec) {
			x = vec.x;
			y = vec.y;
			z = vec.z;
		}

		Vec3<T> operator * (const Vec3<T> & vec) const {
			Vec3<T> result;
			result.x = x * vec.x;
			result.y = y * vec.y;
			result.z = z * vec.z;
			return result;
		}

		Vec3<T> operator = (const Vec3<T> & vec) const {
			Vec3<T> result;
			result.x = vec.x;
			result.y = vec.y;
			result.z = vec.z;
			return result;
		}

		Vec3<T> operator + (const Vec3<T> & vec) const {
			Vec3<T> result;
			result.x = x + vec.x;
			result.y = y + vec.y;
			result.z = z + vec.z;
			return result;
		}

		Vec3<T> operator - (const Vec3<T> & vec) const {
			Vec3<T> result;
			result.x = x - vec.x;
			result.y = y - vec.y;
			result.z = z - vec.z;
			return result;
		}

		Vec3<T> operator * (const T & k) const {
			Vec3<T> result;
			result.x = x * k;
			result.y = y * k;
			result.z = z * k;
			return result;
		}

		float getLength() const {
			return static_cast<float>(sqrt (x * x + y * y + z * z));
		}

		void normalize() {
			float l = 1.0f / getLength();
			x *= l; y *= l; z *= l;
		}

		T dot(const Vec3<T> & Vec3) const {
			return (x * Vec3.x + y * Vec3.y + z * Vec3.z);
		}

		Vec3<T> cross(const Vec3<T> & vec) const {
			Vec3 result;
			result.x = y * vec.z - vec.y * z;
			result.y = vec.x * z - x * vec.z;
			result.z = x * vec.y - vec.x * y;
			return result;
		}
		bool operator < (const Vec3<T> & vec) const
		{
			if (x + y + z < vec.x + vec.y + vec.z) 
			{
				return 1;
			}
			return 0;
		}

		bool operator > (const Vec3<T> & vec) const
		{
			if (x + y + z < vec.x + vec.y + vec.z) 
			{
				return 0;
			}
			return 1;
		}

		Vec3<T> operator += (const Vec3<T> & vec) const {
			Vec3<T> result;
			result.x = x + vec.x;
			result.y = y + vec.y;
			result.z = z + vec.z;
			return result;
		}

		Vec3<T> operator -= (const Vec3<T> & vec) const {
			Vec3<T> result;
			result.x = x - vec.x;
			result.y = y - vec.y;
			result.z = z - vec.z;
			return result;
		}

		Vec3<T> operator *= (const T & k) const {
			Vec3<T> result;
			result.x = x * k;
			result.y = y * k;
			result.z = z * k;
			return result;
		}

		bool operator == (const Vec3<T> & vec) const
		{
			if (x + y + z == vec.x + vec.y + vec.z) 
			{
				return 0;
			}
			return 1;
		}

		bool operator != (const Vec3<T> & vec) const
		{
			if (x + y + z != vec.x + vec.y + vec.z) 
			{
				return 0;
			}
			return 1;
		}
	};
}
#endif
