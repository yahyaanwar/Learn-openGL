#include <GL/glut.h>

int windowWidth = 600,
    windowHeight = 600;

void Quads(int side = 50)
{
    glBegin(GL_QUADS);
    glColor3f(1, 0, 0);
    glVertex2i(-side, -side);
    glVertex2i(-side, side);
    glVertex2i(side, side);
    glVertex2i(side, -side);
    glEnd();
}

float posX = 0, posY = 0, scale = 1;
void shapeMove(int step)
{
    glPushMatrix();
    glTranslatef(posX, posY, 0);
    glScalef(scale, scale, 0);
    Quads(10);
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
    glutTimerFunc(10, Timer, 0);
}

void mouse(int button, int state, int x, int y)
{
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
        scale -= 0.1;
    if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
        scale += 0.1;
}

void motion(int x, int y)
{
    posX = (x - (windowWidth/2))*2;
    posY = (y - (windowHeight/2))*2;
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
    glutMotionFunc(motion);
    glutMainLoop();
    return 0;
}