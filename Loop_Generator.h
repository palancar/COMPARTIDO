#pragma once
#include "MiMundo.h" 


class Loop_Generator
{
public:
	Loop_Generator() { ; }
	virtual ~Loop_Generator() { ; }

	static void nave_dispara(lista<Nave_mala>& ln, lista<Disparo>& ld, float t, float Cycle_time);
	static void Crear_asteroides(lista<Asteroide>& la, float t, float Cycle_time);

};

typedef Loop_Generator LG;