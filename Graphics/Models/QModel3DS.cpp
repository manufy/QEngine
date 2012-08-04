#include "stdafx.h"
#include ".\qmodel3ds.h"





QModel3DS::QModel3DS(QEngine *pEngine) : QModelKeyframed(1, pEngine) 
{
	Model = new t3DModel;
	Model->numOfMaterials = 0;
	Model->numOfObjects = 0;
	Model->pMaterials = NULL;
	Model->pObject = NULL;
}

QModel3DS::~QModel3DS(void)
{
	if (Model->pMaterials)
		delete [] Model->pMaterials;
	if (Model->pObject)
		delete [] Model->pObject;
	if (Model)
		delete Model;
}

int QModel3DS::Load(char *strFileName)
	{
	sprintf(m_pEngine->m_pLog->m_Text, "	QModel3DS: Loading 3DS (%s)\n",strFileName);
	m_pEngine->m_pLog->AddLine(m_pEngine->m_pLog->m_Text);
	
	Model->numOfMaterials =0;
	Model->numOfObjects=0;
	char strMessage[255] = {0};
	tChunk currentChunk = {0};
	// Abrir 3DS
	m_FilePointer = fopen(strFileName, "rb");
	// Existe??
	if(!m_FilePointer) 
	{	m_pEngine->m_pLog->AddLine("	QModel3DS: ERROR, NO FILENAME\n");
		sprintf(strMessage, "Unable to find the file: %s!", strFileName);
		MessageBox(NULL, strMessage, "Error", MB_OK);
		return false;
	}
	// Lee primer chunk
	ReadChunk(&currentChunk);
	// Asegurarse que es 3DS
	if (currentChunk.ID != PRIMARY)
	{
		m_pEngine->m_pLog->AddLine("	QModel3DS: ERROR, NO PRIMARY CHUNK\n");
		sprintf(strMessage, "Unable to load PRIMARY chuck from file: %s!", strFileName);
		MessageBox(NULL, strMessage, "Error", MB_OK);
		return false;
	}

	// Leer datos, crea espacio pal modelo
	Model->pObject = new t3DObject[8000];
	Model->pMaterials = new tMaterialInfo[8000];
	ProcessNextChunk(&currentChunk);
	Import();
	Dump();
	// Limpiar todo
	CleanUp();

	return true;


	return 0;
}



void QModel3DS::CleanUp()
{
	if (m_FilePointer) {
		fclose(m_FilePointer);					// Cerrar fichero
		m_FilePointer = NULL;
	}
}


void QModel3DS::ProcessNextChunk(tChunk *pPreviousChunk)
{
	tMaterialInfo newTexture = {0};				// This is used to add to our material list
	tChunk currentChunk = {0};					// The current chunk to load
	tChunk tempChunk = {0};						// A temp chunk for holding data		

	while (pPreviousChunk->bytesRead < pPreviousChunk->length)
	{
		ReadChunk(&currentChunk);
		switch (currentChunk.ID)
		{
		case VERSION:							// Version 3DS
			currentChunk.bytesRead += fread(gBuffer, 1, currentChunk.length - currentChunk.bytesRead, m_FilePointer);

			// Mayor que 3 da problems
			if ((currentChunk.length - currentChunk.bytesRead == 4) && (gBuffer[0] > 0x03)) {
				MessageBox(NULL, "This 3DS file is over version 3 so it may load incorrectly", "Warning", MB_OK);
			}
			break;

		case OBJECTINFO:						// Version de Mesh
			{	
			ReadChunk(&tempChunk);
			tempChunk.bytesRead += fread(gBuffer, 1, tempChunk.length - tempChunk.bytesRead, m_FilePointer);
			currentChunk.bytesRead += tempChunk.bytesRead;
			ProcessNextChunk(&currentChunk);
			sprintf(m_pEngine->m_pLog->m_Text, "	QModel3DS: Loaded Object Info\n");
			m_pEngine->m_pLog->AddLine(m_pEngine->m_pLog->m_Text);
			break;
		}
		case MATERIAL:							// This holds the material information
			Model->numOfMaterials++;
			ProcessNextMaterialChunk(&currentChunk);
	//		sprintf(m_pEngine->m_pLog->m_Text, "	QModel3DS: Loaded Material\n");
	//		m_pEngine->m_pLog->AddLine(m_pEngine->m_pLog->m_Text);
			break;

		case OBJECT:							// This holds the name of the object being read
			Model->numOfObjects++;
			memset(&(Model->pObject[Model->numOfObjects - 1]), 0, sizeof(t3DObject));
			currentChunk.bytesRead += GetString(Model->pObject[Model->numOfObjects - 1].strName);
			ProcessNextObjectChunk( &currentChunk);
			sprintf(m_pEngine->m_pLog->m_Text, "	QModel3DS: Loaded Object (%d)\n",Model->numOfObjects);
			m_pEngine->m_pLog->AddLine(m_pEngine->m_pLog->m_Text);
			break;

		case EDITKEYFRAME:
			currentChunk.bytesRead += fread(gBuffer, 1, currentChunk.length - currentChunk.bytesRead, m_FilePointer);
			break;

		default: 
	//		sprintf(m_pEngine->m_pLog->m_Text, "	QModel3DS: Unknown ModelChunk ID %x\n",currentChunk.ID);
	//		m_pEngine->m_pLog->AddLine(m_pEngine->m_pLog->m_Text);
			currentChunk.bytesRead += fread(gBuffer, 1, currentChunk.length - currentChunk.bytesRead, m_FilePointer);
			break;
		}
		pPreviousChunk->bytesRead += currentChunk.bytesRead;
	}
}



