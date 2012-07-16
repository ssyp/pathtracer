#include "Mesh.h"
#include "Plane.h"
#include <iostream>
#include <fstream>

bool Mesh::getIntersection(const Ray & ray, float & t, Vec3<float> & normal) const{
	Plane plane;
	bool colision=false;
	size_t index;
	float pointIntersection,t1;
	t=inf;
	
	for(size_t i = 0; i < poligon.size(); i++) {	
		plane.setAbcd(poligon[i],0);
		if(plane.getIntersection(ray,pointIntersection)) {
			Vec3<float> ad = pointIntersection - poligon[i].x;
			Vec3<float> bd = pointIntersection - poligon[i].y;
			Vec3<float> cd = pointIntersection - poligon[i].z;
			Vec3<float> ab = poligon[i].y - poligon[i].x;
			Vec3<float> bc = poligon[i].z - poligon[i].y;
			Vec3<float> ca = poligon[i].x - poligon[i].z;
			if( ad.dot(ab) > 0 && bd.dot(bc) > 0 && ca.dot(cd) > 0) {
				t1=pointIntersection;
				if(t1 < t) { 
					t=t1;
					index=i;
					colision=true;
				}
			}
		}
	}
	if(colision) {
		normal = poligon[index];
		normal.normalize();
		return true;
	}
	return false;
}


void Mesh::load(const std::string & fileName) {
	Vec3 v;
	std::ifstream file(fileName);
	while(!file.eof()) {
		file >> v.x >> v.y >> v.z;
		poligon.push_back(v);
	}				
}
