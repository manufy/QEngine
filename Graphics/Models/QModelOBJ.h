#pragma once

class QModelOBJ
{
public:
	QModelOBJ(void);
	~QModelOBJ(void);
int Load(char *strFileName);


struct tFace
{
	int vertIndex[3];			// indicies for the verts that make up this triangle
	int coordIndex[3];			// indicies for the tex coords to texture this face
};
void ReadObjFile();
	// This is called in ReadObjFile() if we find a line starting with 'v'
	void ReadVertexInfo();

	// This is called in ReadObjFile() if we find a line starting with 'f'
	void ReadFaceInfo();

	// This is called when we are finished loading in the face information
	void FillInObjectInfo();

	// This isn't necessary for the loader, but it's nice to have vertex normals for lighting
	void ComputeNormals();

	// Since .obj files don't have texture/material names, we create a function to set them manually.
	// The materialID is the index into the pMaterial array for our model.
	void SetObjectMaterial( int whichObject, int materialID);

	// To make it easier to assign a material to a .obj object we create a funtion to do so.
	// We can pass in the model, the material name, the texture file name and the RGB colors.
	// If we just want a color, pass in NULL for strFile.
	void AddMaterial( char *strName, char *strFile, 
					 int r = 255,      int g = 255,   int b = 255);


private:

	// This holds our file pointer for reading in the file
	FILE *m_FilePointer;

	// This is an STL (Standard Template Library) vector that holds a list of vertices
//	vector<CVector3>  m_pVertices;

	// This is an STL (Standard Template Library) vector that holds a list of faces
//	vector<tFace> m_pFaces;

	// This is an STL (Standard Template Library) vector that holds a list of UV Coordinates
//	vector<CVector2>  m_pTextureCoords;

	// This tells us if the current object has texture coordinates
	bool m_bObjectHasUV;

	// This tells us if we just read in face data so we can keep track of multiple objects
	bool m_bJustReadAFace;


};
