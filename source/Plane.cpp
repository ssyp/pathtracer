#include "Plane.h"

Vec3<float> Plane::getNormal(const Vec3<float> & ip) {
	Vec3<float> normal = abc;
	return 	normal.normalize();
}

bool Plane::getIntersection(const Ray & r, Vec3<float> & ip) {
	Vec3<float> normal = getNormal(abc);
	float t = 0;
	
	if(normal.dot(ray.direction)!= 0) {
		t = -(normal.dot(ray.position) + d) / normal.dot(ray.direction);
		ip = ray.position + ray.direction * t;
		return true;
	}
	return false;
}
