#include <GL/glut.h> 
#include <cmath>
#include<iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
using namespace std;

void init (void)
{
	glClearColor (0.0, 0.0, 0.0, 0.0); 
	glMatrixMode (GL_PROJECTION); 
	gluOrtho2D (0, 400, 0, 400);

	glEnable(GL_LINE_SMOOTH);
	glHint(GL_LINE_SMOOTH_HINT, GL_NICEST);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
}

void dispPoint (void)
{
	glClear (GL_COLOR_BUFFER_BIT); 
	glColor3f (1.0, 1.0, 1.0); 
	glPointSize(5.0f); 

	GLint iMultiSample= 0;
	GLint iNumSamples= 0;

	glGetIntegerv(GL_SAMPLE_BUFFERS, &iMultiSample);
	glGetIntegerv(GL_SAMPLES, &iNumSamples);

	glEnable(GL_MULTISAMPLE);
	glHint(GL_MULTISAMPLE_FILTER_HINT_NV, GL_NICEST);


	glEnable(GL_LINE_SMOOTH);
	glHint(GL_LINE_SMOOTH_HINT, GL_NICEST);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	glPushMatrix();

	int x0,x1,x2,y0,y1,y2;
	x0=200;
	y0=100;
	x1=100;
	y1=300;
	x2=300;
	y2=300;
	
	if (x0 < 10 || x0 > 400 || x1 < 10 || x1 > 400 || y0 < 10 || y0 > 400 || y1 < 10 || y1 > 400) 
	{
        printf("Please enter coodinates in the range (30, 400)");
        return;
	}
	
	int dx0,dx1,dx2,dy0,dy1,dy2;
	dx0=x1-x0;
	dy0=y1-y0;
	dx1=x2-x1;
	dy1=y2-y1;
	dx2=x0-x2;
	dy2=y0-y2;

	int xmin=x0<x1?(x0<x2?x0:x2):(x1<x2?x1:x2);
	int xmax=x0>x1?(x0>x2?x0:x2):(x1>x2?x1:x2);
	int ymin=y0<y1?(y0<y2?y0:y2):(y1<y2?y1:y2);
	int ymax=y0>y1?(y0>y2?y0:y2):(y1>y2?y1:y2);
	int q=xmax-xmin+1;

	int f0=(xmin-x0)*dy0 - (ymax-y0)*dx0;
	int f1=(xmin-x1)*dy1 - (ymax-y1)*dx1;
	int f2=(xmin-x2)*dy2 - (ymax-y2)*dx2;

	glBegin(GL_POINTS);
		glColor3f (1.0, 0.0, 0.0);
		glVertex2i (0, 0);
		glColor3f (1.0, 1.0, 1.0);
		for(int y=ymax;y>=ymin;y--)
		{
			for(int x=xmin;x<=xmax;x++)
			{
                if((f0>0)&&(f1>0)&&(f2>0))
                    glVertex2i (x, y);
				f0 = f0 + dy0;
				f1 = f1 + dy1;
				f2 = f2 + dy2;
			}
			f0 = f0 - (q*dy0)+dx0;
			f1 = f1 - (q*dy1)+dx1;
			f2 = f2 - (q*dy2)+dx2;
		}
	glEnd();

	glColor3f (0.0, 1.0, 0.0);

	glBegin(GL_POINTS);
		glVertex2i (200, 100);
		glVertex2i (100, 300);
		glVertex2i (300, 300);
	glEnd();

	glPopMatrix();
    glFlush(); 
	glutSwapBuffers();
	glutPostRedisplay();
}


int main (int argc, char** argv)
{
	glutInit (&argc, argv); 
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH | GLUT_MULTISAMPLE);

	glEnable (GL_LINE_SMOOTH);
	glHint (GL_LINE_SMOOTH_HINT, GL_NICEST);
	glEnable(GL_MULTISAMPLE);
	glHint(GL_MULTISAMPLE_FILTER_HINT_NV, GL_NICEST);

	glutInitWindowPosition (10, 10); 
	glutInitWindowSize (600,600); 
	glutCreateWindow("Triangle Supersampling"); 
	init ( );
	glutDisplayFunc (dispPoint); 
	glutMainLoop ( ); 
	return 0;
}
