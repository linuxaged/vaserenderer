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

/* File         :   w32_infgl.cpp
 * Description  :   Win32 OpenGL Caps Loader
 *
 * Copyright (C) 1993-2001 Realtech
 *
 * Permission to use, copy, modify, distribute and sell this software
 * and its documentation for any purpose is hereby granted without fee,
 * provided that the above copyright notice appear in all copies and
 * that both that copyright notice and this permission notice appear
 * in supporting documentation.  Realtech makes no representations
 * about the suitability of this software for any purpose.
 * It is provided "as is" without express or implied warranty.
 */

#pragma comment (lib, "version.lib")    /* used in GetDriverVersion() */

#include <stdio.h>
#include "gl_driver.h"

/* Non-WGL GDI Core API Functions. */
PFNCHOOSEPIXELFORMATPROC                my_ChoosePixelFormat;
PFNDESCRIBEPIXELFORMATPROC              my_DescribePixelFormat;
PFNGETPIXELFORMATPROC                   my_GetPixelFormat;
PFNSETPIXELFORMATPROC                   my_SetPixelFormat;
PFNSWAPBUFFERSPROC                      my_SwapBuffers;

/* WGL Core API Functions. */
PFNWGLCOPYCONTEXTPROC                   my_wglCopyContext;
PFNWGLCREATECONTEXTPROC                 my_wglCreateContext;
PFNWGLCREATELAYERCONTEXTPROC            my_wglCreateLayerContext;
PFNWGLDELETECONTEXTPROC                 my_wglDeleteContext;
PFNWGLDESCRIBELAYERPLANEPROC            my_wglDescribeLayerPlane;
PFNWGLGETCURRENTCONTEXTPROC             my_wglGetCurrentContext;
PFNWGLGETCURRENTDCPROC                  my_wglGetCurrentDC;
PFNWGLGETLAYERPALETTEENTRIESPROC        my_wglGetLayerPaletteEntries;
PFNWGLGETPROCADDRESSPROC                my_wglGetProcAddress;
PFNWGLMAKECURRENTPROC                   my_wglMakeCurrent;
PFNWGLREALIZELAYERPALETTEPROC           my_wglRealizeLayerPalette;
PFNWGLSETLAYERPALETTEENTRIESPROC        my_wglSetLayerPaletteEntries;
PFNWGLSHARELISTSPROC                    my_wglShareLists;
PFNWGLSWAPLAYERBUFFERSPROC              my_wglSwapLayerBuffers;
PFNWGLUSEFONTBITMAPSAPROC               my_wglUseFontBitmapsA;
PFNWGLUSEFONTBITMAPSWPROC               my_wglUseFontBitmapsW;
PFNWGLUSEFONTOUTLINESAPROC              my_wglUseFontOutlinesA;
PFNWGLUSEFONTOUTLINESWPROC              my_wglUseFontOutlinesW;

/* OpenGL 1.1 Core API Functions. */
PFNGLACCUMPROC                          glAccum;
PFNGLALPHAFUNCPROC                      glAlphaFunc;
PFNGLARETEXTURESRESIDENTPROC            glAreTexturesResident;
PFNGLARRAYELEMENTPROC                   glArrayElement;
PFNGLBEGINPROC                          glBegin;
PFNGLBINDTEXTUREPROC                    glBindTexture;
PFNGLBITMAPPROC                         glBitmap;
PFNGLBLENDFUNCPROC                      glBlendFunc;
PFNGLCALLLISTPROC                       glCallList;
PFNGLCALLLISTSPROC                      glCallLists;
PFNGLCLEARPROC                          glClear;
PFNGLCLEARACCUMPROC                     glClearAccum;
PFNGLCLEARCOLORPROC                     glClearColor;
PFNGLCLEARDEPTHPROC                     glClearDepth;
PFNGLCLEARINDEXPROC                     glClearIndex;
PFNGLCLEARSTENCILPROC                   glClearStencil;
PFNGLCLIPPLANEPROC                      glClipPlane;
PFNGLCOLOR3BPROC                        glColor3b;
PFNGLCOLOR3BVPROC                       glColor3bv;
PFNGLCOLOR3DPROC                        glColor3d;
PFNGLCOLOR3DVPROC                       glColor3dv;
PFNGLCOLOR3FPROC                        glColor3f;
PFNGLCOLOR3FVPROC                       glColor3fv;
PFNGLCOLOR3IPROC                        glColor3i;
PFNGLCOLOR3IVPROC                       glColor3iv;
PFNGLCOLOR3SPROC                        glColor3s;
PFNGLCOLOR3SVPROC                       glColor3sv;
PFNGLCOLOR3UBPROC                       glColor3ub;
PFNGLCOLOR3UBVPROC                      glColor3ubv;
PFNGLCOLOR3UIPROC                       glColor3ui;
PFNGLCOLOR3UIVPROC                      glColor3uiv;
PFNGLCOLOR3USPROC                       glColor3us;
PFNGLCOLOR3USVPROC                      glColor3usv;
PFNGLCOLOR4BPROC                        glColor4b;
PFNGLCOLOR4BVPROC                       glColor4bv;
PFNGLCOLOR4DPROC                        glColor4d;
PFNGLCOLOR4DVPROC                       glColor4dv;
PFNGLCOLOR4FPROC                        glColor4f;
PFNGLCOLOR4FVPROC                       glColor4fv;
PFNGLCOLOR4IPROC                        glColor4i;
PFNGLCOLOR4IVPROC                       glColor4iv;
PFNGLCOLOR4SPROC                        glColor4s;
PFNGLCOLOR4SVPROC                       glColor4sv;
PFNGLCOLOR4UBPROC                       glColor4ub;
PFNGLCOLOR4UBVPROC                      glColor4ubv;
PFNGLCOLOR4UIPROC                       glColor4ui;
PFNGLCOLOR4UIVPROC                      glColor4uiv;
PFNGLCOLOR4USPROC                       glColor4us;
PFNGLCOLOR4USVPROC                      glColor4usv;
PFNGLCOLORMASKPROC                      glColorMask;
PFNGLCOLORMATERIALPROC                  glColorMaterial;
PFNGLCOLORPOINTERPROC                   glColorPointer;
PFNGLCOPYPIXELSPROC                     glCopyPixels;
PFNGLCOPYTEXIMAGE1DPROC                 glCopyTexImage1D;
PFNGLCOPYTEXIMAGE2DPROC                 glCopyTexImage2D;
PFNGLCOPYTEXSUBIMAGE1DPROC              glCopyTexSubImage1D;
PFNGLCOPYTEXSUBIMAGE2DPROC              glCopyTexSubImage2D;
PFNGLCULLFACEPROC                       glCullFace;
PFNGLDELETELISTSPROC                    glDeleteLists;
PFNGLDELETETEXTURESPROC                 glDeleteTextures;
PFNGLDEPTHFUNCPROC                      glDepthFunc;
PFNGLDEPTHMASKPROC                      glDepthMask;
PFNGLDEPTHRANGEPROC                     glDepthRange;
PFNGLDISABLEPROC                        glDisable;
PFNGLDISABLECLIENTSTATEPROC             glDisableClientState;
PFNGLDRAWARRAYSPROC                     glDrawArrays;
PFNGLDRAWBUFFERPROC                     glDrawBuffer;
PFNGLDRAWELEMENTSPROC                   glDrawElements;
PFNGLDRAWPIXELSPROC                     glDrawPixels;
PFNGLEDGEFLAGPROC                       glEdgeFlag;
PFNGLEDGEFLAGPOINTERPROC                glEdgeFlagPointer;
PFNGLEDGEFLAGVPROC                      glEdgeFlagv;
PFNGLENABLEPROC                         glEnable;
PFNGLENABLECLIENTSTATEPROC              glEnableClientState;
PFNGLENDPROC                            glEnd;
PFNGLENDLISTPROC                        glEndList;
PFNGLEVALCOORD1DPROC                    glEvalCoord1d;
PFNGLEVALCOORD1DVPROC                   glEvalCoord1dv;
PFNGLEVALCOORD1FPROC                    glEvalCoord1f;
PFNGLEVALCOORD1FVPROC                   glEvalCoord1fv;
PFNGLEVALCOORD2DPROC                    glEvalCoord2d;
PFNGLEVALCOORD2DVPROC                   glEvalCoord2dv;
PFNGLEVALCOORD2FPROC                    glEvalCoord2f;
PFNGLEVALCOORD2FVPROC                   glEvalCoord2fv;
PFNGLEVALMESH1PROC                      glEvalMesh1;
PFNGLEVALMESH2PROC                      glEvalMesh2;
PFNGLEVALPOINT1PROC                     glEvalPoint1;
PFNGLEVALPOINT2PROC                     glEvalPoint2;
PFNGLFEEDBACKBUFFERPROC                 glFeedbackBuffer;
PFNGLFINISHPROC                         glFinish;
PFNGLFLUSHPROC                          glFlush;
PFNGLFOGFPROC                           glFogf;
PFNGLFOGFVPROC                          glFogfv;
PFNGLFOGIPROC                           glFogi;
PFNGLFOGIVPROC                          glFogiv;
PFNGLFRONTFACEPROC                      glFrontFace;
PFNGLFRUSTUMPROC                        glFrustum;
PFNGLGENLISTSPROC                       glGenLists;
PFNGLGENTEXTURESPROC                    glGenTextures;
PFNGLGETBOOLEANVPROC                    glGetBooleanv;
PFNGLGETCLIPPLANEPROC                   glGetClipPlane;
PFNGLGETDOUBLEVPROC                     glGetDoublev;
PFNGLGETERRORPROC                       glGetError;
PFNGLGETFLOATVPROC                      glGetFloatv;
PFNGLGETINTEGERVPROC                    glGetIntegerv;
PFNGLGETLIGHTFVPROC                     glGetLightfv;
PFNGLGETLIGHTIVPROC                     glGetLightiv;
PFNGLGETMAPDVPROC                       glGetMapdv;
PFNGLGETMAPFVPROC                       glGetMapfv;
PFNGLGETMAPIVPROC                       glGetMapiv;
PFNGLGETMATERIALFVPROC                  glGetMaterialfv;
PFNGLGETMATERIALIVPROC                  glGetMaterialiv;
PFNGLGETPIXELMAPFVPROC                  glGetPixelMapfv;
PFNGLGETPIXELMAPUIVPROC                 glGetPixelMapuiv;
PFNGLGETPIXELMAPUSVPROC                 glGetPixelMapusv;
PFNGLGETPOINTERVPROC                    glGetPointerv;
PFNGLGETPOLYGONSTIPPLEPROC              glGetPolygonStipple;
PFNGLGETSTRINGPROC                      glGetString;
PFNGLGETTEXENVFVPROC                    glGetTexEnvfv;
PFNGLGETTEXENVIVPROC                    glGetTexEnviv;
PFNGLGETTEXGENDVPROC                    glGetTexGendv;
PFNGLGETTEXGENFVPROC                    glGetTexGenfv;
PFNGLGETTEXGENIVPROC                    glGetTexGeniv;
PFNGLGETTEXIMAGEPROC                    glGetTexImage;
PFNGLGETTEXLEVELPARAMETERFVPROC         glGetTexLevelParameterfv;
PFNGLGETTEXLEVELPARAMETERIVPROC         glGetTexLevelParameteriv;
PFNGLGETTEXPARAMETERFVPROC              glGetTexParameterfv;
PFNGLGETTEXPARAMETERIVPROC              glGetTexParameteriv;
PFNGLHINTPROC                           glHint;
PFNGLINDEXMASKPROC                      glIndexMask;
PFNGLINDEXPOINTERPROC                   glIndexPointer;
PFNGLINDEXDPROC                         glIndexd;
PFNGLINDEXDVPROC                        glIndexdv;
PFNGLINDEXFPROC                         glIndexf;
PFNGLINDEXFVPROC                        glIndexfv;
PFNGLINDEXIPROC                         glIndexi;
PFNGLINDEXIVPROC                        glIndexiv;
PFNGLINDEXSPROC                         glIndexs;
PFNGLINDEXSVPROC                        glIndexsv;
PFNGLINDEXUBPROC                        glIndexub;
PFNGLINDEXUBVPROC                       glIndexubv;
PFNGLINITNAMESPROC                      glInitNames;
PFNGLINTERLEAVEDARRAYSPROC              glInterleavedArrays;
PFNGLISENABLEDPROC                      glIsEnabled;
PFNGLISLISTPROC                         glIsList;
PFNGLISTEXTUREPROC                      glIsTexture;
PFNGLLIGHTMODELFPROC                    glLightModelf;
PFNGLLIGHTMODELFVPROC                   glLightModelfv;
PFNGLLIGHTMODELIPROC                    glLightModeli;
PFNGLLIGHTMODELIVPROC                   glLightModeliv;
PFNGLLIGHTFPROC                         glLightf;
PFNGLLIGHTFVPROC                        glLightfv;
PFNGLLIGHTIPROC                         glLighti;
PFNGLLIGHTIVPROC                        glLightiv;
PFNGLLINESTIPPLEPROC                    glLineStipple;
PFNGLLINEWIDTHPROC                      glLineWidth;
PFNGLLISTBASEPROC                       glListBase;
PFNGLLOADIDENTITYPROC                   glLoadIdentity;
PFNGLLOADMATRIXDPROC                    glLoadMatrixd;
PFNGLLOADMATRIXFPROC                    glLoadMatrixf;
PFNGLLOADNAMEPROC                       glLoadName;
PFNGLLOGICOPPROC                        glLogicOp;
PFNGLMAP1DPROC                          glMap1d;
PFNGLMAP1FPROC                          glMap1f;
PFNGLMAP2DPROC                          glMap2d;
PFNGLMAP2FPROC                          glMap2f;
PFNGLMAPGRID1DPROC                      glMapGrid1d;
PFNGLMAPGRID1FPROC                      glMapGrid1f;
PFNGLMAPGRID2DPROC                      glMapGrid2d;
PFNGLMAPGRID2FPROC                      glMapGrid2f;
PFNGLMATERIALFPROC                      glMaterialf;
PFNGLMATERIALFVPROC                     glMaterialfv;
PFNGLMATERIALIPROC                      glMateriali;
PFNGLMATERIALIVPROC                     glMaterialiv;
PFNGLMATRIXMODEPROC                     glMatrixMode;
PFNGLMULTMATRIXDPROC                    glMultMatrixd;
PFNGLMULTMATRIXFPROC                    glMultMatrixf;
PFNGLNEWLISTPROC                        glNewList;
PFNGLNORMAL3BPROC                       glNormal3b;
PFNGLNORMAL3BVPROC                      glNormal3bv;
PFNGLNORMAL3DPROC                       glNormal3d;
PFNGLNORMAL3DVPROC                      glNormal3dv;
PFNGLNORMAL3FPROC                       glNormal3f;
PFNGLNORMAL3FVPROC                      glNormal3fv;
PFNGLNORMAL3IPROC                       glNormal3i;
PFNGLNORMAL3IVPROC                      glNormal3iv;
PFNGLNORMAL3SPROC                       glNormal3s;
PFNGLNORMAL3SVPROC                      glNormal3sv;
PFNGLNORMALPOINTERPROC                  glNormalPointer;
PFNGLORTHOPROC                          glOrtho;
PFNGLPASSTHROUGHPROC                    glPassThrough;
PFNGLPIXELMAPFVPROC                     glPixelMapfv;
PFNGLPIXELMAPUIVPROC                    glPixelMapuiv;
PFNGLPIXELMAPUSVPROC                    glPixelMapusv;
PFNGLPIXELSTOREFPROC                    glPixelStoref;
PFNGLPIXELSTOREIPROC                    glPixelStorei;
PFNGLPIXELTRANSFERFPROC                 glPixelTransferf;
PFNGLPIXELTRANSFERIPROC                 glPixelTransferi;
PFNGLPIXELZOOMPROC                      glPixelZoom;
PFNGLPOINTSIZEPROC                      glPointSize;
PFNGLPOLYGONMODEPROC                    glPolygonMode;
PFNGLPOLYGONOFFSETPROC                  glPolygonOffset;
PFNGLPOLYGONSTIPPLEPROC                 glPolygonStipple;
PFNGLPOPATTRIBPROC                      glPopAttrib;
PFNGLPOPCLIENTATTRIBPROC                glPopClientAttrib;
PFNGLPOPMATRIXPROC                      glPopMatrix;
PFNGLPOPNAMEPROC                        glPopName;
PFNGLPRIORITIZETEXTURESPROC             glPrioritizeTextures;
PFNGLPUSHATTRIBPROC                     glPushAttrib;
PFNGLPUSHCLIENTATTRIBPROC               glPushClientAttrib;
PFNGLPUSHMATRIXPROC                     glPushMatrix;
PFNGLPUSHNAMEPROC                       glPushName;
PFNGLRASTERPOS2DPROC                    glRasterPos2d;
PFNGLRASTERPOS2DVPROC                   glRasterPos2dv;
PFNGLRASTERPOS2FPROC                    glRasterPos2f;
PFNGLRASTERPOS2FVPROC                   glRasterPos2fv;
PFNGLRASTERPOS2IPROC                    glRasterPos2i;
PFNGLRASTERPOS2IVPROC                   glRasterPos2iv;
PFNGLRASTERPOS2SPROC                    glRasterPos2s;
PFNGLRASTERPOS2SVPROC                   glRasterPos2sv;
PFNGLRASTERPOS3DPROC                    glRasterPos3d;
PFNGLRASTERPOS3DVPROC                   glRasterPos3dv;
PFNGLRASTERPOS3FPROC                    glRasterPos3f;
PFNGLRASTERPOS3FVPROC                   glRasterPos3fv;
PFNGLRASTERPOS3IPROC                    glRasterPos3i;
PFNGLRASTERPOS3IVPROC                   glRasterPos3iv;
PFNGLRASTERPOS3SPROC                    glRasterPos3s;
PFNGLRASTERPOS3SVPROC                   glRasterPos3sv;
PFNGLRASTERPOS4DPROC                    glRasterPos4d;
PFNGLRASTERPOS4DVPROC                   glRasterPos4dv;
PFNGLRASTERPOS4FPROC                    glRasterPos4f;
PFNGLRASTERPOS4FVPROC                   glRasterPos4fv;
PFNGLRASTERPOS4IPROC                    glRasterPos4i;
PFNGLRASTERPOS4IVPROC                   glRasterPos4iv;
PFNGLRASTERPOS4SPROC                    glRasterPos4s;
PFNGLRASTERPOS4SVPROC                   glRasterPos4sv;
PFNGLREADBUFFERPROC                     glReadBuffer;
PFNGLREADPIXELSPROC                     glReadPixels;
PFNGLRECTDPROC                          glRectd;
PFNGLRECTDVPROC                         glRectdv;
PFNGLRECTFPROC                          glRectf;
PFNGLRECTFVPROC                         glRectfv;
PFNGLRECTIPROC                          glRecti;
PFNGLRECTIVPROC                         glRectiv;
PFNGLRECTSPROC                          glRects;
PFNGLRECTSVPROC                         glRectsv;
PFNGLRENDERMODEPROC                     glRenderMode;
PFNGLROTATEDPROC                        glRotated;
PFNGLROTATEFPROC                        glRotatef;
PFNGLSCALEDPROC                         glScaled;
PFNGLSCALEFPROC                         glScalef;
PFNGLSCISSORPROC                        glScissor;
PFNGLSELECTBUFFERPROC                   glSelectBuffer;
PFNGLSHADEMODELPROC                     glShadeModel;
PFNGLSTENCILFUNCPROC                    glStencilFunc;
PFNGLSTENCILMASKPROC                    glStencilMask;
PFNGLSTENCILOPPROC                      glStencilOp;
PFNGLTEXCOORD1DPROC                     glTexCoord1d;
PFNGLTEXCOORD1DVPROC                    glTexCoord1dv;
PFNGLTEXCOORD1FPROC                     glTexCoord1f;
PFNGLTEXCOORD1FVPROC                    glTexCoord1fv;
PFNGLTEXCOORD1IPROC                     glTexCoord1i;
PFNGLTEXCOORD1IVPROC                    glTexCoord1iv;
PFNGLTEXCOORD1SPROC                     glTexCoord1s;
PFNGLTEXCOORD1SVPROC                    glTexCoord1sv;
PFNGLTEXCOORD2DPROC                     glTexCoord2d;
PFNGLTEXCOORD2DVPROC                    glTexCoord2dv;
PFNGLTEXCOORD2FPROC                     glTexCoord2f;
PFNGLTEXCOORD2FVPROC                    glTexCoord2fv;
PFNGLTEXCOORD2IPROC                     glTexCoord2i;
PFNGLTEXCOORD2IVPROC                    glTexCoord2iv;
PFNGLTEXCOORD2SPROC                     glTexCoord2s;
PFNGLTEXCOORD2SVPROC                    glTexCoord2sv;
PFNGLTEXCOORD3DPROC                     glTexCoord3d;
PFNGLTEXCOORD3DVPROC                    glTexCoord3dv;
PFNGLTEXCOORD3FPROC                     glTexCoord3f;
PFNGLTEXCOORD3FVPROC                    glTexCoord3fv;
PFNGLTEXCOORD3IPROC                     glTexCoord3i;
PFNGLTEXCOORD3IVPROC                    glTexCoord3iv;
PFNGLTEXCOORD3SPROC                     glTexCoord3s;
PFNGLTEXCOORD3SVPROC                    glTexCoord3sv;
PFNGLTEXCOORD4DPROC                     glTexCoord4d;
PFNGLTEXCOORD4DVPROC                    glTexCoord4dv;
PFNGLTEXCOORD4FPROC                     glTexCoord4f;
PFNGLTEXCOORD4FVPROC                    glTexCoord4fv;
PFNGLTEXCOORD4IPROC                     glTexCoord4i;
PFNGLTEXCOORD4IVPROC                    glTexCoord4iv;
PFNGLTEXCOORD4SPROC                     glTexCoord4s;
PFNGLTEXCOORD4SVPROC                    glTexCoord4sv;
PFNGLTEXCOORDPOINTERPROC                glTexCoordPointer;
PFNGLTEXENVFPROC                        glTexEnvf;
PFNGLTEXENVFVPROC                       glTexEnvfv;
PFNGLTEXENVIPROC                        glTexEnvi;
PFNGLTEXENVIVPROC                       glTexEnviv;
PFNGLTEXGENDPROC                        glTexGend;
PFNGLTEXGENDVPROC                       glTexGendv;
PFNGLTEXGENFPROC                        glTexGenf;
PFNGLTEXGENFVPROC                       glTexGenfv;
PFNGLTEXGENIPROC                        glTexGeni;
PFNGLTEXGENIVPROC                       glTexGeniv;
PFNGLTEXIMAGE1DPROC                     glTexImage1D;
PFNGLTEXIMAGE2DPROC                     glTexImage2D;
PFNGLTEXPARAMETERFPROC                  glTexParameterf;
PFNGLTEXPARAMETERFVPROC                 glTexParameterfv;
PFNGLTEXPARAMETERIPROC                  glTexParameteri;
PFNGLTEXPARAMETERIVPROC                 glTexParameteriv;
PFNGLTEXSUBIMAGE1DPROC                  glTexSubImage1D;
PFNGLTEXSUBIMAGE2DPROC                  glTexSubImage2D;
PFNGLTRANSLATEDPROC                     glTranslated;
PFNGLTRANSLATEFPROC                     glTranslatef;
PFNGLVERTEX2DPROC                       glVertex2d;
PFNGLVERTEX2DVPROC                      glVertex2dv;
PFNGLVERTEX2FPROC                       glVertex2f;
PFNGLVERTEX2FVPROC                      glVertex2fv;
PFNGLVERTEX2IPROC                       glVertex2i;
PFNGLVERTEX2IVPROC                      glVertex2iv;
PFNGLVERTEX2SPROC                       glVertex2s;
PFNGLVERTEX2SVPROC                      glVertex2sv;
PFNGLVERTEX3DPROC                       glVertex3d;
PFNGLVERTEX3DVPROC                      glVertex3dv;
PFNGLVERTEX3FPROC                       glVertex3f;
PFNGLVERTEX3FVPROC                      glVertex3fv;
PFNGLVERTEX3IPROC                       glVertex3i;
PFNGLVERTEX3IVPROC                      glVertex3iv;
PFNGLVERTEX3SPROC                       glVertex3s;
PFNGLVERTEX3SVPROC                      glVertex3sv;
PFNGLVERTEX4DPROC                       glVertex4d;
PFNGLVERTEX4DVPROC                      glVertex4dv;
PFNGLVERTEX4FPROC                       glVertex4f;
PFNGLVERTEX4FVPROC                      glVertex4fv;
PFNGLVERTEX4IPROC                       glVertex4i;
PFNGLVERTEX4IVPROC                      glVertex4iv;
PFNGLVERTEX4SPROC                       glVertex4s;
PFNGLVERTEX4SVPROC                      glVertex4sv;
PFNGLVERTEXPOINTERPROC                  glVertexPointer;
PFNGLVIEWPORTPROC                       glViewport;

