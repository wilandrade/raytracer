#pragma once
#include<string>

class Material;


class MaterialFactory
{
	public:
		virtual Material* CreateMaterial()=0;

};