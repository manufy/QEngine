// QTriangleListFan.cpp: implementation of the QTriangleListFan class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "QTriangleListFan.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

QTriangleListFan::QTriangleListFan(QEngine *pEngine,unsigned int NumVertex, float *pVertexList, float *pUVList)  //: QTriangleList(pEngine, NumVertex, pVertexList, NumTriangles, pTriangleList )
{
		m_pVertex = pVertexList; 
		m_NumVertex    = NumVertex;
		m_pUV = pUVList;
}

QTriangleListFan::~QTriangleListFan()
{

}

QTriangleListFan::QTriangleListFan(QEngine *pEngine)//: QTriangleList(pEngine)
{

}


void QTriangleListFan::Render()
{
	int it=0;
glBegin(GL_TRIANGLE_FAN);
	for (unsigned int i=0;i<m_NumVertex;i+=3)
	{
	
		glTexCoord2f(m_pUV[it],m_pUV[it+1]);
		glVertex3f(m_pVertex[i],m_pVertex[i+1],m_pVertex[i+2]);
		it+=2;		

	}glEnd();
	//glEnableClientState(GL_VERTEX_ARRAY);
	//glVertexPointer (3, GL_FLOAT, 0, &m_pVertex[0]);
	//glDrawElements  (GL_TRIANGLE_FAN,m_NumVertex*3, GL_UNSIGNED_INT, m_pVertex);
	//glDisableClientState(GL_VERTEX_ARRAY);
}

void QTriangleListFan::Dump(QLog *pLog)
{
	sprintf(pLog->m_Text, "	QPrimitive:           QTriangleListFan\n");
	pLog->AddLine(pLog->m_Text); 	
	for (unsigned int i=0;i<m_NumVertex;i+=3)
	{
		sprintf(pLog->m_Text,  "		Vertex: %f %f %d\n",m_pVertex[i],m_pVertex[i+1],m_pVertex[i+2]);
		pLog->AddLine(pLog->m_Text); 	
	}
}