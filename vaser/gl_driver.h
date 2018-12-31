/* Copyright (c) 2006 dhpoware. All Rights Reserved.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
 * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
 * IN THE SOFTWARE.
 */

/* License Applicability. Except to the extent portions of this file are
 * made subject to an alternative license as permitted in the SGI Free
 * Software License B, Version 1.1 (the "License"), the contents of this
 * file are subject only to the provisions of the License. You may not use
 * this file except in compliance with the License. You may obtain a copy
 * of the License at Silicon Graphics, Inc., attn: Legal Services, 1600
 * Amphitheatre Parkway, Mountain View, CA 94043-1351, or at:
 *
 * http://oss.sgi.com/projects/FreeB
 *
 * Note that, as provided in the License, the Software is distributed on
 * an "AS IS" basis, with ALL EXPRESS AND IMPLIED WARRANTIES AND
 * CONDITIONS DISCLAIMED, INCLUDING, WITHOUT LIMITATION, ANY IMPLIED
 * WARRANTIES AND CONDITIONS OF MERCHANTABILITY, SATISFACTORY QUALITY,
 * FITNESS FOR A PARTICULAR PURPOSE, AND NON-INFRINGEMENT.
 *
 * Original Code. The Original Code is: OpenGL Sample Implementation,
 * Version 1.2.1, released January 26, 2000, developed by Silicon
 * Graphics, Inc. The Original Code is Copyright (c) 1991-2002 Silicon
 * Graphics, Inc. Copyright in any portions created by third parties is
 * as indicated elsewhere herein. All Rights Reserved.
 *
 * Additional Notice Provisions: This software was created using the
 * OpenGL(R) version 1.2.1 Sample Implementation published by SGI, but has
 * not been independently verified as being compliant with the OpenGL(R)
 * version 1.2.1 Specification.
 */

/* GLdriver Library.
 *
 * This loader module is a complete replacement for the gl.h and glu.h
 * headers shipped with recent versions of MS Visual Studio. Like the
 * MS versions, this loader module depends on basic Windows types declared
 * in windows.h. OpenGL 1.1 to 2.0 inclusive is supported by this module.
 * GLU 1.2 to 1.3 inclusive is supported by this module.
 *
 * To use the GLdriver library follow these steps:
 *
 * 1. Replace #include <GL/gl.h> and #include <GL/glu.h> with
 *      #include "gl_driver.h"
 *
 * 2. Create an instance of the GLdriver structure.
 *      GLdriver driver;
 *
 * 3. Load the OpenGL DLLs. Only OpenGL 1.1 is available at this stage.
 *      GLdriverLoad(&driver, "opengl32.dll", "glu32.dll');
 *
 * 4. Create and activate the OpenGL rendering context for the main window.
 *      ChoosePixelFormat();
 *      SetPixelFormat();
 *      wglCreateContext();
 *      wglMakeCurrent();
 *
 * 5. Initialize the GLdriver library. Loads OpenGL beyond 1.1.
 *      GLdriverInit(&driver);
 *
 * 6. OpenGL is now fully loaded.
 *
 * 7. At application shutdown unload the loaded OpenGL DLLs.
 *      GLdriverUnload(&driver);
 */

#if !defined(GL_DRIVER_H)
#define GL_DRIVER_H

#include <windows.h>
#include <tchar.h>
#include <stddef.h>

