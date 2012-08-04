#pragma once

class QVertex;
class QTextCoord;

class QHeightMap : QPrimitive
{
public:
	QHeightMap(void);
	~QHeightMap(void);

// Mesh Data
	int		m_nVertexCount;						// Vertex Count
	QVertex*		m_pVertices;						// Vertex Data
	QTextCoord*	m_pTexCoords;						// Texture Coordinates
	unsigned int	m_nTextureId;						// Texture ID

	// Vertex Buffer Object Names
	unsigned int	m_nVBOVertices;						// Vertex VBO Name
	unsigned int	m_nVBOTexCoords;					// Texture Coordinate VBO Name

	// Temporary Data
	AUX_RGBImageRec* m_pTextureImage;					// Heightmap Data

public:


	bool Load(char* szPath, float flHeightScale, float flResolution );
	float PointHeight(int nX, int nY);
	void BuildVBOS(void);
};
