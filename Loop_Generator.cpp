#include "Loop_Generator.h"
#include "ETSIDI.h"

void Loop_Generator::nave_dispara(lista<Nave_mala>& ln, lista<Disparo>& ld, float t, float Cycle_time) {
	for (int i = 0; i < ln.size(); i++) {
		ln[i].time += t;
		if (ln[i].time >= Cycle_time) {
			ln[i].Dispara(ld);
			ln[i].time = 0;
		}
	}
}

void LG::Crear_asteroides(lista<Asteroide> & la, float t, float Cycle_time) {
	static float time = 0;
	time += t;
	
	if (time < Cycle_time) return;
	float ang = ETSIDI::lanzaDado(-PI, PI);
	la.push_back(Asteroide());
	la.back().SetPos(Vector2D().fromArgMod(ang, GV::R_Generacion) + Vector2D(40, 30));
	la.back().SetVel(Vector2D().fromArgMod(ang + PI + ETSIDI::lanzaDado(-PI/4, PI/4), la.back().GetV_Nominal()));
	time = 0;
}