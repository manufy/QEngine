// QModelRAW.cpp: implementation of the QModelRAW class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "QModelRAW.h"
#include "..\Objects\QTriangle.h"
#include "QFrame.h"
#include "QPrimitive.h"
#include "QTriangleList.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

QModelRAW::QModelRAW(QEngine *pEngine) : QModelKeyframed(1, pEngine) // 1 Frame
{
	
}

QModelRAW::~QModelRAW()
{
	 
  delete [] pTriangleList;
  delete [] pVertexList;  

}

void QModelRAW::Render()
{
	m_pFrames[0]->Render();
}


int QModelRAW::Load(char *strFileName)
{
	 FILE *pFile = fopen(strFileName, "r");
   
	

   fscanf(pFile, "%d\n", &NumVertex);
   
  pVertexList   = new float[NumVertex*3];
  int c=0;
   for (int i = 0; i < NumVertex; i++)
   {  fscanf(pFile, "%f %f %f\n", &pVertexList[c], &pVertexList[c+1], &pVertexList[c+2]);
      c+=3; }

   fscanf(pFile, "%d\n", &NumTriangles);
   

   // MODIFICADO HOY

   // pTriangleList = new QTriangle[NumTriangles];

    pTriangleList = new  unsigned int[NumTriangles*3];
   
   c = 0;
   for (i = 0; i < NumTriangles; i++)
   { fscanf(pFile, "%d %d %d\n", &pTriangleList[c], &pTriangleList[c+1], &pTriangleList[c+2]);
    c+=3;
   }
   
   fclose(pFile);

  // GenerateNormals(); 
   
  Import();

  
   	  
	//
	return true;

	
}

void QModelRAW::Import()
{

	QFrame *pNewFrame = new QFrame(m_pEngine,1);	// Crea frame con espacio para 1 QMalla
	QMesh  *pNewMesh  = new QMesh(1);	// Crea QMalla con espacio para una QPrimitiva
	
	// Crea primitiva : QTriangleList basado en los datos leidos

	QTriangleList *pNewTriangleList = new QTriangleList(m_pEngine,NumVertex,pVertexList, NumTriangles,pTriangleList,0,NULL); // Crea lista de triangulos
	
	// Añadir primitiva a la QMalla

	pNewMesh->AddPrimitive(pNewTriangleList);

	// Añadir QMalla a QFrame

	pNewFrame->AddMesh(pNewMesh);

	// Añadir el QFrame final

	AddFrame(pNewFrame);

	// IMPORTANTE
	// SE CREAN AQUILAS MESHES
	
	//QMesh *pMesh = new QMesh(MAX_PRIMITIVES_PER_MESH,m_pEngine,NumVertex,pVertexList, NumTriangles,pTriangleList);

	//m_pMeshes[m_NumMeshes] = pMesh;
	//m_NumMeshes++;
//	delete pMesh; NO, porque se destruye en pmeshes

}
