#include <stdlib.h>
#include <GL/glut.h>
float w = 480, h = 480;
float sx = 0, sy = 0, sz = 0;
int object_id = 0;
void cube()
{
    glColor3d(0, 0, 1);
    glutWireCube(10);
}
void sphere(GLdouble radius, GLdouble slices, GLdouble stacks)
{
    glutWireSphere(radius, slices, stacks);
}
void cone(GLdouble base, GLdouble height, GLint slices, GLint stacks)
{
    glColor3d(0, 0, 1);
    glutWireCone(base, height, slices, stacks);
}
void torus(GLdouble innerRadius, GLdouble outerRadius,
           GLint nsides, GLint rings)
{
    glColor3d(0, 0, 1);
    glutWireTorus(innerRadius, outerRadius, nsides, rings);
}
void dodecahedron()
{
    glColor3d(0, 0, 1);
    glScalef(3, 3, 2);
    glutWireDodecahedron();
}
void tetrahedron()
{
    glColor3d(0, 0, 1);
    glScalef(3, 3, 2);
    glutWireTetrahedron();
}
void octahedron()
{
    glColor3d(0, 0, 1);
    glScalef(3, 3, 2);
    glutWireOctahedron();
}
void teapot(GLdouble size)
{
    glutWireTeapot(size);
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    glTranslatef(0, 10, -40);
    glRotatef(sx, 1, 0, 0);
    glRotatef(sy, 0, 1, 0);
    glRotatef(sz, 0, 0, 1);
    glPushMatrix();
    glPopMatrix();

    // kepala
    glPushMatrix();
    glRotatef(95, 1, 0, 0);
    sphere(4, 20, 20);
    glPopMatrix();
    // leher
    glPushMatrix();
    glTranslatef(0, -4, 0);
    glRotatef(95, 1, 0, 0);
    torus(1, 1, 20, 20);
    glPopMatrix();

    // baju
    glPushMatrix();
    glTranslatef(0, -6, 0);
    glRotatef(95, 1, 0, 0);
    cone(10, 13, 20, 20);
    glPopMatrix();

    //celana
    glPushMatrix();
    glTranslatef(0, -20, 0);
    glRotatef(-10, 1, 0, 0);
    glScalef(1, 0.5, 1);
    cube();
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
    else if (key == ' ')
    {
        object_id += 1;
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