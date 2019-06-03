#include "Nave_nuestra.h"
#include "glut.h"
#include "GlobalVar.h"


Nave_nuestra::Nave_nuestra() :Nave(GV::HP_Inicial, GV::V_Nave) {
	SetPos(40, 30); //el centro 
	SetColor(255, 215, 0);
}

void Nave_nuestra::Tecla(Teclado &t) {
	//No pulsar A y D a la vez
	//No pulsar W y S a la vez
	if (t.verify('A') || t.verify('a')) {
		if (t.verify('W') || t.verify('w')) {
			vel.fromArgMod(3 * PI / 4, V_Nominal);
		}
		else if (t.verify('S') || t.verify('s')) {
			vel.fromArgMod(-3 * PI / 4, V_Nominal);
		}
		else
			vel.fromArgMod(PI, V_Nominal);
	}
	else if (t.verify('D') || t.verify('d')) {
		if (t.verify('W') || t.verify('w')) {
			vel.fromArgMod(PI / 4, V_Nominal);
		}
		else if (t.verify('S') || t.verify('s')) {
			vel.fromArgMod(-PI / 4, V_Nominal);
		}
		else
			vel.fromArgMod(0, V_Nominal);
	}
	else if (t.verify('W') || t.verify('w')) {
		vel.fromArgMod(PI / 2, V_Nominal);
	}
	else if (t.verify('S') || t.verify('s')) {
		vel.fromArgMod(-PI / 2, V_Nominal);
	}
	else vel = Vector2D(0, 0);


}