/* OpenGL 1.2 Core API Functions. */
PFNGLCOPYTEXSUBIMAGE3DPROC              glCopyTexSubImage3D;
PFNGLDRAWRANGEELEMENTSPROC              glDrawRangeElements;
PFNGLTEXIMAGE3DPROC                     glTexImage3D;
PFNGLTEXSUBIMAGE3DPROC                  glTexSubImage3D;

/* OpenGL 1.3 Core API Functions. */
PFNGLACTIVETEXTUREPROC                  glActiveTexture;
PFNGLCLIENTACTIVETEXTUREPROC            glClientActiveTexture;
PFNGLCOMPRESSEDTEXIMAGE1DPROC           glCompressedTexImage1D;
PFNGLCOMPRESSEDTEXIMAGE2DPROC           glCompressedTexImage2D;
PFNGLCOMPRESSEDTEXIMAGE3DPROC           glCompressedTexImage3D;
PFNGLCOMPRESSEDTEXSUBIMAGE1DPROC        glCompressedTexSubImage1D;
PFNGLCOMPRESSEDTEXSUBIMAGE2DPROC        glCompressedTexSubImage2D;
PFNGLCOMPRESSEDTEXSUBIMAGE3DPROC        glCompressedTexSubImage3D;
PFNGLGETCOMPRESSEDTEXIMAGEPROC          glGetCompressedTexImage;
PFNGLLOADTRANSPOSEMATRIXDPROC           glLoadTransposeMatrixd;
PFNGLLOADTRANSPOSEMATRIXFPROC           glLoadTransposeMatrixf;
PFNGLMULTITEXCOORD1DPROC                glMultiTexCoord1d;
PFNGLMULTITEXCOORD1DVPROC               glMultiTexCoord1dv;
PFNGLMULTITEXCOORD1FPROC                glMultiTexCoord1f;
PFNGLMULTITEXCOORD1FVPROC               glMultiTexCoord1fv;
PFNGLMULTITEXCOORD1IPROC                glMultiTexCoord1i;
PFNGLMULTITEXCOORD1IVPROC               glMultiTexCoord1iv;
PFNGLMULTITEXCOORD1SPROC                glMultiTexCoord1s;
PFNGLMULTITEXCOORD1SVPROC               glMultiTexCoord1sv;
PFNGLMULTITEXCOORD2DPROC                glMultiTexCoord2d;
PFNGLMULTITEXCOORD2DVPROC               glMultiTexCoord2dv;
PFNGLMULTITEXCOORD2FPROC                glMultiTexCoord2f;
PFNGLMULTITEXCOORD2FVPROC               glMultiTexCoord2fv;
PFNGLMULTITEXCOORD2IPROC                glMultiTexCoord2i;
PFNGLMULTITEXCOORD2IVPROC               glMultiTexCoord2iv;
PFNGLMULTITEXCOORD2SPROC                glMultiTexCoord2s;
PFNGLMULTITEXCOORD2SVPROC               glMultiTexCoord2sv;
PFNGLMULTITEXCOORD3DPROC                glMultiTexCoord3d;
PFNGLMULTITEXCOORD3DVPROC               glMultiTexCoord3dv;
PFNGLMULTITEXCOORD3FPROC                glMultiTexCoord3f;
PFNGLMULTITEXCOORD3FVPROC               glMultiTexCoord3fv;
PFNGLMULTITEXCOORD3IPROC                glMultiTexCoord3i;
PFNGLMULTITEXCOORD3IVPROC               glMultiTexCoord3iv;
PFNGLMULTITEXCOORD3SPROC                glMultiTexCoord3s;
PFNGLMULTITEXCOORD3SVPROC               glMultiTexCoord3sv;
PFNGLMULTITEXCOORD4DPROC                glMultiTexCoord4d;
PFNGLMULTITEXCOORD4DVPROC               glMultiTexCoord4dv;
PFNGLMULTITEXCOORD4FPROC                glMultiTexCoord4f;
PFNGLMULTITEXCOORD4FVPROC               glMultiTexCoord4fv;
PFNGLMULTITEXCOORD4IPROC                glMultiTexCoord4i;
PFNGLMULTITEXCOORD4IVPROC               glMultiTexCoord4iv;
PFNGLMULTITEXCOORD4SPROC                glMultiTexCoord4s;
PFNGLMULTITEXCOORD4SVPROC               glMultiTexCoord4sv;
PFNGLMULTTRANSPOSEMATRIXDPROC           glMultTransposeMatrixd;
PFNGLMULTTRANSPOSEMATRIXFPROC           glMultTransposeMatrixf;
PFNGLSAMPLECOVERAGEPROC                 glSampleCoverage;

/* OpenGL 1.4 Core API Functions. */
PFNGLBLENDFUNCSEPARATEPROC              glBlendFuncSeparate;
PFNGLMULTIDRAWARRAYSPROC                glMultiDrawArrays;
PFNGLMULTIDRAWELEMENTSPROC              glMultiDrawElements;
PFNGLPOINTPARAMETERFPROC                glPointParameterf;
PFNGLPOINTPARAMETERFVPROC               glPointParameterfv;
PFNGLSECONDARYCOLOR3BPROC               glSecondaryColor3b;
PFNGLSECONDARYCOLOR3BVPROC              glSecondaryColor3bv;
PFNGLSECONDARYCOLOR3DPROC               glSecondaryColor3d;
PFNGLSECONDARYCOLOR3DVPROC              glSecondaryColor3dv;
PFNGLSECONDARYCOLOR3FPROC               glSecondaryColor3f;
PFNGLSECONDARYCOLOR3FVPROC              glSecondaryColor3fv;
PFNGLSECONDARYCOLOR3IPROC               glSecondaryColor3i;
PFNGLSECONDARYCOLOR3IVPROC              glSecondaryColor3iv;
PFNGLSECONDARYCOLOR3SPROC               glSecondaryColor3s;
PFNGLSECONDARYCOLOR3SVPROC              glSecondaryColor3sv;
PFNGLSECONDARYCOLOR3UBPROC              glSecondaryColor3ub;
PFNGLSECONDARYCOLOR3UBVPROC             glSecondaryColor3ubv;
PFNGLSECONDARYCOLOR3UIPROC              glSecondaryColor3ui;
PFNGLSECONDARYCOLOR3UIVPROC             glSecondaryColor3uiv;
PFNGLSECONDARYCOLOR3USPROC              glSecondaryColor3us;
PFNGLSECONDARYCOLOR3USVPROC             glSecondaryColor3usv;
PFNGLSECONDARYCOLORPOINTERPROC          glSecondaryColorPointer;
PFNGLWINDOWPOS2DPROC                    glWindowPos2d;
PFNGLWINDOWPOS2DVPROC                   glWindowPos2dv;
PFNGLWINDOWPOS2FPROC                    glWindowPos2f;
PFNGLWINDOWPOS2FVPROC                   glWindowPos2fv;
PFNGLWINDOWPOS2IPROC                    glWindowPos2i;
PFNGLWINDOWPOS2IVPROC                   glWindowPos2iv;
PFNGLWINDOWPOS2SPROC                    glWindowPos2s;
PFNGLWINDOWPOS2SVPROC                   glWindowPos2sv;
PFNGLWINDOWPOS3DPROC                    glWindowPos3d;
PFNGLWINDOWPOS3DVPROC                   glWindowPos3dv;
PFNGLWINDOWPOS3FPROC                    glWindowPos3f;
PFNGLWINDOWPOS3FVPROC                   glWindowPos3fv;
PFNGLWINDOWPOS3IPROC                    glWindowPos3i;
PFNGLWINDOWPOS3IVPROC                   glWindowPos3iv;
PFNGLWINDOWPOS3SPROC                    glWindowPos3s;
PFNGLWINDOWPOS3SVPROC                   glWindowPos3sv;

/* OpenGL 1.5 Core API Functions. */
PFNGLGENQUERIESPROC                     glGenQueries;
PFNGLDELETEQUERIESPROC                  glDeleteQueries;
PFNGLISQUERYPROC                        glIsQuery;
PFNGLBEGINQUERYPROC                     glBeginQuery;
PFNGLENDQUERYPROC                       glEndQuery;
PFNGLGETQUERYIVPROC                     glGetQueryiv;
PFNGLGETQUERYOBJECTIVPROC               glGetQueryObjectiv;
PFNGLGETQUERYOBJECTUIVPROC              glGetQueryObjectuiv;
PFNGLBINDBUFFERPROC                     glBindBuffer;
PFNGLDELETEBUFFERSPROC                  glDeleteBuffers;
PFNGLGENBUFFERSPROC                     glGenBuffers;
PFNGLISBUFFERPROC                       glIsBuffer;
PFNGLBUFFERDATAPROC                     glBufferData;
PFNGLBUFFERSUBDATAPROC                  glBufferSubData;
PFNGLGETBUFFERSUBDATAPROC               glGetBufferSubData;
PFNGLMAPBUFFERPROC                      glMapBuffer;
PFNGLUNMAPBUFFERPROC                    glUnmapBuffer;
PFNGLGETBUFFERPARAMETERIVPROC           glGetBufferParameteriv;
PFNGLGETBUFFERPOINTERVPROC              glGetBufferPointerv;

/* OpenGL 2.0 Core API Functions. */
PFNGLBLENDEQUATIONSEPARATEPROC          glBlendEquationSeparate;
PFNGLDRAWBUFFERSPROC                    glDrawBuffers;
PFNGLSTENCILOPSEPARATEPROC              glStencilOpSeparate;
PFNGLSTENCILFUNCSEPARATEPROC            glStencilFuncSeparate;
PFNGLSTENCILMASKSEPARATEPROC            glStencilMaskSeparate;
PFNGLATTACHSHADERPROC                   glAttachShader;
PFNGLBINDATTRIBLOCATIONPROC             glBindAttribLocation;
PFNGLCOMPILESHADERPROC                  glCompileShader;
PFNGLCREATEPROGRAMPROC                  glCreateProgram;
PFNGLCREATESHADERPROC                   glCreateShader;
PFNGLDELETEPROGRAMPROC                  glDeleteProgram;
PFNGLDELETESHADERPROC                   glDeleteShader;
PFNGLDETACHSHADERPROC                   glDetachShader;
PFNGLDISABLEVERTEXATTRIBARRAYPROC       glDisableVertexAttribArray;
PFNGLENABLEVERTEXATTRIBARRAYPROC        glEnableVertexAttribArray;
PFNGLGETACTIVEATTRIBPROC                glGetActiveAttrib;
PFNGLGETACTIVEUNIFORMPROC               glGetActiveUniform;
PFNGLGETATTACHEDSHADERSPROC             glGetAttachedShaders;
PFNGLGETATTRIBLOCATIONPROC              glGetAttribLocation;
PFNGLGETPROGRAMIVPROC                   glGetProgramiv;
PFNGLGETPROGRAMINFOLOGPROC              glGetProgramInfoLog;
PFNGLGETSHADERIVPROC                    glGetShaderiv;
PFNGLGETSHADERINFOLOGPROC               glGetShaderInfoLog;
PFNGLGETSHADERSOURCEPROC                glGetShaderSource;
PFNGLGETUNIFORMLOCATIONPROC             glGetUniformLocation;
PFNGLGETUNIFORMFVPROC                   glGetUniformfv;
PFNGLGETUNIFORMIVPROC                   glGetUniformiv;
PFNGLGETVERTEXATTRIBDVPROC              glGetVertexAttribdv;
PFNGLGETVERTEXATTRIBFVPROC              glGetVertexAttribfv;
PFNGLGETVERTEXATTRIBIVPROC              glGetVertexAttribiv;
PFNGLGETVERTEXATTRIBPOINTERVPROC        glGetVertexAttribPointerv;
PFNGLISPROGRAMPROC                      glIsProgram;
PFNGLISSHADERPROC                       glIsShader;
PFNGLLINKPROGRAMPROC                    glLinkProgram;
PFNGLSHADERSOURCEPROC                   glShaderSource;
PFNGLUSEPROGRAMPROC                     glUseProgram;
PFNGLUNIFORM1FPROC                      glUniform1f;
PFNGLUNIFORM2FPROC                      glUniform2f;
PFNGLUNIFORM3FPROC                      glUniform3f;
PFNGLUNIFORM4FPROC                      glUniform4f;
PFNGLUNIFORM1IPROC                      glUniform1i;
PFNGLUNIFORM2IPROC                      glUniform2i;
PFNGLUNIFORM3IPROC                      glUniform3i;
PFNGLUNIFORM4IPROC                      glUniform4i;
PFNGLUNIFORM1FVPROC                     glUniform1fv;
PFNGLUNIFORM2FVPROC                     glUniform2fv;
PFNGLUNIFORM3FVPROC                     glUniform3fv;
PFNGLUNIFORM4FVPROC                     glUniform4fv;
PFNGLUNIFORM1IVPROC                     glUniform1iv;
PFNGLUNIFORM2IVPROC                     glUniform2iv;
PFNGLUNIFORM3IVPROC                     glUniform3iv;
PFNGLUNIFORM4IVPROC                     glUniform4iv;
PFNGLUNIFORMMATRIX2FVPROC               glUniformMatrix2fv;
PFNGLUNIFORMMATRIX3FVPROC               glUniformMatrix3fv;
PFNGLUNIFORMMATRIX4FVPROC               glUniformMatrix4fv;
PFNGLVALIDATEPROGRAMPROC                glValidateProgram;
PFNGLVERTEXATTRIB1DPROC                 glVertexAttrib1d;
PFNGLVERTEXATTRIB1DVPROC                glVertexAttrib1dv;
PFNGLVERTEXATTRIB1FPROC                 glVertexAttrib1f;
PFNGLVERTEXATTRIB1FVPROC                glVertexAttrib1fv;
PFNGLVERTEXATTRIB1SPROC                 glVertexAttrib1s;
PFNGLVERTEXATTRIB1SVPROC                glVertexAttrib1sv;
PFNGLVERTEXATTRIB2DPROC                 glVertexAttrib2d;
PFNGLVERTEXATTRIB2DVPROC                glVertexAttrib2dv;
PFNGLVERTEXATTRIB2FPROC                 glVertexAttrib2f;
PFNGLVERTEXATTRIB2FVPROC                glVertexAttrib2fv;
PFNGLVERTEXATTRIB2SPROC                 glVertexAttrib2s;
PFNGLVERTEXATTRIB2SVPROC                glVertexAttrib2sv;
PFNGLVERTEXATTRIB3DPROC                 glVertexAttrib3d;
PFNGLVERTEXATTRIB3DVPROC                glVertexAttrib3dv;
PFNGLVERTEXATTRIB3FPROC                 glVertexAttrib3f;
PFNGLVERTEXATTRIB3FVPROC                glVertexAttrib3fv;
PFNGLVERTEXATTRIB3SPROC                 glVertexAttrib3s;
PFNGLVERTEXATTRIB3SVPROC                glVertexAttrib3sv;
PFNGLVERTEXATTRIB4NBVPROC               glVertexAttrib4Nbv;
PFNGLVERTEXATTRIB4NIVPROC               glVertexAttrib4Niv;
PFNGLVERTEXATTRIB4NSVPROC               glVertexAttrib4Nsv;
PFNGLVERTEXATTRIB4NUBPROC               glVertexAttrib4Nub;
PFNGLVERTEXATTRIB4NUBVPROC              glVertexAttrib4Nubv;
PFNGLVERTEXATTRIB4NUIVPROC              glVertexAttrib4Nuiv;
PFNGLVERTEXATTRIB4NUSVPROC              glVertexAttrib4Nusv;
PFNGLVERTEXATTRIB4BVPROC                glVertexAttrib4bv;
PFNGLVERTEXATTRIB4DPROC                 glVertexAttrib4d;
PFNGLVERTEXATTRIB4DVPROC                glVertexAttrib4dv;
PFNGLVERTEXATTRIB4FPROC                 glVertexAttrib4f;
PFNGLVERTEXATTRIB4FVPROC                glVertexAttrib4fv;
PFNGLVERTEXATTRIB4IVPROC                glVertexAttrib4iv;
PFNGLVERTEXATTRIB4SPROC                 glVertexAttrib4s;
PFNGLVERTEXATTRIB4SVPROC                glVertexAttrib4sv;
PFNGLVERTEXATTRIB4UBVPROC               glVertexAttrib4ubv;
PFNGLVERTEXATTRIB4UIVPROC               glVertexAttrib4uiv;
PFNGLVERTEXATTRIB4USVPROC               glVertexAttrib4usv;
PFNGLVERTEXATTRIBPOINTERPROC            glVertexAttribPointer;

