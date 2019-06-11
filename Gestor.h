#pragma once
#include "MiMundo.h" 
#include "ETSIDI.h"
#include "glut.h"
#include "Player.h"

class Gestor  {
public: 
	Gestor();   
	~Gestor() {;}
	void Tecla() { mundo.Tecla(); }
	void Mueve(float t);   
	void Dibuja();  
	void Inicializa();
	void DibujaFondo();
	void MouseClick(int b, int state);
	void Mouse(int x, int y);
	void press(unsigned char key);
	void unpress(unsigned char key);
	bool Salir() { if (estado == SALIR) return true; return false; }
	void GoToGameOver() { estado = GAMEOVER; }
	void GoToPausa() { estado = PAUSA; }
	void GoToJuego() { estado = JUEGO; }
	void Dificultad();

protected:  
	enum Estado {INICIO, OPCION1,OPCION2,OPCION3,OPCION4,JUEGO,INSTRUCCIONES,PUNTUACIONES,SALIR,PAUSA,GAMEOVER};
	int HP;
	//Puntos; //los puntos se hacen iguales a los puntos del jugador jeje
	
	Estado estado;
	Mundo mundo; 
	int vidas;
	long int AuxPuntos;
	///////////////////////////
	Player actual_player;
	ListaPlayer players;
}; 