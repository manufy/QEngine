#include "stdafx.h"
#include ".\qterrain.h"

QTerrain::QTerrain(void)
{m_pHeightMap = NULL;
	m_Height = 0;
	m_Width = 0;
//	m_glListID = 0;
}

QTerrain::~QTerrain(void)
{free(m_pHeightMap);
	delete [] m_pTriangleStripVertexList;
}
void QTerrain::LoadRaw(LPSTR Name, int Height, int Width)
{
	FILE *pFile = NULL;
	pFile = fopen( Name, "rb" ); // abrir read binary
	if ( pFile == NULL )	// Si no existe
	{
		MessageBox(NULL, "Can't find the height map!", "Error", MB_OK);
		return;
	}
	// Size == ancho*alto

	if (m_pHeightMap != NULL)	// Borra datos previos, si los habia
		free(m_pHeightMap);

	m_pHeightMap = (BYTE*)malloc(Height * Width);
	fread( m_pHeightMap, 1, (Height * Width), pFile );

	if (ferror( pFile ))
	{
		MessageBox(NULL, "Can't get data!", "Error", MB_OK);
	}
	fclose(pFile); // Cerrar

	m_Height = Height;
	m_Width  = Width;
	m_StepSize = 16;
	MakeVertex();

}

void QTerrain::RenderTriangleStrip()
{
	int X = 0, Y = 0;						
	int x, y, z;							
//	MakeVertex();
	if(!m_pHeightMap) return;		
	
	glColor3ub(255,255,255);
	glBegin(GL_TRIANGLES);
	for ( X = 0; X <= m_NumVertex; X++ )
	{	
		
		{	
			glVertex3f (m_pTriangleStripVertexList[X]->x,m_pTriangleStripVertexList[X]->y,m_pTriangleStripVertexList[X]->z);
			
	
		}		
	} 
	glEnd();
/*	for ( X = 0; X <= m_Width ; X += 16 )
	{	glBegin(GL_POINTS);
		for ( Y = 0; Y <= m_Height ; Y += 16 )
		{	x = X;							
			y = Height(X, Y );	
			z = Y;							

			
		//	UN TRIANGULO

		
			glVertex3i(x, Height(X, Y ), z);
		
		
			glVertex3i(x+m_StepSize,Height(X+m_StepSize, Y ),z);
			

		
			}	glEnd(); 			
	
	} /*



		

/*	for ( X = 0; X <= m_Width ; X += 16 )
	{	glBegin(GL_TRIANGLE_STRIP);
		for ( Y = 0; Y <= m_Height ; Y += 16 )
		{	x = X;							
			y = Height(X, Y );	
			z = Y;							

			
		//	UN TRIANGULO

			glColor4f(1,0,0,255);
			glVertex3i(x, Height(X, Y ), z);
		
			glColor4f(0,0,1,255);
			glVertex3i(x,Height(X, Y+StepSize ),z+StepSize);
			
			glColor4f(0,1,0,255);
		    glVertex3i(x+StepSize,Height(X+StepSize, Y ) ,z);	
		
			glColor4f(0.5f,0.5f,0.5f,255);
			glVertex3i(x+StepSize,Height(X+StepSize, Y+StepSize ),z+StepSize);
		
			}	glEnd(); 			
	} */


}

int QTerrain::Height(int X, int Y)
{
	// Make sure we don't go past our array size
	int x = X % m_Width;					// Error check our x value
	int y = Y % m_Height;					// Error check our y value

	if(!m_pHeightMap) return 0;				// Make sure our data is valid

	// Use the equation: index = (x + (y * arrayWidth) ) to find the current height
	return  m_pHeightMap[x + (y * m_Height)];	// Index into our height array and return the height

}

void QTerrain::MakeVertex()
{
	int Index = 0;		




	m_pTriangleStripVertexList = new CVector3*[m_Height * m_Width];

	for ( int x = 0; x <= m_Width ; x += m_StepSize )
		for ( int y = 0; y <= m_Height ; y += m_StepSize )
		{	
			CVector3 *v = new CVector3;
			v->x = (float)x;
			v->z = (float)y;
			v->y = (float)Height(x,y);

			m_pTriangleStripVertexList[Index] = v;
			Index++;

			CVector3 *v2 = new CVector3;
			v2->x = (float)x;
			v2->z = (float)y+m_StepSize;
			v2->y = (float)Height(x,y+m_StepSize);

			m_pTriangleStripVertexList[Index] = v2;
			Index++;

			CVector3 *v3= new CVector3;
			v3->x = (float)x+m_StepSize;
			v3->z = (float)y+m_StepSize;
			v3->y = (float)Height(x+m_StepSize,y+m_StepSize);

			m_pTriangleStripVertexList[Index] = v3;
			Index++;

			CVector3 *v4= new CVector3;
			v4->x = (float)x+m_StepSize;
			v4->z = (float)y+m_StepSize;
			v4->y = (float)Height(x+m_StepSize,y+m_StepSize);

	//		m_pTriangleStripVertexList[Index] = v4;
	//		Index++;



		}

	m_NumVertex = Index-1;
}

void QTerrain::MakeCallList()
{
	for ( int X = 0; X <= m_NumVertex; X++ )
	{	glBegin(GL_POINTS);
		{	
			glVertex3f (m_pTriangleStripVertexList[X]->x,m_pTriangleStripVertexList[X]->y,m_pTriangleStripVertexList[X]->z);
		} 
		glEnd();
	} 
}