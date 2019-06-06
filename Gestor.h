#pragma once
#include "MiMundo.h" 
#include "ETSIDI.h"
#include "glut.h"
#include "Jugadores.h"

class Gestor  {
public: 
	Gestor();   
	~Gestor() {;}
	void Tecla() { mundo.Tecla(); }
	void Mueve(float t);   
	void Dibuja();  
	void Inicializa() { mundo.Inicializa(); }
	void MouseClick(int b, int state);
	void Mouse(int x, int y);
	void press(unsigned char key);
	void SetAuxTi(float aux);
	void unpress(unsigned char key);
	void GoToGameOver() { estado = GAMEOVER; }
	void GoToPausa() { estado = PAUSA; }
	void GoToJuego() { estado = JUEGO; }

protected:  
	enum Estado {INICIO, OPCION1,OPCION2,OPCION3,OPCION4,JUEGO,INSTRUCCIONES,PUNTUACIONES,SALIR,PAUSA,GAMEOVER};
	int HP;
	int Puntos;
	Estado estado;
	Mundo mundo; 
	int auxTitulo;
	///////////////////////////
	Player holagente;
}; 