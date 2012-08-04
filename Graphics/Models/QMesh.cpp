// QMesh.cpp: implementation of the QMesh class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "QMesh.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////




QMesh::QMesh(unsigned int MaxPrimitives) : QHoleManager(MaxPrimitives),QObject(NULL)
{

	m_pPrimitives = new QPrimitive*[MaxPrimitives];
	m_pMaterials  = NULL;

}

QMesh::~QMesh()
{
	for (unsigned i=0;i<m_NumElements;i++)
		delete m_pPrimitives[i];
//	delete [] m_pPrimitives;
}


int QMesh::AddPrimitive(QPrimitive *pPrimitive)
{
	unsigned int Index = GetNextIndex();
	m_pPrimitives[Index] = pPrimitive;
	m_NumElements++;
	return (Index);
}



void QMesh::Render()
{


	// Aplica textura(s)

		
//	glEnable(GL_TEXTURE_2D);
//	glBindTexture(GL_TEXTURE_2D, m_pEngine->m_pTextureManager->m_Textures[m_TextureID]);
	glColor3f(1,1,1);
	for (unsigned int i=0;i<m_NumElements;i++)
	{
		m_pPrimitives[i]->Render();
	}
}



void QMesh::Dump(QLog *pLog)
{sprintf(pLog->m_Text, "	QMesh:          Mesh\n");
		pLog->AddLine(pLog->m_Text); 
	for (unsigned int i=0;i<m_NumElements;i++)
	{
		
		m_pPrimitives[i]->Dump(pLog);
	}
}
int QMesh::LoadTexture(char * strFileName)
{
	// Carga textura, lo intenta con todos los tipos conocidos

//	QMaterial *pMaterial;
	//pMaterial = new QMaterial();

	int Index = m_pEngine->m_pTextureManager->Add(strFileName,"tga");	
	m_TextureID = Index;
	return true;

}