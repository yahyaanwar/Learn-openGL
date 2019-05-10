#include <GL/glut.h>

int windowWidth = 600,
    windowHeight = 600;

void Triangles()
{
    glBegin(GL_TRIANGLES);
    glVertex2i(0, 0);
    glVertex2i(100, 0);
    glVertex2i(50, 100);
    glEnd();
}

float initR = 0;
void shapeMove(int step)
{
    glPushMatrix();
    glRotatef(initR, 1, 0, 0);
    glPushMatrix();
    glTranslatef(-50, -50, 0);
    Triangles();
    initR += step;
    glPopMatrix();
    glPopMatrix();
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    shapeMove(5);
    glFlush();
}
void Timer(int value)
{
    glutPostRedisplay();
    glutTimerFunc(50, Timer, 0);
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);

    int xPosition = glutGet(GLUT_SCREEN_WIDTH) / 2 - windowWidth / 2,
        yPosition = glutGet(GLUT_SCREEN_HEIGHT) / 2 - windowHeight / 2;

    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowSize(windowWidth, windowHeight);
    glutInitWindowPosition(xPosition, yPosition);
    glutCreateWindow("2D Animation");
    gluOrtho2D(-windowWidth, windowWidth, windowHeight, -windowHeight);
    glutDisplayFunc(display);
    glutTimerFunc(100, Timer, 0);
    glutMainLoop();
    return 0;
}