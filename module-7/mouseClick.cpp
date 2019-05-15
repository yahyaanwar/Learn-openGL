#include <GL/glut.h>

int windowWidth = 600,
    windowHeight = 600;

void Quads()
{
    glBegin(GL_QUADS);
    glColor3f(1, 0, 0);
    glVertex2i(-50, -50);
    glVertex2i(-50, 50);
    glVertex2i(50, 50);
    glVertex2i(50, -50);
    glEnd();
}

float posX = 0;
void shapeMove(int step)
{
    glPushMatrix();
    glTranslatef(posX, 0, 0);
    Quads();
    glPopMatrix();
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    shapeMove(1);
    glFlush();
}
void Timer(int value)
{
    glutPostRedisplay();
    glutTimerFunc(100, Timer, 0);
}

void mouse(int button, int state, int x, int y)
{
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
        posX -= 50;
    if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
        posX += 50;
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
    glutMouseFunc(mouse);
    glutMainLoop();
    return 0;
}