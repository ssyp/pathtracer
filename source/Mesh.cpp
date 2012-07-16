#include "Mesh.h"
#include <iostream>
#include <fstream>

Vec3<float> Mesh::getNormal(const Vec3<float> & ip) const{
	Vec3<float> normal;
	for(size_t i = 0; i < poligon.size(); i++) {
		
	}
	normal.normalize();
	return normal;
}

bool Mesh::getIntersection(const Ray & ray, float & t) const{
	Vec3<float> normal = getNormal(abc);
	
	for(size_t i = 0; i < poligon.size(); i++) {
		if(normal.dot(ray.direction)!= 0) {
			t = -(normal.dot(ray.position) + d) / normal.dot(ray.direction);
			return true;
		}
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
