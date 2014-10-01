#include <iostream>
#include "Sphere.h"
#include "Material.h"
#include "MaterialFactoryDepot.h"




const Vector3 Sphere::GetNormal(const Vector3& hitPoint)const
{
	Vector3 normal;
	normal =  hitPoint - mPosition;
	normal.NormalizeVector();

	return normal;
}

Color3 Sphere::GetColor(const HitRecord& hit)
{
	return mMaterial->GetColor(hit);
}


/*
Formula From: http://www.siggraph.org/education/materials/HyperGraph/raytrace/rtinter1.htm
This function assumes that parameter rayDirection is normalized.
*/
double Sphere::CheckForHit(const Vector3& rayOrigin, const Vector3& rayDirection)const
{

	double B,C; //A is not needed because it is always 1 (normalized)

	B = 2 * rayDirection.Dot( rayOrigin - mPosition );

	C = (rayOrigin - mPosition).Dot(rayOrigin - mPosition) - pow( mRadius, 2 );

	double D = pow( B , 2 ) - 4*C ; //discriminant... there's no A because it is always 1

	if(D < 0.0)
		return DOUBLE_MAX;
	else
		return ( -B - sqrt( D ) ) / 2;


}

void Sphere::ProcessProperty(std::ifstream& fileStream, std::string propertyName)
{
	
	
	if(propertyName == "radius")
	{
		fileStream >> mRadius;
		std::cout << "\t -Sphere::" << propertyName << " was loaded as " << mRadius << std::endl;
	}
	else if(propertyName == "position")
	{
		fileStream >> mPosition.x;
		fileStream >> mPosition.y;
		fileStream >> mPosition.z;
		std::cout << "\t -Sphere::" << propertyName << " was loaded as " << mPosition << std::endl;
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

void Sphere::PrintType()const
{
	std::cout << "Sphere";
}

const std::string & Sphere::GetTypeName()const
{
	static std::string name = "Sphere";
	return name;
}