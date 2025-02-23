#pragma once
#include "Light.h"
#include "Vector3.h"

class PointLight : public Light
{
	public:
		virtual void PrintType();
		virtual const std::string & GetTypeName();
		virtual void ProcessProperty(std::ifstream& fileStream, std::string propertyName);
		virtual LightRecord GetLightInfo(const HitRecord& hit);
	private:
		Vector3 mPosition;
		Color3 mColor;
		double mIntensity;

};