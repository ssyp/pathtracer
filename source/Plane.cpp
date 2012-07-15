#include "Plane.h"

Vec3<float> Plane::getNormal(const Vec3<float> & ip) const{
	Vec3<float> normal = abc;
	normal.normalize();
	return normal;
}

bool Plane::getIntersection(const Ray & ray, float & t) const{
	Vec3<float> normal = getNormal(abc);
	
	if(normal.dot(ray.direction)!= 0) {
		t = -(normal.dot(ray.position) + d) / normal.dot(ray.direction);
		return true;
	}
	return false;
}
