// Quake3BSP.cpp: implementation of the CQuake3BSP class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Quake3BSP.h"

//#include "Render.h"



//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CQuake3BSP::CQuake3BSP(CEngine3D *pEngine3D)
{
	m_pEngine3D = pEngine3D;
	m_Gamma = 10;
}

CQuake3BSP::~CQuake3BSP()
{

}

int CQuake3BSP::Load(char *strFileName)
{	




	FILE* pFile;
	Q3BSP_HEADER Header;
	Q3BSP_LUMP Lumps[kMaxLumps];

	if((pFile= fopen(strFileName, "rb"))==NULL)
		{
		//S3Dlog.Output("Could not load %s correctly", filename);
		return false;
		}

	fread(&Header, sizeof(Q3BSP_HEADER), 1, pFile);
	fread(&Lumps,  sizeof(Q3BSP_LUMP),    kMaxLumps,pFile);

	// Memoria para los vertices

	m_NumVertex	 = Lumps[kVertices].Length / sizeof(Q3BSP_VERTEX);
	m_pVertex     = new Q3BSP_VERTEX[m_NumVertex];

	// Memoria para las caras

	m_NumFaces =  Lumps[kFaces].Length / sizeof(Q3BSP_FACE);
	m_pFaces     = new Q3BSP_FACE [m_NumFaces];

	// Memoria para las texturas

	m_NumTextures = Lumps[kTextures].Length / sizeof(Q3BSP_TEXTURE);
	Q3BSP_TEXTURE *m_pTextures = new Q3BSP_TEXTURE [m_NumTextures];

	// Memoria para los LightMaps
	
	m_NumLightmaps = Lumps[kLightmaps].Length / sizeof(Q3BSP_LIGHTMAP);
	Q3BSP_LIGHTMAP *m_pLightmaps = new	Q3BSP_LIGHTMAP [m_NumLightmaps ];

	// Posicionar para la lectura de vertices

	fseek(pFile, Lumps[kVertices].Offset, SEEK_SET);


	// Eje Z apuntando arriba se pasa al eje Y

	for(int i = 0; i < m_NumVertex; i++)
	{
		fread(&m_pVertex[i], 1, sizeof(Q3BSP_VERTEX), pFile);
		
		// Swap the y and z values, and negate the new z so Y is up.
		float temp = m_pVertex[i].vPosition.y;
		m_pVertex[i].vPosition.y = m_pVertex[i].vPosition.z;
		m_pVertex[i].vPosition.z = -temp;

		// Negate the V texture coordinate because it is upside down otherwise...
		m_pVertex[i].vTextureCoord.y *= -1;
	}	

	// Posiciona puntero de lectura para las caras y lee

	fseek(pFile, Lumps[kFaces].Offset, SEEK_SET);	
	fread(m_pFaces, m_NumFaces, sizeof(Q3BSP_FACE), pFile);

	// Reprocesa las texturas en las caras

	int NextTexture = m_pEngine3D->m_pTextureManager->GetNextIndex();
	for (i=0;i<m_NumFaces;i++)
		m_pFaces[i].TextureID+= NextTexture;


	// Posiciona puntero y lee texturas
	fseek(pFile, Lumps[kTextures].Offset, SEEK_SET);
	fread(m_pTextures, m_NumTextures, sizeof(Q3BSP_TEXTURE), pFile);

	
	char Ext[3] = {0};

	// Para todas las texturas
	for(i = 0; i < m_NumTextures; i++)
	{
		Ext[0] = 0;
		// Busca la extension
		FindTextureExtension(m_pTextures[i].strName,Ext);
		
		// Crea path

		char Path[MAX_PATH] = {0};
		strcat(Path, "Data\\");
		strcat(Path, m_pTextures[i].strName);
		m_pEngine3D->m_pTextureManager->Add(Path, Ext);
		
	}
	

	// Reprocesa las texturas en las caras, para los lightmaps

	NextTexture = m_pEngine3D->m_pTextureManager->m_NumElements;
	for (i=0;i<m_NumFaces;i++)
		m_pFaces[i].LightmapID+= NextTexture;




	//  Posicionarse para Lightmaps
	fseek(pFile, Lumps[kLightmaps].Offset, SEEK_SET);

	// Para todos los Lightmaps
	for(i = 0; i < m_NumLightmaps ; i++)
	{
		// Leer datos RGB para cada lightmap

		fread(&m_pLightmaps[i], 1, sizeof(Q3BSP_LIGHTMAP), pFile);

		// Create a texture map for each lightmap that is read in.  The lightmaps
		// are always 128 by 128.

		CreateLightmapTexture((unsigned char *)m_pLightmaps[i].ImageBits, 128, 128);
	}

	// Acordarse de delete texturas y lightmaps

	// Ahora procesa los datos BSP, Nodos, Hojas, Planos, Clusters



	// Memoria para los nodos

	m_NumNodes   = Lumps[kNodes].Length / sizeof(	Q3BSP_NODE);
	m_pNodes     = new Q3BSP_NODE [m_NumNodes];

	// Memoria para las hojas
	m_NumLeafs = Lumps[kLeafs].Length / sizeof(Q3BSP_LEAF);
	m_pLeafs     = new Q3BSP_LEAF [m_NumLeafs];

	// Memoria para las caras de las hojas
	m_NumLeafFaces	= Lumps[kLeafFaces].Length / sizeof(int);
	m_pLeafFaces    = new int [m_NumLeafFaces];

	// Memoria para los planos
	m_NumPlanes = Lumps[kPlanes].Length / sizeof(Q3BSP_PLANE);
	m_pPlanes     = new Q3BSP_PLANE [m_NumPlanes];
	
	
	// Leer Nodos

	fseek(pFile, Lumps[kNodes].Offset, SEEK_SET);
	fread(m_pNodes, m_NumNodes, sizeof(Q3BSP_NODE), pFile);
	
	// Leer Hojas

	fseek(pFile, Lumps[kLeafs].Offset, SEEK_SET);
	fread(m_pLeafs, m_NumLeafs, sizeof(Q3BSP_LEAF), pFile);

	// Leer caras de las hojas

	fseek(pFile, Lumps[kLeafFaces].Offset, SEEK_SET);
	fread(m_pLeafFaces, m_NumLeafFaces, sizeof(int), pFile);

	// Leer planos

	fseek(pFile, Lumps[kPlanes].Offset, SEEK_SET);
	fread(m_pPlanes, m_NumPlanes, sizeof(Q3BSP_PLANE), pFile);



	// Conversion a OPENGL - Eje Y arriba

	// Para las hojas

	for(i = 0; i < m_NumLeafs; i++)
	{
		// Swap the min y and z values, then negate the new Z
		float temp = m_pLeafs[i].min.y;
		m_pLeafs[i].min.y = m_pLeafs[i].min.z;
		m_pLeafs[i].min.z = -temp;

		// Swap the max y and z values, then negate the new Z
		temp = m_pLeafs[i].max.y;
		m_pLeafs[i].max.y = m_pLeafs[i].max.z;
		m_pLeafs[i].max.z = -temp;
	}


	// Para los planos (normal eje y)

	for(i = 0; i < m_NumPlanes; i++)
	{
		float Temp = m_pPlanes[i].vNormal.y;
		m_pPlanes[i].vNormal.y = m_pPlanes[i].vNormal.z;
		m_pPlanes[i].vNormal.z = -Temp;
	}


	// Leer datos de visibilidad

	// Posicionarse para lectura
	fseek(pFile, Lumps[kVisData].Offset, SEEK_SET);

	// Check if there is any visibility information first
	if(Lumps[kVisData].Length) 
	{
		// Read in the number of vectors and each vector's size
		fread(&(m_Clusters.NumClusters),	 1, sizeof(int), pFile);
		fread(&(m_Clusters.BytesPerCluster), 1, sizeof(int), pFile);

		// Allocate the memory for the cluster bitsets
		int Size = m_Clusters.NumClusters * m_Clusters.BytesPerCluster;
		m_Clusters.pBitsets = new BYTE [Size];

		// Read in the all the visibility bitsets for each cluster
		fread(m_Clusters.pBitsets, 1, sizeof(BYTE) * Size, pFile);
	}
	// Otherwise, we don't have any visibility data (prevents a crash)
	else
		m_Clusters.pBitsets = NULL;

	m_FacesDrawn.Resize(m_NumFaces);
	return true;

}

