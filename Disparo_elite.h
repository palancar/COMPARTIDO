#pragma once
#include "Disparo.h"

class Disparo_elite : public Disparo {
public:
	Disparo_elite();
	~Disparo_elite() { ; }

	void Dibuja();
	void Mueve(float t);
};