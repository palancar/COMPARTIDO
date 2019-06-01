#pragma once
#include "Nave.h"
#include <math.h>
#include "Disparo.h"
#include "GlobalVar.h"
#include "glut.h"

Nave::Nave() : point(0), Objeto(2.0) {
	SetPos(40, 30); //el centro
	SetColor(255, 215, 0);
}

void Nave::Dibuja() {
	//el toroide exterior
	glPushMatrix();
	glColor3ub(r, g, b);
	glTranslatef(pos.x, pos.y, 0);
	glutSolidTorus(1, radio, 100, 100);
	glPopMatrix();

	//el cono / disparador
	glPushMatrix();
	glColor3ub(230, 46, 0);
	glTranslatef(pos.x, pos.y, 1);	
	glutSolidSphere(radio, 100, 100);
	glRotatef(90, 0, 1, 0); //primera rotación (para que se vea apropiadamente)
	glRotatef(point * 180 /PI, -1, 0, 0); //segunda rotación (adonde apunta) //OJO º / rad
	glutSolidCone(1.5, 5, 100, 100);
	glPopMatrix();
}


void Nave::Dispara(lista_disparos &dis) {
	if (dis.size() >= GV::N_Disparos) {
		//return;
		dis.erase(0); //borra el primer disparo (el más antiguo)
	}
	dis.push_back(new Disparo()); //crea un disparo al final
	dis.back()->SetColor(0, 176, 246);//color muy bonito :)

	
	//pedir dibujo si no se entiende jeje
	//se puede usar a partir de aquí, indistintamente, la función fromArgMod(...) y rotar(...)
	//se usan las dos como ejemplo
	dis.back()->SetPos(pos + Vector2D().fromArgMod(point, radio));
	dis.back()->SetVel(0.5*vel + Vector2D(GV::V_Disparos, 0).rotar(point));
}
void Nave::Tecla(Teclado &t) {

	////No pulsar A y D a la vez
	//if (t.verify('A') || t.verify('a')) {
	//	if (vel.x >= -5.0f) {
	//		acc.x = -50;
	//	}
	//	else acc.x = -25;
	//}
	//else if (t.verify('D') || t.verify('d')) {
	//	if (vel.x <= 5.0f) {
	//		acc.x = 50;
	//	}
	//	else acc.x = 25;
	//}
	//else acc.x = 0;
	////No pulsar W y S a la vez
	//if (t.verify('W') || t.verify('w')) {
	//	vel.y = -10;
	//	if (vel.y <= 5.0f) {
	//		acc.y = 50;
	//	}
	//	else acc.y = 25;
	//}
	//else if (t.verify('S') || t.verify('s')) {
	//	if (vel.y >= -5.0f) {
	//		acc.y = -50;
	//	}
	//	else acc.y = -25;
	//}
	//else acc.y = 0;

	//No pulsar A y D a la vez
	//No pulsar W y S a la vez
	if (t.verify('A') || t.verify('a')) {
		if (t.verify('W') || t.verify('w')) {
			vel.fromArgMod(135 * PI / 180, GV::V_Nave);
		}
		else if (t.verify('S') || t.verify('s')) {
			vel.fromArgMod(-135 * PI / 180, GV::V_Nave);
		}
		else
			vel.fromArgMod(PI, GV::V_Nave);
	}
	else if (t.verify('D') || t.verify('d')) {
		if (t.verify('W') || t.verify('w')) {
			vel.fromArgMod(45 * PI / 180, GV::V_Nave);
		}
		else if (t.verify('S') || t.verify('s')) {
			vel.fromArgMod(-45 * PI / 180, GV::V_Nave);
		}
		else
			vel.fromArgMod(0, GV::V_Nave);
	}
	else if (t.verify('W') || t.verify('w')) {
		vel.fromArgMod(PI / 2, GV::V_Nave);
	}
	else if (t.verify('S') || t.verify('s')) {
		vel.fromArgMod(-PI / 2, GV::V_Nave);
	}
	else vel = Vector2D(0, 0);

}