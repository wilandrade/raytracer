#include "Vector3.h"

#define TRACER Tracer::GetInstance()

class Scene;
struct HitRecord;

class Tracer
{
	private:
		Tracer(){};
		~Tracer(){};

		Scene* mCurScene;
	
	public:
		Color3 Trace(double nx, double ny);
		Color3 Trace(const Vector3& eye, const Vector3& view);
		Color3 ReflectionTrace(const HitRecord& hit, const Vector3& reflectionVec);
		bool ShadowTrace(const Vector3& origin, const Vector3& direction, double maxDist);


		void SetCurrentScene(Scene* curScene);
		const Scene* GetCurrentScene()const;

		static Tracer* GetInstance()
		{
			static Tracer* s_pInstance = new Tracer(); 
			return s_pInstance;
		}
};