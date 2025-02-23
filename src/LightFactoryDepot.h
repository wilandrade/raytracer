#pragma once
#include<string>
#include <map>

#include "PointLightFactory.h"
#include "DirectionalLightFactory.h"

#define LIGHT_FACTORY_DEPOT LightFactoryDepot::GetInstance()

class LightFactoryDepot
{
	public:
		void RegisterFactoryDepot(const std::string &factoryName, LightFactory *factoryObj);
		Light* CreateLight(const std::string &lightType);

		static LightFactoryDepot* GetInstance()
		{
			static LightFactoryDepot* s_pInstance = new LightFactoryDepot(); 
			return s_pInstance;
		}
	private:
		std::map<std::string, LightFactory*> mFactoryMap;
		LightFactoryDepot(){};
		~LightFactoryDepot(){};
};