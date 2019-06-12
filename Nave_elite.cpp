#include "Nave_elite.h"
#include "Disparo_elite.h"
#include "glut.h"

Nave_elite::Nave_elite() {
	SetV_Nominal(GV::V_Nave_elite);
	SetHP(GV::HP_Nave_elite);
	SetRadio(3.25);
	Cycle_time = GV::T_Disparo_Nave_elite;
	SetColor(93, 31, 31);
	puntos = 500;
}

void Nave_elite::Dibuja() {
	//el toroide exterior
	glPushMatrix();
	glColor3ub(r, g, b);
	glTranslatef(pos.x, pos.y, 0);
	glutSolidTorus(2, radio-0.5, 50, 50);
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
	/*glColor3ub(r, g, b);*/
	glutSolidTorus(0.3, 2, 10, 10);
	
	glPopMatrix();
}

void Nave_elite::Dispara(lista<Disparo> &dis, unsigned char r, unsigned char g, unsigned char b) {
	dis.push_back(new Disparo_elite()); //crea un disparo al final
	dis.back()->SetColor(r, g, b);//color muy bonito 
	dis.back()->SetPos(pos + Vector2D().fromArgMod(point, radio));
	dis.back()->SetVel(Vector2D().fromArgMod(point, dis.back()->GetV_Nominal()));

}