// QTriangleManager.cpp: implementation of the QTriangleManager class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "QTriangleManager.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

QTriangleManager::QTriangleManager(QVertexManager *pVertexManager, int MaxTriangleLists) //: QHoleManager(MaxTriangleLists)
{
	m_pVertexManager = pVertexManager;
	m_pTriangleLists = new QTriangle*[MaxTriangleLists];
	m_pTriangleNormals = new CVector3[MaxTriangleLists];
	m_pFaces = new unsigned int[MaxTriangleLists];
	m_pVertex = new float[MaxTriangleLists*3];
}

QTriangleManager::~QTriangleManager()
{
		for (unsigned int i=0;i<m_NumElements;i++)
			delete m_pTriangleLists[i];
	delete [] m_pTriangleLists;
	delete [] m_pTriangleNormals;
	delete [] m_pFaces;
	delete [] m_pVertex;
}

void QTriangleManager::RenderList(unsigned int TriangleStart, unsigned int NumTriangles,unsigned int TriangleListID, unsigned int VertexListID)
{
	

	// ojo a los overflows

glBegin(GL_TRIANGLES);

	//m_pTriangleLists[i]->Render(;

	/* for (unsigned int i = TriangleStart; i< NumTriangles;i++)
	{
		

 glVertex3f(m_pVertexManager->m_pVertexLists[m_pTriangleLists[i]->m_VertexA]->x,
			m_pVertexManager->m_pVertexLists[m_pTriangleLists[i]->m_VertexA]->y,
			m_pVertexManager->m_pVertexLists[m_pTriangleLists[i]->m_VertexA]->z);
	 
 glVertex3f(m_pVertexManager->m_pVertexLists[m_pTriangleLists[i]->m_VertexB]->x,
			m_pVertexManager->m_pVertexLists[m_pTriangleLists[i]->m_VertexB]->y,
			m_pVertexManager->m_pVertexLists[m_pTriangleLists[i]->m_VertexB]->z);
	 
 glVertex3f(m_pVertexManager->m_pVertexLists[m_pTriangleLists[i]->m_VertexC]->x,
			m_pVertexManager->m_pVertexLists[m_pTriangleLists[i]->m_VertexC]->y,
			m_pVertexManager->m_pVertexLists[m_pTriangleLists[i]->m_VertexC]->z);
	 


	} */



glEnd();


}

int QTriangleManager::AddList(unsigned int NumTriangles, QTriangle *pTriangleList)
{
	unsigned int Index =0;//= GetNextIndex();
	int c;
	c = 0;
	for (unsigned int i=Index;i<(Index+NumTriangles);i++)
	{
		m_pTriangleLists[i] = new QTriangle(pTriangleList[i]);
		m_NumElements++;
		m_pFaces[c] = pTriangleList[i].m_VertexA;
		c++;
		m_pFaces[c] = pTriangleList[i].m_VertexB;
		c++;
		m_pFaces[c] = pTriangleList[i].m_VertexC;
		c++;
	}
	
	
	return (Index);
}

void QTriangleManager::CalculateNormals(unsigned int Start, unsigned int Length)
{

	CVector3 *a, *b;
	CVector3 p, q, n;
	for(unsigned int i=Start;i<(Start+Length);i++)
	{
	  a =new CVector3(m_pVertexManager->m_pVertexLists[m_pTriangleLists[i]->m_VertexA]->x,
					  m_pVertexManager->m_pVertexLists[m_pTriangleLists[i]->m_VertexA]->y,
					  m_pVertexManager->m_pVertexLists[m_pTriangleLists[i]->m_VertexA]->z); // first vertex of triangle

      b = new CVector3(m_pVertexManager->m_pVertexLists[m_pTriangleLists[i]->m_VertexB]->x,
					  m_pVertexManager->m_pVertexLists[m_pTriangleLists[i]->m_VertexB]->y,
					  m_pVertexManager->m_pVertexLists[m_pTriangleLists[i]->m_VertexB]->z); // first vertex of triangle


//      p = b - a;                 // find vector from the first to the second
      b = new CVector3(m_pVertexManager->m_pVertexLists[m_pTriangleLists[i]->m_VertexC]->x,
					  m_pVertexManager->m_pVertexLists[m_pTriangleLists[i]->m_VertexC]->y,
					  m_pVertexManager->m_pVertexLists[m_pTriangleLists[i]->m_VertexC]->z); // first vertex of triangle

//      q = b - a;                 // find vector from the first to the third
   
   //   n.Cross(p, q); // calculate the normal 
     // n.Normalize(); // normalize it, give the normal a length of 1
      m_pTriangleNormals[i] = n;
	}

	CVector3 Sum;
	int Shared = 0;
	for ( i=Start;i<(Start+Length);i++)
	{
		



      for (unsigned int j = 0; j < ((Length-Start) / 3); j++)
      {
         if ( m_pTriangleLists[i]->m_VertexA == i || 
			  m_pTriangleLists[i]->m_VertexB == i || 
			  m_pTriangleLists[i]->m_VertexC == i)
			
         {
            Sum += m_pTriangleNormals[j];
            Shared++;
         }
      }      
    //  vnorms[i] = (Sum / (float) Shared);
    //  vnorms[i].Normalize();
   //   sum.Clear();
      Shared = 0; 

	}
}
