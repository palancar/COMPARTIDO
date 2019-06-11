#pragma once

#include "Nave_mala.h"

class Nave_legendaria : public Nave_mala {
	enum disparo_type{RAFAGA = 0, ELITE, ACELERADO};
	friend class Loop_Generator;
	friend class Choque;
	disparo_type dispt; //usado en la función dispara
	int cuenta_disparos; //usado en la función dispara
	bool pulso; //para el cambio de color interno
public:
	Nave_legendaria();
	void Dibuja();
	void Dispara(lista<Disparo>& ld, unsigned char r, unsigned char g, unsigned char b);
	void Mueve(float t);
};
