#include "Asteroide.h"
#include "GlobalVar.h"
#include "glut.h"

Asteroide::Asteroide() : Objeto(5.0, GV::V_Asteroides) {
	SetColor(157, 153, 105);
}

void Asteroide::Dibuja() {
	glPushMatrix();
	glColor3ub(r, g, b);
	glTranslatef(pos.x, pos.y, 0);
	glutSolidSphere(radio, 50, 50);
	glPopMatrix();
}