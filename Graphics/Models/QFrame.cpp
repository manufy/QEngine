// QFrame.cpp: implementation of the QFrame class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "QFrame.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

QFrame::QFrame(QEngine *pEngine,unsigned int MaxMeshes) : QHoleManager(MaxMeshes), QObject(pEngine)
{
	m_pMeshes = new QMesh*[MaxMeshes];
}

QFrame::~QFrame()
{
	for (unsigned int i=0; i<m_NumElements; i++)
	{
		delete m_pMeshes[i];

	}
	delete [] m_pMeshes;
}

void QFrame::Render()
{
	for (unsigned int i=0; i<m_NumElements; i++)
	{
		m_pMeshes[i]->Render();

	}
}

int QFrame::AddMesh(QMesh *pMesh)
{
	unsigned int Index = GetNextIndex();
	pMesh->m_pEngine = m_pEngine;
	m_pMeshes[Index] = pMesh;
	m_NumElements++;
	return (Index);
}

void QFrame::Dump(QLog *pLog)
{
	for (unsigned int i=0; i<m_NumElements; i++)
	{
		sprintf(pLog->m_Text, "	QFrame:         Frame\n");
		pLog->AddLine(pLog->m_Text); 
		m_pMeshes[i]->Dump(pLog);

	}
}