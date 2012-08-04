/** \file QModelKeyframed.h 
    \author Manuel Fernández Yáñez
    \date Enero-Julio 2003
    \brief Modelo 3D basado en Keyframes. Clase abstracta
	
**/
#if !defined(AFX_QMODELKEYFRAMED_H__8943924F_370F_4298_83F4_75BDD06508A5__INCLUDED_)
#define AFX_QMODELKEYFRAMED_H__8943924F_370F_4298_83F4_75BDD06508A5__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "QModel.h"


class QFrame;

class QModelKeyframed  : public QModel, public QHoleManager
{
public:
	QModelKeyframed(QEngine *pEngine);
	int AddFrame(QFrame *pFrame);
	void Render(unsigned int Frame);
	QModelKeyframed(unsigned int MaxFrames, QEngine *pEngine);
	virtual ~QModelKeyframed();

	// Qmesh es una lista que apunta a una lista de primitivas

	QFrame		**m_pFrames;
};

#endif // !defined(AFX_QMODELKEYFRAMED_H__8943924F_370F_4298_83F4_75BDD06508A5__INCLUDED_)
