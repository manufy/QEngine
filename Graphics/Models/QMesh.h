/** \file QMesh.h 
    \author Manuel Fernández Yáñez
    \date Enero-Julio 2003
    \brief Mallas 3D
	
**/
#if !defined(AFX_QMESH_H__8E2807A9_79EA_4E75_B3A5_29D8996C6F53__INCLUDED_)
#define AFX_QMESH_H__8E2807A9_79EA_4E75_B3A5_29D8996C6F53__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "..\..\Shared\TDA\QHoleManager.h"

class QPrimitive;
#include "..\Objects\QObject.h"
#include "..\Objects\QMaterial.h"

class QMesh  : public QHoleManager,  public QObject
{

  public:
	  void Render();

	QMesh(unsigned int MaxPrimitives);
	int AddPrimitive(QPrimitive *pPrimitive);
	virtual ~QMesh();
	void Dump(QLog *pLog);

	QMaterial		*m_pMaterials;
	unsigned int	m_TextureID;
	QFrame			*m_pParentFrame;
	QPrimitive		**m_pPrimitives;
	int LoadTexture(char * strFileName);
};

#endif // !defined(AFX_QMESH_H__8E2807A9_79EA_4E75_B3A5_29D8996C6F53__INCLUDED_)
