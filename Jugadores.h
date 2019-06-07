#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>

using namespace std;

class Player {
protected:
public:
	string Name;
	int puntos;
	stringstream sstr;
public:
	//void getName();
	//void getPuntos(int p);
};

class Jugadores {
protected:
	Player jug[5];
};