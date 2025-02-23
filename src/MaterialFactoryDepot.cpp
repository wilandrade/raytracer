#include "MaterialFactoryDepot.h"



Material* MaterialFactoryDepot::CreateMaterial(const std::string &materialType)
{
	return mFactoryMap[materialType]->CreateMaterial();
}

void MaterialFactoryDepot::RegisterFactoryDepot(const std::string &factoryName, MaterialFactory *factoryObj)
{
	//assert(factoryObj);
	mFactoryMap[factoryName] = factoryObj;
}