// QModel.cpp: implementation of the QModel class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "QModel.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

QModel::QModel(QEngine *pEngine)
{
	m_pEngine   = pEngine;
}

QModel::~QModel()
{
	 
}


void QModel::Import()
{
	// Import VIRTUAL
}

int QModel::Load(char *strFileName)
{
	return false;
}

void QModel::Render()
{

	// Render VIRTUAL

}

