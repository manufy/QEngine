/** \file QModelRAW.h 
    \author Manuel Fernández Yáñez
    \date Enero-Julio 2003
    \brief Modelo definicdo en formato RAW - Listas de triangulos
	
**/
#if !defined(AFX_QMODELRAW_H__3DC7DE89_35D4_42CF_8D0F_6F322E7C56ED__INCLUDED_)
#define AFX_QMODELRAW_H__3DC7DE89_35D4_42CF_8D0F_6F322E7C56ED__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "QModelKeyframed.h"

class QModelRAW  : public QModelKeyframed
{
public:
	void Import();
	int Load(char *strFileName);
	void Render();
	QModelRAW(QEngine *pEngine);
	virtual ~QModelRAW();

	 int NumVertex;
	 int NumTriangles;

	 unsigned int  *pTriangleList;
	 float	*pVertexList;

};

#endif // !defined(AFX_QMODELRAW_H__3DC7DE89_35D4_42CF_8D0F_6F322E7C56ED__INCLUDED_)
