#pragma once
#include <vector>

template <class T> class lista : public std::vector<T*> {
public:
	void Dibuja();
	void Mueve(float t);
	void erase(unsigned int pos);
	T& operator [](int pos);
	void Vaciar();
};

template <class T> void lista<T>::Dibuja() {
	for (int i = 0; i < this->size(); i++)
		this->operator[](i).Dibuja();		//lista[i].Dibuja(); 
}

template <class T> void lista<T>::Mueve(float t) {
	for (int i = 0; i < this->size(); i++)
		this->operator [](i).Mueve(t);
}

template <class T> void lista<T>::erase(unsigned int pos) {
	delete this->vector::operator[] (pos);
	this->vector::erase(this->begin() + pos);
	this->shrink_to_fit();
}

template <class T> T& lista<T>::operator [](int pos) {
	return *this->vector::operator[] (pos); //no te retorna el puntero, sino lo de dentro del puntero
}

template <class T> void lista<T>::Vaciar() {
	for (int i = 0; i < this->size(); i++) {
		delete this->vector::operator[] (i);
	}
	this->vector::resize(0);
	this->vector::shrink_to_fit();
}