void CQuake3BSP::Render(CVector3 &vPos) // Render por fuerza bruta
{
	

	glEnable(GL_DEPTH_TEST);	
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

	// Enable front face culling, since that's what Quake3 does
	glCullFace(GL_FRONT);
 	glEnable(GL_CULL_FACE);


	glVertexPointer(3, GL_FLOAT, sizeof(Q3BSP_VERTEX), &(m_pVertex[0].vPosition));

	//

	m_pEngine3D->m_pRender->ClientActiveTexture0();
	glTexCoordPointer(2, GL_FLOAT, sizeof(Q3BSP_VERTEX), &(m_pVertex[0].vTextureCoord));
	m_pEngine3D->m_pRender->ClientActiveTexture1();
	glTexCoordPointer(2, GL_FLOAT, sizeof(Q3BSP_VERTEX), &(m_pVertex[0].vLightmapCoord));
	

	m_pEngine3D->m_pRender->ClientActiveTexture0();
	glEnableClientState(GL_TEXTURE_COORD_ARRAY);
	glEnableClientState(GL_VERTEX_ARRAY);

	m_pEngine3D->m_pRender->ClientActiveTexture1();
	glEnableClientState(GL_TEXTURE_COORD_ARRAY);  
	glEnableClientState(GL_VERTEX_ARRAY);
		 
	m_FacesDrawn.Reset();

	// Averiguar en que nodo hoja esta la camara
	int LeafIndex = FindLeaf(vPos);

	// Obtener el cluster asociado a dicha hoja
	int Cluster = m_pLeafs[LeafIndex].Cluster;

	// Inicializar variables 
	int i = m_NumLeafs;
	int VisibleFaces = 0;


	// Iterar caras 
	while(i--)
	{
/*		// Before drawing this face, make sure it's a normal polygon
		if(m_pFaces[i].Type != FACE_POLYGON) continue;

		// If this face already hasn't been drawn
		if(!m_FacesDrawn.On(i)) 
		{
			// Set this face as drawn and render it
			m_FacesDrawn.Set(i);
			
			RenderFace(i); */




		// Get the current leaf that is to be tested for visibility from our camera's leaf
		Q3BSP_LEAF *pLeaf = &(m_pLeafs[i]);

		// If the current leaf can't be seen from our cluster, go to the next leaf
		if(!IsClusterVisible(Cluster, pLeaf->Cluster)) 
			continue;

		// If the current leaf is not in the camera's frustum, go to the next leaf
//		if(!g_Frustum.BoxInFrustum(pLeaf->min.x, pLeaf->min.y, pLeaf->min.z,
//		  	 				       pLeaf->max.x, pLeaf->max.y, pLeaf->max.z))
//			continue;
		
		// If we get here, the leaf we are testing must be visible in our camera's view.
		// Get the number of faces that this leaf is in charge of.
		int FaceCount = pLeaf->NumFaces;

		// Loop through and render all of the faces in this leaf
		while(FaceCount--)
		{
			// Grab the current face index from our leaf faces array
			int	FaceIndex = m_pLeafFaces[pLeaf->LeafFace + FaceCount];

			// Before drawing this face, make sure it's a normal polygon
			if(m_pFaces[FaceIndex].Type != FACE_POLYGON) continue;

			// Since many faces are duplicated in other leafs, we need to
			// make sure this face already hasn't been drawn.
			if(!m_FacesDrawn.On(FaceIndex)) 
			{
				// Increase the rendered face count to display for fun
				VisibleFaces++;

				// Set this face as drawn and render it
				m_FacesDrawn.Set(FaceIndex);
				RenderFace(FaceIndex);
			}
		}	


	
	}

	m_pEngine3D->m_pRender->ActiveTexture0();
	glDisable(GL_CULL_FACE);
	glDisableClientState(GL_TEXTURE_COORD_ARRAY);
	glDisableClientState(GL_VERTEX_ARRAY);
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);


}


