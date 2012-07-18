#ifndef __VARIABLE_H__
#define __VARIABLE_H__
#include "Vec3.h"
#include <string>

class Variable {
	public:
		float floatValue;
		Math::Vec3<float> vectorValue;
		std::string stringValue;
		int type;
};

#endif
