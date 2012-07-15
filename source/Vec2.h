#ifndef __VECTOR2_H__ 
#define __VECTOR2_H__

template <class T>
class Vec2 {
	public:
		T x;
		T y;
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

	T getLength() {
		return static_cast<float> (sqrt (x * x + y * y));
	}

	void normalize() {
		float l=1.0f / getLength();
		x * = l; y * = l;
	}

	T dot(const Vec2<T> & vec2) const {
		return (x * vec2.x + y * vec2.y);
	}
};
#endif
