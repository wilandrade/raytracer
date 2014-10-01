#include "Camera.h"


Camera::Camera()
{
}

Camera::~Camera()
{
	
}

void Camera::ProcessProperty(std::ifstream& fileStream, std::string propertyName)
{
	if(propertyName == "worldUp")
	{
		fileStream >> m_WorldUp.x;
		fileStream >> m_WorldUp.y;
		fileStream >> m_WorldUp.z;
		std::cout << "\t -Camera::" << propertyName << " was loaded as " << m_WorldUp << std::endl;
	}
	else if(propertyName == "eye")
	{
		fileStream >> m_Eye.x;
		fileStream >> m_Eye.y;
		fileStream >> m_Eye.z;
		std::cout << "\t -Camera::" << propertyName << " was loaded as " << m_Eye << std::endl;
	}
	else if(propertyName == "fov")
	{
		fileStream >> m_FOV;
		std::cout << "\t -Camera::" << propertyName << " was loaded as " << m_FOV << std::endl;
	}
	else if(propertyName == "fstop")
	{
		fileStream >> m_FSTOP;
		std::cout << "\t -Camera::" << propertyName << " was loaded as " << m_FSTOP << std::endl;
	}
	else if(propertyName == "lookAt")
	{
		fileStream >> m_LookAt.x;
		fileStream >> m_LookAt.y;
		fileStream >> m_LookAt.z;
		std::cout << "\t -Camera::" << propertyName << " was loaded as " << m_LookAt << std::endl;
	}
	else
		Entity::ProcessProperty(fileStream, propertyName);
}

const Vector3& Camera::GetEye()const
{
	return m_Eye;
}

const Vector3& Camera::GetLookAt()const
{
	return m_LookAt;
}

double Camera::GetFOV()const
{
	return m_FOV;
}

const Vector3& Camera::GetWorldUp()const
{
	return m_WorldUp;
}

void Camera::SetEye(const Vector3& eye)
{
	m_Eye = eye;
}

void Camera::SetLookAt(const Vector3& lookAt)
{
	m_LookAt = lookAt;
}

void Camera::SetWorldUp(const Vector3& worldUp)
{
	m_WorldUp = worldUp;
}

void Camera::SetFOV(double fov)
{
	m_FOV = fov;
}