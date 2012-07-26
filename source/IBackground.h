#ifndef __IBACKGROUND_H__
#define __IBACKGROUND_H__

#include "Vec3.h"
#include "Block.h"

using namespace Math;

class IBackground {
	public:

		virtual Vec3<float> getColor(const Vec3<float> & vec) const = 0;

		virtual void init(const Block & block) = 0;
};

#endif
