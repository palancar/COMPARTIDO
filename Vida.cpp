#include "Vida.h"
#include "ETSIDI.h"
#include "glut.h"



Vida::Vida() :Objeto(2, 0) {
	SetColor(ETSIDI::lanzaDado(0, 255), ETSIDI::lanzaDado(0, 255), ETSIDI::lanzaDado(0, 255));
	for (int i = 0; i < 3; i++)
		pulso[i] = false;
}

void Vida::Dibuja() {
	//3 "toroides"
	glPushMatrix();
	
	glTranslatef(pos.x, pos.y, radio);
	glRotatef(60, 1, 1, 1);
	glColor3ub(r, g, b);
	glutSolidTorus(.25, radio, 20, 20);

	glPushMatrix();
	glRotatef(90, 1, 0, 0);
	glutSolidTorus(.25, radio, 20, 20);
	glPopMatrix();

	glPushMatrix();
	glRotatef(90, 0, 1, 0);
	glutSolidTorus(.25, radio, 20, 20);
	glPopMatrix();

	glPopMatrix();
}

void Vida::Mueve(float t) {
	//la vida no se mueve, pero cambia de color

	//RED
	if (pulso[0])
		r += 1;
	else
		r -= 1;
	if (r >= 255) {
		r = 255;
		pulso[0] = !pulso[0];
	}
	else if (r <= 0) {
		r = 0;
		pulso[0] = !pulso[0];
	}

	//GREEN
	if (pulso[1])
		r += 2;
	else
		r -= 2;
	if (g >= 255) {
		g = 255;
		pulso[1] = !pulso[1];
	}
	else if (g <= 0) {
		g = 0;
		pulso[1] = !pulso[1];
	}

	//BLUE
	if (pulso[2])
		r += 3;
	else
		r -= 3;
	if (b >= 255) {
		b = 255;
		pulso[2] = !pulso[2];
	}
	else if (b <= 0) {
		b = 0;
		pulso[2] = !pulso[2];
	}

}