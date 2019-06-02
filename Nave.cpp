#include "Nave.h"
#include <math.h>
#include "Disparo.h"
#include "GlobalVar.h"
#include "glut.h"

Nave::Nave() : point(0), Objeto(2.0, GV::V_Nave), hp(GV::HP_Nave_Enemiga), cicle_time(0) {
	SetColor(194, 65, 164);
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
	glRotatef(point * 180 / PI, -1, 0, 0); //segunda rotación (adonde apunta) //OJO º / rad
	glutSolidCone(1.4, 5, 100, 100);
	glPopMatrix();
}

void Nave::Dispara(lista<Disparo> &dis, unsigned char r, unsigned char g, unsigned char b) {
	if (dis.size() >= GV::N_Disparos) {
		//return;
		dis.erase(0); //borra el primer disparo (el más antiguo)
	}
	dis.push_back(Disparo()); //crea un disparo al final
	dis.back().SetColor(r, g, b);//color muy bonito :)

	//pedir dibujo si no se entiende jeje
	//se puede usar a partir de aquí, indistintamente, la función fromArgMod(...) y rotar(...)
	//se usan las dos como ejemplo
	dis.back().SetPos(pos + Vector2D().fromArgMod(point, radio));
	dis.back().SetVel(0.5*vel + Vector2D().fromArgMod(point, dis.back().GetV_Nominal()));
}

void Nave::SetHP(int nhp) {
	hp = nhp;
}

void Nave::operator --() {
	hp--;
}

