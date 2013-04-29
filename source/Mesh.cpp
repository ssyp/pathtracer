#include "Mesh.h"
#include "Plane.h"
#include "Poligon.h"
#include "MathUtils.h"
#include <iostream>
#include <fstream>

using namespace Math;

bool Mesh::getIntersection(const Ray & ray, float & t, Vec3<float> & normal) const{
	Plane plane;
	Vec3<float> normalOutput, vertices4;
	bool colision=false;
	float pointIntersection;
	t=inf;
	
	for(size_t i = 0; i < poligons.size(); i++) {	
		plane.setPlane(poligons[i].vertices1,poligons[i].vertices2,poligons[i].vertices3);

		if(plane.getIntersection(ray,pointIntersection,normal)) {
			vertices4 = ray.eval(pointIntersection);

			Vec3<float> ad = vertices4 - poligons[i].vertices1;
			Vec3<float> ab = poligons[i].vertices2 - poligons[i].vertices1;

			Vec3<float> bd = vertices4 - poligons[i].vertices2;
			Vec3<float> bc = poligons[i].vertices3 - poligons[i].vertices2;

			Vec3<float> cd = vertices4 - poligons[i].vertices3;
			Vec3<float> ca = poligons[i].vertices1 - poligons[i].vertices3;

			if( dot(ad, ab) > 0 && dot(bd, bc) > 0 && dot(ca, cd) > 0) {
				if(pointIntersection < t) { 
					t=pointIntersection;
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
    //Before there was not c_str
	std::ifstream file(std::string("scenes/" + fileName).c_str(), std::ifstream::in);
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
