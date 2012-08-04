// Matrix4.cpp: implementation of the CMatrix4 class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Matrix4.h"


//ostream& operator<<(ostream &os, const CMatrix4 &v)
//{
//		return (os << endl << v.m_Matrix[0] << "," << v.m_Matrix[1] << ","<< v.m_Matrix[2] << ","<< v.m_Matrix[3] <<  endl
//				   << v.m_Matrix[4] << "," << v.m_Matrix[5] << ","<< v.m_Matrix[6] << ","<< v.m_Matrix[7] <<  endl
//				   << v.m_Matrix[8] << "," << v.m_Matrix[9] << ","<< v.m_Matrix[10] << ","<< v.m_Matrix[11] <<  endl
//				   << v.m_Matrix[12] << "," << v.m_Matrix[13] << ","<< v.m_Matrix[14] << ","<< v.m_Matrix[15] <<  endl);
//}

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CMatrix4::CMatrix4()
{
	LoadZero();
}

CMatrix4::~CMatrix4()
{

}

void CMatrix4::LoadIdentity()
{
	 m_Matrix[0]   =  1.0f;
	 m_Matrix[1]   =  0.0f;
	 m_Matrix[2]   =  0.0f;
	 m_Matrix[3]   =  0.0f;
	 m_Matrix[4]   =  0.0f;
	 m_Matrix[5]   =  1.0f;
	 m_Matrix[6]   =  0.0f;
	 m_Matrix[7]   =  0.0f;
	 m_Matrix[8]   =  0.0f;
	 m_Matrix[9]   =  0.0f;
	 m_Matrix[10]  =  1.0f;
	 m_Matrix[11]  =  0.0f;
	 m_Matrix[12]  =  0.0f;
	 m_Matrix[13]  =  0.0f;
	 m_Matrix[14]  =  0.0f;
	 m_Matrix[15]  =  1.0f;
	  
}

void CMatrix4::LoadZero()
{
     m_Matrix[0]    =  0.0f;
	 m_Matrix[1]   =  0.0f;
	 m_Matrix[2]   =  0.0f;
	 m_Matrix[3]   =  0.0f;
	 m_Matrix[4]   =  0.0f;
	 m_Matrix[5]   =  0.0f;
	 m_Matrix[6]   =  0.0f;
	 m_Matrix[7]   =  0.0f;
	 m_Matrix[8]   =  0.0f;
	 m_Matrix[9]   =  0.0f;
	 m_Matrix[10]  =  0.0f;
	 m_Matrix[11]  =  0.0f;
	 m_Matrix[12]  =  0.0f;
	 m_Matrix[13]  =  0.0f;
	 m_Matrix[14]  =  0.0f;
	 m_Matrix[15]  =  0.0f;
}

CMatrix4 CMatrix4::Transpose()
{
   CMatrix4 ret;

   ret.m_Matrix[0] = m_Matrix[0]; 
   ret.m_Matrix[1] = m_Matrix[4]; 
   ret.m_Matrix[2] = m_Matrix[8];
   ret.m_Matrix[3] = m_Matrix[12];
   ret.m_Matrix[4] = m_Matrix[1]; 
   ret.m_Matrix[5] = m_Matrix[5]; 
   ret.m_Matrix[6] = m_Matrix[9]; 
   ret.m_Matrix[7] = m_Matrix[13];
   ret.m_Matrix[8] = m_Matrix[2]; 
   ret.m_Matrix[9] = m_Matrix[6]; 
   ret.m_Matrix[10] = m_Matrix[10];
   ret.m_Matrix[11] = m_Matrix[14];
   ret.m_Matrix[12] = m_Matrix[3];
   ret.m_Matrix[13] = m_Matrix[7]; 
   ret.m_Matrix[14] = m_Matrix[11]; 
   ret.m_Matrix[15] = m_Matrix[15];

   return ret;
}



void CMatrix4::TranslateVector(CVector3 *v)
{
	v->x = v->x+m_Matrix[12];
	v->y = v->y+m_Matrix[13];
	v->z = v->z+m_Matrix[14];
}

