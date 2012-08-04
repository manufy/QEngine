#include "stdafx.h"
#include ".\qmodelobj.h"

QModelOBJ::QModelOBJ(void)
{
}

QModelOBJ::~QModelOBJ(void)
{
}

int QModelOBJ::Load(char *strFileName)
{m_FilePointer = fopen(strFileName, "r");
ReadObjFile();
fclose(m_FilePointer);


	return 0;
}




void QModelOBJ::ReadObjFile()
{
	char strLine[255]		= {0};
	char ch					= 0;

	while(!feof(m_FilePointer))
	{
		float x = 0.0f, y = 0.0f, z = 0.0f;

		// Get the beginning character of the current line in the .obj file
		ch = fgetc(m_FilePointer);

		switch(ch)
		{
		case 'v':						// Check if we just read in a 'v' (Could be a vertice/normal/textureCoord)
			
			// If we just read in a face line, then we have gone to another object,
			// so we need to save the last object's data before moving onto the next one.
			if(m_bJustReadAFace) {
				// Save the last object's info into our model structure
				FillInObjectInfo();
			}
		ReadVertexInfo();
			break;

		case 'f':						// Check if we just read in a face header ('f')
			
			ReadFaceInfo();
			break;

		case '\n':

			break;

		default:

			// If we get here then we don't care about the line being read, so read past it.
			fgets(strLine, 100, m_FilePointer);
			break;
		}
	}

	// Now that we are done reading in the file, we have need to save the last object read.
	FillInObjectInfo();
}


///////////////////////////////// READ VERTEX INFO \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*
/////
/////	This function reads in the vertex information ("v" vertex : "vt" UVCoord)
/////
///////////////////////////////// READ VERTEX INFO \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*

void QModelOBJ::ReadVertexInfo()
{
	CVector3 vNewVertex		 ;
	CVector2 vNewTexCoord	 ;
	char strLine[255]		 ;
	char ch = 0;

	// Read the next character in the file to see if it's a vertice/normal/UVCoord
	ch = fgetc(m_FilePointer);

	if(ch == ' ')				// If we get a space it must have been a vertex ("v")
	{
		// Here we read in a vertice.  The format is "v x y z"
		fscanf(m_FilePointer, "%f %f %f", &vNewVertex.x, &vNewVertex.y, &vNewVertex.z);

		// Read the rest of the line so the file pointer returns to the next line.
		fgets(strLine, 100, m_FilePointer);

		// Add a new vertice to our list
//		m_pVertices.push_back(vNewVertex);
	}
	else if(ch == 't')			// If we get a 't' then it must be a texture coordinate ("vt")
	{
		// Here we read in a texture coordinate.  The format is "vt u v"
		fscanf(m_FilePointer, "%f %f", &vNewTexCoord.x, &vNewTexCoord.y);

		// Read the rest of the line so the file pointer returns to the next line.
		fgets(strLine, 100, m_FilePointer);

		// Add a new texture coordinate to our list
	//	m_pTextureCoords.push_back(vNewTexCoord);

		// Set the flag that tells us this object has texture coordinates.
		// Now we know that the face information will list the vertice AND UV index.
		// For example, ("f 1 3 2" verses "f 1/1 2/2 3/3")
		m_bObjectHasUV = true;
	}
	else						// Otherwise it's probably a normal so we don't care ("vn")
	{
		// We calculate our own normals at the end so we read past them.
		fgets(strLine, 100, m_FilePointer);
	}
}


///////////////////////////////// READ FACE INFO \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*
/////
/////	This function reads in the face information ("f")
/////
///////////////////////////////// READ FACE INFO \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*