/* GLU 1.2 Core API Functions. */
PFNGLUBEGINCURVEPROC                    gluBeginCurve;
PFNGLUBEGINPOLYGONPROC                  gluBeginPolygon;
PFNGLUBEGINSURFACEPROC                  gluBeginSurface;
PFNGLUBEGINTRIMPROC                     gluBeginTrim;
PFNGLUBUILD1DMIPMAPSPROC                gluBuild1DMipmaps;
PFNGLUBUILD2DMIPMAPSPROC                gluBuild2DMipmaps;
PFNGLUCYLINDERPROC                      gluCylinder;
PFNGLUDELETENURBSRENDERERPROC           gluDeleteNurbsRenderer;
PFNGLUDELETEQUADRICPROC                 gluDeleteQuadric;
PFNGLUDELETETESSPROC                    gluDeleteTess;
PFNGLUDISKPROC                          gluDisk;
PFNGLUENDCURVEPROC                      gluEndCurve;
PFNGLUENDPOLYGONPROC                    gluEndPolygon;
PFNGLUENDSURFACEPROC                    gluEndSurface;
PFNGLUENDTRIMPROC                       gluEndTrim;
PFNGLUERRORSTRINGPROC                   gluErrorString;
PFNGLUGETNURBSPROPERTYPROC              gluGetNurbsProperty;
PFNGLUGETSTRINGPROC                     gluGetString;
PFNGLUGETTESSPROPERTYPROC               gluGetTessProperty;
PFNGLULOADSAMPLINGMATRICESPROC          gluLoadSamplingMatrices;
PFNGLULOOKATPROC                        gluLookAt;
PFNGLUNEWNURBSRENDERERPROC              gluNewNurbsRenderer;
PFNGLUNEWQUADRICPROC                    gluNewQuadric;
PFNGLUNEWTESSPROC                       gluNewTess;
PFNGLUNEXTCONTOURPROC                   gluNextContour;
PFNGLUNURBSCALLBACKPROC                 gluNurbsCallback;
PFNGLUNURBSCURVEPROC                    gluNurbsCurve;
PFNGLUNURBSPROPERTYPROC                 gluNurbsProperty;
PFNGLUNURBSSURFACEPROC                  gluNurbsSurface;
PFNGLUORTHO2DPROC                       gluOrtho2D;
PFNGLUPARTIALDISKPROC                   gluPartialDisk;
PFNGLUPERSPECTIVEPROC                   gluPerspective;
PFNGLUPICKMATRIXPROC                    gluPickMatrix;
PFNGLUPROJECTPROC                       gluProject;
PFNGLUPWLCURVEPROC                      gluPwlCurve;
PFNGLUQUADRICCALLBACKPROC               gluQuadricCallback;
PFNGLUQUADRICDRAWSTYLEPROC              gluQuadricDrawStyle;
PFNGLUQUADRICNORMALSPROC                gluQuadricNormals;
PFNGLUQUADRICORIENTATIONPROC            gluQuadricOrientation;
PFNGLUQUADRICTEXTUREPROC                gluQuadricTexture;
PFNGLUSCALEIMAGEPROC                    gluScaleImage;
PFNGLUSPHEREPROC                        gluSphere;
PFNGLUTESSBEGINCONTOURPROC              gluTessBeginContour;
PFNGLUTESSBEGINPOLYGONPROC              gluTessBeginPolygon;
PFNGLUTESSCALLBACKPROC                  gluTessCallback;
PFNGLUTESSENDCONTOURPROC                gluTessEndContour;
PFNGLUTESSENDPOLYGONPROC                gluTessEndPolygon;
PFNGLUTESSNORMALPROC                    gluTessNormal;
PFNGLUTESSPROPERTYPROC                  gluTessProperty;
PFNGLUTESSVERTEXPROC                    gluTessVertex;
PFNGLUUNPROJECTPROC                     gluUnProject;

/* GLU 1.3 Core API Functions. */
PFNGLUCHECKEXTENSIONPROC                gluCheckExtension;
PFNGLUBUILD1DMIPMAPLEVELSPROC           gluBuild1DMipmapLevels;
PFNGLUBUILD2DMIPMAPLEVELSPROC           gluBuild2DMipmapLevels;
PFNGLUBUILD3DMIPMAPLEVELSPROC           gluBuild3DMipmapLevels;
PFNGLUBUILD3DMIPMAPSPROC                gluBuild3DMipmaps;
PFNGLUNURBSCALLBACKDATAPROC             gluNurbsCallbackData;
PFNGLUUNPROJECT4PROC                    gluUnProject4;


/* WGL_ARB_extensions_string.
 * This is used internally by the GLdriverExtensionSupported() function.
 */
typedef const char * (WINAPI * PFNWGLGETEXTENSIONSSTRINGARBPROC) (HDC hdc);
static PFNWGLGETEXTENSIONSSTRINGARBPROC wglGetExtensionsStringARB;


/* Private functions to query, convert, and store commonly accessed strings
 * from the glGetString() function.
 */

static LPTSTR GetDriverName(void)
{
    /* Returns the file name of the hardware manufacturer's OpenGL ICD.
     * Based on Realtech's Win32 OpenGL Caps Loader source code.
     */

    LPTSTR pszDriverName = NULL;
    OSVERSIONINFO ovi = {0};

    ovi.dwOSVersionInfoSize = sizeof(ovi);
    
    if (GetVersionEx(&ovi))
    {
        LONG result = 0;
        HKEY hParentKey = NULL;
        LPCTSTR pszRegistryPath = NULL;
        
        if (ovi.dwPlatformId == VER_PLATFORM_WIN32_NT)
            pszRegistryPath = _T("SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion\\OpenGLDrivers");
        else
            pszRegistryPath = _T("SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\OpenGLDrivers");

        result = RegOpenKeyEx(HKEY_LOCAL_MACHINE, pszRegistryPath, 0, KEY_ALL_ACCESS, &hParentKey);

        if (result == ERROR_SUCCESS)
        {
            HKEY hKey = NULL;
            DWORD dwSize = 0;
            FILETIME fileTime = {0};
            TCHAR szName[MAX_PATH] = {0}, szPath[MAX_PATH] = {0};

            dwSize = sizeof(szName);
            result = RegEnumKeyEx(hParentKey, 0, szName, &dwSize, NULL, NULL, NULL, &fileTime);

            while (result == ERROR_SUCCESS)
            {
                if (dwSize)
                {
                    _sntprintf(szPath, MAX_PATH, _T("%s\\%s"), pszRegistryPath, szName);
                    result = RegOpenKeyEx(HKEY_LOCAL_MACHINE, szPath, 0, KEY_QUERY_VALUE, &hKey);

                    if (result == ERROR_SUCCESS)
                    {
                        dwSize = sizeof(szName);
                        result = RegQueryValueEx(hKey, _T("Dll"), NULL, NULL, (BYTE*)szName, &dwSize);

                        if (result == ERROR_SUCCESS)
                        {
                            int length = (int)_tcsclen(szName) + 5;

                            if (pszDriverName = (LPTSTR)calloc(length, sizeof(TCHAR)))
                            {
                                _tcscpy(pszDriverName, szName);
                                _tcscat(pszDriverName, _T(".dll"));
                            }
                                
                            RegCloseKey(hKey);
                            break;
                        }
                    }
                }

                result = RegEnumKeyEx(hParentKey, 0, szName, &dwSize, NULL, NULL, NULL, &fileTime);
            }
            
            RegCloseKey(hParentKey);
        }
    }

    return pszDriverName;
}

static LPTSTR GetDriverVersion(LPCTSTR pszDriverName)
{
    /* Returns the file version of the hardware manufacturer's OpenGL ICD.
     * Based on Realtech's Win32 OpenGL Caps Loader source code.
     */

    LPTSTR pszDriverVersion = NULL;
    LPVOID pData = NULL;
    DWORD dwSize = 0;

    if (dwSize = GetFileVersionInfoSize(pszDriverName, NULL))
    {
        if (pData = (LPVOID)malloc(dwSize))
        {
            if (GetFileVersionInfo(pszDriverName, 0, dwSize, pData))
            {
                LPVOID pTranslation = NULL;
                UINT length = 0;
                TCHAR szSubBlock[128] = {_T("\\VarFileInfo\\Translation")};
                
                if (VerQueryValue(pData, szSubBlock, &pTranslation, &length))
                {
                    LPTSTR pszFileVersion = NULL;
                    DWORD *pDword = (DWORD *)pTranslation;
                    DWORD dwHigh = HIWORD(*pDword), dwLow = LOWORD(*pDword);

                    *pDword = dwHigh | (dwLow << 16);

                    _sntprintf(szSubBlock,
                        sizeof(szSubBlock) / sizeof(szSubBlock[0]),
                        _T("\\StringFileInfo\\%08lx\\%s"),
                        *(DWORD*)pTranslation, _T("FileVersion"));

                    if (VerQueryValue(pData, szSubBlock, &pszFileVersion, &length))
                    {
                        if (pszDriverVersion = (LPTSTR)calloc(length + 1, sizeof(TCHAR)))
                            _tcsncpy(pszDriverVersion, pszFileVersion, length);
                    }
                }
            }

            free(pData);
        }
    }

    return pszDriverVersion;
}

#if defined(UNICODE) && defined(_UNICODE)

static LPWSTR ToUnicodeString(LPCSTR pszText)
{
    int length = 0;
    LPWSTR pszOutput = NULL;

    if (pszText)
    {
        length = (int)strlen(pszText) + 1;
        pszOutput = (LPWSTR)calloc(length, sizeof(WCHAR));

        if (pszOutput)
            MultiByteToWideChar(CP_ACP, 0, pszText, -1, pszOutput, length);
    }

    return pszOutput;
}

static void InitDriverStringsW(GLdriver *pDriver)
{
    if (!pDriver->pszExt)
        pDriver->pszExt = ToUnicodeString((LPCSTR)glGetString(GL_EXTENSIONS));

    if (!pDriver->pszExtWGL)
    {
        if (wglGetExtensionsStringARB)
        {
            HDC hdc = wglGetCurrentDC();
            LPCSTR pszExt = wglGetExtensionsStringARB(hdc);

            pDriver->pszExtWGL = ToUnicodeString(pszExt);
        }
    }

    if (!pDriver->pszRenderer)
        pDriver->pszRenderer = ToUnicodeString((LPCSTR)glGetString(GL_RENDERER));

    if (!pDriver->pszVendor)
        pDriver->pszVendor = ToUnicodeString((LPCSTR)glGetString(GL_VENDOR));

    if (!pDriver->pszVersionGL)
        pDriver->pszVersionGL = ToUnicodeString((LPCSTR)glGetString(GL_VERSION));

    if (!pDriver->pszVersionGLU)
        pDriver->pszVersionGLU = ToUnicodeString((LPCSTR)gluGetString(GLU_VERSION));

    if (!pDriver->pszVersionShader)
        pDriver->pszVersionShader = ToUnicodeString((LPCSTR)glGetString(GL_SHADING_LANGUAGE_VERSION));
}

#else

static LPSTR CopyString(LPCSTR pszText)
{
    LPSTR pszOutput = NULL;

    if (pszText)
    {
        if (pszOutput = malloc(strlen(pszText) + 1))
            strcpy(pszOutput, pszText);
    }

    return pszOutput;
}

static void InitDriverStringsA(GLdriver *pDriver)
{
    if (!pDriver->pszExt)
        pDriver->pszExt = CopyString((LPCSTR)glGetString(GL_EXTENSIONS));

    if (!pDriver->pszExtWGL)
    {
        if (wglGetExtensionsStringARB)
        {
            HDC hdc = wglGetCurrentDC();

            pDriver->pszExtWGL = CopyString(wglGetExtensionsStringARB(hdc));
        }
    }

    if (!pDriver->pszRenderer)
        pDriver->pszRenderer = CopyString((LPCSTR)glGetString(GL_RENDERER));

    if (!pDriver->pszVendor)
        pDriver->pszVendor = CopyString((LPCSTR)glGetString(GL_VENDOR));

    if (!pDriver->pszVersionGL)
        pDriver->pszVersionGL = CopyString((LPCSTR)glGetString(GL_VERSION));

    if (!pDriver->pszVersionGLU)
        pDriver->pszVersionGLU = CopyString((LPCSTR)gluGetString(GLU_VERSION));

    if (!pDriver->pszVersionShader)
        pDriver->pszVersionShader = CopyString((LPCSTR)glGetString(GL_SHADING_LANGUAGE_VERSION));
}

#endif

static void InitDriverStrings(GLdriver *pDriver)
{
    if (pDriver)
    {
    #if defined(UNICODE) && defined(_UNICODE)
        InitDriverStringsW(pDriver);
    #else
        InitDriverStringsA(pDriver);
    #endif

        pDriver->pszDriverName = GetDriverName();
        pDriver->pszDriverVersion = GetDriverVersion(pDriver->pszDriverName);
    }
}

/*
 * GLdriver functions.
 */

GLboolean GLdriverExtensionSupported(GLdriver *pDriver, LPCTSTR pszExtension)
{
    if (_tcsstr(pszExtension, pDriver->pszExt))
        return GL_TRUE;

    if (_tcsstr(pszExtension, pDriver->pszExtWGL))
        return GL_TRUE;

    return GL_FALSE;
}

void GLdriverGetGLVersion(GLdriver *pDriver, GLint *pMajor, GLint *pMinor)
{
    GLint majorGL = 0, minorGL = 0;

    if (!pDriver)
        return;

    if (pDriver->pszVersionGL)
        _stscanf(pDriver->pszVersionGL, _T("%d.%d"), &majorGL, &minorGL);

    if (pMajor)
        *pMajor = majorGL;

    if (pMinor)
        *pMinor = minorGL;
}

void GLdriverGetGLUVersion(GLdriver *pDriver, GLint *pMajor, GLint *pMinor)
{
    GLint majorGLU = 0, minorGLU = 0;

    if (!pDriver)
        return;

    if (pDriver->pszVersionGLU)
        _stscanf(pDriver->pszVersionGLU, _T("%d.%d"), &majorGLU, &minorGLU);

    if (pMajor)
        *pMajor = majorGLU;

    if (pMinor)
        *pMinor = minorGLU;
}

void GLdriverGetGLSLVersion(GLdriver *pDriver, GLint *pMajor, GLint *pMinor)
{
    GLint majorGL = 0, minorGL = 0;
    GLint majorGLSL = 0, minorGLSL = 0;

    if (!pDriver)
        return;

    GLdriverGetGLVersion(pDriver, &majorGL, &minorGL);
        
    if (majorGL >= 2)
    {
        if (pDriver->pszVersionShader)
            _stscanf(pDriver->pszVersionShader, _T("%d.%d"), &majorGLSL, &minorGLSL);
    }
    else
    {
        if (GLdriverExtensionSupported(pDriver, _T("GL_ARB_shading_language_100")))
        {
            majorGLSL = 1;
            minorGLSL = 0;
        }
    }

    if (pMajor)
        *pMajor = majorGLSL;

    if (pMinor)
        *pMinor = minorGLSL;
}

GLboolean GLdriverSupportsGLVersion(GLdriver *pDriver, GLint major, GLint minor)
{
    GLint majorGL = 0, minorGL = 0;

    GLdriverGetGLVersion(pDriver, &majorGL, &minorGL);

    if (majorGL > major)
        return GL_TRUE;

    if (majorGL == major && minorGL >= minor)
        return GL_TRUE;

    return GL_FALSE;
}

GLboolean GLdriverSupportsGLUVersion(GLdriver *pDriver, GLint major, GLint minor)
{
    GLint majorGLU = 0, minorGLU = 0;

    GLdriverGetGLUVersion(pDriver, &majorGLU, &minorGLU);

    if (majorGLU > major)
        return GL_TRUE;

    if (majorGLU == major && minorGLU >= minor)
        return GL_TRUE;

    return GL_FALSE;
}

GLboolean GLdriverSupportsGLSLVersion(GLdriver *pDriver, GLint major, GLint minor)
{
    GLint majorGLSL = 0, minorGLSL = 0;

    GLdriverGetGLSLVersion(pDriver, &majorGLSL, &minorGLSL);

    if (majorGLSL > major)
        return GL_TRUE;

    if (majorGLSL == major && minorGLSL >= minor)
        return GL_TRUE;

    return GL_FALSE;
}

