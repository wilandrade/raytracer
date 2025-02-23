#pragma once
#include "LightFactory.h"

class Light;

class PointLightFactory : public LightFactory
{
	private:
		PointLightFactory();
		~PointLightFactory();

	public:
		virtual Light* CreateLight();

		static LightFactory* GetInstance()
		{
			static LightFactory* s_pInstance = new PointLightFactory(); 
			return s_pInstance;
		}

		



};