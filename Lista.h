#pragma once
#include <vector>

//Simplemente es la clase vector<...> de siempre, pero con otro nombre y dos funciones más

template <class T> class lista : public std::vector<T> {
public:
	void Dibuja();
	void Mueve(float t);
	void erase(unsigned int pos);
};

template <class T> void lista<T>::Dibuja() {
	for (int i = 0; i < this->size(); i++)
		this->operator[](i).Dibuja();//lista[i].Dibuja(); //no sé por qué funciona
}

template <class T> void lista<T>::Mueve(float t) {
	for (int i = 0; i < this->size(); i++)
		this->operator [](i).Mueve(t);
}

template <class T> void lista<T>::erase(unsigned int pos) {
	this->vector::erase(this->begin() + pos);
	this->shrink_to_fit();
}

