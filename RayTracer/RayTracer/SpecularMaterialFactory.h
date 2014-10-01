#pragma once
#include "MaterialFactory.h"

class Material;

class SpecularMaterialFactory : public MaterialFactory
{
	private:
		SpecularMaterialFactory();
		~SpecularMaterialFactory();

	public:
		virtual Material* CreateMaterial();

		static MaterialFactory* GetInstance()
		{
			static MaterialFactory* s_pInstance = new SpecularMaterialFactory(); 
			return s_pInstance;
		}

		



};