/** \file QIncludes.h 
    \author Manuel Fernández Yáñez
    \date Enero 2003. Julio 2003.
    \brief Fichero a incluir en proyectos finales. Contiene todos los ficheros de cabecera
	       necesarios para compilar una aplicación con QEngine.
**/

/** \author     Manuel Fernández Yáñez
    \date       Enero 2003. Julio 2003.
    \ingroup    win32
    \todo       Revisar para que no se produzcan recompilaciones completas en casos innecesarios.
    \brief      Fichero a incluir en aplicaciones finales.
    \version    1.0

    Se hace asi (encapsular todos los includes en uno mas grande) para simplificar al máximo la creación de aplicaciones finales.
**/




/**
 *  @defgroup graficos Módulos gráficos 2D y 3D.
 *  Gestión de las operaciones gráficas, bajo OpenGL y DirectX.
 */

/**
 *  @defgroup entrada Módulos para la gestión de dispositivos de entrada.
 *  Gestión de las operaciones de entrada, bajo Win32 API y DirectX.
 */

/**
 *  @defgroup sonido Módulos para la generaciónde música y sonidos.
 *  Gestión de las operaciones de sonido, basada en DirectSounc y DirectMusic
 */

/**
 *  @defgroup general Módulos globales e includes.
 *  Ficheros globales de QEngine.
 */


/** \author     Manuel Fernández Yáñez
    \date       Diciembre 2003
    \ingroup    general
    \brief      Fichero a incluir en aplicaciones.
    \version    1.0

    Contiene los includes necesarios para poder referenciar a todos los componentes de QEngine.
	
**/


// Includes genéricos para una aplicación C

#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include <math.h>

// Subsistema Win32

//#include <basetsd.h>
//#include <commdlg.h>
//#include <mmreg.h>

// Subsistema Win32 - Temporizadores y modelo de componentes

#include <mmsystem.h>		//**< Temporizadores
#include <objbase.h>		//**< Modelo de objetos COM// Subsistema Win32 - OpenGL

#include <gl/gl.h>
#include <gl/glu.h>
#include <gl/glaux.h>



// Subsistema Win32 - DirectX 9 - Núcleo

//#include <dxerr9.h>

// Subsistema Win32 - DirectX 9 - Directsound

#include <dsound.h>			//**< DirectSound

#define INITGUID			//**< Esto no me acuerdo para que era. Algo de las DirectX */

#include <dmusici.h>		//**< DirectMusic
#include <dinput.h>			//**< DirectInput

// Direct 3D
		
#include <d3d9.h>
//#include <D3DX8.h>			// PELIGRO: conflicto con libjpeg.h
#if defined COMPILE_MULTIMON_STUBS
	#define COMPILE_MULTIMON_STUBS 
	#include "multimon.h"
#endif


#define MONITOR_CENTER     0x0001        // center rect to monitor
#define MONITOR_CLIP     0x0000        // clip rect to monitor
#define MONITOR_WORKAREA 0x0002        // use monitor work area
#define MONITOR_AREA     0x0000        // use monitor entire area

#include "Input\QInputManager.h"

#include "Shared\Objects\QLog.h"
#include "Shared\Objects\QTimer.h"
#include "Shared\Objects\QInstance.h"

#include "App\QAppCore.h"
#include "App\QAppWin32.h"

#include "Shared\Managers\QTimerManager.h"
#include "Shared\Managers\QInstanceManager.h"

#include "Graphics\Renderer\QRenderer.h"
#include "Graphics\Renderer\QRendererOpenGL.h"
#include "Graphics\Renderer\QRendererDirectX.h"

#include "Shared\Win32\QMFCView.h" 
#include "Shared\Win32\QMFCViewOpenGL.h" 
#include "Shared\Win32\QMFCViewDirectX.h" 
#include "Shared\Win32\QMFCDoc.h"
#include "Shared\Win32\QMFCApp.h"
#include "Shared\Win32\QWindowWin32.h"

#include "Shared\Win32\QWindowWin32OpenGL.h"
#include "Shared\Win32\QWindowWin32DirectX.h"

#include "Graphics\Objects\QFont.h"
#include "Graphics\Objects\QFontOpenGL.h"
#include "Graphics\Objects\QActor.h"
#include "Graphics\Objects\QTriangle.h"

#include "Graphics\Managers\QFontManager.h"
#include "Graphics\Managers\QTextureManager.h"
#include "Graphics\Managers\QActorManager.h"
#include "Graphics\Managers\QParticleSystemManager.h"
#include "Graphics\Managers\QVertexManager.h"
#include "Graphics\Managers\QTriangleManager.h"

#include "Graphics\Models\QModel.h"
#include "Graphics\Models\QModelKeyframed.h"
#include "Graphics\Models\QFrame.h"
#include "Graphics\Models\QMesh.h"
#include "Graphics\Models\QPrimitive.h"
#include "Graphics\Models\QTriangleList.h"
#include "Graphics\Models\QTriangleListFan.h"
#include "Graphics\Models\QTriangleListStrip.h"
#include "Graphics\Models\QModelMD2.h"
#include "Graphics\Models\QModelRAW.h"
#include "Graphics\Models\QModelMS3D.h"
#include "Graphics\Models\QModel3DS.h"
#include "Graphics\Models\QFrame.h"

#include "Graphics\Particles\QParticleSystem.h"
#include "Graphics\Particles\QParticle.h"

#include "Graphics\Terrain\QTerrain.h"

#include "Graphics\Skybox\QSkybox.h"

#include "Graphics\Skybox\QSkyDome.h"

#include "Graphics\Geometry\QVertex.h"
#include "Graphics\Geometry\QTextCoord.h"

#include "Shared\Math\Vector3.h"
#include "Shared\Math\Vector2.h"
