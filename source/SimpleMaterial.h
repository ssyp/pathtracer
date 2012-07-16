#ifndef __SIMPLEMATERIAL_H__
#define __SIMPLEMATERIAL_H__

#include "Imaterial.h"

SimpleMaterial : public IMaterial {
	public:
		float getBRDF(Vec3<float> in, Vec3<float> out, Vec3<float> n);
		Vec3<float> interact(Vec3<float> in, Vec3<float> ip, Vec3<float> n);
		// interact == случайный луч по полусфере от нормали
};

#endif