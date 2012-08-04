#include "stdafx.h"
#include "QStarCatalog.h"

QStarCatalog::QStarCatalog(QLog *pLog)
{ 
  m_pLog = pLog;
  m_pStars = new QStar[10000];
  m_pNumStars = 0;

}

QStarCatalog::~QStarCatalog(void)
{
	delete [] m_pStars;
}

int QStarCatalog::LoadString(char *pBuffer)
{
	int index = 0;
	fread(pBuffer, 1, 1, pFile);
	while (*(pBuffer + index++) != 0) {
		fread(pBuffer + index, 1, 1, pFile);
	}
	return strlen(pBuffer) + 1;
}

int QStarCatalog::Load(char * strFileName)
{

	float tmp;
	int d;
	char Buffer[255];
	pFile = fopen(strFileName,"r");
	while (!feof(pFile))
	{ 
		Buffer[0] = 0;			 // Marca Buffer vacio
		fread(Buffer,14,1,pFile); // HR         [1/9110]+ Harvard Revised Number
		//fread(Buffer,9,1,pFile); // Nombre
		Buffer[14] = 0;
	//	sprintf(m_pLog->m_Text, "	QStarCatalog: Loaded %s\n",Buffer);
	//	m_pLog->AddLine(m_pLog->m_Text);
		fread(Buffer,91-14,1,pFile); // HR         [1/9110]+ Harvard Revised Number

		fgets(Buffer,6,pFile); // Leer Longitud
		Buffer[6] = 0;
		
		sprintf(m_pLog->m_Text, "	QStarCatalog: Loaded long %s\n",Buffer);
		m_pLog->AddLine(m_pLog->m_Text);
		sscanf(Buffer,"%f",&tmp);
		m_pStars[m_pNumStars].longitude =tmp;


		fgets(Buffer,2,pFile); // Leer Guion
		fgets(Buffer,6,pFile); // Leer Latitud
		Buffer[6] = 0;
		sprintf(m_pLog->m_Text, "	QStarCatalog: Loaded lat %s\n",Buffer);
		m_pLog->AddLine(m_pLog->m_Text);
		sscanf(Buffer,"%f",&tmp);
		m_pStars[m_pNumStars].latitude =tmp;

		
		fgets(Buffer,6,pFile); // Leer Magnitud
		Buffer[6] = 0;
		sprintf(m_pLog->m_Text, "	QStarCatalog: Loaded mag %s\n",Buffer);
		m_pLog->AddLine(m_pLog->m_Text);
		sscanf(Buffer,"%f",&tmp);
		m_pStars[m_pNumStars].magnitude =tmp;
		fgets(Buffer,254,pFile); // Leer Linea
//		Buffer[107-91-14-7] = 0;
//		sprintf(m_pLog->m_Text, "	QStarCatalog: Loaded %s\n",Buffer);
//		m_pLog->AddLine(m_pLog->m_Text);
		
		//fread(Buffer,85,1,pFile); // Basura
		//fread(&tmp,sizeof(float),1,pFile);
		//fread(&tmp,sizeof(float),1,pFile);
		//fread(&tmp,sizeof(float),1,pFile);
		//fread(Buffer,89,1,pFile); // Basura
		//fread(Buffer,182,1,pFile); // Basura

		
		
		m_pNumStars++;
			
	}
	fclose(pFile);
	sprintf(m_pLog->m_Text, "	QStarCatalog: Loaded %d Stars\n",m_pNumStars);
	m_pLog->AddLine(m_pLog->m_Text);
		
	return 0;

}

void QStarCatalog::Render()
{
	glBegin(GL_POINTS);
	for (int i=0;i<m_pNumStars;i++)
	{
		if (m_pStars[i].magnitude <3 ) 
		{	float nx =100 *  cos(m_pStars[i].longitude)  * cos(m_pStars[i].latitude);
			float ny =100 *  sin(m_pStars[i].longitude)  * cos(m_pStars[i].latitude);
			float nz =100 *  sin(m_pStars[i].latitude);

			glVertex3f(nx,ny,nz);
		}


	}
	glEnd();
}

