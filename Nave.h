#pragma once
#include "Objeto.h"
#include "Disparo.h"
#include "Lista.h"


class Nave :public Objeto { 
	friend class Loop_Generator;
protected:
	float point; //ángulo con el que apunta (en radianes)
	int hp; //vida

public:
	Nave(int hp, float vel);
	virtual ~Nave() { ; }

	void PointTo(float f) { point = f; }
	virtual void Dibuja();

	int GetHP() { return hp; }
	void SetHP(int nhp);
	void operator --(); //resta 1 a la vida (hp)
	void operator ++(); //suma 1 a la vida (hp)
	virtual void Dispara(lista<Disparo> &dis, unsigned char r = 245, unsigned char g = 176, unsigned char b = 65); //rgb color de los disparos

};