void QModel3DS::ProcessNextObjectChunk(tChunk *pPreviousChunk)
{
	tChunk currentChunk = {0};
	while (pPreviousChunk->bytesRead < pPreviousChunk->length)
	{
		ReadChunk(&currentChunk);
		switch (currentChunk.ID)
		{
		
		case OBJECT_MESH:					// This lets us know that we are reading a new object
			ProcessNextObjectChunk(&currentChunk);
			sprintf(m_pEngine->m_pLog->m_Text, "	QModel3DS: Loaded Mesh\n");
			m_pEngine->m_pLog->AddLine(m_pEngine->m_pLog->m_Text);
			break;

		case OBJECT_VERTICES:				// This is the objects vertices
			ReadVertices(&currentChunk);
			sprintf(m_pEngine->m_pLog->m_Text, "	QModel3DS: Loaded %d Vertices\n",Model->pObject[Model->numOfObjects - 1].numOfVerts);
			m_pEngine->m_pLog->AddLine(m_pEngine->m_pLog->m_Text);
			break;

		case OBJECT_FACES:					// This is the objects face information
			ReadVertexIndices( &currentChunk);
			sprintf(m_pEngine->m_pLog->m_Text, "	QModel3DS: Loaded %d Faces\n",Model->pObject[Model->numOfObjects - 1].numOfFaces);
			m_pEngine->m_pLog->AddLine(m_pEngine->m_pLog->m_Text);
			break;

		case OBJECT_MATERIAL:				// This holds the material name that the object has
			ReadObjectMaterial( &currentChunk);			
	//		sprintf(m_pEngine->m_pLog->m_Text, "	QModel3DS: Loaded Material\n");
	//		m_pEngine->m_pLog->AddLine(m_pEngine->m_pLog->m_Text);
			break;

		case OBJECT_UV:						// This holds the UV texture coordinates for the object
			ReadUVCoordinates(&currentChunk);
			sprintf(m_pEngine->m_pLog->m_Text, "	QModel3DS: Loaded %d UV\n", Model->pObject[Model->numOfObjects - 1].numTexVertex);
			m_pEngine->m_pLog->AddLine(m_pEngine->m_pLog->m_Text);
			break;

		default:
	//		sprintf(m_pEngine->m_pLog->m_Text, "	QModel3DS: Unknown ObjectChunk ID %x\n",currentChunk.ID);
	//		m_pEngine->m_pLog->AddLine(m_pEngine->m_pLog->m_Text);
			currentChunk.bytesRead += fread(gBuffer, 1, currentChunk.length - currentChunk.bytesRead, m_FilePointer);
			break;
		}
		pPreviousChunk->bytesRead += currentChunk.bytesRead;
	}
}

