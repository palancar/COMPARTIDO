#pragma once
#include "Objeto.h"
#include "GlobalVar.h"
#include <vector>

class Disparo :public Objeto {

public:
	Disparo() :Objeto(0.5, GV::V_Disparos){ ; }
	~Disparo() { ; }

	void Dibuja();
};
//mecagoentuvidacompañero
