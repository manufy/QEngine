// QInstanceManager.cpp: implementation of the QInstanceManager class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "QInstanceManager.h"

#include "..\TDA\QHoleNode.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

QInstanceManager::QInstanceManager(QActorManager *pActorManager,int NumInstances) : QHoleManager(NumInstances)
{
	m_pActorManager = pActorManager;
	m_pInstances = new QInstance*[NumInstances];	// Inicializa array de instancias
}

QInstanceManager::~QInstanceManager()
{
	delete [] m_pInstances;
}

void QInstanceManager::Remove(int Index)
{
	QHoleNode *pHole	= new QHoleNode(Index,m_pHolesQueue); // Crea e inserta hueco
	delete m_pInstances[Index];
	m_NumElements--;
}

void QInstanceManager::Render()
{
	// Renderiza SOLO LOS OBJETOS ACTIVOS, JOJOJOOJI OJOJOJO 
	// va a fallar cuando hayya: 2 inserciones, 1 borrado

	for (unsigned int i=0;i<m_NumElements;i++)
	{
		m_pInstances[i]->Render();

	}
}
