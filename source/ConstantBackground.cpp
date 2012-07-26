#include "ConstantBackground.h"

Vec3<float> ConstantBackground::getColor(const Vec3<float> & vec) const {
	return color;
}

void ConstantBackground::init(const Block & block) {
	color = block.getVariable("color").vectorValue;
}