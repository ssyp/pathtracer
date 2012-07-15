#ifndef __SPHERE_H__
#define __SPHERE_H__

template<class T>
class Sphere : ISurface {
	public:
		vec3<T> pos;
		T radious;
		
		vec3<T> getNormal(vec3<T> ip);
		
		bool getIntersection(Ray r, vec3<T> &ip);
};

vec3<T> Sphere<T>::getNormal(vec3<T> ip) {
	
}

bool Sphere<T>::getIntersection(Ray r, vec3<T> &ip) {

}

#endif