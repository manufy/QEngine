// QTriangleManager.h: interface for the QTriangleManager class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_QTRIANGLEMANAGER_H__CFE93127_0F63_4A81_AEDB_4C57EA01DBE3__INCLUDED_)
#define AFX_QTRIANGLEMANAGER_H__CFE93127_0F63_4A81_AEDB_4C57EA01DBE3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "QList.h"

class QTriangleManager : public QList
{
public:
	void CalculateNormals(unsigned int Start, unsigned int Length);
	int AddList(unsigned int NumTriangles,QTriangle *pTriangleLists);
	void RenderList(unsigned int TriangleStart, unsigned int NumTriangles,unsigned int ListID, unsigned int VertexListID);
	QTriangleManager(QVertexManager *pVertexManager, int MaxTriangleLists);
	virtual ~QTriangleManager();

	QTriangle			**m_pTriangleLists;
	QVertexManager		 *m_pVertexManager;
	CVector3			 *m_pTriangleNormals;

// NUEVO - NUEVO - NUEVO - 

	unsigned int					 *m_pFaces;
	float							 *m_pVertex;

	
};

#endif // !defined(AFX_QTRIANGLEMANAGER_H__CFE93127_0F63_4A81_AEDB_4C57EA01DBE3__INCLUDED_)
