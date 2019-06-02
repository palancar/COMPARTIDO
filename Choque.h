#pragma once

#include "MiMundo.h"
//lo he llamado Choque.h para que no sea otra vez interacci�n y tal...

class Choque {
public:
	static bool dentro(Vector2D pos, Borde& b); //dentro del mapa
	static bool dentro(Vector2D pos, float radio); //dentro del radio de creadi�n / destrucci�n

	/*CHOQUES UNITARIOS*/

	static bool choque(Objeto& ob1, Objeto& ob2); //dos objetos cualesquiera chocan
	static void choque_borde(Objeto& n, Borde& b); //la nave no puede salir del mapa
	static void rebote_objetos(Objeto &o1, Objeto &o2); //rebote inel�stico de objetos

	/*CHOQUES DE LISTAS*/

	static void choque_disparos(lista<Disparo>& ld, Borde& b); //los disparos no salen del mapa
	static void choque_asteroides(lista<Asteroide>& la, float radio); //choque con el radio exterior de destrucci�n
	static void choque_disparos_asteroides(lista<Disparo>& ld, lista<Asteroide>& la); //choque entre disparos y asteroides
	static void choque_asteroides_nave(lista<Asteroide>& la, Nave n); //choque de la nave con los asteroides
	static void rebote(lista<Asteroide>& la);

	static void nave_dispara(lista<Nave>& ln, lista<Disparo>& ld, float t);
};

typedef Choque CQ;