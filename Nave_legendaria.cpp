#include "Nave_legendaria.h"
#include "Disparo_elite.h"
#include "Disparo_acelerado.h"
#include <math.h>
#include "glut.h"

Nave_legendaria::Nave_legendaria() : dispt (RAFAGA), cuenta_disparos(0), pulso(false) {
	SetV_Nominal(GV::V_Nave_elite); //se mueve a la misma velocidad que una nave de élite
	SetHP(GV::HP_Nave_legendaria = 100);
	SetRadio(6);
	Cycle_time = GV::T_Disparo_Nave_Legendaria;
	//192, 192, 192 plata
	//239, 184, 16 dorado
	//207, 18, 32 lava
	SetColor(207, 18, 32);
	puntos = 2000;
}

void Nave_legendaria::Dibuja() {

	glPushMatrix();
	glTranslatef(pos.x, pos.y, 1);

	glPushMatrix(); //toroide de arriba
	glTranslatef(0, 0, 2);
	glColor3ub(192, 192, 192);
	glutSolidTorus(1, radio - 1, 30, 30);
	glPopMatrix();

	glPushMatrix();
	glRotatef(point * 180 / PI, 0, 0, -1); //rotación (adonde apunta)
	glColor3ub(207, 18, 32); //toroides base
	glutSolidTorus(2, radio - 1, 30, 30);
	glColor3ub(239, 184, 16);
	glutWireTorus(2, radio - 0.5, 40, 40);
	glPopMatrix();

	glPushMatrix();
	glRotatef(point * 180 / PI, 0, 0, 1); //rotación (adonde apunta)
	//esferas
	glColor3ub(r, g, b);
	glutSolidSphere(radio - 0.25, 20, 20);
	glPopMatrix();

	glColor3ub(192, 192, 192);

	glRotatef(90, 0, 1, 0); //primera rotación (para que se vea apropiadamente)
	glRotatef(point * 180 / PI, -1, 0, 0); //segunda rotación (adonde apunta) //OJO º / rad

	

	for (int i = 0; i < 8; i++) { //pinchos
		glPushMatrix();
		glRotatef(45 * i, -1, 0, 0); //tercera rotación (pinchos)
		glutSolidCone(2, 10, 10, 10);
		glPopMatrix();
	}
	for (int i = -1; i < 2; i++) { //minitoroides
		glPushMatrix();
		glRotatef(45 * i, -1, 0, 0);
		glTranslatef(0, 0, 7);
		glutSolidTorus(0.3, 2, 10, 10);
		//minipinchos
	
		for (int j = 0; j < 8; j++){
			glPushMatrix();
			glTranslatef(1.5*cos(PI * j / 4), 1.5*sin(PI * j / 4), 0);
			if (i == 0) 
				glutSolidCone(0.3, 3, 10, 10); //pinchos de los toroides
			else
				glutSolidCone(0.3, 2, 10, 10);
			glPopMatrix();
		}
		glPopMatrix();
	}
	glPopMatrix();
}

void Nave_legendaria::Dispara(lista<Disparo> &dis, unsigned char r, unsigned char g, unsigned char b) {
	
	if (dispt == RAFAGA) {
		if (cuenta_disparos < 8) {
			for (int i = -1; i < 2; i++) {
				dis.push_back(new Disparo());
				dis.back()->SetColor(r, g, b);

				//Lo mismo de siempre
				dis.back()->SetPos(pos + Vector2D().fromArgMod(point + PI * i / 3.5, radio));
				dis.back()->SetVel(Vector2D().fromArgMod(point + PI * i / 3.5, dis.back()->GetV_Nominal()));
			}
			if (cuenta_disparos == 7) {
				Cycle_time = GV::T_Disparo_Nave_Legendaria;
				cuenta_disparos = 0;
				dispt = ELITE;
			}
			else {
				Cycle_time = 0.1;
				cuenta_disparos++;
			}
		}
	}
	else if (dispt == ELITE) {
		if (cuenta_disparos < 3) {
			for (int i = -1; i < 2; i++) {
				dis.push_back(new Disparo_elite());
				dis.back()->SetColor(r, g, b);

				//Lo mismo de siempre
				dis.back()->SetPos(pos + Vector2D().fromArgMod(point + PI * i / 4, radio));
				dis.back()->SetVel(Vector2D().fromArgMod(point + PI * i / 4, dis.back()->GetV_Nominal()));
			}
			if (cuenta_disparos == 2) {
				Cycle_time = GV::T_Disparo_Nave_Legendaria;
				cuenta_disparos = 0;
				dispt = ACELERADO;
			}
			else {
				Cycle_time = 0.3;
				cuenta_disparos++;
			}
		}
	}
	else if (dispt == ACELERADO) {
		if (cuenta_disparos < 3) {
			for (int i = -1; i < 2; i++) {
				dis.push_back(new Disparo_acelerado());
				dis.back()->SetColor(r, g, b);

				//Lo mismo de siempre
				dis.back()->SetPos(pos + Vector2D().fromArgMod(point + PI * i / 4, radio));
				dis.back()->SetVel(Vector2D().fromArgMod(point + PI * i / 8, dis.back()->GetV_Nominal()));
				dis.back()->SetAcc(Vector2D().fromArgMod(point, 10));
			}
			dispt = RAFAGA;
		}
	}
}

void Nave_legendaria::Mueve(float t) {
	Objeto::Mueve(t);
	//cambia de color rojo
	if (pulso)
		r += 1;
	else
		r -= 1;
	if (r >= 240) {
		r = 240;
		pulso = !pulso;
	}
	else if (r <= 40) {
		r = 40;
		pulso = !pulso;
	}
}