void CQuake3BSP::FindTextureExtension(char *strFileName, char*strFileType)
{
	// Obtiene el tipo de textura: jpb, tga, bmp

	char strJPGPath[MAX_PATH] = {0};
	char strTGAPath[MAX_PATH]    = {0}; 
	FILE *fp = NULL;

	GetCurrentDirectory(MAX_PATH, strJPGPath);

	// Añade /
	// Testear JPG y TGA nada mas
	strcat(strJPGPath, "\\Data\\");
	strcat(strJPGPath, strFileName);
	strcpy(strTGAPath, strJPGPath);
	
	// Añadir extensiones
	strcat(strJPGPath, ".jpg");
	strcat(strTGAPath, ".tga");

	// JPG ?
	if((fp = fopen(strJPGPath, "rb")) != NULL)
	{
		// Concatena JPG
		strcat(strFileName, ".jpg");
		strcat(strFileType, TEXTURE_JPG);
		return;
	}

	//TGA ?
	if((fp = fopen(strTGAPath, "rb")) != NULL)
	{
		// Concatena TGA
		strcat(strFileName, ".tga");
		strcat(strFileType, TEXTURE_TGA);
		return;
	}
}

void CQuake3BSP::ChangeGamma(BYTE *pImage, int size, float factor)
{
	//  This function was taken from a couple engines that I saw,
	// which most likely originated from the Aftershock engine.
	// Kudos to them!  What it does is increase/decrease the intensity
	// of the lightmap so that it isn't so dark.  Quake uses hardware to
	// do this, but we will do it in code.

	// Go through every pixel in the lightmap
	for(int i = 0; i < size / 3; i++, pImage += 3) 
	{
		float scale = 1.0f, temp = 0.0f;
		float r = 0, g = 0, b = 0;

		// extract the current RGB values
		r = (float)pImage[0];
		g = (float)pImage[1];
		b = (float)pImage[2];

		// Multiply the factor by the RGB values, while keeping it to a 255 ratio
		r = r * factor / 255.0f;
		g = g * factor / 255.0f;
		b = b * factor / 255.0f;
		
		// Check if the the values went past the highest value
		if(r > 1.0f && (temp = (1.0f/r)) < scale) scale=temp;
		if(g > 1.0f && (temp = (1.0f/g)) < scale) scale=temp;
		if(b > 1.0f && (temp = (1.0f/b)) < scale) scale=temp;

		// Get the scale for this pixel and multiply it by our pixel values
		scale*=255.0f;		
		r*=scale;	g*=scale;	b*=scale;

		// Assign the new gamma'nized RGB values to our image
		pImage[0] = (BYTE)r;
		pImage[1] = (BYTE)g;
		pImage[2] = (BYTE)b;
	}
}

