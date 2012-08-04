// Vector3.h: interface for the CVector3 class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_VECTOR3_H__AD97D0E5_3031_46A6_BCEB_7BAA0148D556__INCLUDED_)
#define AFX_VECTOR3_H__AD97D0E5_3031_46A6_BCEB_7BAA0148D556__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

//#include "ostream.h"
#include "math.h"

class CVector3  
{

// Entrada / Salida

//friend ostream& operator<<(ostream &, const CVector3 &);

public:

	// Constructores y destructores
		
	virtual ~CVector3();
	CVector3(const float x=0, float y=0, float z=0) : x(x), y(y), z(z) { }
	CVector3(const CVector3 &V) : x(V.x), y(V.y), z(V.z) { }
	const CVector3& operator = (const CVector3& V)
	{	x = V.x;
		y = V.y;
		z = V.z;
		return *this;
	}

	//	Operaciones Booleanas

	const bool operator == (const CVector3& Vector) const
	{	return (x == Vector.x && y == Vector.y && z == Vector.z);
	}
	const bool operator != (const CVector3& Vector) const
	{	return !(*this == Vector);
	}

	// Suma, Resta, Positivo, Negativo

	const CVector3 operator + (const CVector3& Vector) const
	{	return CVector3(x + Vector.x, y + Vector.y, z + Vector.z);
	}
	const CVector3 operator + () const
	{	return CVector3(*this);
	}
	const CVector3& operator += (const CVector3& Vector)
	{	x += Vector.x;
		y += Vector.y;
		z += Vector.z;
		return *this;
	}
	const CVector3 operator - (const CVector3& Vector) const
	{	return CVector3(x - Vector.x, y - Vector.y, z - Vector.z);
	}
	const CVector3 operator - () const
	{	return CVector3(-x, -y, -z);
	}
	const CVector3 &operator -= (const CVector3& Vector)
	{	x -= Vector.x;
		y -= Vector.y;
		z -= Vector.z;
		return *this;
	}

	//	Multiplicacion y division

	const CVector3 operator * (const CVector3& Vector) const
	{	return CVector3(x * Vector.x, y * Vector.y, z * Vector.z);
	}
	const CVector3& operator *= (const CVector3& Vector)
	{	x *= Vector.x;
		y *= Vector.y;
		z *= Vector.z;
		return *this;
	}
	const CVector3 operator * (const float d) const
	{	return CVector3(x * d, y * d, z * d);
	}
	const CVector3& operator *= (const float d)
	{	x *= d;
		y *= d;
		z *= d;
		return *this;
	}
	const CVector3 operator / (const CVector3& Vector) const
	{	return CVector3(x / Vector.x, y / Vector.y, z / Vector.z);
	}
	const CVector3 &operator /= (const CVector3& Vector)
	{	x /= Vector.x;
		y /= Vector.y;
		z /= Vector.z;
		return *this;
	}
	const CVector3 operator / (const float d) const
	{	const float _d = 1.0f / d;
		return CVector3(x * _d, y * _d, z * _d);
	}
	const CVector3& operator /= (const float d)
	{	const float _d = 1.0f / d;
		x *= _d;
		y *= _d;
		z *= _d;
		return *this;
	}

	//	Dot Product

	const float operator % (const CVector3& Vector) const
	{	return x*Vector.x + y*Vector.y + z*Vector.z;
	}
	//	Cruz

	const CVector3 operator ^ (const CVector3& Vector) const
	{	return CVector3(
				y * Vector.z - Vector.y * z,
				z * Vector.x - Vector.z * x,
				x * Vector.y - Vector.x * y);
	}
	const CVector3& operator ^= (const CVector3& Vector)
	{	return *this = *this ^ Vector;
	}

	//	Normalizacion

	const float operator ! () const
	{	return sqrtf(x*x + y*y + z*z);
	}
	const CVector3 operator | (const float dLength) const
	{	return *this * (dLength / !*this);
	}
	const CVector3& operator |= (const float dLength)
	{	return *this = *this | dLength;
	}

	//
	//	Funciones avanzadas
	//

	//	Angulo entre 2 vectores (rad)

	const float inline Angle(const CVector3& Normal) const
	{	return acosf(*this % Normal);
	}
	//	Reflejar con respecto al vector normal

	const CVector3 inline Reflection(const CVector3& Normal) const
	{	const CVector3 V(*this | 1);
		return (V - Normal * 2.0 * (V % Normal)) * !*this;
	}
	//	Rotar dAngle (rad) alrededor de la Normal

	const CVector3 inline Rotate(const float dAngle, const CVector3& Normal) const
	{	const float dCos = cosf(dAngle);
		const float dSin = sinf(dAngle);
		return CVector3(
				*this * dCos +
				((Normal * *this) * (1.0f - dCos)) * Normal +
				(*this ^ Normal) * dSin);
	}


	float x;
	float y;
	float z;
};

#endif // !defined(AFX_VECTOR3_H__AD97D0E5_3031_46A6_BCEB_7BAA0148D556__INCLUDED_)

