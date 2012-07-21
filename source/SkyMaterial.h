#ifndef __SKYMATERIAL_H__
#define __SKYMATERIAL_H__

#include "IMaterial.h"
#include "Block.h"

class SkyMaterial : public IMaterial {
	private:
		Vec3<float> reflectance;
		Vec3<float> emittance;
	public:
		float getBRDF(const Vec3<float> & in, const Vec3<float> & out, const Vec3<float> & n) const;
		Vec3<float> interact(const Vec3<float> & in, const Vec3<float> & ip, const Vec3<float> & n) const;
		Vec3<float> getColor(const Vec3<float> & color, const Vec3<float> & point);
		void init(const Block & block);
};

#endif