void CMatrix4::RotateVector(CVector3 *v)
{
	v->x = v->x*m_Matrix[0]+v->y*m_Matrix[4]+v->z*m_Matrix[8];
	v->y = v->x*m_Matrix[1]+v->y*m_Matrix[5]+v->z*m_Matrix[9];
	v->z = v->x*m_Matrix[2]+v->y*m_Matrix[6]+v->z*m_Matrix[10];

}

CMatrix4 CMatrix4::operator =(CMatrix4 &m2)
{
	m_Matrix[0]  = m2.m_Matrix[0];
	m_Matrix[1]  = m2.m_Matrix[1];
	m_Matrix[2]  = m2.m_Matrix[2];
	m_Matrix[3]  = m2.m_Matrix[3];
	m_Matrix[4]  = m2.m_Matrix[4];
	m_Matrix[5]  = m2.m_Matrix[5];
	m_Matrix[6]  = m2.m_Matrix[6];
	m_Matrix[7]  = m2.m_Matrix[7];
	m_Matrix[8]  = m2.m_Matrix[8];
	m_Matrix[9]  = m2.m_Matrix[9];
	m_Matrix[10] = m2.m_Matrix[10];
	m_Matrix[11] = m2.m_Matrix[11];
	m_Matrix[12] = m2.m_Matrix[12];
	m_Matrix[13] = m2.m_Matrix[13];
	m_Matrix[14] = m2.m_Matrix[14];
	m_Matrix[15] = m2.m_Matrix[15];
	return(*this);
}

CMatrix4 CMatrix4::operator +(CMatrix4 &m2)
{
   CMatrix4 ret;
   ret.m_Matrix[0]  = m_Matrix[0]  + m2.m_Matrix[0];
   ret.m_Matrix[1]  = m_Matrix[1]  + m2.m_Matrix[1];
   ret.m_Matrix[2]  = m_Matrix[2]  + m2.m_Matrix[2];
   ret.m_Matrix[3]  = m_Matrix[3]  + m2.m_Matrix[3];
   ret.m_Matrix[4]  = m_Matrix[4]  + m2.m_Matrix[4];
   ret.m_Matrix[5]  = m_Matrix[5]  + m2.m_Matrix[5];
   ret.m_Matrix[6]  = m_Matrix[6]  + m2.m_Matrix[6];
   ret.m_Matrix[7]  = m_Matrix[7]  + m2.m_Matrix[7];
   ret.m_Matrix[8]  = m_Matrix[8]  + m2.m_Matrix[8]; 
   ret.m_Matrix[9]  = m_Matrix[9]  + m2.m_Matrix[9];
   ret.m_Matrix[10] = m_Matrix[10] + m2.m_Matrix[10];
   ret.m_Matrix[11] = m_Matrix[11] + m2.m_Matrix[11];
   ret.m_Matrix[12] = m_Matrix[12] + m2.m_Matrix[12];
   ret.m_Matrix[13] = m_Matrix[13] + m2.m_Matrix[13];
   ret.m_Matrix[14] = m_Matrix[14] + m2.m_Matrix[14];
   ret.m_Matrix[15] = m_Matrix[15] + m2.m_Matrix[15];
   return ret;
}

CMatrix4 CMatrix4::operator -(CMatrix4 &m2)
{
   CMatrix4 ret;
   ret.m_Matrix[0]  = m_Matrix[0]  - m2.m_Matrix[0];
   ret.m_Matrix[1]  = m_Matrix[1]  - m2.m_Matrix[1];
   ret.m_Matrix[2]  = m_Matrix[2]  - m2.m_Matrix[2];
   ret.m_Matrix[3]  = m_Matrix[3]  - m2.m_Matrix[3];
   ret.m_Matrix[4]  = m_Matrix[4]  - m2.m_Matrix[4];
   ret.m_Matrix[5]  = m_Matrix[5]  - m2.m_Matrix[5];
   ret.m_Matrix[6]  = m_Matrix[6]  - m2.m_Matrix[6];
   ret.m_Matrix[7]  = m_Matrix[7]  - m2.m_Matrix[7];
   ret.m_Matrix[8]  = m_Matrix[8]  - m2.m_Matrix[8]; 
   ret.m_Matrix[9]  = m_Matrix[9]  - m2.m_Matrix[9];
   ret.m_Matrix[10] = m_Matrix[10] - m2.m_Matrix[10];
   ret.m_Matrix[11] = m_Matrix[11] - m2.m_Matrix[11];
   ret.m_Matrix[12] = m_Matrix[12] - m2.m_Matrix[12];
   ret.m_Matrix[13] = m_Matrix[13] - m2.m_Matrix[13];
   ret.m_Matrix[14] = m_Matrix[14] - m2.m_Matrix[14];
   ret.m_Matrix[15] = m_Matrix[15] - m2.m_Matrix[15];
   return ret;
}

