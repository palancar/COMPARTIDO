#include "Loop_Generator.h"
#include "Choque.h"
#include "ETSIDI.h"

void Loop_Generator::nave_dispara(lista<Nave_mala>& ln, lista<Disparo>& ld, float t, float Cycle_time) {
	for (int i = 0; i < ln.size(); i++) {
		if (ln[i].time >= Cycle_time) {
			ln[i].Dispara(ld);
			ln[i].time = 0;
		}
		ln[i].time += t;
	}
}

void Loop_Generator::Crear_asteroides(lista<Asteroide> & la, float t, float Cycle_time, const Asteroide& Asteroid) {
	static float time = 0;
	if (time >= Cycle_time) {
		float ang = ETSIDI::lanzaDado(-PI, PI);
		la.push_back(Asteroid);
		la.back().SetPos(Vector2D().fromArgMod(ang, GV::R_Generacion) + Vector2D(40, 30));
		la.back().SetVel(Vector2D().fromArgMod(ang + PI + ETSIDI::lanzaDado(-PI / 4, PI / 4), la.back().GetV_Nominal()));
		time = 0;
	}
	time += t;
}

void Loop_Generator::Crear_naves(lista<Nave_mala>& ln, float t, static float Cycle_time, const Nave_mala& Nave){
	static float time = 0;
	if (time >= Cycle_time) {
		float ang = ETSIDI::lanzaDado(-PI, PI);
		ln.push_back(Nave);
		ln.back().SetPos(Vector2D().fromArgMod(ang, GV::R_Generacion) + Vector2D(40, 30));
		vector2d pos_to_go(ETSIDI::lanzaDado(0.0, 80.0), ETSIDI::lanzaDado(0.0, 60.0));
		float second_ang = (pos_to_go - ln.back().GetPos()).argumento();
		ln.back().SetVel(Vector2D().fromArgMod(second_ang, ln.back().GetV_Nominal()));
		time = 0;
	}
	time += t;
}