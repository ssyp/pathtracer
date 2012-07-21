#include "MirrorMaterial.h"
#include "MathUtils.h"

float MirrorMaterial::getBRDF(const Vec3<float> & in, const Vec3<float> & out, const Vec3<float> & n) const {
	return 1.0f;
}

Vec3<float> MirrorMaterial::getColor(const Vec3<float> & color) {
	return color;
}

Vec3<float> MirrorMaterial::interact(const Vec3<float> & in, const Vec3<float> & ip, const Vec3<float> & n) const {
	Vec3<float> nin = in*(-1);
	//nin.normalize();
	float cos = dot(nin, n);
	//float sin = sqrt(1-cos*cos);
	Vec3<float> v1 = n*(2.0*cos);
	Vec3<float> v =  v1+nin;
	return v;
	/**Vec3<float> nin = in;
	nin.normalize();
	float cos = dot(nin*(-1), n);
	Vec3<float> v = (in * sqrt(1-cos*cos))*2.0;
	return v - in;**/
}

void MirrorMaterial::init(const Block & block) {
	
};