void CMatrix4::operator +=(CMatrix4 &m2)
{
	(*this) = (*this) + m2;
}

void CMatrix4::operator -=(CMatrix4 &m2)
{
	(*this) = (*this) - m2;
}

void CMatrix4::Translate(CVector3 v)
{
   m_Matrix[12] += v.x;
   m_Matrix[13] += v.y;
   m_Matrix[14] += v.z;
}

void CMatrix4::Translate(float x, float y, float z)
{
   m_Matrix[12] += x;
   m_Matrix[13] += y;
   m_Matrix[14] += z;
}

CVector3 CMatrix4::operator *(CVector3 v)
{
	return CVector3(
    v.x * m_Matrix[0] + v.y * m_Matrix[4] + v.z * m_Matrix[8] + m_Matrix[12],
    v.x * m_Matrix[1] + v.y * m_Matrix[5] + v.z * m_Matrix[9] + m_Matrix[13],
    v.x * m_Matrix[2] + v.y * m_Matrix[6] + v.z * m_Matrix[10] + m_Matrix[14]);
}

//CVector3 CMatrix4::operator *(CVector3 v, CMatrix4 &m)
//{
	//return CVector3(m * v);
//}

CMatrix4 CMatrix4::operator *(float n)
{
	CMatrix4 ret;
   ret.m_Matrix[0]  = m_Matrix[0]  * n;
   ret.m_Matrix[1]  = m_Matrix[1]  * n;
   ret.m_Matrix[2]  = m_Matrix[2]   * n;
   ret.m_Matrix[3]  = m_Matrix[3]   * n;
   ret.m_Matrix[4]  = m_Matrix[4]   * n;
   ret.m_Matrix[5]  = m_Matrix[5]   * n;
   ret.m_Matrix[6]  = m_Matrix[6]   * n;
   ret.m_Matrix[7]  = m_Matrix[7]   * n;
   ret.m_Matrix[8]  = m_Matrix[8]  * n;
   ret.m_Matrix[9]  = m_Matrix[9]   * n;
   ret.m_Matrix[10] = m_Matrix[10]  * n;
   ret.m_Matrix[11] = m_Matrix[11] * n;
   ret.m_Matrix[12] = m_Matrix[12] * n;
   ret.m_Matrix[13] = m_Matrix[13] * n;
   ret.m_Matrix[14] = m_Matrix[14]  * n;
   ret.m_Matrix[15] = m_Matrix[15]  * n;
   return ret;
}

CMatrix4 CMatrix4::operator /(float n)
{

	CMatrix4 ret;
   ret.m_Matrix[0]  = m_Matrix[0]  / n;
   ret.m_Matrix[1]  = m_Matrix[1]  / n;
   ret.m_Matrix[2]  = m_Matrix[2]   / n;
   ret.m_Matrix[3]  = m_Matrix[3]   / n;
   ret.m_Matrix[4]  = m_Matrix[4]   / n;
   ret.m_Matrix[5]  = m_Matrix[5]   / n;
   ret.m_Matrix[6]  = m_Matrix[6]   / n;
   ret.m_Matrix[7]  = m_Matrix[7]   / n;
   ret.m_Matrix[8]  = m_Matrix[8]  / n;
   ret.m_Matrix[9]  = m_Matrix[9]   / n;
   ret.m_Matrix[10] = m_Matrix[10]  / n;
   ret.m_Matrix[11] = m_Matrix[11] / n;
   ret.m_Matrix[12] = m_Matrix[12] / n;
   ret.m_Matrix[13] = m_Matrix[13] / n;
   ret.m_Matrix[14] = m_Matrix[14]  / n;
   ret.m_Matrix[15] = m_Matrix[15]  / n;
   return ret;
}

