#include "DiffuseMaterialFactory.h"
#include "DiffuseMaterial.h"


DiffuseMaterialFactory::DiffuseMaterialFactory()
{}

DiffuseMaterialFactory::~DiffuseMaterialFactory()
{}

Material* DiffuseMaterialFactory::CreateMaterial()
{
	Material* diffuseMaterial = new DiffuseMaterial();

	return diffuseMaterial;
}