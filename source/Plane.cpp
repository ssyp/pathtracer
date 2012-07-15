#include "Plane.h"

Vec3<float> Plane::getNormal(const Vec3<float> & ip) const{
	Vec3<float> normal = abc;
	normal.normalize();
	return normal;
}

bool Plane::getIntersection(const Ray & ray, Vec3<float> & ip) const{
	Vec3<float> normal = getNormal(abc);
	float t = 0;
	
	if(normal.dot(ray.direction)!= 0) {
		t = -(normal.dot(ray.position) + d) / normal.dot(ray.direction);
		ip = ray.position + ray.direction * t;
		return true;
	}
	return false;
}
