#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

class Player {
protected:
	string Name;
	int puntos;
public:
	void getName();
	void getPuntos(int p);
};

class Jugadores {
protected:
	Player jug[5];
};