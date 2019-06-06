#include "Nave_mala.h"
#include "ETSIDI.h"

Nave_mala::Nave_mala() : Nave(GV::HP_Nave_Enemiga, GV::V_Nave), dentro(false), time(0), Cycle_time(GV::T_Disparo_NaveEnemiga){
	puntos = 300;
}

void Nave_mala::GoTo( Vector2D v) {
	Vector2D dir = v - pos;
	vel = Vector2D().fromArgMod(dir.argumento(), V_Nominal);
}

void Nave_mala::Dispara(lista<Disparo> &dis, unsigned char r, unsigned char g, unsigned char b) {
	float old_point = point;
	point += ETSIDI::lanzaDado(-PI / 8, PI / 8);
	Nave::Dispara(dis, r, g, b);
	point = old_point;
}