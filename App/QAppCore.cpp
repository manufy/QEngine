// QAppCore.cpp: implementation of the QAppCore class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "QAppCore.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

QAppCore::QAppCore(QAppWin32 *pAppWin32)
{
	// Inicializa punteros

	pAppWin32->m_pAppCore	= this;
	m_pEngine				= pAppWin32->m_pEngine;
	m_pInputManager			= pAppWin32->m_pInputManager;
	m_pLog					= pAppWin32->m_pLog;
	// Fuente del sistema

}

QAppCore::~QAppCore()
{

}

void QAppCore::Cycle(float DeltaTime)
{

}

void QAppCore::Render()
{

}
