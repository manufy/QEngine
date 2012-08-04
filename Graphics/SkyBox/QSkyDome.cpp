// SkyDome.cpp: implementation of the CSkyDome class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "QSkyDome.h"
#include <assert.h>

#include "QStarCatalog.h"

#define DTOR (PI/180.0f)

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

QSkyDome::QSkyDome(QLog *pLog)
{
	m_NumVertex = 0;
	m_pVertexList = NULL;
//	m_pSkyBodyList = NULL;
//	m_pSkyCloudsList = NULL;
	m_pLog =pLog;
	sprintf(m_pLog->m_Text, "	QSkyDome: Constructor\n");
	m_pLog->AddLine(m_pLog->m_Text);
	m_pStars = NULL;
}

QSkyDome::~QSkyDome()
{
	sprintf(m_pLog->m_Text, "	QSkyDome: Destructor\n");
	m_pLog->AddLine(m_pLog->m_Text);
	if (m_pStars)
		delete m_pStars;
	delete [] m_pVertexList;

}
int QSkyDome::LoadStars(char * strFileName)
{
	m_pStars = new QStarCatalog(m_pLog);
	m_pStars->Load("stars.dat");
	return 0;
}

int QSkyDome::GetJulianDateT(int Day, int Month, int Year, int Hour, int Min, int Sec)
{
	int Year2;
	int Month2;
	if (Month==1 || Month ==2)
	{  
        Year2 = Year - 1;
		Month2 = Month+12;
	}
	else
	{
		Year2 = Year;
		Month2 = Month;

	}
	float JD  = 1720996 - (Year2 / 100) + (Year2 / 400) +(365.25*(Year2)) ;
	   JD += (30.6001 * (Month2 + 1)) + Day;
       JD += (Hour + ( Min + Sec/60)/60)/24;

	float T = (JD - 2451545)/36525;
	return T; 
}

