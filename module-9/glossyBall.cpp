#include <stdlib.h>
#include <GL/glut.h>
float w = 480, h = 480;
float sx = 0, sy = 0, sz = 0;

void sphere(GLdouble radius, GLdouble slices, GLdouble stacks)
{
    glColor3d(1, 0, 0);
    glutSolidSphere(radius, slices, stacks);
}
void teapot(GLdouble size)
{
    glColor3d(1, 1, 0);
    glutSolidTeapot(size);
}

void dodecahedron()
{
    glColor3d(0, 1, 0);
    glutSolidDodecahedron();
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
    glTranslatef(1, 0, 0);
    sphere(2, 20, 20);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-5, 0, 0);
    teapot(2);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(6, 0, 0);
    dodecahedron();
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
    GLfloat LightPosition[] = {10.0f, 10.0f, 20.0f, 0.0f};
    GLfloat LightAmbient[] = {5.0f, 5.0f, 0.0f, 1.0f};
    GLfloat LightDiffuse[] = {0.7f, 0.7f, 0.7f, 1.0f};
    GLfloat LightSpecular[] = {0.5f, 0.5f, 0.5f, 1.0f};
    GLfloat Shine[] = {80};

    glEnable(GL_COLOR_MATERIAL);
    glShadeModel(GL_SMOOTH);
    glClearColor(0.0f, 0.0f, 0.0f, 0.5f);
    glClearDepth(1.0f);
    glEnable(GL_DEPTH_TEST);
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
    glMaterialfv(GL_FRONT, GL_AMBIENT, LightAmbient);
    glLightfv(GL_LIGHT0, GL_POSITION, LightPosition);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    return;
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