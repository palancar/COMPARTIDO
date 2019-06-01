#pragma once
#pragma comment(lib, "ETSIDI.lib")
#include <iostream>
#include "ETSIDI.h"
#include "Borde.h"
#include "Nave_nuestra.h"
#include "Teclado.h"
#include "Lista.h"
#include "Choque.h"
#include "GlobalVar.h"

#include <chrono>
#include <random>

class Mundo{
	float ojo[3]; //posici�n del ojo
	float mira[3]; //punto al que mira
	float time;
public:


	Mundo();
	~Mundo() { ; }


	void Inicializa();

	void Tecla();
	void Mueve(float t);
	void Dibuja();
	void Mouse(int x, int y);
	void MouseClick(int b, int state);
	void Interacciones();

	std::default_random_engine generator;
	std::uniform_real_distribution<float> circulo;
	std::uniform_real_distribution<float> cuartocirculo;

	Borde borde;
	Nave_nuestra nave;
	lista_disparos disparo_good;
	lista_disparos disparo_bad;
	lista_asteroides asteroids;
	lista_naves naves_enemigas;
	Teclado teclado;
};
