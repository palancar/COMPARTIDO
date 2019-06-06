#pragma once
#include "Nave.h"

class Nave_mala : public Nave{
	friend class Loop_Generator;
	friend class Choque;
protected:
	float time;
	bool dentro;
	float Cycle_time;
	int puntos; //puntos recibidos por destruirla
public:
	~Nave_mala() { ; }
	Nave_mala();


	void GoTo(Vector2D v);
	void GoTo(float x, float y) {
		GoTo(Vector2D(x, y));
	}
};