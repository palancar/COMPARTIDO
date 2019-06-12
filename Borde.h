#pragma once
#include "Vector2D.h"

class Borde //BORDE DEL MAPA
{
	Vector2D lim1, lim2; //límites del borde
public:
	Borde(float l1, float l2, float l3, float l4): lim1(l1, l2), lim2(l3, l4) { ; }
	~Borde() { ; }

	void Dibuja();
	Vector2D GetLim1() { return lim1; }
	Vector2D GetLim2() { return lim2; }
};
