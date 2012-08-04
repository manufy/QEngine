// QTriangleListStrip.h: interface for the QTriangleListStrip class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_QTRIANGLELISTSTRIP_H__A20EAF62_C833_469D_A3DF_4793957B5623__INCLUDED_)
#define AFX_QTRIANGLELISTSTRIP_H__A20EAF62_C833_469D_A3DF_4793957B5623__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class QTriangleListStrip  : public QPrimitive
{
public:
	QTriangleListStrip(QEngine *pEngine);
	QTriangleListStrip(QEngine *pEngine,unsigned int NumVertex, float *pVertexList);
	QTriangleListStrip(QEngine *pEngine,unsigned int NumVertex, float *pVertexList, float *pUVList);
	virtual ~QTriangleListStrip();
	void Dump(QLog *pLog);


void Render(void);
};

#endif // !defined(AFX_QTRIANGLELISTSTRIP_H__A20EAF62_C833_469D_A3DF_4793957B5623__INCLUDED_)