CMatrix4 CMatrix4::operator *(CMatrix4 &m2)
{
   CMatrix4 ret;


   ret.m_Matrix[0] = m_Matrix[0] * m2.m_Matrix[0] + m_Matrix[4] * m2.m_Matrix[1] + m_Matrix[8] * m2.m_Matrix[2] + m_Matrix[12] * m2.m_Matrix[3];
   ret.m_Matrix[1] = m_Matrix[1] * m2.m_Matrix[0] + m_Matrix[5] * m2.m_Matrix[1] + m_Matrix[9] * m2.m_Matrix[2] + m_Matrix[13] * m2.m_Matrix[3];
   ret.m_Matrix[2] = m_Matrix[2] * m2.m_Matrix[0] + m_Matrix[6] * m2.m_Matrix[1] + m_Matrix[10] * m2.m_Matrix[2] + m_Matrix[14] * m2.m_Matrix[3];
   ret.m_Matrix[3] = m_Matrix[3] * m2.m_Matrix[0] + m_Matrix[7] * m2.m_Matrix[1] + m_Matrix[11] * m2.m_Matrix[2] + m_Matrix[15] * m2.m_Matrix[3];
   ret.m_Matrix[4] = m_Matrix[0] * m2.m_Matrix[4] + m_Matrix[4] * m2.m_Matrix[5] + m_Matrix[8] * m2.m_Matrix[6] + m_Matrix[12] * m2.m_Matrix[7];
   ret.m_Matrix[5] = m_Matrix[1] * m2.m_Matrix[4] + m_Matrix[5] * m2.m_Matrix[5] + m_Matrix[9] * m2.m_Matrix[6] + m_Matrix[13] * m2.m_Matrix[7];
   ret.m_Matrix[6] = m_Matrix[2] * m2.m_Matrix[4] + m_Matrix[6] * m2.m_Matrix[5] + m_Matrix[10] * m2.m_Matrix[6] + m_Matrix[14] * m2.m_Matrix[7];
   ret.m_Matrix[7] = m_Matrix[3] * m2.m_Matrix[4] + m_Matrix[7] * m2.m_Matrix[5] + m_Matrix[11] * m2.m_Matrix[6] + m_Matrix[15] * m2.m_Matrix[7];
   ret.m_Matrix[8] = m_Matrix[0] * m2.m_Matrix[8] + m_Matrix[4] * m2.m_Matrix[9] + m_Matrix[8] * m2.m_Matrix[10] + m_Matrix[12] * m2.m_Matrix[11];
   ret.m_Matrix[9] = m_Matrix[1] * m2.m_Matrix[8] + m_Matrix[5] * m2.m_Matrix[9] + m_Matrix[9] * m2.m_Matrix[10] + m_Matrix[13] * m2.m_Matrix[11];
   ret.m_Matrix[10]= m_Matrix[2] * m2.m_Matrix[8] + m_Matrix[6] * m2.m_Matrix[9] + m_Matrix[10] * m2.m_Matrix[10] + m_Matrix[14] * m2.m_Matrix[11];
   ret.m_Matrix[11]= m_Matrix[3] * m2.m_Matrix[8] + m_Matrix[7] * m2.m_Matrix[9] + m_Matrix[11] * m2.m_Matrix[10] + m_Matrix[15] * m2.m_Matrix[11];
   ret.m_Matrix[12]= m_Matrix[0] * m2.m_Matrix[12] + m_Matrix[4] * m2.m_Matrix[13] + m_Matrix[8] * m2.m_Matrix[14] + m_Matrix[12] * m2.m_Matrix[15];
   ret.m_Matrix[13]= m_Matrix[1] * m2.m_Matrix[12] + m_Matrix[5] * m2.m_Matrix[13] + m_Matrix[9] * m2.m_Matrix[14] + m_Matrix[13] * m2.m_Matrix[15];
   ret.m_Matrix[14]= m_Matrix[2] * m2.m_Matrix[12] + m_Matrix[6] * m2.m_Matrix[13] + m_Matrix[10] * m2.m_Matrix[14] + m_Matrix[14] * m2.m_Matrix[15];
   ret.m_Matrix[15]= m_Matrix[3] * m2.m_Matrix[12] + m_Matrix[7] * m2.m_Matrix[13] + m_Matrix[11] * m2.m_Matrix[14] + m_Matrix[15] * m2.m_Matrix[15];

   return ret;
}

