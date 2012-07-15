#include "Sphere.h"


Vec3<float> Sphere::getNormal(const Vec3<float> & ip) const {
	Vec3<float> normal=ip-position;
	normal.normalize();
	return normal;
}

bool Sphere::getIntersection(const Ray & ray, Vec3<float> & ip) const {
	float D = 4 * ray.direction.dot(ray.position) * ray.direction.dot(ray.position) - 
		4 * ray.direction.dot(ray.direction) * ray.position.dot(ray.position) +
		4 * ray.direction.dot(ray.direction) * radious * radious;
			
	if(D < 0) {
		return false;
	}
	
	if(fabs(D)<0.01) {
		float t;
		t = (-1 * ray.direction.dot(ray.position)) / (2 * ray.direction.dot(ray.direction));
		
		ip = ray.position + ray.direction * t;
		
		return true;
	}
	
	if(D > 0) {
		float t1, t2;
		
		t1 = (-1 * ray.direction.dot(ray.position) - sqrt(D)) / (2 * ray.direction.dot(ray.direction));
		t2 = (-1 * ray.direction.dot(ray.position) + sqrt(D)) / (2 * ray.direction.dot(ray.direction));

		ip = ray.position + ray.direction * std::min(t1,t2);
		
		return true;
	}
}
