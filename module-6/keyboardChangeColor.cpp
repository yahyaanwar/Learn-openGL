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
int red = 255, green = 255, blue = 255;
int redDir = -1, greenDir = -1, blueDir = -1;
void mySpecialKeyboard(int key, int x, int y)
{
    if (key == GLUT_KEY_LEFT)
    {
        red += 5 * redDir;
        glColor3ub(red, green, blue);
        if (redDir == -1 && red <= 0)
            redDir = 1;
        if (redDir == 1 && red >= 255)
            redDir = -1;
    }
    if (key == GLUT_KEY_DOWN)
    {
        green += 5 * greenDir;
        glColor3ub(red, green, blue);
        if (greenDir == -1 && green <= 0)
            greenDir = 1;
        if (greenDir == 1 && green >= 255)
            greenDir = -1;
    }
    if (key == GLUT_KEY_RIGHT)
    {
        blue += 5 * blueDir;
        glColor3ub(red, green, blue);
        if (blueDir == -1 && blue <= 0)
            blueDir = 1;
        if (blueDir == 1 && blue >= 255)
            blueDir = -1;
    }
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