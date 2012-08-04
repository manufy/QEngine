// QModelMD2.cpp: implementation of the QModelMD2 class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "QModelMD2.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

QModelMD2::QModelMD2(QEngine *pEngine) : QModelKeyframed (pEngine)
{

}

QModelMD2::~QModelMD2()
{
}



int QModelMD2::Load(char *strFileName)
{
	FILE* file;
	MD2_HEADER MD2Header;

	sprintf(m_pEngine->m_pLog->m_Text, "	QModelMD2: Loading MD2 (%s)\n",strFileName);
	m_pEngine->m_pLog->AddLine(m_pEngine->m_pLog->m_Text);

	if((file= fopen(strFileName, "rb"))==NULL)
		{
		sprintf(m_pEngine->m_pLog->m_Text, "	QModelMD2: ERROR, NO FILENAME (%s)\n",strFileName);
		m_pEngine->m_pLog->AddLine(m_pEngine->m_pLog->m_Text);
		return false;
		}

	fread(&MD2Header, sizeof(MD2_HEADER), 1, file);

	if(MD2Header.magic!= 844121161)
	{
		sprintf(m_pEngine->m_pLog->m_Text, "	QModelMD2: ERROR, NO VALID MD2 MAGIC (%s)\n",strFileName);
		m_pEngine->m_pLog->AddLine(m_pEngine->m_pLog->m_Text);
		return false;
	}

	if(MD2Header.version!=8)
	{
	sprintf(m_pEngine->m_pLog->m_Text, "	QModelMD2: ERROR, NO VALID MD2 VERSION (%s)\n",strFileName);
	m_pEngine->m_pLog->AddLine(m_pEngine->m_pLog->m_Text);
	return false;
	}

	// Calcula Frames

	m_pMD2Frames= new char[MD2Header.frameSize*MD2Header.numFrames];
	if(m_pMD2Frames==NULL)
		return false;
	fseek(file, MD2Header.offsetFrames, SEEK_SET);
	fread(m_pMD2Frames, MD2Header.frameSize*MD2Header.numFrames, 1, file);

	// Calcula sitio para comandos GL

	m_pGLCommands= new long [MD2Header.numGlCommands*sizeof(long)];

	if(m_pGLCommands==NULL)
		return false;

	// Carga comandos GL

	fseek(file, MD2Header.offsetGlCommands, SEEK_SET);
	fread(m_pGLCommands, MD2Header.numGlCommands*sizeof(long), 1, file);

	// Algunas variables

	m_NumFrames		= MD2Header.numFrames;
	m_NumGLCommands	= MD2Header.numGlCommands;
	m_NumTriangles	= MD2Header.numTriangles;
	m_FrameSize		= MD2Header.frameSize;
	m_NumGLCommands = MD2Header.numGlCommands;
	

	Import();
//	Dump();
	delete  [] m_pMD2Frames;
	delete  [] m_pGLCommands;
	
	return true;
}

