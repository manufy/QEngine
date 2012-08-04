// QTriangle.cpp: implementation of the QTriangle class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "QTriangle.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////
QTriangle::QTriangle()
{
	
}

QTriangle::QTriangle(QTriangle *NewTriangle)
{
	m_VertexA = NewTriangle->m_VertexA;
	m_VertexB = NewTriangle->m_VertexB;
	m_VertexC = NewTriangle->m_VertexC;
}

QTriangle::~QTriangle()
{

}

void QTriangle::Render(QVertexManager *pVertexManager)
{
	/*  glVertex3f(pVertexManager->m_pVertexList[m_VertexA]->x, 
				 pVertexManager->m_pVertexList[m_VertexA]->y, 
				 pVertexManager->m_pVertexList[m_VertexA]->z); 

	  glVertex3f(pVertexManager->m_pVertexList[m_VertexB]->x, 
				 pVertexManager->m_pVertexList[m_VertexB]->y, 
				 pVertexManager->m_pVertexList[m_VertexB]->z); 


	  glVertex3f(pVertexManager->m_pVertexList[m_VertexC]->x, 
				 pVertexManager->m_pVertexList[m_VertexC]->y, 
				 pVertexManager->m_pVertexList[m_VertexC]->z); 


	  
*/

}
