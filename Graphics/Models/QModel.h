/** \file QModel.h 
    \author Manuel Fernández Yáñez
    \date Enero-Julio 2003
    \brief Modelo 3D. Clase abstracta
	
**/
#if !defined(AFX_QMODEL_H__CFBBDB10_3A8E_40BA_9FA7_22421F7F502B__INCLUDED_)
#define AFX_QMODEL_H__CFBBDB10_3A8E_40BA_9FA7_22421F7F502B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class QMesh;
class QEngine;
class QFrame;

class QModel  
{
public:
	virtual void Render();
	virtual int Load(char *strFileName);
	virtual void Import();
	QModel(QEngine *pEngine);
	virtual ~QModel();

	QEngine	*m_pEngine;


	

};

#endif // !defined(AFX_QMODEL_H__CFBBDB10_3A8E_40BA_9FA7_22421F7F502B__INCLUDED_)
