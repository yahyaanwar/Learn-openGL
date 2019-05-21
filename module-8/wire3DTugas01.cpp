#include <stdlib.h>
#include <GL/glut.h>
float w = 480, h = 480;
float sx = 0, sy = 0, sz = 0;

void torus(GLdouble innerRadius, GLdouble outerRadius,
           GLint nsides, GLint rings)
{
    glutWireTorus(innerRadius, outerRadius, nsides, rings);
}
void sphere (GLdouble radius, GLdouble slices, GLdouble stacks){
glutWireSphere(radius, slices, stacks);
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    glTranslatef(0, 0, -40);
    glRotatef(sx, 1, 0, 0);
    glRotatef(sy, 0, 1, 0);
    glRotatef(sz, 0, 0, 1);

    glPushMatrix();
    glColor3d(0, 1, 0);
    sphere(5, 20, 20);
    glPopMatrix();

    glPushMatrix();
    glColor3d(0, 0, 1);
    glRotatef(20, 1, 0, 0);
    glRotatef(-20, 0, 1, 0);
    glTranslatef(8, 8, 0);
    sphere(10, 20, 20);
    glPopMatrix();

    glPushMatrix();
    glColor3d(1, 0, 0);
    glRotatef(10, 1, 0, 0);
    glRotatef(5, 0, 1, 0);
    glTranslatef(-8, -8, 0);
    sphere(10, 20, 20);
    glPopMatrix();
    glutSwapBuffers();
}
void resize(int w1, int h1)
{
    glViewport(0, 0, w1, h1);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, (float)w1 / (float)h1, 1.0, 300.0);
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
void myKeyboard(unsigned char key, int x, int y)
{
    if (key == 'x')
    {
        sx += 10;
    }
    else if (key == 'y')
    {
        sy += 10;
    }
    else if (key == 'z')
    {
        sz += 10;
    }
}
void update(int value)
{
    glutPostRedisplay();
    glutTimerFunc(50, update, 0);
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
    glutTimerFunc(50, update, 0);
    glutKeyboardFunc(myKeyboard);
    glutMainLoop();
}