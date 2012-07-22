#ifndef __SPHERE_H__
#define __SPHERE_H__

#include <cmath>
#include <algorithm>
#include <map>
#include "ISurface.h"
#include "MaterialManager.h"
#include "Block.h"

class Sphere : public ISurface {
	public:
		Sphere();
		Sphere(const Vec3<float> & pos, const float & r);
	
		bool getIntersection(const Ray & ray, float & t, Vec3<float> & normal) const;

		void init(const Block & block);
		
	private:
		Vec3<float> position;
		float radius;
};

#endif
