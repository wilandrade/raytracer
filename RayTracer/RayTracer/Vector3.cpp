#include "Vector3.h"

#define PI 3.14159265





void Vector3::SetVector(double _x, double _y, double _z)
{
x=_x;
y=_y;
z=_z;

}
void Vector3::SetVector(Vector3 v)
{
	x=v.x;
	y=v.y;
	z=v.z;

}

ostream & operator<<(ostream &o, const Vector3 &V)
{
    o << "<" << V.x << ", " << V.y << ", " << V.z << ">";
    return o;
}


void Vector3::NormalizeVector()
{
    double length = 1/GetLength();

    *this = *this*length;   
}



double Vector3::Dot(Vector3 v)const//returns a number!
{
    return (x*v.x + y*v.y + z*v.z);
}



Vector3 Vector3::Cross(Vector3 v)const //returns a vector
{
    Vector3 crossVector;
    crossVector.x = (y*v.z) - (z*v.y);
    crossVector.y = (z*v.x) - (x*v.z);
    crossVector.z = (x* v.y) - (y*v.x);   
    return crossVector;

}


double Vector3::GetLength(void)const
{
    double length = pow(x, 2) + pow(y, 2) + pow(z, 2);
    return sqrt(length);
}




Vector3 Vector3::operator =(const Vector3 &right)
{
    SetVector(right);
    return *this;
}
Vector3 Vector3::operator =(const double &right)
{
    SetVector(right, right, right);
    return *this;
}


bool Vector3::operator ==(const Vector3 &right)const
{
    if(x != right.x)
        return false;
    if(y != right.y)
        return false;
    if(z != right.z)
        return false;

    return true; //this will return true if everything else is passed
}

bool Vector3::operator !=(const Vector3 &right)const
{
    if(*this == right)
        return false;
    else
        return true;
}
Vector3 Vector3::operator +(const Vector3 &right)const
{
    return Vector3(x+right.x, y+right.y, z+right.z);
}
Vector3 Vector3::operator -(const Vector3 &right)const
{
    return Vector3(x-right.x, y-right.y, z-right.z);
}
Vector3 Vector3::operator *(const double &scale)const
{
    return Vector3(x*scale, y*scale, z*scale);
}
Vector3 Vector3::operator /(const double &scale)const
{
    return (*this * (1/scale));
}

Vector3 Vector3::operator +=(const Vector3 &right)
{
    *this = *this + right;
    return *this;
}

Vector3 Vector3::operator -=(const Vector3 &right)
{
    *this = *this - right;
    return *this;
}
Vector3 Vector3::operator *=(const double &right)
{
    *this = *this * right;
    return *this;
}
Vector3 Vector3::operator /=(const double &right)
{
    *this = *this / right;
    return *this;
}