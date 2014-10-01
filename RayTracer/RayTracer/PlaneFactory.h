#pragma once
#include "PrimitiveFactory.h"

class string;
class Primitive;

class PlaneFactory : public PrimitiveFactory
{
	private:
		PlaneFactory();
		~PlaneFactory();

	public:
		virtual Primitive* CreatePrimitive();

		static PrimitiveFactory* GetInstance()
		{
			static PrimitiveFactory* s_pInstance = new PlaneFactory(); 
			return s_pInstance;
		}

		



};