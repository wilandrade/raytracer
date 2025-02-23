#include "DirectionalLightFactory.h"
#include "DirectionalLight.h"

//PrimitiveFactory* PlaneFactory::GetInstance();

DirectionalLightFactory::DirectionalLightFactory()
{}

DirectionalLightFactory::~DirectionalLightFactory()
{}

Light* DirectionalLightFactory::CreateLight()
{
	Light* directionalLight = new DirectionalLight();

	return directionalLight;
}