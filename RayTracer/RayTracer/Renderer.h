#include <string>
#include "Vector3.h"

#define RENDERER Renderer::GetInstance()

class Scene;
class Renderer
{
	private:
		Renderer(){};
		~Renderer(){};
	public:
		void Render(Scene* scene, int w, int h);
		bool WriteToFile(std::string fileName, Color3 *pixelData, int w, int h);

		static Renderer* GetInstance()
		{
			static Renderer* s_pInstance = new Renderer(); 
			return s_pInstance;
		}
};