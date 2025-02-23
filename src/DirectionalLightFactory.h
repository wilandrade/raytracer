#pragma once
#include "LightFactory.h"

class Light;

class DirectionalLightFactory : public LightFactory
{
	private:
		DirectionalLightFactory();
		~DirectionalLightFactory();

	public:
		virtual Light* CreateLight();

		static LightFactory* GetInstance()
		{
			static LightFactory* s_pInstance = new DirectionalLightFactory(); 
			return s_pInstance;
		}

		



};