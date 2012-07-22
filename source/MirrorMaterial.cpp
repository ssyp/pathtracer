#include "MirrorMaterial.h"
#include "MathUtils.h"

float MirrorMaterial::getBRDF(const Vec3<float> & in, const Vec3<float> & out, const Vec3<float> & n) const {
	return 1.0f;
}

Vec3<float> MirrorMaterial::getColor(const Vec3<float> & color, const Vec3<float> & point) {
	return color * reflectance;
}

Vec3<float> MirrorMaterial::interact(const Vec3<float> & in, const Vec3<float> & ip, const Vec3<float> & n) const {
	return in - n * 2 * dot(in, n);
}

void MirrorMaterial::init(const Block & block) {
	reflectance = block.getVariable("reflectance").vectorValue;
}
