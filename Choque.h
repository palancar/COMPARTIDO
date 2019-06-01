#pragma once

#include "MiMundo.h"
//lo he llamado Choque.h para que no sea otra vez interacción y tal...

class Choque {
public:
	static bool dentro(Vector2D pos, Borde& b); //dentro del mapa
	static bool dentro(Vector2D pos, float radio); //dentro del radio de creadión / destrucción

	/*CHOQUES UNITARIOS*/

	static bool choque(Objeto& ob1, Objeto& ob2); //dos objetos cualesquiera chocan
	static bool choque_nave(Nave& n, Borde& b); //la nave no puede salir del mapa
	static void rebote_objetos(Objeto &o1, Objeto &o2); //rebote inelástico de objetos

	/*CHOQUES DE LISTAS*/

	static void choque_disparos(lista_disparos& ld, Borde& b); //los disparos no salen del mapa
	static void choque_asteroides(lista_asteroides& la, float radio); //choque con el radio exterior de destrucción
	static void choque_disparos_asteroides(lista_disparos & ld, lista_asteroides& la); //choque entre disparos y asteroides
	static void choque_asteroides_nave(lista_asteroides& la, Nave n); //choque de la nave con los asteroides
	static void rebote_lista(lista& la);
};

typedef Choque CQ;