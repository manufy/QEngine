// Matrix4.h: interface for the CMatrix4 class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MATRIX4_H__E6AB149B_7E65_4161_9FED_D983FD11DF75__INCLUDED_)
#define AFX_MATRIX4_H__E6AB149B_7E65_4161_9FED_D983FD11DF75__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

//#include "ostream.h"
#include "Vector3.h"
#include "Quaternion.h"

class CMatrix4  
{

//friend ostream& operator<<(ostream &, const CMatrix4 &);

public:
	void SetInverseRotationRadians(CVector3 v);
	void SetInverseRotationDegrees(CVector3 v);
	void SetRotationRadians(CVector3 v);
	void SetRotationDegrees(CVector3 v );
	void SetInverseTranslation(CVector3 t );
	void SetTranslation(CVector3 t);
	void CreateFromAxisAngle(CVector3 axis, float theta);
	bool Inverse(CMatrix4 &m2);
	void RotateZ(float Angle);
	void RotateY(float Angle);
	void RotateX(float Angle);
	void Rotate(float angle, CVector3 v);
	CMatrix4 operator*(CMatrix4 &m2);

	CMatrix4 operator /(float n);
	CMatrix4 operator *(float n);
	CVector3 operator*(CVector3 v);
//	CVector3 operator*(CVector3  v,CMatrix4 &m);
	void Translate(float x, float y, float z);
	void Translate(CVector3 v);
	CMatrix4 operator-(CMatrix4 &m2);
	CMatrix4 operator+(CMatrix4 &m2);
	void     operator +=(CMatrix4 &m2);
	void     operator -=(CMatrix4 &m2);
	void RotateVector(CVector3 *v);
	void TranslateVector(CVector3 *v);

	CMatrix4 Transpose();
	void LoadZero();
	void LoadIdentity();
	CMatrix4();
	virtual ~CMatrix4();

	CMatrix4 operator =(CMatrix4 &m2);

	float m_Matrix[16];
};

#endif // !defined(AFX_MATRIX4_H__E6AB149B_7E65_4161_9FED_D983FD11DF75__INCLUDED_)
