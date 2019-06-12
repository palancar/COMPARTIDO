#include "Player.h"
#include <fstream>

void ListaPlayer::agregar(Player& p) {
	for (int i = 0; i < size(); i++) {
		if (at(i).Name == p.Name) { //at equivale a [i]
			if (p.Puntos > at(i).Puntos)
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
	voltear(' ', '@');
	ofstream fs;
	fs.open(file, ios::out);
	if (fs.fail()) {
		fs.close();
		return;
	}
	fs << size() << endl;
	if (fs.fail()) {
		fs.close();
		return;
	}
	for (int i = 0; i < size(); i++) {
		fs << at(i).Puntos << " " << at(i).Name << endl;
	}
	fs.close();
	voltear('@', ' ');
}

void ListaPlayer::fromFile(string file) {
	ifstream fs;
	int s;
	Player jugador;

	fs.open(file, ios::in);
	fs >> s;
	
	for (int i = 0; i < s; i++) {
		if (fs.eof()) break;
		fs >> jugador.Puntos >> jugador.Name;
		agregar(jugador);
	}
	fs.close();
	voltear('@', ' ');
}

void ListaPlayer::voltear(char viejo, char nuevo) {
	for (int i = 0; i < size(); i++) {
		for (int j = 0; j < at(i).Name.size(); j++) {
			if (at(i).Name[j] == viejo)
				at(i).Name[j] = nuevo;
		}
	}
}