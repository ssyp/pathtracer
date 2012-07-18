#include "MaterialManager.h"
#include "Vec3.h"

void MaterialManager::addMaterial(IMaterial* material) {
	for(size_t i = 0; i < nodes.size(); i++) {
		if(nodes[i] == material) {
			return;
		}
	}
	nodes.push_back(material);	
}

void MaterialManager::deleteMaterial(const int index) {
	nodes.erase(nodes.begin()+index);
}

void MaterialManager::deleteMaterial(const IMaterial* material) {
	for(std::vector<IMaterial*>::iterator it = nodes.begin(); it < nodes.end(); it++) {
		if(*it == material) {
			nodes.erase(it);
			break;
		}
	}
}

int MaterialManager::getNumMaterial() const { 
	return nodes.size();
}

IMaterial* MaterialManager::getMaterial(const int index) const {
	return nodes[index];
}