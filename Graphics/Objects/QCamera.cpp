// QCamera.cpp: implementation of the QCamera class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "QCamera.h"


#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif



//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

QCamera::QCamera()
{
	CVector3 vZero = CVector3(0.0, 0.0, 0.0);		// Init a vVector to 0 0 0 for our position
	CVector3 vView = CVector3(0.0, 1.0, 0.5);		// Init a starting view vVector (looking up and out the screen) 
	CVector3 vUp   = CVector3(0.0, 0.0, 1.0);		// Init a standard up vVector (Rarely ever changes)

	m_vPosition	= m_vOldPosition	= vZero;					// Init the position to zero
	m_vView		= m_vOldView		= vView;					// Init the view to a std starting view
	m_vUpVector	= m_vOldUpVector	= vUp;	

	m_InstanceAttached = 0; // Modo libre
}

QCamera::~QCamera()
{

}

void QCamera::PositionCamera(float px, float py, float pz, float vx, float vy, float vz, float ux, float uy, float uz)
{

	CVector3 vPosition	= CVector3(px, py, pz);
	CVector3 vView		= CVector3(vx, vy, vz);
	CVector3 vUpVector	= CVector3(ux, uy, uz);

	m_vPosition = vPosition;					// Assign the position
	m_vView     = vView;						// Assign the view
	m_vUpVector	= vUpVector;							// Assign the up vector

}

void QCamera::RotateView(float angle, float x, float y, float z)
{
	CVector3 vNewView;

	// Get the view vector (The direction we are facing)
	CVector3 vView = m_vView - m_vPosition;		

	// Calculate the sine and cosine of the angle once
	float cosTheta = (float)cos(angle);
	float sinTheta = (float)sin(angle);

	// Find the new x position for the new rotated point
	vNewView.x  = (cosTheta + (1 - cosTheta) * x * x)		* vView.x;
	vNewView.x += ((1 - cosTheta) * x * y - z * sinTheta)	* vView.y;
	vNewView.x += ((1 - cosTheta) * x * z + y * sinTheta)	* vView.z;

	// Find the new y position for the new rotated point
	vNewView.y  = ((1 - cosTheta) * x * y + z * sinTheta)	* vView.x;
	vNewView.y += (cosTheta + (1 - cosTheta) * y * y)		* vView.y;
	vNewView.y += ((1 - cosTheta) * y * z - x * sinTheta)	* vView.z;

	// Find the new z position for the new rotated point
	vNewView.z  = ((1 - cosTheta) * x * z - y * sinTheta)	* vView.x;
	vNewView.z += ((1 - cosTheta) * y * z + x * sinTheta)	* vView.y;
	vNewView.z += (cosTheta + (1 - cosTheta) * z * z)		* vView.z;

	// Now we just add the newly rotated vector to our position to set
	// our new rotated view of our camera.
	m_vView = m_vPosition + vNewView;
}

void QCamera::Look()
{
	gluLookAt(m_vPosition.x, m_vPosition.y, m_vPosition.z,	
			  m_vView.x,	 m_vView.y,     m_vView.z,	
			  m_vUpVector.x, m_vUpVector.y, m_vUpVector.z);
}

void QCamera::SetViewByMouse()
{
	POINT mousePos;	

 

	int middleX = 1152  >> 1;				// This is a binary shift to get half the width
	int middleY = 864 >> 1;				// This is a binary shift to get half the height
	float angleY = 0.0f;							// This is the direction for looking up or down
	float angleZ = 0.0f;							// This will be the value we need to rotate around the Y axis (Left and Right)
	static float currentRotX = 0.0f;


// Get the mouse's current X,Y position
	GetCursorPos(&mousePos);						
	
	// Now that we got the mouse position, we want to put the mouse position
	// back at the middle of the screen.  We pass in half of our screen width and height.
	// The >> operator is a binary shift.  So, we are shifting our width and height 
	// to the right by 1.  If you do the binary math, it is the same thing and dividing by 2, 
	// but extremely faster.  The reason why we put the cursor in the middle of the 
	// screen each time is we can can get a delta (difference) of how far we move 
	// each frame, so we know how much to rotate the camera.

	// If our cursor is still in the middle, we never moved... so don't update the screen
	if( (mousePos.x == middleX) && (mousePos.y == middleY) ) return;

	// Set the mouse position to the middle of our window
	SetCursorPos(middleX, middleY);							

	// Now we need to get the direction (or VECTOR) that the mouse moved.
	// To do this, it's a simple subtraction.  Just take the middle point,
	// and subtract the new point from it:  VECTOR = P1 - P2;   with P1
	// being the middle point (400, 300) and P2 being the new mouse location.
	// Look below at the *Quick Notes* for more information and examples.
	// After we get the X and Y delta (or direction), I divide by 1000 to bring the number
	// down a bit, otherwise the camera would move lightning fast!

	// Get the direction the mouse moved in, but bring the number down to a reasonable amount
	angleY = (float)( (middleX - mousePos.x) ) / 1000.0f;		
	angleZ = (float)( (middleY - mousePos.y) ) / 1000.0f;		

	// Here we keep track of the current rotation (for up and down) so that
	// we can restrict the camera from doing a full 360 loop.
	currentRotX -= angleZ;  

	// If the current rotation (in radians) is greater than 1.0, we want to cap it.
	if(currentRotX > 100.0f)
		currentRotX = 100.0f;
	// Check if the rotation is below -1.0, if so we want to make sure it doesn't continue
	else if(currentRotX < -100.0f)
		currentRotX = -100.0f;
	// Otherwise, we can rotate the view around our position
	else
	{
		// To find the axis we need to rotate around for up and down
		// movements, we need to get a perpendicular vector from the
		// camera's view vector and up vector.  This will be the axis.
		// Before using the axis, it's a good idea to normalize it first.
		CVector3 vAxis;
		vAxis = (m_vView - m_vPosition);
		vAxis^=m_vUpVector | 1.0;


		// Rotate around our perpendicular axis and along the y-axis
		RotateView(angleZ, vAxis.x, vAxis.y, vAxis.z);
		RotateView(angleY, 0, 1, 0);
	}


// Si hubo movimiento, recalcula frustrum

//	if (angleY!=0 || angleZ!=0)
//		Frustrum.CalculateFrustrum();


}

