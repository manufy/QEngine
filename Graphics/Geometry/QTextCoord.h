#pragma once

/** \file QTextCoord.cpp
    \author Manuel Fernández Yáñez
    \date Diciembre 2003.
   \brief Definición de Coordenada de Textura.
**/

/*! \class QTextCoord QTextCoord.h "inc/QTextCoord.h"
 *  \brief Estructura de coordenadas de textura.
 *
 * Contiene las componentes u v de la posicion en el espacio de texturas;
 */

/** \author     Manuel Fernández Yáñez
    \date       Diciembre 2003
    \ingroup    graficos
    \brief      Estructura de Coordenada de Textura. Clase sin funciones miebros, equivalente a una struct.
    \version    1.0

    Se usa principalmente para llenar arrays de coordenadas uv.
	
**/
class QTextCoord
{
public:
	QTextCoord(void);
	~QTextCoord(void);
	float u;								// U Component
	float v;								// V Component
};
