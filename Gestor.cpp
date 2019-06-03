#include "Gestor.h"

//hola


void Gestor::Dibuja() {
	if (estado == INICIO||estado==OPCION1 || estado == OPCION2 || estado == OPCION3 || estado == OPCION4) {

		gluLookAt(40, 30, GV::Distancia,  // posicion del ojo
			40, 30, 0,      // hacia que punto mira  
			0.0, 1.0, 0.0);      // definimos hacia arriba (eje Y)    
		glEnable(GL_LIGHTING);
		if (estado == OPCION1) { //dibuja cuadraditos de seleccion
			glColor3b(2, 25, 25);
			glBegin(GL_POLYGON);
			glVertex3d(18, 34, -2);
			glVertex3d(18, 38, -2);
			glVertex3d(50, 38, -2);
			glVertex3d(50, 34, -2);
			glEnd();
		}
		else if (estado == OPCION2) {
			glColor3b(2, 25, 25);
			glBegin(GL_POLYGON);
			glVertex3d(18, 29, -2);
			glVertex3d(18, 33, -2);
			glVertex3d(50, 33, -2);
			glVertex3d(50, 29, -2);
			glEnd();
		}
		else if (estado == OPCION3) {
			glColor3b(2, 25, 25);
			glBegin(GL_POLYGON);
			glVertex3d(18, 24, -2);
			glVertex3d(18, 28, -2);
			glVertex3d(50, 28, -2);
			glVertex3d(50, 24, -2);
			glEnd();
		}
		else if (estado == OPCION4) {
			glColor3b(2, 25, 25);
			glBegin(GL_POLYGON);
			glVertex3d(18, 19, -2);
			glVertex3d(18, 23, -2);
			glVertex3d(50, 23, -2);
			glVertex3d(50, 19, -2);
			glEnd();
		}

		ETSIDI::setTextColor(1, 1, 0);
		ETSIDI::setFont("COMPARTIDO/fuentes/spaceranger.ttf", 44);
		ETSIDI::printxy("SPACE DESTROYERS", 9, 45);
		ETSIDI::setFont("COMPARTIDO/fuentes/spaceranger.ttf", 25);
		ETSIDI::printxy("JUGAR", 20, 35,2);
		ETSIDI::printxy("INSTRUCCIONES", 20, 30);
		ETSIDI::printxy("PUNTUACIONES", 20, 25);
		ETSIDI::printxy("SALIR", 20, 20);


	}
	else if (estado == JUEGO) {
		mundo.Dibuja();
	}
	else if (estado == PAUSA) {
		mundo.Dibuja();
		ETSIDI::setTextColor(1, 1, 0);
		ETSIDI::setFont("COMPARTIDO/fuentes/spaceranger.ttf", 44);
		ETSIDI::printxy("PAUSA", 30, 30);
	}
}

void Gestor::Mueve(float t) {
	if (estado ==JUEGO)
		mundo.Mueve(t);
}
Gestor::Gestor() {
	estado = INICIO;
	auxTitulo = 0;
}

void Gestor::Mouse(int x, int y) {

	if (estado == JUEGO)
		mundo.Mouse(x, y);
	else if ((estado == INICIO || estado == OPCION1 || estado == OPCION2 || estado == OPCION3 || estado == OPCION4) && x / 10 > 19 && x / 10 < 45) {
		if ((60 - y / 10) < 38 && (60 - y / 10) > 34)
			estado = OPCION1;
		else if ((60 - y / 10) < 33 && (60 - y / 10) > 29)			//detectar que estas sobre las opciones
			estado = OPCION2;
		else if ((60 - y / 10) < 28 && (60 - y / 10) > 24)
			estado = OPCION3;
		else if ((60 - y / 10) < 23 && (60 - y / 10) > 19)
			estado = OPCION4;
		else
			estado = INICIO;
	}
}

void Gestor::MouseClick(int b, int state) {
	if (estado == JUEGO)
		mundo.MouseClick(b, state);
	else if(b == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {		//hacer click en las opciones te lleva a las distintos menus
		if (estado == OPCION1)
			estado = JUEGO;
		else if (estado == OPCION2)
			estado = INSTRUCCIONES;
		else if (estado == OPCION3)
			estado = PUNTUACIONES;
		else if (estado == OPCION4)
			estado = SALIR;
	}
}
void Gestor::press(unsigned char key) {
	if ((key == 'p' || key == 'P') && estado == JUEGO)
		estado = PAUSA;
	else if ((key == 'p' || key == 'P') && estado == PAUSA)
		estado = JUEGO;
	else if (estado == JUEGO)
		mundo.teclado.press(key);
	
}
void Gestor::unpress(unsigned char key) {
	if (estado == JUEGO)
		mundo.teclado.unpress(key);
}
void Gestor::SetAuxTi(float aux) {
	auxTitulo = aux;
}