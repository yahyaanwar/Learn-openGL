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
    if (key == GLUT_KEY_LEFT)
        glTranslatef(-16, 0, 0);
    if (key == GLUT_KEY_RIGHT)
        glTranslatef(16, 0, 0);
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
    // changes::end
    glutTimerFunc(100, Timer, 0);
    glutMainLoop();
    return 0;
}