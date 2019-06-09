#pragma once
#pragma comment(lib, "ETSIDI.lib")
#include <iostream>
#include "ETSIDI.h"
#include "Borde.h"
#include "Nave_nuestra.h"
#include "Teclado.h"
#include "Disparo.h"
#include "Asteroide.h"
#include "Lista.h"
#include "Choque.h"
#include "GlobalVar.h"
#include "Nave_elite.h"


class Mundo{
	float ojo[3]; //posición del ojo
	float mira[3]; //punto al que mira
	float time;
	int Puntos;

	float time1;//necesarios por ciertos motivos relacionados con la generación de naves
	float time2;
public:

	Mundo();
	~Mundo() { ; }

	void Inicializa();

	void Tecla();
	void Mueve(float t);
	void Dibuja();
	void Mouse(int x, int y);
	void MouseClick(int b, int state);
	void Interacciones(float t);
	void SumaPuntos(int p) { Puntos += p; }
	int GetHP() { return nave.GetHP(); }
	void ResetPuntos() { Puntos = 0; }
	int GetPuntos() { return Puntos; }


	Borde borde;
	Nave_nuestra nave;
	lista<Disparo> disparo_good;
	lista<Disparo> disparo_bad;
	lista<Asteroide> asteroids;
	lista<Nave_mala> naves_enemigas;
	Teclado teclado;
};