void QCamera::MoveCamera(float speed)
{

	CVector3 vVector = m_vView - m_vPosition;
	vVector | 1.0;

	m_vPosition.x += vVector.x * speed;		// Add our acceleration to our position's X
	m_vPosition.y += vVector.y * speed;		// Add our acceleration to our position's Y
	m_vPosition.z += vVector.z * speed;		// Add our acceleration to our position's Z
	m_vView.x += vVector.x * speed;			// Add our acceleration to our view's X
	m_vView.y += vVector.y * speed;			// Add our acceleration to our view's Y
	m_vView.z += vVector.z * speed;			// Add our acceleration to our view's Z
}

void QCamera::RotateAroundPoint(CVector3 vCenter, float angle, float x, float y, float z)
{
	CVector3 vNewPosition;			

	// To rotate our position around a point, what we need to do is find
	// a vector from our position to the center point we will be rotating around.
	// Once we get this vector, then we rotate it along the specified axis with
	// the specified degree.  Finally the new vector is added center point that we
	// rotated around (vCenter) to become our new position.  That's all it takes.

	// Get the vVector from our position to the center we are rotating around
	CVector3 vPos = m_vPosition - vCenter;

	// Calculate the sine and cosine of the angle once
	float cosTheta = (float)cos(angle);
	float sinTheta = (float)sin(angle);

	// Find the new x position for the new rotated point
	vNewPosition.x  = (cosTheta + (1 - cosTheta) * x * x)		* vPos.x;
	vNewPosition.x += ((1 - cosTheta) * x * y - z * sinTheta)	* vPos.y;
	vNewPosition.x += ((1 - cosTheta) * x * z + y * sinTheta)	* vPos.z;

	// Find the new y position for the new rotated point
	vNewPosition.y  = ((1 - cosTheta) * x * y + z * sinTheta)	* vPos.x;
	vNewPosition.y += (cosTheta + (1 - cosTheta) * y * y)		* vPos.y;
	vNewPosition.y += ((1 - cosTheta) * y * z - x * sinTheta)	* vPos.z;

	// Find the new z position for the new rotated point
	vNewPosition.z  = ((1 - cosTheta) * x * z - y * sinTheta)	* vPos.x;
	vNewPosition.z += ((1 - cosTheta) * y * z + x * sinTheta)	* vPos.y;
	vNewPosition.z += (cosTheta + (1 - cosTheta) * z * z)		* vPos.z;

	// Now we just add the newly rotated vector to our position to set
	// our new rotated position of our camera.
	m_vPosition = vCenter + vNewPosition;
}

void QCamera::SetViewFromKeys(bool Keys[])
{

	float Speed = 1;
	if (Keys[VK_UP]==true) {MoveCamera(Speed);}
	if (Keys[VK_DOWN]==true) { MoveCamera(-Speed);}

	if (Keys[VK_LEFT]==true) { RotateAroundPoint(m_vView,  Speed/100, 0, 1, 0);
							}
	if (Keys[VK_RIGHT]==true) { RotateAroundPoint(m_vView, -Speed/100, 0, 1, 0);}

//	if (Keys[VK_LEFT]==true) { StrafeCamera(0.1f); }
//	if (Keys[VK_RIGHT]==true) { StrafeCamera(-0.1f); }



}

void QCamera::StrafeCamera(float speed)
{
	
	// Add the strafe vector to our position
	m_vPosition.x += m_vStrafe.x * speed;
	m_vPosition.z += m_vStrafe.z * speed;

	// Add the strafe vector to our view
	m_vView.x += m_vStrafe.x * speed;
	m_vView.z += m_vStrafe.z * speed;
}



void QCamera::SaveStatus()
{
	// Graba el estado de la camara en variables temporales

	m_vOldPosition	= m_vPosition;
	m_vOldStrafe	= m_vStrafe;
	m_vOldUpVector	= m_vUpVector;
	m_vOldView		= m_vView;
}

void QCamera::LoadStatus()
{
	// Recupera el estado de la camara de las variables temporales

	m_vPosition		= m_vOldPosition;
	m_vStrafe		= m_vOldStrafe;
	m_vUpVector		= m_vOldUpVector;
	m_vView			= m_vOldView;
}
