#pragma once
#include "Nave.h"

class Nave_mala : public Nave{
	friend class Loop_Generator;
protected:
	float time;
	bool dentro;
public:
	~Nave_mala() { ; }
	Nave_mala();

};