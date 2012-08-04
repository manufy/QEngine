// QModelKeyframed.cpp: implementation of the QModelKeyframed class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "QModelKeyframed.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

QModelKeyframed::QModelKeyframed(unsigned int MaxFrames, QEngine *pEngine) : QModel(pEngine) , QHoleManager(MaxFrames)
{
	m_pFrames = new QFrame*[MaxFrames];
}

QModelKeyframed::~QModelKeyframed()
{
	if (m_pFrames)
	{
		for (unsigned i=0; i < m_NumElements;i++)
			delete m_pFrames[i];
		delete [] m_pFrames;
	}
	
}

void QModelKeyframed::Render(unsigned int FrameID)
{
	m_pFrames[FrameID]->Render();
}

int QModelKeyframed::AddFrame(QFrame *pFrame)
{
	unsigned int Index = GetNextIndex();
	m_pFrames[Index] = pFrame;
	m_NumElements++;
	return (Index);
}

QModelKeyframed::QModelKeyframed(QEngine *pEngine) : QModel(pEngine), QHoleManager(MAX_KEYFRAMES_PER_MODEL)
{
	m_pFrames = NULL;
}
