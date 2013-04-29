#include "MaterialManager.h"

std::map<std::string, IMaterial *> MaterialManager::materials;

void MaterialManager::addMaterial(IMaterial* material, const std::string & string) {
	materials[string] = material;
}

void MaterialManager::deleteMaterial(const std::string & string) {
	std::map<std::string, IMaterial *>::iterator it = materials.find(string); //There was a const_iterator
	if (it == materials.end()) {
		return; 
	}
    materials.erase(it); //But gcc 4.7 swears by const_iterator
}

IMaterial* MaterialManager::getMaterial(const std::string & string) {
	std::map<std::string, IMaterial *>::const_iterator it = materials.find(string);
	if (it == materials.end()) {
		return NULL; 
	} 
	return it->second;
}

void MaterialManager::init(Parser & parser) {
	int n = parser.getNumMaterialBlocks();
	for(int i = 0; i < n; i++) {
		addMaterial(Factory::createMaterial(parser.getMaterialBlock(i)), parser.getMaterialBlock(i).getVariable("name").stringValue);
	}
}
