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
	nodes.erase(nodes.begin() + index);
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
	
bool Scene::getIntersection(Ray & ray, ISurface* & surface, float & t, Vec3<float> & normal) const {
	int index = -1;
	float t1;
	t = inf;
	for(size_t i = 0; i < nodes.size(); i++) {
		if(ray.prevSurface != nodes[i] && nodes[i]->getIntersection(ray, t1, normal)) {
			if(t1 < t) {
				t = t1;
				index = i;
			}
		}
	}
	if(index != -1) {
		surface = nodes[index];
		return true;
	}
	return false;
}
