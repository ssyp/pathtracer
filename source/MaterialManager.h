#ifndef __MATERIALMANAGER_H__
#define __MATERIALMANAGER_H__

#include <string>
#include <map>
#include "IMaterial.h"
#include "Parser.h"
#include "Factory.h"

class MaterialManager {
	public:
		
		static IMaterial * getMaterial(const std::string & string);
		
		static void addMaterial(IMaterial* material, const std::string & string);
		static void deleteMaterial(const std::string & string);

		static void init(Parser & parser);
		
	private:
		
		static std::map<std::string,IMaterial *> materials;
		
};

#endif
