#pragma once

#include "Objeto.h"

class Asteroide : public Objeto {
public:
	Asteroide(float rad);
	~Asteroide() { ; }
	void Dibuja();
};