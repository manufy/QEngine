#pragma once

/** \file QVertex.cpp
    \author Manuel Fern�ndez Y��ez
    \date Diciembre 2003.
    \brief Definici�n de V�rtice 3D.
**/

/*! \class QVertex QVertex.h "inc/QVertex.h"
 *  \brief Estructura V�rtice.
 *
 * Contiene las componentes x y z de un Vector 3D. 
 */

/** \author     Manuel Fern�ndez Y��ez
    \date       Diciembre 2003
    \ingroup    graficos
    \brief      Estructura V�rtice. Clase sin funciones miebros, equivalente a una struct.
    \version    1.0

    Se usa principalmente para llenar arrays de v�rtices.
	
**/

class QVertex
{
public:
	QVertex(void);
	~QVertex(void);

		float x;								// X Component
		float y;								// Y Component
		float z;								// Z Component
};
