#pragma once
#include "Nave.h"

class Nave_nuestra : public Nave {
public:
	Nave_nuestra();
	virtual ~Nave_nuestra() { ; }

	void Tecla(Teclado &t);
};