void CMatrix4::Rotate(float angle, CVector3 v)
{

   float c = (float)cos(angle);
   float s = (float)sin(angle);
   float mc = 1 - c;
   float x = v.x;
   float y = v.y;
   float z = v.z;

   m_Matrix[0] = (x * x * mc) + c;
   m_Matrix[1] = (y * x * mc) + (z * s);
   m_Matrix[2] = (x * z * mc) - (y * s);
   m_Matrix[4] = (x * y * mc) - (z * s);
   m_Matrix[5] = (y * y * mc) + c;
   m_Matrix[6] = (y * z * mc) + (x * s);
   m_Matrix[8] = (x * z * mc) + (y * s);
   m_Matrix[9] = (y * z * mc) - (x * s);
   m_Matrix[10] = (z * z * mc) + c;

}

void CMatrix4::RotateX(float Angle)
{
   float c = (float)cos(Angle);
   float s = (float)sin(Angle);

   m_Matrix[5] = c;   
   m_Matrix[6] = s;
   m_Matrix[9] = -s;  
   m_Matrix[10] = c;  
}

void CMatrix4::RotateY(float Angle)
{
   float c = (float)cos(Angle);
   float s = (float)sin(Angle);

   m_Matrix[0] = c;   
   m_Matrix[2] = -s;
   m_Matrix[8] = s;  
   m_Matrix[10] = c;
}

void CMatrix4::RotateZ(float Angle)
{
   float c = (float)cos(Angle);
   float s = (float)sin(Angle);

   m_Matrix[0] = c;   
   m_Matrix[1] = s;
   m_Matrix[4] = -s;  
   m_Matrix[5] = c;
}

bool CMatrix4::Inverse(CMatrix4 &m2)
{
 int i, j, k, swap;
   float t;
   float temp[4][4];

   for (i = 0; i < 4; i++)
	   for (j = 0; j < 4; j++)
         temp[i][j] = m_Matrix[(i * 4) + j];

   m2.LoadIdentity();

   for (i = 0; i < 4; i++)
   {
      /*
      ** Look for largest element in column
      */
      swap = i;
      for (j = i + 1; j < 4; j++)
         if (fabs(temp[j][i]) > fabs(temp[i][i]))
            swap = j;
   
      if (swap != i)
      {
         /*
         ** Swap rows.
         */
         for (k = 0; k < 4; k++)
         {
            t = temp[i][k];
            temp[i][k] = temp[swap][k];
            temp[swap][k] = t;

            t = m2.m_Matrix[(i * 4) + k];
            m2.m_Matrix[(i * 4) + k] = m2.m_Matrix[(swap * 4) + k];
            m2.m_Matrix[(swap * 4) + k] = t;
         }
      }

      /*
      ** No non-zero pivot.  The matrix is singular, which shouldn't
      ** happen.  This means the user gave us a bad matrix.
      */
      if (temp[i][i] == 0)
         return 0;

      t = temp[i][i];
      for (k = 0; k < 4; k++)
      {
         temp[i][k] /= t;
         m2.m_Matrix[(i * 4) + k] /= t;
      }
      for (j = 0; j < 4; j++)
      {
         if (j != i)
         {
            t = temp[j][i];
            for (k = 0; k < 4; k++)
            {
               temp[j][k] -= temp[i][k] * t;
               m2.m_Matrix[(j * 4) + k] -= m2.m_Matrix[(i * 4) + k] * t;
            }
         }
      }
   }
   return 1;
}

