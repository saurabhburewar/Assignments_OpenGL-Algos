#include <iostream>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

using namespace std;

void init (void) {
    glClearColor( 0, 0, 0, 0 );
    glMatrixMode( GL_PROJECTION );
    gluOrtho2D(0, 500, 0, 500);
}

void display (void) {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f( 1, 1, 1 );
    glPointSize(5.0f); 


    int x0 = 35, y0 = 35, x1 = 300, y1 = 300;

    if (x0 < 30 || x0 > 400 || x1 < 30 || x1 > 400 || y0 < 30 || y0 > 400 || y1 < 30 || y1 > 400) {
        printf("Please enter coodinates in the range (30, 400)");
        return;
    }

    int dx = x1 - x0;
    int dy = y1 - y0;
    int d = 2*dy - dx;
    int dE = 2*dy;
    int dNE = 2*(dy - dx);
    int x = x0;
    int y = y0;
    
    glBegin(GL_POINTS);
    glColor3f (1.0, 0.0, 0.0);
		glVertex2i (0, 0);
		glColor3f (1.0, 1.0, 1.0);
    glVertex2i( x, y );
    while (x < x1) {
        if (d <= 0) {
            d = d + dE;
            x++;
        } else {
            d = d + dNE;
            x++;
            y++;
        }
        glVertex2i( x, y );
    }
    glEnd();

    glFlush();
}

int main (int argc, char** argv) {
    glutInit( &argc, argv );
    glutInitDisplayMode( GLUT_SINGLE );
    glutInitWindowSize( 600, 600 );
    glutInitWindowPosition( 10, 30 );
    glutCreateWindow("Midpoint Line Drawing algorithm");
    init();
    glutDisplayFunc(display);
    
    glutMainLoop();
}