#include "LightFactoryDepot.h"



Light* LightFactoryDepot::CreateLight(const std::string &lightType)
{
	return mFactoryMap[lightType]->CreateLight();
}

void LightFactoryDepot::RegisterFactoryDepot(const std::string &factoryName, LightFactory *factoryObj)
{
	//assert(factoryObj);
	mFactoryMap[factoryName] = factoryObj;
}