void QModel3DS::ProcessNextMaterialChunk(tChunk *pPreviousChunk)
{
	tChunk currentChunk = {0};
	while (pPreviousChunk->bytesRead < pPreviousChunk->length)
	{
		ReadChunk(&currentChunk);
		switch (currentChunk.ID)
		{
		case MATNAME:							// This chunk holds the name of the material
			currentChunk.bytesRead += fread(Model->pMaterials[Model->numOfMaterials - 1].strName, 1, currentChunk.length - currentChunk.bytesRead, m_FilePointer);
			sprintf(m_pEngine->m_pLog->m_Text, "	QModel3DS: Material Name: %s\n",Model->pMaterials[Model->numOfMaterials - 1].strName);
			m_pEngine->m_pLog->AddLine(m_pEngine->m_pLog->m_Text);
			break;

		case MATDIFFUSE:						// This holds the R G B color of our object
			ReadColorChunk(&(Model->pMaterials[Model->numOfMaterials - 1]), &currentChunk);
			sprintf(m_pEngine->m_pLog->m_Text, "	QModel3DS:         Color: %d,%d,%d\n",Model->pMaterials[Model->numOfMaterials - 1].color[0],Model->pMaterials[Model->numOfMaterials - 1].color[1],Model->pMaterials[Model->numOfMaterials - 1].color[2]);
			m_pEngine->m_pLog->AddLine(m_pEngine->m_pLog->m_Text);
			break;
		
		case MATMAP:							// This is the header for the texture info
			ProcessNextMaterialChunk(&currentChunk);
			break;

		case MATMAPFILE:						// This stores the file name of the material
			currentChunk.bytesRead += fread(Model->pMaterials[Model->numOfMaterials - 1].strFile, 1, currentChunk.length - currentChunk.bytesRead, m_FilePointer);
			sprintf(m_pEngine->m_pLog->m_Text, "	QModel3DS:          Map: %s\n",Model->pMaterials[Model->numOfMaterials - 1].strFile);
			m_pEngine->m_pLog->AddLine(m_pEngine->m_pLog->m_Text);
			break;
		
		default:  
		//	sprintf(m_pEngine->m_pLog->m_Text, "	QModel3DS: Unknown MaterialChunk ID %x\n",currentChunk.ID);
	//		m_pEngine->m_pLog->AddLine(m_pEngine->m_pLog->m_Text);
			currentChunk.bytesRead += fread(gBuffer, 1, currentChunk.length - currentChunk.bytesRead, m_FilePointer);
			break;
		}
		pPreviousChunk->bytesRead += currentChunk.bytesRead;
	}
}


void QModel3DS::ReadChunk(tChunk *pChunk)
{
	pChunk->bytesRead = fread(&pChunk->ID, 1, 2, m_FilePointer);
	pChunk->bytesRead += fread(&pChunk->length, 1, 4, m_FilePointer);
}


int QModel3DS::GetString(char *pBuffer)
{
	int index = 0;
	fread(pBuffer, 1, 1, m_FilePointer);
	while (*(pBuffer + index++) != 0) {
		fread(pBuffer + index, 1, 1, m_FilePointer);
	}
	return strlen(pBuffer) + 1;
}


void QModel3DS::ReadColorChunk(tMaterialInfo *pMaterial, tChunk *pChunk)
{
	tChunk tempChunk = {0};
	ReadChunk(&tempChunk);
	tempChunk.bytesRead += fread(pMaterial->color, 1, tempChunk.length - tempChunk.bytesRead, m_FilePointer);
	pChunk->bytesRead += tempChunk.bytesRead;
}



void QModel3DS::ReadVertexIndices(tChunk *pPreviousChunk)
{
	unsigned short index = 0;					// This is used to read in the current face index
	pPreviousChunk->bytesRead += fread(&Model->pObject[Model->numOfObjects - 1].numOfFaces, 1, 2, m_FilePointer);
	Model->pObject[Model->numOfObjects - 1].pFaces = new tFace [Model->pObject[Model->numOfObjects - 1].numOfFaces];
	memset(Model->pObject[Model->numOfObjects - 1].pFaces, 0, sizeof(tFace) * Model->pObject[Model->numOfObjects - 1].numOfFaces);
	for(int i = 0; i < Model->pObject[Model->numOfObjects - 1].numOfFaces; i++)
	{
		for(int j = 0; j < 4; j++)
		{
			pPreviousChunk->bytesRead += fread(&index, 1, sizeof(index), m_FilePointer);

			if(j < 3)
			{
				Model->pObject[Model->numOfObjects - 1].pFaces[i].vertIndex[j] = index;
			}
		}
	}
}


///////////////////////////////// READ UV COORDINATES \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*
/////
/////	This function reads in the UV coordinates for the object
/////
///////////////////////////////// READ UV COORDINATES \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*

void QModel3DS::ReadUVCoordinates( tChunk *pPreviousChunk)
{
	// In order to read in the UV indices for the object, we need to first
	// read in the amount there are, then read them in.

	// Read in the number of UV coordinates there are (int)
	pPreviousChunk->bytesRead += fread(&(Model->pObject[Model->numOfObjects - 1].numTexVertex), 1, 2, m_FilePointer);

	// Allocate memory to hold the UV coordinates
	Model->pObject[Model->numOfObjects - 1].pTexVerts = new CVector2 [Model->pObject[Model->numOfObjects - 1].numTexVertex];

	// Read in the texture coodinates (an array 2 float)
	pPreviousChunk->bytesRead += fread(Model->pObject[Model->numOfObjects - 1].pTexVerts, 1, pPreviousChunk->length - pPreviousChunk->bytesRead, m_FilePointer);
}


