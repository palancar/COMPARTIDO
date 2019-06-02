#pragma once
#include "Objeto.h"
#include "Disparo.h"
#include "Lista.h"


class Nave :public Objeto { //en principio es nuestra nave
	friend class Choque;
protected:
	float point; //ángulo con el que apunta (en radianes)
	int hp; //vida
	float cicle_time;
public:
	Nave();
	virtual ~Nave() { ; }

	void PointTo(float f) { point = f; }
	virtual void Dibuja();

	int GetHP() { return hp; }
	void SetHP(int nhp);
	void operator --(); //resta 1 a la vida (hp)
	void Dispara(lista<Disparo> &dis, unsigned char r = 245, unsigned char g = 176, unsigned char b = 65); //rgb color de los disparos

};


