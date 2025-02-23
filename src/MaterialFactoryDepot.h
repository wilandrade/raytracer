#pragma once
#include<string>
#include <map>

#include "DiffuseMaterialFactory.h"
#include "SpecularMaterialFactory.h"

#define MATERIAL_FACTORY_DEPOT MaterialFactoryDepot::GetInstance()

class MaterialFactoryDepot
{
	public:
		void RegisterFactoryDepot(const std::string &factoryName, MaterialFactory *factoryObj);
		Material* CreateMaterial(const std::string &materialType);

		static MaterialFactoryDepot* GetInstance()
		{
			static MaterialFactoryDepot* s_pInstance = new MaterialFactoryDepot(); 
			return s_pInstance;
		}
	private:
		std::map<std::string, MaterialFactory*> mFactoryMap;
		MaterialFactoryDepot(){};
		~MaterialFactoryDepot(){};
};