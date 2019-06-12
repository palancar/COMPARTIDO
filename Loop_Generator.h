#pragma once
#include "MiMundo.h" 


class Loop_Generator
{
public:
	Loop_Generator() { ; }
	virtual ~Loop_Generator() { ; }
	static void Naves_disparan(lista<Nave_mala>& ln, lista<Disparo>& ld, float t);
	static void Crear_asteroides(lista<Asteroide> & la, float t, float Cycle_time, Asteroide* Asteroid);
	static void Crear_naves(lista<Nave_mala>& ln, float t, float Cycle_time, Nave_mala* Nave, float& statictime);
	static void Naves_apuntan(lista<Nave_mala>& ln, Nave_nuestra& n);
};


typedef Loop_Generator LG;