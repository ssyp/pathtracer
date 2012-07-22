#include "MirrorMaterial.h"
#include "MathUtils.h"

float MirrorMaterial::getBRDF(const Vec3<float> & in, const Vec3<float> & out, const Vec3<float> & n) const {
	return 1.0f;
}

Vec3<float> MirrorMaterial::getColor(const Vec3<float> & color, const Vec3<float> & point) {
	return color;
}

Vec3<float> MirrorMaterial::interact(const Vec3<float> & in, const Vec3<float> & ip, const Vec3<float> & n) const {
	/**Vec3<float> normalIn = in*(-1);
	normalIn.normalize();
	float cos = dot(normalIn, n);
	return n*(2.0*cos)+normalIn;**/
	float k = dot(in, n);
	Vec3<float> proj = in - n * k;
	return  proj - n * k;
}

void MirrorMaterial::init(const Block & block) {
	return;
};
