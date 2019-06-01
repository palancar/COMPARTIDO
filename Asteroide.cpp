#include "Asteroide.h"
#include "GlobalVar.h"
#include "glut.h"

Asteroide::Asteroide(float rad) : Objeto(rad){
	SetColor(191, 183, 104);
}

void Asteroide::Dibuja() {
	glPushMatrix();
	glColor3ub(r, g, b);
	glTranslatef(pos.x, pos.y, 0);
	glutSolidSphere(radio, 50, 50);
	glPopMatrix();
}