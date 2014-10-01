#pragma once
#include<string>

class Light;


class LightFactory
{
	public:
		virtual Light* CreateLight()=0;

};