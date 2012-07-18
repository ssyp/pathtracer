#include "SimpleMaterial.h"
#include "MathUtils.h"

float SimpleMaterial::getBRDF(const Vec3<float> & in, const Vec3<float> & out, const Vec3<float> & n) const {
	return 1.0f;
}

Vec3<float> SimpleMaterial::interact(const Vec3<float> & in, const Vec3<float> & ip, const Vec3<float> & n) const {
	return GetRandomPointOnHemisphere(n);
}
