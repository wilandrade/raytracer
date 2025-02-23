#include <iostream>
#include "Plane.h"
#include "Material.h"
#include "MaterialFactoryDepot.h"


Color3 Plane::GetColor(const HitRecord& hit)
{
	return mMaterial->GetColor(hit);
}

const Vector3 Plane::GetNormal(const Vector3 &hitPoint)const
{
	return mNormal;
}

double Plane::CheckForHit(const Vector3& rayOrigin, const Vector3& rayDirection)const
{
	double hitDist = DOUBLE_MAX;

	double Vd = rayDirection.Dot(mNormal);
    if(Vd >= 0) //IF PLANE IS PARALLEL TO RAY
        return DOUBLE_MAX;
    else
	{
		double Vo = -1 * (rayOrigin.Dot(mNormal) + mDValue);
		hitDist = Vo/Vd;

		if(hitDist < 0)
			return DOUBLE_MAX;
		else
			return hitDist;
	}





	return hitDist;
}

void Plane::ProcessProperty(std::ifstream& fileStream, std::string propertyName)
{
	if(propertyName == "dValue")
	{
		fileStream >> mDValue;
		std::cout << "\t -" << propertyName << " was loaded as " << mDValue << std::endl;
	}
	else if(propertyName == "normal")
	{
		fileStream >> mNormal.x;
		fileStream >> mNormal.y;
		fileStream >> mNormal.z;
		std::cout << "\t -" << propertyName << " was loaded as " << mNormal << std::endl;
	}
	else if(propertyName == "material")
	{
		std::string propertyValue;
		fileStream >> propertyValue;

		if(propertyValue == "diffuse")
			mMaterial = MATERIAL_FACTORY_DEPOT->CreateMaterial("DiffuseMaterial");
	}
	else
		Entity::ProcessProperty(fileStream, propertyName);
}

void Plane::PrintType()const
{
	std::cout << "Plane";
}

const std::string & Plane::GetTypeName()const
{
	static std::string name = "Plane";
	return name;
}