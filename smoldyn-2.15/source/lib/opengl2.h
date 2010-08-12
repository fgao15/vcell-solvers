/* Steven Andrews, 2/03.
Header for opengl2.c.
See documentation called opengl2_doc.doc.
Copyright 2003-2007 by Steven Andrews.  This work is distributed under the terms
of the Gnu Lesser General Public License (LGPL). */

#ifndef __opengl2_h
#define __opengl2_h

/* If the OpenGL graphics libraries are unavailable, comment out the following
lines (most functions here will become non-active).  Also, note that different
names may be required for OpenGL header files, such as <GL/gl.h> */

#include "smoldyn_config.h"

#if defined(OPENGL)

	#if defined(HAVE_GL_GL_H)
		#include <GL/gl.h>
	#elif defined(HAVE_OPENGL_GL_H)
		#include <OpenGl/gl.h>
	#endif

	#if defined(HAVE_GL_GLUT_H)
		#include <GL/glut.h>
	#elif defined(HAVE_GLUT_GLUT_H)
		#include <GLUT/glut.h>
	#endif

	#if defined(HAVE_LIBTIFF)
		#include <tiffio.h>
	#endif

#else
	#define GLfloat float

#endif

void gl2Initialize(float xlo,float xhi,float ylo,float yhi,float zlo,float zhi);
void gl2glutInit(int *argc,char **argv);
int gl2State(int state);
float gl2GetNumber(char *variable);
char *gl2GetString(char *option,char *string);
int gl2SetOptionInt(char *option,int value);
float gl2SetOptionFlt(char *option,float value);
char *gl2SetOptionStr(char *option,char *value);
char *gl2SetOptionVoid(char *option,void *value);
void gl2SetKeyPush(unsigned char key);
void gl2SetColor(char c);

float gl2FindRotate(float *vect1,float *vect2,float *axis);
double gl2FindRotateD(double *vect1,double *vect2,double *axis);
void gl2DrawBox(float *pt1,float *pt2,int dim);
void gl2DrawBoxD(double *pt1,double *pt2,int dim);
void gl2DrawGrid(float *pt1,float *pt2,int *n,int dim);
void gl2DrawGridD(double *pt1,double *pt2,int *n,int dim);
void gl2DrawCircle(float *cent,float radius,int slices,char style,int dim);
void gl2DrawCircleD(double *cent,double radius,int slices,char style,int dim);
void gl2DrawArc(float *cent,float radius,float theta1,float theta2,int slices,char style,int dim);
void gl2DrawArcD(double *cent,double radius,double theta1,double theta2,int slices,char style,int dim);
void gl2DrawHemisphere(float radius,int slices,int stacks,int frontin,int normals);
void gl2DrawCylinder(float baseRadius,float topRadius,float height,int slices,int stacks,int frontin,int normals);
void gl2DrawSphere(float radius,int slices,int stacks,int frontin,int normals);
void gl2DrawEcoli(float radius,float length,int slices,int stacks,int frontin,int normals);
void gl2PlotData(float *xdata,float *ydata,int nx,int nycol,char *style);
void gl2PlotPts(float **data,int *ser,int nser,int npts,float **color,float *size,char style);
void gl2PlotPtsD(double **data,int *ser,int nser,int npts,double **color,double *size,char style);
void gl2PlotSurf(float *xdata,float *ydata,float **zdata,int nx,int ny,int nz,char *style);

#endif
