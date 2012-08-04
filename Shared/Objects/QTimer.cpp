
#include "stdafx.h"
#include "QTimer.h"

QTimer::QTimer(bool bTimerTypePerformance, float MaxTime, bool Respawn, QTimerManager *pTimerManager)
{
// Inicializa valores.

	m_pTimerManager = pTimerManager;				
	m_Respawn = Respawn;						
	m_MaxTime = MaxTime;						
	m_bTimerTypePerformance = bTimerTypePerformance;		// Tipo de temporizador, alta o baja resolución.
	m_TimeElapsed = 0;	
}

QTimer::~QTimer()
{

}

bool QTimer::ElapsedInterval()
{
// Devuelve true si desde la ultima vez que se llamó, paso el intervalo de tiempo especificado
// Antes de usarla se debe haber usado TimerManager::Step()

	if(m_TimeElapsed > m_MaxTime)
	{
		m_TimeElapsed = 0;
		return true;
	}
	   else
	    return false;
}
