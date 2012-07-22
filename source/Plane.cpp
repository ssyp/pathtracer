#include "Plane.h"


Plane::Plane() {
	abc.x = 0;
	abc.y = 0;
	abc.z = 0;
	d = 0;
}


Plane::Plane(const Vec3<float> & vec, const float & d1) {
	abc = vec;
	d = d1;
}

Plane::Plane(const Vec3<float> & a, const Vec3<float> & b, const Vec3<float> & c) {
	abc.x = a.y * (b.z - c.z) + b.y * (c.z - a.z) + c.y * (a.z - b.z);
	abc.y = a.z * (b.x - c.x) + b.z * (c.x - a.x) + c.z * (a.x - b.x);
	abc.z = a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y);
	d = -(a.x * (b.y * c.z - c.y * b.z) + b.x * (c.y * a.z - a.y * c.z) + c.x * (a.y * b.z - b.y * a.z));
	normalV = abc;
	normalV.normalize();
}

void Plane::setPlane(const Vec3<float> & a, const Vec3<float> & b, const Vec3<float> & c) {
	abc.x = a.y * (b.z - c.z) + b.y * (c.z - a.z) + c.y * (a.z - b.z);
	abc.y = a.z * (b.x - c.x) + b.z * (c.x - a.x) + c.z * (a.x - b.x);
	abc.z = a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y);
	d = -(a.x * (b.y * c.z - c.y * b.z) + b.x * (c.y * a.z - a.y * c.z) + c.x * (a.y * b.z - b.y * a.z));
	normalV = abc;
	normalV.normalize();
}

void Plane::setAbcd(const Vec3<float> & vec, const float & d1) {
	abc = vec;
	d = d1;
}

bool Plane::getIntersection(const Ray & ray, float & t, Vec3<float> & normal) const {
	normal = abc;
	float dotNormalDirection = dot(ray.direction, normal);
	if(dotNormalDirection != 0) {
		t = -(dot(ray.position, normal) + d) / dotNormalDirection;
		if(t < 0) {
			return false;
		}
		normal = normalV;
		return true;
	}
	return false;
}

void Plane::init(const Block & block) {
	abc = block.getVariable("abc").vectorValue;
	normalV = abc;
	normalV.normalize();
	d = block.getVariable("d").floatValue;
	material = MaterialManager::getMaterial(block.getVariable("material").stringValue);
};
