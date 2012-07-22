#include "Sphere.h"
#include "MathUtils.h"

Sphere::Sphere() {
	position.x = 0;
	position.y = 0;
	position.z = 0;
	radius = 1;
}

Sphere::Sphere(const Vec3<float> & pos, const float & r) {
	position = pos;
	radius = r;
}

bool Sphere::getIntersection(const Ray & ray, float & t, Vec3<float> & normal) const {
	Vec3<float> localPosition = ray.position - position;
	
	float dotDirectionDirection = dot(ray.direction, ray.direction) ;
	float dotDirectionLocalPosition = dot(ray.direction, localPosition);
	
	float D = 4 * dotDirectionLocalPosition * dotDirectionLocalPosition - 
		4 * dotDirectionDirection * dot(localPosition, localPosition) +
		4 * dotDirectionDirection * radius * radius;
			
	if(D < 0) {
		return false;
	}

	if(f_eq(D,0)) {
		t = (-dotDirectionLocalPosition) / (dotDirectionDirection);
		if(t < 0) {
			return false;
		}
		normal = ray.eval(t) - position;
		normal.normalize();
		return true;
	}
	
	float t1, t2;
	float sqrtD = static_cast<float>(sqrt(D) * 0.5);
		
	t1 = (-dotDirectionLocalPosition - sqrtD) / (dotDirectionDirection);
	t2 = (-dotDirectionLocalPosition + sqrtD) / (dotDirectionDirection);

	if(t1 < 0 && t2 > 0){
		t = t2;
		normal = ray.eval(t) - position;
		normal.normalize();
		return true;
	}
	if(t2 < 0 && t1 > 0) {
		t = t1;
		normal = ray.eval(t) - position;
		normal.normalize();
		return true;
	}
	if(t1 < 0 && t2 < 0) {
		return false;
	}
	
	t = std::min(t1,t2);
	normal = ray.eval(t) - position;
	normal.normalize();
		
	return true;
}

void Sphere::init(const Block & block) {
	position = block.getVariable("pos").vectorValue;
	radius = block.getVariable("radius").floatValue;
	material = MaterialManager::getMaterial(block.getVariable("material").stringValue);
};
