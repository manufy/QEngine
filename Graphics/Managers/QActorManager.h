/** \file QActorManager.h 
    \author Manuel Fernández Yáñez
    \date Enero-Julio 2003
    \brief Gestor de actores
**/ 
#if !defined(AFX_QACTORMANAGER_H__39FE8103_1BD9_4E2E_A300_EB8524AB7BAE__INCLUDED_)
#define AFX_QACTORMANAGER_H__39FE8103_1BD9_4E2E_A300_EB8524AB7BAE__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "..\..\Shared\TDA\QHoleManager.h"

#define MAX_ACTORS 1024

class QEngine;
class QActor;

class QActorManager  : public QHoleManager
{
public:
	QActorManager(int NumActors);
	virtual ~QActorManager();


	QEngine		*m_pEngine;
	QActor		**m_pActors;	// Puntero a objetos tipo CActor
};

#endif // !defined(AFX_QACTORMANAGER_H__39FE8103_1BD9_4E2E_A300_EB8524AB7BAE__INCLUDED_)
