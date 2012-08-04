// QVertexManager.cpp: implementation of the QVertexManager class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "QVertexManager.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

QVertexManager::QVertexManager(int MaxVertex) : QHoleManager (MaxVertex)
{
	m_pVertexLists	 = new CVector3*[MaxVertex];	
	m_pVertex		 = new float[MaxVertex];
	m_pVertexNormals = new CVector3*[MaxVertex];
}

QVertexManager::~QVertexManager()
{
	for (unsigned int i=0;i<m_NumElements;i++)
			delete m_pVertexLists[i];
	
	delete [] m_pVertexLists;
	delete [] m_pVertexNormals;
	delete [] m_pVertex;
}

int QVertexManager::AddList(unsigned int NumVertex,CVector3 *pVertexList)
{
	unsigned int Index = GetNextIndex();
	int c = 0;
	for (unsigned int i=Index; i < Index+NumVertex;i++)
	{
		m_pVertexLists[i] = new		CVector3(pVertexList[i-Index].x,
											pVertexList[i-Index].y,
											pVertexList[i-Index].z);
		m_pVertex[c] = pVertexList[i-Index].x;
		c++;
		m_pVertex[c] = pVertexList[i-Index].y;
		c++;
		m_pVertex[c] = pVertexList[i-Index].z;
		c++;
		m_NumElements++;
	}
	
	return (Index);
}

void QVertexManager::CalculateNormals(unsigned int Start, unsigned int Length)
{
	CVector3 Sum;
	int Shared = 0;
	

}
