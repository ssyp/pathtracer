#ifndef __SIMPLEMATERIAL_H__
#define __SIMPLEMATERIAL_H__

#include "IMaterial.h"
#include "Block.h"

class SimpleMaterial : public IMaterial {
	private:
		Vec3<float> reflectance;
		Vec3<float> emittance;
	public:
		//SimpleMaterial() { reflectance=Vec3<float>(1,0,0); emittance=Vec3<float>(1,1,1); }
		float getBRDF(const Vec3<float> & in, const Vec3<float> & out, const Vec3<float> & n) const;
		Vec3<float> interact(const Vec3<float> & in, const Vec3<float> & ip, const Vec3<float> & n) const;
		Vec3<float> getColor(const Vec3<float> & color);
		void init(const Block & block);
};

#endif
