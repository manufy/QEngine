/** \file stdafx.h
    \author Manuel Fern�ndez Y��ez
    \date Octubre 2003. 1Rev: Julio 2003
    \brief Aqui est�n los includes del sistema, globales para toda la librer�a QEngine.
**/

// 11-1-2003 Arreglados todos los memory leaks
// 23-7-2003 Bug en postquitmessage???? el resto ok. 

/*! \mainpage QEngine 
*
* Motor para la programaci�n de videojuegos en entornos Win32. 
* \image html a.jpg
* \section intro Introducci�n
*
* \author Manuel Fern�ndez Y��ez
* 
* QEngine es un Engine 3D desarrollado de modo autodidacta, y con el solo prop�sito de aprender 
* distintas t�cnicas de programaci�n en visualizaci�n gr�fica. QEngine est� basado en las APIS
* gr�ficas OpenGL 1.2 y DirectX 8.1. La documentaci�n se ha generado con Doxygen. El desarrollo
* lo hago con las herramientas de Visual Studio y Visual Assist.
*
* \section features Caracter�sticas, algunas presentes y otras por implementas
*
* - APIs gr�ficas soportadas: OpenGL 1.2 y DirectX 9 
* - Sonido y gesti�n de entrada (teclado, rat�n, joystick, guante 3D, force feedback)
* - Efectos especiales: blendings, radial blur, etc.
* - C�maras e interpolacion de trayectorias de c�mara con quaterniones. Opticas, ojo de pez.
* - Lens flares.
* - Terreno y Nubes.
* - Niebla.
* - Varias pasadas simultaneas de texturizacion.
* - LightMaps
* - Terrenos voxel y heightmap. Generacion con tecnicas fractales, punto medio y perlin noise.
* - Sistema de part�culas.
* - Detecci�n de colisiones con cubos, esferas, elipsoides y modo alta resoluci�n.
* - Temporizadores de alta precisi�n.
* - Clases derivadas de las Microsoft FOundation Classes para el desarrollo r�pido de aplicaciones 3D bajo vc++.
* - Modelos MD2, MD3, MS3D, OBJ y 3DS
* - Gesti�n de actores
* - Networking cliente servidor
* - Servidor XML
*
*
* \section design Dise�o
*
* Clases "conceptuales"
*
* QEngine esta pensado como un objeto a a�adir a la aplicaci�n que lo usa mediante una simple definici�n a nivel de c�digo fuente.
* Pueden existir m�ltiples objetos QEngine en ejecuci�n simultaneamente, representando m�ltiples universos 3D.
*
* QEngine se clasifica en varios apartados , comunes a diversos tipos de objetos:
*
* Core: N�cleo, elementos b�sicos como temporizadores, gesti�n de memoria, tipos abstractos de datos usados y sistema de log. Abstracci�n del Hardware.
*   
* Graphics:     Clases relacionadas con el renderizado de escenas, modelos, efectos, terrenos, skybox.
*
* Sound:        Clases relacionadas con la gesti�n de sonido, sonido 3D, efectos, mp3, wavs. etc
*
* Input:        Gesti�n de dispositivos de entrada: teclado, rat�n, jopystick, guante.
*
* Script:       Lenguaje de script implementado mediante m�quina virtual. Plugins para lenguajes standard. 
*
* Physics:      Gesti�n del sistema f�sico, integradores, huesos, muelles.
*
* Game:         Sistema de construccion de videojuegos, n�cleo, IA.
* 

* \section implement Implementaci�n
*
* El c�digo fuente se halla distribuido en varios directorios, correspondientes a la clasificaci�n de apartados del dise�o.
*
*
* Windows: QEngine compila bajo Visual C++ 6.0 , como librer�a est�tica. Como addons del vc++ uso una macro para
* la regeneraci�n autom�tica del n�mero de version despues de cada compilaci�n, adem�s de Visual Assist para la
* gesti�n inteligente del c�digo fuente.
*
*
* \todo Implementar tecnolog�a COM bajo Windows
* \todo Linux: Los planes son portar a GCC (Una vez que compile bajo DevC++). Como implementaci�n gr�fica, OpenGL y SDL.
* \todo En cuanto al lenguaje de Script, aun est� en desarrollo. Actualmente implementado con flex/bison posiblemente se porte a Accent � Lemon.
*
*
* \section install Instalaci�n
*
* Este engine esta pensado para usarse como una librer�a est�tica, aunque nada impide su implementaci�n mediante
* DLL, COM/COM+, .NET, y CORBA.
*
* \subsection paso1 Paso 1: Descargar el paquete
*
* Supongo que no tendr�s problemas en este punto.
*
* \subsection paso2 Paso 2: Descomprimir las fuentes
*
* Apto para cualquier persona capaz de descomprimir .zip. 
*
* \subsection paso3 Paso 3: Incluir la libreria en el proyecto 
*
* Usar #include "..\donde\demonios\este\Qengine.h" donde ya estan contenidas todas las definiciones (.h)
*
* \subsection paso4 Paso 4: Compilando
*
* Probar a incluir un objeto QEngine3D y .. a disfrutar ...
* \section mejoras Mejoras futuras
*
*  - Vertex Shaders y Pixel Shaders
*  - Pelo
*  - Blobs
*  - Fractales IFS y l-sistemas
*  - Mundos distribuidos: SOAP-XML, por supuesto cliente-servidor.
*  - Portar a Linux / SDL.
*
* \section agra Agradecimientos
*
*  Un saludo.
*
*  Manu.
*/


#if !defined(AFX_STDAFX_H__67970465_D4CA_4E1B_AD98_537CFD2FAF68__INCLUDED_)
#define AFX_STDAFX_H__67970465_D4CA_4E1B_AD98_537CFD2FAF68__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#define VC_EXTRALEAN		/**< Excluir cosas raras de las cabeceras de windows */
#define WINVER 0x0501

#define DIRECTINPUT_VERSION 0x0800

// Globales - afw y windows.h

#include <afx.h>
#include <afxwin.h>
#include <windows.h>

// Includes para QEngine. /todo recompilacion condicional.

#include "QIncludes.h"

/**< Versi�n del producto, en formato String */
//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_STDAFX_H__67970465_D4CA_4E1B_AD98_537CFD2FAF68__INCLUDED_)
