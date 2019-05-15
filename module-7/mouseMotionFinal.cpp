#include <GL/glut.h>

int windowWidth = 600,
    windowHeight = 600;

void Quads(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4)
{
    glBegin(GL_QUADS);
    glColor3f(1, 0, 0);
    glVertex2i(x1, y1);
    glVertex2i(x2, y2);
    glVertex2i(x3, y3);
    glVertex2i(x4, y4);
    glEnd();
}

int x1 = -50, y1 = -50, x2 = 50, y2 = -50, x3 = 50, y3 = 50, x4 = -50, y4 = 50;
int rotate = 0;
void shapeMove()
{
    glPushMatrix();
    glRotatef(rotate, 0, 0, 1);
    Quads(x1, y1, x2, y2, x3, y3, x4, y4);
    glPopMatrix();
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    shapeMove();
    glFlush();
}
void Timer(int value)
{
    glutPostRedisplay();
    glutTimerFunc(10, Timer, 0);
}

int *moveX = NULL;
int *moveY = NULL;
bool dragged = false;
int area = 20;
void mouse(int button, int state, int x, int y)
{
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
        x = (x - (windowWidth / 2)) * 2;
        y = (y - (windowHeight / 2)) * 2;
        if (x > x1 - area && x < x1 + area && y > y1 - area && y < y1 + area)
        {
            moveX = &x1;
            moveY = &y1;
        }
        else if (x > x2 - area && x < x2 + area && y > y2 - area && y < y2 + area)
        {
            moveX = &x2;
            moveY = &y2;
        }
        else if (x > x3 - area && x < x3 + area && y > y3 - area && y < y3 + area)
        {
            moveX = &x3;
            moveY = &y3;
        }
        else if (x > x4 - area && x < x4 + area && y > y4 - area && y < y4 + area)
        {
            moveX = &x4;
            moveY = &y4;
        }
        else
        {
            moveX = NULL;
            moveY = NULL;
        }
        dragged = true;
    }
    if (button == GLUT_LEFT_BUTTON && state == GLUT_UP)
        dragged = false;
    if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
        rotate += 20;
}

void motion(int x, int y)
{
    if (dragged && moveX != NULL && moveY != NULL)
    {
        *moveX = (x - (windowWidth / 2)) * 2;
        *moveY = (y - (windowHeight / 2)) * 2;
    }
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