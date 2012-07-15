#ifndef __ISURFACE_H__
#define __ISURFACE_H__

template<class T>
class ISurfece {
	public:
		virtual vec3<T> getNormal(vec3<t> ip) = 0;
		virtual bool getIntersection(Ray r, vec3<T> &ip) = 0;
};

#endif