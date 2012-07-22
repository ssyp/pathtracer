#include "SimpleMaterial.h"
#include "MathUtils.h"

float SimpleMaterial::getBRDF(const Vec3<float> & in, const Vec3<float> & out, const Vec3<float> & n) const {
	return dot(n, out);
}

Vec3<float> SimpleMaterial::getColor(const Vec3<float> & color, const Vec3<float> & point) {
	return emittance + reflectance * color;
}

Vec3<float> SimpleMaterial::interact(const Vec3<float> & in, const Vec3<float> & ip, const Vec3<float> & n) const {
	return getRandomPointOnHemisphere(n);
}

void SimpleMaterial::init(const Block & block) {
	reflectance = block.getVariable("reflectance").vectorValue;
	emittance = block.getVariable("emittance").vectorValue;
};
