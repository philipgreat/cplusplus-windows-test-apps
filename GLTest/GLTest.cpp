// GLTest.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include "stdafx.h"


#include <windows.h> 
#include <gl/gl.h>
#include <gl/glaux.h> 
#include <gl/glu.h> 
#include <math.h> 
#pragma comment(lib,"opengl32.lib")
#pragma comment(lib,"glaux.lib")
#pragma comment(lib,"glu32.lib")

void myinit() 
{ 
	glClearColor(1,1,0,0); 
	GLfloat ambient[]={.5,.5,.5,0}; 
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, 
	ambient); 
	GLfloat mat_ambient[]={.8,.8,.8,1.0}; 
	GLfloat mat_diffuse[]={.8,.0,.8,1.0}; 
	GLfloat mat_specular[]={1.0,.0,1.0,1.0}; 
	GLfloat mat_shininess[]={50.0}; 
	GLfloat light_diffuse[]={0,0,.5,1}; 
	GLfloat light_position[]={0,0,1.0,0}; 
	glMaterialfv(GL_FRONT_AND_BACK,GL_AMBIENT,mat_ambient); 
	glMaterialfv(GL_FRONT_AND_BACK,GL_DIFFUSE,mat_diffuse); 
	glMaterialfv(GL_FRONT_AND_BACK,GL_SPECULAR,mat_specular); 
	glMaterialfv(GL_FRONT_AND_BACK,GL_SHININESS,mat_shininess); 
	glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse); 
	glLightfv(GL_LIGHT0,GL_POSITION, light_position); 
	glEnable(GL_LIGHTING); 
	glEnable(GL_LIGHT0); 
	glDepthFunc(GL_LESS); 
	glEnable(GL_DEPTH_TEST); 
} 
void CALLBACK display() 
{ 
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT); 
	auxSolidSphere(1.0);//绘制半径为1.0的实体球 
	glFlush(); //强制输出图像 
	auxSwapBuffers(); //交换绘图缓存 
	//Sleep(10);

} 
void CALLBACK Idledisplay() 
{ 
	//x,y满足x2+y2=0.01。这样可以使物体沿该圆轨 //迹运动。 
	static float x=-.1,y=0.0; 
	static BOOL mark=TRUE; 
	static float step=.01; 
	x+=step; 
	if(x<=.1&&x>=-.1) 
	{	 
		if(step>0) 
			y=sqrt(.01-x*x); 
		else 
			y=-sqrt(.01-x*x); 
		glTranslatef(x,y,0); 
	} 
	else 
	{ 
		step=0-step; 
	} 
	display(); 
} 
void CALLBACK myReshape(GLsizei w,GLsizei h) 
{ 
	glViewport(0,0,w,h); 
	glMatrixMode(GL_PROJECTION); 
	glLoadIdentity(); 
	if(w<=h) 
	glOrtho(-3.5,3.5,-3.5*(GLfloat)w/(GLfloat)h, 3.5*(GLfloat)w/(GLfloat)h,-10,10); 
	else 
	glOrtho(-3.5*(GLfloat)w/(GLfloat)h,3.5* (GLfloat)w/(GLfloat)h,-3.5,3.5,-10,10); 
	glMatrixMode(GL_MODELVIEW); 
	glLoadIdentity(); 
} 
int  main() 
{ 
	auxInitDisplayMode(AUX_DOUBLE|AUX_RGBA); 
	auxInitPosition(0,0,640,480); 
	auxInitWindow(" circle "); 
	myinit(); 
	auxReshapeFunc(myReshape); 
	auxIdleFunc(Idledisplay); 
	auxMainLoop(display);
	return 0;


}