GLboolean GLdriverLoad(GLdriver *pDriver, LPCTSTR pszPathGL, LPCTSTR pszPathGLU)
{
    HMODULE hLib = NULL;

    if (!pszPathGL)
        return GL_FALSE;

    pDriver->hLibGL = NULL;
    pDriver->hLibGLU = NULL;
    pDriver->hLibOS = NULL;
    hLib = LoadLibrary(pszPathGL);

    if (!hLib)
        return GL_FALSE;

    pDriver->hLibGL = hLib;

    #define GPA(x) GetProcAddress(hLib, x)

    /* WGL Core API Functions. */
    my_wglCopyContext           = (PFNWGLCOPYCONTEXTPROC)GPA("wglCopyContext");
    my_wglCreateContext         = (PFNWGLCREATECONTEXTPROC)GPA("wglCreateContext");
    my_wglCreateLayerContext    = (PFNWGLCREATELAYERCONTEXTPROC)GPA("wglCreateLayerContext");
    my_wglDeleteContext         = (PFNWGLDELETECONTEXTPROC)GPA("wglDeleteContext");
    my_wglDescribeLayerPlane    = (PFNWGLDESCRIBELAYERPLANEPROC)GPA("wglDescribeLayerPlane");
    my_wglGetCurrentContext     = (PFNWGLGETCURRENTCONTEXTPROC)GPA("wglGetCurrentContext");
    my_wglGetCurrentDC          = (PFNWGLGETCURRENTDCPROC)GPA("wglGetCurrentDC");
    my_wglGetLayerPaletteEntries= (PFNWGLGETLAYERPALETTEENTRIESPROC)GPA("wglGetLayerPaletteEntries");
    my_wglGetProcAddress        = (PFNWGLGETPROCADDRESSPROC)GPA("wglGetProcAddress");
    my_wglMakeCurrent           = (PFNWGLMAKECURRENTPROC)GPA("wglMakeCurrent");
    my_wglRealizeLayerPalette   = (PFNWGLREALIZELAYERPALETTEPROC)GPA("wglRealizeLayerPalette");
    my_wglSetLayerPaletteEntries= (PFNWGLSETLAYERPALETTEENTRIESPROC)GPA("wglSetLayerPaletteEntries");
    my_wglShareLists            = (PFNWGLSHARELISTSPROC)GPA("wglShareLists");
    my_wglSwapLayerBuffers      = (PFNWGLSWAPLAYERBUFFERSPROC)GPA("wglSwapLayerBuffers");
    my_wglUseFontBitmapsA       = (PFNWGLUSEFONTBITMAPSAPROC)GPA("wglUseFontBitmapsA");
    my_wglUseFontBitmapsW       = (PFNWGLUSEFONTBITMAPSWPROC)GPA("wglUseFontBitmapsW");
    my_wglUseFontOutlinesA      = (PFNWGLUSEFONTOUTLINESAPROC)GPA("wglUseFontOutlinesA");
    my_wglUseFontOutlinesW      = (PFNWGLUSEFONTOUTLINESWPROC)GPA("wglUseFontOutlinesW");

    /* OpenGL 1.1 Core API Functions. */
    glAccum                     = (PFNGLACCUMPROC)GPA("glAccum");
    glAlphaFunc                 = (PFNGLALPHAFUNCPROC)GPA("glAlphaFunc");
    glAreTexturesResident       = (PFNGLARETEXTURESRESIDENTPROC)GPA("glAreTexturesResident");
    glArrayElement              = (PFNGLARRAYELEMENTPROC)GPA("glArrayElement");
    glBegin                     = (PFNGLBEGINPROC)GPA("glBegin");
    glBindTexture               = (PFNGLBINDTEXTUREPROC)GPA("glBindTexture");
    glBitmap                    = (PFNGLBITMAPPROC)GPA("glBitmap");
    glBlendFunc                 = (PFNGLBLENDFUNCPROC)GPA("glBlendFunc");
    glCallList                  = (PFNGLCALLLISTPROC)GPA("glCallList");
    glCallLists                 = (PFNGLCALLLISTSPROC)GPA("glCallLists");
    glClear                     = (PFNGLCLEARPROC)GPA("glClear");
    glClearAccum                = (PFNGLCLEARACCUMPROC)GPA("glClearAccum");
    glClearColor                = (PFNGLCLEARCOLORPROC)GPA("glClearColor");
    glClearDepth                = (PFNGLCLEARDEPTHPROC)GPA("glClearDepth");
    glClearIndex                = (PFNGLCLEARINDEXPROC)GPA("glClearIndex");
    glClearStencil              = (PFNGLCLEARSTENCILPROC)GPA("glClearStencil");
    glClipPlane                 = (PFNGLCLIPPLANEPROC)GPA("glClipPlane");
    glColor3b                   = (PFNGLCOLOR3BPROC)GPA("glColor3b");
    glColor3bv                  = (PFNGLCOLOR3BVPROC)GPA("glColor3bv");
    glColor3d                   = (PFNGLCOLOR3DPROC)GPA("glColor3d");
    glColor3dv                  = (PFNGLCOLOR3DVPROC)GPA("glColor3dv");
    glColor3f                   = (PFNGLCOLOR3FPROC)GPA("glColor3f");
    glColor3fv                  = (PFNGLCOLOR3FVPROC)GPA("glColor3fv");
    glColor3i                   = (PFNGLCOLOR3IPROC)GPA("glColor3i");
    glColor3iv                  = (PFNGLCOLOR3IVPROC)GPA("glColor3iv");
    glColor3s                   = (PFNGLCOLOR3SPROC)GPA("glColor3s");
    glColor3sv                  = (PFNGLCOLOR3SVPROC)GPA("glColor3sv");
    glColor3ub                  = (PFNGLCOLOR3UBPROC)GPA("glColor3ub");
    glColor3ubv                 = (PFNGLCOLOR3UBVPROC)GPA("glColor3ubv");
    glColor3ui                  = (PFNGLCOLOR3UIPROC)GPA("glColor3ui");
    glColor3uiv                 = (PFNGLCOLOR3UIVPROC)GPA("glColor3uiv");
    glColor3us                  = (PFNGLCOLOR3USPROC)GPA("glColor3us");
    glColor3usv                 = (PFNGLCOLOR3USVPROC)GPA("glColor3usv");
    glColor4b                   = (PFNGLCOLOR4BPROC)GPA("glColor4b");
    glColor4bv                  = (PFNGLCOLOR4BVPROC)GPA("glColor4bv");
    glColor4d                   = (PFNGLCOLOR4DPROC)GPA("glColor4d");
    glColor4dv                  = (PFNGLCOLOR4DVPROC)GPA("glColor4dv");
    glColor4f                   = (PFNGLCOLOR4FPROC)GPA("glColor4f");
    glColor4fv                  = (PFNGLCOLOR4FVPROC)GPA("glColor4fv");
    glColor4i                   = (PFNGLCOLOR4IPROC)GPA("glColor4i");
    glColor4iv                  = (PFNGLCOLOR4IVPROC)GPA("glColor4iv");
    glColor4s                   = (PFNGLCOLOR4SPROC)GPA("glColor4s");
    glColor4sv                  = (PFNGLCOLOR4SVPROC)GPA("glColor4sv");
    glColor4ub                  = (PFNGLCOLOR4UBPROC)GPA("glColor4ub");
    glColor4ubv                 = (PFNGLCOLOR4UBVPROC)GPA("glColor4ubv");
    glColor4ui                  = (PFNGLCOLOR4UIPROC)GPA("glColor4ui");
    glColor4uiv                 = (PFNGLCOLOR4UIVPROC)GPA("glColor4uiv");
    glColor4us                  = (PFNGLCOLOR4USPROC)GPA("glColor4us");
    glColor4usv                 = (PFNGLCOLOR4USVPROC)GPA("glColor4usv");
    glColorMask                 = (PFNGLCOLORMASKPROC)GPA("glColorMask");
    glColorMaterial             = (PFNGLCOLORMATERIALPROC)GPA("glColorMaterial");
    glColorPointer              = (PFNGLCOLORPOINTERPROC)GPA("glColorPointer");
    glCopyPixels                = (PFNGLCOPYPIXELSPROC)GPA("glCopyPixels");
    glCopyTexImage1D            = (PFNGLCOPYTEXIMAGE1DPROC)GPA("glCopyTexImage1D");
    glCopyTexImage2D            = (PFNGLCOPYTEXIMAGE2DPROC)GPA("glCopyTexImage2D");
    glCopyTexSubImage1D         = (PFNGLCOPYTEXSUBIMAGE1DPROC)GPA("glCopyTexSubImage1D");
    glCopyTexSubImage2D         = (PFNGLCOPYTEXSUBIMAGE2DPROC)GPA("glCopyTexSubImage2D");
    glCullFace                  = (PFNGLCULLFACEPROC)GPA("glCullFace");
    glDeleteLists               = (PFNGLDELETELISTSPROC)GPA("glDeleteLists");
    glDeleteTextures            = (PFNGLDELETETEXTURESPROC)GPA("glDeleteTextures");
    glDepthFunc                 = (PFNGLDEPTHFUNCPROC)GPA("glDepthFunc");
    glDepthMask                 = (PFNGLDEPTHMASKPROC)GPA("glDepthMask");
    glDepthRange                = (PFNGLDEPTHRANGEPROC)GPA("glDepthRange");
    glDisable                   = (PFNGLDISABLEPROC)GPA("glDisable");
    glDisableClientState        = (PFNGLDISABLECLIENTSTATEPROC)GPA("glDisableClientState");
    glDrawArrays                = (PFNGLDRAWARRAYSPROC)GPA("glDrawArrays");
    glDrawBuffer                = (PFNGLDRAWBUFFERPROC)GPA("glDrawBuffer");
    glDrawElements              = (PFNGLDRAWELEMENTSPROC)GPA("glDrawElements");
    glDrawPixels                = (PFNGLDRAWPIXELSPROC)GPA("glDrawPixels");
    glEdgeFlag                  = (PFNGLEDGEFLAGPROC)GPA("glEdgeFlag");
    glEdgeFlagPointer           = (PFNGLEDGEFLAGPOINTERPROC)GPA("glEdgeFlagPointer");
    glEdgeFlagv                 = (PFNGLEDGEFLAGVPROC)GPA("glEdgeFlagv");
    glEnable                    = (PFNGLENABLEPROC)GPA("glEnable");
    glEnableClientState         = (PFNGLENABLECLIENTSTATEPROC)GPA("glEnableClientState");
    glEnd                       = (PFNGLENDPROC)GPA("glEnd");
    glEndList                   = (PFNGLENDLISTPROC)GPA("glEndList");
    glEvalCoord1d               = (PFNGLEVALCOORD1DPROC)GPA("glEvalCoord1d");
    glEvalCoord1dv              = (PFNGLEVALCOORD1DVPROC)GPA("glEvalCoord1dv");
    glEvalCoord1f               = (PFNGLEVALCOORD1FPROC)GPA("glEvalCoord1f");
    glEvalCoord1fv              = (PFNGLEVALCOORD1FVPROC)GPA("glEvalCoord1fv");
    glEvalCoord2d               = (PFNGLEVALCOORD2DPROC)GPA("glEvalCoord2d");
    glEvalCoord2dv              = (PFNGLEVALCOORD2DVPROC)GPA("glEvalCoord2dv");
    glEvalCoord2f               = (PFNGLEVALCOORD2FPROC)GPA("glEvalCoord2f");
    glEvalCoord2fv              = (PFNGLEVALCOORD2FVPROC)GPA("glEvalCoord2fv");
    glEvalMesh1                 = (PFNGLEVALMESH1PROC)GPA("glEvalMesh1");
    glEvalMesh2                 = (PFNGLEVALMESH2PROC)GPA("glEvalMesh2");
    glEvalPoint1                = (PFNGLEVALPOINT1PROC)GPA("glEvalPoint1");
    glEvalPoint2                = (PFNGLEVALPOINT2PROC)GPA("glEvalPoint2");
    glFeedbackBuffer            = (PFNGLFEEDBACKBUFFERPROC)GPA("glFeedbackBuffer");
    glFinish                    = (PFNGLFINISHPROC)GPA("glFinish");
    glFlush                     = (PFNGLFLUSHPROC)GPA("glFlush");
    glFogf                      = (PFNGLFOGFPROC)GPA("glFogf");
    glFogfv                     = (PFNGLFOGFVPROC)GPA("glFogfv");
    glFogi                      = (PFNGLFOGIPROC)GPA("glFogi");
    glFogiv                     = (PFNGLFOGIVPROC)GPA("glFogiv");
    glFrontFace                 = (PFNGLFRONTFACEPROC)GPA("glFrontFace");
    glFrustum                   = (PFNGLFRUSTUMPROC)GPA("glFrustum");
    glGenLists                  = (PFNGLGENLISTSPROC)GPA("glGenLists");
    glGenTextures               = (PFNGLGENTEXTURESPROC)GPA("glGenTextures");
    glGetBooleanv               = (PFNGLGETBOOLEANVPROC)GPA("glGetBooleanv");
    glGetClipPlane              = (PFNGLGETCLIPPLANEPROC)GPA("glGetClipPlane");
    glGetDoublev                = (PFNGLGETDOUBLEVPROC)GPA("glGetDoublev");
    glGetError                  = (PFNGLGETERRORPROC)GPA("glGetError");
    glGetFloatv                 = (PFNGLGETFLOATVPROC)GPA("glGetFloatv");
    glGetIntegerv               = (PFNGLGETINTEGERVPROC)GPA("glGetIntegerv");
    glGetLightfv                = (PFNGLGETLIGHTFVPROC)GPA("glGetLightfv");
    glGetLightiv                = (PFNGLGETLIGHTIVPROC)GPA("glGetLightiv");
    glGetMapdv                  = (PFNGLGETMAPDVPROC)GPA("glGetMapdv");
    glGetMapfv                  = (PFNGLGETMAPFVPROC)GPA("glGetMapfv");
    glGetMapiv                  = (PFNGLGETMAPIVPROC)GPA("glGetMapiv");
    glGetMaterialfv             = (PFNGLGETMATERIALFVPROC)GPA("glGetMaterialfv");
    glGetMaterialiv             = (PFNGLGETMATERIALIVPROC)GPA("glGetMaterialiv");
    glGetPixelMapfv             = (PFNGLGETPIXELMAPFVPROC)GPA("glGetPixelMapfv");
    glGetPixelMapuiv            = (PFNGLGETPIXELMAPUIVPROC)GPA("glGetPixelMapuiv");
    glGetPixelMapusv            = (PFNGLGETPIXELMAPUSVPROC)GPA("glGetPixelMapusv");
    glGetPointerv               = (PFNGLGETPOINTERVPROC)GPA("glGetPointerv");
    glGetPolygonStipple         = (PFNGLGETPOLYGONSTIPPLEPROC)GPA("glGetPolygonStipple");
    glGetString                 = (PFNGLGETSTRINGPROC)GPA("glGetString");
    glGetTexEnvfv               = (PFNGLGETTEXENVFVPROC)GPA("glGetTexEnvfv");
    glGetTexEnviv               = (PFNGLGETTEXENVIVPROC)GPA("glGetTexEnviv");
    glGetTexGendv               = (PFNGLGETTEXGENDVPROC)GPA("glGetTexGendv");
    glGetTexGenfv               = (PFNGLGETTEXGENFVPROC)GPA("glGetTexGenfv");
    glGetTexGeniv               = (PFNGLGETTEXGENIVPROC)GPA("glGetTexGeniv");
    glGetTexImage               = (PFNGLGETTEXIMAGEPROC)GPA("glGetTexImage");
    glGetTexLevelParameterfv    = (PFNGLGETTEXLEVELPARAMETERFVPROC)GPA("glGetTexLevelParameterfv");
    glGetTexLevelParameteriv    = (PFNGLGETTEXLEVELPARAMETERIVPROC)GPA("glGetTexLevelParameteriv");
    glGetTexParameterfv         = (PFNGLGETTEXPARAMETERFVPROC)GPA("glGetTexParameterfv");
    glGetTexParameteriv         = (PFNGLGETTEXPARAMETERIVPROC)GPA("glGetTexParameteriv");
    glHint                      = (PFNGLHINTPROC)GPA("glHint");
    glIndexMask                 = (PFNGLINDEXMASKPROC)GPA("glIndexMask");
    glIndexPointer              = (PFNGLINDEXPOINTERPROC)GPA("glIndexPointer");
    glIndexd                    = (PFNGLINDEXDPROC)GPA("glIndexd");
    glIndexdv                   = (PFNGLINDEXDVPROC)GPA("glIndexdv");
    glIndexf                    = (PFNGLINDEXFPROC)GPA("glIndexf");
    glIndexfv                   = (PFNGLINDEXFVPROC)GPA("glIndexfv");
    glIndexi                    = (PFNGLINDEXIPROC)GPA("glIndexi");
    glIndexiv                   = (PFNGLINDEXIVPROC)GPA("glIndexiv");
    glIndexs                    = (PFNGLINDEXSPROC)GPA("glIndexs");
    glIndexsv                   = (PFNGLINDEXSVPROC)GPA("glIndexsv");
    glIndexub                   = (PFNGLINDEXUBPROC)GPA("glIndexub");
    glIndexubv                  = (PFNGLINDEXUBVPROC)GPA("glIndexubv");
    glInitNames                 = (PFNGLINITNAMESPROC)GPA("glInitNames");
    glInterleavedArrays         = (PFNGLINTERLEAVEDARRAYSPROC)GPA("glInterleavedArrays");
    glIsEnabled                 = (PFNGLISENABLEDPROC)GPA("glIsEnabled");
    glIsList                    = (PFNGLISLISTPROC)GPA("glIsList");
    glIsTexture                 = (PFNGLISTEXTUREPROC)GPA("glIsTexture");
    glLightModelf               = (PFNGLLIGHTMODELFPROC)GPA("glLightModelf");
    glLightModelfv              = (PFNGLLIGHTMODELFVPROC)GPA("glLightModelfv");
    glLightModeli               = (PFNGLLIGHTMODELIPROC)GPA("glLightModeli");
    glLightModeliv              = (PFNGLLIGHTMODELIVPROC)GPA("glLightModeliv");
    glLightf                    = (PFNGLLIGHTFPROC)GPA("glLightf");
    glLightfv                   = (PFNGLLIGHTFVPROC)GPA("glLightfv");
    glLighti                    = (PFNGLLIGHTIPROC)GPA("glLighti");
    glLightiv                   = (PFNGLLIGHTIVPROC)GPA("glLightiv");
    glLineStipple               = (PFNGLLINESTIPPLEPROC)GPA("glLineStipple");
    glLineWidth                 = (PFNGLLINEWIDTHPROC)GPA("glLineWidth");
    glListBase                  = (PFNGLLISTBASEPROC)GPA("glListBase");
    glLoadIdentity              = (PFNGLLOADIDENTITYPROC)GPA("glLoadIdentity");
    glLoadMatrixd               = (PFNGLLOADMATRIXDPROC)GPA("glLoadMatrixd");
    glLoadMatrixf               = (PFNGLLOADMATRIXFPROC)GPA("glLoadMatrixf");
    glLoadName                  = (PFNGLLOADNAMEPROC)GPA("glLoadName");
    glLogicOp                   = (PFNGLLOGICOPPROC)GPA("glLogicOp");
    glMap1d                     = (PFNGLMAP1DPROC)GPA("glMap1d");
    glMap1f                     = (PFNGLMAP1FPROC)GPA("glMap1f");
    glMap2d                     = (PFNGLMAP2DPROC)GPA("glMap2d");
    glMap2f                     = (PFNGLMAP2FPROC)GPA("glMap2f");
    glMapGrid1d                 = (PFNGLMAPGRID1DPROC)GPA("glMapGrid1d");
    glMapGrid1f                 = (PFNGLMAPGRID1FPROC)GPA("glMapGrid1f");
    glMapGrid2d                 = (PFNGLMAPGRID2DPROC)GPA("glMapGrid2d");
    glMapGrid2f                 = (PFNGLMAPGRID2FPROC)GPA("glMapGrid2f");
    glMaterialf                 = (PFNGLMATERIALFPROC)GPA("glMaterialf");
    glMaterialfv                = (PFNGLMATERIALFVPROC)GPA("glMaterialfv");
    glMateriali                 = (PFNGLMATERIALIPROC)GPA("glMateriali");
    glMaterialiv                = (PFNGLMATERIALIVPROC)GPA("glMaterialiv");
    glMatrixMode                = (PFNGLMATRIXMODEPROC)GPA("glMatrixMode");
    glMultMatrixd               = (PFNGLMULTMATRIXDPROC)GPA("glMultMatrixd");
    glMultMatrixf               = (PFNGLMULTMATRIXFPROC)GPA("glMultMatrixf");
    glNewList                   = (PFNGLNEWLISTPROC)GPA("glNewList");
    glNormal3b                  = (PFNGLNORMAL3BPROC)GPA("glNormal3b");
    glNormal3bv                 = (PFNGLNORMAL3BVPROC)GPA("glNormal3bv");
    glNormal3d                  = (PFNGLNORMAL3DPROC)GPA("glNormal3d");
    glNormal3dv                 = (PFNGLNORMAL3DVPROC)GPA("glNormal3dv");
    glNormal3f                  = (PFNGLNORMAL3FPROC)GPA("glNormal3f");
    glNormal3fv                 = (PFNGLNORMAL3FVPROC)GPA("glNormal3fv");
    glNormal3i                  = (PFNGLNORMAL3IPROC)GPA("glNormal3i");
    glNormal3iv                 = (PFNGLNORMAL3IVPROC)GPA("glNormal3iv");
    glNormal3s                  = (PFNGLNORMAL3SPROC)GPA("glNormal3s");
    glNormal3sv                 = (PFNGLNORMAL3SVPROC)GPA("glNormal3sv");
    glNormalPointer             = (PFNGLNORMALPOINTERPROC)GPA("glNormalPointer");
    glOrtho                     = (PFNGLORTHOPROC)GPA("glOrtho");
    glPassThrough               = (PFNGLPASSTHROUGHPROC)GPA("glPassThrough");
    glPixelMapfv                = (PFNGLPIXELMAPFVPROC)GPA("glPixelMapfv");
    glPixelMapuiv               = (PFNGLPIXELMAPUIVPROC)GPA("glPixelMapuiv");
    glPixelMapusv               = (PFNGLPIXELMAPUSVPROC)GPA("glPixelMapusv");
    glPixelStoref               = (PFNGLPIXELSTOREFPROC)GPA("glPixelStoref");
    glPixelStorei               = (PFNGLPIXELSTOREIPROC)GPA("glPixelStorei");
    glPixelTransferf            = (PFNGLPIXELTRANSFERFPROC)GPA("glPixelTransferf");
    glPixelTransferi            = (PFNGLPIXELTRANSFERIPROC)GPA("glPixelTransferi");
    glPixelZoom                 = (PFNGLPIXELZOOMPROC)GPA("glPixelZoom");
    glPointSize                 = (PFNGLPOINTSIZEPROC)GPA("glPointSize");
    glPolygonMode               = (PFNGLPOLYGONMODEPROC)GPA("glPolygonMode");
    glPolygonOffset             = (PFNGLPOLYGONOFFSETPROC)GPA("glPolygonOffset");
    glPolygonStipple            = (PFNGLPOLYGONSTIPPLEPROC)GPA("glPolygonStipple");
    glPopAttrib                 = (PFNGLPOPATTRIBPROC)GPA("glPopAttrib");
    glPopClientAttrib           = (PFNGLPOPCLIENTATTRIBPROC)GPA("glPopClientAttrib");
    glPopMatrix                 = (PFNGLPOPMATRIXPROC)GPA("glPopMatrix");
    glPopName                   = (PFNGLPOPNAMEPROC)GPA("glPopName");
    glPrioritizeTextures        = (PFNGLPRIORITIZETEXTURESPROC)GPA("glPrioritizeTextures");
    glPushAttrib                = (PFNGLPUSHATTRIBPROC)GPA("glPushAttrib");
    glPushClientAttrib          = (PFNGLPUSHCLIENTATTRIBPROC)GPA("glPushClientAttrib");
    glPushMatrix                = (PFNGLPUSHMATRIXPROC)GPA("glPushMatrix");
    glPushName                  = (PFNGLPUSHNAMEPROC)GPA("glPushName");
    glRasterPos2d               = (PFNGLRASTERPOS2DPROC)GPA("glRasterPos2d");
    glRasterPos2dv              = (PFNGLRASTERPOS2DVPROC)GPA("glRasterPos2dv");
    glRasterPos2f               = (PFNGLRASTERPOS2FPROC)GPA("glRasterPos2f");
    glRasterPos2fv              = (PFNGLRASTERPOS2FVPROC)GPA("glRasterPos2fv");
    glRasterPos2i               = (PFNGLRASTERPOS2IPROC)GPA("glRasterPos2i");
    glRasterPos2iv              = (PFNGLRASTERPOS2IVPROC)GPA("glRasterPos2iv");
    glRasterPos2s               = (PFNGLRASTERPOS2SPROC)GPA("glRasterPos2s");
    glRasterPos2sv              = (PFNGLRASTERPOS2SVPROC)GPA("glRasterPos2sv");
    glRasterPos3d               = (PFNGLRASTERPOS3DPROC)GPA("glRasterPos3d");
    glRasterPos3dv              = (PFNGLRASTERPOS3DVPROC)GPA("glRasterPos3dv");
    glRasterPos3f               = (PFNGLRASTERPOS3FPROC)GPA("glRasterPos3f");
    glRasterPos3fv              = (PFNGLRASTERPOS3FVPROC)GPA("glRasterPos3fv");
    glRasterPos3i               = (PFNGLRASTERPOS3IPROC)GPA("glRasterPos3i");
    glRasterPos3iv              = (PFNGLRASTERPOS3IVPROC)GPA("glRasterPos3iv");
    glRasterPos3s               = (PFNGLRASTERPOS3SPROC)GPA("glRasterPos3s");
    glRasterPos3sv              = (PFNGLRASTERPOS3SVPROC)GPA("glRasterPos3sv");
    glRasterPos4d               = (PFNGLRASTERPOS4DPROC)GPA("glRasterPos4d");
    glRasterPos4dv              = (PFNGLRASTERPOS4DVPROC)GPA("glRasterPos4dv");
    glRasterPos4f               = (PFNGLRASTERPOS4FPROC)GPA("glRasterPos4f");
    glRasterPos4fv              = (PFNGLRASTERPOS4FVPROC)GPA("glRasterPos4fv");
    glRasterPos4i               = (PFNGLRASTERPOS4IPROC)GPA("glRasterPos4i");
    glRasterPos4iv              = (PFNGLRASTERPOS4IVPROC)GPA("glRasterPos4iv");
    glRasterPos4s               = (PFNGLRASTERPOS4SPROC)GPA("glRasterPos4s");
    glRasterPos4sv              = (PFNGLRASTERPOS4SVPROC)GPA("glRasterPos4sv");
    glReadBuffer                = (PFNGLREADBUFFERPROC)GPA("glReadBuffer");
    glReadPixels                = (PFNGLREADPIXELSPROC)GPA("glReadPixels");
    glRectd                     = (PFNGLRECTDPROC)GPA("glRectd");
    glRectdv                    = (PFNGLRECTDVPROC)GPA("glRectdv");
    glRectf                     = (PFNGLRECTFPROC)GPA("glRectf");
    glRectfv                    = (PFNGLRECTFVPROC)GPA("glRectfv");
    glRecti                     = (PFNGLRECTIPROC)GPA("glRecti");
    glRectiv                    = (PFNGLRECTIVPROC)GPA("glRectiv");
    glRects                     = (PFNGLRECTSPROC)GPA("glRects");
    glRectsv                    = (PFNGLRECTSVPROC)GPA("glRectsv");
    glRenderMode                = (PFNGLRENDERMODEPROC)GPA("glRenderMode");
    glRotated                   = (PFNGLROTATEDPROC)GPA("glRotated");
    glRotatef                   = (PFNGLROTATEFPROC)GPA("glRotatef");
    glScaled                    = (PFNGLSCALEDPROC)GPA("glScaled");
    glScalef                    = (PFNGLSCALEFPROC)GPA("glScalef");
    glScissor                   = (PFNGLSCISSORPROC)GPA("glScissor");
    glSelectBuffer              = (PFNGLSELECTBUFFERPROC)GPA("glSelectBuffer");
    glShadeModel                = (PFNGLSHADEMODELPROC)GPA("glShadeModel");
    glStencilFunc               = (PFNGLSTENCILFUNCPROC)GPA("glStencilFunc");
    glStencilMask               = (PFNGLSTENCILMASKPROC)GPA("glStencilMask");
    glStencilOp                 = (PFNGLSTENCILOPPROC)GPA("glStencilOp");
    glTexCoord1d                = (PFNGLTEXCOORD1DPROC)GPA("glTexCoord1d");
    glTexCoord1dv               = (PFNGLTEXCOORD1DVPROC)GPA("glTexCoord1dv");
    glTexCoord1f                = (PFNGLTEXCOORD1FPROC)GPA("glTexCoord1f");
    glTexCoord1fv               = (PFNGLTEXCOORD1FVPROC)GPA("glTexCoord1fv");
    glTexCoord1i                = (PFNGLTEXCOORD1IPROC)GPA("glTexCoord1i");
    glTexCoord1iv               = (PFNGLTEXCOORD1IVPROC)GPA("glTexCoord1iv");
    glTexCoord1s                = (PFNGLTEXCOORD1SPROC)GPA("glTexCoord1s");
    glTexCoord1sv               = (PFNGLTEXCOORD1SVPROC)GPA("glTexCoord1sv");
    glTexCoord2d                = (PFNGLTEXCOORD2DPROC)GPA("glTexCoord2d");
    glTexCoord2dv               = (PFNGLTEXCOORD2DVPROC)GPA("glTexCoord2dv");
    glTexCoord2f                = (PFNGLTEXCOORD2FPROC)GPA("glTexCoord2f");
    glTexCoord2fv               = (PFNGLTEXCOORD2FVPROC)GPA("glTexCoord2fv");
    glTexCoord2i                = (PFNGLTEXCOORD2IPROC)GPA("glTexCoord2i");
    glTexCoord2iv               = (PFNGLTEXCOORD2IVPROC)GPA("glTexCoord2iv");
    glTexCoord2s                = (PFNGLTEXCOORD2SPROC)GPA("glTexCoord2s");
    glTexCoord2sv               = (PFNGLTEXCOORD2SVPROC)GPA("glTexCoord2sv");
    glTexCoord3d                = (PFNGLTEXCOORD3DPROC)GPA("glTexCoord3d");
    glTexCoord3dv               = (PFNGLTEXCOORD3DVPROC)GPA("glTexCoord3dv");
    glTexCoord3f                = (PFNGLTEXCOORD3FPROC)GPA("glTexCoord3f");
    glTexCoord3fv               = (PFNGLTEXCOORD3FVPROC)GPA("glTexCoord3fv");
    glTexCoord3i                = (PFNGLTEXCOORD3IPROC)GPA("glTexCoord3i");
    glTexCoord3iv               = (PFNGLTEXCOORD3IVPROC)GPA("glTexCoord3iv");
    glTexCoord3s                = (PFNGLTEXCOORD3SPROC)GPA("glTexCoord3s");
    glTexCoord3sv               = (PFNGLTEXCOORD3SVPROC)GPA("glTexCoord3sv");
    glTexCoord4d                = (PFNGLTEXCOORD4DPROC)GPA("glTexCoord4d");
    glTexCoord4dv               = (PFNGLTEXCOORD4DVPROC)GPA("glTexCoord4dv");
    glTexCoord4f                = (PFNGLTEXCOORD4FPROC)GPA("glTexCoord4f");
    glTexCoord4fv               = (PFNGLTEXCOORD4FVPROC)GPA("glTexCoord4fv");
    glTexCoord4i                = (PFNGLTEXCOORD4IPROC)GPA("glTexCoord4i");
    glTexCoord4iv               = (PFNGLTEXCOORD4IVPROC)GPA("glTexCoord4iv");
    glTexCoord4s                = (PFNGLTEXCOORD4SPROC)GPA("glTexCoord4s");
    glTexCoord4sv               = (PFNGLTEXCOORD4SVPROC)GPA("glTexCoord4sv");
    glTexCoordPointer           = (PFNGLTEXCOORDPOINTERPROC)GPA("glTexCoordPointer");
    glTexEnvf                   = (PFNGLTEXENVFPROC)GPA("glTexEnvf");
    glTexEnvfv                  = (PFNGLTEXENVFVPROC)GPA("glTexEnvfv");
    glTexEnvi                   = (PFNGLTEXENVIPROC)GPA("glTexEnvi");
    glTexEnviv                  = (PFNGLTEXENVIVPROC)GPA("glTexEnviv");
    glTexGend                   = (PFNGLTEXGENDPROC)GPA("glTexGend");
    glTexGendv                  = (PFNGLTEXGENDVPROC)GPA("glTexGendv");
    glTexGenf                   = (PFNGLTEXGENFPROC)GPA("glTexGenf");
    glTexGenfv                  = (PFNGLTEXGENFVPROC)GPA("glTexGenfv");
    glTexGeni                   = (PFNGLTEXGENIPROC)GPA("glTexGeni");
    glTexGeniv                  = (PFNGLTEXGENIVPROC)GPA("glTexGeniv");
    glTexImage1D                = (PFNGLTEXIMAGE1DPROC)GPA("glTexImage1D");
    glTexImage2D                = (PFNGLTEXIMAGE2DPROC)GPA("glTexImage2D");
    glTexParameterf             = (PFNGLTEXPARAMETERFPROC)GPA("glTexParameterf");
    glTexParameterfv            = (PFNGLTEXPARAMETERFVPROC)GPA("glTexParameterfv");
    glTexParameteri             = (PFNGLTEXPARAMETERIPROC)GPA("glTexParameteri");
    glTexParameteriv            = (PFNGLTEXPARAMETERIVPROC)GPA("glTexParameteriv");
    glTexSubImage1D             = (PFNGLTEXSUBIMAGE1DPROC)GPA("glTexSubImage1D");
    glTexSubImage2D             = (PFNGLTEXSUBIMAGE2DPROC)GPA("glTexSubImage2D");
    glTranslated                = (PFNGLTRANSLATEDPROC)GPA("glTranslated");
    glTranslatef                = (PFNGLTRANSLATEFPROC)GPA("glTranslatef");
    glVertex2d                  = (PFNGLVERTEX2DPROC)GPA("glVertex2d");
    glVertex2dv                 = (PFNGLVERTEX2DVPROC)GPA("glVertex2dv");
    glVertex2f                  = (PFNGLVERTEX2FPROC)GPA("glVertex2f");
    glVertex2fv                 = (PFNGLVERTEX2FVPROC)GPA("glVertex2fv");
    glVertex2i                  = (PFNGLVERTEX2IPROC)GPA("glVertex2i");
    glVertex2iv                 = (PFNGLVERTEX2IVPROC)GPA("glVertex2iv");
    glVertex2s                  = (PFNGLVERTEX2SPROC)GPA("glVertex2s");
    glVertex2sv                 = (PFNGLVERTEX2SVPROC)GPA("glVertex2sv");
    glVertex3d                  = (PFNGLVERTEX3DPROC)GPA("glVertex3d");
    glVertex3dv                 = (PFNGLVERTEX3DVPROC)GPA("glVertex3dv");
    glVertex3f                  = (PFNGLVERTEX3FPROC)GPA("glVertex3f");
    glVertex3fv                 = (PFNGLVERTEX3FVPROC)GPA("glVertex3fv");
    glVertex3i                  = (PFNGLVERTEX3IPROC)GPA("glVertex3i");
    glVertex3iv                 = (PFNGLVERTEX3IVPROC)GPA("glVertex3iv");
    glVertex3s                  = (PFNGLVERTEX3SPROC)GPA("glVertex3s");
    glVertex3sv                 = (PFNGLVERTEX3SVPROC)GPA("glVertex3sv");
    glVertex4d                  = (PFNGLVERTEX4DPROC)GPA("glVertex4d");
    glVertex4dv                 = (PFNGLVERTEX4DVPROC)GPA("glVertex4dv");
    glVertex4f                  = (PFNGLVERTEX4FPROC)GPA("glVertex4f");
    glVertex4fv                 = (PFNGLVERTEX4FVPROC)GPA("glVertex4fv");
    glVertex4i                  = (PFNGLVERTEX4IPROC)GPA("glVertex4i");
    glVertex4iv                 = (PFNGLVERTEX4IVPROC)GPA("glVertex4iv");
    glVertex4s                  = (PFNGLVERTEX4SPROC)GPA("glVertex4s");
    glVertex4sv                 = (PFNGLVERTEX4SVPROC)GPA("glVertex4sv");
    glVertexPointer             = (PFNGLVERTEXPOINTERPROC)GPA("glVertexPointer");
    glViewport                  = (PFNGLVIEWPORTPROC)GPA("glViewport");

    #undef GPA

    if (_tcsstr(pszPathGL, _T("opengl32.dll")))
    {
        hLib = LoadLibrary(_T("gdi32.dll"));

        if (!hLib)
        {
            GLdriverUnload(pDriver);
            return GL_FALSE;
        }

        pDriver->hLibOS = hLib;

        #define GPA(x) GetProcAddress(hLib, x)

        /* Non-WGL GDI API Functions. */
        my_ChoosePixelFormat   = (PFNCHOOSEPIXELFORMATPROC)GPA("ChoosePixelFormat");
        my_DescribePixelFormat = (PFNDESCRIBEPIXELFORMATPROC)GPA("DescribePixelFormat");
        my_GetPixelFormat      = (PFNGETPIXELFORMATPROC)GPA("GetPixelFormat");
        my_SetPixelFormat      = (PFNSETPIXELFORMATPROC)GPA("SetPixelFormat");
        my_SwapBuffers         = (PFNSWAPBUFFERSPROC)GPA("SwapBuffers");

        #undef GPA
    }
    else
    {
        #define GPA(x) GetProcAddress((HMODULE)pDriver->hLibGL, x)

        my_ChoosePixelFormat   = (PFNCHOOSEPIXELFORMATPROC)GPA("wglChoosePixelFormat");
        my_DescribePixelFormat = (PFNDESCRIBEPIXELFORMATPROC)GPA("wglDescribePixelFormat");
        my_GetPixelFormat      = (PFNGETPIXELFORMATPROC)GPA("wglGetPixelFormat");
        my_SetPixelFormat      = (PFNSETPIXELFORMATPROC)GPA("wglSetPixelFormat");
        my_SwapBuffers         = (PFNSWAPBUFFERSPROC)GPA("wglSwapBuffers");

        #undef GPA
    }

    if (pszPathGLU)
    {
        hLib = LoadLibrary(pszPathGLU);

        if (!hLib)
        {
            GLdriverUnload(pDriver);
            return GL_FALSE;
        }

        pDriver->hLibGLU = hLib;

        #define GPA(x) GetProcAddress(hLib, x)

        /* GLU 1.2 Core API Functions. */
        gluBeginCurve               = (PFNGLUBEGINCURVEPROC)GPA("gluBeginCurve");
        gluBeginPolygon             = (PFNGLUBEGINPOLYGONPROC)GPA("gluBeginPolygon");
        gluBeginSurface             = (PFNGLUBEGINSURFACEPROC)GPA("gluBeginSurface");
        gluBeginTrim                = (PFNGLUBEGINTRIMPROC)GPA("gluBeginTrim");
        gluBuild1DMipmaps           = (PFNGLUBUILD1DMIPMAPSPROC)GPA("gluBuild1DMipmaps");
        gluBuild2DMipmaps           = (PFNGLUBUILD2DMIPMAPSPROC)GPA("gluBuild2DMipmaps");
        gluCylinder                 = (PFNGLUCYLINDERPROC)GPA("gluCylinder");
        gluDeleteNurbsRenderer      = (PFNGLUDELETENURBSRENDERERPROC)GPA("gluDeleteNurbsRenderer");
        gluDeleteQuadric            = (PFNGLUDELETEQUADRICPROC)GPA("gluDeleteQuadric");
        gluDeleteTess               = (PFNGLUDELETETESSPROC)GPA("gluDeleteTess");
        gluDisk                     = (PFNGLUDISKPROC)GPA("gluDisk");
        gluEndCurve                 = (PFNGLUENDCURVEPROC)GPA("gluEndCurve");
        gluEndPolygon               = (PFNGLUENDPOLYGONPROC)GPA("gluEndPolygon");
        gluEndSurface               = (PFNGLUENDSURFACEPROC)GPA("gluEndSurface");
        gluEndTrim                  = (PFNGLUENDTRIMPROC)GPA("gluEndTrim");
        gluErrorString              = (PFNGLUERRORSTRINGPROC)GPA("gluErrorString");
        gluGetNurbsProperty         = (PFNGLUGETNURBSPROPERTYPROC)GPA("gluGetNurbsProperty");
        gluGetString                = (PFNGLUGETSTRINGPROC)GPA("gluGetString");
        gluGetTessProperty          = (PFNGLUGETTESSPROPERTYPROC)GPA("gluGetTessProperty");
        gluLoadSamplingMatrices     = (PFNGLULOADSAMPLINGMATRICESPROC)GPA("gluLoadSamplingMatrices");
        gluLookAt                   = (PFNGLULOOKATPROC)GPA("gluLookAt");
        gluNewNurbsRenderer         = (PFNGLUNEWNURBSRENDERERPROC)GPA("gluNewNurbsRenderer");
        gluNewQuadric               = (PFNGLUNEWQUADRICPROC)GPA("gluNewQuadric");
        gluNewTess                  = (PFNGLUNEWTESSPROC)GPA("gluNewTess");
        gluNextContour              = (PFNGLUNEXTCONTOURPROC)GPA("gluNextContour");
        gluNurbsCallback            = (PFNGLUNURBSCALLBACKPROC)GPA("gluNurbsCallback");
        gluNurbsCurve               = (PFNGLUNURBSCURVEPROC)GPA("gluNurbsCurve");
        gluNurbsProperty            = (PFNGLUNURBSPROPERTYPROC)GPA("gluNurbsProperty");
        gluNurbsSurface             = (PFNGLUNURBSSURFACEPROC)GPA("gluNurbsSurface");
        gluOrtho2D                  = (PFNGLUORTHO2DPROC)GPA("gluOrtho2D");
        gluPartialDisk              = (PFNGLUPARTIALDISKPROC)GPA("gluPartialDisk");
        gluPerspective              = (PFNGLUPERSPECTIVEPROC)GPA("gluPerspective");
        gluPickMatrix               = (PFNGLUPICKMATRIXPROC)GPA("gluPickMatrix");
        gluProject                  = (PFNGLUPROJECTPROC)GPA("gluProject");
        gluPwlCurve                 = (PFNGLUPWLCURVEPROC)GPA("gluPwlCurve");
        gluQuadricCallback          = (PFNGLUQUADRICCALLBACKPROC)GPA("gluQuadricCallback");
        gluQuadricDrawStyle         = (PFNGLUQUADRICDRAWSTYLEPROC)GPA("gluQuadricDrawStyle");
        gluQuadricNormals           = (PFNGLUQUADRICNORMALSPROC)GPA("gluQuadricNormals");
        gluQuadricOrientation       = (PFNGLUQUADRICORIENTATIONPROC)GPA("gluQuadricOrientation");
        gluQuadricTexture           = (PFNGLUQUADRICTEXTUREPROC)GPA("gluQuadricTexture");
        gluScaleImage               = (PFNGLUSCALEIMAGEPROC)GPA("gluScaleImage");
        gluSphere                   = (PFNGLUSPHEREPROC)GPA("gluSphere");
        gluTessBeginContour         = (PFNGLUTESSBEGINCONTOURPROC)GPA("gluTessBeginContour");
        gluTessBeginPolygon         = (PFNGLUTESSBEGINPOLYGONPROC)GPA("gluTessBeginPolygon");
        gluTessCallback             = (PFNGLUTESSCALLBACKPROC)GPA("gluTessCallback");
        gluTessEndContour           = (PFNGLUTESSENDCONTOURPROC)GPA("gluTessEndContour");
        gluTessEndPolygon           = (PFNGLUTESSENDPOLYGONPROC)GPA("gluTessEndPolygon");
        gluTessNormal               = (PFNGLUTESSNORMALPROC)GPA("gluTessNormal");
        gluTessProperty             = (PFNGLUTESSPROPERTYPROC)GPA("gluTessProperty");
        gluTessVertex               = (PFNGLUTESSVERTEXPROC)GPA("gluTessVertex");
        gluUnProject                = (PFNGLUUNPROJECTPROC)GPA("gluUnProject");

        /* GLU 1.3 Core API Functions. */
        gluCheckExtension           = (PFNGLUCHECKEXTENSIONPROC)GPA("gluCheckExtension");
        gluBuild1DMipmapLevels      = (PFNGLUBUILD1DMIPMAPLEVELSPROC)GPA("gluBuild1DMipmapLevels");
        gluBuild2DMipmapLevels      = (PFNGLUBUILD2DMIPMAPLEVELSPROC)GPA("gluBuild2DMipmapLevels");
        gluBuild3DMipmapLevels      = (PFNGLUBUILD3DMIPMAPLEVELSPROC)GPA("gluBuild3DMipmapLevels");
        gluBuild3DMipmaps           = (PFNGLUBUILD3DMIPMAPSPROC)GPA("gluBuild3DMipmaps");
        gluNurbsCallbackData        = (PFNGLUNURBSCALLBACKDATAPROC)GPA("gluNurbsCallbackData");
        gluUnProject4               = (PFNGLUUNPROJECT4PROC)GPA("gluUnProject4");

        #undef GPA
    }

    return GL_TRUE;
}

