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

#include <chrono>
#include <random>

class Mundo{
	float ojo[3]; //posición del ojo
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
	void Interacciones(float t);

	std::default_random_engine generator;
	std::uniform_real_distribution<float> circulo;
	std::uniform_real_distribution<float> cuartocirculo;

	Borde borde;
	Nave_nuestra nave;
	lista<Disparo> disparo_good;
	lista<Disparo> disparo_bad;
	lista<Asteroide> asteroids;
	lista<Nave> naves_enemigas;
	Teclado teclado;
};
