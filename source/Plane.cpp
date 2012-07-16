#include "Plane.h"

Plane::Plane(const Vec3<float> & vec, const float & d1) {
	abc=vec;
	d=d1;
}

Plane::Plane() {
	abc.x=0;
	abc.y=0;
	abc.z=0;
	d=0;
}

bool Plane::getIntersection(const Ray & ray, float & t, Vec3<float> & normal) const{
	Vec3<float> normal = getNormal(abc);
	
	if(normal.dot(ray.direction)!= 0) {
		t = -(normal.dot(ray.position) + d) / normal.dot(ray.direction);
		normal=abc;
		normal.normalize();
		return true;
	}
	return false;
}