void CMatrix4::CreateFromAxisAngle(CVector3 axis, float theta)
{
		CQuaternion q;
        GLfloat halfTheta = (float)theta * 0.5f;
        GLfloat cosHalfTheta = (float)cos(halfTheta);
        GLfloat sinHalfTheta = (float)sin(halfTheta);
        GLfloat xs, ys, zs, wx, wy, wz, xx, xy, xz, yy, yz, zz;
        q.x = axis.x * sinHalfTheta;
        q.y = axis.y * sinHalfTheta;
        q.z = axis.z * sinHalfTheta;
        q.w = cosHalfTheta;
        xs = q.x * 2;  ys = q.y * 2;  zs = q.z * 2;
        wx = q.w * xs; wy = q.w * ys; wz = q.w * zs;
        xx = q.x * xs; xy = q.x * ys; xz = q.x * zs;
        yy = q.y * ys; yz = q.y * zs; zz = q.z * zs;
        m_Matrix[0] = 1 - (yy + zz);
        m_Matrix[1] = xy - wz;
        m_Matrix[2] = xz + wy;
        m_Matrix[4] = xy + wz;
        m_Matrix[5] = 1 - (xx + zz);
        m_Matrix[6] = yz - wx;
        m_Matrix[8] = xz - wy;
        m_Matrix[9] = yz + wx;
        m_Matrix[10] = 1 - (xx + yy);
        m_Matrix[12] = m_Matrix[13] = m_Matrix[14] = m_Matrix[3] = m_Matrix[7] = m_Matrix[11] = 0;
        m_Matrix[15] = 1;
}

void CMatrix4::SetTranslation(CVector3 t)
{
	m_Matrix[12] = t.x;
	m_Matrix[13] = t.y;
	m_Matrix[14] = t.z;
}

void CMatrix4::SetInverseTranslation(CVector3 t)
{
	m_Matrix[12] = -t.x;
	m_Matrix[13] = -t.y;
	m_Matrix[14] = -t.z;
}

void CMatrix4::SetRotationDegrees(CVector3 v)
{

	v.x = ( float )( v.x*180.0/PI );
	v.y = ( float )( v.y*180.0/PI );
	v.z = ( float )( v.z*180.0/PI );
	SetRotationRadians(v);
}


void CMatrix4::SetRotationRadians(CVector3 v)
{
	double cr = cos( v.x );
	double sr = sin( v.x );
	double cp = cos( v.y );
	double sp = sin( v.y );
	double cy = cos( v.z );
	double sy = sin( v.z );

	m_Matrix[0] = ( float )( cp*cy );
	m_Matrix[1] = ( float )( cp*sy );
	m_Matrix[2] = ( float )( -sp );

	double srsp = sr*sp;
	double crsp = cr*sp;

	m_Matrix[4] = ( float )( srsp*cy-cr*sy );
	m_Matrix[5] = ( float )( srsp*sy+cr*cy );
	m_Matrix[6] = ( float )( sr*cp );

	m_Matrix[8] = ( float )( crsp*cy+sr*sy );
	m_Matrix[9] = ( float )( crsp*sy-sr*cy );
	m_Matrix[10] = ( float )( cr*cp );
}

void CMatrix4::SetInverseRotationDegrees(CVector3 v)
{

	v.x = ( float )( v.x*180.0/PI );
	v.y = ( float )( v.y*180.0/PI );
	v.z = ( float )( v.z*180.0/PI );
	SetInverseRotationRadians( v );
}

void CMatrix4::SetInverseRotationRadians(CVector3 v)
{
	double cr = cos( v.x );
	double sr = sin( v.x );
	double cp = cos( v.y );
	double sp = sin( v.y );
	double cy = cos( v.z );
	double sy = sin( v.z );

	m_Matrix[0] = ( float )( cp*cy );
	m_Matrix[4] = ( float )( cp*sy );
	m_Matrix[8] = ( float )( -sp );

	double srsp = sr*sp;
	double crsp = cr*sp;

	m_Matrix[1] = ( float )( srsp*cy-cr*sy );
	m_Matrix[5] = ( float )( srsp*sy+cr*cy );
	m_Matrix[9] = ( float )( sr*cp );

	m_Matrix[2] = ( float )( crsp*cy+sr*sy );
	m_Matrix[6] = ( float )( crsp*sy-sr*cy );
	m_Matrix[10] = ( float )( cr*cp );
}
