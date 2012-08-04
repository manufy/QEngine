# Microsoft Developer Studio Project File - Name="QEngine" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Static Library" 0x0104

CFG=QEngine - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "QEngine.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "QEngine.mak" CFG="QEngine - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "QEngine - Win32 Release" (based on "Win32 (x86) Static Library")
!MESSAGE "QEngine - Win32 Debug" (based on "Win32 (x86) Static Library")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
RSC=rc.exe

!IF  "$(CFG)" == "QEngine - Win32 Release"

# PROP BASE Use_MFC 2
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 2
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /Yu"stdafx.h" /FD /c
# ADD CPP /nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Yu"stdafx.h" /FD /c
# ADD BASE RSC /l 0xc0a /d "NDEBUG" /d "_AFXDLL"
# ADD RSC /l 0xc0a /d "NDEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo
# ADD LIB32 /nologo

!ELSEIF  "$(CFG)" == "QEngine - Win32 Debug"

# PROP BASE Use_MFC 2
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 2
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /Yu"stdafx.h" /FD /GZ /c
# ADD CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /FR /Yu"stdafx.h" /FD /GZ /c
# ADD BASE RSC /l 0xc0a /d "_DEBUG" /d "_AFXDLL"
# ADD RSC /l 0xc0a /d "_DEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo
# ADD LIB32 /nologo

!ENDIF 

# Begin Target

# Name "QEngine - Win32 Release"
# Name "QEngine - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=.\Shared\TDA\BitSet.cpp
# End Source File
# Begin Source File

SOURCE=.\Shared\Math\Matrix4.cpp
# End Source File
# Begin Source File

SOURCE=.\Graphics\Objects\QActor.cpp
# End Source File
# Begin Source File

SOURCE=.\Graphics\Managers\QActorManager.cpp
# End Source File
# Begin Source File

SOURCE=.\App\QAppCore.cpp
# End Source File
# Begin Source File

SOURCE=.\App\QAppWin32.cpp
# End Source File
# Begin Source File

SOURCE=.\Graphics\Objects\QCamera.cpp
# End Source File
# Begin Source File

SOURCE=.\Input\QDirectInput.cpp
# End Source File
# Begin Source File

SOURCE=.\QEngine.cpp
# End Source File
# Begin Source File

SOURCE=.\Graphics\Objects\QFont.cpp
# End Source File
# Begin Source File

SOURCE=.\Graphics\Objects\QFontDirectX.cpp
# End Source File
# Begin Source File

SOURCE=.\Graphics\Managers\QFontManager.cpp
# End Source File
# Begin Source File

SOURCE=.\Graphics\Objects\QFontOpenGL.cpp
# End Source File
# Begin Source File

SOURCE=.\Graphics\Models\QFrame.cpp
# End Source File
# Begin Source File

SOURCE=.\Shared\TDA\QHoleManager.cpp
# End Source File
# Begin Source File

SOURCE=.\Shared\TDA\QHoleNode.cpp
# End Source File
# Begin Source File

SOURCE=.\Input\QInputDirectX.cpp
# End Source File
# Begin Source File

SOURCE=.\Input\QInputManager.cpp
# End Source File
# Begin Source File

SOURCE=.\Input\QInputWin32.cpp
# End Source File
# Begin Source File

SOURCE=.\Shared\Objects\QInstance.cpp
# End Source File
# Begin Source File

SOURCE=.\Shared\Managers\QInstanceManager.cpp
# End Source File
# Begin Source File

SOURCE=.\Shared\Objects\QLog.cpp
# End Source File
# Begin Source File

SOURCE=.\Graphics\Models\QMesh.cpp
# End Source File
# Begin Source File

SOURCE=.\Shared\Win32\QMFCApp.cpp
# End Source File
# Begin Source File

SOURCE=.\Shared\Win32\QMFCDoc.cpp
# End Source File
# Begin Source File

SOURCE=.\Shared\Win32\QMFCView.cpp
# End Source File
# Begin Source File

SOURCE=.\Shared\Win32\QMFCViewDirectX.cpp
# End Source File
# Begin Source File

SOURCE=.\Shared\Win32\QMFCViewOpenGL.cpp
# End Source File
# Begin Source File

SOURCE=.\Graphics\Models\QModel.cpp
# End Source File
# Begin Source File

SOURCE=.\Graphics\Models\QModelKeyframed.cpp
# End Source File
# Begin Source File

SOURCE=.\Graphics\Models\QModelMD2.cpp
# End Source File
# Begin Source File

SOURCE=.\Graphics\Models\QModelMD3.cpp
# End Source File
# Begin Source File

SOURCE=.\Graphics\Models\QModelMS3D.cpp
# End Source File
# Begin Source File

SOURCE=.\Graphics\Models\QModelRAW.cpp
# End Source File
# Begin Source File

