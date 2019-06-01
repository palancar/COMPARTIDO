#include "Lista.h"

void lista::Dibuja() {
	for (int i = 0; i < size(); i++)
		operator[](i)->Dibuja();//lista[i].Dibuja(); //no s� por qu� funciona
}

void lista::Mueve(float t) {
	for (int i = 0; i < size(); i++)
		operator [](i)->Mueve(t);
}

void lista::erase(unsigned int pos) {
	delete operator[](pos);
	vector::erase(begin() + pos);
	shrink_to_fit();
}