#include<stdlib.h>
#include<iostream>
#include<GL/glut.h>
#include<math.h>

using namespace std;

void draw(void){
	float radius, jumlah_titik, x_tengah, y_tengah;
	const double PI = 3.141592653589793;
	float x, y, sudut;
	float start, end;

	//menulis program menggambar
	glClear(GL_COLOR_BUFFER_BIT);
	glPointSize(5);
	
	glBegin(GL_LINE_STRIP);
		radius = 50;
		jumlah_titik = 360;
		x_tengah = 0;
		y_tengah = 0;
		start = 0;
		end = 360;
		sudut = 2*PI / jumlah_titik;
		for (int i=start; i<=end; i++){
			//rumus konversi koordinat sudut ke kartesian
			x = x_tengah + radius*cos(i*sudut);
			y = y_tengah + radius*sin(i*sudut);
			glVertex2f(x,y);
		}
	glEnd();

	glFlush();
}

void main(int argc, char **argv){
	glutInit(&argc, argv);

	glutInitDisplayMode(GLUT_DEPTH | GLUT_SINGLE | GLUT_RGBA);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(320, 320);
	
	glutCreateWindow("Grafika");
	gluOrtho2D(-100,100,-100,100);

	glutDisplayFunc(draw);
	glutMainLoop();
}