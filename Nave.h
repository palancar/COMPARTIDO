#pragma once
#include "Objeto.h"
#include "Lista.h"


class Nave :public Objeto { //en principio es nuestra nave

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

	void Dispara(lista_disparos &dis, unsigned char r, unsigned char g, unsigned char b);
	void Mueve_Disp(float t, lista_disparos& dis); //cosa especial para que dispare cada X tiempo
};


