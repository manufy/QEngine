// Quake3BSP.h: interface for the CQuake3BSP class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_QUAKE3BSP_H__CE8E603F_1451_4BEF_BED3_884B910E8040__INCLUDED_)
#define AFX_QUAKE3BSP_H__CE8E603F_1451_4BEF_BED3_884B910E8040__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


#include "..\..\Shared\TDA\BitSet.h"

#include "..\Engine3D.h"

#define FACE_POLYGON	1


// Vectores BSP


typedef struct Q3_BSP_VECTOR3I_TYPE
{
	int x, y, z;	
} Q3_BSP_VECTOR3I;


typedef struct Q3BSP_VECTOR3_TYPE
{
	float x, y, z;
} Q3BSP_VECTOR3;

typedef struct Q3BSP_VECTOR2_TYPE
{
	float x,y;	
} Q3BSP_VECTOR2;



// Cabecera BSP

typedef struct Q3BSP_HEADER_TYPE
{
    char	strID[4];				// ='IBSP'
    int		Version;				// = 0x2e en Quake 3
} Q3BSP_HEADER; 


// BSP Lump

typedef struct Q3BSP_LUMP_TYPE
{
	int Offset;					// Offset de comienzo del lump
	int Length;					// Longitud en bytes
} Q3BSP_LUMP;


// Vertice BSP

typedef struct Q3BSP_VERTEX_TYPE
{
	Q3BSP_VECTOR3 vPosition;			// (Posicion x, y, z)
    Q3BSP_VECTOR2 vTextureCoord;		// Coordenada de textura (u, v)
	Q3BSP_VECTOR2 vLightmapCoord;		// Coordenada lightmap (u, v)
    Q3BSP_VECTOR3 vNormal;				// Vector Normal (x, y, z)
	BYTE color[4];				// Color RGBA 
} Q3BSP_VERTEX;


// Cara BSP

typedef struct Q3BSP_FACE_TYPE
{
    int				TextureID;				// Index en el array de texturas
    int				Effect;					// Indice para elefecto, ó -1 (n/a)
    int				Type;					// 1=poligono, 2=patch, 3=mesh, 4=billboard 
    int				StartVertIndex;			// Indice del Vertice inicio
    int				NumVertex;				// Nº de vertices
    int				MeshVertIndex;			// index en el primer meshvertex 
    int				NumMeshVerts;			// Numero de mesh vertices 
    int				LightmapID;				// Indice de la textura del lightmap 
    int				lMapCorner[2];			// The face's lightmap corner in the image 
    int				lMapSize[2];			// Tamaño de la seccion lightmap
    Q3BSP_VECTOR3	lMapPos;				// The 3D origin of lightmap. 
    Q3BSP_VECTOR3	lMapVecs[2];			// The 3D space for s and t unit vectors. 
    Q3BSP_VECTOR3	vNormal;				// The face normal. 
    int				Size[2];				// The bezier patch dimensions. 
} Q3BSP_FACE ;


// Textura BSP

typedef struct Q3BSP_TEXTURE_TYPE
{
   char strName[64];			// Nombre de texture, sin extension
   int  Flags;					// ?
   int  Contents;				// ?
} Q3BSP_TEXTURE;

typedef struct Q3BSP_LIGHTMAP
{
    BYTE ImageBits[128][128][3];   // Datos RGB en una imagen 128x128
} Q3BSP_LIGHTMAP;


	// Datos BSP



// Nodo BSP

typedef struct Q3BSP_NODE_TYPE
{
    int Plane;					// The index into the planes array 
    int Front;					// The child index for the front node 
    int Back;					// The child index for the back node 
    Q3_BSP_VECTOR3I min;				// The bounding box min position. 
    Q3_BSP_VECTOR3I max;				// The bounding box max position. 
} Q3BSP_NODE; 

// Hoja BSP (Nodo terminal BSP)

typedef struct Q3BSP_LEAF_TYPE
{
    int Cluster;				// The visibility cluster 
    int Area;					// The area portal 
    Q3_BSP_VECTOR3I min;				// The bounding box min position 
    Q3_BSP_VECTOR3I max;				// The bounding box max position 
    int LeafFace;				// The first index into the face array 
    int NumFaces;			// The number of faces for this leaf 
    int LeafBrush;				// The first index for into the brushes 
    int NumBrushes;		// The number of brushes for this leaf 
} Q3BSP_LEAF; 

// Plano BSP

typedef struct Q3BSP_PLANE_TYPE
{
    CVector3 vNormal;			// Plane normal. 
    float d;					// The plane distance from origin 
} Q3BSP_PLANE;

// Datos cluster para pvs'
typedef struct Q3BSP_VISDATA_TYPE
{
	int NumClusters;			// The number of clusters
	int BytesPerCluster;		// The amount of bytes (8 bits) in the cluster's bitset
	BYTE *pBitsets;				// The array of bytes that holds the cluster bitsets				
} Q3BSP_VISDATA;





// This is our lumps enumeration
enum eLumps
{
    kEntities = 0,				// Stores player/object positions, etc...
    kTextures,					// Stores texture information
    kPlanes,				    // Stores the splitting planes
    kNodes,						// Stores the BSP nodes
    kLeafs,						// Stores the leafs of the nodes
    kLeafFaces,					// Stores the leaf's indices into the faces
    kLeafBrushes,				// Stores the leaf's indices into the brushes
    kModels,					// Stores the info of world models
    kBrushes,					// Stores the brushes info (for collision)
    kBrushSides,				// Stores the brush surfaces info
    kVertices,					// Stores the level vertices
    kMeshVerts,					// Stores the model vertices offsets
    kShaders,					// Stores the shader files (blending, anims..)
    kFaces,						// Stores the faces for the level
    kLightmaps,					// Stores the lightmaps for the level
    kLightVolumes,				// Stores extra world lighting information
    kVisData,					// Stores PVS and cluster info (visibility)
    kMaxLumps					// A constant to store the number of lumps
};



class CQuake3BSP  
{
public:
	void RenderFace(int FaceIndex);
	inline int IsClusterVisible(int current, int test);
	int FindLeaf(const CVector3 &vPos);
	void CreateLightmapTexture(BYTE *pImageBits, int width, int height);
	void ChangeGamma(BYTE *pImage, int size, float factor);
	void FindTextureExtension(char *strFileName, char *strFileType);
	void Render(CVector3 &vPos);
	int Load(char *strFileName);
	CQuake3BSP(CEngine3D *pEngine3D);
	virtual ~CQuake3BSP();

	int	m_NumVertex;
	int m_NumFaces;
	int m_NumTextures;
	int m_NumLightmaps;
	int	m_NumNodes;
	int m_NumLeafs;
	int m_NumLeafFaces;
	int	m_NumPlanes;

	int	m_Gamma;

	Q3BSP_LIGHTMAP		*m_pLightMaps;
	Q3BSP_VERTEX		*m_pVertex;
	Q3BSP_FACE			*m_pFaces;
	Q3BSP_TEXTURE		*m_pTextures;
	Q3BSP_NODE			*m_pNodes;
	Q3BSP_LEAF			*m_pLeafs;
	Q3BSP_PLANE			*m_pPlanes;
	Q3BSP_VISDATA		m_Clusters;	
	int					*m_pLeafFaces;
	CBitSet				m_FacesDrawn;
	CEngine3D			*m_pEngine3D;
};

#endif // !defined(AFX_QUAKE3BSP_H__CE8E603F_1451_4BEF_BED3_884B910E8040__INCLUDED_)
