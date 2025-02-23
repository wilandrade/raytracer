#pragma once
#include<string>
#include <map>

#include "PlaneFactory.h"
#include "SphereFactory.h"

#define PRIMITIVE_FACTORY_DEPOT PrimitiveFactoryDepot::GetInstance()

class PrimitiveFactoryDepot
{
	public:
		void RegisterFactoryDepot(const std::string &factoryName, PrimitiveFactory *factoryObj);
		Primitive* CreatePrimitive(const std::string &primitiveType);

		static PrimitiveFactoryDepot* GetInstance()
		{
			static PrimitiveFactoryDepot* s_pInstance = new PrimitiveFactoryDepot(); 
			return s_pInstance;
		}
	private:
		std::map<std::string, PrimitiveFactory*> mFactoryMap;
		PrimitiveFactoryDepot(){};
		~PrimitiveFactoryDepot(){};
};