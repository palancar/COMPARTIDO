#pragma once

#include "Nave_mala.h"

class Nave_legendaria : public Nave_mala {
	friend class Loop_Generator;
	friend class Choque;
	int dispt; //usado en la funci�n dispara
	int cuenta_disparos; //usado en la funci�n dispara
public:
	Nave_legendaria();
	void Dibuja();
	void Dispara(lista<Disparo>& ld, unsigned char r, unsigned char g, unsigned char b);
};
