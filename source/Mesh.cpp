#include "Mesh.h"
#include "Plane.h"
#include "Poligon.h"
#include "MathUtils.h"
#include <iostream>
#include <fstream>

using namespace Math;

bool Mesh::getIntersection(const Ray & ray, float & t, Vec3<float> & normal) const{
	Plane plane;
	Vec3<float> normalOutput;
	bool colision=false;
	float pointIntersection,t1;
	t=inf;
	
	for(size_t i = 0; i < poligons.size(); i++) {	
		plane.setPlane(poligons[i].vertices1,poligons[i].vertices2,poligons[i].vertices3);

		if(plane.getIntersection(ray,pointIntersection,normal)) {

			Vec3<float> ad = ray.eval(pointIntersection) - poligons[i].vertices1;
			Vec3<float> ab = poligons[i].vertices2 - poligons[i].vertices1;

			Vec3<float> bd = ray.eval(pointIntersection) - poligons[i].vertices2;
			Vec3<float> bc = poligons[i].vertices3 - poligons[i].vertices2;

			Vec3<float> cd = ray.eval(pointIntersection) - poligons[i].vertices3;
			Vec3<float> ca = poligons[i].vertices1 - poligons[i].vertices3;

			if( dot(ad, ab) > 0 && dot(bd, bc) > 0 && dot(ca, cd) > 0) {
				t1=pointIntersection;
				if(t1 < t) { 
					t=t1;
					normalOutput=normal;
					colision=true;
				}
			}
		}
	}
	if(colision) {
		normal = normalOutput;
		return true;
	}
	return false;
}


void Mesh::load(const std::string & fileName) {
	Poligon poligon;
	std::ifstream file("scenes/" + fileName);
	while(!file.eof() && file) {
		file >> poligon.vertices1.x >> poligon.vertices1.y >> poligon.vertices1.z;
		file >> poligon.vertices2.x >> poligon.vertices2.y >> poligon.vertices2.z;
		file >> poligon.vertices3.x >> poligon.vertices3.y >> poligon.vertices3.z;
		poligons.push_back(poligon);
	}
}

void Mesh::init(const Block & block) {
	load(block.getVariable("file").stringValue);
	material = MaterialManager::getMaterial(block.getVariable("material").stringValue);
}
