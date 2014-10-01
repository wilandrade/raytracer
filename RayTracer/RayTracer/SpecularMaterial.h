#pragma once
#include "DiffuseMaterial.h"


class SpecularMaterial : public DiffuseMaterial
{
	public:
		virtual void PrintType();
		virtual const std::string & GetTypeName();
		virtual void ProcessProperty(std::ifstream& fileStream, std::string propertyName);
		virtual Color3 GetColor(const HitRecord& hit);
	
	protected:
		Color3 _Specular(const HitRecord& hit);
};