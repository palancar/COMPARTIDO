#pragma once
#include "Objeto.h"
#include <vector>

class Disparo :public Objeto {

public:
	Disparo() :Objeto(0.5){ ; }
	~Disparo() { ; }

	void Dibuja();
};
//mecagoentuvidacompañero
