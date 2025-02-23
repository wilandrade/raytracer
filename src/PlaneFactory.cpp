#include "PlaneFactory.h"
#include "Plane.h"

//PrimitiveFactory* PlaneFactory::GetInstance();

PlaneFactory::PlaneFactory()
{}

PlaneFactory::~PlaneFactory()
{}

Primitive* PlaneFactory::CreatePrimitive()
{
	Primitive* plane = new Plane();

	return plane;
}