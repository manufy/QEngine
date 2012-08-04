// Vector2.h: interface for the CVector2 class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_VECTOR2_H__E67FAE5D_D445_421C_8767_E3704E021009__INCLUDED_)
#define AFX_VECTOR2_H__E67FAE5D_D445_421C_8767_E3704E021009__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CVector2  
{
public:
	CVector2();
	virtual ~CVector2();

	CVector2(float X, float Y) 
	{ 
		x = X; y = Y;
	}

	
	CVector2 operator+(CVector2 vVector)	// Suma de vectores
	{ 
		return CVector2(vVector.x + x, vVector.y + y);
	}

	
	CVector2 operator-(CVector2 vVector) // Resta de vectores
	{
		return CVector2(x - vVector.x, y - vVector.y);
	}
	
	CVector2 operator*(float num)
	{
		return CVector2(x * num, y * num); // Multiplicacion por escalar
	}

	
	CVector2 operator/(float num) // Division por escalar
	{
		// Return the scale vector
		return CVector2(x / num, y / num);
	}

	float x, y;


};

#endif // !defined(AFX_VECTOR2_H__E67FAE5D_D445_421C_8767_E3704E021009__INCLUDED_)
