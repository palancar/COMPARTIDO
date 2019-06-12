#pragma once
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Player {
	string Name;
	long int Puntos;
};

class ListaPlayer : public vector<Player> {
public:
	void agregar(Player& p);
	void ordenar();
	void toFile(string file);
	void fromFile(string file);
	void voltear(char viejo, char nuevo); //pone en la cadena "Name" un carácter nuevo donde antes había otro
	//necesario para poder emplear espacios de forma sencilla


};

