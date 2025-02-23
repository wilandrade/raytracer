#pragma once
#include "Entity.h"
#include "Vector3.h"
#include "HitRecord.h"

class Material : public Entity
{
	public:
		virtual void PrintType()=0;
		virtual const std::string & GetTypeName()=0;
		virtual Color3 GetColor(const HitRecord& hit)=0;
};