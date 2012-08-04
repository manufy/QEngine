// QFontOpenGL.cpp: implementation of the QFontOpenGL class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "QFontOpenGL.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

QFontOpenGL::QFontOpenGL(QEngine *pEngine) : QFont (pEngine)
{

}

QFontOpenGL::~QFontOpenGL()
{

}

void QFontOpenGL::Draw2D(int x, int y, char *strText)
{
//	m_pFontList[FontListID]->m_hOldFont = (HFONT)SelectObject(m_pFontList[FontListID]->m_hDc, m_pFontList[FontListID]->m_hFont); // Sin esta linea no rula, cambio de tamañod e fuentes

	m_hOldFont = (HFONT)SelectObject(m_pEngine->m_pWindow->m_hDc, m_hFont); // Sin esta linea no rula, cambio de tamañod e fuentes

	glDisable(GL_DEPTH_TEST);					
	glMatrixMode(GL_PROJECTION);					
	glPushMatrix();	
	glMatrixMode(GL_MODELVIEW);						
	glPushMatrix();							


	

	//char		strText[256];							// This will hold our text to display
	//va_list		argumentPtr;							// This will hold the pointer to the argument list
	//if (strString == NULL)								// Check if a string was given
	//	return;											// Don't render anything then
	//va_start(argumentPtr, strString);					// Parse the arguments out of the string
	//vsprintf(strText, strString, argumentPtr);			// Now add the arguments into the full string
	//va_end(argumentPtr);								// This resets and frees the pointer to the argument list.
	Position2D(x, y);									// Call our own function to position the text on screen
	glPushAttrib(GL_LIST_BIT);	
	glColor3f(1,1,1);						// This saves the list base information
//	glListBase(m_pFontList[FontListID]->m_FontID);							// This sets the lists base
	glListBase(m_FontID);							// This sets the lists base
	glCallLists(strlen(strText), GL_UNSIGNED_BYTE, strText);

	glPopAttrib();		
	
	glMatrixMode(GL_PROJECTION);						// Select The Projection Matrix
	glPopMatrix();	
	glMatrixMode(GL_MODELVIEW);						// Select The Modelview Matrix
	glPopMatrix();

	glEnable(GL_DEPTH_TEST);
}

void QFontOpenGL::Create2D(char *strFontName, int Size)
{
	m_Height = Size;
	m_FontID = glGenLists(MAX_CHARS);					// Generate the list for the font
	m_hFont = CreateFont(Size,							// Our desired HEIGHT of the font
						0,								// The WIDTH (If we leave this zero it will pick the best width depending on the height)
						0,								// The angle of escapement
						0,								// The angle of orientation
						FW_BOLD,						// The font's weight (We want it bold)
						FALSE,							// Italica
						FALSE,							// Subrayado
						FALSE,							// Tachado
						ANSI_CHARSET,					// Tipo del juego de caracteres
						OUT_TT_PRECIS,					// Precision de salida
						CLIP_DEFAULT_PRECIS,			// Precision de recorte
						ANTIALIASED_QUALITY,			// Calidad
						FF_DONTCARE|DEFAULT_PITCH,		// Familia, pitch
						strFontName);					// Nombre
	m_hOldFont = (HFONT)SelectObject(m_pEngine->m_pWindow->m_hDc, m_hFont);	// Sin esta linea no rula, cambio de tamañod e fuentes
	wglUseFontBitmaps(m_pEngine->m_pWindow->m_hDc, 0, MAX_CHARS - 1, m_FontID);	// Construye caracteres
}

