#include "ConstantBackground.h"
#include "MathUtils.h"

Vec3<float> ConstantBackground::getColor(const Ray & ray) {
	return color;
}

void ConstantBackground::init(const Block & block) {
	color = Math::getColor(block.getVariable("color").vectorValue);
}