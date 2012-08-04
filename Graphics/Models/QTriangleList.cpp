// QTriangleList.cpp: implementation of the QTriangleList class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "QTriangleList.h"

//#include "QTriangle.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

QTriangleList::QTriangleList(QEngine *pEngine,unsigned int NumVertex, float *pVertexList, unsigned int NumTriangles,unsigned int *pTriangleList,unsigned int NumUV,float *pUVList)
{
	m_pUV = pUVList;
	m_pVertexManager = pEngine->m_pVertexManager;
	m_pTriangleManager = pEngine->m_pTriangleManager;
	m_NumTriangles = NumTriangles;
	m_NumVertex    = NumVertex;
//	m_pTriangleList = pTriangleList;
//	m_pVertexList = pVertexList;
//	m_VertexListID = m_pVertexManager->AddList(m_NumVertex, pVertexList);
//	m_TriangleListID = m_pTriangleManager->AddList(m_NumTriangles,pTriangleList);
//	m_pTriangleManager->CalculateNormals(m_TriangleListID,NumTriangles);
	m_pVertex = pVertexList; // new float[NumVertex*3];
	//for (unsigned int i=0; i < NumVertex*3;i++)
	//{
		//m_pVertex[i] = pVertexList[i];
	//}
	
	//m_pFaces  = new unsigned int[NumTriangles*3];
	//for (unsigned int i=0;i<NumTriangles*3;i++)
	//{
//		m_pFaces[i] = pTriangleList[i];
//		printf("%d",m_pFaces[i]);
//	}
	m_pFaces  = pTriangleList;
}

QTriangleList::~QTriangleList()
{
//	//delete [] m_pVertex;
//	delete [] m_pFaces;
}

void QTriangleList::Render()
{
	//m_pTriangleManager->RenderList(0,m_NumTriangles,m_TriangleListID,m_VertexListID);
glEnableClientState(GL_VERTEX_ARRAY);

glVertexPointer (3, GL_FLOAT, 0, &m_pVertex[0]);
//glDrawElements  (GL_TRIANGLES,9, GL_UNSIGNED_INT, t);
glDrawElements  (GL_TRIANGLES,m_NumTriangles*3, GL_UNSIGNED_INT, m_pFaces);
glDisableClientState(GL_VERTEX_ARRAY);


}

QTriangleList::QTriangleList(QEngine *pEngine)	
{
	m_pVertexManager = pEngine->m_pVertexManager;
	m_pTriangleManager = pEngine->m_pTriangleManager;
	m_NumVertex = 0;
	m_NumTriangles = 0;
	m_pTriangleList = NULL;
	m_pVertexList = NULL;
	m_VertexListID = 0;
	m_TriangleListID = 0;
}

void QTriangleList::AddVertexList(int NumVertex, CVector3 *pVertexList)
{
	m_NumTriangles = 0;
	m_NumVertex    = NumVertex;
	m_VertexListID = m_pVertexManager->AddList(m_NumVertex, pVertexList);
}


void QTriangleList::Dump(QLog *pLog)
{
}
