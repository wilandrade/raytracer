#include <iostream>
#include "SpecularMaterial.h"


Color3 SpecularMaterial::GetColor(const HitRecord& hit)
{
	Color3 color;
	color = _Specular(hit) + DiffuseMaterial::GetColor(hit);
	return color;
}
Color3 SpecularMaterial::_Specular(const HitRecord& hit)
{
	return Color3(0,0,0);
}
void SpecularMaterial::PrintType()
{
	std::cout << "SpecularMaterial";
}

const std::string & SpecularMaterial::GetTypeName()
{
	static std::string name = "SpecularMaterial";
	return name;
}

void SpecularMaterial::ProcessProperty(std::ifstream& fileStream, std::string propertyName)
{
	std::string propertyValue;
	fileStream >> propertyValue;
	std::cout << "\t -" << propertyName << " was loaded as " << propertyValue << std::endl;
}