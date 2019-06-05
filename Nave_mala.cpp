#include "Nave_mala.h"

Nave_mala::Nave_mala() : Nave(GV::HP_Nave_Enemiga, GV::V_Nave), dentro(false), time(0){
	;
}

void Nave_mala::GoTo(Vector2D v) {
	Vector2D dir = v - pos;
	vel = Vector2D().fromArgMod(dir.argumento(), V_Nominal);
}