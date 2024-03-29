#include "Nave.h"
#include <math.h>
#include "Disparo.h"
#include "GlobalVar.h"
#include "glut.h"

Nave::Nave(int hp, float vel) : point(0), Objeto(2.0, vel), hp(hp) {
	SetColor(194, 65, 16);
}

void Nave::Dibuja() {
	//el toroide exterior
	glPushMatrix();
	glColor3ub(r, g, b);
	glTranslatef(pos.x, pos.y, 0);
	glutSolidTorus(1, radio, 50, 50);
	glPopMatrix();

	//el cono / disparador
	glPushMatrix();
	glColor3ub(230, 46, 0);
	glTranslatef(pos.x, pos.y, 1);
	glutSolidSphere(radio, 10, 10);
	glRotatef(90, 0, 1, 0); //primera rotaci�n (para que se vea apropiadamente)
	glRotatef(point * 180 / PI, -1, 0, 0); //segunda rotaci�n (adonde apunta) //OJO � / rad
	//glutSolidCone(1.2, 5, 10, 10);
	gluCylinder(gluNewQuadric(), 1.2f, 0.7f, 3.8f, 10, 10); //mira aver si te gusta mas siendo un cilindro

	glPopMatrix();
}

void Nave::Dispara(lista<Disparo> &dis, unsigned char r, unsigned char g, unsigned char b) {
	dis.push_back(new Disparo());	//crea un disparo al final
	dis.back()->SetColor(r, g, b);	//color 
	dis.back()->SetPos(pos + Vector2D().fromArgMod(point, radio));
	dis.back()->SetVel(vel*0.2 + Vector2D().fromArgMod(point, dis.back()->GetV_Nominal()));

}

void Nave::SetHP(int nhp) {
	hp = nhp;
}

void Nave::operator --() {
	hp--;
}

void Nave::operator ++() {
	hp++;
}


