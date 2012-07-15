#include "Scene.h"
#include "Vec3.h"

void addSurface(const ISurface* surface) {
	for(int i = 0; i < nodes.size(); i++) {
		if(nodes[i] == surface) {
			return;
		}
	}
	nodes.push_back(surface);	
}

void deleteSurface(const int index) {
	nodes.erase(nodes.begin()+index);
}

void deleteSurface(const ISurface* surface) {
	for(std::vector<float>::iterator it = nodes.begin(); it < nodes.end(); it++) {
		if(*it == surface) {
			nodes.erase(it);
			break;
		}
	}
}

int getNumSurfaces() const { 
	return nodes.size();
}

ISurface* getSurface(const int index) const {
	return nodes[index];
}
	
int getIntersection(const Ray & ray) const {
	Vec3<float> v;
	for(int i=0; i < nodes.size(); i++) {
		if(nodes[i]->getIntersection(ray, v)) {
			return i;
		}
	}
}
