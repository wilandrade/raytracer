#include <iostream>
#include "DirectionalLight.h"
#include "Tracer.h"



LightRecord DirectionalLight::GetLightInfo(const HitRecord& hit)
{
	LightRecord lightRec;
	lightRec.mIncidentVector = mDirection * -1;
	double distToLight = lightRec.mIncidentVector.GetLength();
	lightRec.mIncidentVector.NormalizeVector();
	if(TRACER->ShadowTrace(hit.mHitPoint, lightRec.mIncidentVector, distToLight))
	{
		lightRec.bIsOccluded = true;
	}
	else
		lightRec.bIsOccluded = false;

	lightRec.mLightColor = mColor;
	lightRec.mLightIntensity = mIntensity;
	
	return lightRec;
}



void DirectionalLight::ProcessProperty(std::ifstream& fileStream, std::string propertyName)
{
	if(propertyName == "intensity")
	{
		fileStream >> mIntensity;
		std::cout << "\t -DirectionalLight::" << propertyName << " was loaded as " << mIntensity << std::endl;
	}
	else if(propertyName == "direction")
	{
		fileStream >> mDirection.x;
		fileStream >> mDirection.y;
		fileStream >> mDirection.z;
		std::cout << "\t -DirectionalLight::" << propertyName << " was loaded as " << mDirection << std::endl;
	}
	else if(propertyName == "color")
	{
		fileStream >> mColor.x;
		fileStream >> mColor.y;
		fileStream >> mColor.z;
		std::cout << "\t -DirectionalLight::" << propertyName << " was loaded as " << mColor << std::endl;
	}
	else
		Entity::ProcessProperty(fileStream, propertyName);
}

void DirectionalLight::PrintType()
{
	std::cout << "DirectionalLight";
}

const std::string & DirectionalLight::GetTypeName()
{
	static std::string name = "DirectionalLight";
	return name;
}