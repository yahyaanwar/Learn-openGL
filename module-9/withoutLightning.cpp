#include <stdlib.h>
#include <GL/glut.h>
float w = 480, h = 480;
float sx = 0, sy = 0, sz = 0;

void sphere(GLdouble radius, GLdouble slices, GLdouble stacks)
{
    glutSolidSphere(radius, slices, stacks);
}

void display()
{
    glutPostRedisplay();
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    glTranslatef(0, 0, -10);
    glRotatef(sx, 1, 0, 0);
    glRotatef(sy, 0, 1, 0);
    glRotatef(sz, 0, 0, 1);

    glPushMatrix();
    sphere(4, 20, 20);
    glPopMatrix();

    glutSwapBuffers();
}
void resize(int w1, int h1)
{
    glViewport(0, 0, w1, h1);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(80.0, (float)w1 / (float)h1, 1.0, 300.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void init()
{
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glEnable(GL_DEPTH_TEST);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45., (GLdouble)w / (GLdouble)h, 1., 300.);
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH | GLUT_RGBA);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(w, h);
    glutCreateWindow("Objek 3D");
    glutDisplayFunc(display);
    glutReshapeFunc(resize);
    init();
    glutMainLoop();
}