void CQuake3BSP::CreateLightmapTexture(BYTE *pImageBits, int width, int height)
{

	// Crea un texture map de un light map

//	 m_pEngine3D->m_pRender->ActiveTexture0();
	// Generar una nueva textura
	int Index = m_pEngine3D->m_pTextureManager->AllocateTexture();

	glGenTextures(1, &m_pEngine3D->m_pTextureManager->m_Textures[Index]);
	glPixelStorei (GL_UNPACK_ALIGNMENT, 1); // Efecto: elimina parpadeos
	glBindTexture(GL_TEXTURE_2D, m_pEngine3D->m_pTextureManager->m_Textures[Index]);




	// Change the lightmap gamma values by our desired gamma
	ChangeGamma(pImageBits, width*height*3, m_Gamma);

	// Build Mipmaps (builds different versions of the picture for distances - looks better)
	gluBuild2DMipmaps(GL_TEXTURE_2D, 3, width, height, GL_RGB, GL_UNSIGNED_BYTE, pImageBits);

	//Assign the mip map levels		
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);	
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_NEAREST);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
}

int CQuake3BSP::FindLeaf(const CVector3 &vPos)
{
	int i = 0;
	float Distance = 0.0f;

	// This function takes in our camera position, then goes and walks
	// through the BSP nodes, starting at the root node, finding the leaf node
	// that our camera resides in.  This is done by checking to see if
	// the camera is in front or back of each node's splitting plane.
	// If the camera is in front of the camera, then we want to check
	// the node in front of the node just tested.  If the camera is behind
	// the current node, we check that nodes back node.  Eventually, this
	// will find where the camera is according to the BSP tree.  Once a
	// node index (i) is found to be a negative number, that tells us that
	// that index is a leaf node, not another BSP node.  We can either calculate
	// the leaf node index from -(i + 1) or ~1.  This is because the starting
	// leaf index is 0, and you can't have a negative 0.  It's important
	// for us to know which leaf our camera is in so that we know which cluster
	// we are in.  That way we can test if other clusters are seen from our cluster.
	
	// Continue looping until we find a negative index
	while(i >= 0)
	{	Q3BSP_NODE_TYPE		&Node = m_pNodes[i];
		// Get the current node, then find the slitter plane from that
		// node's plane index.  Notice that we use a constant reference
		// to store the plane and node so we get some optimization.
	//	
		Q3BSP_PLANE_TYPE	&Plane = m_pPlanes[Node.Plane];

		// Use the Plane Equation (Ax + by + Cz + D = 0) to find if the
		// camera is in front of or behind the current splitter plane.
        Distance =	Plane.vNormal.x * vPos.x + 
					Plane.vNormal.y * vPos.y + 
					Plane.vNormal.z * vPos.z - Plane.d;

	
		// If the camera is in front of the plane
        if(Distance >= 0)	
		{
			// Assign the current node to the node in front of itself
            i = Node.Front;
        }
		// Else if the camera is behind the plane
        else		
		{
			// Assign the current node to the node behind itself
            i = Node.Back;
        }
    }

	// Return the leaf index (same thing as saying:  return -(i + 1)).
    return ~i;  // Binary operation
}

