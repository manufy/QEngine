/** \file QInstance.h 
    \author Manuel Fernández Yáñez
    \date Enero-Julio 2003
    \brief Instancia de modelo 3D
	
**/
#if !defined(AFX_QINSTANCE_H__722B7383_0B29_4801_8A77_CD37D014E615__INCLUDED_)
#define AFX_QINSTANCE_H__722B7383_0B29_4801_8A77_CD37D014E615__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


#include "..\Math\Vector3.h"


class QActor;
class QActorManager;

class QInstance  
{
public:
	void Render();
	QInstance(QActorManager *pActorManager,int ActorIndex, float x, float y, float z);
	virtual ~QInstance();

	QActor	*m_pActor;
	QActorManager *m_pActorManager;

	CVector3 m_Pos;
	CVector3 m_Rot;
	CVector3 m_Dir;
	CVector3 m_Scale;
};

#endif // !defined(AFX_QINSTANCE_H__722B7383_0B29_4801_8A77_CD37D014E615__INCLUDED_)
