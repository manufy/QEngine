// QTriangleList.h: interface for the QTriangleList class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_QTRIANGLELIST_H__2780699C_53D0_41A5_BBBF_C62336076C1C__INCLUDED_)
#define AFX_QTRIANGLELIST_H__2780699C_53D0_41A5_BBBF_C62336076C1C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "QPrimitive.h"

//class CVector3;
class QTriangle;

class QTriangleList  : public QPrimitive
{
public:
	void AddVertexList(int NumVertex, CVector3 *pVertexList);
	QTriangleList(QEngine *pEngine);
	virtual void Render();
	QTriangleList(QEngine *pEngine,unsigned int NumVertex, float *pVertexList, unsigned int NumTriangles,unsigned int *pTriangleList,unsigned int NumUV,float *pUVList);
	virtual ~QTriangleList();
	void Dump(QLog *pLog);
	unsigned int m_NumVertex;
	unsigned int m_NumTriangles;
	unsigned int m_TriangleListID;
	unsigned int m_VertexListID;

	CVector3 *m_pVertexList;
	QTriangle *m_pTriangleList;
	QVertexManager *m_pVertexManager;
	QTriangleManager *m_pTriangleManager;



	// NUEVO --- PASAR DE CODIGO ANTERIOR ......

	float *m_pVertex;
	unsigned int *m_pFaces;
	



};

#endif // !defined(AFX_QTRIANGLELIST_H__2780699C_53D0_41A5_BBBF_C62336076C1C__INCLUDED_)