void QFontOpenGL::Position2D(int x, int y)
{
// If you are to use this font code for your applications,
	// you must be aware that you cannot position the font in 3D,
	// which means you can't rotate and scale it.  That will be covered in
	// the next font tutorial.  BUT, though that might be a drag, this code
	// is useful because when you display the text, it will always be on top
	// of everything else.  This is good if the camera is moving around, and you
	// don't want the text to move.  If the text was positioned in 3D you would have
	// to come up with a tricky way of making it always render in front of the camera.
	// To do this, we need to set the Raster Position.  That is the position that OpenGL
	// starts drawing at.  Since it's in floating point, it's not very intuitive, so what
	// we do is create a new view port, and then always draw the text at (0, 0, 0) in that
	// view port.  The weird part is that the Y is flipped, so (0, 0) is the bottom left corner.
	// Below we do some simple math to flip it back to normal.

	// Before we create a new view port, we need to save the current one we have.
	// This saves our transform (matrix) information and our current viewport information.
	// At the end of this function we POP it back.
	glPushAttrib( GL_TRANSFORM_BIT | GL_VIEWPORT_BIT );

	// Here we use a new projection and modelview matrix to work with.
	glMatrixMode( GL_PROJECTION );						// Set our matrix to our projection matrix
	glPushMatrix();										// Push on a new matrix to work with
	glLoadIdentity();									// reset the matrix
	glMatrixMode( GL_MODELVIEW );						// Set our matrix to our model view matrix
	glPushMatrix();										// Push on a new matrix to work with
	glLoadIdentity();									// Reset that matrix

	// Because the Y is flipped, we want 0 to be at the top, not bottom.
	// If we subtract the font height from the screen height, that should display the
	// font at the top of the screen (if they passed in 0 for Y), but then we subtract
	// the Y from that to get the desired position.  Since the font's drawing point is
	// at the base line of the font, we needed to subtract the font height to make sure
	// if they passed in (0, 0) it wouldn't be off screen.  If you view this in window mode,
	// the top of the window will cut off part of the font, but in full screen it works fine.
	// You just need to add about 25 to the Y to fix that for window mode.

	y = HEIGHT-y-m_Height-30;				// Calculate the weird screen position

	// Now we create another view port (that is why we saved the old one above).
	// Since glViewPort takes the lower LEFT corner, we needed to change the Y
	// to make it more intuitive when using PositionText().  We minus 1 from the X and Y
	// because 0 is taken into account with the position.  The next 2 parameters are set
	// to 0 for the width and height so it will always draw in the middle of that position.
	// glRasterPos4f() takes (0, 0, 0) as the middle of the viewport, so if we give it a small
	// width/height it will draw at the X and Y given.  Sounds strange, to test this, try
	// using glRasterPos4f(0, 0, 0, 1) instead of PositionText() and you will see, everything
	// will be drawn from the middle.

	glViewport( x,  y,10, 10 );					// Create a new viewport to draw into

	// This is the most important function in here.  This actually positions the text.
	// The parameters are (x, y, z, w).  w should always be 1 , it's a clip coordinate.
	// don't worry about that though.  Because we set the projection and modelview matrix
	// back to the beginning (through LoadIdentity()), the view port is looking at (0, 0, 0).
	// This is the middle, so if we set the drawing position to the middle, it will draw at our
	// X and Y because the width/height of the viewport is 0, starting at X and Y.
	// You can actually call this function (or glRasterPos2f(0, 0)) instead of PositionText(),
	// but it is in floating point and doesn't work as nicely.  You will see why if you try.

	glRasterPos4f( 0,  0,0, 1 );						// Set the drawing position

//	glRasterPos2f( x,y);						// Set the drawing position

	

	// Now that we positioned the raster position, any text we draw afterwards will start
	// from that position.  Now we just have to put everything else back to normal.

	glPopMatrix();										// Pop the current modelview matrix off the stack
	glMatrixMode( GL_PROJECTION );						// Go back into projection mode
	glPopMatrix();										// Pop the projection matrix off the stack

	glPopAttrib();										// This restores our TRANSFORM and VIEWPORT attributes
}

void QFontOpenGL::ActivateFont()
{
	wglUseFontBitmaps(m_pEngine->m_pWindow->m_hDc, 0, MAX_CHARS - 1, m_FontID);	// Builds 255 bitmap characters	
}
