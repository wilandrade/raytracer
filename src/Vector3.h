#pragma once

#define PI 3.14159265
#define DOUBLE_MAX 1.7976931348623158e+308 /* max value */

#include <iostream>
#include <fstream>
#include <cmath>

using std::ostream;


class Vector3
{
    public:
    Vector3(){x=0; y=0; z=0;}
    Vector3(double _x, double _y, double _z){x=_x; y=_y; z=_z;}
    ~Vector3(){}

	void SetVector(double _x, double _y, double _z);
	void SetVector(Vector3 v);
    
    double GetLength(void)const;

    void NormalizeVector();


	friend ostream & operator<<(ostream &o, const Vector3 &V);
	double Dot(Vector3 v)const;
	Vector3 Cross(Vector3 v)const;
	Vector3 operator =(const Vector3 &right);
	Vector3 operator =(const double &right);
	bool operator ==(const Vector3 &right)const;
	bool operator !=(const Vector3 &right)const;
	Vector3 operator +(const Vector3 &right)const;
	Vector3 operator -(const Vector3 &right)const;
	Vector3 operator *(const double &scale)const;
	Vector3 operator /(const double &scale)const;
	Vector3 operator +=(const Vector3 &right);
	Vector3 operator -=(const Vector3 &right);
	Vector3 operator *=(const double &right);
	Vector3 operator /=(const double &right);


    double x;
    double y;
    double z;


};

typedef Vector3 Color3;