int QSkyDome::GetEclipticObliquity(float T)
{
	float E= 0.409093 - ( 0.000227 * T);
	return E;
}
void QSkyDome::GenerateDome(float radius, float dtheta, float dphi, float hTile, float vTile)
{
	int theta, phi;

	int red = 0;
	int green = 0;
	int blue = 255;

//	int DTOR = 10;
	// Make sure our vertex array is clear
	if (m_pVertexList != NULL) 
	{
		delete m_pVertexList;
		m_pVertexList = NULL;
		m_NumVertex = 0;
	}

	// Initialize our Vertex array
	m_NumVertex = (int)((360/dtheta)*(90/dphi)*4);
	m_pVertexList = new QSkyDomeVertex[m_NumVertex];
	// Used to calculate the UV coordinates
	float vx, vy, vz, mag;

	// Generate the dome
	int n = 0;
	for (phi=0; phi <= 90 - dphi; phi += (int)dphi)
	{
	//	red+=5;
	//	green+=5;
	//	blue= abs(255 - blue);
		//	green+=5;
	//	red+=5;
		for (theta=0; theta <= 360 - dtheta; theta += (int)dtheta)
		{	
			// Calculate the vertex at phi, theta
			m_pVertexList[n].x = radius * sinf(phi*DTOR) * cosf(DTOR*theta);
			m_pVertexList[n].y = radius * sinf(phi*DTOR) * sinf(DTOR*theta);
			m_pVertexList[n].z = radius * cosf(phi*DTOR);

			// Create a vector from the origin to this vertex
			vx = m_pVertexList[n].x;
			vy = m_pVertexList[n].y;
			vz = m_pVertexList[n].z;


			m_pVertexList[n].r = red;
			m_pVertexList[n].g = green;
			m_pVertexList[n].b = blue;

			// Normalize the vector
			mag = (float)sqrt((vx * vx)+(vy*vy)+(vz*vz));
			vx /= mag;
			vy /= mag;
			vz /= mag;

			// Calculate the spherical texture coordinates
			m_pVertexList[n].u = hTile * (float)(atan2(vx, vz)/(PI*2)) + 0.5f;
			m_pVertexList[n].v = vTile * (float)(asinf(vy) / PI) + 0.5f;		
			n++;

			// Calculate the vertex at phi+dphi, theta
			m_pVertexList[n].x = radius * sinf((phi+dphi)*DTOR) * cosf(theta*DTOR);
			m_pVertexList[n].y = radius * sinf((phi+dphi)*DTOR) * sinf(theta*DTOR);
			m_pVertexList[n].z = radius * cosf((phi+dphi)*DTOR);
			
			// Calculate the texture coordinates
			vx = m_pVertexList[n].x;
			vy = m_pVertexList[n].y;
			vz = m_pVertexList[n].z;

			m_pVertexList[n].r = red;
			m_pVertexList[n].g = green;
			m_pVertexList[n].b = blue;


			mag = (float)sqrt((vx*vx)+(vy*vy)+(vz*vz));
			vx /= mag;
			vy /= mag;
			vz /= mag;

			m_pVertexList[n].u = hTile * (float)(atan2(vx, vz)/(PI*2)) + 0.5f;
			m_pVertexList[n].v = vTile * (float)(asinf(vy) / PI) + 0.5f;		
			n++;

			// Calculate the vertex at phi, theta+dtheta
			m_pVertexList[n].x = radius * sinf(DTOR*phi) * cosf(DTOR*(theta+dtheta));
			m_pVertexList[n].y = radius * sinf(DTOR*phi) * sinf(DTOR*(theta+dtheta));
			m_pVertexList[n].z = radius * cosf(DTOR*phi);
			
			// Calculate the texture coordinates
			vx = m_pVertexList[n].x;
			vy = m_pVertexList[n].y;
			vz = m_pVertexList[n].z;

			m_pVertexList[n].r = red;
			m_pVertexList[n].g = green;
			m_pVertexList[n].b = blue;


			mag = (float)sqrt((vx*vx)+(vy*vy)+(vz*vz));
			vx /= mag;
			vy /= mag;
			vz /= mag;

			m_pVertexList[n].u = hTile * (float)(atan2(vx, vz)/(PI*2)) + 0.5f;
			m_pVertexList[n].v = vTile * (float)(asinf(vy) / PI) + 0.5f;		
			n++;

			if (phi > -90 && phi < 90)
			{
				// Calculate the vertex at phi+dphi, theta+dtheta
				m_pVertexList[n].x = radius * sinf((phi+dphi)*DTOR) * cosf(DTOR*(theta+dtheta));
				m_pVertexList[n].y = radius * sinf((phi+dphi)*DTOR) * sinf(DTOR*(theta+dtheta));
				m_pVertexList[n].z = radius * cosf((phi+dphi)*DTOR);
				
				// Calculate the texture coordinates
				vx = m_pVertexList[n].x;
				vy = m_pVertexList[n].y;
				vz = m_pVertexList[n].z;

				mag = (float)sqrt((vx*vx)+(vy*vy)+(vz*vz));
				vx /= mag;
				vy /= mag;
				vz /= mag;



			m_pVertexList[n].r = red;
			m_pVertexList[n].g = green;
			m_pVertexList[n].b = blue;


				m_pVertexList[n].u = hTile * (float)(atan2(vx, vz)/(PI*2)) + 0.5f;
				m_pVertexList[n].v = vTile * (float)(asinf(vy) / PI) + 0.5f;		
				n++;
			}
		
		
		}
	}

	// Fix the problem at the seam
	for (int i=0; i < m_NumVertex-3; i++)
	{
		if (m_pVertexList[i].u - m_pVertexList[i+1].u > 0.9f)
			m_pVertexList[i+1].u += 1.0f;

		if (m_pVertexList[i+1].u - m_pVertexList[i].u > 0.9f)
			m_pVertexList[i].u += 1.0f;

		if (m_pVertexList[i].u - m_pVertexList[i+2].u > 0.9f)
			m_pVertexList[i+2].u += 1.0f;

		if (m_pVertexList[i+2].u - m_pVertexList[i].u > 0.9f)
			m_pVertexList[i].u += 1.0f;

		if (m_pVertexList[i+1].u - m_pVertexList[i+2].u > 0.9f)
			m_pVertexList[i+2].u += 1.0f;

		if (m_pVertexList[i+2].u - m_pVertexList[i+1].u > 0.9f)
			m_pVertexList[i+1].u += 1.0f;

		if (m_pVertexList[i].v - m_pVertexList[i+1].v > 0.8f)
			m_pVertexList[i+1].v += 1.0f;

		if (m_pVertexList[i+1].v - m_pVertexList[i].v > 0.8f)
			m_pVertexList[i].v += 1.0f;

		if (m_pVertexList[i].v - m_pVertexList[i+2].v > 0.8f)
			m_pVertexList[i+2].v += 1.0f;

		if (m_pVertexList[i+2].v - m_pVertexList[i].v > 0.8f)
			m_pVertexList[i].v += 1.0f;

		if (m_pVertexList[i+1].v - m_pVertexList[i+2].v > 0.8f)
			m_pVertexList[i+2].v += 1.0f;

		if (m_pVertexList[i+2].v - m_pVertexList[i+1].v > 0.8f)
			m_pVertexList[i+1].v += 1.0f;
	}
}



void QSkyDome::Render()
{
if (m_pStars)
	m_pStars->Render();
//return;
	bool Wireframe = false;
	static float rot = 0;
	rot+=0.1;
//	if (Wireframe)
//					{
					//	glDisable(GL_TEXTURE_2D);
				//		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	//				}
	//				else
		//			{
				//		glEnable(GL_TEXTURE_2D);
				//		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
		//			}

	glPushMatrix();
	glTranslatef(0.0f, -100.0f, 0.0f);
	glRotatef(rot,0.0f, 1.0f, 0.0f);
	glRotatef(270, 1.0f, 0.0f, 0.0f);

	//glColor3ub(1,1,55);


	glBegin(GL_TRIANGLE_STRIP);

	for (int i=0; i < m_NumVertex; i++)
	{
	//	glColor3f(1.0f, 1.0f, 1.0f);

		glTexCoord2f(m_pVertexList[i].u, m_pVertexList[i].v);
//		glColor3ub(m_pVertexList[i].r,m_pVertexList[i].g,m_pVertexList[i].b);
		glVertex3f(m_pVertexList[i].x, m_pVertexList[i].y, m_pVertexList[i].z);
	}

	glEnd();

	glPopMatrix();
	
	
}

//void QSkyDome::AddClouds(LPSTR strFileName)
//{
	//CSkyClouds *c = new CSkyClouds;
	//c->LoadTexture("clouds.bmp");
//}
