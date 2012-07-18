#include "Sphere.h"

Sphere::Sphere() {
	position.x = 0;
	position.y = 0;
	position.z = 0;
	radius = 1;
}

Sphere::Sphere(const Vec3<float> & pos, const float & r) {
	position=pos;
	radius=r;
}

bool Sphere::getIntersection(const Ray & ray, float & t, Vec3<float> & normal) const {
	Vec3<float> localPosition = ray.position-position;
	
	float dotDirectionDirection = ray.direction.dot(ray.direction) ;
	float dotDirectionLocalPosition = ray.direction.dot(localPosition);
	
	float D = 4 * dotDirectionLocalPosition * dotDirectionLocalPosition - 
		4 * dotDirectionDirection * localPosition.dot(localPosition) +
		4 * dotDirectionDirection * radius * radius;
			
	if(D < 0) {
		return false;
	}
	
	if(fabs(D)<0.01) {
		t = (-1 * dotDirectionLocalPosition) / (dotDirectionDirection);
		
		normal=ray.eval(t)-position;
		normal.normalize();
		return true;
	}
	
	float t1, t2;
		
	t1 = (-1 * dotDirectionLocalPosition - sqrt(D)) / (dotDirectionDirection);
	t2 = (-1 * dotDirectionLocalPosition + sqrt(D)) / (dotDirectionDirection);

	t = std::min(t1,t2);
	
	
	normal=ray.eval(t)-position;
	normal.normalize();
	return true;
}

void init(const Block & block) {
	position = block.map["pos"].vectorValue;
	radius = block.map["radius"].floatValue;
};