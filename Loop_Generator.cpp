#include "Loop_Generator.h"
#include "Choque.h"
#include "ETSIDI.h"

void Loop_Generator::Naves_disparan(lista<Nave_mala>& ln, lista<Disparo>& ld, float t) {
	for (int i = 0; i < ln.size(); i++) {
		if (ln[i].time >= ln[i].Cycle_time) {
			ln[i].Dispara(ld);
			ETSIDI::play("COMPARTIDO/sonidos/disparo2.wav");
			ln[i].time = 0;
		}
		ln[i].time += t;
	}
}

void Loop_Generator::Crear_asteroides(lista<Asteroide> & la, float t, float Cycle_time, Asteroide* Asteroid) {
	static float time = 0;
	if (time >= Cycle_time) {
		float ang = ETSIDI::lanzaDado(-PI, PI);
		la.push_back(Asteroid);
		la.back()->SetPos(Vector2D().fromArgMod(ang, GV::R_Generacion) + Vector2D(40, 30));
		la.back()->SetVel(Vector2D().fromArgMod(ang + PI + ETSIDI::lanzaDado(-PI / 4, PI / 4), la.back()->GetV_Nominal()));
		time = 0;
	}
	else
		delete Asteroid;
	time += t;
}

void Loop_Generator::Crear_naves(lista<Nave_mala>& ln, float t, float Cycle_time, Nave_mala* Nave, float& statictime){
	if (statictime >= Cycle_time) {
		float ang = ETSIDI::lanzaDado(-PI, PI);

		ln.push_back(Nave);
		ln.back()->SetPos(Vector2D().fromArgMod(ang, GV::R_Generacion) + Vector2D(40, 30));
		ln.back()->GoTo(ETSIDI::lanzaDado(0.0, 80.0), ETSIDI::lanzaDado(0.0, 60.0));
		statictime = 0;
	}
	else
		delete Nave; //importante que se pase un new como puntero
	statictime += t;
}

void Loop_Generator::Naves_apuntan(lista<Nave_mala>& ln, Nave_nuestra& n) {
	for (int i = 0; i < ln.size(); i++) {
		float ang = (n.GetPos() - ln[i].GetPos()).argumento();
		ln[i].PointTo(ang);
	}
}