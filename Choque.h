#pragma once

#include "MiMundo.h"
#include "Nave_mala.h"
//lo he llamado Choque.h para que no sea otra vez interacción y tal...

class Choque {
public:
	static bool dentro(Vector2D pos, Borde& b); //dentro del mapa
	static bool dentro(Vector2D pos, float radio); //dentro del radio de creadión / destrucción

	/*CHOQUES UNITARIOS*/
	//se llaman choque si implica destrucción, rebote si no
	static bool choque(Objeto& ob1, Objeto& ob2); //dos objetos cualesquiera chocan
	static bool rebote(Nave& n, Borde& b); //la nave no puede salir del mapa
	static bool rebote(Objeto &o1, Objeto &o2); //rebote inelástico de objetos

	/*CHOQUES DE LISTAS*/

	static void choque_lista(lista<Disparo>& ld, Borde& b); //los disparos no salen del mapa
	static void choque_lista(lista<Asteroide>& la, float radio); //choque con el radio exterior de destrucción
	static void choque_lista(lista<Disparo>& ld, lista<Asteroide>& la); //choque entre disparos y asteroides
	static void choque_lista(lista<Disparo>& ld, lista<Asteroide>& la, int &puntos); //choque entre disparos y asteroides con puntuación
	static void choque_lista(lista<Asteroide>& la, Nave& n); //choque de la nave con los asteroides
	static void rebote_lista(lista<Asteroide>& la);//choque de los asteroides entre sí
	static void rebote_lista(lista<Nave_mala>& ln, Borde& b); //choque de naves con el borde
	static void rebote_lista(lista<Nave_mala>& ln, lista<Asteroide>& la); //las naves rebotan con los asteroides
	static void rebote_lista(lista<Nave_mala>& ln); //rebotes entre naves 
	static bool choque_lista(lista<Disparo>& ld, Nave& n); //choque entre disparos y nave
	static void choque_lista(lista<Disparo>& ld, lista<Nave_mala>& ln, int &puntos); //a las naves les llega un disparo y puntuación

};

typedef Choque CQ;