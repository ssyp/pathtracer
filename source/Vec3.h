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
				
			void clamp (float min, float max) {
				if (x < min) x = min;
				if (x > max) x = max;
				if (y < min) y = min;
				if (y > max) y = max;
				if (z < min) z = min;
				if (z > max) z = max;
			}

			Vec3<T> operator * (const Vec3<T> & vec) const {
				Vec3<T> result;
				result.x = x * vec.x;
				result.y = y * vec.y;
				result.z = z * vec.z;
				return result;
			}

			Vec3<T> operator * (const T & k) const {
				Vec3<T> result;
				result.x = x * k;
				result.y = y * k;
				result.z = z * k;
				return result;
			}

			void operator = (const Vec3<T> & vec) {
				x = vec.x;
				y = vec.y;
				z = vec.z;
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
	
			float getLength() const {
				return static_cast<float>(sqrt (x * x + y * y + z * z));
			}
	
			void normalize() {
				float l = 1.0f / getLength();
				x *= l; y *= l; z *= l;
			}

			bool operator < (const Vec3<T> & vec) const
			{
				if (x + y + z < vec.x + vec.y + vec.z) return true;
				return false;
			}
	
			bool operator > (const Vec3<T> & vec) const
			{
				if (x + y + z < vec.x + vec.y + vec.z) return true;
				return false;
			}

			bool operator >= (const Vec3<T> & vec) const {
				if (x >= vec.x && y >= vec.y && z >= vec.z) return true;
				return false;
			}
	
			bool operator <= (const Vec3<T> & vec) const {
				if (x <= vec.x && y <= vec.y && z <= vec.z) return true;
				return false;
			}

			void operator += (const Vec3<T> & vec) {
				x += vec.x;
				y += vec.y;
				z += vec.z;
			}
	
			void operator -= (const Vec3<T> & vec) {
				x -= vec.x;
				y -= vec.y;
				z -= vec.z;
			}
	
			void operator *= (const T & k)
			{
				x *= k;
				y *= k;
				z *= k;
			}
	
			bool operator == (const Vec3<T> & vec) const
			{
				if (x == vec.x && y == vec.y && z == vec.z) 
				{
					return true;
				}
				return false;
			}
	
			bool operator != (const Vec3<T> & vec) const
			{
				if (x != vec.x &&  y != vec.y && z != vec.z) 
				{
					return true;
				}
				return false;
			}
	};
}
#endif