///////////////////////////////// READ VERTICES \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*
/////
/////	This function reads in the vertices for the object
/////
///////////////////////////////// READ VERTICES \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*

void QModel3DS::ReadVertices(tChunk *pPreviousChunk)
{
	// Like most chunks, before we read in the actual vertices, we need
	// to find out how many there are to read in.  Once we have that number
	// we then fread() them into our vertice array.

	// Read in the number of vertices (int)
	pPreviousChunk->bytesRead += fread(&(Model->pObject[Model->numOfObjects - 1].numOfVerts), 1, 2, m_FilePointer);

	// Allocate the memory for the verts and initialize the structure
	Model->pObject[Model->numOfObjects - 1].pVerts = new CVector3 [Model->pObject[Model->numOfObjects - 1].numOfVerts];
	memset(Model->pObject[Model->numOfObjects - 1].pVerts, 0, sizeof(CVector3) * Model->pObject[Model->numOfObjects - 1].numOfVerts);

	// Read in the array of vertices (an array of 3 floats)
//	pPreviousChunk->bytesRead += fread(Model->pObject->pVerts, 1, pPreviousChunk->length - pPreviousChunk->bytesRead, m_FilePointer);

	// Now we should have all of the vertices read in.  Because 3D Studio Max
	// Models with the Z-Axis pointing up (strange and ugly I know!), we need
	// to flip the y values with the z values in our vertices.  That way it
	// will be normal, with Y pointing up.  If you prefer to work with Z pointing
	// up, then just delete this next loop.  Also, because we swap the Y and Z
	// we need to negate the Z to make it come out correctly.

	// Go through all of the vertices that we just read and swap the Y and Z values
	int index = 0;
	CVector3 tmp;
	for(int i = 0; i < Model->pObject[Model->numOfObjects - 1].numOfVerts; i++)
	{

			   fread (&tmp.x, sizeof(float), 1, m_FilePointer);
               fread (&tmp.y, sizeof(float), 1, m_FilePointer);
               fread (&tmp.z, sizeof(float), 1, m_FilePointer);
			   Model->pObject[Model->numOfObjects - 1].pVerts[index].x = tmp.x;
			   Model->pObject[Model->numOfObjects - 1].pVerts[index].y = tmp.z;
			   Model->pObject[Model->numOfObjects - 1].pVerts[index].z = -tmp.y;
			   index ++;
		// Store off the Y value
		//float fTempY = Model->pObject->pVerts[i].y;
		//float fTempX = Model->pObject->pVerts[i].x;
		//float fTempZ = Model->pObject->pVerts[i].z;

		// Set the Y value to the Z value
	//	Model->pObject->pVerts[i].x = fTempZ;
	//	Model->pObject->pVerts[i].y = fTempZ;
	//	Model->pObject->pVerts[i].z = -fTempY;

		// Set the Z value to the Y value, 
		// but negative Z because 3D Studio max does the opposite.
	//	Model->pObject->pVerts[i].z = -fTempY;
	}
	tmp.x=0;
pPreviousChunk->bytesRead += (sizeof(float) * Model->pObject[Model->numOfObjects - 1].numOfVerts*3);
}























///////////////////////////////// READ OBJECT MATERIAL \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*
/////
/////	This function reads in the material name assigned to the object and sets the materialID
/////
///////////////////////////////// READ OBJECT MATERIAL \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*

