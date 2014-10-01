#pragma once
#include "MaterialFactory.h"

class Material;

class DiffuseMaterialFactory : public MaterialFactory
{
	private:
		DiffuseMaterialFactory();
		~DiffuseMaterialFactory();

	public:
		virtual Material* CreateMaterial();

		static MaterialFactory* GetInstance()
		{
			static MaterialFactory* s_pInstance = new DiffuseMaterialFactory(); 
			return s_pInstance;
		}

		



};