void QModelOBJ::ReadFaceInfo()
{
	tFace newFace			= {0};
	char strLine[255]		= {0};

	// This function reads in the face information of the object.
	// A face is a polygon (a triangle in this case) that has information about it.
	// It has the 3D points that make up the polygon and may also have texture coordinates.
	// When reading in an .obj, objects don't have to have UV texture coordinates so we
	// need to read in the face information differently in that case.  If the object does have
	// UV coordinates, then the format will look like this:
	// "f vertexIndex1/coordIndex1 vertexIndex2/coordIndex2 vertexIndex3/coordIndex3"
	// otherwise the format will look like this:"f vertexIndex1 vertexIndex2 vertexIndex3"
	// The index values index into our vertice and texture coordinate arrays.  More explained in RenderScene().
	// *Note* Make sure if you cut this code out for your own use you minus 1 from the indices.
	// This is because arrays are zero based and the .obj indices start at 1.  Look at FillInObjectInfo().

	// Check if this object has texture coordinates before reading in the values
	if(m_bObjectHasUV )
	{
		// Here we read in the object's vertex and texture coordinate indices.
		// Here is the format: "f vertexIndex1/coordIndex1 vertexIndex2/coordIndex2 vertexIndex3/coordIndex3"
		fscanf(m_FilePointer, "%d/%d %d/%d %d/%d", &newFace.vertIndex[0], &newFace.coordIndex[0],
												   &newFace.vertIndex[1], &newFace.coordIndex[1],
												   &newFace.vertIndex[2], &newFace.coordIndex[2]);				
	}
	else										// The object does NOT have texture coordinates
	{
		// Here we read in just the object's vertex indices.
		// Here is the format: "f vertexIndex1 vertexIndex2 vertexIndex3"
		fscanf(m_FilePointer, "%d %d %d", &newFace.vertIndex[0],
										  &newFace.vertIndex[1],
										  &newFace.vertIndex[2]);				
	}

	// Read the rest of the line so the file pointer returns to the next line.
	fgets(strLine, 100, m_FilePointer);
				
	// Add the new face to our face list
//	m_pFaces.push_back(newFace);

	// We set this flag to TRUE so we know that we just read in some face information.
	// Since face information is the last thing we read in for an object we will check
	// this flag when we read in a vertice.  If it's true, then we just finished reading
	// in an object and we need to save off the information before going to the next object.
	// Since there is no standard header for objects in a .obj file we do it this way.
	m_bJustReadAFace = true;
}


///////////////////////////////// FILL IN OBJECT INFO \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*
/////
/////	This function is called after an object is read in to fill in the model structure
/////
///////////////////////////////// FILL IN OBJECT INFO \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*

