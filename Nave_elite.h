#pragma once
#include "Nave_mala.h"

class Nave_elite : public Nave_mala {
	friend class Loop_Generator;
	friend class Choque;
public:
	Nave_elite();
	void Dibuja();
	void Dispara(lista<Disparo>& ld, unsigned char r, unsigned char g, unsigned char b);
};