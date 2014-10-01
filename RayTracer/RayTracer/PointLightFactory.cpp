#include "PointLightFactory.h"
#include "PointLight.h"

//PrimitiveFactory* PlaneFactory::GetInstance();

PointLightFactory::PointLightFactory()
{}

PointLightFactory::~PointLightFactory()
{}

Light* PointLightFactory::CreateLight()
{
	Light* pointLight = new PointLight();

	return pointLight;
}