void GLdriverInit(GLdriver *pDriver)
{
    #define GPA(x) wglGetProcAddress(x)

    /* OpenGL 1.2. */
    glCopyTexSubImage3D         = (PFNGLCOPYTEXSUBIMAGE3DPROC)GPA("glCopyTexSubImage3D");
    glDrawRangeElements         = (PFNGLDRAWRANGEELEMENTSPROC)GPA("glDrawRangeElements");
    glTexImage3D                = (PFNGLTEXIMAGE3DPROC)GPA("glTexImage3D");
    glTexSubImage3D             = (PFNGLTEXSUBIMAGE3DPROC)GPA("glTexSubImage3D");

    /* OpenGL 1.3. */
    glActiveTexture             = (PFNGLACTIVETEXTUREPROC)GPA("glActiveTexture");
    glClientActiveTexture       = (PFNGLCLIENTACTIVETEXTUREPROC)GPA("glClientActiveTexture");
    glMultiTexCoord1d           = (PFNGLMULTITEXCOORD1DPROC)GPA("glMultiTexCoord1d");
    glMultiTexCoord1dv          = (PFNGLMULTITEXCOORD1DVPROC)GPA("glMultiTexCoord1dv");
    glMultiTexCoord1f           = (PFNGLMULTITEXCOORD1FPROC)GPA("glMultiTexCoord1f");
    glMultiTexCoord1fv          = (PFNGLMULTITEXCOORD1FVPROC)GPA("glMultiTexCoord1fv");
    glMultiTexCoord1i           = (PFNGLMULTITEXCOORD1IPROC)GPA("glMultiTexCoord1i");
    glMultiTexCoord1iv          = (PFNGLMULTITEXCOORD1IVPROC)GPA("glMultiTexCoord1iv");
    glMultiTexCoord1s           = (PFNGLMULTITEXCOORD1SPROC)GPA("glMultiTexCoord1s");
    glMultiTexCoord1sv          = (PFNGLMULTITEXCOORD1SVPROC)GPA("glMultiTexCoord1sv");
    glMultiTexCoord2d           = (PFNGLMULTITEXCOORD2DPROC)GPA("glMultiTexCoord2d");
    glMultiTexCoord2dv          = (PFNGLMULTITEXCOORD2DVPROC)GPA("glMultiTexCoord2dv");
    glMultiTexCoord2f           = (PFNGLMULTITEXCOORD2FPROC)GPA("glMultiTexCoord2f");
    glMultiTexCoord2fv          = (PFNGLMULTITEXCOORD2FVPROC)GPA("glMultiTexCoord2fv");
    glMultiTexCoord2i           = (PFNGLMULTITEXCOORD2IPROC)GPA("glMultiTexCoord2i");
    glMultiTexCoord2iv          = (PFNGLMULTITEXCOORD2IVPROC)GPA("glMultiTexCoord2iv");
    glMultiTexCoord2s           = (PFNGLMULTITEXCOORD2SPROC)GPA("glMultiTexCoord2s");
    glMultiTexCoord2sv          = (PFNGLMULTITEXCOORD2SVPROC)GPA("glMultiTexCoord2sv");
    glMultiTexCoord3d           = (PFNGLMULTITEXCOORD3DPROC)GPA("glMultiTexCoord3d");
    glMultiTexCoord3dv          = (PFNGLMULTITEXCOORD3DVPROC)GPA("glMultiTexCoord3dv");
    glMultiTexCoord3f           = (PFNGLMULTITEXCOORD3FPROC)GPA("glMultiTexCoord3f");
    glMultiTexCoord3fv          = (PFNGLMULTITEXCOORD3FVPROC)GPA("glMultiTexCoord3fv");
    glMultiTexCoord3i           = (PFNGLMULTITEXCOORD3IPROC)GPA("glMultiTexCoord3i");
    glMultiTexCoord3iv          = (PFNGLMULTITEXCOORD3IVPROC)GPA("glMultiTexCoord3iv");
    glMultiTexCoord3s           = (PFNGLMULTITEXCOORD3SPROC)GPA("glMultiTexCoord3s");
    glMultiTexCoord3sv          = (PFNGLMULTITEXCOORD3SVPROC)GPA("glMultiTexCoord3sv");
    glMultiTexCoord4d           = (PFNGLMULTITEXCOORD4DPROC)GPA("glMultiTexCoord4d");
    glMultiTexCoord4dv          = (PFNGLMULTITEXCOORD4DVPROC)GPA("glMultiTexCoord4dv");
    glMultiTexCoord4f           = (PFNGLMULTITEXCOORD4FPROC)GPA("glMultiTexCoord4f");
    glMultiTexCoord4fv          = (PFNGLMULTITEXCOORD4FVPROC)GPA("glMultiTexCoord4fv");
    glMultiTexCoord4i           = (PFNGLMULTITEXCOORD4IPROC)GPA("glMultiTexCoord4i");
    glMultiTexCoord4iv          = (PFNGLMULTITEXCOORD4IVPROC)GPA("glMultiTexCoord4iv");
    glMultiTexCoord4s           = (PFNGLMULTITEXCOORD4SPROC)GPA("glMultiTexCoord4s");
    glMultiTexCoord4sv          = (PFNGLMULTITEXCOORD4SVPROC)GPA("glMultiTexCoord4sv");
    glLoadTransposeMatrixf      = (PFNGLLOADTRANSPOSEMATRIXFPROC)GPA("glLoadTransposeMatrixf");
    glLoadTransposeMatrixd      = (PFNGLLOADTRANSPOSEMATRIXDPROC)GPA("glLoadTransposeMatrixd");
    glMultTransposeMatrixf      = (PFNGLMULTTRANSPOSEMATRIXFPROC)GPA("glMultTransposeMatrixf");
    glMultTransposeMatrixd      = (PFNGLMULTTRANSPOSEMATRIXDPROC)GPA("glMultTransposeMatrixd");
    glSampleCoverage            = (PFNGLSAMPLECOVERAGEPROC)GPA("glSampleCoverage");
    glCompressedTexImage3D      = (PFNGLCOMPRESSEDTEXIMAGE3DPROC)GPA("glCompressedTexImage3D");
    glCompressedTexImage2D      = (PFNGLCOMPRESSEDTEXIMAGE2DPROC)GPA("glCompressedTexImage2D");
    glCompressedTexImage1D      = (PFNGLCOMPRESSEDTEXIMAGE1DPROC)GPA("glCompressedTexImage1D");
    glCompressedTexSubImage3D   = (PFNGLCOMPRESSEDTEXSUBIMAGE3DPROC)GPA("glCompressedTexSubImage3D");
    glCompressedTexSubImage2D   = (PFNGLCOMPRESSEDTEXSUBIMAGE2DPROC)GPA("glCompressedTexSubImage2D");
    glCompressedTexSubImage1D   = (PFNGLCOMPRESSEDTEXSUBIMAGE1DPROC)GPA("glCompressedTexSubImage1D");
    glGetCompressedTexImage     = (PFNGLGETCOMPRESSEDTEXIMAGEPROC)GPA("glGetCompressedTexImage");

    /* OpenGL 1.4. */
    glMultiDrawArrays           = (PFNGLMULTIDRAWARRAYSPROC)GPA("glMultiDrawArrays");
    glMultiDrawElements         = (PFNGLMULTIDRAWELEMENTSPROC)GPA("glMultiDrawElements");
    glPointParameterf           = (PFNGLPOINTPARAMETERFPROC)GPA("glPointParameterf");
    glPointParameterfv          = (PFNGLPOINTPARAMETERFVPROC)GPA("glPointParameterfv");
    glSecondaryColor3b          = (PFNGLSECONDARYCOLOR3BPROC)GPA("glSecondaryColor3b");
    glSecondaryColor3bv         = (PFNGLSECONDARYCOLOR3BVPROC)GPA("glSecondaryColor3bv");
    glSecondaryColor3d          = (PFNGLSECONDARYCOLOR3DPROC)GPA("glSecondaryColor3d");
    glSecondaryColor3dv         = (PFNGLSECONDARYCOLOR3DVPROC)GPA("glSecondaryColor3dv");
    glSecondaryColor3f          = (PFNGLSECONDARYCOLOR3FPROC)GPA("glSecondaryColor3f");
    glSecondaryColor3fv         = (PFNGLSECONDARYCOLOR3FVPROC)GPA("glSecondaryColor3fv");
    glSecondaryColor3i          = (PFNGLSECONDARYCOLOR3IPROC)GPA("glSecondaryColor3i");
    glSecondaryColor3iv         = (PFNGLSECONDARYCOLOR3IVPROC)GPA("glSecondaryColor3iv");
    glSecondaryColor3s          = (PFNGLSECONDARYCOLOR3SPROC)GPA("glSecondaryColor3s");
    glSecondaryColor3sv         = (PFNGLSECONDARYCOLOR3SVPROC)GPA("glSecondaryColor3sv");
    glSecondaryColor3ub         = (PFNGLSECONDARYCOLOR3UBPROC)GPA("glSecondaryColor3ub");
    glSecondaryColor3ubv        = (PFNGLSECONDARYCOLOR3UBVPROC)GPA("glSecondaryColor3ubv");
    glSecondaryColor3ui         = (PFNGLSECONDARYCOLOR3UIPROC)GPA("glSecondaryColor3ui");
    glSecondaryColor3uiv        = (PFNGLSECONDARYCOLOR3UIVPROC)GPA("glSecondaryColor3uiv");
    glSecondaryColor3us         = (PFNGLSECONDARYCOLOR3USPROC)GPA("glSecondaryColor3us");
    glSecondaryColor3usv        = (PFNGLSECONDARYCOLOR3USVPROC)GPA("glSecondaryColor3usv");
    glSecondaryColorPointer     = (PFNGLSECONDARYCOLORPOINTERPROC)GPA("glSecondaryColorPointer");
    glBlendFuncSeparate         = (PFNGLBLENDFUNCSEPARATEPROC)GPA("glBlendFuncSeparate");
    glWindowPos2d               = (PFNGLWINDOWPOS2DPROC)GPA("glWindowPos2d");
    glWindowPos2f               = (PFNGLWINDOWPOS2FPROC)GPA("glWindowPos2f");
    glWindowPos2i               = (PFNGLWINDOWPOS2IPROC)GPA("glWindowPos2i");
    glWindowPos2s               = (PFNGLWINDOWPOS2SPROC)GPA("glWindowPos2s");
    glWindowPos2dv              = (PFNGLWINDOWPOS2DVPROC)GPA("glWindowPos2dv");
    glWindowPos2fv              = (PFNGLWINDOWPOS2FVPROC)GPA("glWindowPos2fv");
    glWindowPos2iv              = (PFNGLWINDOWPOS2IVPROC)GPA("glWindowPos2iv");
    glWindowPos2sv              = (PFNGLWINDOWPOS2SVPROC)GPA("glWindowPos2sv");
    glWindowPos3d               = (PFNGLWINDOWPOS3DPROC)GPA("glWindowPos3d");
    glWindowPos3f               = (PFNGLWINDOWPOS3FPROC)GPA("glWindowPos3f");
    glWindowPos3i               = (PFNGLWINDOWPOS3IPROC)GPA("glWindowPos3i");
    glWindowPos3s               = (PFNGLWINDOWPOS3SPROC)GPA("glWindowPos3s");
    glWindowPos3dv              = (PFNGLWINDOWPOS3DVPROC)GPA("glWindowPos3dv");
    glWindowPos3fv              = (PFNGLWINDOWPOS3FVPROC)GPA("glWindowPos3fv");
    glWindowPos3iv              = (PFNGLWINDOWPOS3IVPROC)GPA("glWindowPos3iv");
    glWindowPos3sv              = (PFNGLWINDOWPOS3SVPROC)GPA("glWindowPos3sv");

    /* OpenGL 1.5. */
    glGenQueries                = (PFNGLGENQUERIESPROC)GPA("glGenQueries");
    glDeleteQueries             = (PFNGLDELETEQUERIESPROC)GPA("glDeleteQueries");
    glIsQuery                   = (PFNGLISQUERYPROC)GPA("glIsQuery");
    glBeginQuery                = (PFNGLBEGINQUERYPROC)GPA("glBeginQuery");
    glEndQuery                  = (PFNGLENDQUERYPROC)GPA("glEndQuery");
    glGetQueryiv                = (PFNGLGETQUERYIVPROC)GPA("glGetQueryiv");
    glGetQueryObjectiv          = (PFNGLGETQUERYOBJECTIVPROC)GPA("glGetQueryObjectiv");
    glGetQueryObjectuiv         = (PFNGLGETQUERYOBJECTUIVPROC)GPA("glGetQueryObjectuiv");
    glBindBuffer                = (PFNGLBINDBUFFERPROC)GPA("glBindBuffer");
    glDeleteBuffers             = (PFNGLDELETEBUFFERSPROC)GPA("glDeleteBuffers");
    glGenBuffers                = (PFNGLGENBUFFERSPROC)GPA("glGenBuffers");
    glIsBuffer                  = (PFNGLISBUFFERPROC)GPA("glIsBuffer");
    glBufferData                = (PFNGLBUFFERDATAPROC)GPA("glBufferData");
    glBufferSubData             = (PFNGLBUFFERSUBDATAPROC)GPA("glBufferSubData");
    glGetBufferSubData          = (PFNGLGETBUFFERSUBDATAPROC)GPA("glGetBufferSubData");
    glMapBuffer                 = (PFNGLMAPBUFFERPROC)GPA("glMapBuffer");
    glUnmapBuffer               = (PFNGLUNMAPBUFFERPROC)GPA("glUnmapBuffer");
    glGetBufferParameteriv      = (PFNGLGETBUFFERPARAMETERIVPROC)GPA("glGetBufferParameteriv");
    glGetBufferPointerv         = (PFNGLGETBUFFERPOINTERVPROC)GPA("glGetBufferPointerv");

    /* OpenGL 2.0. */
    glBlendEquationSeparate     = (PFNGLBLENDEQUATIONSEPARATEPROC)GPA("glBlendEquationSeparate");
    glDrawBuffers               = (PFNGLDRAWBUFFERSPROC)GPA("glDrawBuffers");
    glStencilOpSeparate         = (PFNGLSTENCILOPSEPARATEPROC)GPA("glStencilOpSeparate");
    glStencilFuncSeparate       = (PFNGLSTENCILFUNCSEPARATEPROC)GPA("glStencilFuncSeparate");
    glStencilMaskSeparate       = (PFNGLSTENCILMASKSEPARATEPROC)GPA("glStencilMaskSeparate");
    glAttachShader              = (PFNGLATTACHSHADERPROC)GPA("glAttachShader");
    glBindAttribLocation        = (PFNGLBINDATTRIBLOCATIONPROC)GPA("glBindAttribLocation");
    glCompileShader             = (PFNGLCOMPILESHADERPROC)GPA("glCompileShader");
    glCreateProgram             = (PFNGLCREATEPROGRAMPROC)GPA("glCreateProgram");
    glCreateShader              = (PFNGLCREATESHADERPROC)GPA("glCreateShader");
    glDeleteProgram             = (PFNGLDELETEPROGRAMPROC)GPA("glDeleteProgram");
    glDeleteShader              = (PFNGLDELETESHADERPROC)GPA("glDeleteShader");
    glDetachShader              = (PFNGLDETACHSHADERPROC)GPA("glDetachShader");
    glDisableVertexAttribArray  = (PFNGLDISABLEVERTEXATTRIBARRAYPROC)GPA("glDisableVertexAttribArray");
    glEnableVertexAttribArray   = (PFNGLENABLEVERTEXATTRIBARRAYPROC)GPA("glEnableVertexAttribArray");
    glGetActiveAttrib           = (PFNGLGETACTIVEATTRIBPROC)GPA("glGetActiveAttrib");
    glGetActiveUniform          = (PFNGLGETACTIVEUNIFORMPROC)GPA("glGetActiveUniform");
    glGetAttachedShaders        = (PFNGLGETATTACHEDSHADERSPROC)GPA("glGetAttachedShaders");
    glGetAttribLocation         = (PFNGLGETATTRIBLOCATIONPROC)GPA("glGetAttribLocation");
    glGetProgramiv              = (PFNGLGETPROGRAMIVPROC)GPA("glGetProgramiv");
    glGetProgramInfoLog         = (PFNGLGETPROGRAMINFOLOGPROC)GPA("glGetProgramInfoLog");
    glGetShaderiv               = (PFNGLGETSHADERIVPROC)GPA("glGetShaderiv");
    glGetShaderInfoLog          = (PFNGLGETSHADERINFOLOGPROC)GPA("glGetShaderInfoLog");
    glGetShaderSource           = (PFNGLGETSHADERSOURCEPROC)GPA("glGetShaderSource");
    glGetUniformLocation        = (PFNGLGETUNIFORMLOCATIONPROC)GPA("glGetUniformLocation");
    glGetUniformfv              = (PFNGLGETUNIFORMFVPROC)GPA("glGetUniformfv");
    glGetUniformiv              = (PFNGLGETUNIFORMIVPROC)GPA("glGetUniformiv");
    glGetVertexAttribdv         = (PFNGLGETVERTEXATTRIBDVPROC)GPA("glGetVertexAttribdv");
    glGetVertexAttribfv         = (PFNGLGETVERTEXATTRIBFVPROC)GPA("glGetVertexAttribfv");
    glGetVertexAttribiv         = (PFNGLGETVERTEXATTRIBIVPROC)GPA("glGetVertexAttribiv");
    glGetVertexAttribPointerv   = (PFNGLGETVERTEXATTRIBPOINTERVPROC)GPA("glGetVertexAttribPointerv");
    glIsProgram                 = (PFNGLISPROGRAMPROC)GPA("glIsProgram");
    glIsShader                  = (PFNGLISSHADERPROC)GPA("glIsShader");
    glLinkProgram               = (PFNGLLINKPROGRAMPROC)GPA("glLinkProgram");
    glShaderSource              = (PFNGLSHADERSOURCEPROC)GPA("glShaderSource");
    glUseProgram                = (PFNGLUSEPROGRAMPROC)GPA("glUseProgram");
    glUniform1f                 = (PFNGLUNIFORM1FPROC)GPA("glUniform1f");
    glUniform2f                 = (PFNGLUNIFORM2FPROC)GPA("glUniform2f");
    glUniform3f                 = (PFNGLUNIFORM3FPROC)GPA("glUniform3f");
    glUniform4f                 = (PFNGLUNIFORM4FPROC)GPA("glUniform4f");
    glUniform1i                 = (PFNGLUNIFORM1IPROC)GPA("glUniform1i");
    glUniform2i                 = (PFNGLUNIFORM2IPROC)GPA("glUniform2i");
    glUniform3i                 = (PFNGLUNIFORM3IPROC)GPA("glUniform3i");
    glUniform4i                 = (PFNGLUNIFORM4IPROC)GPA("glUniform4i");
    glUniform1fv                = (PFNGLUNIFORM1FVPROC)GPA("glUniform1fv");
    glUniform2fv                = (PFNGLUNIFORM2FVPROC)GPA("glUniform2fv");
    glUniform3fv                = (PFNGLUNIFORM3FVPROC)GPA("glUniform3fv");
    glUniform4fv                = (PFNGLUNIFORM4FVPROC)GPA("glUniform4fv");
    glUniform1iv                = (PFNGLUNIFORM1IVPROC)GPA("glUniform1iv");
    glUniform2iv                = (PFNGLUNIFORM2IVPROC)GPA("glUniform2iv");
    glUniform3iv                = (PFNGLUNIFORM3IVPROC)GPA("glUniform3iv");
    glUniform4iv                = (PFNGLUNIFORM4IVPROC)GPA("glUniform4iv");
    glUniformMatrix2fv          = (PFNGLUNIFORMMATRIX2FVPROC)GPA("glUniformMatrix2fv");
    glUniformMatrix3fv          = (PFNGLUNIFORMMATRIX3FVPROC)GPA("glUniformMatrix3fv");
    glUniformMatrix4fv          = (PFNGLUNIFORMMATRIX4FVPROC)GPA("glUniformMatrix4fv");
    glValidateProgram           = (PFNGLVALIDATEPROGRAMPROC)GPA("glValidateProgram");
    glVertexAttrib1d            = (PFNGLVERTEXATTRIB1DPROC)GPA("glVertexAttrib1d");
    glVertexAttrib1dv           = (PFNGLVERTEXATTRIB1DVPROC)GPA("glVertexAttrib1dv");
    glVertexAttrib1f            = (PFNGLVERTEXATTRIB1FPROC)GPA("glVertexAttrib1f");
    glVertexAttrib1fv           = (PFNGLVERTEXATTRIB1FVPROC)GPA("glVertexAttrib1fv");
    glVertexAttrib1s            = (PFNGLVERTEXATTRIB1SPROC)GPA("glVertexAttrib1s");
    glVertexAttrib1sv           = (PFNGLVERTEXATTRIB1SVPROC)GPA("glVertexAttrib1sv");
    glVertexAttrib2d            = (PFNGLVERTEXATTRIB2DPROC)GPA("glVertexAttrib2d");
    glVertexAttrib2dv           = (PFNGLVERTEXATTRIB2DVPROC)GPA("glVertexAttrib2dv");
    glVertexAttrib2f            = (PFNGLVERTEXATTRIB2FPROC)GPA("glVertexAttrib2f");
    glVertexAttrib2fv           = (PFNGLVERTEXATTRIB2FVPROC)GPA("glVertexAttrib2fv");
    glVertexAttrib2s            = (PFNGLVERTEXATTRIB2SPROC)GPA("glVertexAttrib2s");
    glVertexAttrib2sv           = (PFNGLVERTEXATTRIB2SVPROC)GPA("glVertexAttrib2sv");
    glVertexAttrib3d            = (PFNGLVERTEXATTRIB3DPROC)GPA("glVertexAttrib3d");
    glVertexAttrib3dv           = (PFNGLVERTEXATTRIB3DVPROC)GPA("glVertexAttrib3dv");
    glVertexAttrib3f            = (PFNGLVERTEXATTRIB3FPROC)GPA("glVertexAttrib3f");
    glVertexAttrib3fv           = (PFNGLVERTEXATTRIB3FVPROC)GPA("glVertexAttrib3fv");
    glVertexAttrib3s            = (PFNGLVERTEXATTRIB3SPROC)GPA("glVertexAttrib3s");
    glVertexAttrib3sv           = (PFNGLVERTEXATTRIB3SVPROC)GPA("glVertexAttrib3sv");
    glVertexAttrib4Nbv          = (PFNGLVERTEXATTRIB4NBVPROC)GPA("glVertexAttrib4Nbv");
    glVertexAttrib4Niv          = (PFNGLVERTEXATTRIB4NIVPROC)GPA("glVertexAttrib4Niv");
    glVertexAttrib4Nsv          = (PFNGLVERTEXATTRIB4NSVPROC)GPA("glVertexAttrib4Nsv");
    glVertexAttrib4Nub          = (PFNGLVERTEXATTRIB4NUBPROC)GPA("glVertexAttrib4Nub");
    glVertexAttrib4Nubv         = (PFNGLVERTEXATTRIB4NUBVPROC)GPA("glVertexAttrib4Nubv");
    glVertexAttrib4Nuiv         = (PFNGLVERTEXATTRIB4NUIVPROC)GPA("glVertexAttrib4Nuiv");
    glVertexAttrib4Nusv         = (PFNGLVERTEXATTRIB4NUSVPROC)GPA("glVertexAttrib4Nusv");
    glVertexAttrib4bv           = (PFNGLVERTEXATTRIB4BVPROC)GPA("glVertexAttrib4bv");
    glVertexAttrib4d            = (PFNGLVERTEXATTRIB4DPROC)GPA("glVertexAttrib4d");
    glVertexAttrib4dv           = (PFNGLVERTEXATTRIB4DVPROC)GPA("glVertexAttrib4dv");
    glVertexAttrib4f            = (PFNGLVERTEXATTRIB4FPROC)GPA("glVertexAttrib4f");
    glVertexAttrib4fv           = (PFNGLVERTEXATTRIB4FVPROC)GPA("glVertexAttrib4fv");
    glVertexAttrib4iv           = (PFNGLVERTEXATTRIB4IVPROC)GPA("glVertexAttrib4iv");
    glVertexAttrib4s            = (PFNGLVERTEXATTRIB4SPROC)GPA("glVertexAttrib4s");
    glVertexAttrib4sv           = (PFNGLVERTEXATTRIB4SVPROC)GPA("glVertexAttrib4sv");
    glVertexAttrib4ubv          = (PFNGLVERTEXATTRIB4UBVPROC)GPA("glVertexAttrib4ubv");
    glVertexAttrib4uiv          = (PFNGLVERTEXATTRIB4UIVPROC)GPA("glVertexAttrib4uiv");
    glVertexAttrib4usv          = (PFNGLVERTEXATTRIB4USVPROC)GPA("glVertexAttrib4usv");
    glVertexAttribPointer       = (PFNGLVERTEXATTRIBPOINTERPROC)GPA("glVertexAttribPointer");

    /* WGL_ARB_extensions_string. */
    wglGetExtensionsStringARB   = (PFNWGLGETEXTENSIONSSTRINGARBPROC)GPA("wglGetExtensionsStringARB");

    #undef GPA

    InitDriverStrings(pDriver);
}

