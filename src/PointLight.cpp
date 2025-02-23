#include <iostream>
#include "PointLight.h"
#include "Tracer.h"


LightRecord PointLight::GetLightInfo(const HitRecord& hit)
{
	LightRecord lightRec; //light record that holds all the light data
	lightRec.mIncidentVector = (hit.mHitPoint - mPosition) * -1; //align with hitpoint normal
	lightRec.mIncidentVector.NormalizeVector();
	
	Vector3 uVec; // the light's local right axis
	uVec = lightRec.mIncidentVector.Cross( Vector3( 0,1,0 ) );
	uVec.NormalizeVector();

	Vector3 vVec; // the light's local up axis
	vVec = uVec.Cross( lightRec.mIncidentVector );
	vVec.NormalizeVector();


	int totalOccludedSamples = 0; //total number of samples that were occluded
	int totalSamples = 4;  // Increased from 1 to get soft shadows
	Vector3 sampleOrigin; // location that we are sampling from
	Vector3 hitToSample; // vector from the hit point to the point we're sampling around the light
	double distToSample; // distance from hit point to sampleOrigin
	double sampleDiskRadius = 0.30; //samples will be taken from within a disk area. This is the disk's radius
	double tempRand = 0; //random number temp
	double precision = 10.0f;


	for(int curSample = 0; curSample < totalSamples; curSample++)
	{
		sampleOrigin = mPosition;
		
		//x component
		tempRand = (rand() % ((int)precision*2)) - precision;
		tempRand /= precision; //normalize random number
		sampleOrigin += ( uVec * tempRand *  sampleDiskRadius );
		
		//y component
		tempRand = (rand() % ((int)precision*2)) - precision;
		tempRand /= precision; //normalize random number
		sampleOrigin += ( vVec * tempRand * sampleDiskRadius );
		
		//setup the vector from the hit point to the point of the light being sampled
		hitToSample = ( hit.mHitPoint - sampleOrigin ) * -1;
		//setup the distance to the point in the light being sampled
		distToSample = hitToSample.GetLength();

		hitToSample.NormalizeVector();



		if(TRACER->ShadowTrace(hit.mHitPoint, hitToSample, distToSample))
			totalOccludedSamples++;
	}
	
	double sampleHitRatio = (double) totalOccludedSamples / (double) totalSamples;
	lightRec.mOcclusion = 1.0 - sampleHitRatio;
	lightRec.mLightColor = mColor;
	lightRec.mLightIntensity = mIntensity;

	
	return lightRec;
}



void PointLight::ProcessProperty(std::ifstream& fileStream, std::string propertyName)
{
	if(propertyName == "intensity")
	{
		fileStream >> mIntensity;
		std::cout << "\t -PointLight::" << propertyName << " was loaded as " << mIntensity << std::endl;
	}
	else if(propertyName == "position")
	{
		fileStream >> mPosition.x;
		fileStream >> mPosition.y;
		fileStream >> mPosition.z;
		std::cout << "\t -PointLight::" << propertyName << " was loaded as " << mPosition << std::endl;
	}
	else if(propertyName == "color")
	{
		fileStream >> mColor.x;
		fileStream >> mColor.y;
		fileStream >> mColor.z;
		std::cout << "\t -PointLight::" << propertyName << " was loaded as " << mColor << std::endl;
	}
	else
		Entity::ProcessProperty(fileStream, propertyName);
}

void PointLight::PrintType()
{
	std::cout << "DirectionalLight";
}

const std::string & PointLight::GetTypeName()
{
	static std::string name = "DirectionalLight";
	return name;
}