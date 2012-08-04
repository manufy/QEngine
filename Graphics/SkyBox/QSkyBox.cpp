// SkyBox.cpp: implementation of the CSkyBox class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
//#include "Engine3D.h"
#include "QSkyBox.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

#include "..\Managers\QTextureManager.h"

// These defines correspond to an index within the g_Texture[] array.
// We will use these defines to bind the appropriate texture to the
// right side of the box.

#define BACK_ID		0									// The texture ID for the back side of the cube
#define FRONT_ID	1									// The texture ID for the front side of the cube
#define BOTTOM_ID	2									// The texture ID for the bottom side of the cube
#define TOP_ID		3									// The texture ID for the top side of the cube
#define LEFT_ID		4									// The texture ID for the left side of the cube
#define RIGHT_ID	5									// The texture ID for the right side of the cube



//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CSkyBox::CSkyBox()
{

}

CSkyBox::~CSkyBox()
{

}

void CSkyBox::Init(QTextureManager *TextureManager)
{
//	TextureManager->CreateTexture( "Back.bmp",	BACK_ID		);
//	TextureManager->CreateTexture( "Front.bmp",	FRONT_ID	);
//	TextureManager->CreateTexture( "Bottom.bmp",	BOTTOM_ID	);
//	TextureManager->CreateTexture("Top.bmp",		TOP_ID		);
//	TextureManager->CreateTexture("Left.bmp",	LEFT_ID		);
//	TextureManager->CreateTexture("Right.bmp",	RIGHT_ID	);
}

void CSkyBox::CreateSkyBox(QTextureManager *TextureManager,float x, float y, float z, float width, float height, float length)
{
// Also, depending on your culling, the vertex
	// order might need to be changed around.  I don't use culling in this tutorial
	// so it will work fine here, but be sure to remember this if you do.

	
/*	glBindTexture(GL_TEXTURE_2D, TextureManager->m_Textures[BACK_ID]);

	// This centers the sky box around (x, y, z)
	x = x - width  / 2;
	y = y - height / 2;

	glBegin(GL_QUADS);		
	
		glTexCoord2f(1.0f, 0.0f); glVertex3f(x + width, y,			z);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(x + width, y + height, z); 
		glTexCoord2f(0.0f, 1.0f); glVertex3f(x,			y + height, z);
		glTexCoord2f(0.0f, 0.0f); glVertex3f(x,			y,			z);
		
	glEnd();


	glBindTexture(GL_TEXTURE_2D, TextureManager->m_Textures[FRONT_ID]);

	// Start drawing the side as a QUAD
	glBegin(GL_QUADS);	
	
		// Assign the texture coordinates and vertices for the FRONT Side
		glTexCoord2f(1.0f, 0.0f); glVertex3f(x,			y,			z + length);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(x,			y + height, z + length);
		glTexCoord2f(0.0f, 1.0f); glVertex3f(x + width, y + height, z + length); 
		glTexCoord2f(0.0f, 0.0f); glVertex3f(x + width, y,			z + length);
	glEnd();

	// Bind the BOTTOM texture of the sky map to the BOTTOM side of the box
	glBindTexture(GL_TEXTURE_2D, TextureManager->m_Textures[BOTTOM_ID]);

	// Start drawing the side as a QUAD
	glBegin(GL_QUADS);		
	
		// Assign the texture coordinates and vertices for the BOTTOM Side
		glTexCoord2f(1.0f, 0.0f); glVertex3f(x,			y,			z);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(x,			y,			z + length);
		glTexCoord2f(0.0f, 1.0f); glVertex3f(x + width, y,			z + length); 
		glTexCoord2f(0.0f, 0.0f); glVertex3f(x + width, y,			z);
	glEnd();

	// Bind the TOP texture of the sky map to the TOP side of the box
	glBindTexture(GL_TEXTURE_2D, TextureManager->m_Textures[TOP_ID]);
	
	// Start drawing the side as a QUAD
	glBegin(GL_QUADS);		
		
		// Assign the texture coordinates and vertices for the TOP Side
		glTexCoord2f(0.0f, 1.0f); glVertex3f(x + width, y + height, z);
		glTexCoord2f(0.0f, 0.0f); glVertex3f(x + width, y + height, z + length); 
		glTexCoord2f(1.0f, 0.0f); glVertex3f(x,			y + height,	z + length);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(x,			y + height,	z);
		
	glEnd();

	// Bind the LEFT texture of the sky map to the LEFT side of the box
	glBindTexture(GL_TEXTURE_2D, TextureManager->m_Textures[LEFT_ID]);
	
	// Start drawing the side as a QUAD
	glBegin(GL_QUADS);		
		
		// Assign the texture coordinates and vertices for the LEFT Side
		glTexCoord2f(1.0f, 1.0f); glVertex3f(x,			y + height,	z);	
		glTexCoord2f(0.0f, 1.0f); glVertex3f(x,			y + height,	z + length); 
		glTexCoord2f(0.0f, 0.0f); glVertex3f(x,			y,			z + length);
		glTexCoord2f(1.0f, 0.0f); glVertex3f(x,			y,			z);		
		
	glEnd();

	// Bind the RIGHT texture of the sky map to the RIGHT side of the box
	glBindTexture(GL_TEXTURE_2D, TextureManager->m_Textures[RIGHT_ID]);

	// Start drawing the side as a QUAD
	glBegin(GL_QUADS);		

		// Assign the texture coordinates and vertices for the RIGHT Side
		glTexCoord2f(0.0f, 0.0f); glVertex3f(x + width, y,			z);
		glTexCoord2f(1.0f, 0.0f); glVertex3f(x + width, y,			z + length);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(x + width, y + height,	z + length); 
		glTexCoord2f(0.0f, 1.0f); glVertex3f(x + width, y + height,	z);
	glEnd(); */
}
