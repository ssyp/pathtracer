#ifndef __vec3<T>3_H__ 
#define __vec3<T>3_H__

template <class T>
class Vec3 {
	public:
		T x;
		T y;
		T z;
		
	Vec3<T> operator + (const Vec3<T> &vec) const {
		Vec3<T> result;
		result.x=x+vec.x;
		result.y=y+vec.y;
		result.z=z+vec.z;
		return result;
	}

	Vec3<T> operator - (const Vec3<T> &vec) const {
		Vec3<T> result;
		result.x=x-vec.x;
		result.y=y-vec.y;
		result.z=z-vec.z;
		return result;
	}

	Vec3<T> operator * (const T &k) const {
		Vec3<T> result;
		result.x=x*k;
		result.y=y*k;
		result.z=z*k;
		return result;
	}

	T getLength() {
		return static_cast<float>(sqrt(x*x+y*y+z*z));
	}

	void normalize() {
		float l=1.0f/getLength();
		x*=l; y*=l; z*=l;
	}

	T dot(const Vec3<T> &Vec3) const {
		return (x*Vec3.x+y*Vec3.y+z*Vec3.z);
	}

	Vec3<T> cross(const Vec3<T> &vec) const {
		Vec3 result;
		result.x=y*vec.z-vec.y*z;
		result.y=vec.x*z-x*vec.z;
		result.z=x*vec.y-vec.x*y;
		return result;
	}

};
#endif
