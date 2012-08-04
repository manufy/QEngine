// HoleManager.cpp: implementation of the CHoleManager class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "QHoleManager.h"

#include "QHoleNode.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////


QHoleManager::~QHoleManager()
{
//	delete m_pHolesQueue;
}

QHoleManager::QHoleManager(unsigned int NumElements)
{
	m_MaxElements = 0;
	m_NumElements = 0;
	m_NumHoles	  = 0;
	m_pHolesQueue = NULL;
	m_NextElement = 0;
}

unsigned int QHoleManager::GetNextIndex()
{
 	if (m_pHolesQueue == NULL)
	{
		return m_NumElements;
	}
	else
	{
		return m_pHolesQueue->m_Index;
	}
}

unsigned int QHoleManager::GetNumElements()
{
	return m_NumElements;
}
