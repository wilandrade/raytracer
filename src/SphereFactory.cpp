#include "SphereFactory.h"
#include "Sphere.h"


SphereFactory::SphereFactory()
{}

SphereFactory::~SphereFactory()
{}

Primitive* SphereFactory::CreatePrimitive()
{
	Primitive* sphere = new Sphere();

	return sphere;
}