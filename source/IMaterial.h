#ifndef __IMATERIAL_H__
#define __IMATERIAL_H__

#include "Vec3.h"
#include "Parser.h"

using namespace Math;

class IMaterial {
	public:
		virtual float getBRDF(const Vec3<float> & in, const Vec3<float> & out, const Vec3<float> & n) const = 0;
		virtual Vec3<float> interact(const Vec3<float> & in, const Vec3<float> & ip, const Vec3<float> & n) const = 0;
		virtual Vec3<float> getColor(const Vec3<float> & color, const Vec3<float> & point) = 0;
		virtual void init(const Block & block) = 0;
};	

#endif