#if defined(__cplusplus)
extern "C" {
#endif

/*
 * OpenGL Basic Types.
 */

typedef double                            GLclampd;
typedef double                            GLdouble;
typedef float                             GLclampf;
typedef float                             GLfloat;
typedef int                               GLint;
typedef int                               GLsizei;
typedef short                             GLshort;
typedef signed char                       GLbyte;
typedef unsigned char                     GLboolean;
typedef unsigned char                     GLubyte;
typedef unsigned int                      GLbitfield;
typedef unsigned int                      GLenum;
typedef unsigned int                      GLuint;
typedef unsigned short                    GLushort;
typedef void                              GLvoid;

/*
 * WGL API.
 */

/* Non-WGL GDI Core API Functions. */
#undef  ChoosePixelFormat
#undef  DescribePixelFormat
#undef  GetPixelFormat
#undef  SetPixelFormat
#undef  SwapBuffers
#define ChoosePixelFormat           my_ChoosePixelFormat
#define DescribePixelFormat         my_DescribePixelFormat
#define GetPixelFormat              my_GetPixelFormat
#define SetPixelFormat              my_SetPixelFormat
#define SwapBuffers                 my_SwapBuffers

/* WGL Core API Functions. */
#undef  wglCopyContext
#undef  wglCreateContext
#undef  wglCreateLayerContext
#undef  wglDeleteContext
#undef  wglDescribeLayerPlane
#undef  wglGetCurrentContext
#undef  wglGetCurrentDC
#undef  wglGetLayerPaletteEntries
#undef  wglGetProcAddress
#undef  wglMakeCurrent
#undef  wglRealizeLayerPalette
#undef  wglSetLayerPaletteEntries
#undef  wglShareLists
#undef  wglSwapLayerBuffers
#undef  wglUseFontBitmapsA
#undef  wglUseFontBitmapsW
#undef  wglUseFontOutlinesA
#undef  wglUseFontOutlinesW
#define wglCopyContext              my_wglCopyContext
#define wglCreateContext            my_wglCreateContext
#define wglCreateLayerContext       my_wglCreateLayerContext
#define wglDeleteContext            my_wglDeleteContext
#define wglDescribeLayerPlane       my_wglDescribeLayerPlane
#define wglGetCurrentContext        my_wglGetCurrentContext
#define wglGetCurrentDC             my_wglGetCurrentDC
#define wglGetLayerPaletteEntries   my_wglGetLayerPaletteEntries
#define wglGetProcAddress           my_wglGetProcAddress
#define wglMakeCurrent              my_wglMakeCurrent
#define wglRealizeLayerPalette      my_wglRealizeLayerPalette
#define wglSetLayerPaletteEntries   my_wglSetLayerPaletteEntries
#define wglShareLists               my_wglShareLists
#define wglSwapLayerBuffers         my_wglSwapLayerBuffers
#define wglUseFontBitmapsA          my_wglUseFontBitmapsA
#define wglUseFontBitmapsW          my_wglUseFontBitmapsW
#define wglUseFontOutlinesA         my_wglUseFontOutlinesA
#define wglUseFontOutlinesW         my_wglUseFontOutlinesW

/* WGL Core API Symbols. */
#if defined(_UNICODE)
#undef  wglUseFontBitmaps
#undef  wglUseFontOutlines
#define wglUseFontBitmaps           wglUseFontBitmapsW
#define wglUseFontOutlines          wglUseFontOutlinesW
#else
#undef  wglUseFontBitmaps
#undef  wglUseFontOutlines
#define wglUseFontBitmaps           wglUseFontBitmapsA
#define wglUseFontOutlines          wglUseFontOutlinesA
#endif

/* Non-WGL GDI Core API Type Definitions. */
typedef int   (WINAPI * PFNCHOOSEPIXELFORMATPROC) (HDC, CONST PIXELFORMATDESCRIPTOR*);
typedef int   (WINAPI * PFNDESCRIBEPIXELFORMATPROC) (HDC, INT, UINT, PIXELFORMATDESCRIPTOR*);
typedef int   (WINAPI * PFNGETPIXELFORMATPROC) (HDC);
typedef BOOL  (WINAPI * PFNSETPIXELFORMATPROC) (HDC, INT, CONST PIXELFORMATDESCRIPTOR*);
typedef BOOL  (WINAPI * PFNSWAPBUFFERSPROC) (HDC);

/* WGL Core API Type Definitions. */
typedef BOOL  (WINAPI * PFNWGLCOPYCONTEXTPROC) (HGLRC, HGLRC, UINT);
typedef BOOL  (WINAPI * PFNWGLDELETECONTEXTPROC) (HGLRC);
typedef BOOL  (WINAPI * PFNWGLDESCRIBELAYERPLANEPROC) (HDC, int, int, UINT, LPLAYERPLANEDESCRIPTOR);
typedef BOOL  (WINAPI * PFNWGLMAKECURRENTPROC) (HDC, HGLRC);
typedef BOOL  (WINAPI * PFNWGLREALIZELAYERPALETTEPROC) (HDC, int, BOOL);
typedef BOOL  (WINAPI * PFNWGLSHARELISTSPROC) (HGLRC, HGLRC);
typedef BOOL  (WINAPI * PFNWGLSWAPLAYERBUFFERSPROC) (HDC, UINT);
typedef BOOL  (WINAPI * PFNWGLUSEFONTBITMAPSAPROC) (HDC, DWORD, DWORD, DWORD);
typedef BOOL  (WINAPI * PFNWGLUSEFONTBITMAPSWPROC) (HDC, DWORD, DWORD, DWORD);
typedef BOOL  (WINAPI * PFNWGLUSEFONTOUTLINESAPROC) (HDC, DWORD, DWORD, DWORD, FLOAT, FLOAT, int, LPGLYPHMETRICSFLOAT);
typedef BOOL  (WINAPI * PFNWGLUSEFONTOUTLINESWPROC) (HDC, DWORD, DWORD, DWORD, FLOAT, FLOAT, int, LPGLYPHMETRICSFLOAT);
typedef HDC   (WINAPI * PFNWGLGETCURRENTDCPROC) (VOID);
typedef HGLRC (WINAPI * PFNWGLCREATECONTEXTPROC) (HDC);
typedef HGLRC (WINAPI * PFNWGLCREATELAYERCONTEXTPROC) (HDC, int);
typedef HGLRC (WINAPI * PFNWGLGETCURRENTCONTEXTPROC) (VOID);
typedef PROC  (WINAPI * PFNWGLGETPROCADDRESSPROC) (LPCSTR);
typedef int   (WINAPI * PFNWGLGETLAYERPALETTEENTRIESPROC) (HDC, int, int, int, COLORREF *);
typedef int   (WINAPI * PFNWGLSETLAYERPALETTEENTRIESPROC) (HDC, int, int, int, CONST COLORREF *);

/* Non-WGL GDI Core API Functions. */
extern PFNCHOOSEPIXELFORMATPROC                my_ChoosePixelFormat;
extern PFNDESCRIBEPIXELFORMATPROC              my_DescribePixelFormat;
extern PFNGETPIXELFORMATPROC                   my_GetPixelFormat;
extern PFNSETPIXELFORMATPROC                   my_SetPixelFormat;
extern PFNSWAPBUFFERSPROC                      my_SwapBuffers;

/* WGL Core API Functions. */
extern PFNWGLCOPYCONTEXTPROC                   my_wglCopyContext;
extern PFNWGLCREATECONTEXTPROC                 my_wglCreateContext;
extern PFNWGLCREATELAYERCONTEXTPROC            my_wglCreateLayerContext;
extern PFNWGLDELETECONTEXTPROC                 my_wglDeleteContext;
extern PFNWGLDESCRIBELAYERPLANEPROC            my_wglDescribeLayerPlane;
extern PFNWGLGETCURRENTCONTEXTPROC             my_wglGetCurrentContext;
extern PFNWGLGETCURRENTDCPROC                  my_wglGetCurrentDC;
extern PFNWGLGETLAYERPALETTEENTRIESPROC        my_wglGetLayerPaletteEntries;
extern PFNWGLGETPROCADDRESSPROC                my_wglGetProcAddress;
extern PFNWGLMAKECURRENTPROC                   my_wglMakeCurrent;
extern PFNWGLREALIZELAYERPALETTEPROC           my_wglRealizeLayerPalette;
extern PFNWGLSETLAYERPALETTEENTRIESPROC        my_wglSetLayerPaletteEntries;
extern PFNWGLSHARELISTSPROC                    my_wglShareLists;
extern PFNWGLSWAPLAYERBUFFERSPROC              my_wglSwapLayerBuffers;
extern PFNWGLUSEFONTBITMAPSAPROC               my_wglUseFontBitmapsA;
extern PFNWGLUSEFONTBITMAPSWPROC               my_wglUseFontBitmapsW;
extern PFNWGLUSEFONTOUTLINESAPROC              my_wglUseFontOutlinesA;
extern PFNWGLUSEFONTOUTLINESWPROC              my_wglUseFontOutlinesW;

/*
 * OpenGL 1.1 API.
 */

#define GL_2D                             0x0600
#define GL_2_BYTES                        0x1407
#define GL_3D                             0x0601
#define GL_3D_COLOR                       0x0602
#define GL_3D_COLOR_TEXTURE               0x0603
#define GL_3_BYTES                        0x1408
#define GL_4D_COLOR_TEXTURE               0x0604
#define GL_4_BYTES                        0x1409
#define GL_ACCUM                          0x0100
#define GL_ACCUM_ALPHA_BITS               0x0D5B
#define GL_ACCUM_BLUE_BITS                0x0D5A
#define GL_ACCUM_BUFFER_BIT               0x00000200
#define GL_ACCUM_CLEAR_VALUE              0x0B80
#define GL_ACCUM_GREEN_BITS               0x0D59
#define GL_ACCUM_RED_BITS                 0x0D58
#define GL_ADD                            0x0104
#define GL_ALL_ATTRIB_BITS                0x000fffff
#define GL_ALPHA                          0x1906
#define GL_ALPHA12                        0x803D
#define GL_ALPHA16                        0x803E
#define GL_ALPHA4                         0x803B
#define GL_ALPHA8                         0x803C
#define GL_ALPHA_BIAS                     0x0D1D
#define GL_ALPHA_BITS                     0x0D55
#define GL_ALPHA_SCALE                    0x0D1C
#define GL_ALPHA_TEST                     0x0BC0
#define GL_ALPHA_TEST_FUNC                0x0BC1
#define GL_ALPHA_TEST_REF                 0x0BC2
#define GL_ALWAYS                         0x0207
#define GL_AMBIENT                        0x1200
#define GL_AMBIENT_AND_DIFFUSE            0x1602
#define GL_AND                            0x1501
#define GL_AND_INVERTED                   0x1504
#define GL_AND_REVERSE                    0x1502
#define GL_ATTRIB_STACK_DEPTH             0x0BB0
#define GL_AUTO_NORMAL                    0x0D80
#define GL_AUX0                           0x0409
#define GL_AUX1                           0x040A
#define GL_AUX2                           0x040B
#define GL_AUX3                           0x040C
#define GL_AUX_BUFFERS                    0x0C00
#define GL_BACK                           0x0405
#define GL_BACK_LEFT                      0x0402
#define GL_BACK_RIGHT                     0x0403
#define GL_BITMAP                         0x1A00
#define GL_BITMAP_TOKEN                   0x0704
#define GL_BLEND                          0x0BE2
#define GL_BLEND_DST                      0x0BE0
#define GL_BLEND_SRC                      0x0BE1
#define GL_BLUE                           0x1905
#define GL_BLUE_BIAS                      0x0D1B
#define GL_BLUE_BITS                      0x0D54
#define GL_BLUE_SCALE                     0x0D1A
#define GL_BYTE                           0x1400
#define GL_C3F_V3F                        0x2A24
#define GL_C4F_N3F_V3F                    0x2A26
#define GL_C4UB_V2F                       0x2A22
#define GL_C4UB_V3F                       0x2A23
#define GL_CCW                            0x0901
#define GL_CLAMP                          0x2900
#define GL_CLEAR                          0x1500
#define GL_CLIENT_ALL_ATTRIB_BITS         0xffffffff
#define GL_CLIENT_ATTRIB_STACK_DEPTH      0x0BB1
#define GL_CLIENT_PIXEL_STORE_BIT         0x00000001
#define GL_CLIENT_VERTEX_ARRAY_BIT        0x00000002
#define GL_CLIP_PLANE0                    0x3000
#define GL_CLIP_PLANE1                    0x3001
#define GL_CLIP_PLANE2                    0x3002
#define GL_CLIP_PLANE3                    0x3003
#define GL_CLIP_PLANE4                    0x3004
#define GL_CLIP_PLANE5                    0x3005
#define GL_COEFF                          0x0A00
#define GL_COLOR                          0x1800
#define GL_COLOR_ARRAY                    0x8076
#define GL_COLOR_ARRAY_POINTER            0x8090
#define GL_COLOR_ARRAY_SIZE               0x8081
#define GL_COLOR_ARRAY_STRIDE             0x8083
#define GL_COLOR_ARRAY_TYPE               0x8082
#define GL_COLOR_BUFFER_BIT               0x00004000
#define GL_COLOR_CLEAR_VALUE              0x0C22
#define GL_COLOR_INDEX                    0x1900
#define GL_COLOR_INDEXES                  0x1603
#define GL_COLOR_LOGIC_OP                 0x0BF2
#define GL_COLOR_MATERIAL                 0x0B57
#define GL_COLOR_MATERIAL_FACE            0x0B55
#define GL_COLOR_MATERIAL_PARAMETER       0x0B56
#define GL_COLOR_WRITEMASK                0x0C23
#define GL_COMPILE                        0x1300
#define GL_COMPILE_AND_EXECUTE            0x1301
#define GL_CONSTANT_ATTENUATION           0x1207
#define GL_COPY                           0x1503
#define GL_COPY_INVERTED                  0x150C
#define GL_COPY_PIXEL_TOKEN               0x0706
#define GL_CULL_FACE                      0x0B44
#define GL_CULL_FACE_MODE                 0x0B45
#define GL_CURRENT_BIT                    0x00000001
#define GL_CURRENT_COLOR                  0x0B00
#define GL_CURRENT_INDEX                  0x0B01
#define GL_CURRENT_NORMAL                 0x0B02
#define GL_CURRENT_RASTER_COLOR           0x0B04
#define GL_CURRENT_RASTER_DISTANCE        0x0B09
#define GL_CURRENT_RASTER_INDEX           0x0B05
#define GL_CURRENT_RASTER_POSITION        0x0B07
#define GL_CURRENT_RASTER_POSITION_VALID  0x0B08
#define GL_CURRENT_RASTER_TEXTURE_COORDS  0x0B06
#define GL_CURRENT_TEXTURE_COORDS         0x0B03
#define GL_CW                             0x0900
#define GL_DECAL                          0x2101
#define GL_DECR                           0x1E03
#define GL_DEPTH                          0x1801
#define GL_DEPTH_BIAS                     0x0D1F
#define GL_DEPTH_BITS                     0x0D56
#define GL_DEPTH_BUFFER_BIT               0x00000100
#define GL_DEPTH_CLEAR_VALUE              0x0B73
#define GL_DEPTH_COMPONENT                0x1902
#define GL_DEPTH_FUNC                     0x0B74
#define GL_DEPTH_RANGE                    0x0B70
#define GL_DEPTH_SCALE                    0x0D1E
#define GL_DEPTH_TEST                     0x0B71
#define GL_DEPTH_WRITEMASK                0x0B72
#define GL_DIFFUSE                        0x1201
#define GL_DITHER                         0x0BD0
#define GL_DOMAIN                         0x0A02
#define GL_DONT_CARE                      0x1100
#define GL_DOUBLE                         0x140A
#define GL_DOUBLEBUFFER                   0x0C32
#define GL_DRAW_BUFFER                    0x0C01
#define GL_DRAW_PIXEL_TOKEN               0x0705
#define GL_DST_ALPHA                      0x0304
#define GL_DST_COLOR                      0x0306
#define GL_EDGE_FLAG                      0x0B43
#define GL_EDGE_FLAG_ARRAY                0x8079
#define GL_EDGE_FLAG_ARRAY_POINTER        0x8093
#define GL_EDGE_FLAG_ARRAY_STRIDE         0x808C
#define GL_EMISSION                       0x1600
#define GL_ENABLE_BIT                     0x00002000
#define GL_EQUAL                          0x0202
#define GL_EQUIV                          0x1509
#define GL_EVAL_BIT                       0x00010000
#define GL_EXP                            0x0800
#define GL_EXP2                           0x0801
#define GL_EXTENSIONS                     0x1F03
#define GL_EYE_LINEAR                     0x2400
#define GL_EYE_PLANE                      0x2502
#define GL_FALSE                          0
#define GL_FASTEST                        0x1101
#define GL_FEEDBACK                       0x1C01
#define GL_FEEDBACK_BUFFER_POINTER        0x0DF0
#define GL_FEEDBACK_BUFFER_SIZE           0x0DF1
#define GL_FEEDBACK_BUFFER_TYPE           0x0DF2
#define GL_FILL                           0x1B02
#define GL_FLAT                           0x1D00
#define GL_FLOAT                          0x1406
#define GL_FOG                            0x0B60
#define GL_FOG_BIT                        0x00000080
#define GL_FOG_COLOR                      0x0B66
#define GL_FOG_DENSITY                    0x0B62
#define GL_FOG_END                        0x0B64
#define GL_FOG_HINT                       0x0C54
#define GL_FOG_INDEX                      0x0B61
#define GL_FOG_MODE                       0x0B65
#define GL_FOG_START                      0x0B63
#define GL_FRONT                          0x0404
#define GL_FRONT_AND_BACK                 0x0408
#define GL_FRONT_FACE                     0x0B46
#define GL_FRONT_LEFT                     0x0400
#define GL_FRONT_RIGHT                    0x0401
#define GL_GEQUAL                         0x0206
#define GL_GREATER                        0x0204
#define GL_GREEN                          0x1904
#define GL_GREEN_BIAS                     0x0D19
#define GL_GREEN_BITS                     0x0D53
#define GL_GREEN_SCALE                    0x0D18
#define GL_HINT_BIT                       0x00008000
#define GL_INCR                           0x1E02
#define GL_INDEX_ARRAY                    0x8077
#define GL_INDEX_ARRAY_POINTER            0x8091
#define GL_INDEX_ARRAY_STRIDE             0x8086
#define GL_INDEX_ARRAY_TYPE               0x8085
#define GL_INDEX_BITS                     0x0D51
#define GL_INDEX_CLEAR_VALUE              0x0C20
#define GL_INDEX_LOGIC_OP                 0x0BF1
#define GL_INDEX_MODE                     0x0C30
#define GL_INDEX_OFFSET                   0x0D13
#define GL_INDEX_SHIFT                    0x0D12
#define GL_INDEX_WRITEMASK                0x0C21
#define GL_INT                            0x1404
#define GL_INTENSITY                      0x8049
#define GL_INTENSITY12                    0x804C
#define GL_INTENSITY16                    0x804D
#define GL_INTENSITY4                     0x804A
#define GL_INTENSITY8                     0x804B
#define GL_INVALID_ENUM                   0x0500
#define GL_INVALID_OPERATION              0x0502
#define GL_INVALID_VALUE                  0x0501
#define GL_INVERT                         0x150A
#define GL_KEEP                           0x1E00
#define GL_LEFT                           0x0406
#define GL_LEQUAL                         0x0203
#define GL_LESS                           0x0201
#define GL_LIGHT0                         0x4000
#define GL_LIGHT1                         0x4001
#define GL_LIGHT2                         0x4002
#define GL_LIGHT3                         0x4003
#define GL_LIGHT4                         0x4004
#define GL_LIGHT5                         0x4005
#define GL_LIGHT6                         0x4006
#define GL_LIGHT7                         0x4007
#define GL_LIGHTING                       0x0B50
#define GL_LIGHTING_BIT                   0x00000040
#define GL_LIGHT_MODEL_AMBIENT            0x0B53
#define GL_LIGHT_MODEL_LOCAL_VIEWER       0x0B51
#define GL_LIGHT_MODEL_TWO_SIDE           0x0B52
#define GL_LINE                           0x1B01
#define GL_LINEAR                         0x2601
#define GL_LINEAR_ATTENUATION             0x1208
#define GL_LINEAR_MIPMAP_LINEAR           0x2703
#define GL_LINEAR_MIPMAP_NEAREST          0x2701
#define GL_LINES                          0x0001
#define GL_LINE_BIT                       0x00000004
#define GL_LINE_LOOP                      0x0002
#define GL_LINE_RESET_TOKEN               0x0707
#define GL_LINE_SMOOTH                    0x0B20
#define GL_LINE_SMOOTH_HINT               0x0C52
#define GL_LINE_STIPPLE                   0x0B24
#define GL_LINE_STIPPLE_PATTERN           0x0B25
#define GL_LINE_STIPPLE_REPEAT            0x0B26
#define GL_LINE_STRIP                     0x0003
#define GL_LINE_TOKEN                     0x0702
#define GL_LINE_WIDTH                     0x0B21
#define GL_LINE_WIDTH_GRANULARITY         0x0B23
#define GL_LINE_WIDTH_RANGE               0x0B22
#define GL_LIST_BASE                      0x0B32
#define GL_LIST_BIT                       0x00020000
#define GL_LIST_INDEX                     0x0B33
#define GL_LIST_MODE                      0x0B30
#define GL_LOAD                           0x0101
#define GL_LOGIC_OP_MODE                  0x0BF0
#define GL_LUMINANCE                      0x1909
#define GL_LUMINANCE12                    0x8041
#define GL_LUMINANCE12_ALPHA12            0x8047
#define GL_LUMINANCE12_ALPHA4             0x8046
#define GL_LUMINANCE16                    0x8042
#define GL_LUMINANCE16_ALPHA16            0x8048
#define GL_LUMINANCE4                     0x803F
#define GL_LUMINANCE4_ALPHA4              0x8043
#define GL_LUMINANCE6_ALPHA2              0x8044
#define GL_LUMINANCE8                     0x8040
#define GL_LUMINANCE8_ALPHA8              0x8045
#define GL_LUMINANCE_ALPHA                0x190A
#define GL_MAP1_COLOR_4                   0x0D90
#define GL_MAP1_GRID_DOMAIN               0x0DD0
#define GL_MAP1_GRID_SEGMENTS             0x0DD1
#define GL_MAP1_INDEX                     0x0D91
#define GL_MAP1_NORMAL                    0x0D92
#define GL_MAP1_TEXTURE_COORD_1           0x0D93
#define GL_MAP1_TEXTURE_COORD_2           0x0D94
#define GL_MAP1_TEXTURE_COORD_3           0x0D95
#define GL_MAP1_TEXTURE_COORD_4           0x0D96
#define GL_MAP1_VERTEX_3                  0x0D97
#define GL_MAP1_VERTEX_4                  0x0D98
#define GL_MAP2_COLOR_4                   0x0DB0
#define GL_MAP2_GRID_DOMAIN               0x0DD2
#define GL_MAP2_GRID_SEGMENTS             0x0DD3
#define GL_MAP2_INDEX                     0x0DB1
#define GL_MAP2_NORMAL                    0x0DB2
#define GL_MAP2_TEXTURE_COORD_1           0x0DB3
#define GL_MAP2_TEXTURE_COORD_2           0x0DB4
#define GL_MAP2_TEXTURE_COORD_3           0x0DB5
#define GL_MAP2_TEXTURE_COORD_4           0x0DB6
#define GL_MAP2_VERTEX_3                  0x0DB7
#define GL_MAP2_VERTEX_4                  0x0DB8
#define GL_MAP_COLOR                      0x0D10
#define GL_MAP_STENCIL                    0x0D11
#define GL_MATRIX_MODE                    0x0BA0
#define GL_MAX_ATTRIB_STACK_DEPTH         0x0D35
#define GL_MAX_CLIENT_ATTRIB_STACK_DEPTH  0x0D3B
#define GL_MAX_CLIP_PLANES                0x0D32
#define GL_MAX_EVAL_ORDER                 0x0D30
#define GL_MAX_LIGHTS                     0x0D31
#define GL_MAX_LIST_NESTING               0x0B31
#define GL_MAX_MODELVIEW_STACK_DEPTH      0x0D36
#define GL_MAX_NAME_STACK_DEPTH           0x0D37
#define GL_MAX_PIXEL_MAP_TABLE            0x0D34
#define GL_MAX_PROJECTION_STACK_DEPTH     0x0D38
#define GL_MAX_TEXTURE_SIZE               0x0D33
#define GL_MAX_TEXTURE_STACK_DEPTH        0x0D39
#define GL_MAX_VIEWPORT_DIMS              0x0D3A
#define GL_MODELVIEW                      0x1700
#define GL_MODELVIEW_MATRIX               0x0BA6
#define GL_MODELVIEW_STACK_DEPTH          0x0BA3
#define GL_MODULATE                       0x2100
#define GL_MULT                           0x0103
#define GL_N3F_V3F                        0x2A25
#define GL_NAME_STACK_DEPTH               0x0D70
#define GL_NAND                           0x150E
#define GL_NEAREST                        0x2600
#define GL_NEAREST_MIPMAP_LINEAR          0x2702
#define GL_NEAREST_MIPMAP_NEAREST         0x2700
#define GL_NEVER                          0x0200
#define GL_NICEST                         0x1102
#define GL_NONE                           0
#define GL_NOOP                           0x1505
#define GL_NOR                            0x1508
#define GL_NORMALIZE                      0x0BA1
#define GL_NORMAL_ARRAY                   0x8075
#define GL_NORMAL_ARRAY_POINTER           0x808F
#define GL_NORMAL_ARRAY_STRIDE            0x807F
#define GL_NORMAL_ARRAY_TYPE              0x807E
#define GL_NOTEQUAL                       0x0205
#define GL_NO_ERROR                       0
#define GL_OBJECT_LINEAR                  0x2401
#define GL_OBJECT_PLANE                   0x2501
#define GL_ONE                            1
#define GL_ONE_MINUS_DST_ALPHA            0x0305
#define GL_ONE_MINUS_DST_COLOR            0x0307
#define GL_ONE_MINUS_SRC_ALPHA            0x0303
#define GL_ONE_MINUS_SRC_COLOR            0x0301
#define GL_OR                             0x1507
#define GL_ORDER                          0x0A01
#define GL_OR_INVERTED                    0x150D
#define GL_OR_REVERSE                     0x150B
#define GL_OUT_OF_MEMORY                  0x0505
#define GL_PACK_ALIGNMENT                 0x0D05
#define GL_PACK_LSB_FIRST                 0x0D01
#define GL_PACK_ROW_LENGTH                0x0D02
#define GL_PACK_SKIP_PIXELS               0x0D04
#define GL_PACK_SKIP_ROWS                 0x0D03
#define GL_PACK_SWAP_BYTES                0x0D00
#define GL_PASS_THROUGH_TOKEN             0x0700
#define GL_PERSPECTIVE_CORRECTION_HINT    0x0C50
#define GL_PIXEL_MAP_A_TO_A               0x0C79
#define GL_PIXEL_MAP_A_TO_A_SIZE          0x0CB9
#define GL_PIXEL_MAP_B_TO_B               0x0C78
#define GL_PIXEL_MAP_B_TO_B_SIZE          0x0CB8
#define GL_PIXEL_MAP_G_TO_G               0x0C77
#define GL_PIXEL_MAP_G_TO_G_SIZE          0x0CB7
#define GL_PIXEL_MAP_I_TO_A               0x0C75
#define GL_PIXEL_MAP_I_TO_A_SIZE          0x0CB5
#define GL_PIXEL_MAP_I_TO_B               0x0C74
#define GL_PIXEL_MAP_I_TO_B_SIZE          0x0CB4
#define GL_PIXEL_MAP_I_TO_G               0x0C73
#define GL_PIXEL_MAP_I_TO_G_SIZE          0x0CB3
#define GL_PIXEL_MAP_I_TO_I               0x0C70
#define GL_PIXEL_MAP_I_TO_I_SIZE          0x0CB0
#define GL_PIXEL_MAP_I_TO_R               0x0C72
#define GL_PIXEL_MAP_I_TO_R_SIZE          0x0CB2
#define GL_PIXEL_MAP_R_TO_R               0x0C76
#define GL_PIXEL_MAP_R_TO_R_SIZE          0x0CB6
#define GL_PIXEL_MAP_S_TO_S               0x0C71
#define GL_PIXEL_MAP_S_TO_S_SIZE          0x0CB1
#define GL_PIXEL_MODE_BIT                 0x00000020
#define GL_POINT                          0x1B00
#define GL_POINTS                         0x0000
#define GL_POINT_BIT                      0x00000002
#define GL_POINT_SIZE                     0x0B11
#define GL_POINT_SIZE_GRANULARITY         0x0B13
#define GL_POINT_SIZE_RANGE               0x0B12
#define GL_POINT_SMOOTH                   0x0B10
#define GL_POINT_SMOOTH_HINT              0x0C51
#define GL_POINT_TOKEN                    0x0701
#define GL_POLYGON                        0x0009
#define GL_POLYGON_BIT                    0x00000008
#define GL_POLYGON_MODE                   0x0B40
#define GL_POLYGON_OFFSET_FACTOR          0x8038
#define GL_POLYGON_OFFSET_FILL            0x8037
#define GL_POLYGON_OFFSET_LINE            0x2A02
#define GL_POLYGON_OFFSET_POINT           0x2A01
#define GL_POLYGON_OFFSET_UNITS           0x2A00
#define GL_POLYGON_SMOOTH                 0x0B41
#define GL_POLYGON_SMOOTH_HINT            0x0C53
#define GL_POLYGON_STIPPLE                0x0B42
#define GL_POLYGON_STIPPLE_BIT            0x00000010
#define GL_POLYGON_TOKEN                  0x0703
#define GL_POSITION                       0x1203
#define GL_PROJECTION                     0x1701
#define GL_PROJECTION_MATRIX              0x0BA7
#define GL_PROJECTION_STACK_DEPTH         0x0BA4
#define GL_PROXY_TEXTURE_1D               0x8063
#define GL_PROXY_TEXTURE_2D               0x8064
#define GL_Q                              0x2003
#define GL_QUADRATIC_ATTENUATION          0x1209
#define GL_QUADS                          0x0007
#define GL_QUAD_STRIP                     0x0008
#define GL_R                              0x2002
#define GL_R3_G3_B2                       0x2A10
#define GL_READ_BUFFER                    0x0C02
#define GL_RED                            0x1903
#define GL_RED_BIAS                       0x0D15
#define GL_RED_BITS                       0x0D52
#define GL_RED_SCALE                      0x0D14
#define GL_RENDER                         0x1C00
#define GL_RENDERER                       0x1F01
#define GL_RENDER_MODE                    0x0C40
#define GL_REPEAT                         0x2901
#define GL_REPLACE                        0x1E01
#define GL_RETURN                         0x0102
#define GL_RGB                            0x1907
#define GL_RGB10                          0x8052
#define GL_RGB10_A2                       0x8059
#define GL_RGB12                          0x8053
#define GL_RGB16                          0x8054
#define GL_RGB4                           0x804F
#define GL_RGB5                           0x8050
#define GL_RGB5_A1                        0x8057
#define GL_RGB8                           0x8051
#define GL_RGBA                           0x1908
#define GL_RGBA12                         0x805A
#define GL_RGBA16                         0x805B
#define GL_RGBA2                          0x8055
#define GL_RGBA4                          0x8056
#define GL_RGBA8                          0x8058
#define GL_RGBA_MODE                      0x0C31
#define GL_RIGHT                          0x0407
#define GL_S                              0x2000
#define GL_SCISSOR_BIT                    0x00080000
#define GL_SCISSOR_BOX                    0x0C10
#define GL_SCISSOR_TEST                   0x0C11
#define GL_SELECT                         0x1C02
#define GL_SELECTION_BUFFER_POINTER       0x0DF3
#define GL_SELECTION_BUFFER_SIZE          0x0DF4
#define GL_SET                            0x150F
#define GL_SHADE_MODEL                    0x0B54
#define GL_SHININESS                      0x1601
#define GL_SHORT                          0x1402
#define GL_SMOOTH                         0x1D01
#define GL_SPECULAR                       0x1202
#define GL_SPHERE_MAP                     0x2402
#define GL_SPOT_CUTOFF                    0x1206
#define GL_SPOT_DIRECTION                 0x1204
#define GL_SPOT_EXPONENT                  0x1205
#define GL_SRC_ALPHA                      0x0302
#define GL_SRC_ALPHA_SATURATE             0x0308
#define GL_SRC_COLOR                      0x0300
#define GL_STACK_OVERFLOW                 0x0503
#define GL_STACK_UNDERFLOW                0x0504
#define GL_STENCIL                        0x1802
#define GL_STENCIL_BITS                   0x0D57
#define GL_STENCIL_BUFFER_BIT             0x00000400
#define GL_STENCIL_CLEAR_VALUE            0x0B91
#define GL_STENCIL_FAIL                   0x0B94
#define GL_STENCIL_FUNC                   0x0B92
#define GL_STENCIL_INDEX                  0x1901
#define GL_STENCIL_PASS_DEPTH_FAIL        0x0B95
#define GL_STENCIL_PASS_DEPTH_PASS        0x0B96
#define GL_STENCIL_REF                    0x0B97
#define GL_STENCIL_TEST                   0x0B90
#define GL_STENCIL_VALUE_MASK             0x0B93
#define GL_STENCIL_WRITEMASK              0x0B98
#define GL_STEREO                         0x0C33
#define GL_SUBPIXEL_BITS                  0x0D50
#define GL_T                              0x2001
#define GL_T2F_C3F_V3F                    0x2A2A
#define GL_T2F_C4F_N3F_V3F                0x2A2C
#define GL_T2F_C4UB_V3F                   0x2A29
#define GL_T2F_N3F_V3F                    0x2A2B
#define GL_T2F_V3F                        0x2A27
#define GL_T4F_C4F_N3F_V4F                0x2A2D
#define GL_T4F_V4F                        0x2A28
#define GL_TEXTURE                        0x1702
#define GL_TEXTURE_1D                     0x0DE0
#define GL_TEXTURE_2D                     0x0DE1
#define GL_TEXTURE_ALPHA_SIZE             0x805F
#define GL_TEXTURE_BINDING_1D             0x8068
#define GL_TEXTURE_BINDING_2D             0x8069
#define GL_TEXTURE_BIT                    0x00040000
#define GL_TEXTURE_BLUE_SIZE              0x805E
#define GL_TEXTURE_BORDER                 0x1005
#define GL_TEXTURE_BORDER_COLOR           0x1004
#define GL_TEXTURE_COORD_ARRAY            0x8078
#define GL_TEXTURE_COORD_ARRAY_POINTER    0x8092
#define GL_TEXTURE_COORD_ARRAY_SIZE       0x8088
#define GL_TEXTURE_COORD_ARRAY_STRIDE     0x808A
#define GL_TEXTURE_COORD_ARRAY_TYPE       0x8089
#define GL_TEXTURE_ENV                    0x2300
#define GL_TEXTURE_ENV_COLOR              0x2201
#define GL_TEXTURE_ENV_MODE               0x2200
#define GL_TEXTURE_GEN_MODE               0x2500
#define GL_TEXTURE_GEN_Q                  0x0C63
#define GL_TEXTURE_GEN_R                  0x0C62
#define GL_TEXTURE_GEN_S                  0x0C60
#define GL_TEXTURE_GEN_T                  0x0C61
#define GL_TEXTURE_GREEN_SIZE             0x805D
#define GL_TEXTURE_HEIGHT                 0x1001
#define GL_TEXTURE_INTENSITY_SIZE         0x8061
#define GL_TEXTURE_INTERNAL_FORMAT        0x1003
#define GL_TEXTURE_LUMINANCE_SIZE         0x8060
#define GL_TEXTURE_MAG_FILTER             0x2800
#define GL_TEXTURE_MATRIX                 0x0BA8
#define GL_TEXTURE_MIN_FILTER             0x2801
#define GL_TEXTURE_PRIORITY               0x8066
#define GL_TEXTURE_RED_SIZE               0x805C
#define GL_TEXTURE_RESIDENT               0x8067
#define GL_TEXTURE_STACK_DEPTH            0x0BA5
#define GL_TEXTURE_WIDTH                  0x1000
#define GL_TEXTURE_WRAP_S                 0x2802
#define GL_TEXTURE_WRAP_T                 0x2803
#define GL_TRANSFORM_BIT                  0x00001000
#define GL_TRIANGLES                      0x0004
#define GL_TRIANGLE_FAN                   0x0006
#define GL_TRIANGLE_STRIP                 0x0005
#define GL_TRUE                           1
#define GL_UNPACK_ALIGNMENT               0x0CF5
#define GL_UNPACK_LSB_FIRST               0x0CF1
#define GL_UNPACK_ROW_LENGTH              0x0CF2
#define GL_UNPACK_SKIP_PIXELS             0x0CF4
#define GL_UNPACK_SKIP_ROWS               0x0CF3
#define GL_UNPACK_SWAP_BYTES              0x0CF0
#define GL_UNSIGNED_BYTE                  0x1401
#define GL_UNSIGNED_INT                   0x1405
#define GL_UNSIGNED_SHORT                 0x1403
#define GL_V2F                            0x2A20
#define GL_V3F                            0x2A21
#define GL_VENDOR                         0x1F00
#define GL_VERSION                        0x1F02
#define GL_VERTEX_ARRAY                   0x8074
#define GL_VERTEX_ARRAY_POINTER           0x808E
#define GL_VERTEX_ARRAY_SIZE              0x807A
#define GL_VERTEX_ARRAY_STRIDE            0x807C
#define GL_VERTEX_ARRAY_TYPE              0x807B
#define GL_VIEWPORT                       0x0BA2
#define GL_VIEWPORT_BIT                   0x00000800
#define GL_XOR                            0x1506
#define GL_ZERO                           0
#define GL_ZOOM_X                         0x0D16
#define GL_ZOOM_Y                         0x0D17

typedef void (APIENTRY * PFNGLACCUMPROC) (GLenum op, GLfloat value);
typedef void (APIENTRY * PFNGLALPHAFUNCPROC) (GLenum func, GLclampf ref);
typedef GLboolean (APIENTRY * PFNGLARETEXTURESRESIDENTPROC) (GLsizei n, const GLuint *textures, GLboolean *residences);
typedef void (APIENTRY * PFNGLARRAYELEMENTPROC) (GLint i);
typedef void (APIENTRY * PFNGLBEGINPROC) (GLenum mode);
typedef void (APIENTRY * PFNGLBINDTEXTUREPROC) (GLenum target, GLuint texture);
typedef void (APIENTRY * PFNGLBITMAPPROC) (GLsizei width, GLsizei height, GLfloat xorig, GLfloat yorig, GLfloat xmove, GLfloat ymove, const GLubyte *bitmap);
typedef void (APIENTRY * PFNGLBLENDFUNCPROC) (GLenum sfactor, GLenum dfactor);
typedef void (APIENTRY * PFNGLCALLLISTPROC) (GLuint list);
typedef void (APIENTRY * PFNGLCALLLISTSPROC) (GLsizei n, GLenum type, const void *lists);
typedef void (APIENTRY * PFNGLCLEARPROC) (GLbitfield mask);
typedef void (APIENTRY * PFNGLCLEARACCUMPROC) (GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha);
typedef void (APIENTRY * PFNGLCLEARCOLORPROC) (GLclampf red, GLclampf green, GLclampf blue, GLclampf alpha);
typedef void (APIENTRY * PFNGLCLEARDEPTHPROC) (GLclampd depth);
typedef void (APIENTRY * PFNGLCLEARINDEXPROC) (GLfloat c);
typedef void (APIENTRY * PFNGLCLEARSTENCILPROC) (GLint s);
typedef void (APIENTRY * PFNGLCLIPPLANEPROC) (GLenum plane, const GLdouble *equation);
typedef void (APIENTRY * PFNGLCOLOR3BPROC) (GLbyte red, GLbyte green, GLbyte blue);
typedef void (APIENTRY * PFNGLCOLOR3BVPROC) (const GLbyte *v);
typedef void (APIENTRY * PFNGLCOLOR3DPROC) (GLdouble red, GLdouble green, GLdouble blue);
typedef void (APIENTRY * PFNGLCOLOR3DVPROC) (const GLdouble *v);
typedef void (APIENTRY * PFNGLCOLOR3FPROC) (GLfloat red, GLfloat green, GLfloat blue);
typedef void (APIENTRY * PFNGLCOLOR3FVPROC) (const GLfloat *v);
typedef void (APIENTRY * PFNGLCOLOR3IPROC) (GLint red, GLint green, GLint blue);
typedef void (APIENTRY * PFNGLCOLOR3IVPROC) (const GLint *v);
typedef void (APIENTRY * PFNGLCOLOR3SPROC) (GLshort red, GLshort green, GLshort blue);
typedef void (APIENTRY * PFNGLCOLOR3SVPROC) (const GLshort *v);
typedef void (APIENTRY * PFNGLCOLOR3UBPROC) (GLubyte red, GLubyte green, GLubyte blue);
typedef void (APIENTRY * PFNGLCOLOR3UBVPROC) (const GLubyte *v);
typedef void (APIENTRY * PFNGLCOLOR3UIPROC) (GLuint red, GLuint green, GLuint blue);
typedef void (APIENTRY * PFNGLCOLOR3UIVPROC) (const GLuint *v);
typedef void (APIENTRY * PFNGLCOLOR3USPROC) (GLushort red, GLushort green, GLushort blue);
typedef void (APIENTRY * PFNGLCOLOR3USVPROC) (const GLushort *v);
typedef void (APIENTRY * PFNGLCOLOR4BPROC) (GLbyte red, GLbyte green, GLbyte blue, GLbyte alpha);
typedef void (APIENTRY * PFNGLCOLOR4BVPROC) (const GLbyte *v);
typedef void (APIENTRY * PFNGLCOLOR4DPROC) (GLdouble red, GLdouble green, GLdouble blue, GLdouble alpha);
typedef void (APIENTRY * PFNGLCOLOR4DVPROC) (const GLdouble *v);
typedef void (APIENTRY * PFNGLCOLOR4FPROC) (GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha);
typedef void (APIENTRY * PFNGLCOLOR4FVPROC) (const GLfloat *v);
typedef void (APIENTRY * PFNGLCOLOR4IPROC) (GLint red, GLint green, GLint blue, GLint alpha);
typedef void (APIENTRY * PFNGLCOLOR4IVPROC) (const GLint *v);
typedef void (APIENTRY * PFNGLCOLOR4SPROC) (GLshort red, GLshort green, GLshort blue, GLshort alpha);
typedef void (APIENTRY * PFNGLCOLOR4SVPROC) (const GLshort *v);
typedef void (APIENTRY * PFNGLCOLOR4UBPROC) (GLubyte red, GLubyte green, GLubyte blue, GLubyte alpha);
typedef void (APIENTRY * PFNGLCOLOR4UBVPROC) (const GLubyte *v);
typedef void (APIENTRY * PFNGLCOLOR4UIPROC) (GLuint red, GLuint green, GLuint blue, GLuint alpha);
typedef void (APIENTRY * PFNGLCOLOR4UIVPROC) (const GLuint *v);
typedef void (APIENTRY * PFNGLCOLOR4USPROC) (GLushort red, GLushort green, GLushort blue, GLushort alpha);
typedef void (APIENTRY * PFNGLCOLOR4USVPROC) (const GLushort *v);
typedef void (APIENTRY * PFNGLCOLORMASKPROC) (GLboolean red, GLboolean green, GLboolean blue, GLboolean alpha);
typedef void (APIENTRY * PFNGLCOLORMATERIALPROC) (GLenum face, GLenum mode);
typedef void (APIENTRY * PFNGLCOLORPOINTERPROC) (GLint size, GLenum type, GLsizei stride, const void *pointer);
typedef void (APIENTRY * PFNGLCOPYPIXELSPROC) (GLint x, GLint y, GLsizei width, GLsizei height, GLenum type);
typedef void (APIENTRY * PFNGLCOPYTEXIMAGE1DPROC) (GLenum target, GLint level, GLenum internalFormat, GLint x, GLint y, GLsizei width, GLint border);
typedef void (APIENTRY * PFNGLCOPYTEXIMAGE2DPROC) (GLenum target, GLint level, GLenum internalFormat, GLint x, GLint y, GLsizei width, GLsizei height, GLint border);
typedef void (APIENTRY * PFNGLCOPYTEXSUBIMAGE1DPROC) (GLenum target, GLint level, GLint xoffset, GLint x, GLint y, GLsizei width);
typedef void (APIENTRY * PFNGLCOPYTEXSUBIMAGE2DPROC) (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height);
typedef void (APIENTRY * PFNGLCULLFACEPROC) (GLenum mode);
typedef void (APIENTRY * PFNGLDELETELISTSPROC) (GLuint list, GLsizei range);
typedef void (APIENTRY * PFNGLDELETETEXTURESPROC) (GLsizei n, const GLuint *textures);
typedef void (APIENTRY * PFNGLDEPTHFUNCPROC) (GLenum func);
typedef void (APIENTRY * PFNGLDEPTHMASKPROC) (GLboolean flag);
typedef void (APIENTRY * PFNGLDEPTHRANGEPROC) (GLclampd zNear, GLclampd zFar);
typedef void (APIENTRY * PFNGLDISABLEPROC) (GLenum cap);
typedef void (APIENTRY * PFNGLDISABLECLIENTSTATEPROC) (GLenum array);
typedef void (APIENTRY * PFNGLDRAWARRAYSPROC) (GLenum mode, GLint first, GLsizei count);
typedef void (APIENTRY * PFNGLDRAWBUFFERPROC) (GLenum mode);
typedef void (APIENTRY * PFNGLDRAWELEMENTSPROC) (GLenum mode, GLsizei count, GLenum type, const void *indices);
typedef void (APIENTRY * PFNGLDRAWPIXELSPROC) (GLsizei width, GLsizei height, GLenum format, GLenum type, const void *pixels);
typedef void (APIENTRY * PFNGLEDGEFLAGPROC) (GLboolean flag);
typedef void (APIENTRY * PFNGLEDGEFLAGPOINTERPROC) (GLsizei stride, const void *pointer);
typedef void (APIENTRY * PFNGLEDGEFLAGVPROC) (const GLboolean *flag);
typedef void (APIENTRY * PFNGLENABLEPROC) (GLenum cap);
typedef void (APIENTRY * PFNGLENABLECLIENTSTATEPROC) (GLenum array);
typedef void (APIENTRY * PFNGLENDPROC) (void);
typedef void (APIENTRY * PFNGLENDLISTPROC) (void);
typedef void (APIENTRY * PFNGLEVALCOORD1DPROC) (GLdouble u);
typedef void (APIENTRY * PFNGLEVALCOORD1DVPROC) (const GLdouble *u);
typedef void (APIENTRY * PFNGLEVALCOORD1FPROC) (GLfloat u);
typedef void (APIENTRY * PFNGLEVALCOORD1FVPROC) (const GLfloat *u);
typedef void (APIENTRY * PFNGLEVALCOORD2DPROC) (GLdouble u, GLdouble v);
typedef void (APIENTRY * PFNGLEVALCOORD2DVPROC) (const GLdouble *u);
typedef void (APIENTRY * PFNGLEVALCOORD2FPROC) (GLfloat u, GLfloat v);
typedef void (APIENTRY * PFNGLEVALCOORD2FVPROC) (const GLfloat *u);
typedef void (APIENTRY * PFNGLEVALMESH1PROC) (GLenum mode, GLint i1, GLint i2);
typedef void (APIENTRY * PFNGLEVALMESH2PROC) (GLenum mode, GLint i1, GLint i2, GLint j1, GLint j2);
typedef void (APIENTRY * PFNGLEVALPOINT1PROC) (GLint i);
typedef void (APIENTRY * PFNGLEVALPOINT2PROC) (GLint i, GLint j);
typedef void (APIENTRY * PFNGLFEEDBACKBUFFERPROC) (GLsizei size, GLenum type, GLfloat *buffer);
typedef void (APIENTRY * PFNGLFINISHPROC) (void);
typedef void (APIENTRY * PFNGLFLUSHPROC) (void);
typedef void (APIENTRY * PFNGLFOGFPROC) (GLenum pname, GLfloat param);
typedef void (APIENTRY * PFNGLFOGFVPROC) (GLenum pname, const GLfloat *params);
typedef void (APIENTRY * PFNGLFOGIPROC) (GLenum pname, GLint param);
typedef void (APIENTRY * PFNGLFOGIVPROC) (GLenum pname, const GLint *params);
typedef void (APIENTRY * PFNGLFRONTFACEPROC) (GLenum mode);
typedef void (APIENTRY * PFNGLFRUSTUMPROC) (GLdouble left, GLdouble right, GLdouble bottom, GLdouble top, GLdouble zNear, GLdouble zFar);
typedef GLuint (APIENTRY * PFNGLGENLISTSPROC) (GLsizei range);
typedef void (APIENTRY * PFNGLGENTEXTURESPROC) (GLsizei n, GLuint *textures);
typedef void (APIENTRY * PFNGLGETBOOLEANVPROC) (GLenum pname, GLboolean *params);
typedef void (APIENTRY * PFNGLGETCLIPPLANEPROC) (GLenum plane, GLdouble *equation);
typedef void (APIENTRY * PFNGLGETDOUBLEVPROC) (GLenum pname, GLdouble *params);
typedef GLenum (APIENTRY * PFNGLGETERRORPROC) (void);
typedef void (APIENTRY * PFNGLGETFLOATVPROC) (GLenum pname, GLfloat *params);
typedef void (APIENTRY * PFNGLGETINTEGERVPROC) (GLenum pname, GLint *params);
typedef void (APIENTRY * PFNGLGETLIGHTFVPROC) (GLenum light, GLenum pname, GLfloat *params);
typedef void (APIENTRY * PFNGLGETLIGHTIVPROC) (GLenum light, GLenum pname, GLint *params);
typedef void (APIENTRY * PFNGLGETMAPDVPROC) (GLenum target, GLenum query, GLdouble *v);
typedef void (APIENTRY * PFNGLGETMAPFVPROC) (GLenum target, GLenum query, GLfloat *v);
typedef void (APIENTRY * PFNGLGETMAPIVPROC) (GLenum target, GLenum query, GLint *v);
typedef void (APIENTRY * PFNGLGETMATERIALFVPROC) (GLenum face, GLenum pname, GLfloat *params);
typedef void (APIENTRY * PFNGLGETMATERIALIVPROC) (GLenum face, GLenum pname, GLint *params);
typedef void (APIENTRY * PFNGLGETPIXELMAPFVPROC) (GLenum map, GLfloat *values);
typedef void (APIENTRY * PFNGLGETPIXELMAPUIVPROC) (GLenum map, GLuint *values);
typedef void (APIENTRY * PFNGLGETPIXELMAPUSVPROC) (GLenum map, GLushort *values);
typedef void (APIENTRY * PFNGLGETPOINTERVPROC) (GLenum pname, void* *params);
typedef void (APIENTRY * PFNGLGETPOLYGONSTIPPLEPROC) (GLubyte *mask);
typedef const GLubyte * (APIENTRY * PFNGLGETSTRINGPROC) (GLenum name);
typedef void (APIENTRY * PFNGLGETTEXENVFVPROC) (GLenum target, GLenum pname, GLfloat *params);
typedef void (APIENTRY * PFNGLGETTEXENVIVPROC) (GLenum target, GLenum pname, GLint *params);
typedef void (APIENTRY * PFNGLGETTEXGENDVPROC) (GLenum coord, GLenum pname, GLdouble *params);
typedef void (APIENTRY * PFNGLGETTEXGENFVPROC) (GLenum coord, GLenum pname, GLfloat *params);
typedef void (APIENTRY * PFNGLGETTEXGENIVPROC) (GLenum coord, GLenum pname, GLint *params);
typedef void (APIENTRY * PFNGLGETTEXIMAGEPROC) (GLenum target, GLint level, GLenum format, GLenum type, void *pixels);
typedef void (APIENTRY * PFNGLGETTEXLEVELPARAMETERFVPROC) (GLenum target, GLint level, GLenum pname, GLfloat *params);
typedef void (APIENTRY * PFNGLGETTEXLEVELPARAMETERIVPROC) (GLenum target, GLint level, GLenum pname, GLint *params);
typedef void (APIENTRY * PFNGLGETTEXPARAMETERFVPROC) (GLenum target, GLenum pname, GLfloat *params);
typedef void (APIENTRY * PFNGLGETTEXPARAMETERIVPROC) (GLenum target, GLenum pname, GLint *params);
typedef void (APIENTRY * PFNGLHINTPROC) (GLenum target, GLenum mode);
typedef void (APIENTRY * PFNGLINDEXMASKPROC) (GLuint mask);
typedef void (APIENTRY * PFNGLINDEXPOINTERPROC) (GLenum type, GLsizei stride, const void *pointer);
typedef void (APIENTRY * PFNGLINDEXDPROC) (GLdouble c);
typedef void (APIENTRY * PFNGLINDEXDVPROC) (const GLdouble *c);
typedef void (APIENTRY * PFNGLINDEXFPROC) (GLfloat c);
typedef void (APIENTRY * PFNGLINDEXFVPROC) (const GLfloat *c);
typedef void (APIENTRY * PFNGLINDEXIPROC) (GLint c);
typedef void (APIENTRY * PFNGLINDEXIVPROC) (const GLint *c);
typedef void (APIENTRY * PFNGLINDEXSPROC) (GLshort c);
typedef void (APIENTRY * PFNGLINDEXSVPROC) (const GLshort *c);
typedef void (APIENTRY * PFNGLINDEXUBPROC) (GLubyte c);
typedef void (APIENTRY * PFNGLINDEXUBVPROC) (const GLubyte *c);
typedef void (APIENTRY * PFNGLINITNAMESPROC) (void);
typedef void (APIENTRY * PFNGLINTERLEAVEDARRAYSPROC) (GLenum format, GLsizei stride, const void *pointer);
typedef GLboolean (APIENTRY * PFNGLISENABLEDPROC) (GLenum cap);
typedef GLboolean (APIENTRY * PFNGLISLISTPROC) (GLuint list);
typedef GLboolean (APIENTRY * PFNGLISTEXTUREPROC) (GLuint texture);
typedef void (APIENTRY * PFNGLLIGHTMODELFPROC) (GLenum pname, GLfloat param);
typedef void (APIENTRY * PFNGLLIGHTMODELFVPROC) (GLenum pname, const GLfloat *params);
typedef void (APIENTRY * PFNGLLIGHTMODELIPROC) (GLenum pname, GLint param);
typedef void (APIENTRY * PFNGLLIGHTMODELIVPROC) (GLenum pname, const GLint *params);
typedef void (APIENTRY * PFNGLLIGHTFPROC) (GLenum light, GLenum pname, GLfloat param);
typedef void (APIENTRY * PFNGLLIGHTFVPROC) (GLenum light, GLenum pname, const GLfloat *params);
typedef void (APIENTRY * PFNGLLIGHTIPROC) (GLenum light, GLenum pname, GLint param);
typedef void (APIENTRY * PFNGLLIGHTIVPROC) (GLenum light, GLenum pname, const GLint *params);
typedef void (APIENTRY * PFNGLLINESTIPPLEPROC) (GLint factor, GLushort pattern);
typedef void (APIENTRY * PFNGLLINEWIDTHPROC) (GLfloat width);
typedef void (APIENTRY * PFNGLLISTBASEPROC) (GLuint base);
typedef void (APIENTRY * PFNGLLOADIDENTITYPROC) (void);
typedef void (APIENTRY * PFNGLLOADMATRIXDPROC) (const GLdouble *m);
typedef void (APIENTRY * PFNGLLOADMATRIXFPROC) (const GLfloat *m);
typedef void (APIENTRY * PFNGLLOADNAMEPROC) (GLuint name);
typedef void (APIENTRY * PFNGLLOGICOPPROC) (GLenum opcode);
typedef void (APIENTRY * PFNGLMAP1DPROC) (GLenum target, GLdouble u1, GLdouble u2, GLint stride, GLint order, const GLdouble *points);
typedef void (APIENTRY * PFNGLMAP1FPROC) (GLenum target, GLfloat u1, GLfloat u2, GLint stride, GLint order, const GLfloat *points);
typedef void (APIENTRY * PFNGLMAP2DPROC) (GLenum target, GLdouble u1, GLdouble u2, GLint ustride, GLint uorder, GLdouble v1, GLdouble v2, GLint vstride, GLint vorder, const GLdouble *points);
typedef void (APIENTRY * PFNGLMAP2FPROC) (GLenum target, GLfloat u1, GLfloat u2, GLint ustride, GLint uorder, GLfloat v1, GLfloat v2, GLint vstride, GLint vorder, const GLfloat *points);
typedef void (APIENTRY * PFNGLMAPGRID1DPROC) (GLint un, GLdouble u1, GLdouble u2);
typedef void (APIENTRY * PFNGLMAPGRID1FPROC) (GLint un, GLfloat u1, GLfloat u2);
typedef void (APIENTRY * PFNGLMAPGRID2DPROC) (GLint un, GLdouble u1, GLdouble u2, GLint vn, GLdouble v1, GLdouble v2);
typedef void (APIENTRY * PFNGLMAPGRID2FPROC) (GLint un, GLfloat u1, GLfloat u2, GLint vn, GLfloat v1, GLfloat v2);
typedef void (APIENTRY * PFNGLMATERIALFPROC) (GLenum face, GLenum pname, GLfloat param);
typedef void (APIENTRY * PFNGLMATERIALFVPROC) (GLenum face, GLenum pname, const GLfloat *params);
typedef void (APIENTRY * PFNGLMATERIALIPROC) (GLenum face, GLenum pname, GLint param);
typedef void (APIENTRY * PFNGLMATERIALIVPROC) (GLenum face, GLenum pname, const GLint *params);
typedef void (APIENTRY * PFNGLMATRIXMODEPROC) (GLenum mode);
typedef void (APIENTRY * PFNGLMULTMATRIXDPROC) (const GLdouble *m);
typedef void (APIENTRY * PFNGLMULTMATRIXFPROC) (const GLfloat *m);
typedef void (APIENTRY * PFNGLNEWLISTPROC) (GLuint list, GLenum mode);
typedef void (APIENTRY * PFNGLNORMAL3BPROC) (GLbyte nx, GLbyte ny, GLbyte nz);
typedef void (APIENTRY * PFNGLNORMAL3BVPROC) (const GLbyte *v);
typedef void (APIENTRY * PFNGLNORMAL3DPROC) (GLdouble nx, GLdouble ny, GLdouble nz);
typedef void (APIENTRY * PFNGLNORMAL3DVPROC) (const GLdouble *v);
typedef void (APIENTRY * PFNGLNORMAL3FPROC) (GLfloat nx, GLfloat ny, GLfloat nz);
typedef void (APIENTRY * PFNGLNORMAL3FVPROC) (const GLfloat *v);
typedef void (APIENTRY * PFNGLNORMAL3IPROC) (GLint nx, GLint ny, GLint nz);
typedef void (APIENTRY * PFNGLNORMAL3IVPROC) (const GLint *v);
typedef void (APIENTRY * PFNGLNORMAL3SPROC) (GLshort nx, GLshort ny, GLshort nz);
typedef void (APIENTRY * PFNGLNORMAL3SVPROC) (const GLshort *v);
typedef void (APIENTRY * PFNGLNORMALPOINTERPROC) (GLenum type, GLsizei stride, const void *pointer);
typedef void (APIENTRY * PFNGLORTHOPROC) (GLdouble left, GLdouble right, GLdouble bottom, GLdouble top, GLdouble zNear, GLdouble zFar);
typedef void (APIENTRY * PFNGLPASSTHROUGHPROC) (GLfloat token);
typedef void (APIENTRY * PFNGLPIXELMAPFVPROC) (GLenum map, GLsizei mapsize, const GLfloat *values);
typedef void (APIENTRY * PFNGLPIXELMAPUIVPROC) (GLenum map, GLsizei mapsize, const GLuint *values);
typedef void (APIENTRY * PFNGLPIXELMAPUSVPROC) (GLenum map, GLsizei mapsize, const GLushort *values);
typedef void (APIENTRY * PFNGLPIXELSTOREFPROC) (GLenum pname, GLfloat param);
typedef void (APIENTRY * PFNGLPIXELSTOREIPROC) (GLenum pname, GLint param);
typedef void (APIENTRY * PFNGLPIXELTRANSFERFPROC) (GLenum pname, GLfloat param);
typedef void (APIENTRY * PFNGLPIXELTRANSFERIPROC) (GLenum pname, GLint param);
typedef void (APIENTRY * PFNGLPIXELZOOMPROC) (GLfloat xfactor, GLfloat yfactor);
typedef void (APIENTRY * PFNGLPOINTSIZEPROC) (GLfloat size);
typedef void (APIENTRY * PFNGLPOLYGONMODEPROC) (GLenum face, GLenum mode);
typedef void (APIENTRY * PFNGLPOLYGONOFFSETPROC) (GLfloat factor, GLfloat units);
typedef void (APIENTRY * PFNGLPOLYGONSTIPPLEPROC) (const GLubyte *mask);
typedef void (APIENTRY * PFNGLPOPATTRIBPROC) (void);
typedef void (APIENTRY * PFNGLPOPCLIENTATTRIBPROC) (void);
typedef void (APIENTRY * PFNGLPOPMATRIXPROC) (void);
typedef void (APIENTRY * PFNGLPOPNAMEPROC) (void);
typedef void (APIENTRY * PFNGLPRIORITIZETEXTURESPROC) (GLsizei n, const GLuint *textures, const GLclampf *priorities);
typedef void (APIENTRY * PFNGLPUSHATTRIBPROC) (GLbitfield mask);
typedef void (APIENTRY * PFNGLPUSHCLIENTATTRIBPROC) (GLbitfield mask);
typedef void (APIENTRY * PFNGLPUSHMATRIXPROC) (void);
typedef void (APIENTRY * PFNGLPUSHNAMEPROC) (GLuint name);
typedef void (APIENTRY * PFNGLRASTERPOS2DPROC) (GLdouble x, GLdouble y);
typedef void (APIENTRY * PFNGLRASTERPOS2DVPROC) (const GLdouble *v);
typedef void (APIENTRY * PFNGLRASTERPOS2FPROC) (GLfloat x, GLfloat y);
typedef void (APIENTRY * PFNGLRASTERPOS2FVPROC) (const GLfloat *v);
typedef void (APIENTRY * PFNGLRASTERPOS2IPROC) (GLint x, GLint y);
typedef void (APIENTRY * PFNGLRASTERPOS2IVPROC) (const GLint *v);
typedef void (APIENTRY * PFNGLRASTERPOS2SPROC) (GLshort x, GLshort y);
typedef void (APIENTRY * PFNGLRASTERPOS2SVPROC) (const GLshort *v);
typedef void (APIENTRY * PFNGLRASTERPOS3DPROC) (GLdouble x, GLdouble y, GLdouble z);
typedef void (APIENTRY * PFNGLRASTERPOS3DVPROC) (const GLdouble *v);
typedef void (APIENTRY * PFNGLRASTERPOS3FPROC) (GLfloat x, GLfloat y, GLfloat z);
typedef void (APIENTRY * PFNGLRASTERPOS3FVPROC) (const GLfloat *v);
typedef void (APIENTRY * PFNGLRASTERPOS3IPROC) (GLint x, GLint y, GLint z);
typedef void (APIENTRY * PFNGLRASTERPOS3IVPROC) (const GLint *v);
typedef void (APIENTRY * PFNGLRASTERPOS3SPROC) (GLshort x, GLshort y, GLshort z);
typedef void (APIENTRY * PFNGLRASTERPOS3SVPROC) (const GLshort *v);
typedef void (APIENTRY * PFNGLRASTERPOS4DPROC) (GLdouble x, GLdouble y, GLdouble z, GLdouble w);
typedef void (APIENTRY * PFNGLRASTERPOS4DVPROC) (const GLdouble *v);
typedef void (APIENTRY * PFNGLRASTERPOS4FPROC) (GLfloat x, GLfloat y, GLfloat z, GLfloat w);
typedef void (APIENTRY * PFNGLRASTERPOS4FVPROC) (const GLfloat *v);
typedef void (APIENTRY * PFNGLRASTERPOS4IPROC) (GLint x, GLint y, GLint z, GLint w);
typedef void (APIENTRY * PFNGLRASTERPOS4IVPROC) (const GLint *v);
typedef void (APIENTRY * PFNGLRASTERPOS4SPROC) (GLshort x, GLshort y, GLshort z, GLshort w);
typedef void (APIENTRY * PFNGLRASTERPOS4SVPROC) (const GLshort *v);
typedef void (APIENTRY * PFNGLREADBUFFERPROC) (GLenum mode);
typedef void (APIENTRY * PFNGLREADPIXELSPROC) (GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, void *pixels);
typedef void (APIENTRY * PFNGLRECTDPROC) (GLdouble x1, GLdouble y1, GLdouble x2, GLdouble y2);
typedef void (APIENTRY * PFNGLRECTDVPROC) (const GLdouble *v1, const GLdouble *v2);
typedef void (APIENTRY * PFNGLRECTFPROC) (GLfloat x1, GLfloat y1, GLfloat x2, GLfloat y2);
typedef void (APIENTRY * PFNGLRECTFVPROC) (const GLfloat *v1, const GLfloat *v2);
typedef void (APIENTRY * PFNGLRECTIPROC) (GLint x1, GLint y1, GLint x2, GLint y2);
typedef void (APIENTRY * PFNGLRECTIVPROC) (const GLint *v1, const GLint *v2);
typedef void (APIENTRY * PFNGLRECTSPROC) (GLshort x1, GLshort y1, GLshort x2, GLshort y2);
typedef void (APIENTRY * PFNGLRECTSVPROC) (const GLshort *v1, const GLshort *v2);
typedef GLint (APIENTRY * PFNGLRENDERMODEPROC) (GLenum mode);
typedef void (APIENTRY * PFNGLROTATEDPROC) (GLdouble angle, GLdouble x, GLdouble y, GLdouble z);
typedef void (APIENTRY * PFNGLROTATEFPROC) (GLfloat angle, GLfloat x, GLfloat y, GLfloat z);
typedef void (APIENTRY * PFNGLSCALEDPROC) (GLdouble x, GLdouble y, GLdouble z);
typedef void (APIENTRY * PFNGLSCALEFPROC) (GLfloat x, GLfloat y, GLfloat z);
typedef void (APIENTRY * PFNGLSCISSORPROC) (GLint x, GLint y, GLsizei width, GLsizei height);
typedef void (APIENTRY * PFNGLSELECTBUFFERPROC) (GLsizei size, GLuint *buffer);
typedef void (APIENTRY * PFNGLSHADEMODELPROC) (GLenum mode);
typedef void (APIENTRY * PFNGLSTENCILFUNCPROC) (GLenum func, GLint ref, GLuint mask);
typedef void (APIENTRY * PFNGLSTENCILMASKPROC) (GLuint mask);
typedef void (APIENTRY * PFNGLSTENCILOPPROC) (GLenum fail, GLenum zfail, GLenum zpass);
typedef void (APIENTRY * PFNGLTEXCOORD1DPROC) (GLdouble s);
typedef void (APIENTRY * PFNGLTEXCOORD1DVPROC) (const GLdouble *v);
typedef void (APIENTRY * PFNGLTEXCOORD1FPROC) (GLfloat s);
typedef void (APIENTRY * PFNGLTEXCOORD1FVPROC) (const GLfloat *v);
typedef void (APIENTRY * PFNGLTEXCOORD1IPROC) (GLint s);
typedef void (APIENTRY * PFNGLTEXCOORD1IVPROC) (const GLint *v);
typedef void (APIENTRY * PFNGLTEXCOORD1SPROC) (GLshort s);
typedef void (APIENTRY * PFNGLTEXCOORD1SVPROC) (const GLshort *v);
typedef void (APIENTRY * PFNGLTEXCOORD2DPROC) (GLdouble s, GLdouble t);
typedef void (APIENTRY * PFNGLTEXCOORD2DVPROC) (const GLdouble *v);
typedef void (APIENTRY * PFNGLTEXCOORD2FPROC) (GLfloat s, GLfloat t);
typedef void (APIENTRY * PFNGLTEXCOORD2FVPROC) (const GLfloat *v);
typedef void (APIENTRY * PFNGLTEXCOORD2IPROC) (GLint s, GLint t);
typedef void (APIENTRY * PFNGLTEXCOORD2IVPROC) (const GLint *v);
typedef void (APIENTRY * PFNGLTEXCOORD2SPROC) (GLshort s, GLshort t);
typedef void (APIENTRY * PFNGLTEXCOORD2SVPROC) (const GLshort *v);
typedef void (APIENTRY * PFNGLTEXCOORD3DPROC) (GLdouble s, GLdouble t, GLdouble r);
typedef void (APIENTRY * PFNGLTEXCOORD3DVPROC) (const GLdouble *v);
typedef void (APIENTRY * PFNGLTEXCOORD3FPROC) (GLfloat s, GLfloat t, GLfloat r);
typedef void (APIENTRY * PFNGLTEXCOORD3FVPROC) (const GLfloat *v);
typedef void (APIENTRY * PFNGLTEXCOORD3IPROC) (GLint s, GLint t, GLint r);
typedef void (APIENTRY * PFNGLTEXCOORD3IVPROC) (const GLint *v);
typedef void (APIENTRY * PFNGLTEXCOORD3SPROC) (GLshort s, GLshort t, GLshort r);
typedef void (APIENTRY * PFNGLTEXCOORD3SVPROC) (const GLshort *v);
typedef void (APIENTRY * PFNGLTEXCOORD4DPROC) (GLdouble s, GLdouble t, GLdouble r, GLdouble q);
typedef void (APIENTRY * PFNGLTEXCOORD4DVPROC) (const GLdouble *v);
typedef void (APIENTRY * PFNGLTEXCOORD4FPROC) (GLfloat s, GLfloat t, GLfloat r, GLfloat q);
typedef void (APIENTRY * PFNGLTEXCOORD4FVPROC) (const GLfloat *v);
typedef void (APIENTRY * PFNGLTEXCOORD4IPROC) (GLint s, GLint t, GLint r, GLint q);
typedef void (APIENTRY * PFNGLTEXCOORD4IVPROC) (const GLint *v);
typedef void (APIENTRY * PFNGLTEXCOORD4SPROC) (GLshort s, GLshort t, GLshort r, GLshort q);
typedef void (APIENTRY * PFNGLTEXCOORD4SVPROC) (const GLshort *v);
typedef void (APIENTRY * PFNGLTEXCOORDPOINTERPROC) (GLint size, GLenum type, GLsizei stride, const void *pointer);
typedef void (APIENTRY * PFNGLTEXENVFPROC) (GLenum target, GLenum pname, GLfloat param);
typedef void (APIENTRY * PFNGLTEXENVFVPROC) (GLenum target, GLenum pname, const GLfloat *params);
typedef void (APIENTRY * PFNGLTEXENVIPROC) (GLenum target, GLenum pname, GLint param);
typedef void (APIENTRY * PFNGLTEXENVIVPROC) (GLenum target, GLenum pname, const GLint *params);
typedef void (APIENTRY * PFNGLTEXGENDPROC) (GLenum coord, GLenum pname, GLdouble param);
typedef void (APIENTRY * PFNGLTEXGENDVPROC) (GLenum coord, GLenum pname, const GLdouble *params);
typedef void (APIENTRY * PFNGLTEXGENFPROC) (GLenum coord, GLenum pname, GLfloat param);
typedef void (APIENTRY * PFNGLTEXGENFVPROC) (GLenum coord, GLenum pname, const GLfloat *params);
typedef void (APIENTRY * PFNGLTEXGENIPROC) (GLenum coord, GLenum pname, GLint param);
typedef void (APIENTRY * PFNGLTEXGENIVPROC) (GLenum coord, GLenum pname, const GLint *params);
typedef void (APIENTRY * PFNGLTEXIMAGE1DPROC) (GLenum target, GLint level, GLint internalformat, GLsizei width, GLint border, GLenum format, GLenum type, const void *pixels);
typedef void (APIENTRY * PFNGLTEXIMAGE2DPROC) (GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, const void *pixels);
typedef void (APIENTRY * PFNGLTEXPARAMETERFPROC) (GLenum target, GLenum pname, GLfloat param);
typedef void (APIENTRY * PFNGLTEXPARAMETERFVPROC) (GLenum target, GLenum pname, const GLfloat *params);
typedef void (APIENTRY * PFNGLTEXPARAMETERIPROC) (GLenum target, GLenum pname, GLint param);
typedef void (APIENTRY * PFNGLTEXPARAMETERIVPROC) (GLenum target, GLenum pname, const GLint *params);
typedef void (APIENTRY * PFNGLTEXSUBIMAGE1DPROC) (GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLenum type, const void *pixels);
typedef void (APIENTRY * PFNGLTEXSUBIMAGE2DPROC) (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const void *pixels);
typedef void (APIENTRY * PFNGLTRANSLATEDPROC) (GLdouble x, GLdouble y, GLdouble z);
typedef void (APIENTRY * PFNGLTRANSLATEFPROC) (GLfloat x, GLfloat y, GLfloat z);
typedef void (APIENTRY * PFNGLVERTEX2DPROC) (GLdouble x, GLdouble y);
typedef void (APIENTRY * PFNGLVERTEX2DVPROC) (const GLdouble *v);
typedef void (APIENTRY * PFNGLVERTEX2FPROC) (GLfloat x, GLfloat y);
typedef void (APIENTRY * PFNGLVERTEX2FVPROC) (const GLfloat *v);
typedef void (APIENTRY * PFNGLVERTEX2IPROC) (GLint x, GLint y);
typedef void (APIENTRY * PFNGLVERTEX2IVPROC) (const GLint *v);
typedef void (APIENTRY * PFNGLVERTEX2SPROC) (GLshort x, GLshort y);
typedef void (APIENTRY * PFNGLVERTEX2SVPROC) (const GLshort *v);
typedef void (APIENTRY * PFNGLVERTEX3DPROC) (GLdouble x, GLdouble y, GLdouble z);
typedef void (APIENTRY * PFNGLVERTEX3DVPROC) (const GLdouble *v);
typedef void (APIENTRY * PFNGLVERTEX3FPROC) (GLfloat x, GLfloat y, GLfloat z);
typedef void (APIENTRY * PFNGLVERTEX3FVPROC) (const GLfloat *v);
typedef void (APIENTRY * PFNGLVERTEX3IPROC) (GLint x, GLint y, GLint z);
typedef void (APIENTRY * PFNGLVERTEX3IVPROC) (const GLint *v);
typedef void (APIENTRY * PFNGLVERTEX3SPROC) (GLshort x, GLshort y, GLshort z);
typedef void (APIENTRY * PFNGLVERTEX3SVPROC) (const GLshort *v);
typedef void (APIENTRY * PFNGLVERTEX4DPROC) (GLdouble x, GLdouble y, GLdouble z, GLdouble w);
typedef void (APIENTRY * PFNGLVERTEX4DVPROC) (const GLdouble *v);
typedef void (APIENTRY * PFNGLVERTEX4FPROC) (GLfloat x, GLfloat y, GLfloat z, GLfloat w);
typedef void (APIENTRY * PFNGLVERTEX4FVPROC) (const GLfloat *v);
typedef void (APIENTRY * PFNGLVERTEX4IPROC) (GLint x, GLint y, GLint z, GLint w);
typedef void (APIENTRY * PFNGLVERTEX4IVPROC) (const GLint *v);
typedef void (APIENTRY * PFNGLVERTEX4SPROC) (GLshort x, GLshort y, GLshort z, GLshort w);
typedef void (APIENTRY * PFNGLVERTEX4SVPROC) (const GLshort *v);
typedef void (APIENTRY * PFNGLVERTEXPOINTERPROC) (GLint size, GLenum type, GLsizei stride, const void *pointer);
typedef void (APIENTRY * PFNGLVIEWPORTPROC) (GLint x, GLint y, GLsizei width, GLsizei height);

extern PFNGLACCUMPROC                          glAccum;
extern PFNGLALPHAFUNCPROC                      glAlphaFunc;
extern PFNGLARETEXTURESRESIDENTPROC            glAreTexturesResident;
extern PFNGLARRAYELEMENTPROC                   glArrayElement;
extern PFNGLBEGINPROC                          glBegin;
extern PFNGLBINDTEXTUREPROC                    glBindTexture;
extern PFNGLBITMAPPROC                         glBitmap;
extern PFNGLBLENDFUNCPROC                      glBlendFunc;
extern PFNGLCALLLISTPROC                       glCallList;
extern PFNGLCALLLISTSPROC                      glCallLists;
extern PFNGLCLEARPROC                          glClear;
extern PFNGLCLEARACCUMPROC                     glClearAccum;
extern PFNGLCLEARCOLORPROC                     glClearColor;
extern PFNGLCLEARDEPTHPROC                     glClearDepth;
extern PFNGLCLEARINDEXPROC                     glClearIndex;
extern PFNGLCLEARSTENCILPROC                   glClearStencil;
extern PFNGLCLIPPLANEPROC                      glClipPlane;
extern PFNGLCOLOR3BPROC                        glColor3b;
extern PFNGLCOLOR3BVPROC                       glColor3bv;
extern PFNGLCOLOR3DPROC                        glColor3d;
extern PFNGLCOLOR3DVPROC                       glColor3dv;
extern PFNGLCOLOR3FPROC                        glColor3f;
extern PFNGLCOLOR3FVPROC                       glColor3fv;
extern PFNGLCOLOR3IPROC                        glColor3i;
extern PFNGLCOLOR3IVPROC                       glColor3iv;
extern PFNGLCOLOR3SPROC                        glColor3s;
extern PFNGLCOLOR3SVPROC                       glColor3sv;
extern PFNGLCOLOR3UBPROC                       glColor3ub;
extern PFNGLCOLOR3UBVPROC                      glColor3ubv;
extern PFNGLCOLOR3UIPROC                       glColor3ui;
extern PFNGLCOLOR3UIVPROC                      glColor3uiv;
extern PFNGLCOLOR3USPROC                       glColor3us;
extern PFNGLCOLOR3USVPROC                      glColor3usv;
extern PFNGLCOLOR4BPROC                        glColor4b;
extern PFNGLCOLOR4BVPROC                       glColor4bv;
extern PFNGLCOLOR4DPROC                        glColor4d;
extern PFNGLCOLOR4DVPROC                       glColor4dv;
extern PFNGLCOLOR4FPROC                        glColor4f;
extern PFNGLCOLOR4FVPROC                       glColor4fv;
extern PFNGLCOLOR4IPROC                        glColor4i;
extern PFNGLCOLOR4IVPROC                       glColor4iv;
extern PFNGLCOLOR4SPROC                        glColor4s;
extern PFNGLCOLOR4SVPROC                       glColor4sv;
extern PFNGLCOLOR4UBPROC                       glColor4ub;
extern PFNGLCOLOR4UBVPROC                      glColor4ubv;
extern PFNGLCOLOR4UIPROC                       glColor4ui;
extern PFNGLCOLOR4UIVPROC                      glColor4uiv;
extern PFNGLCOLOR4USPROC                       glColor4us;
extern PFNGLCOLOR4USVPROC                      glColor4usv;
extern PFNGLCOLORMASKPROC                      glColorMask;
extern PFNGLCOLORMATERIALPROC                  glColorMaterial;
extern PFNGLCOLORPOINTERPROC                   glColorPointer;
extern PFNGLCOPYPIXELSPROC                     glCopyPixels;
extern PFNGLCOPYTEXIMAGE1DPROC                 glCopyTexImage1D;
extern PFNGLCOPYTEXIMAGE2DPROC                 glCopyTexImage2D;
extern PFNGLCOPYTEXSUBIMAGE1DPROC              glCopyTexSubImage1D;
extern PFNGLCOPYTEXSUBIMAGE2DPROC              glCopyTexSubImage2D;
extern PFNGLCULLFACEPROC                       glCullFace;
extern PFNGLDELETELISTSPROC                    glDeleteLists;
extern PFNGLDELETETEXTURESPROC                 glDeleteTextures;
extern PFNGLDEPTHFUNCPROC                      glDepthFunc;
extern PFNGLDEPTHMASKPROC                      glDepthMask;
extern PFNGLDEPTHRANGEPROC                     glDepthRange;
extern PFNGLDISABLEPROC                        glDisable;
extern PFNGLDISABLECLIENTSTATEPROC             glDisableClientState;
extern PFNGLDRAWARRAYSPROC                     glDrawArrays;
extern PFNGLDRAWBUFFERPROC                     glDrawBuffer;
extern PFNGLDRAWELEMENTSPROC                   glDrawElements;
extern PFNGLDRAWPIXELSPROC                     glDrawPixels;
extern PFNGLEDGEFLAGPROC                       glEdgeFlag;
extern PFNGLEDGEFLAGPOINTERPROC                glEdgeFlagPointer;
extern PFNGLEDGEFLAGVPROC                      glEdgeFlagv;
extern PFNGLENABLEPROC                         glEnable;
extern PFNGLENABLECLIENTSTATEPROC              glEnableClientState;
extern PFNGLENDPROC                            glEnd;
extern PFNGLENDLISTPROC                        glEndList;
extern PFNGLEVALCOORD1DPROC                    glEvalCoord1d;
extern PFNGLEVALCOORD1DVPROC                   glEvalCoord1dv;
extern PFNGLEVALCOORD1FPROC                    glEvalCoord1f;
extern PFNGLEVALCOORD1FVPROC                   glEvalCoord1fv;
extern PFNGLEVALCOORD2DPROC                    glEvalCoord2d;
extern PFNGLEVALCOORD2DVPROC                   glEvalCoord2dv;
extern PFNGLEVALCOORD2FPROC                    glEvalCoord2f;
extern PFNGLEVALCOORD2FVPROC                   glEvalCoord2fv;
extern PFNGLEVALMESH1PROC                      glEvalMesh1;
extern PFNGLEVALMESH2PROC                      glEvalMesh2;
extern PFNGLEVALPOINT1PROC                     glEvalPoint1;
extern PFNGLEVALPOINT2PROC                     glEvalPoint2;
extern PFNGLFEEDBACKBUFFERPROC                 glFeedbackBuffer;
extern PFNGLFINISHPROC                         glFinish;
extern PFNGLFLUSHPROC                          glFlush;
extern PFNGLFOGFPROC                           glFogf;
extern PFNGLFOGFVPROC                          glFogfv;
extern PFNGLFOGIPROC                           glFogi;
extern PFNGLFOGIVPROC                          glFogiv;
extern PFNGLFRONTFACEPROC                      glFrontFace;
extern PFNGLFRUSTUMPROC                        glFrustum;
extern PFNGLGENLISTSPROC                       glGenLists;
extern PFNGLGENTEXTURESPROC                    glGenTextures;
extern PFNGLGETBOOLEANVPROC                    glGetBooleanv;
extern PFNGLGETCLIPPLANEPROC                   glGetClipPlane;
extern PFNGLGETDOUBLEVPROC                     glGetDoublev;
extern PFNGLGETERRORPROC                       glGetError;
extern PFNGLGETFLOATVPROC                      glGetFloatv;
extern PFNGLGETINTEGERVPROC                    glGetIntegerv;
extern PFNGLGETLIGHTFVPROC                     glGetLightfv;
extern PFNGLGETLIGHTIVPROC                     glGetLightiv;
extern PFNGLGETMAPDVPROC                       glGetMapdv;
extern PFNGLGETMAPFVPROC                       glGetMapfv;
extern PFNGLGETMAPIVPROC                       glGetMapiv;
extern PFNGLGETMATERIALFVPROC                  glGetMaterialfv;
extern PFNGLGETMATERIALIVPROC                  glGetMaterialiv;
extern PFNGLGETPIXELMAPFVPROC                  glGetPixelMapfv;
extern PFNGLGETPIXELMAPUIVPROC                 glGetPixelMapuiv;
extern PFNGLGETPIXELMAPUSVPROC                 glGetPixelMapusv;
extern PFNGLGETPOINTERVPROC                    glGetPointerv;
extern PFNGLGETPOLYGONSTIPPLEPROC              glGetPolygonStipple;
extern PFNGLGETSTRINGPROC                      glGetString;
extern PFNGLGETTEXENVFVPROC                    glGetTexEnvfv;
extern PFNGLGETTEXENVIVPROC                    glGetTexEnviv;
extern PFNGLGETTEXGENDVPROC                    glGetTexGendv;
extern PFNGLGETTEXGENFVPROC                    glGetTexGenfv;
extern PFNGLGETTEXGENIVPROC                    glGetTexGeniv;
extern PFNGLGETTEXIMAGEPROC                    glGetTexImage;
extern PFNGLGETTEXLEVELPARAMETERFVPROC         glGetTexLevelParameterfv;
extern PFNGLGETTEXLEVELPARAMETERIVPROC         glGetTexLevelParameteriv;
extern PFNGLGETTEXPARAMETERFVPROC              glGetTexParameterfv;
extern PFNGLGETTEXPARAMETERIVPROC              glGetTexParameteriv;
extern PFNGLHINTPROC                           glHint;
extern PFNGLINDEXMASKPROC                      glIndexMask;
extern PFNGLINDEXPOINTERPROC                   glIndexPointer;
extern PFNGLINDEXDPROC                         glIndexd;
extern PFNGLINDEXDVPROC                        glIndexdv;
extern PFNGLINDEXFPROC                         glIndexf;
extern PFNGLINDEXFVPROC                        glIndexfv;
extern PFNGLINDEXIPROC                         glIndexi;
extern PFNGLINDEXIVPROC                        glIndexiv;
extern PFNGLINDEXSPROC                         glIndexs;
extern PFNGLINDEXSVPROC                        glIndexsv;
extern PFNGLINDEXUBPROC                        glIndexub;
extern PFNGLINDEXUBVPROC                       glIndexubv;
extern PFNGLINITNAMESPROC                      glInitNames;
extern PFNGLINTERLEAVEDARRAYSPROC              glInterleavedArrays;
extern PFNGLISENABLEDPROC                      glIsEnabled;
extern PFNGLISLISTPROC                         glIsList;
extern PFNGLISTEXTUREPROC                      glIsTexture;
extern PFNGLLIGHTMODELFPROC                    glLightModelf;
extern PFNGLLIGHTMODELFVPROC                   glLightModelfv;
extern PFNGLLIGHTMODELIPROC                    glLightModeli;
extern PFNGLLIGHTMODELIVPROC                   glLightModeliv;
extern PFNGLLIGHTFPROC                         glLightf;
extern PFNGLLIGHTFVPROC                        glLightfv;
extern PFNGLLIGHTIPROC                         glLighti;
extern PFNGLLIGHTIVPROC                        glLightiv;
extern PFNGLLINESTIPPLEPROC                    glLineStipple;
extern PFNGLLINEWIDTHPROC                      glLineWidth;
extern PFNGLLISTBASEPROC                       glListBase;
extern PFNGLLOADIDENTITYPROC                   glLoadIdentity;
extern PFNGLLOADMATRIXDPROC                    glLoadMatrixd;
extern PFNGLLOADMATRIXFPROC                    glLoadMatrixf;
extern PFNGLLOADNAMEPROC                       glLoadName;
extern PFNGLLOGICOPPROC                        glLogicOp;
extern PFNGLMAP1DPROC                          glMap1d;
extern PFNGLMAP1FPROC                          glMap1f;
extern PFNGLMAP2DPROC                          glMap2d;
extern PFNGLMAP2FPROC                          glMap2f;
extern PFNGLMAPGRID1DPROC                      glMapGrid1d;
extern PFNGLMAPGRID1FPROC                      glMapGrid1f;
extern PFNGLMAPGRID2DPROC                      glMapGrid2d;
extern PFNGLMAPGRID2FPROC                      glMapGrid2f;
extern PFNGLMATERIALFPROC                      glMaterialf;
extern PFNGLMATERIALFVPROC                     glMaterialfv;
extern PFNGLMATERIALIPROC                      glMateriali;
extern PFNGLMATERIALIVPROC                     glMaterialiv;
extern PFNGLMATRIXMODEPROC                     glMatrixMode;
extern PFNGLMULTMATRIXDPROC                    glMultMatrixd;
extern PFNGLMULTMATRIXFPROC                    glMultMatrixf;
extern PFNGLNEWLISTPROC                        glNewList;
extern PFNGLNORMAL3BPROC                       glNormal3b;
extern PFNGLNORMAL3BVPROC                      glNormal3bv;
extern PFNGLNORMAL3DPROC                       glNormal3d;
extern PFNGLNORMAL3DVPROC                      glNormal3dv;
extern PFNGLNORMAL3FPROC                       glNormal3f;
extern PFNGLNORMAL3FVPROC                      glNormal3fv;
extern PFNGLNORMAL3IPROC                       glNormal3i;
extern PFNGLNORMAL3IVPROC                      glNormal3iv;
extern PFNGLNORMAL3SPROC                       glNormal3s;
extern PFNGLNORMAL3SVPROC                      glNormal3sv;
extern PFNGLNORMALPOINTERPROC                  glNormalPointer;
extern PFNGLORTHOPROC                          glOrtho;
extern PFNGLPASSTHROUGHPROC                    glPassThrough;
extern PFNGLPIXELMAPFVPROC                     glPixelMapfv;
extern PFNGLPIXELMAPUIVPROC                    glPixelMapuiv;
extern PFNGLPIXELMAPUSVPROC                    glPixelMapusv;
extern PFNGLPIXELSTOREFPROC                    glPixelStoref;
extern PFNGLPIXELSTOREIPROC                    glPixelStorei;
extern PFNGLPIXELTRANSFERFPROC                 glPixelTransferf;
extern PFNGLPIXELTRANSFERIPROC                 glPixelTransferi;
extern PFNGLPIXELZOOMPROC                      glPixelZoom;
extern PFNGLPOINTSIZEPROC                      glPointSize;
extern PFNGLPOLYGONMODEPROC                    glPolygonMode;
extern PFNGLPOLYGONOFFSETPROC                  glPolygonOffset;
extern PFNGLPOLYGONSTIPPLEPROC                 glPolygonStipple;
extern PFNGLPOPATTRIBPROC                      glPopAttrib;
extern PFNGLPOPCLIENTATTRIBPROC                glPopClientAttrib;
extern PFNGLPOPMATRIXPROC                      glPopMatrix;
extern PFNGLPOPNAMEPROC                        glPopName;
extern PFNGLPRIORITIZETEXTURESPROC             glPrioritizeTextures;
extern PFNGLPUSHATTRIBPROC                     glPushAttrib;
extern PFNGLPUSHCLIENTATTRIBPROC               glPushClientAttrib;
extern PFNGLPUSHMATRIXPROC                     glPushMatrix;
extern PFNGLPUSHNAMEPROC                       glPushName;
extern PFNGLRASTERPOS2DPROC                    glRasterPos2d;
extern PFNGLRASTERPOS2DVPROC                   glRasterPos2dv;
extern PFNGLRASTERPOS2FPROC                    glRasterPos2f;
extern PFNGLRASTERPOS2FVPROC                   glRasterPos2fv;
extern PFNGLRASTERPOS2IPROC                    glRasterPos2i;
extern PFNGLRASTERPOS2IVPROC                   glRasterPos2iv;
extern PFNGLRASTERPOS2SPROC                    glRasterPos2s;
extern PFNGLRASTERPOS2SVPROC                   glRasterPos2sv;
extern PFNGLRASTERPOS3DPROC                    glRasterPos3d;
extern PFNGLRASTERPOS3DVPROC                   glRasterPos3dv;
extern PFNGLRASTERPOS3FPROC                    glRasterPos3f;
extern PFNGLRASTERPOS3FVPROC                   glRasterPos3fv;
extern PFNGLRASTERPOS3IPROC                    glRasterPos3i;
extern PFNGLRASTERPOS3IVPROC                   glRasterPos3iv;
extern PFNGLRASTERPOS3SPROC                    glRasterPos3s;
extern PFNGLRASTERPOS3SVPROC                   glRasterPos3sv;
extern PFNGLRASTERPOS4DPROC                    glRasterPos4d;
extern PFNGLRASTERPOS4DVPROC                   glRasterPos4dv;
extern PFNGLRASTERPOS4FPROC                    glRasterPos4f;
extern PFNGLRASTERPOS4FVPROC                   glRasterPos4fv;
extern PFNGLRASTERPOS4IPROC                    glRasterPos4i;
extern PFNGLRASTERPOS4IVPROC                   glRasterPos4iv;
extern PFNGLRASTERPOS4SPROC                    glRasterPos4s;
extern PFNGLRASTERPOS4SVPROC                   glRasterPos4sv;
extern PFNGLREADBUFFERPROC                     glReadBuffer;
extern PFNGLREADPIXELSPROC                     glReadPixels;
extern PFNGLRECTDPROC                          glRectd;
extern PFNGLRECTDVPROC                         glRectdv;
extern PFNGLRECTFPROC                          glRectf;
extern PFNGLRECTFVPROC                         glRectfv;
extern PFNGLRECTIPROC                          glRecti;
extern PFNGLRECTIVPROC                         glRectiv;
extern PFNGLRECTSPROC                          glRects;
extern PFNGLRECTSVPROC                         glRectsv;
extern PFNGLRENDERMODEPROC                     glRenderMode;
extern PFNGLROTATEDPROC                        glRotated;
extern PFNGLROTATEFPROC                        glRotatef;
extern PFNGLSCALEDPROC                         glScaled;
extern PFNGLSCALEFPROC                         glScalef;
extern PFNGLSCISSORPROC                        glScissor;
extern PFNGLSELECTBUFFERPROC                   glSelectBuffer;
extern PFNGLSHADEMODELPROC                     glShadeModel;
extern PFNGLSTENCILFUNCPROC                    glStencilFunc;
extern PFNGLSTENCILMASKPROC                    glStencilMask;
extern PFNGLSTENCILOPPROC                      glStencilOp;
extern PFNGLTEXCOORD1DPROC                     glTexCoord1d;
extern PFNGLTEXCOORD1DVPROC                    glTexCoord1dv;
extern PFNGLTEXCOORD1FPROC                     glTexCoord1f;
extern PFNGLTEXCOORD1FVPROC                    glTexCoord1fv;
extern PFNGLTEXCOORD1IPROC                     glTexCoord1i;
extern PFNGLTEXCOORD1IVPROC                    glTexCoord1iv;
extern PFNGLTEXCOORD1SPROC                     glTexCoord1s;
extern PFNGLTEXCOORD1SVPROC                    glTexCoord1sv;
extern PFNGLTEXCOORD2DPROC                     glTexCoord2d;
extern PFNGLTEXCOORD2DVPROC                    glTexCoord2dv;
extern PFNGLTEXCOORD2FPROC                     glTexCoord2f;
extern PFNGLTEXCOORD2FVPROC                    glTexCoord2fv;
extern PFNGLTEXCOORD2IPROC                     glTexCoord2i;
extern PFNGLTEXCOORD2IVPROC                    glTexCoord2iv;
extern PFNGLTEXCOORD2SPROC                     glTexCoord2s;
extern PFNGLTEXCOORD2SVPROC                    glTexCoord2sv;
extern PFNGLTEXCOORD3DPROC                     glTexCoord3d;
extern PFNGLTEXCOORD3DVPROC                    glTexCoord3dv;
extern PFNGLTEXCOORD3FPROC                     glTexCoord3f;
extern PFNGLTEXCOORD3FVPROC                    glTexCoord3fv;
extern PFNGLTEXCOORD3IPROC                     glTexCoord3i;
extern PFNGLTEXCOORD3IVPROC                    glTexCoord3iv;
extern PFNGLTEXCOORD3SPROC                     glTexCoord3s;
extern PFNGLTEXCOORD3SVPROC                    glTexCoord3sv;
extern PFNGLTEXCOORD4DPROC                     glTexCoord4d;
extern PFNGLTEXCOORD4DVPROC                    glTexCoord4dv;
extern PFNGLTEXCOORD4FPROC                     glTexCoord4f;
extern PFNGLTEXCOORD4FVPROC                    glTexCoord4fv;
extern PFNGLTEXCOORD4IPROC                     glTexCoord4i;
extern PFNGLTEXCOORD4IVPROC                    glTexCoord4iv;
extern PFNGLTEXCOORD4SPROC                     glTexCoord4s;
extern PFNGLTEXCOORD4SVPROC                    glTexCoord4sv;
extern PFNGLTEXCOORDPOINTERPROC                glTexCoordPointer;
extern PFNGLTEXENVFPROC                        glTexEnvf;
extern PFNGLTEXENVFVPROC                       glTexEnvfv;
extern PFNGLTEXENVIPROC                        glTexEnvi;
extern PFNGLTEXENVIVPROC                       glTexEnviv;
extern PFNGLTEXGENDPROC                        glTexGend;
extern PFNGLTEXGENDVPROC                       glTexGendv;
extern PFNGLTEXGENFPROC                        glTexGenf;
extern PFNGLTEXGENFVPROC                       glTexGenfv;
extern PFNGLTEXGENIPROC                        glTexGeni;
extern PFNGLTEXGENIVPROC                       glTexGeniv;
extern PFNGLTEXIMAGE1DPROC                     glTexImage1D;
extern PFNGLTEXIMAGE2DPROC                     glTexImage2D;
extern PFNGLTEXPARAMETERFPROC                  glTexParameterf;
extern PFNGLTEXPARAMETERFVPROC                 glTexParameterfv;
extern PFNGLTEXPARAMETERIPROC                  glTexParameteri;
extern PFNGLTEXPARAMETERIVPROC                 glTexParameteriv;
extern PFNGLTEXSUBIMAGE1DPROC                  glTexSubImage1D;
extern PFNGLTEXSUBIMAGE2DPROC                  glTexSubImage2D;
extern PFNGLTRANSLATEDPROC                     glTranslated;
extern PFNGLTRANSLATEFPROC                     glTranslatef;
extern PFNGLVERTEX2DPROC                       glVertex2d;
extern PFNGLVERTEX2DVPROC                      glVertex2dv;
extern PFNGLVERTEX2FPROC                       glVertex2f;
extern PFNGLVERTEX2FVPROC                      glVertex2fv;
extern PFNGLVERTEX2IPROC                       glVertex2i;
extern PFNGLVERTEX2IVPROC                      glVertex2iv;
extern PFNGLVERTEX2SPROC                       glVertex2s;
extern PFNGLVERTEX2SVPROC                      glVertex2sv;
extern PFNGLVERTEX3DPROC                       glVertex3d;
extern PFNGLVERTEX3DVPROC                      glVertex3dv;
extern PFNGLVERTEX3FPROC                       glVertex3f;
extern PFNGLVERTEX3FVPROC                      glVertex3fv;
extern PFNGLVERTEX3IPROC                       glVertex3i;
extern PFNGLVERTEX3IVPROC                      glVertex3iv;
extern PFNGLVERTEX3SPROC                       glVertex3s;
extern PFNGLVERTEX3SVPROC                      glVertex3sv;
extern PFNGLVERTEX4DPROC                       glVertex4d;
extern PFNGLVERTEX4DVPROC                      glVertex4dv;
extern PFNGLVERTEX4FPROC                       glVertex4f;
extern PFNGLVERTEX4FVPROC                      glVertex4fv;
extern PFNGLVERTEX4IPROC                       glVertex4i;
extern PFNGLVERTEX4IVPROC                      glVertex4iv;
extern PFNGLVERTEX4SPROC                       glVertex4s;
extern PFNGLVERTEX4SVPROC                      glVertex4sv;
extern PFNGLVERTEXPOINTERPROC                  glVertexPointer;
extern PFNGLVIEWPORTPROC                       glViewport;

/*
 * OpenGL 1.2 API.
 */

#define GL_ALIASED_LINE_WIDTH_RANGE               0x846E
#define GL_ALIASED_POINT_SIZE_RANGE               0x846D
#define GL_BGR                                    0x80E0
#define GL_BGRA                                   0x80E1
#define GL_CLAMP_TO_EDGE                          0x812F
#define GL_LIGHT_MODEL_COLOR_CONTROL              0x81F8
#define GL_MAX_3D_TEXTURE_SIZE                    0x8073
#define GL_MAX_ELEMENTS_INDICES                   0x80E9
#define GL_MAX_ELEMENTS_VERTICES                  0x80E8
#define GL_PACK_IMAGE_HEIGHT                      0x806C
#define GL_PACK_SKIP_IMAGES                       0x806B
#define GL_PROXY_TEXTURE_3D                       0x8070
#define GL_RESCALE_NORMAL                         0x803A
#define GL_SEPARATE_SPECULAR_COLOR                0x81FA
#define GL_SINGLE_COLOR                           0x81F9
#define GL_SMOOTH_LINE_WIDTH_GRANULARITY          0x0B23
#define GL_SMOOTH_LINE_WIDTH_RANGE                0x0B22
#define GL_SMOOTH_POINT_SIZE_GRANULARITY          0x0B13
#define GL_SMOOTH_POINT_SIZE_RANGE                0x0B12
#define GL_TEXTURE_3D                             0x806F
#define GL_TEXTURE_BASE_LEVEL                     0x813C
#define GL_TEXTURE_BINDING_3D                     0x806A
#define GL_TEXTURE_DEPTH                          0x8071
#define GL_TEXTURE_MAX_LEVEL                      0x813D
#define GL_TEXTURE_MAX_LOD                        0x813B
#define GL_TEXTURE_MIN_LOD                        0x813A
#define GL_TEXTURE_WRAP_R                         0x8072
#define GL_UNPACK_IMAGE_HEIGHT                    0x806E
#define GL_UNPACK_SKIP_IMAGES                     0x806D
#define GL_UNSIGNED_BYTE_2_3_3_REV                0x8362
#define GL_UNSIGNED_BYTE_3_3_2                    0x8032
#define GL_UNSIGNED_INT_10_10_10_2                0x8036
#define GL_UNSIGNED_INT_2_10_10_10_REV            0x8368
#define GL_UNSIGNED_INT_8_8_8_8                   0x8035
#define GL_UNSIGNED_INT_8_8_8_8_REV               0x8367
#define GL_UNSIGNED_SHORT_1_5_5_5_REV             0x8366
#define GL_UNSIGNED_SHORT_4_4_4_4                 0x8033
#define GL_UNSIGNED_SHORT_4_4_4_4_REV             0x8365
#define GL_UNSIGNED_SHORT_5_5_5_1                 0x8034
#define GL_UNSIGNED_SHORT_5_6_5                   0x8363
#define GL_UNSIGNED_SHORT_5_6_5_REV               0x8364

typedef void (APIENTRY * PFNGLCOPYTEXSUBIMAGE3DPROC) (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height);
typedef void (APIENTRY * PFNGLDRAWRANGEELEMENTSPROC) (GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, const void *indices);
typedef void (APIENTRY * PFNGLTEXIMAGE3DPROC) (GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLenum format, GLenum type, const void *pixels);
typedef void (APIENTRY * PFNGLTEXSUBIMAGE3DPROC) (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const void *pixels);

extern PFNGLCOPYTEXSUBIMAGE3DPROC                 glCopyTexSubImage3D;
extern PFNGLDRAWRANGEELEMENTSPROC                 glDrawRangeElements;
extern PFNGLTEXIMAGE3DPROC                        glTexImage3D;
extern PFNGLTEXSUBIMAGE3DPROC                     glTexSubImage3D;

/*
 * OpenGL 1.3 API.
 */

#define GL_ACTIVE_TEXTURE                         0x84E0
#define GL_ADD_SIGNED                             0x8574
#define GL_CLAMP_TO_BORDER                        0x812D
#define GL_CLAMP_TO_BORDER_SGIS                   0x812D
#define GL_CLIENT_ACTIVE_TEXTURE                  0x84E1
#define GL_COMBINE                                0x8570
#define GL_COMBINE_ALPHA                          0x8572
#define GL_COMBINE_RGB                            0x8571
#define GL_COMPRESSED_ALPHA                       0x84E9
#define GL_COMPRESSED_INTENSITY                   0x84EC
#define GL_COMPRESSED_LUMINANCE                   0x84EA
#define GL_COMPRESSED_LUMINANCE_ALPHA             0x84EB
#define GL_COMPRESSED_RGB                         0x84ED
#define GL_COMPRESSED_RGBA                        0x84EE
#define GL_COMPRESSED_TEXTURE_FORMATS             0x86A3
#define GL_CONSTANT                               0x8576
#define GL_DOT3_RGB                               0x86AE
#define GL_DOT3_RGBA                              0x86AF
#define GL_INTERPOLATE                            0x8575
#define GL_MAX_CUBE_MAP_TEXTURE_SIZE              0x851C
#define GL_MAX_TEXTURE_UNITS                      0x84E2
#define GL_MULTISAMPLE                            0x809D
#define GL_MULTISAMPLE_BIT                        0x20000000
#define GL_NORMAL_MAP                             0x8511
#define GL_NUM_COMPRESSED_TEXTURE_FORMATS         0x86A2
#define GL_OPERAND0_ALPHA                         0x8598
#define GL_OPERAND0_RGB                           0x8590
#define GL_OPERAND1_ALPHA                         0x8599
#define GL_OPERAND1_RGB                           0x8591
#define GL_OPERAND2_ALPHA                         0x859A
#define GL_OPERAND2_RGB                           0x8592
#define GL_PREVIOUS                               0x8578
#define GL_PRIMARY_COLOR                          0x8577
#define GL_PROXY_TEXTURE_CUBE_MAP                 0x851B
#define GL_REFLECTION_MAP                         0x8512
#define GL_RGB_SCALE                              0x8573
#define GL_SAMPLES                                0x80A9
#define GL_SAMPLE_ALPHA_TO_COVERAGE               0x809E
#define GL_SAMPLE_ALPHA_TO_ONE                    0x809F
#define GL_SAMPLE_BUFFERS                         0x80A8
#define GL_SAMPLE_COVERAGE                        0x80A0
#define GL_SAMPLE_COVERAGE_INVERT                 0x80AB
#define GL_SAMPLE_COVERAGE_VALUE                  0x80AA
#define GL_SOURCE0_ALPHA                          0x8588
#define GL_SOURCE0_RGB                            0x8580
#define GL_SOURCE1_ALPHA                          0x8589
#define GL_SOURCE1_RGB                            0x8581
#define GL_SOURCE2_ALPHA                          0x858A
#define GL_SOURCE2_RGB                            0x8582
#define GL_SUBTRACT                               0x84E7
#define GL_TEXTURE0                               0x84C0
#define GL_TEXTURE1                               0x84C1
#define GL_TEXTURE10                              0x84CA
#define GL_TEXTURE11                              0x84CB
#define GL_TEXTURE12                              0x84CC
#define GL_TEXTURE13                              0x84CD
#define GL_TEXTURE14                              0x84CE
#define GL_TEXTURE15                              0x84CF
#define GL_TEXTURE16                              0x84D0
#define GL_TEXTURE17                              0x84D1
#define GL_TEXTURE18                              0x84D2
#define GL_TEXTURE19                              0x84D3
#define GL_TEXTURE2                               0x84C2
#define GL_TEXTURE20                              0x84D4
#define GL_TEXTURE21                              0x84D5
#define GL_TEXTURE22                              0x84D6
#define GL_TEXTURE23                              0x84D7
#define GL_TEXTURE24                              0x84D8
#define GL_TEXTURE25                              0x84D9
#define GL_TEXTURE26                              0x84DA
#define GL_TEXTURE27                              0x84DB
#define GL_TEXTURE28                              0x84DC
#define GL_TEXTURE29                              0x84DD
#define GL_TEXTURE3                               0x84C3
#define GL_TEXTURE30                              0x84DE
#define GL_TEXTURE31                              0x84DF
#define GL_TEXTURE4                               0x84C4
#define GL_TEXTURE5                               0x84C5
#define GL_TEXTURE6                               0x84C6
#define GL_TEXTURE7                               0x84C7
#define GL_TEXTURE8                               0x84C8
#define GL_TEXTURE9                               0x84C9
#define GL_TEXTURE_BINDING_CUBE_MAP               0x8514
#define GL_TEXTURE_COMPRESSED                     0x86A1
#define GL_TEXTURE_COMPRESSED_IMAGE_SIZE          0x86A0
#define GL_TEXTURE_COMPRESSION_HINT               0x84EF
#define GL_TEXTURE_CUBE_MAP                       0x8513
#define GL_TEXTURE_CUBE_MAP_NEGATIVE_X            0x8516
#define GL_TEXTURE_CUBE_MAP_NEGATIVE_Y            0x8518
#define GL_TEXTURE_CUBE_MAP_NEGATIVE_Z            0x851A
#define GL_TEXTURE_CUBE_MAP_POSITIVE_X            0x8515
#define GL_TEXTURE_CUBE_MAP_POSITIVE_Y            0x8517
#define GL_TEXTURE_CUBE_MAP_POSITIVE_Z            0x8519
#define GL_TRANSPOSE_COLOR_MATRIX                 0x84E6
#define GL_TRANSPOSE_MODELVIEW_MATRIX             0x84E3
#define GL_TRANSPOSE_PROJECTION_MATRIX            0x84E4
#define GL_TRANSPOSE_TEXTURE_MATRIX               0x84E5

typedef void (APIENTRY * PFNGLACTIVETEXTUREPROC) (GLenum texture);
typedef void (APIENTRY * PFNGLCLIENTACTIVETEXTUREPROC) (GLenum texture);
typedef void (APIENTRY * PFNGLCOMPRESSEDTEXIMAGE1DPROC) (GLenum target, GLint level, GLenum internalformat, GLsizei width, GLint border, GLsizei imageSize, const void *data);
typedef void (APIENTRY * PFNGLCOMPRESSEDTEXIMAGE2DPROC) (GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLsizei imageSize, const void *data);
typedef void (APIENTRY * PFNGLCOMPRESSEDTEXIMAGE3DPROC) (GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLsizei imageSize, const void *data);
typedef void (APIENTRY * PFNGLCOMPRESSEDTEXSUBIMAGE1DPROC) (GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLsizei imageSize, const void *data);
typedef void (APIENTRY * PFNGLCOMPRESSEDTEXSUBIMAGE2DPROC) (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const void *data);
typedef void (APIENTRY * PFNGLCOMPRESSEDTEXSUBIMAGE3DPROC) (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, const void *data);
typedef void (APIENTRY * PFNGLGETCOMPRESSEDTEXIMAGEPROC) (GLenum target, GLint level, void *img);
typedef void (APIENTRY * PFNGLLOADTRANSPOSEMATRIXDPROC) (const GLdouble *m);
typedef void (APIENTRY * PFNGLLOADTRANSPOSEMATRIXFPROC) (const GLfloat *m);
typedef void (APIENTRY * PFNGLMULTITEXCOORD1DPROC) (GLenum target, GLdouble s);
typedef void (APIENTRY * PFNGLMULTITEXCOORD1DVPROC) (GLenum target, const GLdouble *v);
typedef void (APIENTRY * PFNGLMULTITEXCOORD1FPROC) (GLenum target, GLfloat s);
typedef void (APIENTRY * PFNGLMULTITEXCOORD1FVPROC) (GLenum target, const GLfloat *v);
typedef void (APIENTRY * PFNGLMULTITEXCOORD1IPROC) (GLenum target, GLint s);
typedef void (APIENTRY * PFNGLMULTITEXCOORD1IVPROC) (GLenum target, const GLint *v);
typedef void (APIENTRY * PFNGLMULTITEXCOORD1SPROC) (GLenum target, GLshort s);
typedef void (APIENTRY * PFNGLMULTITEXCOORD1SVPROC) (GLenum target, const GLshort *v);
typedef void (APIENTRY * PFNGLMULTITEXCOORD2DPROC) (GLenum target, GLdouble s, GLdouble t);
typedef void (APIENTRY * PFNGLMULTITEXCOORD2DVPROC) (GLenum target, const GLdouble *v);
typedef void (APIENTRY * PFNGLMULTITEXCOORD2FPROC) (GLenum target, GLfloat s, GLfloat t);
typedef void (APIENTRY * PFNGLMULTITEXCOORD2FVPROC) (GLenum target, const GLfloat *v);
typedef void (APIENTRY * PFNGLMULTITEXCOORD2IPROC) (GLenum target, GLint s, GLint t);
typedef void (APIENTRY * PFNGLMULTITEXCOORD2IVPROC) (GLenum target, const GLint *v);
typedef void (APIENTRY * PFNGLMULTITEXCOORD2SPROC) (GLenum target, GLshort s, GLshort t);
typedef void (APIENTRY * PFNGLMULTITEXCOORD2SVPROC) (GLenum target, const GLshort *v);
typedef void (APIENTRY * PFNGLMULTITEXCOORD3DPROC) (GLenum target, GLdouble s, GLdouble t, GLdouble r);
typedef void (APIENTRY * PFNGLMULTITEXCOORD3DVPROC) (GLenum target, const GLdouble *v);
typedef void (APIENTRY * PFNGLMULTITEXCOORD3FPROC) (GLenum target, GLfloat s, GLfloat t, GLfloat r);
typedef void (APIENTRY * PFNGLMULTITEXCOORD3FVPROC) (GLenum target, const GLfloat *v);
typedef void (APIENTRY * PFNGLMULTITEXCOORD3IPROC) (GLenum target, GLint s, GLint t, GLint r);
typedef void (APIENTRY * PFNGLMULTITEXCOORD3IVPROC) (GLenum target, const GLint *v);
typedef void (APIENTRY * PFNGLMULTITEXCOORD3SPROC) (GLenum target, GLshort s, GLshort t, GLshort r);
typedef void (APIENTRY * PFNGLMULTITEXCOORD3SVPROC) (GLenum target, const GLshort *v);
typedef void (APIENTRY * PFNGLMULTITEXCOORD4DPROC) (GLenum target, GLdouble s, GLdouble t, GLdouble r, GLdouble q);
typedef void (APIENTRY * PFNGLMULTITEXCOORD4DVPROC) (GLenum target, const GLdouble *v);
typedef void (APIENTRY * PFNGLMULTITEXCOORD4FPROC) (GLenum target, GLfloat s, GLfloat t, GLfloat r, GLfloat q);
typedef void (APIENTRY * PFNGLMULTITEXCOORD4FVPROC) (GLenum target, const GLfloat *v);
typedef void (APIENTRY * PFNGLMULTITEXCOORD4IPROC) (GLenum target, GLint s, GLint t, GLint r, GLint q);
typedef void (APIENTRY * PFNGLMULTITEXCOORD4IVPROC) (GLenum target, const GLint *v);
typedef void (APIENTRY * PFNGLMULTITEXCOORD4SPROC) (GLenum target, GLshort s, GLshort t, GLshort r, GLshort q);
typedef void (APIENTRY * PFNGLMULTITEXCOORD4SVPROC) (GLenum target, const GLshort *v);
typedef void (APIENTRY * PFNGLMULTTRANSPOSEMATRIXDPROC) (const GLdouble *m);
typedef void (APIENTRY * PFNGLMULTTRANSPOSEMATRIXFPROC) (const GLfloat *m);
typedef void (APIENTRY * PFNGLSAMPLECOVERAGEPROC) (GLclampf value, GLboolean invert);

extern PFNGLACTIVETEXTUREPROC                     glActiveTexture;
extern PFNGLCLIENTACTIVETEXTUREPROC               glClientActiveTexture;
extern PFNGLCOMPRESSEDTEXIMAGE1DPROC              glCompressedTexImage1D;
extern PFNGLCOMPRESSEDTEXIMAGE2DPROC              glCompressedTexImage2D;
extern PFNGLCOMPRESSEDTEXIMAGE3DPROC              glCompressedTexImage3D;
extern PFNGLCOMPRESSEDTEXSUBIMAGE1DPROC           glCompressedTexSubImage1D;
extern PFNGLCOMPRESSEDTEXSUBIMAGE2DPROC           glCompressedTexSubImage2D;
extern PFNGLCOMPRESSEDTEXSUBIMAGE3DPROC           glCompressedTexSubImage3D;
extern PFNGLGETCOMPRESSEDTEXIMAGEPROC             glGetCompressedTexImage;
extern PFNGLLOADTRANSPOSEMATRIXDPROC              glLoadTransposeMatrixd;
extern PFNGLLOADTRANSPOSEMATRIXFPROC              glLoadTransposeMatrixf;
extern PFNGLMULTITEXCOORD1DPROC                   glMultiTexCoord1d;
extern PFNGLMULTITEXCOORD1DVPROC                  glMultiTexCoord1dv;
extern PFNGLMULTITEXCOORD1FPROC                   glMultiTexCoord1f;
extern PFNGLMULTITEXCOORD1FVPROC                  glMultiTexCoord1fv;
extern PFNGLMULTITEXCOORD1IPROC                   glMultiTexCoord1i;
extern PFNGLMULTITEXCOORD1IVPROC                  glMultiTexCoord1iv;
extern PFNGLMULTITEXCOORD1SPROC                   glMultiTexCoord1s;
extern PFNGLMULTITEXCOORD1SVPROC                  glMultiTexCoord1sv;
extern PFNGLMULTITEXCOORD2DPROC                   glMultiTexCoord2d;
extern PFNGLMULTITEXCOORD2DVPROC                  glMultiTexCoord2dv;
extern PFNGLMULTITEXCOORD2FPROC                   glMultiTexCoord2f;
extern PFNGLMULTITEXCOORD2FVPROC                  glMultiTexCoord2fv;
extern PFNGLMULTITEXCOORD2IPROC                   glMultiTexCoord2i;
extern PFNGLMULTITEXCOORD2IVPROC                  glMultiTexCoord2iv;
extern PFNGLMULTITEXCOORD2SPROC                   glMultiTexCoord2s;
extern PFNGLMULTITEXCOORD2SVPROC                  glMultiTexCoord2sv;
extern PFNGLMULTITEXCOORD3DPROC                   glMultiTexCoord3d;
extern PFNGLMULTITEXCOORD3DVPROC                  glMultiTexCoord3dv;
extern PFNGLMULTITEXCOORD3FPROC                   glMultiTexCoord3f;
extern PFNGLMULTITEXCOORD3FVPROC                  glMultiTexCoord3fv;
extern PFNGLMULTITEXCOORD3IPROC                   glMultiTexCoord3i;
extern PFNGLMULTITEXCOORD3IVPROC                  glMultiTexCoord3iv;
extern PFNGLMULTITEXCOORD3SPROC                   glMultiTexCoord3s;
extern PFNGLMULTITEXCOORD3SVPROC                  glMultiTexCoord3sv;
extern PFNGLMULTITEXCOORD4DPROC                   glMultiTexCoord4d;
extern PFNGLMULTITEXCOORD4DVPROC                  glMultiTexCoord4dv;
extern PFNGLMULTITEXCOORD4FPROC                   glMultiTexCoord4f;
extern PFNGLMULTITEXCOORD4FVPROC                  glMultiTexCoord4fv;
extern PFNGLMULTITEXCOORD4IPROC                   glMultiTexCoord4i;
extern PFNGLMULTITEXCOORD4IVPROC                  glMultiTexCoord4iv;
extern PFNGLMULTITEXCOORD4SPROC                   glMultiTexCoord4s;
extern PFNGLMULTITEXCOORD4SVPROC                  glMultiTexCoord4sv;
extern PFNGLMULTTRANSPOSEMATRIXDPROC              glMultTransposeMatrixd;
extern PFNGLMULTTRANSPOSEMATRIXFPROC              glMultTransposeMatrixf;
extern PFNGLSAMPLECOVERAGEPROC                    glSampleCoverage;

/*
 * OpenGL 1.4 API.
 */

#define GL_BLEND_DST_ALPHA                        0x80CA
#define GL_BLEND_DST_RGB                          0x80C8
#define GL_BLEND_SRC_ALPHA                        0x80CB
#define GL_BLEND_SRC_RGB                          0x80C9
#define GL_COLOR_SUM                              0x8458
#define GL_COMPARE_R_TO_TEXTURE                   0x884E
#define GL_CURRENT_FOG_COORDINATE                 0x8453
#define GL_CURRENT_SECONDARY_COLOR                0x8459
#define GL_DECR_WRAP                              0x8508
#define GL_DEPTH_COMPONENT16                      0x81A5
#define GL_DEPTH_COMPONENT24                      0x81A6
#define GL_DEPTH_COMPONENT32                      0x81A7
#define GL_DEPTH_TEXTURE_MODE                     0x884B
#define GL_FOG_COORDINATE                         0x8451
#define GL_FOG_COORDINATE_ARRAY                   0x8457
#define GL_FOG_COORDINATE_ARRAY_POINTER           0x8456
#define GL_FOG_COORDINATE_ARRAY_STRIDE            0x8455
#define GL_FOG_COORDINATE_ARRAY_TYPE              0x8454
#define GL_FOG_COORDINATE_SOURCE                  0x8450
#define GL_FRAGMENT_DEPTH                         0x8452
#define GL_GENERATE_MIPMAP                        0x8191
#define GL_GENERATE_MIPMAP_HINT                   0x8192
#define GL_INCR_WRAP                              0x8507
#define GL_MAX_TEXTURE_LOD_BIAS                   0x84FD
#define GL_MIRRORED_REPEAT                        0x8370
#define GL_POINT_DISTANCE_ATTENUATION             0x8129
#define GL_POINT_FADE_THRESHOLD_SIZE              0x8128
#define GL_POINT_SIZE_MAX                         0x8127
#define GL_POINT_SIZE_MIN                         0x8126
#define GL_SECONDARY_COLOR_ARRAY                  0x845E
#define GL_SECONDARY_COLOR_ARRAY_POINTER          0x845D
#define GL_SECONDARY_COLOR_ARRAY_SIZE             0x845A
#define GL_SECONDARY_COLOR_ARRAY_STRIDE           0x845C
#define GL_SECONDARY_COLOR_ARRAY_TYPE             0x845B
#define GL_TEXTURE_COMPARE_FUNC                   0x884D
#define GL_TEXTURE_COMPARE_MODE                   0x884C
#define GL_TEXTURE_DEPTH_SIZE                     0x884A
#define GL_TEXTURE_FILTER_CONTROL                 0x8500
#define GL_TEXTURE_LOD_BIAS                       0x8501

typedef void (APIENTRY * PFNGLBLENDFUNCSEPARATEPROC) (GLenum sfactorRGB, GLenum dfactorRGB, GLenum sfactorAlpha, GLenum dfactorAlpha);
typedef void (APIENTRY * PFNGLFOGCOORDDPROC) (GLdouble coord);
typedef void (APIENTRY * PFNGLFOGCOORDDVPROC) (const GLdouble *coord);
typedef void (APIENTRY * PFNGLFOGCOORDFPROC) (GLfloat coord);
typedef void (APIENTRY * PFNGLFOGCOORDFVPROC) (const GLfloat *coord);
typedef void (APIENTRY * PFNGLFOGCOORDPOINTERPROC) (GLenum type, GLsizei stride, const void *pointer);
typedef void (APIENTRY * PFNGLMULTIDRAWARRAYSPROC) (GLenum mode, GLint *first, GLsizei *count, GLsizei primcount);
typedef void (APIENTRY * PFNGLMULTIDRAWELEMENTSPROC) (GLenum mode, const GLsizei *count, GLenum type, const void* *indices, GLsizei primcount);
typedef void (APIENTRY * PFNGLPOINTPARAMETERFPROC) (GLenum pname, GLfloat param);
typedef void (APIENTRY * PFNGLPOINTPARAMETERFVPROC) (GLenum pname, const GLfloat *params);
typedef void (APIENTRY * PFNGLPOINTPARAMETERIPROC) (GLenum pname, GLint param);
typedef void (APIENTRY * PFNGLPOINTPARAMETERIVPROC) (GLenum pname, const GLint *params);
typedef void (APIENTRY * PFNGLSECONDARYCOLOR3BPROC) (GLbyte red, GLbyte green, GLbyte blue);
typedef void (APIENTRY * PFNGLSECONDARYCOLOR3BVPROC) (const GLbyte *v);
typedef void (APIENTRY * PFNGLSECONDARYCOLOR3DPROC) (GLdouble red, GLdouble green, GLdouble blue);
typedef void (APIENTRY * PFNGLSECONDARYCOLOR3DVPROC) (const GLdouble *v);
typedef void (APIENTRY * PFNGLSECONDARYCOLOR3FPROC) (GLfloat red, GLfloat green, GLfloat blue);
typedef void (APIENTRY * PFNGLSECONDARYCOLOR3FVPROC) (const GLfloat *v);
typedef void (APIENTRY * PFNGLSECONDARYCOLOR3IPROC) (GLint red, GLint green, GLint blue);
typedef void (APIENTRY * PFNGLSECONDARYCOLOR3IVPROC) (const GLint *v);
typedef void (APIENTRY * PFNGLSECONDARYCOLOR3SPROC) (GLshort red, GLshort green, GLshort blue);
typedef void (APIENTRY * PFNGLSECONDARYCOLOR3SVPROC) (const GLshort *v);
typedef void (APIENTRY * PFNGLSECONDARYCOLOR3UBPROC) (GLubyte red, GLubyte green, GLubyte blue);
typedef void (APIENTRY * PFNGLSECONDARYCOLOR3UBVPROC) (const GLubyte *v);
typedef void (APIENTRY * PFNGLSECONDARYCOLOR3UIPROC) (GLuint red, GLuint green, GLuint blue);
typedef void (APIENTRY * PFNGLSECONDARYCOLOR3UIVPROC) (const GLuint *v);
typedef void (APIENTRY * PFNGLSECONDARYCOLOR3USPROC) (GLushort red, GLushort green, GLushort blue);
typedef void (APIENTRY * PFNGLSECONDARYCOLOR3USVPROC) (const GLushort *v);
typedef void (APIENTRY * PFNGLSECONDARYCOLORPOINTERPROC) (GLint size, GLenum type, GLsizei stride, const void *pointer);
typedef void (APIENTRY * PFNGLWINDOWPOS2DPROC) (GLdouble x, GLdouble y);
typedef void (APIENTRY * PFNGLWINDOWPOS2DVPROC) (const GLdouble *v);
typedef void (APIENTRY * PFNGLWINDOWPOS2FPROC) (GLfloat x, GLfloat y);
typedef void (APIENTRY * PFNGLWINDOWPOS2FVPROC) (const GLfloat *v);
typedef void (APIENTRY * PFNGLWINDOWPOS2IPROC) (GLint x, GLint y);
typedef void (APIENTRY * PFNGLWINDOWPOS2IVPROC) (const GLint *v);
typedef void (APIENTRY * PFNGLWINDOWPOS2SPROC) (GLshort x, GLshort y);
typedef void (APIENTRY * PFNGLWINDOWPOS2SVPROC) (const GLshort *v);
typedef void (APIENTRY * PFNGLWINDOWPOS3DPROC) (GLdouble x, GLdouble y, GLdouble z);
typedef void (APIENTRY * PFNGLWINDOWPOS3DVPROC) (const GLdouble *v);
typedef void (APIENTRY * PFNGLWINDOWPOS3FPROC) (GLfloat x, GLfloat y, GLfloat z);
typedef void (APIENTRY * PFNGLWINDOWPOS3FVPROC) (const GLfloat *v);
typedef void (APIENTRY * PFNGLWINDOWPOS3IPROC) (GLint x, GLint y, GLint z);
typedef void (APIENTRY * PFNGLWINDOWPOS3IVPROC) (const GLint *v);
typedef void (APIENTRY * PFNGLWINDOWPOS3SPROC) (GLshort x, GLshort y, GLshort z);
typedef void (APIENTRY * PFNGLWINDOWPOS3SVPROC) (const GLshort *v);

extern PFNGLBLENDFUNCSEPARATEPROC                 glBlendFuncSeparate;
extern PFNGLMULTIDRAWARRAYSPROC                   glMultiDrawArrays;
extern PFNGLMULTIDRAWELEMENTSPROC                 glMultiDrawElements;
extern PFNGLPOINTPARAMETERFPROC                   glPointParameterf;
extern PFNGLPOINTPARAMETERFVPROC                  glPointParameterfv;
extern PFNGLSECONDARYCOLOR3BPROC                  glSecondaryColor3b;
extern PFNGLSECONDARYCOLOR3BVPROC                 glSecondaryColor3bv;
extern PFNGLSECONDARYCOLOR3DPROC                  glSecondaryColor3d;
extern PFNGLSECONDARYCOLOR3DVPROC                 glSecondaryColor3dv;
extern PFNGLSECONDARYCOLOR3FPROC                  glSecondaryColor3f;
extern PFNGLSECONDARYCOLOR3FVPROC                 glSecondaryColor3fv;
extern PFNGLSECONDARYCOLOR3IPROC                  glSecondaryColor3i;
extern PFNGLSECONDARYCOLOR3IVPROC                 glSecondaryColor3iv;
extern PFNGLSECONDARYCOLOR3SPROC                  glSecondaryColor3s;
extern PFNGLSECONDARYCOLOR3SVPROC                 glSecondaryColor3sv;
extern PFNGLSECONDARYCOLOR3UBPROC                 glSecondaryColor3ub;
extern PFNGLSECONDARYCOLOR3UBVPROC                glSecondaryColor3ubv;
extern PFNGLSECONDARYCOLOR3UIPROC                 glSecondaryColor3ui;
extern PFNGLSECONDARYCOLOR3UIVPROC                glSecondaryColor3uiv;
extern PFNGLSECONDARYCOLOR3USPROC                 glSecondaryColor3us;
extern PFNGLSECONDARYCOLOR3USVPROC                glSecondaryColor3usv;
extern PFNGLSECONDARYCOLORPOINTERPROC             glSecondaryColorPointer;
extern PFNGLWINDOWPOS2DPROC                       glWindowPos2d;
extern PFNGLWINDOWPOS2DVPROC                      glWindowPos2dv;
extern PFNGLWINDOWPOS2FPROC                       glWindowPos2f;
extern PFNGLWINDOWPOS2FVPROC                      glWindowPos2fv;
extern PFNGLWINDOWPOS2IPROC                       glWindowPos2i;
extern PFNGLWINDOWPOS2IVPROC                      glWindowPos2iv;
extern PFNGLWINDOWPOS2SPROC                       glWindowPos2s;
extern PFNGLWINDOWPOS2SVPROC                      glWindowPos2sv;
extern PFNGLWINDOWPOS3DPROC                       glWindowPos3d;
extern PFNGLWINDOWPOS3DVPROC                      glWindowPos3dv;
extern PFNGLWINDOWPOS3FPROC                       glWindowPos3f;
extern PFNGLWINDOWPOS3FVPROC                      glWindowPos3fv;
extern PFNGLWINDOWPOS3IPROC                       glWindowPos3i;
extern PFNGLWINDOWPOS3IVPROC                      glWindowPos3iv;
extern PFNGLWINDOWPOS3SPROC                       glWindowPos3s;
extern PFNGLWINDOWPOS3SVPROC                      glWindowPos3sv;

/*
 * OpenGL 1.5 API.
 */

typedef ptrdiff_t GLintptr;
typedef ptrdiff_t GLsizeiptr;

#define GL_BUFFER_SIZE                            0x8764
#define GL_BUFFER_USAGE                           0x8765
#define GL_QUERY_COUNTER_BITS                     0x8864
#define GL_CURRENT_QUERY                          0x8865
#define GL_QUERY_RESULT                           0x8866
#define GL_QUERY_RESULT_AVAILABLE                 0x8867
#define GL_ARRAY_BUFFER                           0x8892
#define GL_ELEMENT_ARRAY_BUFFER                   0x8893
#define GL_ARRAY_BUFFER_BINDING                   0x8894
#define GL_ELEMENT_ARRAY_BUFFER_BINDING           0x8895
#define GL_VERTEX_ARRAY_BUFFER_BINDING            0x8896
#define GL_NORMAL_ARRAY_BUFFER_BINDING            0x8897
#define GL_COLOR_ARRAY_BUFFER_BINDING             0x8898
#define GL_INDEX_ARRAY_BUFFER_BINDING             0x8899
#define GL_TEXTURE_COORD_ARRAY_BUFFER_BINDING     0x889A
#define GL_EDGE_FLAG_ARRAY_BUFFER_BINDING         0x889B
#define GL_SECONDARY_COLOR_ARRAY_BUFFER_BINDING   0x889C
#define GL_FOG_COORDINATE_ARRAY_BUFFER_BINDING    0x889D
#define GL_WEIGHT_ARRAY_BUFFER_BINDING            0x889E
#define GL_VERTEX_ATTRIB_ARRAY_BUFFER_BINDING     0x889F
#define GL_READ_ONLY                              0x88B8
#define GL_WRITE_ONLY                             0x88B9
#define GL_READ_WRITE                             0x88BA
#define GL_BUFFER_ACCESS                          0x88BB
#define GL_BUFFER_MAPPED                          0x88BC
#define GL_BUFFER_MAP_POINTER                     0x88BD
#define GL_STREAM_DRAW                            0x88E0
#define GL_STREAM_READ                            0x88E1
#define GL_STREAM_COPY                            0x88E2
#define GL_STATIC_DRAW                            0x88E4
#define GL_STATIC_READ                            0x88E5
#define GL_STATIC_COPY                            0x88E6
#define GL_DYNAMIC_DRAW                           0x88E8
#define GL_DYNAMIC_READ                           0x88E9
#define GL_DYNAMIC_COPY                           0x88EA
#define GL_SAMPLES_PASSED                         0x8914
#define GL_FOG_COORD_SOURCE                       GL_FOG_COORDINATE_SOURCE
#define GL_FOG_COORD                              GL_FOG_COORDINATE
#define GL_CURRENT_FOG_COORD                      GL_CURRENT_FOG_COORDINATE
#define GL_FOG_COORD_ARRAY_TYPE                   GL_FOG_COORDINATE_ARRAY_TYPE
#define GL_FOG_COORD_ARRAY_STRIDE                 GL_FOG_COORDINATE_ARRAY_STRIDE
#define GL_FOG_COORD_ARRAY_POINTER                GL_FOG_COORDINATE_ARRAY_POINTER
#define GL_FOG_COORD_ARRAY                        GL_FOG_COORDINATE_ARRAY
#define GL_FOG_COORD_ARRAY_BUFFER_BINDING         GL_FOG_COORDINATE_ARRAY_BUFFER_BINDING
#define GL_SRC0_RGB                               GL_SOURCE0_RGB
#define GL_SRC1_RGB                               GL_SOURCE1_RGB
#define GL_SRC2_RGB                               GL_SOURCE2_RGB
#define GL_SRC0_ALPHA                             GL_SOURCE0_ALPHA
#define GL_SRC1_ALPHA                             GL_SOURCE1_ALPHA
#define GL_SRC2_ALPHA                             GL_SOURCE2_ALPHA

typedef void (APIENTRY * PFNGLGENQUERIESPROC) (GLsizei n, GLuint *ids);
typedef void (APIENTRY * PFNGLDELETEQUERIESPROC) (GLsizei n, const GLuint *ids);
typedef GLboolean (APIENTRY * PFNGLISQUERYPROC) (GLuint id);
typedef void (APIENTRY * PFNGLBEGINQUERYPROC) (GLenum target, GLuint id);
typedef void (APIENTRY * PFNGLENDQUERYPROC) (GLenum target);
typedef void (APIENTRY * PFNGLGETQUERYIVPROC) (GLenum target, GLenum pname, GLint *params);
typedef void (APIENTRY * PFNGLGETQUERYOBJECTIVPROC) (GLuint id, GLenum pname, GLint *params);
typedef void (APIENTRY * PFNGLGETQUERYOBJECTUIVPROC) (GLuint id, GLenum pname, GLuint *params);
typedef void (APIENTRY * PFNGLBINDBUFFERPROC) (GLenum target, GLuint buffer);
typedef void (APIENTRY * PFNGLDELETEBUFFERSPROC) (GLsizei n, const GLuint *buffers);
typedef void (APIENTRY * PFNGLGENBUFFERSPROC) (GLsizei n, GLuint *buffers);
typedef GLboolean (APIENTRY * PFNGLISBUFFERPROC) (GLuint buffer);
typedef void (APIENTRY * PFNGLBUFFERDATAPROC) (GLenum target, GLsizeiptr size, const void *data, GLenum usage);
typedef void (APIENTRY * PFNGLBUFFERSUBDATAPROC) (GLenum target, GLintptr offset, GLsizeiptr size, const void *data);
typedef void (APIENTRY * PFNGLGETBUFFERSUBDATAPROC) (GLenum target, GLintptr offset, GLsizeiptr size, void *data);
typedef void* (APIENTRY * PFNGLMAPBUFFERPROC) (GLenum target, GLenum access);
typedef GLboolean (APIENTRY * PFNGLUNMAPBUFFERPROC) (GLenum target);
typedef void (APIENTRY * PFNGLGETBUFFERPARAMETERIVPROC) (GLenum target, GLenum pname, GLint *params);
typedef void (APIENTRY * PFNGLGETBUFFERPOINTERVPROC) (GLenum target, GLenum pname, void* *params);

extern PFNGLGENQUERIESPROC                        glGenQueries;
extern PFNGLDELETEQUERIESPROC                     glDeleteQueries;
extern PFNGLISQUERYPROC                           glIsQuery;
extern PFNGLBEGINQUERYPROC                        glBeginQuery;
extern PFNGLENDQUERYPROC                          glEndQuery;
extern PFNGLGETQUERYIVPROC                        glGetQueryiv;
extern PFNGLGETQUERYOBJECTIVPROC                  glGetQueryObjectiv;
extern PFNGLGETQUERYOBJECTUIVPROC                 glGetQueryObjectuiv;
extern PFNGLBINDBUFFERPROC                        glBindBuffer;
extern PFNGLDELETEBUFFERSPROC                     glDeleteBuffers;
extern PFNGLGENBUFFERSPROC                        glGenBuffers;
extern PFNGLISBUFFERPROC                          glIsBuffer;
extern PFNGLBUFFERDATAPROC                        glBufferData;
extern PFNGLBUFFERSUBDATAPROC                     glBufferSubData;
extern PFNGLGETBUFFERSUBDATAPROC                  glGetBufferSubData;
extern PFNGLMAPBUFFERPROC                         glMapBuffer;
extern PFNGLUNMAPBUFFERPROC                       glUnmapBuffer;
extern PFNGLGETBUFFERPARAMETERIVPROC              glGetBufferParameteriv;
extern PFNGLGETBUFFERPOINTERVPROC                 glGetBufferPointerv;

/*
 * OpenGL 2.0 API.
 */

typedef char GLchar;

#define GL_BLEND_EQUATION_RGB                     GL_BLEND_EQUATION
#define GL_VERTEX_ATTRIB_ARRAY_ENABLED            0x8622
#define GL_VERTEX_ATTRIB_ARRAY_SIZE               0x8623
#define GL_VERTEX_ATTRIB_ARRAY_STRIDE             0x8624
#define GL_VERTEX_ATTRIB_ARRAY_TYPE               0x8625
#define GL_CURRENT_VERTEX_ATTRIB                  0x8626
#define GL_VERTEX_PROGRAM_POINT_SIZE              0x8642
#define GL_VERTEX_PROGRAM_TWO_SIDE                0x8643
#define GL_VERTEX_ATTRIB_ARRAY_POINTER            0x8645
#define GL_STENCIL_BACK_FUNC                      0x8800
#define GL_STENCIL_BACK_FAIL                      0x8801
#define GL_STENCIL_BACK_PASS_DEPTH_FAIL           0x8802
#define GL_STENCIL_BACK_PASS_DEPTH_PASS           0x8803
#define GL_MAX_DRAW_BUFFERS                       0x8824
#define GL_DRAW_BUFFER0                           0x8825
#define GL_DRAW_BUFFER1                           0x8826
#define GL_DRAW_BUFFER2                           0x8827
#define GL_DRAW_BUFFER3                           0x8828
#define GL_DRAW_BUFFER4                           0x8829
#define GL_DRAW_BUFFER5                           0x882A
#define GL_DRAW_BUFFER6                           0x882B
#define GL_DRAW_BUFFER7                           0x882C
#define GL_DRAW_BUFFER8                           0x882D
#define GL_DRAW_BUFFER9                           0x882E
#define GL_DRAW_BUFFER10                          0x882F
#define GL_DRAW_BUFFER11                          0x8830
#define GL_DRAW_BUFFER12                          0x8831
#define GL_DRAW_BUFFER13                          0x8832
#define GL_DRAW_BUFFER14                          0x8833
#define GL_DRAW_BUFFER15                          0x8834
#define GL_BLEND_EQUATION_ALPHA                   0x883D
#define GL_POINT_SPRITE                           0x8861
#define GL_COORD_REPLACE                          0x8862
#define GL_MAX_VERTEX_ATTRIBS                     0x8869
#define GL_VERTEX_ATTRIB_ARRAY_NORMALIZED         0x886A
#define GL_MAX_TEXTURE_COORDS                     0x8871
#define GL_MAX_TEXTURE_IMAGE_UNITS                0x8872
#define GL_FRAGMENT_SHADER                        0x8B30
#define GL_VERTEX_SHADER                          0x8B31
#define GL_MAX_FRAGMENT_UNIFORM_COMPONENTS        0x8B49
#define GL_MAX_VERTEX_UNIFORM_COMPONENTS          0x8B4A
#define GL_MAX_VARYING_FLOATS                     0x8B4B
#define GL_MAX_VERTEX_TEXTURE_IMAGE_UNITS         0x8B4C
#define GL_MAX_COMBINED_TEXTURE_IMAGE_UNITS       0x8B4D
#define GL_SHADER_TYPE                            0x8B4F
#define GL_FLOAT_VEC2                             0x8B50
#define GL_FLOAT_VEC3                             0x8B51
#define GL_FLOAT_VEC4                             0x8B52
#define GL_INT_VEC2                               0x8B53
#define GL_INT_VEC3                               0x8B54
#define GL_INT_VEC4                               0x8B55
#define GL_BOOL                                   0x8B56
#define GL_BOOL_VEC2                              0x8B57
#define GL_BOOL_VEC3                              0x8B58
#define GL_BOOL_VEC4                              0x8B59
#define GL_FLOAT_MAT2                             0x8B5A
#define GL_FLOAT_MAT3                             0x8B5B
#define GL_FLOAT_MAT4                             0x8B5C
#define GL_SAMPLER_1D                             0x8B5D
#define GL_SAMPLER_2D                             0x8B5E
#define GL_SAMPLER_3D                             0x8B5F
#define GL_SAMPLER_CUBE                           0x8B60
#define GL_SAMPLER_1D_SHADOW                      0x8B61
#define GL_SAMPLER_2D_SHADOW                      0x8B62
#define GL_DELETE_STATUS                          0x8B80
#define GL_COMPILE_STATUS                         0x8B81
#define GL_LINK_STATUS                            0x8B82
#define GL_VALIDATE_STATUS                        0x8B83
#define GL_INFO_LOG_LENGTH                        0x8B84
#define GL_ATTACHED_SHADERS                       0x8B85
#define GL_ACTIVE_UNIFORMS                        0x8B86
#define GL_ACTIVE_UNIFORM_MAX_LENGTH              0x8B87
#define GL_SHADER_SOURCE_LENGTH                   0x8B88
#define GL_ACTIVE_ATTRIBUTES                      0x8B89
#define GL_ACTIVE_ATTRIBUTE_MAX_LENGTH            0x8B8A
#define GL_FRAGMENT_SHADER_DERIVATIVE_HINT        0x8B8B
#define GL_SHADING_LANGUAGE_VERSION               0x8B8C
#define GL_CURRENT_PROGRAM                        0x8B8D
#define GL_POINT_SPRITE_COORD_ORIGIN              0x8CA0
#define GL_LOWER_LEFT                             0x8CA1
#define GL_UPPER_LEFT                             0x8CA2
#define GL_STENCIL_BACK_REF                       0x8CA3
#define GL_STENCIL_BACK_VALUE_MASK                0x8CA4
#define GL_STENCIL_BACK_WRITEMASK                 0x8CA5

typedef void (APIENTRY * PFNGLBLENDEQUATIONSEPARATEPROC) (GLenum modeRGB, GLenum modeAlpha);
typedef void (APIENTRY * PFNGLDRAWBUFFERSPROC) (GLsizei n, const GLenum *bufs);
typedef void (APIENTRY * PFNGLSTENCILOPSEPARATEPROC) (GLenum face, GLenum sfail, GLenum dpfail, GLenum dppass);
typedef void (APIENTRY * PFNGLSTENCILFUNCSEPARATEPROC) (GLenum frontfunc, GLenum backfunc, GLint ref, GLuint mask);
typedef void (APIENTRY * PFNGLSTENCILMASKSEPARATEPROC) (GLenum face, GLuint mask);
typedef void (APIENTRY * PFNGLATTACHSHADERPROC) (GLuint program, GLuint shader);
typedef void (APIENTRY * PFNGLBINDATTRIBLOCATIONPROC) (GLuint program, GLuint index, const GLchar *name);
typedef void (APIENTRY * PFNGLCOMPILESHADERPROC) (GLuint shader);
typedef GLuint (APIENTRY * PFNGLCREATEPROGRAMPROC) (void);
typedef GLuint (APIENTRY * PFNGLCREATESHADERPROC) (GLenum type);
typedef void (APIENTRY * PFNGLDELETEPROGRAMPROC) (GLuint program);
typedef void (APIENTRY * PFNGLDELETESHADERPROC) (GLuint shader);
typedef void (APIENTRY * PFNGLDETACHSHADERPROC) (GLuint program, GLuint shader);
typedef void (APIENTRY * PFNGLDISABLEVERTEXATTRIBARRAYPROC) (GLuint index);
typedef void (APIENTRY * PFNGLENABLEVERTEXATTRIBARRAYPROC) (GLuint index);
typedef void (APIENTRY * PFNGLGETACTIVEATTRIBPROC) (GLuint program, GLuint index, GLsizei bufSize, GLsizei *length, GLint *size, GLenum *type, GLchar *name);
typedef void (APIENTRY * PFNGLGETACTIVEUNIFORMPROC) (GLuint program, GLuint index, GLsizei bufSize, GLsizei *length, GLint *size, GLenum *type, GLchar *name);
typedef void (APIENTRY * PFNGLGETATTACHEDSHADERSPROC) (GLuint program, GLsizei maxCount, GLsizei *count, GLuint *obj);
typedef GLint (APIENTRY * PFNGLGETATTRIBLOCATIONPROC) (GLuint program, const GLchar *name);
typedef void (APIENTRY * PFNGLGETPROGRAMIVPROC) (GLuint program, GLenum pname, GLint *params);
typedef void (APIENTRY * PFNGLGETPROGRAMINFOLOGPROC) (GLuint program, GLsizei bufSize, GLsizei *length, GLchar *infoLog);
typedef void (APIENTRY * PFNGLGETSHADERIVPROC) (GLuint shader, GLenum pname, GLint *params);
typedef void (APIENTRY * PFNGLGETSHADERINFOLOGPROC) (GLuint shader, GLsizei bufSize, GLsizei *length, GLchar *infoLog);
typedef void (APIENTRY * PFNGLGETSHADERSOURCEPROC) (GLuint shader, GLsizei bufSize, GLsizei *length, GLchar *source);
typedef GLint (APIENTRY * PFNGLGETUNIFORMLOCATIONPROC) (GLuint program, const GLchar *name);
typedef void (APIENTRY * PFNGLGETUNIFORMFVPROC) (GLuint program, GLint location, GLfloat *params);
typedef void (APIENTRY * PFNGLGETUNIFORMIVPROC) (GLuint program, GLint location, GLint *params);
typedef void (APIENTRY * PFNGLGETVERTEXATTRIBDVPROC) (GLuint index, GLenum pname, GLdouble *params);
typedef void (APIENTRY * PFNGLGETVERTEXATTRIBFVPROC) (GLuint index, GLenum pname, GLfloat *params);
typedef void (APIENTRY * PFNGLGETVERTEXATTRIBIVPROC) (GLuint index, GLenum pname, GLint *params);
typedef void (APIENTRY * PFNGLGETVERTEXATTRIBPOINTERVPROC) (GLuint index, GLenum pname, void* *pointer);
typedef GLboolean (APIENTRY * PFNGLISPROGRAMPROC) (GLuint program);
typedef GLboolean (APIENTRY * PFNGLISSHADERPROC) (GLuint shader);
typedef void (APIENTRY * PFNGLLINKPROGRAMPROC) (GLuint program);
typedef void (APIENTRY * PFNGLSHADERSOURCEPROC) (GLuint shader, GLsizei count, const GLchar* *string, const GLint *length);
typedef void (APIENTRY * PFNGLUSEPROGRAMPROC) (GLuint program);
typedef void (APIENTRY * PFNGLUNIFORM1FPROC) (GLint location, GLfloat v0);
typedef void (APIENTRY * PFNGLUNIFORM2FPROC) (GLint location, GLfloat v0, GLfloat v1);
typedef void (APIENTRY * PFNGLUNIFORM3FPROC) (GLint location, GLfloat v0, GLfloat v1, GLfloat v2);
typedef void (APIENTRY * PFNGLUNIFORM4FPROC) (GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3);
typedef void (APIENTRY * PFNGLUNIFORM1IPROC) (GLint location, GLint v0);
typedef void (APIENTRY * PFNGLUNIFORM2IPROC) (GLint location, GLint v0, GLint v1);
typedef void (APIENTRY * PFNGLUNIFORM3IPROC) (GLint location, GLint v0, GLint v1, GLint v2);
typedef void (APIENTRY * PFNGLUNIFORM4IPROC) (GLint location, GLint v0, GLint v1, GLint v2, GLint v3);
typedef void (APIENTRY * PFNGLUNIFORM1FVPROC) (GLint location, GLsizei count, const GLfloat *value);
typedef void (APIENTRY * PFNGLUNIFORM2FVPROC) (GLint location, GLsizei count, const GLfloat *value);
typedef void (APIENTRY * PFNGLUNIFORM3FVPROC) (GLint location, GLsizei count, const GLfloat *value);
typedef void (APIENTRY * PFNGLUNIFORM4FVPROC) (GLint location, GLsizei count, const GLfloat *value);
typedef void (APIENTRY * PFNGLUNIFORM1IVPROC) (GLint location, GLsizei count, const GLint *value);
typedef void (APIENTRY * PFNGLUNIFORM2IVPROC) (GLint location, GLsizei count, const GLint *value);
typedef void (APIENTRY * PFNGLUNIFORM3IVPROC) (GLint location, GLsizei count, const GLint *value);
typedef void (APIENTRY * PFNGLUNIFORM4IVPROC) (GLint location, GLsizei count, const GLint *value);
typedef void (APIENTRY * PFNGLUNIFORMMATRIX2FVPROC) (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
typedef void (APIENTRY * PFNGLUNIFORMMATRIX3FVPROC) (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
typedef void (APIENTRY * PFNGLUNIFORMMATRIX4FVPROC) (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
typedef void (APIENTRY * PFNGLVALIDATEPROGRAMPROC) (GLuint program);
typedef void (APIENTRY * PFNGLVERTEXATTRIB1DPROC) (GLuint index, GLdouble x);
typedef void (APIENTRY * PFNGLVERTEXATTRIB1DVPROC) (GLuint index, const GLdouble *v);
typedef void (APIENTRY * PFNGLVERTEXATTRIB1FPROC) (GLuint index, GLfloat x);
typedef void (APIENTRY * PFNGLVERTEXATTRIB1FVPROC) (GLuint index, const GLfloat *v);
typedef void (APIENTRY * PFNGLVERTEXATTRIB1SPROC) (GLuint index, GLshort x);
typedef void (APIENTRY * PFNGLVERTEXATTRIB1SVPROC) (GLuint index, const GLshort *v);
typedef void (APIENTRY * PFNGLVERTEXATTRIB2DPROC) (GLuint index, GLdouble x, GLdouble y);
typedef void (APIENTRY * PFNGLVERTEXATTRIB2DVPROC) (GLuint index, const GLdouble *v);
typedef void (APIENTRY * PFNGLVERTEXATTRIB2FPROC) (GLuint index, GLfloat x, GLfloat y);
typedef void (APIENTRY * PFNGLVERTEXATTRIB2FVPROC) (GLuint index, const GLfloat *v);
typedef void (APIENTRY * PFNGLVERTEXATTRIB2SPROC) (GLuint index, GLshort x, GLshort y);
typedef void (APIENTRY * PFNGLVERTEXATTRIB2SVPROC) (GLuint index, const GLshort *v);
typedef void (APIENTRY * PFNGLVERTEXATTRIB3DPROC) (GLuint index, GLdouble x, GLdouble y, GLdouble z);
typedef void (APIENTRY * PFNGLVERTEXATTRIB3DVPROC) (GLuint index, const GLdouble *v);
typedef void (APIENTRY * PFNGLVERTEXATTRIB3FPROC) (GLuint index, GLfloat x, GLfloat y, GLfloat z);
typedef void (APIENTRY * PFNGLVERTEXATTRIB3FVPROC) (GLuint index, const GLfloat *v);
typedef void (APIENTRY * PFNGLVERTEXATTRIB3SPROC) (GLuint index, GLshort x, GLshort y, GLshort z);
typedef void (APIENTRY * PFNGLVERTEXATTRIB3SVPROC) (GLuint index, const GLshort *v);
typedef void (APIENTRY * PFNGLVERTEXATTRIB4NBVPROC) (GLuint index, const GLbyte *v);
typedef void (APIENTRY * PFNGLVERTEXATTRIB4NIVPROC) (GLuint index, const GLint *v);
typedef void (APIENTRY * PFNGLVERTEXATTRIB4NSVPROC) (GLuint index, const GLshort *v);
typedef void (APIENTRY * PFNGLVERTEXATTRIB4NUBPROC) (GLuint index, GLubyte x, GLubyte y, GLubyte z, GLubyte w);
typedef void (APIENTRY * PFNGLVERTEXATTRIB4NUBVPROC) (GLuint index, const GLubyte *v);
typedef void (APIENTRY * PFNGLVERTEXATTRIB4NUIVPROC) (GLuint index, const GLuint *v);
typedef void (APIENTRY * PFNGLVERTEXATTRIB4NUSVPROC) (GLuint index, const GLushort *v);
typedef void (APIENTRY * PFNGLVERTEXATTRIB4BVPROC) (GLuint index, const GLbyte *v);
typedef void (APIENTRY * PFNGLVERTEXATTRIB4DPROC) (GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
typedef void (APIENTRY * PFNGLVERTEXATTRIB4DVPROC) (GLuint index, const GLdouble *v);
typedef void (APIENTRY * PFNGLVERTEXATTRIB4FPROC) (GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w);
typedef void (APIENTRY * PFNGLVERTEXATTRIB4FVPROC) (GLuint index, const GLfloat *v);
typedef void (APIENTRY * PFNGLVERTEXATTRIB4IVPROC) (GLuint index, const GLint *v);
typedef void (APIENTRY * PFNGLVERTEXATTRIB4SPROC) (GLuint index, GLshort x, GLshort y, GLshort z, GLshort w);
typedef void (APIENTRY * PFNGLVERTEXATTRIB4SVPROC) (GLuint index, const GLshort *v);
typedef void (APIENTRY * PFNGLVERTEXATTRIB4UBVPROC) (GLuint index, const GLubyte *v);
typedef void (APIENTRY * PFNGLVERTEXATTRIB4UIVPROC) (GLuint index, const GLuint *v);
typedef void (APIENTRY * PFNGLVERTEXATTRIB4USVPROC) (GLuint index, const GLushort *v);
typedef void (APIENTRY * PFNGLVERTEXATTRIBPOINTERPROC) (GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const void *pointer);

extern PFNGLBLENDEQUATIONSEPARATEPROC             glBlendEquationSeparate;
extern PFNGLDRAWBUFFERSPROC                       glDrawBuffers;
extern PFNGLSTENCILOPSEPARATEPROC                 glStencilOpSeparate;
extern PFNGLSTENCILFUNCSEPARATEPROC               glStencilFuncSeparate;
extern PFNGLSTENCILMASKSEPARATEPROC               glStencilMaskSeparate;
extern PFNGLATTACHSHADERPROC                      glAttachShader;
extern PFNGLBINDATTRIBLOCATIONPROC                glBindAttribLocation;
extern PFNGLCOMPILESHADERPROC                     glCompileShader;
extern PFNGLCREATEPROGRAMPROC                     glCreateProgram;
extern PFNGLCREATESHADERPROC                      glCreateShader;
extern PFNGLDELETEPROGRAMPROC                     glDeleteProgram;
extern PFNGLDELETESHADERPROC                      glDeleteShader;
extern PFNGLDETACHSHADERPROC                      glDetachShader;
extern PFNGLDISABLEVERTEXATTRIBARRAYPROC          glDisableVertexAttribArray;
extern PFNGLENABLEVERTEXATTRIBARRAYPROC           glEnableVertexAttribArray;
extern PFNGLGETACTIVEATTRIBPROC                   glGetActiveAttrib;
extern PFNGLGETACTIVEUNIFORMPROC                  glGetActiveUniform;
extern PFNGLGETATTACHEDSHADERSPROC                glGetAttachedShaders;
extern PFNGLGETATTRIBLOCATIONPROC                 glGetAttribLocation;
extern PFNGLGETPROGRAMIVPROC                      glGetProgramiv;
extern PFNGLGETPROGRAMINFOLOGPROC                 glGetProgramInfoLog;
extern PFNGLGETSHADERIVPROC                       glGetShaderiv;
extern PFNGLGETSHADERINFOLOGPROC                  glGetShaderInfoLog;
extern PFNGLGETSHADERSOURCEPROC                   glGetShaderSource;
extern PFNGLGETUNIFORMLOCATIONPROC                glGetUniformLocation;
extern PFNGLGETUNIFORMFVPROC                      glGetUniformfv;
extern PFNGLGETUNIFORMIVPROC                      glGetUniformiv;
extern PFNGLGETVERTEXATTRIBDVPROC                 glGetVertexAttribdv;
extern PFNGLGETVERTEXATTRIBFVPROC                 glGetVertexAttribfv;
extern PFNGLGETVERTEXATTRIBIVPROC                 glGetVertexAttribiv;
extern PFNGLGETVERTEXATTRIBPOINTERVPROC           glGetVertexAttribPointerv;
extern PFNGLISPROGRAMPROC                         glIsProgram;
extern PFNGLISSHADERPROC                          glIsShader;
extern PFNGLLINKPROGRAMPROC                       glLinkProgram;
extern PFNGLSHADERSOURCEPROC                      glShaderSource;
extern PFNGLUSEPROGRAMPROC                        glUseProgram;
extern PFNGLUNIFORM1FPROC                         glUniform1f;
extern PFNGLUNIFORM2FPROC                         glUniform2f;
extern PFNGLUNIFORM3FPROC                         glUniform3f;
extern PFNGLUNIFORM4FPROC                         glUniform4f;
extern PFNGLUNIFORM1IPROC                         glUniform1i;
extern PFNGLUNIFORM2IPROC                         glUniform2i;
extern PFNGLUNIFORM3IPROC                         glUniform3i;
extern PFNGLUNIFORM4IPROC                         glUniform4i;
extern PFNGLUNIFORM1FVPROC                        glUniform1fv;
extern PFNGLUNIFORM2FVPROC                        glUniform2fv;
extern PFNGLUNIFORM3FVPROC                        glUniform3fv;
extern PFNGLUNIFORM4FVPROC                        glUniform4fv;
extern PFNGLUNIFORM1IVPROC                        glUniform1iv;
extern PFNGLUNIFORM2IVPROC                        glUniform2iv;
extern PFNGLUNIFORM3IVPROC                        glUniform3iv;
extern PFNGLUNIFORM4IVPROC                        glUniform4iv;
extern PFNGLUNIFORMMATRIX2FVPROC                  glUniformMatrix2fv;
extern PFNGLUNIFORMMATRIX3FVPROC                  glUniformMatrix3fv;
extern PFNGLUNIFORMMATRIX4FVPROC                  glUniformMatrix4fv;
extern PFNGLVALIDATEPROGRAMPROC                   glValidateProgram;
extern PFNGLVERTEXATTRIB1DPROC                    glVertexAttrib1d;
extern PFNGLVERTEXATTRIB1DVPROC                   glVertexAttrib1dv;
extern PFNGLVERTEXATTRIB1FPROC                    glVertexAttrib1f;
extern PFNGLVERTEXATTRIB1FVPROC                   glVertexAttrib1fv;
extern PFNGLVERTEXATTRIB1SPROC                    glVertexAttrib1s;
extern PFNGLVERTEXATTRIB1SVPROC                   glVertexAttrib1sv;
extern PFNGLVERTEXATTRIB2DPROC                    glVertexAttrib2d;
extern PFNGLVERTEXATTRIB2DVPROC                   glVertexAttrib2dv;
extern PFNGLVERTEXATTRIB2FPROC                    glVertexAttrib2f;
extern PFNGLVERTEXATTRIB2FVPROC                   glVertexAttrib2fv;
extern PFNGLVERTEXATTRIB2SPROC                    glVertexAttrib2s;
extern PFNGLVERTEXATTRIB2SVPROC                   glVertexAttrib2sv;
extern PFNGLVERTEXATTRIB3DPROC                    glVertexAttrib3d;
extern PFNGLVERTEXATTRIB3DVPROC                   glVertexAttrib3dv;
extern PFNGLVERTEXATTRIB3FPROC                    glVertexAttrib3f;
extern PFNGLVERTEXATTRIB3FVPROC                   glVertexAttrib3fv;
extern PFNGLVERTEXATTRIB3SPROC                    glVertexAttrib3s;
extern PFNGLVERTEXATTRIB3SVPROC                   glVertexAttrib3sv;
extern PFNGLVERTEXATTRIB4NBVPROC                  glVertexAttrib4Nbv;
extern PFNGLVERTEXATTRIB4NIVPROC                  glVertexAttrib4Niv;
extern PFNGLVERTEXATTRIB4NSVPROC                  glVertexAttrib4Nsv;
extern PFNGLVERTEXATTRIB4NUBPROC                  glVertexAttrib4Nub;
extern PFNGLVERTEXATTRIB4NUBVPROC                 glVertexAttrib4Nubv;
extern PFNGLVERTEXATTRIB4NUIVPROC                 glVertexAttrib4Nuiv;
extern PFNGLVERTEXATTRIB4NUSVPROC                 glVertexAttrib4Nusv;
extern PFNGLVERTEXATTRIB4BVPROC                   glVertexAttrib4bv;
extern PFNGLVERTEXATTRIB4DPROC                    glVertexAttrib4d;
extern PFNGLVERTEXATTRIB4DVPROC                   glVertexAttrib4dv;
extern PFNGLVERTEXATTRIB4FPROC                    glVertexAttrib4f;
extern PFNGLVERTEXATTRIB4FVPROC                   glVertexAttrib4fv;
extern PFNGLVERTEXATTRIB4IVPROC                   glVertexAttrib4iv;
extern PFNGLVERTEXATTRIB4SPROC                    glVertexAttrib4s;
extern PFNGLVERTEXATTRIB4SVPROC                   glVertexAttrib4sv;
extern PFNGLVERTEXATTRIB4UBVPROC                  glVertexAttrib4ubv;
extern PFNGLVERTEXATTRIB4UIVPROC                  glVertexAttrib4uiv;
extern PFNGLVERTEXATTRIB4USVPROC                  glVertexAttrib4usv;
extern PFNGLVERTEXATTRIBPOINTERPROC               glVertexAttribPointer;

/*
 * GLU 1.2 API.
 */

#define GLU_VERSION                       100800
#define GLU_EXTENSIONS                    100801
#define GLU_AUTO_LOAD_MATRIX              100200
#define GLU_BEGIN                         100100
#define GLU_CCW                           100121
#define GLU_CULLING                       100201
#define GLU_CW                            100120
#define GLU_DISPLAY_MODE                  100204
#define GLU_DOMAIN_DISTANCE               100217
#define GLU_EDGE_FLAG                     100104
#define GLU_END                           100102
#define GLU_ERROR                         100103
#define GLU_EXTERIOR                      100123
#define GLU_FALSE                         0
#define GLU_FILL                          100012
#define GLU_FLAT                          100001
#define GLU_INCOMPATIBLE_GL_VERSION       100903
#define GLU_INSIDE                        100021
#define GLU_INTERIOR                      100122
#define GLU_INVALID_ENUM                  100900
#define GLU_INVALID_OPERATION             100904
#define GLU_INVALID_VALUE                 100901
#define GLU_LINE                          100011
#define GLU_MAP1_TRIM_2                   100210
#define GLU_MAP1_TRIM_3                   100211
#define GLU_NONE                          100002
#define GLU_NURBS_ERROR1                  100251
#define GLU_NURBS_ERROR10                 100260
#define GLU_NURBS_ERROR11                 100261
#define GLU_NURBS_ERROR12                 100262
#define GLU_NURBS_ERROR13                 100263
#define GLU_NURBS_ERROR14                 100264
#define GLU_NURBS_ERROR15                 100265
#define GLU_NURBS_ERROR16                 100266
#define GLU_NURBS_ERROR17                 100267
#define GLU_NURBS_ERROR18                 100268
#define GLU_NURBS_ERROR19                 100269
#define GLU_NURBS_ERROR2                  100252
#define GLU_NURBS_ERROR20                 100270
#define GLU_NURBS_ERROR21                 100271
#define GLU_NURBS_ERROR22                 100272
#define GLU_NURBS_ERROR23                 100273
#define GLU_NURBS_ERROR24                 100274
#define GLU_NURBS_ERROR25                 100275
#define GLU_NURBS_ERROR26                 100276
#define GLU_NURBS_ERROR27                 100277
#define GLU_NURBS_ERROR28                 100278
#define GLU_NURBS_ERROR29                 100279
#define GLU_NURBS_ERROR3                  100253
#define GLU_NURBS_ERROR30                 100280
#define GLU_NURBS_ERROR31                 100281
#define GLU_NURBS_ERROR32                 100282
#define GLU_NURBS_ERROR33                 100283
#define GLU_NURBS_ERROR34                 100284
#define GLU_NURBS_ERROR35                 100285
#define GLU_NURBS_ERROR36                 100286
#define GLU_NURBS_ERROR37                 100287
#define GLU_NURBS_ERROR4                  100254
#define GLU_NURBS_ERROR5                  100255
#define GLU_NURBS_ERROR6                  100256
#define GLU_NURBS_ERROR7                  100257
#define GLU_NURBS_ERROR8                  100258
#define GLU_NURBS_ERROR9                  100259
#define GLU_OUTLINE_PATCH                 100241
#define GLU_OUTLINE_POLYGON               100240
#define GLU_OUTSIDE                       100020
#define GLU_OUT_OF_MEMORY                 100902
#define GLU_PARAMETRIC_ERROR              100216
#define GLU_PARAMETRIC_TOLERANCE          100202
#define GLU_PATH_LENGTH                   100215
#define GLU_POINT                         100010
#define GLU_SAMPLING_METHOD               100205
#define GLU_SAMPLING_TOLERANCE            100203
#define GLU_SILHOUETTE                    100013
#define GLU_SMOOTH                        100000
#define GLU_TESS_BEGIN                    100100
#define GLU_TESS_BEGIN_DATA               100106
#define GLU_TESS_BOUNDARY_ONLY            100141
#define GLU_TESS_COMBINE                  100105
#define GLU_TESS_COMBINE_DATA             100111
#define GLU_TESS_COORD_TOO_LARGE          100155
#define GLU_TESS_EDGE_FLAG                100104
#define GLU_TESS_EDGE_FLAG_DATA           100110
#define GLU_TESS_END                      100102
#define GLU_TESS_END_DATA                 100108
#define GLU_TESS_ERROR                    100103
#define GLU_TESS_ERROR1                   100151
#define GLU_TESS_ERROR2                   100152
#define GLU_TESS_ERROR3                   100153
#define GLU_TESS_ERROR4                   100154
#define GLU_TESS_ERROR5                   100155
#define GLU_TESS_ERROR6                   100156
#define GLU_TESS_ERROR7                   100157
#define GLU_TESS_ERROR8                   100158
#define GLU_TESS_ERROR_DATA               100109
#define GLU_TESS_MAX_COORD               1.0e150
#define GLU_TESS_MISSING_BEGIN_CONTOUR    100152
#define GLU_TESS_MISSING_BEGIN_POLYGON    100151
#define GLU_TESS_MISSING_END_CONTOUR      100154
#define GLU_TESS_MISSING_END_POLYGON      100153
#define GLU_TESS_NEED_COMBINE_CALLBACK    100156
#define GLU_TESS_TOLERANCE                100142
#define GLU_TESS_VERTEX                   100101
#define GLU_TESS_VERTEX_DATA              100107
#define GLU_TESS_WINDING_ABS_GEQ_TWO      100134
#define GLU_TESS_WINDING_NEGATIVE         100133
#define GLU_TESS_WINDING_NONZERO          100131
#define GLU_TESS_WINDING_ODD              100130
#define GLU_TESS_WINDING_POSITIVE         100132
#define GLU_TESS_WINDING_RULE             100140
#define GLU_TRUE                          1
#define GLU_UNKNOWN                       100124
#define GLU_U_STEP                        100206
#define GLU_VERTEX                        100101
#define GLU_V_STEP                        100207
#if defined(__cplusplus)
    class GLUnurbs;
    class GLUquadric;
    class GLUtesselator;
    typedef class GLUnurbs GLUnurbsObj;
    typedef class GLUquadric GLUquadricObj;
    typedef class GLUtesselator GLUtesselatorObj;
    typedef class GLUtesselator GLUtriangulatorObj;
#else
    typedef struct GLUnurbs GLUnurbs;
    typedef struct GLUquadric GLUquadric;
    typedef struct GLUtesselator GLUtesselator;
    typedef struct GLUnurbs GLUnurbsObj;
    typedef struct GLUquadric GLUquadricObj;
    typedef struct GLUtesselator GLUtesselatorObj;
    typedef struct GLUtesselator GLUtriangulatorObj;
#endif

typedef void (APIENTRY * PFNGLUBEGINCURVEPROC) (GLUnurbs* nurb);
typedef void (APIENTRY * PFNGLUBEGINPOLYGONPROC) (GLUtesselator* tess);
typedef void (APIENTRY * PFNGLUBEGINSURFACEPROC) (GLUnurbs* nurb);
typedef void (APIENTRY * PFNGLUBEGINTRIMPROC) (GLUnurbs* nurb);
typedef GLint (APIENTRY * PFNGLUBUILD1DMIPMAPSPROC) (GLenum target, GLint component, GLsizei width, GLenum format, GLenum type, const void *data);
typedef GLint (APIENTRY * PFNGLUBUILD2DMIPMAPSPROC) (GLenum target, GLint component, GLsizei width, GLsizei height, GLenum format, GLenum type, const void *data);
typedef void (APIENTRY * PFNGLUCYLINDERPROC) (GLUquadric* quad, GLdouble base, GLdouble top, GLdouble height, GLint slices, GLint stacks);
typedef void (APIENTRY * PFNGLUDELETENURBSRENDERERPROC) (GLUnurbs* nurb);
typedef void (APIENTRY * PFNGLUDELETEQUADRICPROC) (GLUquadric* quad);
typedef void (APIENTRY * PFNGLUDELETETESSPROC) (GLUtesselator* tess);
typedef void (APIENTRY * PFNGLUDISKPROC) (GLUquadric* quad, GLdouble inner, GLdouble outer, GLint slices, GLint loops);
typedef void (APIENTRY * PFNGLUENDCURVEPROC) (GLUnurbs* nurb);
typedef void (APIENTRY * PFNGLUENDPOLYGONPROC) (GLUtesselator* tess);
typedef void (APIENTRY * PFNGLUENDSURFACEPROC) (GLUnurbs* nurb);
typedef void (APIENTRY * PFNGLUENDTRIMPROC) (GLUnurbs* nurb);
typedef const GLubyte * (APIENTRY * PFNGLUERRORSTRINGPROC) (GLenum error);
typedef void (APIENTRY * PFNGLUGETNURBSPROPERTYPROC) (GLUnurbs* nurb, GLenum property, GLfloat* data);
typedef const GLubyte * (APIENTRY * PFNGLUGETSTRINGPROC) (GLenum name);
typedef void (APIENTRY * PFNGLUGETTESSPROPERTYPROC) (GLUtesselator* tess, GLenum which, GLdouble* data);
typedef void (APIENTRY * PFNGLULOADSAMPLINGMATRICESPROC) (GLUnurbs* nurb, const GLfloat *model, const GLfloat *perspective, const GLint *view);
typedef void (APIENTRY * PFNGLULOOKATPROC) (GLdouble eyeX, GLdouble eyeY, GLdouble eyeZ, GLdouble centerX, GLdouble centerY, GLdouble centerZ, GLdouble upX, GLdouble upY, GLdouble upZ);
typedef GLUnurbs* (APIENTRY * PFNGLUNEWNURBSRENDERERPROC) (void);
typedef GLUquadric* (APIENTRY * PFNGLUNEWQUADRICPROC) (void);
typedef GLUtesselator* (APIENTRY * PFNGLUNEWTESSPROC) (void);
typedef void (APIENTRY * PFNGLUNEXTCONTOURPROC) (GLUtesselator* tess, GLenum type);
typedef void (APIENTRY * PFNGLUNURBSCALLBACKPROC) (GLUnurbs* nurb, GLenum which, void (CALLBACK *CallBackFunc)());
typedef void (APIENTRY * PFNGLUNURBSCURVEPROC) (GLUnurbs* nurb, GLint knotCount, GLfloat *knots, GLint stride, GLfloat *control, GLint order, GLenum type);
typedef void (APIENTRY * PFNGLUNURBSPROPERTYPROC) (GLUnurbs* nurb, GLenum property, GLfloat value);
typedef void (APIENTRY * PFNGLUNURBSSURFACEPROC) (GLUnurbs* nurb, GLint sKnotCount, GLfloat* sKnots, GLint tKnotCount, GLfloat* tKnots, GLint sStride, GLint tStride, GLfloat* control, GLint sOrder, GLint tOrder, GLenum type);
typedef void (APIENTRY * PFNGLUORTHO2DPROC) (GLdouble left, GLdouble right, GLdouble bottom, GLdouble top);
typedef void (APIENTRY * PFNGLUPARTIALDISKPROC) (GLUquadric* quad, GLdouble inner, GLdouble outer, GLint slices, GLint loops, GLdouble start, GLdouble sweep);
typedef void (APIENTRY * PFNGLUPERSPECTIVEPROC) (GLdouble fovy, GLdouble aspect, GLdouble zNear, GLdouble zFar);
typedef void (APIENTRY * PFNGLUPICKMATRIXPROC) (GLdouble x, GLdouble y, GLdouble delX, GLdouble delY, GLint *viewport);
typedef GLint (APIENTRY * PFNGLUPROJECTPROC) (GLdouble objX, GLdouble objY, GLdouble objZ, const GLdouble *model, const GLdouble *proj, const GLint *view, GLdouble* winX, GLdouble* winY, GLdouble* winZ);
typedef void (APIENTRY * PFNGLUPWLCURVEPROC) (GLUnurbs* nurb, GLint count, GLfloat* data, GLint stride, GLenum type);
typedef void (APIENTRY * PFNGLUQUADRICCALLBACKPROC) (GLUquadric* quad, GLenum which, void (CALLBACK *CallBackFunc)());
typedef void (APIENTRY * PFNGLUQUADRICDRAWSTYLEPROC) (GLUquadric* quad, GLenum draw);
typedef void (APIENTRY * PFNGLUQUADRICNORMALSPROC) (GLUquadric* quad, GLenum normal);
typedef void (APIENTRY * PFNGLUQUADRICORIENTATIONPROC) (GLUquadric* quad, GLenum orientation);
typedef void (APIENTRY * PFNGLUQUADRICTEXTUREPROC) (GLUquadric* quad, GLboolean texture);
typedef GLint (APIENTRY * PFNGLUSCALEIMAGEPROC) (GLenum format, GLsizei wIn, GLsizei hIn, GLenum typeIn, const void *dataIn, GLsizei wOut, GLsizei hOut, GLenum typeOut, void* dataOut);
typedef void (APIENTRY * PFNGLUSPHEREPROC) (GLUquadric* quad, GLdouble radius, GLint slices, GLint stacks);
typedef void (APIENTRY * PFNGLUTESSBEGINCONTOURPROC) (GLUtesselator* tess);
typedef void (APIENTRY * PFNGLUTESSBEGINPOLYGONPROC) (GLUtesselator* tess, void* data);
typedef void (APIENTRY * PFNGLUTESSCALLBACKPROC) (GLUtesselator* tess, GLenum which, void (CALLBACK *CallBackFunc)());
typedef void (APIENTRY * PFNGLUTESSENDCONTOURPROC) (GLUtesselator* tess);
typedef void (APIENTRY * PFNGLUTESSENDPOLYGONPROC) (GLUtesselator* tess);
typedef void (APIENTRY * PFNGLUTESSNORMALPROC) (GLUtesselator* tess, GLdouble valueX, GLdouble valueY, GLdouble valueZ);
typedef void (APIENTRY * PFNGLUTESSPROPERTYPROC) (GLUtesselator* tess, GLenum which, GLdouble data);
typedef void (APIENTRY * PFNGLUTESSVERTEXPROC) (GLUtesselator* tess, GLdouble *location, void* data);
typedef GLint (APIENTRY * PFNGLUUNPROJECTPROC) (GLdouble winX, GLdouble winY, GLdouble winZ, const GLdouble *model, const GLdouble *proj, const GLint *view, GLdouble* objX, GLdouble* objY, GLdouble* objZ);

extern PFNGLUBEGINCURVEPROC                    gluBeginCurve;
extern PFNGLUBEGINPOLYGONPROC                  gluBeginPolygon;
extern PFNGLUBEGINSURFACEPROC                  gluBeginSurface;
extern PFNGLUBEGINTRIMPROC                     gluBeginTrim;
extern PFNGLUBUILD1DMIPMAPSPROC                gluBuild1DMipmaps;
extern PFNGLUBUILD2DMIPMAPSPROC                gluBuild2DMipmaps;
extern PFNGLUCYLINDERPROC                      gluCylinder;
extern PFNGLUDELETENURBSRENDERERPROC           gluDeleteNurbsRenderer;
extern PFNGLUDELETEQUADRICPROC                 gluDeleteQuadric;
extern PFNGLUDELETETESSPROC                    gluDeleteTess;
extern PFNGLUDISKPROC                          gluDisk;
extern PFNGLUENDCURVEPROC                      gluEndCurve;
extern PFNGLUENDPOLYGONPROC                    gluEndPolygon;
extern PFNGLUENDSURFACEPROC                    gluEndSurface;
extern PFNGLUENDTRIMPROC                       gluEndTrim;
extern PFNGLUERRORSTRINGPROC                   gluErrorString;
extern PFNGLUGETNURBSPROPERTYPROC              gluGetNurbsProperty;
extern PFNGLUGETSTRINGPROC                     gluGetString;
extern PFNGLUGETTESSPROPERTYPROC               gluGetTessProperty;
extern PFNGLULOADSAMPLINGMATRICESPROC          gluLoadSamplingMatrices;
extern PFNGLULOOKATPROC                        gluLookAt;
extern PFNGLUNEWNURBSRENDERERPROC              gluNewNurbsRenderer;
extern PFNGLUNEWQUADRICPROC                    gluNewQuadric;
extern PFNGLUNEWTESSPROC                       gluNewTess;
extern PFNGLUNEXTCONTOURPROC                   gluNextContour;
extern PFNGLUNURBSCALLBACKPROC                 gluNurbsCallback;
extern PFNGLUNURBSCURVEPROC                    gluNurbsCurve;
extern PFNGLUNURBSPROPERTYPROC                 gluNurbsProperty;
extern PFNGLUNURBSSURFACEPROC                  gluNurbsSurface;
extern PFNGLUORTHO2DPROC                       gluOrtho2D;
extern PFNGLUPARTIALDISKPROC                   gluPartialDisk;
extern PFNGLUPERSPECTIVEPROC                   gluPerspective;
extern PFNGLUPICKMATRIXPROC                    gluPickMatrix;
extern PFNGLUPROJECTPROC                       gluProject;
extern PFNGLUPWLCURVEPROC                      gluPwlCurve;
extern PFNGLUQUADRICCALLBACKPROC               gluQuadricCallback;
extern PFNGLUQUADRICDRAWSTYLEPROC              gluQuadricDrawStyle;
extern PFNGLUQUADRICNORMALSPROC                gluQuadricNormals;
extern PFNGLUQUADRICORIENTATIONPROC            gluQuadricOrientation;
extern PFNGLUQUADRICTEXTUREPROC                gluQuadricTexture;
extern PFNGLUSCALEIMAGEPROC                    gluScaleImage;
extern PFNGLUSPHEREPROC                        gluSphere;
extern PFNGLUTESSBEGINCONTOURPROC              gluTessBeginContour;
extern PFNGLUTESSBEGINPOLYGONPROC              gluTessBeginPolygon;
extern PFNGLUTESSCALLBACKPROC                  gluTessCallback;
extern PFNGLUTESSENDCONTOURPROC                gluTessEndContour;
extern PFNGLUTESSENDPOLYGONPROC                gluTessEndPolygon;
extern PFNGLUTESSNORMALPROC                    gluTessNormal;
extern PFNGLUTESSPROPERTYPROC                  gluTessProperty;
extern PFNGLUTESSVERTEXPROC                    gluTessVertex;
extern PFNGLUUNPROJECTPROC                     gluUnProject;

/*
 * GLU 1.3 API.
 */

#define GLU_NURBS_BEGIN                   100164
#define GLU_NURBS_BEGIN_DATA              100170
#define GLU_NURBS_BEGIN_EXT               100164
#define GLU_NURBS_COLOR                   100167
#define GLU_NURBS_COLOR_DATA              100173
#define GLU_NURBS_COLOR_EXT               100167
#define GLU_NURBS_END                     100169
#define GLU_NURBS_END_DATA                100175
#define GLU_NURBS_ERROR                   100103
#define GLU_NURBS_MODE                    100160
#define GLU_NURBS_NORMAL                  100166
#define GLU_NURBS_NORMAL_DATA             100172
#define GLU_NURBS_RENDERER                100162
#define GLU_NURBS_TESSELLATOR             100161
#define GLU_NURBS_TEXTURE_COORD           100168
#define GLU_NURBS_TEXTURE_COORD_DATA      100174
#define GLU_NURBS_VERTEX                  100165
#define GLU_NURBS_VERTEX_DATA             100171
#define GLU_NURBS_VERTEX_EXT              100165
#define GLU_OBJECT_PARAMETRIC_ERROR       100208
#define GLU_OBJECT_PATH_LENGTH            100209

typedef GLboolean (APIENTRY *  PFNGLUCHECKEXTENSIONPROC) (const GLubyte *extName, const GLubyte *extString);
typedef GLint (APIENTRY *  PFNGLUBUILD1DMIPMAPLEVELSPROC) (GLenum target, GLint internalFormat, GLsizei width, GLenum format, GLenum type, GLint level, GLint base, GLint max, const void *data);
typedef GLint (APIENTRY *  PFNGLUBUILD2DMIPMAPLEVELSPROC) (GLenum target, GLint internalFormat, GLsizei width, GLsizei height, GLenum format, GLenum type, GLint level, GLint base, GLint max, const void *data);
typedef GLint (APIENTRY *  PFNGLUBUILD3DMIPMAPLEVELSPROC) (GLenum target, GLint internalFormat, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, GLint level, GLint base, GLint max, const void *data);
typedef GLint (APIENTRY *  PFNGLUBUILD3DMIPMAPSPROC) (GLenum target, GLint internalFormat, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const void *data);
typedef GLint (APIENTRY *  PFNGLUUNPROJECT4PROC) (GLdouble winX, GLdouble winY, GLdouble winZ, GLdouble clipW, const GLdouble *model, const GLdouble *proj, const GLint *view, GLdouble nearVal, GLdouble farVal, GLdouble* objX, GLdouble* objY, GLdouble* objZ, GLdouble* objW);
typedef void (APIENTRY *  PFNGLUNURBSCALLBACKDATAPROC) (GLUnurbs* nurb, void* userData);

extern PFNGLUCHECKEXTENSIONPROC                gluCheckExtension;
extern PFNGLUBUILD1DMIPMAPLEVELSPROC           gluBuild1DMipmapLevels;
extern PFNGLUBUILD2DMIPMAPLEVELSPROC           gluBuild2DMipmapLevels;
extern PFNGLUBUILD3DMIPMAPLEVELSPROC           gluBuild3DMipmapLevels;
extern PFNGLUBUILD3DMIPMAPSPROC                gluBuild3DMipmaps;
extern PFNGLUNURBSCALLBACKDATAPROC             gluNurbsCallbackData;
extern PFNGLUUNPROJECT4PROC                    gluUnProject4;

/*
 * GLdriver API.
 */

typedef struct
{
    HMODULE hLibGL;             /* handle to loaded GL driver             */
    HMODULE hLibGLU;            /* handle to loaded GLU driver            */
    HMODULE hLibOS;             /* handle to OS support driver            */
    LPTSTR pszExt;              /* OpenGL extension string                */
    LPTSTR pszExtWGL;           /* WGL extension string                   */
    LPTSTR pszVersionGL;        /* GL version string                      */
    LPTSTR pszVersionGLU;       /* GLU version string                     */
    LPTSTR pszVersionShader;    /* GLSL version string                    */
    LPTSTR pszRenderer;         /* GL renderer string                     */
    LPTSTR pszVendor;           /* GL vendor string                       */
    LPTSTR pszDriverName;       /* hardware manufacturer ICD file name    */
    LPTSTR pszDriverVersion;    /* hardware manufacturer ICD file version */
}  GLdriver;

/* Loads the OpenGL drivers.
 *
 * Only OpenGL 1.1 and the highest supported GLU version are loaded by this
 * function. This function is designed to load enough of the OpenGL APIs to
 * allow the creation and activation of OpenGL rendering contexts.
 *
 * Once the rendering context is created call GLdriverInit() to more fully
 * initialize the GLdriver library. This includes loading the highest supported
 * version of OpenGL.
 *
 * 'pszPathGL' is the full path to the OpenGL DLL to load.
 * This argument cannot be NULL. 
 *
 * 'pszPathGLU' is the full path to the OpenGL Utility (GLU) library
 * DLL to load. This argument is optional and can be NULL.
 */
extern GLboolean GLdriverLoad(GLdriver *pDriver, LPCTSTR pszPathGL, LPCTSTR pszPathGLU);

/* Initializes the GLdriver library.
 *
 * Initialization includes loading all of the OpenGL API entry-points (for
 * OpenGL greater than 1.1), and loading the various GLdriver structure strings.
 *
 * Call this function after a rendering context has been created and activated.
 * If this function is called before there is an active OpenGL rendering context
 * undefined behavior will result.
 */
extern void GLdriverInit(GLdriver *pDriver);

/* Unloads the OpenGL drivers and NULLs out all the function pointers to
 * the OpenGL API entry-points in the drivers. All of the strings stored in the
 * GLdriver structure are also freed here.
 */
extern void GLdriverUnload(GLdriver *pDriver);

/* Checks if the specified OpenGL Extension is supported. */
extern GLboolean GLdriverExtensionSupported(GLdriver *pDriver, LPCTSTR pszExtension);

/* These functions return the highest supported version of OpenGL, GLU, and
 * the OpenGL Shading Language. The highest supported version is returned in
 * the 'pMajor' and 'pMinor' arguments.
 */
extern void GLdriverGetGLVersion(GLdriver *pDriver, GLint *pMajor, GLint *pMinor);
extern void GLdriverGetGLUVersion(GLdriver *pDriver, GLint *pMajor, GLint *pMinor);
extern void GLdriverGetGLSLVersion(GLdriver *pDriver, GLint *pMajor, GLint *pMinor);

/* These functions determine whether the specified version of OpenGL, GLU, and
 * the OpenGL Shading Language is supported.
 */
extern GLboolean GLdriverSupportsGLVersion(GLdriver *pDriver, GLint major, GLint minor);
extern GLboolean GLdriverSupportsGLUVersion(GLdriver *pDriver, GLint major, GLint minor);
extern GLboolean GLdriverSupportsGLSLVersion(GLdriver *pDriver, GLint major, GLint minor);

#if defined(__cplusplus)
}
#endif

#endif /* !defined(GL_DRIVER_H) */