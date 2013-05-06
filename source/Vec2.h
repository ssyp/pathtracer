#ifndef __VEC2_H__ 
#define __VEC2_H__

namespace Math {

	template <class T>
	class Vec2 {
		public:
			T x;
			T y;
				
			Vec2() {
				x = 0;
				y = 0;
			}
	
			Vec2(T newX, T newY) {
				x = newX;
				y = newY;
			}

			Vec2(const Vec2<T> & vec) {
				x = vec.x;
				y = vec.y;
			}
				
			void operator = (const Vec2<T> & vec) {
				x = vec.x;
				y = vec.y;
			}
	
			Vec2<T> operator * (const Vec2<T> & vec) const {
				Vec2<T> result;
				result.x = x * vec.x;
				result.y = y * vec.y;
				return result;
			}

			Vec2<T> operator + (const Vec2<T> & vec2) const {
				Vec2<T> result;
				result.x = x + vec2.x;
				result.y = y + vec2.y;
				return result;
			}
	
			Vec2<T> operator - (const Vec2<T> & vec2) const {
				Vec2<T> result;
				result.x = x - vec2.x;
				result.y = y - vec2.y;
				return result;
			}
	
			Vec2<T> operator * (const T & k) const {
				Vec2<T> result;
				result.x = x * k;
				result.y = y * k;
				return result;
			}
	
			float getLength() const {
				return static_cast<float> (sqrt (x * x + y * y));
			}
	
			void normalize() {
				float l = 1.0f / getLength();
				x *= l; y *= l;
			}
				
			T dot(const Vec2<T> & vec2) const {
				return (x * vec2.x + y * vec2.y);
			}
	
			bool operator < (const Vec2<T> & vec2) const
			{
				if (x + y < vec2.x + vec2.y) 
				{
					return true;
				}
				return false;
			}
	
			bool operator > (const Vec2<T> & vec2) const
			{
				if (x + y < vec2.x + vec2.y) 
				{
					return true;
				}
				return false;
			}
	
			Vec2<T> operator += (const Vec2<T> & vec2) const {
				Vec2<T> result;
				result.x = x + vec2.x;
				result.y = y + vec2.y;
				return result;
			}
	
			Vec2<T> operator -= (const Vec2<T> & vec2) const {
				Vec2<T> result;
				result.x = x - vec2.x;
				result.y = y - vec2.y;
				return result;
			}
	
			Vec2<T> operator *= (const T & k) const {
				Vec2<T> result;
				result.x = x * k;
				result.y = y * k;
				return result;
			}
	
			bool operator == (const Vec2<T> & vec2) const
			{
				if (x == vec2.x && y == vec2.y) 
				{
					return true;
				}
				return false;
			}
	
			bool operator != (const Vec2<T> & vec2) const
			{
				if (x != vec2.x && y != vec2.y) 
				{
					return true;
				}
				return false;
			}
	};
}
#endif


