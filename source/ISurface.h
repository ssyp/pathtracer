#ifndef __ISURFACE_H__
#define __ISURFACE_H__

class ISurfece {
	public:
		virtual Vec3<float> getNormal(Vec3<float> ip) = 0;
		virtual bool getIntersection(Ray r, Vec3<float> &ip) = 0;
};

#endif
