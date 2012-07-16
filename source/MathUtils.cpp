#include "MathUtils.h"

namespace Math { 
	bool f_eq(float v1, float v2){
		if (fabs(v1 - v2) < eps) {return true;}
		else {return false;}
	}
}
