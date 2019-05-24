#include <stdlib.h>
#include <GL/glut.h>
float w = 480, h = 480;
float sx = 0, sy = -20, sz = 0;
float posX = 10.0f, posY = 10.0f, scale = 1;

void cube()
{
    glutSolidCube(10);
}

void display()
{
    glutPostRedisplay();
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    glTranslatef(0, 0, -30);
    glRotatef(sx, 1, 0, 0);
    glRotatef(sy, 0, 1, 0);
    glRotatef(sz, 0, 0, 1);

    // genteng
    glPushMatrix();
    glTranslatef(3, 0, 0);
    glRotatef(40, 0, 0, 1);
    glScalef(0.1, 1, 1.2);
    glColor3d(1, 0, 0);
    cube();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-3, 0, 0);
    glRotatef(-40, 0, 0, 1);
    glScalef(0.1, 1, 1.2);
    glColor3d(1, 0, 0);
    cube();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, -3, 0);
    glScalef(0.8, 0.8, 0.99);
    glRotatef(45, 0, 0, 1);
    glColor3d(0.5, 0, 0);
    cube();
    glPopMatrix();

    // pintu
    glPushMatrix();
    glTranslatef(0, -9.9, 0.1);
    glScalef(0.4, 0.6, 1);
    glColor3d(1, 0, 1);
    cube();
    glPopMatrix();

    // jendela
    glPushMatrix();
    glTranslatef(0, -8, 1);
    glScalef(1.02, 0.15, 0.15);
    glColor3d(0, 1, 1);
    cube();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, -8, -1);
    glScalef(1.02, 0.15, 0.15);
    glColor3d(0, 1, 1);
    cube();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, -10, 1);
    glScalef(1.02, 0.15, 0.15);
    glColor3d(0, 1, 1);
    cube();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, -10, -1);
    glScalef(1.02, 0.15, 0.15);
    glColor3d(0, 1, 1);
    cube();
    glPopMatrix();

    // cerobong
    glPushMatrix();
    glTranslatef(3, -2, -1);
    glScalef(0.15, 1.02, 0.15);
    glColor3d(1, 0, 1);
    cube();
    glPopMatrix();

    // dinding
    glPushMatrix();
    glTranslatef(0, -8, 0);
    glColor3d(1, 1, 0);
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
    GLfloat LightPosition[] = {posX, posY, 0.0f, 0.0f};
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

void motion(int x, int y)
{
    posX = (x - (w/2))*2;
    posY = (y - (h/2))*-2;
    init();
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
    glutMotionFunc(motion);
    glutKeyboardFunc(myKeyboard);
    glutMainLoop();
}