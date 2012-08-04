// QActor.cpp: implementation of the QActor class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "QActor.h"

#include "..\Models\QModelMD2.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

QActor::QActor(QEngine	*pEngine)
{
	m_pEngine = pEngine;
}

QActor::~QActor()
{

}

void QActor::Load(char *strFileName)
{
QModelMD2 *pMD2	= new QModelMD2(m_pEngine);
							pMD2->Load(strFileName);
							m_pModel = pMD2;
m_pModel->Import();
					
}

void QActor::Render()
{
//m_pModel->Animate(m_pModel->m_StateStart,m_pModel->m_StateEnd,0.9f);
}
