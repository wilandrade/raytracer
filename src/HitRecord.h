#pragma once
#include "Vector3.h"

class Primitive;

struct HitRecord
{
	Vector3 mHitPoint; //point of collision
	Vector3 mNormal; //normal of hit point
	Vector3 mRayOrigin; //origin of the ray cast
	Vector3 mRayDirection; //direction of the ray
	int recurseDepth; //amount of times the ray can bounce
	Primitive* mHitPrimitive; //primitive that was hit by ray

};