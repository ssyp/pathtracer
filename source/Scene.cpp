#include "Scene.h"
#include "Vec3.h"

void Scene::addSurface(ISurface* surface) {
	for(size_t i = 0; i < nodes.size(); i++) {
		if(nodes[i] == surface) {
			return;
		}
	}
	nodes.push_back(surface);	
}

void Scene::deleteSurface(const int index) {
	nodes.erase(nodes.begin()+index);
}

void Scene::deleteSurface(const ISurface* surface) {
	for(std::vector<ISurface*>::iterator it = nodes.begin(); it < nodes.end(); it++) {
		if(*it == surface) {
			nodes.erase(it);
			break;
		}
	}
}

int Scene::getNumSurfaces() const { 
	return nodes.size();
}

ISurface* Scene::getSurface(const int index) const {
	return nodes[index];
}
	
int Scene::getIntersection(const Ray & ray) const {
	float t1, t = inf;
	int index;
	for(size_t i = 0; i < nodes.size(); i++) {
		if(nodes[i]->getIntersection(ray, t1)) {
			if(t1 < t) {
				t = t1;
				index = i;
			}
		}
	}
	return index;
}
