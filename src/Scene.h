#pragma once

#include <list>
#include "Vector3.h"

class Entity;
class Primitive;
class Light;
class Material;
class Camera;
class string;

class Scene
{
	public:
		Scene();
		~Scene();
		void LoadScene(const std::string &fileName);
		void PrintSceneTypes();

		Camera* GetCamera()const;
		const Color3& GetBackgroundColor()const;

		void SetBackgroundColor(const Color3& bgColor);

		const std::list<Primitive*>& GetObjectList()const;
		const std::list<Light*>& GetLightList()const;

		Color3 mAmbientLight;

	private:
		std::list<Primitive*> mObjectList;
		std::list<Light*> mLightList;
		Camera* mCamera;
		Color3 mBackgroundColor;
		
};