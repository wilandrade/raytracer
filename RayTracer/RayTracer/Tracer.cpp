#include "Tracer.h"
#include "Scene.h"
#include "Camera.h"
#include "Vector3.h"
#include "Primitive.h"
#include "HitRecord.h"


void Tracer::SetCurrentScene(Scene* curScene)
{
	mCurScene = curScene;
}

const Scene* Tracer::GetCurrentScene()const
{
	return mCurScene;
}


//This function changes the request of the trace to the way it really works.
//It converts the trace from pixel coordinates to normalized coordinates
const Color3& Tracer::Trace(double nx, double ny)
{
	Color3 theColor = Vector3(0,0,0); //color found by the trace

	Vector3 lookAtVec; //The vector from the camera to the lookAt point
	lookAtVec = mCurScene->GetCamera()->GetLookAt() - mCurScene->GetCamera()->GetEye();

	Vector3 uVec; //The right vector of the plane
	Vector3 up = mCurScene->GetCamera()->GetWorldUp(); //assumes GetWorldUp returns a normalized vector
	uVec = up.Cross(lookAtVec);
	uVec.NormalizeVector();


	Vector3 vVec; //The up vector of the plane
	vVec = lookAtVec.Cross(uVec);
	vVec.NormalizeVector();

	double tempRand = 0; //random number holder
	double precision = 10.0;//magic number
	double lensRadius = lookAtVec.GetLength() / (2 * mCurScene->GetCamera()->m_FSTOP); //samples will be taken from within a disk area. This is the disk's radius
	int totalSamples = 1;
	Vector3 theEye; //camera pos
	
	
	//DO DEPTH OF FIELD
	for(int curSample = 0; curSample < totalSamples; curSample++)
	{
		
		theEye = mCurScene->GetCamera()->GetEye();
		
		//TODO: USE MORE ACCURATE RANDOM NUMBER (RAND() / RAND_MAX)
		//x component
		tempRand = (rand() % ((int)precision*2)) - precision;
		tempRand /= precision;
		theEye +=  uVec * lensRadius * tempRand;

		//y component
		tempRand = (rand() % ((int)precision*2)) - precision;
		tempRand /= precision; //normalize random number
		theEye += vVec * lensRadius * tempRand;
		
		lookAtVec = mCurScene->GetCamera()->GetLookAt() - theEye; //get the new lookAt with the jittered eye position


		double distToPoint; //The distance from the camera to the lookAt point
		distToPoint = lookAtVec.GetLength();
		
		double radiansFOV; //the FOV of the camera in radians
		radiansFOV = mCurScene->GetCamera()->GetFOV() * PI / 180.0;


		double scale; //The scale of the viewing cone
		scale = 2 * distToPoint * tan( radiansFOV / 2.0 );

		

		//S = ( lookAtDirection + scale ( nx - 0.5 ) uVec + ( scale ( 0.5 - ny ) vVec ) / aspectRatio )
		//Formula from Paul Edmondson, Programming for Computer Graphics
		Vector3 S; //Point we're sampling from
		S = mCurScene->GetCamera()->GetLookAt() + ( uVec * scale * ( nx - 0.5 ) ) + ( vVec * scale * ( 0.5 - ny ) );
		
		Vector3 theView; //camera view vec
		theView = S - theEye;
		theView.NormalizeVector();

		theColor += Trace(theEye, theView)/(double)totalSamples;
	}

	return theColor;
}

const Color3& Tracer::Trace(const Vector3& eye, const Vector3& view)
{
	
	std::list<Primitive*> objectList = mCurScene->GetObjectList();
	std::list<Primitive*>::iterator iter;
	
	Primitive* closestObject = 0; //object hit by ray that is closest to the plane
	double closestDistance = DOUBLE_MAX; //the closest distance that was hit by the ray

	
	//Check each object and see if it intersects with the ray
	for (iter = objectList.begin(); iter != objectList.end(); iter++)
	{
		double hitDist = (*iter)->CheckForHit(eye, view); //returns the hit distance, DOUBLE_MAX if no hit
		if(hitDist < closestDistance)
		{
			closestObject = (*iter);
			closestDistance = hitDist;
		}
	}
	
	if(closestObject)//if nothing was hit
	{
		HitRecord hit;
		hit.mHitPoint = eye + view * closestDistance;
		hit.mHitPrimitive = closestObject;
		hit.mNormal = closestObject->GetNormal(hit.mHitPoint);
		hit.mRayDirection = view;
		hit.mRayOrigin = eye;
		hit.recurseDepth = 1;

		return closestObject->GetColor(hit);
	}

	return mCurScene->GetBackgroundColor();

	
}

const Color3& Tracer::ReflectionTrace(const HitRecord& hit, const Vector3& reflectionVec)
{
	
	std::list<Primitive*> objectList = mCurScene->GetObjectList();
	std::list<Primitive*>::iterator iter;
	
	Primitive* closestObject = 0; //object hit by ray that is closest to the plane
	double closestDistance = DOUBLE_MAX; //the closest distance that was hit by the ray

	
	//Check each object and see if it intersects with the ray
	for (iter = objectList.begin(); iter != objectList.end(); iter++)
	{
		double bias = 0.003;
		double hitDist = (*iter)->CheckForHit(hit.mHitPoint, reflectionVec); //returns the hit distance, DOUBLE_MAX if no hit
		if(hitDist < closestDistance && hitDist > bias)
		{
			closestObject = (*iter);
			closestDistance = hitDist;
		}
	}
	
	if(closestObject)//if nothing was hit
	{
		HitRecord newHit;
		newHit.mHitPoint = hit.mHitPoint + reflectionVec * closestDistance;
		newHit.mHitPrimitive = closestObject;
		newHit.mNormal = closestObject->GetNormal(hit.mHitPoint);
		newHit.mRayDirection = reflectionVec;
		newHit.mRayOrigin = hit.mHitPoint;
		newHit.recurseDepth = hit.recurseDepth;
		return closestObject->GetColor(newHit);
	}

	return mCurScene->GetBackgroundColor();

	
}

bool Tracer::ShadowTrace(const Vector3& rayOrigin, const Vector3& rayDirection, double maxDist)
{
	std::list<Primitive*> objectList = mCurScene->GetObjectList();
	std::list<Primitive*>::iterator iter;
	
	double bias = 0000.3; //the closest distance that was hit by the ray

	
	//Check each object and see if it intersects with the ray
	for (iter = objectList.begin(); iter != objectList.end(); iter++)
	{
		double hitDist = (*iter)->CheckForHit(rayOrigin, rayDirection); //returns the hit distance, DOUBLE_MAX if no hit
		if(hitDist > bias && hitDist < maxDist)
		{
			return true; //point is occluded
		}
	}

	return false;//point is not occluded

	
}