#pragma once

/** \file QVertex.cpp
    \author Manuel Fernández Yáñez
    \date Diciembre 2003.
    \brief Definición de Vértice 3D.
**/

/*! \class QVertex QVertex.h "inc/QVertex.h"
 *  \brief Estructura Vértice.
 *
 * Contiene las componentes x y z de un Vector 3D. 
 */

/** \author     Manuel Fernández Yáñez
    \date       Diciembre 2003
    \ingroup    graficos
    \brief      Estructura Vértice. Clase sin funciones miebros, equivalente a una struct.
    \version    1.0

    Se usa principalmente para llenar arrays de vértices.
	
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
