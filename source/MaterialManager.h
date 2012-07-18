#ifndef __MATERIALMANAGER_H__
#define __MATERIALMANAGER_H__

class MaterialManager {
	public:
		
		static void IMaterial * getMaterial(const std::string & string);
		static void addMaterial(IMaterial* material);
		static void deleteMaterial(const int index);
		static void deleteMaterial(const IMaterial* material);
	
		int getNumMaterials() const;	
		IMaterial* getMaterial(const int index) const;
	
		
	private:
		
		static std::map<std::string,IMaterial *> materials;
		
		
};

#endif
