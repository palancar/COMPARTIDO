#pragma once

#include "MiMundo.h"
//lo he llamado Choque.h para que no sea otra vez interacción y tal...


bool dentro(Vector2D pos, Borde& b);

/*CHOQUES UNITARIOS*/

bool choque(Objeto& o, Borde& b);
bool choque_nave(Nave& n, Borde& b);

/*CHOQUES DE LISTAS*/

bool choque_disparos(lista_disparos& ld, Borde& b);