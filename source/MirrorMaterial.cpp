#include "MirrorMaterial.h"

float MirrorMaterial::getBRDF(const Vec3<float> & in, const Vec3<float> & out, const Vec3<float> & n) const {
	return 1.0f;
}

Vec3<float> MirrorMaterial::getColor(const Vec3<float> & color) {
	return color;
}

Vec3<float> MirrorMaterial::interact(const Vec3<float> & in, const Vec3<float> & ip, const Vec3<float> & n) const {
	float cos = (in*(-1)).dot(n);// / (in.getLength() * n.getLength());
	//float sin = sqrt(1-cos*cos);
	Vec3<float> v =  in*2*cos-in;
	return v;
}

void MirrorMaterial::init(const Block & block) {
	
};