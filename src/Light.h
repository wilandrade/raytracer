#pragma once
#include "Entity.h"
#include "HitRecord.h"
#include "LightRecord.h"


class Light : public Entity
{
	public:
		virtual void PrintType()=0;
		virtual const std::string & GetTypeName()=0;
		virtual LightRecord GetLightInfo(const HitRecord& hit)=0;
};