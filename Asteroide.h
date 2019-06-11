#pragma once

#include "Objeto.h"

class Asteroide : public Objeto {
public:
	Asteroide();
	Asteroide(float R);
	~Asteroide() { ; }
	void Dibuja();
};