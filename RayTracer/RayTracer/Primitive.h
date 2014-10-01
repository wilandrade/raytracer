#pragma once
#include "Entity.h"
#include "Vector3.h"
#include "HitRecord.h"

class Primitive : public Entity
{
	public:
		virtual void PrintType()const = 0;
		virtual const std::string& GetTypeName()const = 0;
		virtual Color3 GetColor(const HitRecord& hit) = 0;
		virtual double CheckForHit(const Vector3& rayOrigin, const Vector3& rayDirection)const = 0;
		virtual const Vector3 GetNormal(const Vector3& hitPoint)const = 0;
};