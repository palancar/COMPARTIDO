#include "Disparo.h"
#include "glut.h"

void Disparo::Dibuja() {
	glPushMatrix();
	glColor3ub(r, g, b);
	glTranslatef(pos.x, pos.y, 1);
	glutSolidSphere(radio, 20, 20);
	glPopMatrix();

}

