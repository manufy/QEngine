// Quaternion.h: interface for the CQuaternion class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_QUATERNION_H__AD0CF979_B35E_47E1_B3CF_CC0F44C16E26__INCLUDED_)
#define AFX_QUATERNION_H__AD0CF979_B35E_47E1_B3CF_CC0F44C16E26__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#define PI 3.14159

class CQuaternion  
{
public:
	void Reset();
	void Slerp(CQuaternion *c1, CQuaternion *c2,float a_fInterp);
	CQuaternion();	// Constructor por defecto: 0,0,0,1

	virtual ~CQuaternion();


	CQuaternion(float X, float Y, float Z, float W) // Constructor
	{ 
		x = X;		y = Y;		z = Z;		w = W;
	}

	
	void CreateFromAxisAngle(float X, float Y, float Z, float degree); // Convierte angulo-eje a quaternion

	
	void CreateMatrix(float *pMatrix);	// Quaternion a a matrix 4x4
	float x, y, z, w; // Valores 4D del Quaternion

	// Normalizacion 

	const void operator !();
	



private:
	
};

#endif // !defined(AFX_QUATERNION_H__AD0CF979_B35E_47E1_B3CF_CC0F44C16E26__INCLUDED_)
