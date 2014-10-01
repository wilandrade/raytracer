#pragma once
#include "Vector3.h"

struct LightRecord
{
	Vector3 mIncidentVector; //light vector
	Color3 mLightColor; //color of the light
	double mLightIntensity; //intensity of the light
	bool bIsOccluded; //TEMP, GETTING RID OF THIS SOON WHEN OTHER LIGHTS DON'T NEED IT
	double mOcclusion; //holds average of multiple light samples

};