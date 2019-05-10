#include <GL/glut.h>

int windowWidth = 600,
    windowHeight = 600;

void Triangles()
{
    glBegin(GL_POLYGON);
    glVertex2i(50, 50);
    glVertex2i(0, 0);
    glVertex2i(100, 0);
    glVertex2i(50, 50);
    glVertex2i(0, 100);
    glVertex2i(100, 100);
    glEnd();
}

float initR = 0;
void shapeMove(int step)
{
    glPushMatrix();
    glTranslatef(-50, -150, 0);
    glScalef(1, 3, 1);
    Triangles();
    glPopMatrix();

    initR -= step;
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
    glutTimerFunc(20, Timer, 0);
}

// changes::start
void myKeyboard(unsigned char key, int x, int y)
{
    if (key == 'k')
        glRotatef(-16, 0, 0, 1);
    if (key == 'l')
        glRotatef(16, 0, 0, 1);
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
    glutCreateWindow("2D Animation");
    gluOrtho2D(-windowWidth, windowWidth, windowHeight, -windowHeight);
    glutDisplayFunc(display);
    // changes::start
    glutKeyboardFunc(myKeyboard);
    // changes::end
    glutTimerFunc(100, Timer, 0);
    glutMainLoop();
    return 0;
}