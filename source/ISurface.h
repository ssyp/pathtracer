#ifndef __ISURFACE_H__
#define __ISURFACE_H__

#include "Vec3.h"
#include "Ray.h"
#include "IMaterial.h"
#include "Block.h"
#include "SimpleMaterial.h"

using namespace Math;

class ISurface {
	public:

		virtual bool getIntersection(const Ray & ray, float & t, Vec3<float> & normal) const = 0;

		virtual void init(const Block & block) = 0;
		
		IMaterial* getMaterial() const {
			return material;
		}
		
	protected:
		IMaterial* material;
};

#endif