void QModelOBJ::FillInObjectInfo()
{
//	t3DObject newObject = {0};
	int textureOffset = 0, vertexOffset = 0;
	int i = 0;

	// If we get here then we just finished reading in an object
	// and need to increase the object count.
//	pModel->numOfObjects++;

	// Add a new object to the list of objects in our model
//	pModel->pObject.push_back(newObject);

	// Get a pointer to the current object so our code is easier to read
//	t3DObject *pObject = &(pModel->pObject[pModel->numOfObjects - 1]);

	// Now that we have our list's full of information, we can get the size
	// of these lists by calling size() from our vectors.  That is one of the
	// wonderful things that the Standard Template Library offers us.  Now you
	// never need to write a link list or constantly call malloc()/new.

	// Here we get the number of faces, vertices and texture coordinates
//	pObject->numOfFaces   = m_pFaces.size();
//	pObject->numOfVerts   = m_pVertices.size();
//	pObject->numTexVertex = m_pTextureCoords.size();

	// If we read in any faces for this object (required)
//	if(pObject->numOfFaces) {

		// Allocate enough memory to store all the faces in our object
//		pObject->pFaces = new tFace [pObject->numOfFaces];
//	}

	// If we read in any vertices for this object (required)
//	if(pObject->numOfVerts) {

		// Allocate enough memory to store all the vertices in our object
//		pObject->pVerts = new CVector3 [pObject->numOfVerts];
	//}	

	// If we read in any texture coordinates for this object (optional)
	//if(pObject->numTexVertex) {
	//	pObject->pTexVerts = new CVector2 [pObject->numTexVertex];
	//	pObject->bHasTexture = true;
//	}	

	// Go through all of the faces in the object
/*	for(i = 0; i < pObject->numOfFaces; i++)
	{
		// Copy the current face from the temporary list to our Model list
		pObject->pFaces[i] = m_pFaces[i];

		// Because of the problem with .obj files not being very object friendly,
		// if a new object is found in the file, the face and texture indices start
		// from the last index that was used in the last object.  That means that if
		// the last one was 8, it would then go to 9 for the next object.  We need to
		// bring that back down to 1, so we just create an offset that we subtract from
		// the vertex and UV indices.

		// Check if this is the first face of the object
		if(i == 0) 
		{
			// If the first index is NOT 1, then we must be past the first object
			if(pObject->pFaces[0].vertIndex[0] != 1) {

				// To create the offset we take the current starting point and then minus 1.
				// Lets say the last object ended at 8.  Well we would then have 9 here.
				// We want to then subtract 8 from the 9 to get back to 1.
				vertexOffset = pObject->pFaces[0].vertIndex[0] - 1;

				// The same goes for texture coordinates, if we have them do the same
				if(pObject->numTexVertex > 0) {

					// Take the current index and minus 1 from it
					textureOffset = pObject->pFaces[0].coordIndex[0] - 1;
				}
			}					
		}

		// Because the face indices start at 1, we need to minus 1 from them due
		// to arrays being zero based.  This is VERY important!
		for(int j = 0; j < 3; j++)
		{
			// For each index, minus 1 to conform with zero based arrays.
			// We also need to add the vertex and texture offsets to subtract
			// the total amount necessary for this to work.  The first object
			// will have a offset of 0 for both since it starts at 1.
			pObject->pFaces[i].vertIndex[j]  -= 1 + vertexOffset;
			pObject->pFaces[i].coordIndex[j] -= 1 + textureOffset;
		}
	}

	// Go through all the vertices in the object
	for(i = 0; i < pObject->numOfVerts; i++)
	{
		// Copy the current vertice from the temporary list to our Model list
		pObject->pVerts[i] = m_pVertices[i];
	}

	// Go through all of the texture coordinates in the object (if any)
	for(i = 0; i < pObject->numTexVertex; i++)
	{
		// Copy the current UV coordinate from the temporary list to our Model list
		pObject->pTexVerts[i] = m_pTextureCoords[i];
	}

	// Since .OBJ files don't have materials, we set the material ID to -1.
	// We need to manually give it a material using AddMaterial().
	pObject->materialID = -1;

	// Now that we have all the information from out list's, we need to clear them
	// so we can be ready for the next object that we read in.
	m_pVertices.clear();
	m_pFaces.clear();
	m_pTextureCoords.clear();

	// Reset these booleans to be prepared for the next object
	m_bObjectHasUV   = false;
	m_bJustReadAFace = false; */
}


///////////////////////////////// SET OBJECT MATERIAL \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*
/////
/////	This function assigns a material to a specific object in our array of objects
/////
///////////////////////////////// SET OBJECT MATERIAL \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*

void QModelOBJ::SetObjectMaterial( int whichObject, int materialID)
{
	// Make sure we have a valid model or else quit the function
	/* if(!pModel) return;

	// Make sure we don't index over the array of objects
	if(whichObject >= pModel->numOfObjects) return;

	// Here we set the material ID assigned to this object
	pModel->pObject[whichObject].materialID = materialID; */
}


///////////////////////////////// ADD MATERIAL \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*
/////
/////	This function adds a material to our model manually since .obj has no such info
/////
///////////////////////////////// ADD MATERIAL \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*

void QModelOBJ::AddMaterial(char *strName, char *strFile, 
									int r,			  int g,		 int b)
{
	/* tMaterialInfo newMaterial = {0};

	// Set the RGB value for this material [0 - RED		1 - GREEN	2 - BLUE]
	newMaterial.color[0] = r; newMaterial.color[1] = g; newMaterial.color[2] = b;

	// If we have a file name passed in, let's copy it to our material structure
	if(strFile) {
		strcpy(newMaterial.strFile, strFile);
	}

	// If we have a material name passed in, let's copy it to our material structure
	if(strName) {
		strcpy(newMaterial.strName, strName);
	}

	// Now we add this material to model's list.  Once again we use the incredibly
	// helpfull STL vector functions for allocating dynamic memory.
	pModel->pMaterials.push_back(newMaterial);

	// Increase the material count
	pModel->numOfMaterials++; */
}
