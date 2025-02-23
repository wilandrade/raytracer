#pragma once
#include<string>

class Primitive;


class PrimitiveFactory
{
	public:
		virtual Primitive* CreatePrimitive()=0;

};