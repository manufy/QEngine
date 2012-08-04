// QTimerManager.cpp: implementation of the QTimerManager class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "QTimerManager.h"

#include "..\Objects\QTimer.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

QTimerManager::QTimerManager(): QHoleManager (MAX_TIMERS)
{
	LONGLONG perf_cnt;

	m_pTimers = new QTimer*[MAX_TIMERS];

	if (QueryPerformanceFrequency((LARGE_INTEGER *) &perf_cnt))
	{
		m_bTimerTypePerformance = true;
		m_TimeFactor=1.0/perf_cnt;
	} 
  else 
	{
		m_bTimerTypePerformance = false;
		m_TimeFactor=0.001;
	}
	
	GetCurrentTime();
	m_LastTime = m_CurrentTime;
	m_TimeElapsed = 0;
	m_Seconds = 0;
}

QTimerManager::~QTimerManager()
{
for (unsigned int i=0; i< m_NumElements; i++)
{
	delete m_pTimers[i];
}
delete [] m_pTimers;
}

int QTimerManager::AddTimer(float Time, bool Respawn)
{
// MEMORY LEAK


	int Index = GetNextIndex();

	m_pTimers[Index] = new QTimer(m_bTimerTypePerformance,Time,Respawn, this);

	
	m_NumElements++;
	return Index;
}

void QTimerManager::GetCurrentTime()
{
	if (m_bTimerTypePerformance)
	{	
		QueryPerformanceCounter((LARGE_INTEGER *) &m_CurrentTime);
	} 
  else 
	{	m_CurrentTime=timeGetTime();
	}
}

void QTimerManager::Step()
{
// Esta funcion se ejecuta a la mayor velocidad de procesador posible
	
	GetCurrentTime();

	// Obtiene el tiempo transcurrido restando el actual del ultimo

	m_TimeElapsed = (float)((m_CurrentTime - m_LastTime) * m_TimeFactor);
	m_LastTime	  = m_CurrentTime;

	// Actualiza timer global (padre)

	m_Seconds+=m_TimeElapsed;

	// Actualiza los timers individuales

	for (unsigned int i=0; i< m_NumElements;i++)
		m_pTimers[i]->m_TimeElapsed+=m_TimeElapsed;

	
}
