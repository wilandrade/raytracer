#pragma once
#include "PrimitiveFactory.h"

class string;
class Primitive;

class SphereFactory : public PrimitiveFactory
{
	private:
		SphereFactory();
		~SphereFactory();

	public:
		virtual Primitive* CreatePrimitive();

		static PrimitiveFactory* GetInstance()
		{
			static PrimitiveFactory* s_pInstance = new SphereFactory(); 
			return s_pInstance;
		}

};

