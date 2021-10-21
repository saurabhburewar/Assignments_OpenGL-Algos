// Implement the Midpoint Circle Drawing Algorithm (using only integer operations) to draw an arc
// of radius 100 pixels centered at (200, 200) and starting from 135◦to 215. 
// The use of 8-way symmetry is strictly prohibited. Traverse along the arc in the counter-clockwise 
// direction. Use the appropriate size of the window and viewport.

#include <GL/gl.h> 
#include <GL/glu.h> 
#include <GL/glut.h>
#include<iostream>

using namespace std;

void init (void)
{
	glClearColor (0.0, 0.0, 0.0, 0.0);
	glMatrixMode (GL_PROJECTION);
	gluOrtho2D (0, 600, 0, 600);
}

void displayCircle (void)
{
	glClear (GL_COLOR_BUFFER_BIT);
	glColor3f (1.0, 0.0, 0.0);
	glPointSize(5.0f);

    int rad=100;
    int x=-rad,y=0;
    double d=(5.0/4.0)-rad;
        
    x=-rad;
    y=0;
    d=(5.0/4.0)-rad;

    glBegin(GL_POINTS);
        glColor3f (1.0, 0.0, 0.0);
        glVertex2i(0, 0);
        glColor3f (1.0, 1.0, 1.0);
        glVertex2i(200, 200);

        while(y<(-x))
        {
            if(d<0)
            {
                d=d+2*y+3;
                y=y+1;
            }
            else
            {
                d=d+(2*x)+(2*y)+5;
                x=x+1;
                y=y+1;
            }
            glVertex2i(x+200,y+200);
        }
    
        x=-rad;
        y=0;
        d=(5.0/4.0)-rad;

        while(-(y)<(-x))
        {
            if(d<0)
            {
                d=d-2*y+3;
                y=y-1;
            }
            else
            {
                d=d+(2*x)-(2*y)+5;
                x=x+1;
                y=y-1;
            }
            glVertex2i(x+200,y+200);
        }

    glEnd( );
	glFlush( ); 
}

int main (int argc, char** argv)
{
	glutInit (&argc, argv);
	glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition (10, 10);
	glutInitWindowSize (600, 600);
	glutCreateWindow("Circle");
	init ( );
	glutDisplayFunc (displayCircle);
	
    glutMainLoop ( );
}
