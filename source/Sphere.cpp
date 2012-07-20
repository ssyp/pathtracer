#include "Sphere.h"
#include "MathUtils.h"

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

	normal=ray.eval(t)-position;
	normal.normalize();
	
	if(fabs(D)<0.01) {
		t = (-dotDirectionLocalPosition) / (dotDirectionDirection);
		if(t < 0) {
			return false;
		}
		
		return true;
	}
	
	float t1, t2;
	float sqrtD=static_cast<float>(sqrt(D)*0.5);
		
	t1 = (-1 * dotDirectionLocalPosition - sqrtD) / (dotDirectionDirection);
	t2 = (-1 * dotDirectionLocalPosition + sqrtD) / (dotDirectionDirection);

	t=Math::inf;
	if(t1 < 0) {
		t=t2;
	}
	if(t2 < 0) {
		t=t1;
	}
	if(t < 0) {
		return false;
	}
	
	t = std::min(t1,t2);
	
	return true;
}

void Sphere::init(const Block & block) {
	position = block.getVariable("pos").vectorValue;
	radius = block.getVariable("radius").floatValue;
	material = MaterialManager::getMaterial(block.getVariable("material").stringValue);
};