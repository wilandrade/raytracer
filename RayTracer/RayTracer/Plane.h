#pragma once
#include "Primitive.h"


class Material;

class Plane : public Primitive
{
	private:
		double mDValue; //distance to the closest point on the plane from the origin
		Vector3 mNormal; //plane normal

		Material * mMaterial; //pointer to material used by object

	public:
		virtual void PrintType()const;
		virtual const std::string & GetTypeName()const;
		virtual void ProcessProperty(std::ifstream& fileStream, std::string propertyName);
		virtual double CheckForHit(const Vector3& rayOrigin, const Vector3& rayDirection)const;
		virtual Color3 GetColor(const HitRecord& hit);
		virtual const Vector3 GetNormal(const Vector3& hitPoint)const;
};