#include <GL/glut.h>

int windowWidth = 600,
    windowHeight = 600;

void Quads()
{
    glBegin(GL_QUADS);
    glVertex2i(-50, -50);
    glVertex2i(-50, 50);
    glVertex2i(50, 50);
    glVertex2i(50, -50);
    glEnd();
}

void shapeMove(int step)
{
    Quads();
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
    glutTimerFunc(10, Timer, 0);
}

// changes::start
void mySpecialKeyboard(int key, int x, int y)
{
    if (key == GLUT_KEY_UP)
        glTranslatef(0, -50, 0);
    if (key == GLUT_KEY_LEFT)
        glTranslatef(-50, 0, 0);
    if (key == GLUT_KEY_DOWN)
        glTranslatef(0, 50, 0);
    if (key == GLUT_KEY_RIGHT)
        glTranslatef(50, 0, 0);
}

void myKeyboard(unsigned char key, int x, int y)
{
    if (key == 'w' || key == 'W')
        glColor3ub(255, 0, 0);
    if (key == 'a' || key == 'A')
        glColor3ub(0, 255, 0);
    if (key == 's' || key == 'S')
        glColor3ub(0, 0, 255);
    if (key == 'd' || key == 'D')
        glColor3ub(255, 255, 0);
    if (key == 27)
        exit(0);
}
// changes::end

int main(int argc, char **argv)
{
    glutInit(&argc, argv);

    int xPosition = glutGet(GLUT_SCREEN_WIDTH) / 2 - windowWidth / 2,
        yPosition = glutGet(GLUT_SCREEN_HEIGHT) / 2 - windowHeight / 2;

    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowSize(windowWidth, windowHeight);
    glutInitWindowPosition(xPosition, yPosition);
    glutCreateWindow("2D Keyboard");
    gluOrtho2D(-windowWidth, windowWidth, windowHeight, -windowHeight);
    glutDisplayFunc(display);
    // changes::start
    glutSpecialFunc(mySpecialKeyboard);
    glutKeyboardFunc(myKeyboard);
    // changes::end
    glutTimerFunc(100, Timer, 0);
    glutMainLoop();
    return 0;
}