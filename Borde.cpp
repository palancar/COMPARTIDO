#include "Borde.h"
#include "glut.h"


void Borde::Dibuja() {
	//dibuja el borde, como 4 líneas

	glDisable(GL_LIGHTING);
	glBegin(GL_LINES);
	glColor3ub(255, 255, 255);
	glVertex3d(lim1.x, lim1.y, 0);
	glVertex3d(lim1.x, lim2.y, 0);
	glEnd();
	glBegin(GL_LINES);
	glColor3ub(255, 255, 255);
	glVertex3d(lim1.x, lim2.y, 0);
	glVertex3d(lim2.x, lim2.y, 0);
	glEnd();
	glBegin(GL_LINES);
	glColor3ub(255, 255, 255);
	glVertex3d(lim2.x, lim2.y, 0);
	glVertex3d(lim2.x, lim1.y, 0);
	glEnd();
	glBegin(GL_LINES);
	glColor3ub(255, 255, 255);
	glVertex3d(lim2.x, lim1.y, 0);
	glVertex3d(lim1.x, lim1.y, 0);
	glEnd();



	glEnable(GL_LIGHTING);
}