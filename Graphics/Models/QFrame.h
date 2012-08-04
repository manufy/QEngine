// QFrame.h: interface for the QFrame class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_QFRAME_H__0C875C71_8C3E_4902_8F0D_4D52D72A431D__INCLUDED_)
#define AFX_QFRAME_H__0C875C71_8C3E_4902_8F0D_4D52D72A431D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class QPrimitive;
#include "..\Objects\QObject.h"

class QFrame  : public QHoleManager,public QObject
{
public:
	int AddMesh(QMesh *pMesh);
	void Render();
	void Dump(QLog *pLog);
	QFrame(QEngine *pEngine,unsigned int MaxMeshes);
	virtual ~QFrame();


	QMesh	**m_pMeshes;
};

#endif // !defined(AFX_QFRAME_H__0C875C71_8C3E_4902_8F0D_4D52D72A431D__INCLUDED_)
