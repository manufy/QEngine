// QTriangleListStrip.cpp: implementation of the QTriangleListStrip class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "QTriangleListStrip.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

QTriangleListStrip::QTriangleListStrip(QEngine *pEngine,unsigned int NumVertex, float *pVertexList, float *pUVList)  //: QTriangleList(pEngine, NumVertex, pVertexList, NumTriangles, pTriangleList )
{
		m_pVertex = pVertexList; 
		m_NumVertex    = NumVertex;
		m_pUV = pUVList;
}

QTriangleListStrip::~QTriangleListStrip()
{

}

QTriangleListStrip::QTriangleListStrip(QEngine *pEngine) //: QTriangleList(pEngine)
{

}
void QTriangleListStrip::Render()

{	int it=0;
	glBegin(GL_TRIANGLE_STRIP);
	for (unsigned int i=0;i<m_NumVertex;i+=3)
	{
	
		glTexCoord2f(m_pUV[it],m_pUV[it+1]);
		glVertex3f(m_pVertex[i],m_pVertex[i+1],m_pVertex[i+2]);
		it+=2;

	}glEnd();

	//glEnableClientState(GL_VERTEX_ARRAY);
	//glVertexPointer (3, GL_FLOAT, 0, &m_pVertex[0]);
	//glDrawElements  (GL_TRIANGLE_STRIP,m_NumVertex*3, GL_UNSIGNED_INT, m_pVertex);
	//glDisableClientState(GL_VERTEX_ARRAY);
}
void QTriangleListStrip::Dump(QLog *pLog)
{
	sprintf(pLog->m_Text, "	QPrimitive:           QTriangleListStrip\n");
	pLog->AddLine(pLog->m_Text); 	
	for (unsigned int i=0;i<m_NumVertex;i+=3)
	{
		sprintf(pLog->m_Text,  "		Vertex: %f %f %d\n",m_pVertex[i],m_pVertex[i+1],m_pVertex[i+2]);
		pLog->AddLine(pLog->m_Text); 	
	}
}