inline int CQuake3BSP::IsClusterVisible(int current, int test)
{
// This function is used to test the "current" cluster against
	// the "test" cluster.  If the "test" cluster is seen from the
	// "current" cluster, we can then draw it's associated faces, assuming
	// they aren't frustum culled of course.  Each cluster has their own
	// bitset containing a bit for each other cluster.  For instance, if there
	// is 10 clusters in the whole level (a tiny level), then each cluster
	// would have a bitset of 10 bits that store a 1 (visible) or a 0 (not visible) 
	// for each other cluster.  Bitsets are used because it's faster and saves
	// memory, instead of creating a huge array of booleans.  It seems that
	// people tend to call the bitsets "vectors", so keep that in mind too.

	// Make sure we have valid memory and that the current cluster is > 0.
	// If we don't have any memory or a negative cluster, return a visibility (1).
	if(!m_Clusters.pBitsets || current < 0) return 1;

	// Use binary math to get the 8 bit visibility set for the current cluster
	BYTE visSet = m_Clusters.pBitsets[(current*m_Clusters.BytesPerCluster) + (test / 8)];
	
	// Now that we have our vector (bitset), do some bit shifting to find if
	// the "test" cluster is visible from the "current" cluster, according to the bitset.
	int result = visSet & (1 << ((test) & 7));

	// Return the result ( either 1 (visible) or 0 (not visible) )
	return ( result );
}

void CQuake3BSP::RenderFace(int FaceIndex)
{
	// Dibuja la cara

	Q3BSP_FACE *pFace;

	pFace = &m_pFaces[FaceIndex];
		


	m_pEngine3D->m_pRender->ActiveTexture0();
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, m_pEngine3D->m_pTextureManager->m_Textures[pFace->TextureID]);
glColor3f(1,1,1);
	m_pEngine3D->m_pRender->ActiveTexture1();
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D,  m_pEngine3D->m_pTextureManager->m_Textures[pFace->LightmapID]);
	glColor3f(1,1,1);

	glDrawArrays(GL_TRIANGLE_FAN, pFace->StartVertIndex, pFace->NumVertex);


}
