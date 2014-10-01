#include <time.h>
#include "Renderer.h"
#include "Scene.h"
#include "Camera.h"

int main()
{
	Scene* scene = new Scene();

	scene->LoadScene("SceneScript.txt");

	scene->SetBackgroundColor(Color3(0.0, 0.0, 0.0));
	scene->mAmbientLight = Color3( 0.0, 0.0, 0.0 ); //temporary flat shaded color for objects in the scene

	//Initialize random number generator
	srand((unsigned)time(0));
	
	RENDERER->Render(scene, 400, 400);

	return 0;
}