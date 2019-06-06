#include "Disparo_elite.h"
#include "glut.h"


Disparo_elite::Disparo_elite() {
	SetV_Nominal(GV::V_Disparo_elite);
}


void Disparo_elite::Dibuja() {
	glPushMatrix();
	glColor3ub(r, g, b);
	glTranslatef(pos.x, pos.y, 1);
	glutSolidTorus(0.2, radio, 50, 50);
	glColor3ub(235, 241, 16);
	glutWireTorus(0.5, radio, 10, 10);
	glPopMatrix();
}

void Disparo_elite::Mueve(float t) {
	Objeto::Mueve(t);
	radio += 0.03;
}