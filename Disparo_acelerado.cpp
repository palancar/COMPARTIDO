#include "Disparo_acelerado.h"
#include "glut.h"


Disparo_acelerado::Disparo_acelerado() {
	SetV_Nominal(GV::V_Disparos);
	SetRadio(4.5);
}


void Disparo_acelerado::Dibuja() {
	glPushMatrix();
	glColor3ub(207, 16, 32);
	glTranslatef(pos.x, pos.y, 1);
	glutSolidSphere(radio - 2, 10, 10);
	glColor3ub(r, g, b);
	glutWireSphere(radio, 20, 20);
	glPopMatrix();
}
