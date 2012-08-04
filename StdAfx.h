/** \file stdafx.h
    \author Manuel Fernández Yáñez
    \date Octubre 2003. 1Rev: Julio 2003
    \brief Aqui están los includes del sistema, globales para toda la librería QEngine.
**/

// 11-1-2003 Arreglados todos los memory leaks
// 23-7-2003 Bug en postquitmessage???? el resto ok. 

/*! \mainpage QEngine 
*
* Motor para la programación de videojuegos en entornos Win32. 
* \image html a.jpg
* \section intro Introducción
*
* \author Manuel Fernández Yáñez
* 
* QEngine es un Engine 3D desarrollado de modo autodidacta, y con el solo propósito de aprender 
* distintas técnicas de programación en visualización gráfica. QEngine está basado en las APIS
* gráficas OpenGL 1.2 y DirectX 8.1. La documentación se ha generado con Doxygen. El desarrollo
* lo hago con las herramientas de Visual Studio y Visual Assist.
*
* \section features Características, algunas presentes y otras por implementas
*
* - APIs gráficas soportadas: OpenGL 1.2 y DirectX 9 
* - Sonido y gestión de entrada (teclado, ratón, joystick, guante 3D, force feedback)
* - Efectos especiales: blendings, radial blur, etc.
* - Cámaras e interpolacion de trayectorias de cámara con quaterniones. Opticas, ojo de pez.
* - Lens flares.
* - Terreno y Nubes.
* - Niebla.
* - Varias pasadas simultaneas de texturizacion.
* - LightMaps
* - Terrenos voxel y heightmap. Generacion con tecnicas fractales, punto medio y perlin noise.
* - Sistema de partículas.
* - Detección de colisiones con cubos, esferas, elipsoides y modo alta resolución.
* - Temporizadores de alta precisión.
* - Clases derivadas de las Microsoft FOundation Classes para el desarrollo rápido de aplicaciones 3D bajo vc++.
* - Modelos MD2, MD3, MS3D, OBJ y 3DS
* - Gestión de actores
* - Networking cliente servidor
* - Servidor XML
*
*
* \section design Diseño
*
* Clases "conceptuales"
*
* QEngine esta pensado como un objeto a añadir a la aplicación que lo usa mediante una simple definición a nivel de código fuente.
* Pueden existir múltiples objetos QEngine en ejecución simultaneamente, representando múltiples universos 3D.
*
* QEngine se clasifica en varios apartados , comunes a diversos tipos de objetos:
*
* Core: Núcleo, elementos básicos como temporizadores, gestión de memoria, tipos abstractos de datos usados y sistema de log. Abstracción del Hardware.
*   
* Graphics:     Clases relacionadas con el renderizado de escenas, modelos, efectos, terrenos, skybox.
*
* Sound:        Clases relacionadas con la gestión de sonido, sonido 3D, efectos, mp3, wavs. etc
*
* Input:        Gestión de dispositivos de entrada: teclado, ratón, jopystick, guante.
*
* Script:       Lenguaje de script implementado mediante máquina virtual. Plugins para lenguajes standard. 
*
* Physics:      Gestión del sistema físico, integradores, huesos, muelles.
*
* Game:         Sistema de construccion de videojuegos, núcleo, IA.
* 

* \section implement Implementación
*
* El código fuente se halla distribuido en varios directorios, correspondientes a la clasificación de apartados del diseño.
*
*
* Windows: QEngine compila bajo Visual C++ 6.0 , como librería estática. Como addons del vc++ uso una macro para
* la regeneración automática del número de version despues de cada compilación, además de Visual Assist para la
* gestión inteligente del código fuente.
*
*
* \todo Implementar tecnología COM bajo Windows
* \todo Linux: Los planes son portar a GCC (Una vez que compile bajo DevC++). Como implementación gráfica, OpenGL y SDL.
* \todo En cuanto al lenguaje de Script, aun está en desarrollo. Actualmente implementado con flex/bison posiblemente se porte a Accent ó Lemon.
*
*
* \section install Instalación
*
* Este engine esta pensado para usarse como una librería estática, aunque nada impide su implementación mediante
* DLL, COM/COM+, .NET, y CORBA.
*
* \subsection paso1 Paso 1: Descargar el paquete
*
* Supongo que no tendrás problemas en este punto.
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

/**< Versión del producto, en formato String */
//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_STDAFX_H__67970465_D4CA_4E1B_AD98_537CFD2FAF68__INCLUDED_)
