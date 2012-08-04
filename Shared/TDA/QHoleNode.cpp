// QHoleNode.cpp: implementation of the CHoleNode class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "QHoleNode.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

QHoleNode::QHoleNode()
{
	m_pNext = NULL;
	m_Index   = 0;
}

QHoleNode::~QHoleNode()
{
	//delete m_pNext;
}

QHoleNode::QHoleNode(int Index,QHoleNode *Queue)
{
	m_Index	= Index;	// Ajusta punteros 
	m_pNext = Queue;
	Queue   = this;
}