SOURCE=.\Graphics\Particles\QParticle.cpp
# End Source File
# Begin Source File

SOURCE=.\Graphics\Particles\QParticleSystem.cpp
# End Source File
# Begin Source File

SOURCE=.\Graphics\Managers\QParticleSystemManager.cpp
# End Source File
# Begin Source File

SOURCE=.\Graphics\Models\QPrimitive.cpp
# End Source File
# Begin Source File

SOURCE=.\Graphics\Renderer\QRenderer.cpp
# End Source File
# Begin Source File

SOURCE=.\Graphics\Renderer\QRendererDirectX.cpp
# End Source File
# Begin Source File

SOURCE=.\Graphics\Renderer\QRendererOpenGL.cpp
# End Source File
# Begin Source File

SOURCE=.\Graphics\Textures\QTexture.cpp
# End Source File
# Begin Source File

SOURCE=.\Graphics\Textures\QTextureDirectX.cpp
# End Source File
# Begin Source File

SOURCE=.\Graphics\Managers\QTextureManager.cpp
# End Source File
# Begin Source File

SOURCE=.\Graphics\Textures\QTextureOpenGL.cpp
# End Source File
# Begin Source File

SOURCE=.\Shared\Objects\QTimer.cpp
# End Source File
# Begin Source File

SOURCE=.\Shared\Managers\QTimerManager.cpp
# End Source File
# Begin Source File

SOURCE=.\Graphics\Objects\QTriangle.cpp
# End Source File
# Begin Source File

SOURCE=.\Graphics\Models\QTriangleList.cpp
# End Source File
# Begin Source File

SOURCE=.\Graphics\Models\QTriangleListFan.cpp
# End Source File
# Begin Source File

SOURCE=.\Graphics\Models\QTriangleListStrip.cpp
# End Source File
# Begin Source File

SOURCE=.\Graphics\Managers\QTriangleManager.cpp
# End Source File
# Begin Source File

SOURCE=.\Shared\Math\Quaternion.cpp
# End Source File
# Begin Source File

SOURCE=.\Graphics\Managers\QVertexManager.cpp
# End Source File
# Begin Source File

SOURCE=.\Shared\Win32\QWindowWin32.cpp
# End Source File
# Begin Source File

SOURCE=.\Shared\Win32\QWindowWin32DirectX.cpp
# End Source File
# Begin Source File

SOURCE=.\Shared\Win32\QWindowWin32OpenGL.cpp
# End Source File
# Begin Source File

SOURCE=.\StdAfx.cpp
# ADD CPP /Yc"stdafx.h"
# End Source File
# Begin Source File

SOURCE=.\Shared\Math\Vector2.cpp
# End Source File
# Begin Source File

SOURCE=.\Shared\Math\Vector3.cpp
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=.\Shared\TDA\BitSet.h
# End Source File
# Begin Source File

SOURCE=.\Graphics\jpeglib.h
# End Source File
# Begin Source File

SOURCE=.\Shared\Math\Matrix4.h
# End Source File
# Begin Source File

SOURCE=.\Scripting\parse.h
# End Source File
# Begin Source File

SOURCE=.\Graphics\Objects\QActor.h
# End Source File
# Begin Source File

SOURCE=.\Graphics\Managers\QActorManager.h
# End Source File
# Begin Source File

SOURCE=.\App\QAppCore.h
# End Source File
# Begin Source File

SOURCE=.\App\QAppWin32.h
# End Source File
# Begin Source File

SOURCE=.\Graphics\Objects\QCamera.h
# End Source File
# Begin Source File

SOURCE=.\Input\QDirectInput.h
# End Source File
# Begin Source File

SOURCE=.\QEngine.h
# End Source File
# Begin Source File

SOURCE=.\Graphics\Objects\QFont.h
# End Source File
# Begin Source File

SOURCE=.\Graphics\Objects\QFontDirectX.h
# End Source File
# Begin Source File

SOURCE=.\Graphics\Managers\QFontManager.h
# End Source File
# Begin Source File

SOURCE=.\Graphics\Objects\QFontOpenGL.h
# End Source File
# Begin Source File

SOURCE=.\Graphics\Models\QFrame.h
# End Source File
# Begin Source File

SOURCE=.\Shared\TDA\QHoleManager.h
# End Source File
# Begin Source File

SOURCE=.\Shared\TDA\QHoleNode.h
# End Source File
# Begin Source File

SOURCE=.\QIncludes.h
# End Source File
# Begin Source File

SOURCE=.\Input\QInputDirectX.h
# End Source File
# Begin Source File

SOURCE=.\Input\QInputManager.h
# End Source File
# Begin Source File

SOURCE=.\Input\QInputWin32.h
# End Source File
# Begin Source File

