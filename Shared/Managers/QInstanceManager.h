/** \file QInstanceManager.h 
    \author Manuel Fernández Yáñez
    \date Enero-Julio 2003
    \brief Gestor de Instancias de modelos 3D
	
**/
#if !defined(AFX_QINSTANCEMANAGER_H__0346141A_1799_44D5_B5FA_9A36CB5C3642__INCLUDED_)
#define AFX_QINSTANCEMANAGER_H__0346141A_1799_44D5_B5FA_9A36CB5C3642__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "..\TDA\QHoleManager.h"

class QActorManager;
class QInstance;

class QInstanceManager  : public QHoleManager
{
public:
	void Render();
	void Remove(int Index);
	QInstanceManager(QActorManager *pActorManager,int NumInstances);
	virtual ~QInstanceManager();

	QActorManager	*m_pActorManager;
	QInstance		**m_pInstances;		 // Instancias de los actores
};


#endif // !defined(AFX_QINSTANCEMANAGER_H__0346141A_1799_44D5_B5FA_9A36CB5C3642__INCLUDED_)
