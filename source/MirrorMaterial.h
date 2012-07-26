#ifndef __MIRRORMATERIAL_H__
#define __MIRRORMATERIAL_H__

#include "IMaterial.h"
#include "Block.h"

class MirrorMaterial : public IMaterial {
	public:
		float getBRDF(const Vec3<float> & in, const Vec3<float> & out, const Vec3<float> & n) const;
		Vec3<float> interact(const Vec3<float> & in, const Vec3<float> & ip, const Vec3<float> & n) const;
		Vec3<float> getColor(const Vec3<float> & color);
		void init(const Block & block);

	private:
		Vec3<float> reflectance;	
};

#endif