void QModelMD2::Import()
{
	
	MD2_FRAME_PTR	CurrentFrame;
	long*	pCommand;
	int	NumVertex;

	int	Type;
	int	VertexIndex;
	unsigned int *pTriangleList;

	float *pVertexList;
	
	sprintf(m_pEngine->m_pLog->m_Text, "	QModelMD2: Import %d Frames %d Vertex %d Faces\n",m_NumFrames,m_NumGLCommands,m_NumTriangles);
	m_pEngine->m_pLog->AddLine(m_pEngine->m_pLog->m_Text);




	m_pFrames = new QFrame*[m_NumFrames];


	// for (int f=0;f<100;f++)
	{
		QFrame *pNewFrame = new QFrame(m_pEngine,1);	// Crea frame con espacio para 1 QMalla
		QMesh  *pNewMesh  = new QMesh(m_NumGLCommands);	// Crea QMalla con espacio para m_NumGLCommands primitivas
	
			CurrentFrame= (MD2_FRAME*) ((char*)m_pMD2Frames+m_FrameSize*0);
			pCommand      = m_pGLCommands;
			while((*pCommand)!=0)
			{
				if(*pCommand>0)		//  Triangle Strip
				{
					NumVertex= *pCommand; 
					pCommand++; 
					Type= 0;
					pTriangleList =  new unsigned int[NumVertex*3];
					sprintf(m_pEngine->m_pLog->m_Text, "	QModelMD2: Import TriangleListStrip %d Vertex\n",NumVertex);
					m_pEngine->m_pLog->AddLine(m_pEngine->m_pLog->m_Text);
				}
				else			// Triangle Fan
				{
					NumVertex= - *pCommand; 
					pCommand++; 
					Type= 1;
					pTriangleList =  new unsigned int[NumVertex*3];
					sprintf(m_pEngine->m_pLog->m_Text, "	QModelMD2: Import TriangleListFan %d Vertex\n",NumVertex);
					m_pEngine->m_pLog->AddLine(m_pEngine->m_pLog->m_Text);
				}
				if(NumVertex<0)
				NumVertex= -NumVertex;

				// Importa Primitiva

				int it=0;
				int iv=0;
				pVertexList   = new float[NumVertex*3];
				float *pUV    = new float[NumVertex*2];
  				for (int k=0;k<NumVertex;k++)
				{   
					pUV[it]= *((float*)pCommand); 
					pCommand++;
					pUV[it+1]= *((float*)pCommand); 
				    pCommand++;
					VertexIndex= *pCommand; 
					pVertexList[iv] = ( (CurrentFrame->vertices[VertexIndex].vertex[0]* 
										CurrentFrame->scale[0])+ 
										CurrentFrame->translate[0]);
					pVertexList[iv+1] = -((CurrentFrame-> vertices[VertexIndex].vertex[1]* 
										CurrentFrame->scale[1])+ 
										CurrentFrame->translate[1]);
					pVertexList[iv+2] = ((CurrentFrame->vertices[VertexIndex].vertex[2]* 
										CurrentFrame->scale[2])+ 
										CurrentFrame->translate[2]);
					pTriangleList[it] = k;
					sprintf(m_pEngine->m_pLog->m_Text, "	QModelMD2:        Vertex %f %f %f\n",pVertexList[iv],pVertexList[iv+1],pVertexList[iv+2]);
					m_pEngine->m_pLog->AddLine(m_pEngine->m_pLog->m_Text);
					//sprintf(m_pEngine->m_pLog->m_Text, "	QModelMD2: Import Face %f\n",k);
					//m_pEngine->m_pLog->AddLine(m_pEngine->m_pLog->m_Text);
					it+=2;
					iv+=3;
					pCommand++;
			
				}

			// Una vez construida la lista de vertices, se mete en el trianglelist


				if (Type == 0) 
				{	QTriangleListStrip *pNewTriangleListStrip = new QTriangleListStrip(m_pEngine,NumVertex*3,pVertexList, pUV); // Crea lista de triangulos
						pNewMesh->AddPrimitive(pNewTriangleListStrip); }
				else
				{	QTriangleListFan *pNewTriangleListFan = new QTriangleListFan(m_pEngine,NumVertex*3,pVertexList,pUV); // Crea lista de triangulos
					pNewMesh->AddPrimitive(pNewTriangleListFan); }// Crea lista de triangulos

	
	
			} // end while

			// Añadir QMalla a QFrame
			
			pNewFrame->AddMesh(pNewMesh); // SE METE ANTES DE CARGAR TEXTURAS, OJO
			pNewMesh->LoadTexture("a.tga");
			AddFrame(pNewFrame);

		//	delete [] pNewFrame;
	}
	
	
	
	
}



void QModelMD2::Render()
{
	m_pFrames[0]->Render();
}

void QModelMD2::Dump()
{

sprintf(m_pEngine->m_pLog->m_Text, "	QModelMD2: Dump\n");
m_pEngine->m_pLog->AddLine(m_pEngine->m_pLog->m_Text); 
m_pFrames[0]->Dump(m_pEngine->m_pLog);

}
