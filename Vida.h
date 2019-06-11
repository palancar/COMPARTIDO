#pragma once
#include "Objeto.h"

class Vida :public Objeto { //Bonus 
	bool pulso[3]; //true = aumenta color, false = disminuye. Es un vector que se encarga de variar el color rgb con el tiempo
public:
	Vida(); //las vidas no se mueven de donde caen
	~Vida() { ; }

	void Dibuja();
	void Mueve(float t);
};