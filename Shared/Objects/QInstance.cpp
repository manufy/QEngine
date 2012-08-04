// QInstance.cpp: implementation of the QInstance class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "QInstance.h"

#include "..\..\Graphics\Objects\QActor.h"
#include "..\..\Graphics\Managers\QActorManager.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

QInstance::QInstance(QActorManager *pActorManager,int ActorIndex, float x, float y, float z)
{
	m_pActorManager = pActorManager;
	m_pActor = m_pActorManager->m_pActors[ActorIndex];
	m_Pos.x = x;
	m_Pos.y = y;
	m_Pos.z = z;

}

QInstance::~QInstance()
{

}

void QInstance::Render()
{
	glPushMatrix();
	glTranslated(m_Pos.x,m_Pos.y,m_Pos.z);	
	m_pActor->Render();
	glPopMatrix();
}
