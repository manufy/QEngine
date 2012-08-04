#pragma once

class QTerrain
{
public:
	QTerrain(void);
	~QTerrain(void);
int m_NumVertex;
	void MakeVertex();
int Height(int X, int Y);
void MakeCallList();
	
	void RenderTriangleStrip();
	void LoadRaw(LPSTR Name, int Height, int Width);

CVector3	**m_pTriangleStripVertexList;
BYTE		*m_pHeightMap;
int m_Height;
	int m_Width;
	int m_StepSize;
};