void QModel3DS::ReadObjectMaterial( tChunk *pPreviousChunk)
{
	char strMaterial[255] = {0};			// This is used to hold the objects material name
	tChunk TempChunk = {0};
	// *What is a material?*  - A material is either the color or the texture map of the object.
	// It can also hold other information like the brightness, shine, etc... Stuff we don't
	// really care about.  We just want the color, or the texture map file name really.

	// Here we read the material name that is assigned to the current object.
	// strMaterial should now have a string of the material name, like "Material #2" etc..
	pPreviousChunk->bytesRead += GetString(strMaterial);
	
	// Now that we have a material name, we need to go through all of the materials
	// and check the name against each material.  When we find a material in our material
	// list that matches this name we just read in, then we assign the materialID
	// of the object to that material index.  You will notice that we passed in the
	// model to this function.  This is because we need the number of textures.
	// Yes though, we could have just passed in the model and not the object too.

	// Go through all of the textures
	for(int i = 0; i < Model->numOfMaterials; i++)
	{
		// If the material we just read in matches the current texture name
		if(strcmp(strMaterial, Model->pMaterials[i].strName) == 0)
		{
			// Set the material ID to the current index 'i' and stop checking
			Model->pObject[Model->numOfObjects - 1].materialID = i;

			// Now that we found the material, check if it's a texture map.
			// If the strFile has a string length of 1 and over it's a texture
			if(strlen(Model->pMaterials[i].strFile) > 0) {

				// Set the object's flag to say it has a texture map to bind.
				Model->pObject[Model->numOfObjects - 1].bHasTexture = true;
			}	
			break;
		}
		else
		{
			// Set the ID to -1 to show there is no material for this object
			Model->pObject[Model->numOfObjects - 1].materialID = -1;
		}
	}

	sprintf(m_pEngine->m_pLog->m_Text, "	QModel3DS: Loaded ObjectMaterial: %s TextureID: %d\n",strMaterial,Model->pObject[Model->numOfObjects - 1].materialID);
	m_pEngine->m_pLog->AddLine(m_pEngine->m_pLog->m_Text);

	// AKIIIIIIIIIIIIIII METER CARASSSSSSSSSSSSS POR MATERIALLLLLLLLLLLLLLLLLLLLLLLLLLLL

	unsigned short nfaces = 0;
	 short index;
	pPreviousChunk->bytesRead += fread(&nfaces, 1, 2, m_FilePointer);
	for (int n=0; n<nfaces;n++)
	{
		pPreviousChunk->bytesRead += fread(&index, 1, 2, m_FilePointer);
		sprintf(m_pEngine->m_pLog->m_Text, "	QModel3DS: Loaded ObjectMaterial Index: %d\n",index);
		m_pEngine->m_pLog->AddLine(m_pEngine->m_pLog->m_Text);

	}

    pPreviousChunk->bytesRead += fread(gBuffer, 1, pPreviousChunk->length - pPreviousChunk->bytesRead, m_FilePointer);
	};

	// Read past the rest of the chunk since we don't care about shared vertices
	// You will notice we subtract the bytes already read in this chunk from the total length.
//	pPreviousChunk->bytesRead += fread(gBuffer, 1, pPreviousChunk->length - pPreviousChunk->bytesRead, m_FilePointer);
			
// *Note* 
//
// Below are some math functions for calculating vertex normals.  We want vertex normals
// because it makes the lighting look really smooth and life like.  You probably already
// have these functions in the rest of your engine, so you can delete these and call
// your own.  I wanted to add them so I could show how to calculate vertex normals.

//////////////////////////////	Math Functions  ////////////////////////////////*

// This computes the magnitude of a normal.   (magnitude = sqrt(x^2 + y^2 + z^2)
#define Mag(Normal) (sqrt(Normal.x*Normal.x + Normal.y*Normal.y + Normal.z*Normal.z))

// This calculates a vector between 2 points and returns the result

///////////////////////////////// COMPUTER NORMALS \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*
/////
/////	This function computes the normals and vertex normals of the objects
/////
///////////////////////////////// COMPUTER NORMALS \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*

 /* void QModel3DS::ComputeNormals(t3DModel *pModel)
{
	CVector3 vVector1, vVector2, vNormal, vPoly[3];

	// If there are no objects, we can skip this part
	if(pModel->numOfObjects <= 0)
		return;

	// What are vertex normals?  And how are they different from other normals?
	// Well, if you find the normal to a triangle, you are finding a "Face Normal".
	// If you give OpenGL a face normal for lighting, it will make your object look
	// really flat and not very round.  If we find the normal for each vertex, it makes
	// the smooth lighting look.  This also covers up blocky looking objects and they appear
	// to have more polygons than they do.    Basically, what you do is first
	// calculate the face normals, then you take the average of all the normals around each
	// vertex.  It's just averaging.  That way you get a better approximation for that vertex.

	// Go through each of the objects to calculate their normals
	for(int index = 0; index < pModel->numOfObjects; index++)
	{
		// Get the current object
		t3DObject *pObject = &(pModel->pObject[index]);

		// Here we allocate all the memory we need to calculate the normals
		CVector3 *pNormals		= new CVector3 [pObject->numOfFaces];
		CVector3 *pTempNormals	= new CVector3 [pObject->numOfFaces];
		pObject->pNormals		= new CVector3 [pObject->numOfVerts];

		// Go though all of the faces of this object
		for(int i=0; i < pObject->numOfFaces; i++)
		{												
			// To cut down LARGE code, we extract the 3 points of this face
			vPoly[0] = pObject->pVerts[pObject->pFaces[i].vertIndex[0]];
			vPoly[1] = pObject->pVerts[pObject->pFaces[i].vertIndex[1]];
			vPoly[2] = pObject->pVerts[pObject->pFaces[i].vertIndex[2]];

			// Now let's calculate the face normals (Get 2 vectors and find the cross product of those 2)

			vVector1 = Vector(vPoly[0], vPoly[2]);		// Get the vector of the polygon (we just need 2 sides for the normal)
			vVector2 = Vector(vPoly[2], vPoly[1]);		// Get a second vector of the polygon

			vNormal  = Cross(vVector1, vVector2);		// Return the cross product of the 2 vectors (normalize vector, but not a unit vector)
			pTempNormals[i] = vNormal;					// Save the un-normalized normal for the vertex normals
			vNormal  = Normalize(vNormal);				// Normalize the cross product to give us the polygons normal

			pNormals[i] = vNormal;						// Assign the normal to the list of normals
		}

		//////////////// Now Get The Vertex Normals /////////////////

		CVector3 vSum = {0.0, 0.0, 0.0};
		CVector3 vZero = vSum;
		int shared=0;

		for (i = 0; i < pObject->numOfVerts; i++)			// Go through all of the vertices
		{
			for (int j = 0; j < pObject->numOfFaces; j++)	// Go through all of the triangles
			{												// Check if the vertex is shared by another face
				if (pObject->pFaces[j].vertIndex[0] == i || 
					pObject->pFaces[j].vertIndex[1] == i || 
					pObject->pFaces[j].vertIndex[2] == i)
				{
					vSum = AddVector(vSum, pTempNormals[j]);// Add the un-normalized normal of the shared face
					shared++;								// Increase the number of shared triangles
				}
			}      
			
			// Get the normal by dividing the sum by the shared.  We negate the shared so it has the normals pointing out.
			pObject->pNormals[i] = DivideVectorByScaler(vSum, float(-shared));

			// Normalize the normal for the final vertex normal
			pObject->pNormals[i] = Normalize(pObject->pNormals[i]);	

			vSum = vZero;									// Reset the sum
			shared = 0;										// Reset the shared
		}
	
		// Free our memory and start over on the next object
		delete [] pTempNormals;
		delete [] pNormals;
	}
} */


