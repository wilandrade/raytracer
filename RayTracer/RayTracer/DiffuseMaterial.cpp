#include <iostream>
#include "DiffuseMaterial.h"
#include "Tracer.h"
#include "Scene.h"
#include "Light.h"


Color3 DiffuseMaterial::GetColor(const HitRecord& hit)
{
	return _Diffuse(hit) + TRACER->GetCurrentScene()->mAmbientLight;
}

Color3 DiffuseMaterial::_Diffuse(const HitRecord& hit)
{
	Color3 diffuseColor(0,0,0); //the calculated diffuse color


	double diff; //the dotProduct calculated for each N.L
	std::list<Light*> lightList = TRACER->GetCurrentScene()->GetLightList(); //list of lights in the scene
	std::list<Light*>::iterator iter; //iterator for the lightList
	for (iter = lightList.begin(); iter != lightList.end(); iter++)
	{
		LightRecord lightRec = (*iter)->GetLightInfo(hit); //get all the light info
		diff = hit.mNormal.Dot(lightRec.mIncidentVector);
		if(diff > 0)//if light is not behind hitPoint
		{
			diffuseColor += lightRec.mLightColor * lightRec.mLightIntensity * diff;// * lightRec.mOcclusion; //add light attribution
			//diffuseColor = Color3(lightRec.mOcclusion, lightRec.mOcclusion, lightRec.mOcclusion); //occlusion pass test
		}
	}
 
	return diffuseColor;


}

void DiffuseMaterial::PrintType()
{
	std::cout << "DiffuseMaterial";
}

const std::string & DiffuseMaterial::GetTypeName()
{
	static std::string name = "DiffuseMaterial";
	return name;
}

void DiffuseMaterial::ProcessProperty(std::ifstream& fileStream, std::string propertyName)
{
	std::string propertyValue;
	fileStream >> propertyValue;
	std::cout << "\t -" << propertyName << " was loaded as " << propertyValue << std::endl;
}