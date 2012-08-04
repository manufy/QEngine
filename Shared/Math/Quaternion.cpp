// Quaternion.cpp: implementation of the CQuaternion class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Quaternion.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif


#include "math.h"

//////////////////////////////////////////////////////////////////////
// Constructores y destructor
//////////////////////////////////////////////////////////////////////

CQuaternion::CQuaternion()
{
	x = y = z = 0.0f;
	w = 1.0f;
}

CQuaternion::~CQuaternion()
{

}

void CQuaternion::CreateFromAxisAngle(float X, float Y, float Z, float degree) 
{ 
	// Convierte eje-angulo como glRotatef() a Quaternion

	// Estas son las ecuaciones eje-angulo:

	// w = cos( theta / 2 )
	// x = X * sin( theta / 2 )
	// y = Y * sin( theta / 2 )
	// z = Z * sin( theta / 2 )

	
	// Grados a radianes
	float angle = float((degree / 180.0f) * PI);

	// Calcular sin(theta/2) para optimizacion
	float result = (float)sin( angle / 2.0f );
		
	// w = cos(theta2/2)
	w = (float)cos( angle / 2.0f );

	// Calcula x,y,z
	x = float(X * result);
	y = float(Y * result);
	z = float(Z * result);
}


void CQuaternion::CreateMatrix(float *pMatrix)
{
	// Asegurarse de que hay memoria asignada
	if(!pMatrix) return;

	
	//
	//     ¦        2     2												 ¦
    //     ¦ 1 - (2y  + 2z )   2xy + 2zw         2xz - 2yw			0	 ¦
    //     ¦															 ¦
    //     ¦                          2     2							 ¦
    // M = ¦ 2xy - 2zw         1 - (2x  + 2z )   2zy + 2xw			0	 ¦
    //     ¦															 ¦
    //     ¦                                            2     2			 ¦
    //     ¦ 2xz + 2yw         2yz - 2xw         1 - (2x  + 2y )	0	 ¦
    //     ¦															 ¦
	//     ¦															 ¦
	//     ¦ 0				   0				 0					1	 |													 ¦
	//     ¦															 ¦
	// 
	// in our matrix accordingly below.
	
	// 1 fila
	pMatrix[ 0] = 1.0f - 2.0f * ( y * y + z * z ); 
	pMatrix[ 1] = 2.0f * (x * y + z * w);
	pMatrix[ 2] = 2.0f * (x * z - y * w);
	pMatrix[ 3] = 0.0f;  

	// 2 fila
	pMatrix[ 4] = 2.0f * ( x * y - z * w );  
	pMatrix[ 5] = 1.0f - 2.0f * ( x * x + z * z ); 
	pMatrix[ 6] = 2.0f * (z * y + x * w );  
	pMatrix[ 7] = 0.0f;  

	// 3 fila
	pMatrix[ 8] = 2.0f * ( x * z + y * w );
	pMatrix[ 9] = 2.0f * ( y * z - x * w );
	pMatrix[10] = 1.0f - 2.0f * ( x * x + y * y );  
	pMatrix[11] = 0.0f;  

	// 4 fila
	pMatrix[12] = 0;  
	pMatrix[13] = 0;  
	pMatrix[14] = 0;  
	pMatrix[15] = 1.0f;

	// pMatrix[] ahora es una matriz homogenea 4x4 
}

void CQuaternion::Slerp(CQuaternion *a_q1, CQuaternion *a_q2, float a_fInterp)
{
/*	float sclq1;
	float sclq2;
	float omega;
	float sinom;
	float cosom;
	float a= 0;
	float b= 0;
	int i;
	
	for(i=0; i<4; i++)
	{
		a= a+(a_q1[i] - a_q2[i]) * (a_q1[i] - a_q2[i]);
		b+= (a_q1[i] + a_q2[i]) * (a_q1[i] + a_q2[i]);
	}
	if(a>b)
		a_q2.SetInverse();

	cosom = a_q1[0]*a_q2[0]+a_q1[1]*a_q2[1]+a_q1[2]*a_q2[2]+a_q1[3]*a_q2[3];

	if((1+cosom)>0.00000001f)
	{
		if((1.0-cosom)>0.00000001f)
		{
			omega= acosf(cosom);
			sinom= sinf(omega);
			sclq1= sinf((1-a_fInterp)*omega)/sinom;
			sclq2= sinf(a_fInterp*omega)/sinom;
		}
		else
		{
			sclq1= 1-a_fInterp;
			sclq2= a_fInterp;
		}
		for(i=0; i<4; i++)
			p_fQuat[i]= sclq1*a_q1[i]+sclq2*a_q2[i];
	}
	else
	{
		p_fQuat[0]=-a_q1[1];
		p_fQuat[1]= a_q1[0];
		p_fQuat[2]=-a_q1[3];
		p_fQuat[3]= a_q1[2];

		sclq1= sinf(1-a_fInterp)*0.5f*PI;
		sclq2= sinf(a_fInterp*0.5f*PI);
		for(i=0; i<3; i++)
			p_fQuat[i]= sclq1*a_q1[i]+sclq2*p_fQuat[i];
	} */
}

void CQuaternion::Reset()
{
	w = 1;
	x = y = z = 0;
}

const void CQuaternion::operator !()
{
   float Dot = (x * x) + (y * y) + (z * z) + (w * w);

   if (Dot == 0.0f)
      return;

   float Scale = 1.0f / (float) sqrt(Dot);

   x *= Scale;
   y *= Scale;
   z *= Scale;
   w *= Scale;
}
