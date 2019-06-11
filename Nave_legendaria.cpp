#include "Nave_legendaria.h"
#include "Disparo_elite.h"
#include "glut.h"

Nave_legendaria::Nave_legendaria() {
	SetV_Nominal(GV::V_Nave_elite);
	SetHP(100);
	SetRadio(5);
	Cycle_time = 3;
	//175, 185, 186 plata
	SetColor(175, 185, 186);
	puntos = 2000;
}

void Nave_legendaria::Dibuja() {
	//el toroide exterior
	glPushMatrix();
	glColor3ub(r, g, b);
	glTranslatef(pos.x, pos.y, 0);
	glutSolidTorus(2, radio - 0.5, 50, 50);
	glPopMatrix();

	//el cono / disparador
	glPushMatrix();
	glColor3ub(85, 107, 107);
	glTranslatef(pos.x, pos.y, 1);
	glutSolidSphere(radio, 50, 50);
	glRotatef(90, 0, 1, 0); //primera rotación (para que se vea apropiadamente)
	glRotatef(point * 180 / PI, -1, 0, 0); //segunda rotación (adonde apunta) //OJO º / rad
	glutSolidCone(2, 6, 50, 50);
	glTranslatef(0, 0, 4);
	
	glutSolidTorus(0.3, 2, 10, 10);

	glPopMatrix();
}

void Nave_legendaria::Dispara(lista<Disparo> &dis, unsigned char r, unsigned char g, unsigned char b) {
	dis.push_back(new Disparo_elite());
	dis.back()->SetColor(r, g, b);

	//Lo mismo de siempre
	dis.back()->SetPos(pos + Vector2D().fromArgMod(point, radio));
	dis.back()->SetVel(Vector2D().fromArgMod(point, dis.back()->GetV_Nominal()));

}