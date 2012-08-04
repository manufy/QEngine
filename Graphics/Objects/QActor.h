/** \file QActor.h 
    \author Manuel Fernández Yáñez
    \date Enero-Julio 2003
    \brief Actor
**/ 
#if !defined(AFX_QACTOR_H__45CC03F7_922D_4270_B1C1_01D343848430__INCLUDED_)
#define AFX_QACTOR_H__45CC03F7_922D_4270_B1C1_01D343848430__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class QEngine;
class QModel;

class QActor  
{
public:
	void Render();
	void Load(char *strFileName);
	QActor(QEngine *pEngine);
	virtual ~QActor();

	QEngine			*m_pEngine;
	QModel			*m_pModel;
};

#endif // !defined(AFX_QACTOR_H__45CC03F7_922D_4270_B1C1_01D343848430__INCLUDED_)
