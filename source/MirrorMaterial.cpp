#include "MirrorMaterial.h"
#include "MathUtils.h"

float MirrorMaterial::getBRDF(const Vec3<float> & in, const Vec3<float> & out, const Vec3<float> & n) const {
	return 1.0f;
}

Vec3<float> MirrorMaterial::getColor(const Vec3<float> & color) {
	return color;
}

Vec3<float> MirrorMaterial::interact(const Vec3<float> & in, const Vec3<float> & ip, const Vec3<float> & n) const {
	float cos = dot(in, n);
	//float sin = sqrt(1-cos*cos);
	Vec3<float> v1 = in*(2*cos);
	Vec3<float> v =  v1-in;
	return v;
}

void MirrorMaterial::init(const Block & block) {
	
};