SOURCE=.\Shared\Objects\QInstance.h
# End Source File
# Begin Source File

SOURCE=.\Shared\Managers\QInstanceManager.h
# End Source File
# Begin Source File

SOURCE=.\Shared\Objects\QLog.h
# End Source File
# Begin Source File

SOURCE=.\Graphics\Models\QMesh.h
# End Source File
# Begin Source File

SOURCE=.\Shared\Win32\QMFCApp.h
# End Source File
# Begin Source File

SOURCE=.\Shared\Win32\QMFCDoc.h
# End Source File
# Begin Source File

SOURCE=.\Shared\Win32\QMFCView.h
# End Source File
# Begin Source File

SOURCE=.\Shared\Win32\QMFCViewDirectX.h
# End Source File
# Begin Source File

SOURCE=.\Shared\Win32\QMFCViewOpenGL.h
# End Source File
# Begin Source File

SOURCE=.\Graphics\Models\QModel.h
# End Source File
# Begin Source File

SOURCE=.\Graphics\Models\QModelKeyframed.h
# End Source File
# Begin Source File

SOURCE=.\Graphics\Models\QModelMD2.h
# End Source File
# Begin Source File

SOURCE=.\Graphics\Models\QModelMD3.h
# End Source File
# Begin Source File

SOURCE=.\Graphics\Models\QModelMS3D.h
# End Source File
# Begin Source File

SOURCE=.\Graphics\Models\QModelRAW.h
# End Source File
# Begin Source File

SOURCE=.\Graphics\Particles\QParticle.h
# End Source File
# Begin Source File

SOURCE=.\Graphics\Particles\QParticleSystem.h
# End Source File
# Begin Source File

SOURCE=.\Graphics\Managers\QParticleSystemManager.h
# End Source File
# Begin Source File

SOURCE=.\Graphics\Models\QPrimitive.h
# End Source File
# Begin Source File

SOURCE=.\Graphics\Renderer\QRenderer.h
# End Source File
# Begin Source File

SOURCE=.\Graphics\Renderer\QRendererDirectX.h
# End Source File
# Begin Source File

SOURCE=.\Graphics\Renderer\QRendererOpenGL.h
# End Source File
# Begin Source File

SOURCE=.\Graphics\Textures\QTexture.h
# End Source File
# Begin Source File

SOURCE=.\Graphics\Textures\QTextureDirectX.h
# End Source File
# Begin Source File

SOURCE=.\Graphics\Managers\QTextureManager.h
# End Source File
# Begin Source File

SOURCE=.\Graphics\Textures\QTextureOpenGL.h
# End Source File
# Begin Source File

SOURCE=.\Shared\Objects\QTimer.h
# End Source File
# Begin Source File

SOURCE=.\Shared\Managers\QTimerManager.h
# End Source File
# Begin Source File

SOURCE=.\Graphics\Objects\QTriangle.h
# End Source File
# Begin Source File

SOURCE=.\Graphics\Models\QTriangleList.h
# End Source File
# Begin Source File

SOURCE=.\Graphics\Models\QTriangleListFan.h
# End Source File
# Begin Source File

SOURCE=.\Graphics\Models\QTriangleListStrip.h
# End Source File
# Begin Source File

SOURCE=.\Graphics\Managers\QTriangleManager.h
# End Source File
# Begin Source File

SOURCE=.\Shared\Math\Quaternion.h
# End Source File
# Begin Source File

SOURCE=.\Graphics\Managers\QVertexManager.h
# End Source File
# Begin Source File

SOURCE=.\Shared\Win32\QWindowWin32.h
# End Source File
# Begin Source File

SOURCE=.\Shared\Win32\QWindowWin32DirectX.h
# End Source File
# Begin Source File

SOURCE=.\Shared\Win32\QWindowWin32OpenGL.h
# End Source File
# Begin Source File

SOURCE=.\StdAfx.h
# End Source File
# Begin Source File

SOURCE=.\Shared\Math\Vector2.h
# End Source File
# Begin Source File

SOURCE=.\Shared\Math\Vector3.h
# End Source File
# Begin Source File

SOURCE=.\VersionNo.h
# End Source File
# End Group
# Begin Source File

SOURCE=.\Readme.txt
# End Source File
# Begin Source File

SOURCE=.\Scripting\string.l

!IF  "$(CFG)" == "QEngine - Win32 Release"

!ELSEIF  "$(CFG)" == "QEngine - Win32 Debug"

# Begin Custom Build - Generando lexer... (flex -olex.cpp string.l)
InputPath=.\Scripting\string.l

"lex.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	e:\Programacion\C\Lib\Flex\MISC\MSVC\bin\Release\flex -olex.cpp .\Scripting\string.l

# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\Scripting\string.y
# End Source File
# End Target
# End Project
