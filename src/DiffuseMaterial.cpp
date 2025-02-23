#include <iostream>
#include "DiffuseMaterial.h"
#include "Tracer.h"
#include "Scene.h"
#include "Light.h"


Color3 DiffuseMaterial::GetColor(const HitRecord& hit)
{
	Color3 color = _Diffuse(hit) + TRACER->GetCurrentScene()->mAmbientLight;
    
    // Clamp final color
    color.x = std::min(1.0, std::max(0.0, color.x));
    color.y = std::min(1.0, std::max(0.0, color.y));
    color.z = std::min(1.0, std::max(0.0, color.z));
    
    return color;
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
			// Apply both diffuse and shadow terms
			Color3 contribution = lightRec.mLightColor * lightRec.mLightIntensity * diff * lightRec.mOcclusion;
			
			// Clamp the contribution
			contribution.x = std::min(1.0, std::max(0.0, contribution.x));
			contribution.y = std::min(1.0, std::max(0.0, contribution.y));
			contribution.z = std::min(1.0, std::max(0.0, contribution.z));
			
			diffuseColor += contribution;
		}
	}
	
	// Clamp final color
	diffuseColor.x = std::min(1.0, std::max(0.0, diffuseColor.x));
	diffuseColor.y = std::min(1.0, std::max(0.0, diffuseColor.y));
	diffuseColor.z = std::min(1.0, std::max(0.0, diffuseColor.z));
 
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