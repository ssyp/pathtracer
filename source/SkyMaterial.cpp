#include "SkyMaterial.h"
#include "MathUtils.h"

float SkyMaterial::getBRDF(const Vec3<float> & in, const Vec3<float> & out, const Vec3<float> & n) const {
	return 1.0f;
}

Vec3<float> SkyMaterial::getColor(const Vec3<float> & color, const Vec3<float> & point) {
	return emittance + reflectance * color;
}

Vec3<float> SkyMaterial::interact(const Vec3<float> & in, const Vec3<float> & ip, const Vec3<float> & n) const {
	return getRandomPointOnHemisphere(n);
}

void SkyMaterial::init(const Block & block) {
	reflectance = block.getVariable("reflectance").vectorValue;
	emittance = block.getVariable("emittance").vectorValue;
};
