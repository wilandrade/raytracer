#include "SpecularMaterialFactory.h"
#include "SpecularMaterial.h"


SpecularMaterialFactory::SpecularMaterialFactory()
{}

SpecularMaterialFactory::~SpecularMaterialFactory()
{}

Material* SpecularMaterialFactory::CreateMaterial()
{
	Material* specularMaterial = new SpecularMaterial();

	return specularMaterial;
}