/////////////////////////////////////////////////////////////////////////////////
//
// * QUICK NOTES * 
//
// This was a HUGE amount of knowledge and probably the largest tutorial yet!
// In the next tutorial we will show you how to load a text file format called .obj.
// This is the most common 3D file format that almost ANY 3D software will import.
//
// Once again I should point out that the coordinate system of OpenGL and 3DS Max are different.
// Since 3D Studio Max Models with the Z-Axis pointing up (strange and ugly I know! :), 
// we need to flip the y values with the z values in our vertices.  That way it
// will be normal, with Y pointing up.  Also, because we swap the Y and Z we need to negate 
// the Z to make it come out correctly.  This is also explained and done in ReadVertices().
//
// CHUNKS: What is a chunk anyway?
// 
// "The chunk ID is a unique code which identifies the type of data in this chunk 
// and also may indicate the existence of subordinate chunks. The chunk length indicates 
// the length of following data to be associated with this chunk. Note, this may 
// contain more data than just this chunk. If the length of data is greater than that 
// needed to fill in the information for the chunk, additional subordinate chunks are 
// attached to this chunk immediately following any data needed for this chunk, and 
// should be parsed out. These subordinate chunks may themselves contain subordinate chunks. 
// Unfortunately, there is no indication of the length of data, which is owned by the current 
// chunk, only the total length of data attached to the chunk, which means that the only way 
// to parse out subordinate chunks is to know the exact format of the owning chunk. On the 
// other hand, if a chunk is unknown, the parsing program can skip the entire chunk and 
// subordinate chunks in one jump. " - Jeff Lewis (werewolf@worldgate.com)
//
// In a short amount of words, a chunk is defined this way:
// 2 bytes - Stores the chunk ID (OBJECT, MATERIAL, PRIMARY, etc...)
// 4 bytes - Stores the length of that chunk.  That way you know when that
//           chunk is done and there is a new chunk.
//
// So, to start reading the 3DS file, you read the first 2 bytes of it, then
// the length (using fread()).  It should be the PRIMARY chunk, otherwise it isn't
// a .3DS file.  
//
// Below is a list of the order that you will find the chunks and all the know chunks.
// If you go to www.wosit.org you can find a few documents on the 3DS file format.
// You can also take a look at the 3DS Format.rtf that is included with this tutorial.
//
//
//
//      MAIN3DS  (0x4D4D)
//     |
//     +--EDIT3DS  (0x3D3D)
//     |  |
//     |  +--EDIT_MATERIAL (0xAFFF)
//     |  |  |
//     |  |  +--MAT_NAME01 (0xA000) (See mli Doc) 
//     |  |
//     |  +--EDIT_CONFIG1  (0x0100)
//     |  +--EDIT_CONFIG2  (0x3E3D) 
//     |  +--EDIT_VIEW_P1  (0x7012)
//     |  |  |
//     |  |  +--TOP            (0x0001)
//     |  |  +--BOTTOM         (0x0002)
//     |  |  +--LEFT           (0x0003)
//     |  |  +--RIGHT          (0x0004)
//     |  |  +--FRONT          (0x0005) 
//     |  |  +--BACK           (0x0006)
//     |  |  +--USER           (0x0007)
//     |  |  +--CAMERA         (0xFFFF)
//     |  |  +--LIGHT          (0x0009)
//     |  |  +--DISABLED       (0x0010)  
//     |  |  +--BOGUS          (0x0011)
//     |  |
//     |  +--EDIT_VIEW_P2  (0x7011)
//     |  |  |
//     |  |  +--TOP            (0x0001)
//     |  |  +--BOTTOM         (0x0002)
//     |  |  +--LEFT           (0x0003)
//     |  |  +--RIGHT          (0x0004)
//     |  |  +--FRONT          (0x0005) 
//     |  |  +--BACK           (0x0006)
//     |  |  +--USER           (0x0007)
//     |  |  +--CAMERA         (0xFFFF)
//     |  |  +--LIGHT          (0x0009)
//     |  |  +--DISABLED       (0x0010)  
//     |  |  +--BOGUS          (0x0011)
//     |  |
//     |  +--EDIT_VIEW_P3  (0x7020)
//     |  +--EDIT_VIEW1    (0x7001) 
//     |  +--EDIT_BACKGR   (0x1200) 
//     |  +--EDIT_AMBIENT  (0x2100)
//     |  +--EDIT_OBJECT   (0x4000)
//     |  |  |
//     |  |  +--OBJ_TRIMESH   (0x4100)      
//     |  |  |  |
//     |  |  |  +--TRI_VERTEXL          (0x4110) 
//     |  |  |  +--TRI_VERTEXOPTIONS    (0x4111)
//     |  |  |  +--TRI_MAPPINGCOORS     (0x4140) 
//     |  |  |  +--TRI_MAPPINGSTANDARD  (0x4170)
//     |  |  |  +--TRI_FACEL1           (0x4120)
//     |  |  |  |  |
//     |  |  |  |  +--TRI_SMOOTH            (0x4150)   
//     |  |  |  |  +--TRI_MATERIAL          (0x4130)
//     |  |  |  |
//     |  |  |  +--TRI_LOCAL            (0x4160)
//     |  |  |  +--TRI_VISIBLE          (0x4165)
//     |  |  |
//     |  |  +--OBJ_LIGHT    (0x4600)
//     |  |  |  |
//     |  |  |  +--LIT_OFF              (0x4620)
//     |  |  |  +--LIT_SPOT             (0x4610) 
//     |  |  |  +--LIT_UNKNWN01         (0x465A) 
//     |  |  | 
//     |  |  +--OBJ_CAMERA   (0x4700)
//     |  |  |  |
//     |  |  |  +--CAM_UNKNWN01         (0x4710)
//     |  |  |  +--CAM_UNKNWN02         (0x4720)  
//     |  |  |
//     |  |  +--OBJ_UNKNWN01 (0x4710)
//     |  |  +--OBJ_UNKNWN02 (0x4720)
//     |  |
//     |  +--EDIT_UNKNW01  (0x1100)
//     |  +--EDIT_UNKNW02  (0x1201) 
//     |  +--EDIT_UNKNW03  (0x1300)
//     |  +--EDIT_UNKNW04  (0x1400)
//     |  +--EDIT_UNKNW05  (0x1420)
//     |  +--EDIT_UNKNW06  (0x1450)
//     |  +--EDIT_UNKNW07  (0x1500)
//     |  +--EDIT_UNKNW08  (0x2200)
//     |  +--EDIT_UNKNW09  (0x2201)
//     |  +--EDIT_UNKNW10  (0x2210)
//     |  +--EDIT_UNKNW11  (0x2300)
//     |  +--EDIT_UNKNW12  (0x2302)
//     |  +--EDIT_UNKNW13  (0x2000)
//     |  +--EDIT_UNKNW14  (0xAFFF)
//     |
//     +--KEYF3DS (0xB000)
//        |
//        +--KEYF_UNKNWN01 (0xB00A)
//        +--............. (0x7001) ( viewport, same as editor )
//        +--KEYF_FRAMES   (0xB008)
//        +--KEYF_UNKNWN02 (0xB009)
//        +--KEYF_OBJDES   (0xB002)
//           |
//           +--KEYF_OBJHIERARCH  (0xB010)
//           +--KEYF_OBJDUMMYNAME (0xB011)
//           +--KEYF_OBJUNKNWN01  (0xB013)
//           +--KEYF_OBJUNKNWN02  (0xB014)
//           +--KEYF_OBJUNKNWN03  (0xB015)  
//           +--KEYF_OBJPIVOT     (0xB020)  
//           +--KEYF_OBJUNKNWN04  (0xB021)  
//           +--KEYF_OBJUNKNWN05  (0xB022)  
//
// Once you know how to read chunks, all you have to know is the ID you are looking for
// and what data is stored after that ID.  You need to get the file format for that.
// I can give it to you if you want, or you can go to www.wosit.org for several versions.
// Because this is a proprietary format, it isn't a official document.
//
// I know there was a LOT of information blown over, but it is too much knowledge for
// one tutorial.  In the animation tutorial that I eventually will get to, some of
// the things explained here will be explained in more detail.  I do not claim that
// this is the best .3DS tutorial, or even a GOOD one :)  But it is a good start, and there
// isn't much code out there that is simple when it comes to reading .3DS files.
// So far, this is the best I have seen.  That is why I made it :)
// 
// I would like to thank www.wosit.org and Terry Caton (tcaton@umr.edu) for his help on this.
//
// Let me know if this helps you out!
// 
// 
// Ben Humphrey (DigiBen)
// Game Programmer
// DigiBen@GameTutorials.com
// Co-Web Host of www.GameTutorials.com
//
//

