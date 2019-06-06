#include "Nave.h"
#include <math.h>
#include "Disparo.h"
#include "GlobalVar.h"
#include "glut.h"

Nave::Nave(int hp, float vel) : point(0), Objeto(2.0, vel), hp(hp) {
	SetColor(194, 65, 164);
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
	glutSolidSphere(radio, 50, 50);
	glRotatef(90, 0, 1, 0); //primera rotación (para que se vea apropiadamente)
	glRotatef(point * 180 / PI, -1, 0, 0); //segunda rotación (adonde apunta) //OJO º / rad
	glutSolidCone(1.4, 5, 50, 50);
	glPopMatrix();
}

void Nave::Dispara(lista<Disparo> &dis, unsigned char r, unsigned char g, unsigned char b) {
	dis.push_back(new Disparo()); //crea un disparo al final
	dis.back()->SetColor(r, g, b);//color muy bonito :)

	//pedir dibujo si no se entiende jeje
	//se puede usar a partir de aquí, indistintamente, la función fromArgMod(...) y rotar(...)
	//se usan las dos como ejemplo
	dis.back()->SetPos(pos + Vector2D().fromArgMod(point, radio));
	dis.back()->SetVel(vel*0.2 + Vector2D().fromArgMod(point, dis.back()->GetV_Nominal()));

}

void Nave::SetHP(int nhp) {
	hp = nhp;
}

void Nave::operator --() {
	hp--;
}


