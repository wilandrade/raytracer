#include "Entity.h"
#include "Vector3.h"


class Camera : public Entity
{
	private:
		Vector3 m_Eye;
		Vector3 m_LookAt;
		Vector3 m_WorldUp;
		
		double m_camLensRadius;
		double m_FOV;
		

	public:
		Camera();
		~Camera();

		double m_FSTOP;
		
		
		virtual void ProcessProperty(std::ifstream& fileStream, std::string propertyName);

		const Vector3& GetEye()const;
		const Vector3& GetLookAt()const;
		const Vector3& GetWorldUp()const;
		double GetFOV()const;

		void SetEye(const Vector3& eye);
		void SetLookAt(const Vector3& lookAt);
		void SetWorldUp(const Vector3& up);
		void SetFOV(double fov);

};