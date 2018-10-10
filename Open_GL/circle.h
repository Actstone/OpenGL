
#include <GLUT/GLUT.h>
#include "iostream"
#include <cmath>
using namespace std;

const GLfloat R = 0.5f;
const GLfloat pi = 3.1415926536f;


class circle_1{
public:
    int n;
}cir;

void display()
{
    int i = 0;
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_POLYGON);
    for (i = 0; i < cir.n; i++)
    {
        glVertex2f(R*cos(2*pi/cir.n*i), R*sin(2*pi/cir.n*i));
    }
    glEnd();
    glFlush();
    
}


int circle_1(int argc, char **argv)
{
    cout<<"input n(n represents the apex. The bigger n, the finer):";cin>>cir.n;
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(400, 400);
    glutCreateWindow("circle");
    glutDisplayFunc(display);
    glutMainLoop();
    
    return 0;
}