void QModel3DS::Import(void)
{
	QFrame *pNewFrame = new QFrame(m_pEngine,1);	// Crea frame con espacio para 1 QMalla
	QMesh  *pNewMesh  = new QMesh(1);	// Crea QMalla con espacio para una QPrimitiva
	

	for(int i = 0; i <Model->numOfObjects; i++)	// Para todos los objetos
	
	{
		
		t3DObject *pObject = &Model->pObject[i];
		float *pVertexList   = new float[pObject->numOfVerts*3];
		unsigned int *pTriangleList   = new unsigned int[pObject->numOfFaces*3];
		float *pUVList = new float[pObject->numTexVertex*2];

	
		int c = 0;
		for(int j = 0; j < pObject->numOfVerts; j++) // Vertices
			{
				pVertexList[c]     = pObject->pVerts[j].x;
				pVertexList[c+1]   = pObject->pVerts[j].y;
				pVertexList[c+2]   = pObject->pVerts[j].z;
				c+=3;
			}
		c = 0;
		for(int j = 0; j < pObject->numOfFaces; j++) // Vertices
			{
				pTriangleList[c]   = pObject->pFaces[j].vertIndex[0];
				pTriangleList[c+1]   = pObject->pFaces[j].vertIndex[1];
				pTriangleList[c+2]   = pObject->pFaces[j].vertIndex[2];
				c+=3;
			}
		c = 0;
		for(int j = 0; j < pObject->numTexVertex; j++) // Vertices
			{
				pUVList[c]     = pObject->pTexVerts[j].x;
				pUVList[c+1]     = pObject->pTexVerts[j].y;
				c+=2;
			}


			QTriangleList *pNewTriangleList = new QTriangleList(m_pEngine,pObject->numOfVerts,pVertexList, pObject->numOfFaces,pTriangleList, pObject->numTexVertex, pUVList); // Crea lista de triangulos
		pNewMesh->AddPrimitive(pNewTriangleList);
		

	}
	pNewFrame->AddMesh(pNewMesh);

	AddFrame(pNewFrame);
}

void QModel3DS::Render(void)
{	for(int i = 0; i <Model->numOfObjects; i++)	// Para todos los objetos
	{
		
		t3DObject *pObject = &Model->pObject[i];
	//	glBegin(GL_TRIANGLES);
		for(int j = 0; j < pObject->numOfFaces; j++) // Caras
		{
			for(int whichVertex = 0; whichVertex < 3; whichVertex++) // Vertices
				{int index = pObject->pFaces[j].vertIndex[whichVertex];
			//		 glVertex3f(pObject->pVerts[ index ].x, pObject->pVerts[ index ].y, pObject->pVerts[ index ].z);
				}
		
		}
	//	glEnd();
	}
	m_pFrames[0]->Render();
}

void QModel3DS::Dump(void)
{
	for(int i = 0; i <Model->numOfObjects; i++)	// Para todos los objetos
	{	
		t3DObject *pObject = &Model->pObject[i];
		sprintf(m_pEngine->m_pLog->m_Text, "	QModel3DS: DUMP Object %d Vertex: %d Faces: %d Material: %d\n",i,pObject->numOfVerts,pObject->numOfFaces, pObject->materialID);
		m_pEngine->m_pLog->AddLine(m_pEngine->m_pLog->m_Text);
	}
}
