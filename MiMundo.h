#pragma once
#include "Borde.h"
#include "Nave_nuestra.h"
#include "Teclado.h"
#include "Lista.h"
#include "Choque.h"
#include "GlobalVar.h"

#include <chrono>
#include <iostream>
#include <random>

class Mundo{
	float ojo[3]; //posición del ojo
	float mira[3]; //punto al que mira
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

	std::default_random_engine generator; //esto es para crear cosas aleatorias
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
