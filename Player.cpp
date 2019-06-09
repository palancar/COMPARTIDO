#include "Player.h"
#include <fstream>

void ListaPlayer::agregar(Player& p) {
	for (int i = 0; i < size(); i++) {
		if (at(i).Name == p.Name && p.Puntos > at(i).Puntos) { //at equivale a [i]
			at(i) = p;
			return;
		}
	}
	push_back(p);
	ordenar();
}

void ListaPlayer::ordenar() {
	int s = size();
	Player aux;
	for (int i = 0; i < s; i++) {
		for (int j = i + 1; j < s; j++) {
			if (at(i).Puntos < at(j).Puntos) {
				aux = at(i);
				at(i) = at(j);
				at(j) = aux;
			}
		}
	}
}

void ListaPlayer::toFile(string file) {
	ofstream fs;
	fs.open(file, ios::out);
	fs << size() << endl;
	for (int i = 0; i < size(); i++) {
		fs << at(i).Puntos << endl;
		fs << at(i).Name << endl;
	}
	fs.close();
}

void ListaPlayer::fromFile(string file) {
	ifstream fs;
	int s;
	Player jugador;

	fs.open(file, ios::in);
	fs >> s;
	
	for (int i = 0; i < s; i++) {
		fs >> jugador.Puntos;
		fs >> jugador.Name;
		agregar(jugador);
	}
	fs.close();
}