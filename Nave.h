#pragma once
#include "Objeto.h"
#include "Lista.h"


class Nave:public Objeto {
public:
	

private:
	float point; //ángulo con el que apunta (en radianes)

public:
	Nave();
	virtual ~Nave() { ; }

	void PointTo(float f) { point = f; }
	void Dibuja();
	void Tecla(Teclado &t);

	void Dispara(lista_disparos &dis);

};

