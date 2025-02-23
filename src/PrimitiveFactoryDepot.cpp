#include "PrimitiveFactoryDepot.h"



Primitive* PrimitiveFactoryDepot::CreatePrimitive(const std::string &primitiveType)
{
	return mFactoryMap[primitiveType]->CreatePrimitive();
}

void PrimitiveFactoryDepot::RegisterFactoryDepot(const std::string &factoryName, PrimitiveFactory *factoryObj)
{
	mFactoryMap[factoryName] = factoryObj;
}