// QModelMS3D.h: interface for the QModelMS3D class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_QMODELMS3D_H__F7610562_6BF7_42E0_BB4A_EEA957979B37__INCLUDED_)
#define AFX_QMODELMS3D_H__F7610562_6BF7_42E0_BB4A_EEA957979B37__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

// Estructura de cabecera

typedef struct MS3D_HEADER_TYPE
{
   	char				ID[10];	// = "MS3D000000"
	int					Version;	// = 3 ó 4

} MS3D_HEADER, *MS3D_HEADER_PTR;
// Estructura de vertice

typedef struct MS3D_VERTEX_TYPE
{
	unsigned char		Flags;
	unsigned char		RefCount;
	char				BoneID;
	float				Vertex[3];

} MS3D_VERTEX, *MS3D_VERTEX_PTR;

// Estructura de triangulo

typedef struct MS3D_TRIANGLE_TYPE
{
	unsigned short		Flags;
	unsigned short		VertexIndices[3];
	float				VertexNormals[3][3];
	float				u[3];
	float				v[3];
	unsigned char		SmoothingGroup;
	unsigned char		GroupIndex;
} MS3D_TRIANGLE, *MS3D_TRIANGLE_PTR;


// Estructura de grupo

typedef struct MS3D_GROUP_TYPE
{
   	unsigned char		Flags;
   	char				Name[32];
   	unsigned short		NumTriangles;
	unsigned short*		pTriangleIndices;
	char				MaterialIndex;
} MS3D_GROUP, *MS3D_GROUP_PTR;

class QModelMS3D  : public QModelKeyframed
{
public:
	void Render();
	void Import();
	int Load(char *strFileName);
	QModelMS3D(QEngine *pEngine);
	virtual ~QModelMS3D();

	unsigned short				m_NumTriangles;	
	unsigned short				m_NumVertex;
	unsigned short				m_NumGroups;
	MS3D_VERTEX		*m_pVertex;
	MS3D_TRIANGLE	*m_pTriangles;
	MS3D_GROUP		*m_pGroups;
};

#endif // !defined(AFX_QMODELMS3D_H__F7610562_6BF7_42E0_BB4A_EEA957979B37__INCLUDED_)
