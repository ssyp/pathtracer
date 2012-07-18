#include "MaterialManager.h"

std::map<std::string,IMaterial *> MaterialManager::materials;

void MaterialManager::addMaterial(IMaterial* material, const std::string & string) {
	materials[string] = material;
}

void MaterialManager::deleteMaterial(const std::string & string) {
	std::map<std::string,IMaterial *>::const_iterator it = materials.find(string);
	if (it == materials.end()) {
		return; 
	} 
	materials.erase(it);
}

IMaterial* MaterialManager::getMaterial(const std::string & string) {
	std::map<std::string,IMaterial *>::const_iterator it = materials.find(string);
	if (it == materials.end()) {
		return NULL; 
	} 
	return it->second;
}