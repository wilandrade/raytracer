#include <iostream>
#include <fstream>
#include <string>
#include "Primitive.h"
#include "Light.h"
#include "Material.h"
#include "Camera.h"

#include "Scene.h"
#include "PrimitiveFactoryDepot.h"
#include "LightFactoryDepot.h"
#include "MaterialFactoryDepot.h"


Scene::Scene()
{
	//Register Primitive Factories
	PRIMITIVE_FACTORY_DEPOT->RegisterFactoryDepot("Sphere", SphereFactory::GetInstance());
	PRIMITIVE_FACTORY_DEPOT->RegisterFactoryDepot("Plane", PlaneFactory::GetInstance());
	
	//Register Light Factories
	LIGHT_FACTORY_DEPOT->RegisterFactoryDepot("PointLight", PointLightFactory::GetInstance());
	LIGHT_FACTORY_DEPOT->RegisterFactoryDepot("DirectionalLight", DirectionalLightFactory::GetInstance());

	//Register Material Factories
	MATERIAL_FACTORY_DEPOT->RegisterFactoryDepot("DiffuseMaterial", DiffuseMaterialFactory::GetInstance());
	MATERIAL_FACTORY_DEPOT->RegisterFactoryDepot("SpecularMaterial", SpecularMaterialFactory::GetInstance());
	
	mCamera = new Camera();
}

Scene::~Scene()
{
	mObjectList.clear();

}

const Color3& Scene::GetBackgroundColor()const
{
	return mBackgroundColor;
}

void Scene::SetBackgroundColor(const Color3& bgColor)
{
	mBackgroundColor = bgColor;
}

const std::list<Primitive*>& Scene::GetObjectList()const
{
	return mObjectList;
}

const std::list<Light*>& Scene::GetLightList()const
{
	return mLightList;
}

Camera* Scene::GetCamera()const
{
	return mCamera;
}

void Scene::LoadScene(const std::string &fileName)
{
	std::string stringToken; //buffer for the string we're reading from the file stream
	std::ifstream fileStream (fileName.c_str()); //file that we're streaming

	Entity* entity=0;//will hold the current entity that we're loading
	
	std::string propertiesStartDelimiter = "{"; //delimiter used to see if we're beginning the property definitions

	if (fileStream.is_open()) //check if file is open
	{
		while (! fileStream.eof() )//keep looping until we reach the end of the file
		{
			fileStream >> stringToken; //get the next token from the script file
			if(stringToken == propertiesStartDelimiter) //if the token is the delimiter used to begin properties scope
			{
				entity->LoadProperties(fileStream); //load all of the properties
			}
			else //this is the object type
			{
				if(stringToken == "Sphere" || stringToken == "Plane")//check for primitive
				{
					entity = PRIMITIVE_FACTORY_DEPOT->CreatePrimitive(stringToken); //create a primitive
					mObjectList.push_back(dynamic_cast<Primitive*>(entity)); //push it onto the scene object list
				}
				else if(stringToken == "PointLight" || stringToken == "DirectionalLight") //check for primitive
				{
					entity = LIGHT_FACTORY_DEPOT->CreateLight(stringToken); //create a light
					mLightList.push_back(dynamic_cast<Light*>(entity)); ////push it onto the scene light list
				}
				else if(stringToken == "Camera")
				{
					entity = GetCamera();
				}

			}


		}
		fileStream.close(); //close files
	}

	else std::cout << "Unable to open file";

}


/*Iterate through the scene and print out each of its types*/
void Scene::PrintSceneTypes()
{
	std::list<Primitive*>::iterator iter;
	for (iter = mObjectList.begin(); iter != mObjectList.end(); iter++)
	{
		(*iter)->PrintType();
		std::cout << "\n";
	}

	std::list<Light*>::iterator iter2;
	for (iter2 = mLightList.begin(); iter2 != mLightList.end(); iter2++)
	{
		(*iter2)->PrintType();
		std::cout << "\n";
	}



}