#ifndef __SIMPLEMATERIAL_H__
#define __SIMPLEMATERIAL_H__

#include "IMaterial.h"

class SimpleMaterial : public IMaterial {
	public:
		float getBRDF(const Vec3<float> & in, const Vec3<float> & out, const Vec3<float> & n) const;
		Vec3<float> interact(const Vec3<float> & in, const Vec3<float> & ip, const Vec3<float> & n) const;
};

#endif
