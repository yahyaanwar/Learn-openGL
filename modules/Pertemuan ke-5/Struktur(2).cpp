#include <stdlib.h>
#include <gl/glut.h>

void drawQuads() {
	glBegin(GL_QUADS);
		glVertex2f(0.,0.);
		glVertex2f(0.,20.);
		glVertex2f(10.,20.);
		glVertex2f(10.,0.);
	glEnd();
}

void render(){
	glClear(GL_COLOR_BUFFER_BIT);
		glColor3f(1,0,0); // merah
		drawQuads();

		glPushMatrix();
			glColor3f(0,0,1); //biru
			glRotatef(60,0,0,1);
			drawQuads();

			glColor3f(0,1,0); //hijau
			glTranslatef(50,0,0);
			drawQuads();
		glPopMatrix();

		glColor3f(1,1,0); //kuning
		glTranslatef(50,0,0);
		drawQuads();

	glFlush();
}

	
void main (int argc,char **argv){
	glutInit(&argc,argv);
	
	glutInitDisplayMode(GLUT_DEPTH | GLUT_RGBA);
	glutInitWindowPosition(100,100);
	glutInitWindowSize(480,480);
	

	glutCreateWindow("Grafika");
	glClearColor(1,1,1,0);
	gluOrtho2D(-100.,100.,-100,100);
	glutDisplayFunc(render);
	glutMainLoop();
}
