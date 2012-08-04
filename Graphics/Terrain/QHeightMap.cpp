#include "stdafx.h"
#include "QHeightMap.h"



#define MESH_RESOLUTION 4.0f							// Pixels Per Vertex
#define MESH_HEIGHTSCALE 1.0f							// Mesh Height Scale
// VBO Extension Definitions, From glext.h
#define GL_ARRAY_BUFFER_ARB 0x8892
#define GL_STATIC_DRAW_ARB 0x88E4
typedef void (APIENTRY * PFNGLBINDBUFFERARBPROC) (GLenum target, GLuint buffer);
typedef void (APIENTRY * PFNGLDELETEBUFFERSARBPROC) (GLsizei n, const GLuint *buffers);
typedef void (APIENTRY * PFNGLGENBUFFERSARBPROC) (GLsizei n, GLuint *buffers);
typedef void (APIENTRY * PFNGLBUFFERDATAARBPROC) (GLenum target, int size, const GLvoid *data, GLenum usage);

// VBO Extension Function Pointers en rendererd opengl
//PFNGLGENBUFFERSARBPROC glGenBuffersARB = NULL;					// VBO Name Generation Procedure
//PFNGLBINDBUFFERARBPROC glBindBufferARB = NULL;					// VBO Bind Procedure
//PFNGLBUFFERDATAARBPROC glBufferDataARB = NULL;					// VBO Data Loading Procedure
//PFNGLDELETEBUFFERSARBPROC glDeleteBuffersARB = NULL;				// VBO Deletion Procedure

QHeightMap::QHeightMap(void)
{
}

QHeightMap::~QHeightMap(void)
{
}
