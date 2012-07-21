#include "Cube.h"

Cube::Cube() {
	min.x = 0;
	min.y = 0;
	min.z = 0;
	max.x = 0;
	max.y = 0;
	max.z = 0;
}

Cube::Cube(const Vec3<float> & minP, const Vec3<float> & maxP) {
	min.x = minP.x;
	min.y = minP.x;
	min.z = minP.x;
	max.x = maxP.x;
	max.y = maxP.x;
	max.z = maxP.x;
}

void Cube::init(const Block & block) {
	min = block.getVariable("min").vectorValue;
	max = block.getVariable("max").vectorValue;
	material = MaterialManager::getMaterial(block.getVariable("material").stringValue);
}

bool Cube::getIntersection(const Ray & ray, float & t, Vec3<float> & normal) const {
	Plane add1(Vec3<float>(min.x, min.y, min.z), Vec3<float>(max.x, min.y, min.z), Vec3<float>(max.x, min.y, max.z));
	Plane dd1ñ1(Vec3<float>(max.x, min.y, min.z), Vec3<float>(max.x, min.y, max.z), Vec3<float>(max.x, max.y, max.z));
	Plane adc(Vec3<float>(min.x, min.y, min.z), Vec3<float>(max.x, min.y, min.z), Vec3<float>(max.x, max.y, min.z));
	Plane abb1(Vec3<float>(min.x, min.y, min.z), Vec3<float>(min.x, max.y, min.z), Vec3<float>(min.x, max.y, max.z));
	Plane bcc1(Vec3<float>(min.x, max.y, min.z), Vec3<float>(max.x, max.y, min.z), Vec3<float>(max.x, max.y, max.z));
	Plane a1b1c1(Vec3<float>(min.x, min.y, max.z), Vec3<float>(min.x, max.y, max.z), Vec3<float>(max.x, max.y, max.z));
	
	Vec3<float> pointIntersection, minValue, maxValue, normal1, normalP;
	float t1, tP;
	t1 = inf;
	
	if(add1.getIntersection(ray, tP, normalP)) {
		pointIntersection = ray.eval(tP);
		minValue.x = min.x;
		minValue.y = min.y;
		minValue.z = min.z;
		maxValue.x = max.x;
		maxValue.y = min.y;
		maxValue.z = max.z;		
		if ((pointIntersection >= minValue) && (pointIntersection <= maxValue)) {		
			if(tP < t1) {
				t1 = tP;
				normal1 = normalP;
			}
		}
	}
	if(dd1ñ1.getIntersection(ray, tP, normalP)) {
		pointIntersection = ray.eval(tP);
		minValue.x = max.x;
		minValue.y = min.y;
		minValue.z = min.z;
		maxValue.x = max.x;
		maxValue.y = max.y;
		maxValue.z = max.z;
		if (pointIntersection >= minValue && pointIntersection <= maxValue) {
			if(tP < t1) {
				t1 = tP;
				normal1 = normalP;
			}
		}
	}
	if(adc.getIntersection(ray, tP, normalP)) {
		pointIntersection = ray.eval(tP);
		minValue.x = min.x;
		minValue.y = min.y;
		minValue.z = min.z;
		maxValue.x = max.x;
		maxValue.y = max.y;
		maxValue.z = min.z;	
		if (pointIntersection >= minValue && pointIntersection <= maxValue) {
			if(tP < t1) {
				t1 = tP;
				normal1 = normalP;
			}
		}
	}
	if(abb1.getIntersection(ray, tP, normalP)) {
		pointIntersection = ray.eval(tP);
		minValue.x = min.x;
		minValue.y = min.y;
		minValue.z = min.z;
		maxValue.x = min.x;
		maxValue.y = max.y;
		maxValue.z = max.z;
		if (pointIntersection >= minValue && pointIntersection <= maxValue) {
			if(tP < t1) {
				t1 = t;
				normal1 = normalP;
			}
		}
	}
	if(bcc1.getIntersection(ray, tP, normalP)) {
		pointIntersection = ray.eval(tP);
		minValue.x = min.x;
		minValue.y = max.y;
		minValue.z = min.z;
		maxValue.x = max.x;
		maxValue.y = max.y;
		maxValue.z = max.z;
		if (pointIntersection >= minValue && pointIntersection <= maxValue) {
			if(tP < t1) {
				t1 = tP;
				normal1 = normalP;
			}
		}
	}
	if(a1b1c1.getIntersection(ray, tP, normalP)) {
		pointIntersection = ray.eval(tP);
		minValue.x = min.x;
		minValue.y = min.y;
		minValue.z = max.z;
		maxValue.x = max.x;
		maxValue.y = max.y;
		maxValue.z = max.z;
		if (pointIntersection >= minValue && pointIntersection <= maxValue) {
			if(tP < t1) {
				t1 = tP;
				normal1 = normalP;
			}
		}
	}
	
	if(t1 == Math::inf) {
		return false;
	}
	
	t = t1;
	normal = normal1;
	return true;
}
