// QVertexManager.h: interface for the QVertexManager class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_QVERTEXMANAGER_H__22F3C61A_7B9A_4CFA_AB52_113CC9AE089E__INCLUDED_)
#define AFX_QVERTEXMANAGER_H__22F3C61A_7B9A_4CFA_AB52_113CC9AE089E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "..\..\Shared\TDA\QHoleManager.h"

class QVertexManager  : public QHoleManager
{
public:
	void CalculateNormals(unsigned int Start, unsigned int Length);
	int AddList(unsigned int NumVertex,CVector3 *pVertexList);
	QVertexManager(int MaxVertex);
	virtual ~QVertexManager();

	CVector3		**m_pVertexLists;
	CVector3		**m_pVertexNormals;

	float           *m_pVertex;

};

#endif // !defined(AFX_QVERTEXMANAGER_H__22F3C61A_7B9A_4CFA_AB52_113CC9AE089E__INCLUDED_)
