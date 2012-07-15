#ifndef __SPHERE_H__
#define __SPHERE_H__

class Sphere : ISurface {
	public:
		Vec3<float> pos;
		float radious;
		
		Vec3<float> getNormal(Vec3<float> ip);
		
		bool getIntersection(Ray r, Vec3<float> &ip);
};

Vec3<float> Sphere::getNormal(Vec3<float> ip) {
	
}

bool Sphere::getIntersection(Ray r, Vec3<float> &ip) {
	
}

#endif
