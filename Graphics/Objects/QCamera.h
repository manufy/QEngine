// QCamera.h: interface for the QCamera class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_QCAMERA_H__243ABEFF_AD44_4AAE_82CC_B6F33F06FFC5__INCLUDED_)
#define AFX_QCAMERA_H__243ABEFF_AD44_4AAE_82CC_B6F33F06FFC5__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


//#include "Frustrum.h"

#include "..\..\Shared\Math\Vector3.h"

class QCamera  
{
private:
		
							
public:
	void LoadStatus();
	void SaveStatus();
	void StrafeCamera(float speed);
	void SetViewFromKeys(bool Keys[]);
	void RotateAroundPoint(CVector3 vCenter, float angle, float x, float y, float z);
	void MoveCamera(float speed);
	void SetViewByMouse();
	void Look();
	void RotateView(float angle, float x, float y, float z);
	void PositionCamera(float px, float py, float pz, float vx, float vy, float vz, float ux, float uy, float uz);
	QCamera();
	virtual ~QCamera();

	CVector3 Position() {	return m_vPosition;		}
	CVector3 View()		{	return m_vView;			}
	CVector3 UpVector() {	return m_vUpVector;		}
	CVector3 Strafe()	{	return m_vStrafe;		}

//	CFrustrum Frustrum;
	CVector3 m_vPosition;					

	// Vector vista de la camara
	CVector3 m_vView;						

	// Verctor arriba
	CVector3 m_vUpVector;		
	
	// Vector strafe
	CVector3 m_vStrafe;		

	// Posiciones antiguas, grabadas para cambios de vista

	CVector3 m_vOldPosition;
	CVector3 m_vOldView;
	CVector3 m_vOldUpVector;
	CVector3 m_vOldStrafe;

	unsigned int m_InstanceAttached;		// Camara fija en una instancia de un actor o 0 si no (modo libre)
};

#endif // !defined(AFX_QCAMERA_H__243ABEFF_AD44_4AAE_82CC_B6F33F06FFC5__INCLUDED_)
