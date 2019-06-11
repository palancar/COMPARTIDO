#pragma once
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Player {
	string Name;
	int Puntos;
};

class ListaPlayer : public vector<Player> {
public:
	void agregar(Player& p);
	void ordenar();
	void toFile(string file);
	void fromFile(string file);
};

