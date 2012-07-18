#ifndef __MATERIALMANAGER_H__
#define __MATERIALMANAGER_H__

#include <string>
#include <map>
#include "IMaterial.h"

class MaterialManager {
	public:
		
		static void IMaterial * getMaterial(const std::string & string) const;
		
		static void addMaterial(IMaterial* material, const std::string & string);
		static void deleteMaterial(const std::string & string);
		
	private:
		
		static std::map<std::string,IMaterial *> materials;
		
};

#endif
