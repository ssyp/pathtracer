#ifndef __MESH_H__
#define __MESH_H__

#include "ISurface.h"
#include "Poligon.h"
#include <cmath>
#include <string>
#include <vector>

class Mesh : public ISurface {
	public:
		bool getIntersection(const Ray & ray, float & t, Vec3<float> & normal) const;
		
		void load(const std::string & fileName);
        bool getIntersectionTriangle(const Vec3<float> & a, const Vec3<float> & b, const Vec3<float> & c, const Vec3<float> & p) const;
        bool belongingTriangle(const Vec3<float> & a, const Vec3<float> & b, const Vec3<float> c, const Vec3<float> p) const;

		void init(const Block & block);
		
	private:
		std::vector<Poligon> poligons;
};

#endif
