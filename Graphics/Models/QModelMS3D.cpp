// QModelMS3D.cpp: implementation of the QModelMS3D class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "QModelMS3D.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

QModelMS3D::QModelMS3D(QEngine *pEngine): QModelKeyframed(1, pEngine) // 1 Frame
{
	m_pTriangles = NULL;
	m_pVertex = NULL;
	m_pGroups = NULL;
}

QModelMS3D::~QModelMS3D()
{
	if (m_pTriangles) 
		delete  m_pTriangles;
	if (m_pVertex) 
		delete  m_pVertex;  
	if (m_pGroups)
		delete  m_pGroups; 

}

int QModelMS3D::Load(char *strFileName)
{
	FILE* pFile;
	MS3D_HEADER MS3DHeader;


	if((pFile= fopen(strFileName, "rb"))==NULL)
	{
	//	S3Dlog.Output("Could not load %s correctly", filename);
		return false;
	}

	// Leer cabecera
	fread(&MS3DHeader.ID, sizeof(char), 10, pFile);
	fread(&MS3DHeader.Version, 1, sizeof(int), pFile);


	// Comprobacion de version

	if(strncmp(MS3DHeader.ID, "MS3D000000", 10)!=0)
	{
	//	S3Dlog.Output("%s if not a valid .ms3d", filename);
		return false;
	}

	if(MS3DHeader.Version!=3 && MS3DHeader.Version!=4)
	{
	//	S3Dlog.Output("%s if not a valid .ms3d", filename);
		return false;
	}


	// Leer Vertices

	fread(&m_NumVertex, sizeof(unsigned short), 1, pFile);
	m_pVertex = new MS3D_VERTEX [m_NumVertex];
	for(int i=0; i<m_NumVertex; i++)
	{
		fread(&m_pVertex[i].Flags,	  sizeof(BYTE),  1, pFile);
		fread( m_pVertex[i].Vertex,	  sizeof(float), 3, pFile);
		fread(&m_pVertex[i].BoneID,	  sizeof(char),  1, pFile);
		fread(&m_pVertex[i].RefCount, sizeof(BYTE),  1, pFile);
	}

	// Leer Triangulos

	fread(&m_NumTriangles, sizeof(unsigned short), 1, pFile);
	m_pTriangles= new MS3D_TRIANGLE [m_NumTriangles];
	for(i=0; i<m_NumTriangles; i++)
	{
		fread(&m_pTriangles[i].Flags,		sizeof(unsigned short), 1, pFile);
		fread( m_pTriangles[i].VertexIndices,	sizeof(unsigned short), 3, pFile);
		fread( m_pTriangles[i].VertexNormals[0],sizeof(float),		3, pFile);
		fread( m_pTriangles[i].VertexNormals[1],sizeof(float),	 	3, pFile);
		fread( m_pTriangles[i].VertexNormals[2],sizeof(float),		3, pFile);
		fread( m_pTriangles[i].u,		sizeof(float),		3, pFile);
		fread( m_pTriangles[i].v,		sizeof(float),		3, pFile);
		fread(&m_pTriangles[i].SmoothingGroup,	sizeof(unsigned char),	1, pFile);
		fread(&m_pTriangles[i].GroupIndex,	sizeof(unsigned char),	1, pFile);
	}

	// Leer Grupos

	fread(&m_NumGroups, sizeof(unsigned short), 1, pFile);
	m_pGroups= new MS3D_GROUP [m_NumGroups];
	for(i=0; i<m_NumGroups; i++)
	{
		fread(&m_pGroups[i].Flags,	 sizeof(unsigned char),	1,  pFile);
		fread( m_pGroups[i].Name,	 sizeof(char),		32, pFile);
		fread(&m_pGroups[i].NumTriangles,sizeof(unsigned short),1,  pFile);

		m_pGroups[i].pTriangleIndices=new unsigned short [m_pGroups[i].NumTriangles];

		fread( m_pGroups[i].pTriangleIndices, sizeof(unsigned short), m_pGroups[i].NumTriangles,pFile);
		fread(&m_pGroups[i].MaterialIndex,   sizeof(char), 1, pFile);
	}

//	S3Dlog.Output("Loaded %s correctly", filename);
	Import();
	return true;



}

void QModelMS3D::Import()
{	
	
	
	// Convierte vertices

	//CVector3 *pNewVertex;
float *pVertexList   = new float[m_NumVertex*3];
	//pNewVertex = new CVector3[m_NumVertex];
 int c = 0;
	for (int f=0;f<m_NumVertex;f++)
	{	pVertexList[c]   = m_pVertex[f].Vertex[0];
		pVertexList[c+1] = m_pVertex[f].Vertex[1];
		pVertexList[c+2] = m_pVertex[f].Vertex[2];
		c+=3;
	}

	// Convierte triangulos



QFrame *pNewFrame = new QFrame(m_pEngine,1);	// Crea frame con espacio para 1 QMalla

	

	
	for (int g=0;g<m_NumGroups;g++) // PONER GRUPOS
	{
		QMesh  *pNewMesh  = new QMesh(1);	// Crea QMalla con espacio para una QPrimitiva

		c=0;	
		unsigned int *pFaces   = new unsigned int[m_pGroups[g].NumTriangles*3];
	
		for (int t=0;t<m_pGroups[g].NumTriangles;t++)
		{


			

		int triangleIndex       =  m_pGroups[g].pTriangleIndices[t];
		const MS3D_TRIANGLE* tri= &m_pTriangles[triangleIndex];		
		for(int loop3=0; loop3<3; loop3++)
				{
					int index= tri->VertexIndices[loop3];

				//	glNormal3fv( tri->VertexNormals[loop3]);
				//	glTexCoord2f(tri->u[loop3], tri->v[loop3]);
				//	glVertex3fv(m_pVertex[index].Vertex);
					pFaces[c]=index;
					c++;
				}

		}


		QTriangleList *pNewTriangleList = new QTriangleList(m_pEngine,m_NumVertex,pVertexList, m_pGroups[g].NumTriangles,pFaces,0, NULL); // Crea lista de triangulos
		
		// Añadir primitiva a la QMalla

		pNewMesh->AddPrimitive(pNewTriangleList);

		// Añadir QMalla a QFrame

		pNewFrame->AddMesh(pNewMesh);

		



	}
	
	// Añadir el QFrame final

		AddFrame(pNewFrame);
}

void QModelMS3D::Render()
{
  /* int loop1;
	int loop2;
	int loop3;

	// Draw By Group
	for(loop1=0; loop1<1; loop1++ ) //m_NumGroups
		{
			// Draw As Regular Triangles, Since .MS3D's Aren't Optimized Like .MD2's
			glBegin(GL_TRIANGLES);
			for(loop2=0; loop2<m_pGroups[loop1].NumTriangles; loop2++)
			{
				int triangleIndex       =  m_pGroups[loop1].pTriangleIndices[loop2];
				const MS3D_TRIANGLE* tri= &m_pTriangles[triangleIndex];

				// Loop Through The Triangle's Vertices, And Output Them!
				for(loop3=0; loop3<3; loop3++)
				{
					int index= tri->VertexIndices[loop3];

			//		glNormal3fv( tri->VertexNormals[loop3]);
			//		glTexCoord2f(tri->u[loop3], tri->v[loop3]);
			//		glVertex3fv(m_pVertex[index].Vertex);
				}
			}
			glEnd();
		} */
m_pFrames[0]->Render();
}
