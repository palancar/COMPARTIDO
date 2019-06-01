#pragma once

#include "Objeto.h"
#include <vector>

//Simplemente es la clase vector<...> de siempre, pero con otro nombre y dos funciones más

class lista : public std::vector<Objeto*> {
public:
	void Dibuja();
	void Mueve(float t);
	void erase(unsigned int pos);
};


typedef lista lista_disparos;
typedef lista lista_asteroides;
typedef lista lista_naves;