void GLdriverUnload(GLdriver *pDriver)
{
    if (pDriver->hLibGLU)
    {
        FreeLibrary(pDriver->hLibGLU);
        pDriver->hLibGLU = NULL;
    }

    if (pDriver->hLibGL)
    {
        FreeLibrary(pDriver->hLibGL);
        pDriver->hLibGL = NULL;
    }

    if (pDriver->hLibOS)
    {
        FreeLibrary(pDriver->hLibOS);
        pDriver->hLibOS = NULL;
    }

    if (pDriver->pszExt)
    {
        free(pDriver->pszExt);
        pDriver->pszExt = NULL;
    }

    if (pDriver->pszExtWGL)
    {
        free(pDriver->pszExtWGL);
        pDriver->pszExtWGL = NULL;
    }

    if (pDriver->pszVersionGL)
    {
        free(pDriver->pszVersionGL);
        pDriver->pszVersionGL = NULL;
    }

    if (pDriver->pszVersionGLU)
    {
        free(pDriver->pszVersionGLU);
        pDriver->pszVersionGLU = NULL;
    }

    if (pDriver->pszVersionShader)
    {
        free(pDriver->pszVersionShader);
        pDriver->pszVersionShader = NULL;
    }

    if (pDriver->pszRenderer)
    {
        free(pDriver->pszRenderer);
        pDriver->pszRenderer = NULL;
    }
    
    if (pDriver->pszVendor)
    {
        free(pDriver->pszVendor);
        pDriver->pszVendor = NULL;
    }

    if (pDriver->pszDriverName)
    {
        free(pDriver->pszDriverName);
        pDriver->pszDriverName = NULL;
    }

    if (pDriver->pszDriverVersion)
    {
        free(pDriver->pszDriverVersion);
        pDriver->pszDriverVersion = NULL;
    }

    /* Non-WGL GDI Core API Functions. */
    my_ChoosePixelFormat        = NULL;
    my_DescribePixelFormat      = NULL;
    my_GetPixelFormat           = NULL;
    my_SetPixelFormat           = NULL;
    my_SwapBuffers              = NULL;

    /* WGL Core API Functions. */
    my_wglCopyContext           = NULL;
    my_wglCreateContext         = NULL;
    my_wglCreateLayerContext    = NULL;
    my_wglDeleteContext         = NULL;
    my_wglDescribeLayerPlane    = NULL;
    my_wglGetCurrentContext     = NULL;
    my_wglGetCurrentDC          = NULL;
    my_wglGetLayerPaletteEntries= NULL;
    my_wglGetProcAddress        = NULL;
    my_wglMakeCurrent           = NULL;
    my_wglRealizeLayerPalette   = NULL;
    my_wglSetLayerPaletteEntries= NULL;
    my_wglShareLists            = NULL;
    my_wglSwapLayerBuffers      = NULL;
    my_wglUseFontBitmapsA       = NULL;
    my_wglUseFontBitmapsW       = NULL;
    my_wglUseFontOutlinesA      = NULL;
    my_wglUseFontOutlinesW      = NULL;

    /* OpenGL 1.1 Core API Functions. */
    glAccum                     = NULL;
    glAlphaFunc                 = NULL;
    glAreTexturesResident       = NULL;
    glArrayElement              = NULL;
    glBegin                     = NULL;
    glBindTexture               = NULL;
    glBitmap                    = NULL;
    glBlendFunc                 = NULL;
    glCallList                  = NULL;
    glCallLists                 = NULL;
    glClear                     = NULL;
    glClearAccum                = NULL;
    glClearColor                = NULL;
    glClearDepth                = NULL;
    glClearIndex                = NULL;
    glClearStencil              = NULL;
    glClipPlane                 = NULL;
    glColor3b                   = NULL;
    glColor3bv                  = NULL;
    glColor3d                   = NULL;
    glColor3dv                  = NULL;
    glColor3f                   = NULL;
    glColor3fv                  = NULL;
    glColor3i                   = NULL;
    glColor3iv                  = NULL;
    glColor3s                   = NULL;
    glColor3sv                  = NULL;
    glColor3ub                  = NULL;
    glColor3ubv                 = NULL;
    glColor3ui                  = NULL;
    glColor3uiv                 = NULL;
    glColor3us                  = NULL;
    glColor3usv                 = NULL;
    glColor4b                   = NULL;
    glColor4bv                  = NULL;
    glColor4d                   = NULL;
    glColor4dv                  = NULL;
    glColor4f                   = NULL;
    glColor4fv                  = NULL;
    glColor4i                   = NULL;
    glColor4iv                  = NULL;
    glColor4s                   = NULL;
    glColor4sv                  = NULL;
    glColor4ub                  = NULL;
    glColor4ubv                 = NULL;
    glColor4ui                  = NULL;
    glColor4uiv                 = NULL;
    glColor4us                  = NULL;
    glColor4usv                 = NULL;
    glColorMask                 = NULL;
    glColorMaterial             = NULL;
    glColorPointer              = NULL;
    glCopyPixels                = NULL;
    glCopyTexImage1D            = NULL;
    glCopyTexImage2D            = NULL;
    glCopyTexSubImage1D         = NULL;
    glCopyTexSubImage2D         = NULL;
    glCullFace                  = NULL;
    glDeleteLists               = NULL;
    glDeleteTextures            = NULL;
    glDepthFunc                 = NULL;
    glDepthMask                 = NULL;
    glDepthRange                = NULL;
    glDisable                   = NULL;
    glDisableClientState        = NULL;
    glDrawArrays                = NULL;
    glDrawBuffer                = NULL;
    glDrawElements              = NULL;
    glDrawPixels                = NULL;
    glEdgeFlag                  = NULL;
    glEdgeFlagPointer           = NULL;
    glEdgeFlagv                 = NULL;
    glEnable                    = NULL;
    glEnableClientState         = NULL;
    glEnd                       = NULL;
    glEndList                   = NULL;
    glEvalCoord1d               = NULL;
    glEvalCoord1dv              = NULL;
    glEvalCoord1f               = NULL;
    glEvalCoord1fv              = NULL;
    glEvalCoord2d               = NULL;
    glEvalCoord2dv              = NULL;
    glEvalCoord2f               = NULL;
    glEvalCoord2fv              = NULL;
    glEvalMesh1                 = NULL;
    glEvalMesh2                 = NULL;
    glEvalPoint1                = NULL;
    glEvalPoint2                = NULL;
    glFeedbackBuffer            = NULL;
    glFinish                    = NULL;
    glFlush                     = NULL;
    glFogf                      = NULL;
    glFogfv                     = NULL;
    glFogi                      = NULL;
    glFogiv                     = NULL;
    glFrontFace                 = NULL;
    glFrustum                   = NULL;
    glGenLists                  = NULL;
    glGenTextures               = NULL;
    glGetBooleanv               = NULL;
    glGetClipPlane              = NULL;
    glGetDoublev                = NULL;
    glGetError                  = NULL;
    glGetFloatv                 = NULL;
    glGetIntegerv               = NULL;
    glGetLightfv                = NULL;
    glGetLightiv                = NULL;
    glGetMapdv                  = NULL;
    glGetMapfv                  = NULL;
    glGetMapiv                  = NULL;
    glGetMaterialfv             = NULL;
    glGetMaterialiv             = NULL;
    glGetPixelMapfv             = NULL;
    glGetPixelMapuiv            = NULL;
    glGetPixelMapusv            = NULL;
    glGetPointerv               = NULL;
    glGetPolygonStipple         = NULL;
    glGetString                 = NULL;
    glGetTexEnvfv               = NULL;
    glGetTexEnviv               = NULL;
    glGetTexGendv               = NULL;
    glGetTexGenfv               = NULL;
    glGetTexGeniv               = NULL;
    glGetTexImage               = NULL;
    glGetTexLevelParameterfv    = NULL;
    glGetTexLevelParameteriv    = NULL;
    glGetTexParameterfv         = NULL;
    glGetTexParameteriv         = NULL;
    glHint                      = NULL;
    glIndexMask                 = NULL;
    glIndexPointer              = NULL;
    glIndexd                    = NULL;
    glIndexdv                   = NULL;
    glIndexf                    = NULL;
    glIndexfv                   = NULL;
    glIndexi                    = NULL;
    glIndexiv                   = NULL;
    glIndexs                    = NULL;
    glIndexsv                   = NULL;
    glIndexub                   = NULL;
    glIndexubv                  = NULL;
    glInitNames                 = NULL;
    glInterleavedArrays         = NULL;
    glIsEnabled                 = NULL;
    glIsList                    = NULL;
    glIsTexture                 = NULL;
    glLightModelf               = NULL;
    glLightModelfv              = NULL;
    glLightModeli               = NULL;
    glLightModeliv              = NULL;
    glLightf                    = NULL;
    glLightfv                   = NULL;
    glLighti                    = NULL;
    glLightiv                   = NULL;
    glLineStipple               = NULL;
    glLineWidth                 = NULL;
    glListBase                  = NULL;
    glLoadIdentity              = NULL;
    glLoadMatrixd               = NULL;
    glLoadMatrixf               = NULL;
    glLoadName                  = NULL;
    glLogicOp                   = NULL;
    glMap1d                     = NULL;
    glMap1f                     = NULL;
    glMap2d                     = NULL;
    glMap2f                     = NULL;
    glMapGrid1d                 = NULL;
    glMapGrid1f                 = NULL;
    glMapGrid2d                 = NULL;
    glMapGrid2f                 = NULL;
    glMaterialf                 = NULL;
    glMaterialfv                = NULL;
    glMateriali                 = NULL;
    glMaterialiv                = NULL;
    glMatrixMode                = NULL;
    glMultMatrixd               = NULL;
    glMultMatrixf               = NULL;
    glNewList                   = NULL;
    glNormal3b                  = NULL;
    glNormal3bv                 = NULL;
    glNormal3d                  = NULL;
    glNormal3dv                 = NULL;
    glNormal3f                  = NULL;
    glNormal3fv                 = NULL;
    glNormal3i                  = NULL;
    glNormal3iv                 = NULL;
    glNormal3s                  = NULL;
    glNormal3sv                 = NULL;
    glNormalPointer             = NULL;
    glOrtho                     = NULL;
    glPassThrough               = NULL;
    glPixelMapfv                = NULL;
    glPixelMapuiv               = NULL;
    glPixelMapusv               = NULL;
    glPixelStoref               = NULL;
    glPixelStorei               = NULL;
    glPixelTransferf            = NULL;
    glPixelTransferi            = NULL;
    glPixelZoom                 = NULL;
    glPointSize                 = NULL;
    glPolygonMode               = NULL;
    glPolygonOffset             = NULL;
    glPolygonStipple            = NULL;
    glPopAttrib                 = NULL;
    glPopClientAttrib           = NULL;
    glPopMatrix                 = NULL;
    glPopName                   = NULL;
    glPrioritizeTextures        = NULL;
    glPushAttrib                = NULL;
    glPushClientAttrib          = NULL;
    glPushMatrix                = NULL;
    glPushName                  = NULL;
    glRasterPos2d               = NULL;
    glRasterPos2dv              = NULL;
    glRasterPos2f               = NULL;
    glRasterPos2fv              = NULL;
    glRasterPos2i               = NULL;
    glRasterPos2iv              = NULL;
    glRasterPos2s               = NULL;
    glRasterPos2sv              = NULL;
    glRasterPos3d               = NULL;
    glRasterPos3dv              = NULL;
    glRasterPos3f               = NULL;
    glRasterPos3fv              = NULL;
    glRasterPos3i               = NULL;
    glRasterPos3iv              = NULL;
    glRasterPos3s               = NULL;
    glRasterPos3sv              = NULL;
    glRasterPos4d               = NULL;
    glRasterPos4dv              = NULL;
    glRasterPos4f               = NULL;
    glRasterPos4fv              = NULL;
    glRasterPos4i               = NULL;
    glRasterPos4iv              = NULL;
    glRasterPos4s               = NULL;
    glRasterPos4sv              = NULL;
    glReadBuffer                = NULL;
    glReadPixels                = NULL;
    glRectd                     = NULL;
    glRectdv                    = NULL;
    glRectf                     = NULL;
    glRectfv                    = NULL;
    glRecti                     = NULL;
    glRectiv                    = NULL;
    glRects                     = NULL;
    glRectsv                    = NULL;
    glRenderMode                = NULL;
    glRotated                   = NULL;
    glRotatef                   = NULL;
    glScaled                    = NULL;
    glScalef                    = NULL;
    glScissor                   = NULL;
    glSelectBuffer              = NULL;
    glShadeModel                = NULL;
    glStencilFunc               = NULL;
    glStencilMask               = NULL;
    glStencilOp                 = NULL;
    glTexCoord1d                = NULL;
    glTexCoord1dv               = NULL;
    glTexCoord1f                = NULL;
    glTexCoord1fv               = NULL;
    glTexCoord1i                = NULL;
    glTexCoord1iv               = NULL;
    glTexCoord1s                = NULL;
    glTexCoord1sv               = NULL;
    glTexCoord2d                = NULL;
    glTexCoord2dv               = NULL;
    glTexCoord2f                = NULL;
    glTexCoord2fv               = NULL;
    glTexCoord2i                = NULL;
    glTexCoord2iv               = NULL;
    glTexCoord2s                = NULL;
    glTexCoord2sv               = NULL;
    glTexCoord3d                = NULL;
    glTexCoord3dv               = NULL;
    glTexCoord3f                = NULL;
    glTexCoord3fv               = NULL;
    glTexCoord3i                = NULL;
    glTexCoord3iv               = NULL;
    glTexCoord3s                = NULL;
    glTexCoord3sv               = NULL;
    glTexCoord4d                = NULL;
    glTexCoord4dv               = NULL;
    glTexCoord4f                = NULL;
    glTexCoord4fv               = NULL;
    glTexCoord4i                = NULL;
    glTexCoord4iv               = NULL;
    glTexCoord4s                = NULL;
    glTexCoord4sv               = NULL;
    glTexCoordPointer           = NULL;
    glTexEnvf                   = NULL;
    glTexEnvfv                  = NULL;
    glTexEnvi                   = NULL;
    glTexEnviv                  = NULL;
    glTexGend                   = NULL;
    glTexGendv                  = NULL;
    glTexGenf                   = NULL;
    glTexGenfv                  = NULL;
    glTexGeni                   = NULL;
    glTexGeniv                  = NULL;
    glTexImage1D                = NULL;
    glTexImage2D                = NULL;
    glTexParameterf             = NULL;
    glTexParameterfv            = NULL;
    glTexParameteri             = NULL;
    glTexParameteriv            = NULL;
    glTexSubImage1D             = NULL;
    glTexSubImage2D             = NULL;
    glTranslated                = NULL;
    glTranslatef                = NULL;
    glVertex2d                  = NULL;
    glVertex2dv                 = NULL;
    glVertex2f                  = NULL;
    glVertex2fv                 = NULL;
    glVertex2i                  = NULL;
    glVertex2iv                 = NULL;
    glVertex2s                  = NULL;
    glVertex2sv                 = NULL;
    glVertex3d                  = NULL;
    glVertex3dv                 = NULL;
    glVertex3f                  = NULL;
    glVertex3fv                 = NULL;
    glVertex3i                  = NULL;
    glVertex3iv                 = NULL;
    glVertex3s                  = NULL;
    glVertex3sv                 = NULL;
    glVertex4d                  = NULL;
    glVertex4dv                 = NULL;
    glVertex4f                  = NULL;
    glVertex4fv                 = NULL;
    glVertex4i                  = NULL;
    glVertex4iv                 = NULL;
    glVertex4s                  = NULL;
    glVertex4sv                 = NULL;
    glVertexPointer             = NULL;
    glViewport                  = NULL;

    /* OpenGL 1.2 Core API Functions. */
    glCopyTexSubImage3D         = NULL;
    glDrawRangeElements         = NULL;
    glTexImage3D                = NULL;
    glTexSubImage3D             = NULL;

    /* OpenGL 1.3 Core API Functions. */
    glActiveTexture             = NULL;
    glClientActiveTexture       = NULL;
    glCompressedTexImage1D      = NULL;
    glCompressedTexImage2D      = NULL;
    glCompressedTexImage3D      = NULL;
    glCompressedTexSubImage1D   = NULL;
    glCompressedTexSubImage2D   = NULL;
    glCompressedTexSubImage3D   = NULL;
    glGetCompressedTexImage     = NULL;
    glLoadTransposeMatrixd      = NULL;
    glLoadTransposeMatrixf      = NULL;
    glMultiTexCoord1d           = NULL;
    glMultiTexCoord1dv          = NULL;
    glMultiTexCoord1f           = NULL;
    glMultiTexCoord1fv          = NULL;
    glMultiTexCoord1i           = NULL;
    glMultiTexCoord1iv          = NULL;
    glMultiTexCoord1s           = NULL;
    glMultiTexCoord1sv          = NULL;
    glMultiTexCoord2d           = NULL;
    glMultiTexCoord2dv          = NULL;
    glMultiTexCoord2f           = NULL;
    glMultiTexCoord2fv          = NULL;
    glMultiTexCoord2i           = NULL;
    glMultiTexCoord2iv          = NULL;
    glMultiTexCoord2s           = NULL;
    glMultiTexCoord2sv          = NULL;
    glMultiTexCoord3d           = NULL;
    glMultiTexCoord3dv          = NULL;
    glMultiTexCoord3f           = NULL;
    glMultiTexCoord3fv          = NULL;
    glMultiTexCoord3i           = NULL;
    glMultiTexCoord3iv          = NULL;
    glMultiTexCoord3s           = NULL;
    glMultiTexCoord3sv          = NULL;
    glMultiTexCoord4d           = NULL;
    glMultiTexCoord4dv          = NULL;
    glMultiTexCoord4f           = NULL;
    glMultiTexCoord4fv          = NULL;
    glMultiTexCoord4i           = NULL;
    glMultiTexCoord4iv          = NULL;
    glMultiTexCoord4s           = NULL;
    glMultiTexCoord4sv          = NULL;
    glMultTransposeMatrixd      = NULL;
    glMultTransposeMatrixf      = NULL;
    glSampleCoverage            = NULL;

    /* OpenGL 1.4 Core API Functions. */
    glBlendFuncSeparate         = NULL;
    glMultiDrawArrays           = NULL;
    glMultiDrawElements         = NULL;
    glPointParameterf           = NULL;
    glPointParameterfv          = NULL;
    glSecondaryColor3b          = NULL;
    glSecondaryColor3bv         = NULL;
    glSecondaryColor3d          = NULL;
    glSecondaryColor3dv         = NULL;
    glSecondaryColor3f          = NULL;
    glSecondaryColor3fv         = NULL;
    glSecondaryColor3i          = NULL;
    glSecondaryColor3iv         = NULL;
    glSecondaryColor3s          = NULL;
    glSecondaryColor3sv         = NULL;
    glSecondaryColor3ub         = NULL;
    glSecondaryColor3ubv        = NULL;
    glSecondaryColor3ui         = NULL;
    glSecondaryColor3uiv        = NULL;
    glSecondaryColor3us         = NULL;
    glSecondaryColor3usv        = NULL;
    glSecondaryColorPointer     = NULL;
    glWindowPos2d               = NULL;
    glWindowPos2dv              = NULL;
    glWindowPos2f               = NULL;
    glWindowPos2fv              = NULL;
    glWindowPos2i               = NULL;
    glWindowPos2iv              = NULL;
    glWindowPos2s               = NULL;
    glWindowPos2sv              = NULL;
    glWindowPos3d               = NULL;
    glWindowPos3dv              = NULL;
    glWindowPos3f               = NULL;
    glWindowPos3fv              = NULL;
    glWindowPos3i               = NULL;
    glWindowPos3iv              = NULL;
    glWindowPos3s               = NULL;
    glWindowPos3sv              = NULL;

    /* OpenGL 1.5 Core API Functions. */
    glGenQueries                = NULL;
    glDeleteQueries             = NULL;
    glIsQuery                   = NULL;
    glBeginQuery                = NULL;
    glEndQuery                  = NULL;
    glGetQueryiv                = NULL;
    glGetQueryObjectiv          = NULL;
    glGetQueryObjectuiv         = NULL;
    glBindBuffer                = NULL;
    glDeleteBuffers             = NULL;
    glGenBuffers                = NULL;
    glIsBuffer                  = NULL;
    glBufferData                = NULL;
    glBufferSubData             = NULL;
    glGetBufferSubData          = NULL;
    glMapBuffer                 = NULL;
    glUnmapBuffer               = NULL;
    glGetBufferParameteriv      = NULL;
    glGetBufferPointerv         = NULL;

    /* OpenGL 2.0 Core API Functions. */
    glBlendEquationSeparate     = NULL;
    glDrawBuffers               = NULL;
    glStencilOpSeparate         = NULL;
    glStencilFuncSeparate       = NULL;
    glStencilMaskSeparate       = NULL;
    glAttachShader              = NULL;
    glBindAttribLocation        = NULL;
    glCompileShader             = NULL;
    glCreateProgram             = NULL;
    glCreateShader              = NULL;
    glDeleteProgram             = NULL;
    glDeleteShader              = NULL;
    glDetachShader              = NULL;
    glDisableVertexAttribArray  = NULL;
    glEnableVertexAttribArray   = NULL;
    glGetActiveAttrib           = NULL;
    glGetActiveUniform          = NULL;
    glGetAttachedShaders        = NULL;
    glGetAttribLocation         = NULL;
    glGetProgramiv              = NULL;
    glGetProgramInfoLog         = NULL;
    glGetShaderiv               = NULL;
    glGetShaderInfoLog          = NULL;
    glGetShaderSource           = NULL;
    glGetUniformLocation        = NULL;
    glGetUniformfv              = NULL;
    glGetUniformiv              = NULL;
    glGetVertexAttribdv         = NULL;
    glGetVertexAttribfv         = NULL;
    glGetVertexAttribiv         = NULL;
    glGetVertexAttribPointerv   = NULL;
    glIsProgram                 = NULL;
    glIsShader                  = NULL;
    glLinkProgram               = NULL;
    glShaderSource              = NULL;
    glUseProgram                = NULL;
    glUniform1f                 = NULL;
    glUniform2f                 = NULL;
    glUniform3f                 = NULL;
    glUniform4f                 = NULL;
    glUniform1i                 = NULL;
    glUniform2i                 = NULL;
    glUniform3i                 = NULL;
    glUniform4i                 = NULL;
    glUniform1fv                = NULL;
    glUniform2fv                = NULL;
    glUniform3fv                = NULL;
    glUniform4fv                = NULL;
    glUniform1iv                = NULL;
    glUniform2iv                = NULL;
    glUniform3iv                = NULL;
    glUniform4iv                = NULL;
    glUniformMatrix2fv          = NULL;
    glUniformMatrix3fv          = NULL;
    glUniformMatrix4fv          = NULL;
    glValidateProgram           = NULL;
    glVertexAttrib1d            = NULL;
    glVertexAttrib1dv           = NULL;
    glVertexAttrib1f            = NULL;
    glVertexAttrib1fv           = NULL;
    glVertexAttrib1s            = NULL;
    glVertexAttrib1sv           = NULL;
    glVertexAttrib2d            = NULL;
    glVertexAttrib2dv           = NULL;
    glVertexAttrib2f            = NULL;
    glVertexAttrib2fv           = NULL;
    glVertexAttrib2s            = NULL;
    glVertexAttrib2sv           = NULL;
    glVertexAttrib3d            = NULL;
    glVertexAttrib3dv           = NULL;
    glVertexAttrib3f            = NULL;
    glVertexAttrib3fv           = NULL;
    glVertexAttrib3s            = NULL;
    glVertexAttrib3sv           = NULL;
    glVertexAttrib4Nbv          = NULL;
    glVertexAttrib4Niv          = NULL;
    glVertexAttrib4Nsv          = NULL;
    glVertexAttrib4Nub          = NULL;
    glVertexAttrib4Nubv         = NULL;
    glVertexAttrib4Nuiv         = NULL;
    glVertexAttrib4Nusv         = NULL;
    glVertexAttrib4bv           = NULL;
    glVertexAttrib4d            = NULL;
    glVertexAttrib4dv           = NULL;
    glVertexAttrib4f            = NULL;
    glVertexAttrib4fv           = NULL;
    glVertexAttrib4iv           = NULL;
    glVertexAttrib4s            = NULL;
    glVertexAttrib4sv           = NULL;
    glVertexAttrib4ubv          = NULL;
    glVertexAttrib4uiv          = NULL;
    glVertexAttrib4usv          = NULL;
    glVertexAttribPointer       = NULL;

    /* WGL_ARB_extensions_string. */
    wglGetExtensionsStringARB   = NULL;
}