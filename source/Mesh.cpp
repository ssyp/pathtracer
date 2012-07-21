#include "Mesh.h"
#include "Plane.h"
#include "Poligon.h"
#include "MathUtils.h"
#include <iostream>
#include <fstream>

using namespace Math;

bool Mesh::getIntersection(const Ray & ray, float & t, Vec3<float> & normal) const{
	Plane plane;
	Vec3<float> normalSave;
	bool colision=false;
	size_t index;
	float pointIntersection,t1;
	t=inf;
	
	for(size_t i = 0; i < poligons.size(); i++) {	

		plane.setAbcd(poligons[i].vertices1,poligons[i].vertices2,poligons[i].vertices3);
		if(plane.getIntersection(ray,pointIntersection,normal)) {
			Vec3<float> ad = ray.eval(pointIntersection) - poligons[i].vertices1; //x=vertices1
			Vec3<float> bd = ray.eval(pointIntersection) - poligons[i].vertices2; //y=vertices2
			Vec3<float> cd = ray.eval(pointIntersection) - poligons[i].vertices3; //z=vertices3
			Vec3<float> ab = poligons[i].vertices2 - poligons[i].vertices1;
			Vec3<float> bc = poligons[i].vertices3 - poligons[i].vertices2;
			Vec3<float> ca = poligons[i].vertices1 - poligons[i].vertices3;
			if( ad.dot(ab) > 0 && bd.dot(bc) > 0 && ca.dot(cd) > 0) {
				t1=pointIntersection;
				if(t1 < t) { 
					t=t1;
					index=i;
					normalSave=normal;
					colision=true;
				}
			}
		}
	}
	if(colision) {
		plane.setAbcd(poligons[index].vertices1,poligons[index].vertices2,poligons[index].vertices3);
		normal = normalSave;
		return true;
	}
	return false;
}


void Mesh::load(const std::string & fileName) {
	Vec3<float> point;
	Poligon poligon;
	std::ifstream file(fileName);
	while(!file.eof()) {
		file >> poligon.vertices1.x >> poligon.vertices1.y >> poligon.vertices1.z;
		file >> poligon.vertices1.x >> poligon.vertices1.y >> poligon.vertices1.z;
		file >> poligon.vertices1.x >> poligon.vertices1.y >> poligon.vertices1.z;
		poligons.push_back(poligon);
	}
}

void Mesh::init(const Block & block) {
	load(block.getVariable("file").stringValue);
}
