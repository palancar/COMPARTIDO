#include "Gestor.h"

using namespace std;

bool valid_char(char& key) {
	if (key >= '0' && key <= '9') return true;
	if (key >= 'A' && key <= 'Z') return true;
	if (key >= 'a' && key <= 'z') { 
		key += 'A' - 'a'; //lo pasa a mayúsculas
		return true;
	}
	if (key == '_' || key == '-') return true;
	return false;
}

Gestor::Gestor() {
	estado = INICIO;
}

void Gestor::Dibuja() {

	if (estado == INICIO||estado==OPCION1 || estado == OPCION2 || estado == OPCION3 || estado == OPCION4) {

		gluLookAt(40, 30, GV::Distancia,  // posicion del ojo
			40, 30, 0,      // hacia que punto mira  
			0.0, 1.0, 0.0);      // definimos hacia arriba (eje Y)    
		glEnable(GL_LIGHTING);

		glEnable(GL_TEXTURE_2D);

		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("COMPARTIDO/imagenes/superfondo.png").id);
		glDisable(GL_LIGHTING);
		glBegin(GL_POLYGON);
		glColor3f(255, 255,255);

		glTexCoord2d(0, 1);		glVertex3f(-2, -2, -2.1);
		glTexCoord2d(1, 1);		glVertex3f(82, -2, -2.1);
		glTexCoord2d(1, 0);		glVertex3f(82, 62, -2.1);
		glTexCoord2d(0, 0);		glVertex3f(-2, 62, -2.1);
		glEnd();

		glDisable(GL_LIGHTING);
		glDisable(GL_TEXTURE_2D);
		//
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
		HP=mundo.GetHP();
		char txt[100];
		snprintf(txt, 100, "VIDAS: %d", HP); //en serio, printf ??? Jajaja

		actual_player.Puntos = mundo.GetPuntos();
		char TXT[100];
		snprintf(TXT, 100, "PUNTOS: %d", actual_player.Puntos);

		ETSIDI::setTextColor(1, 1, 0);
		ETSIDI::setFont("COMPARTIDO/fuentes/spaceranger.ttf", 20);
		ETSIDI::printxy(txt, 55, 55);
		ETSIDI::printxy(TXT, 10, 55);



	}

	else if (estado == INSTRUCCIONES) {
		gluLookAt(40, 30, GV::Distancia,  // posicion del ojo
			40, 30, 0,      // hacia que punto mira  
			0.0, 1.0, 0.0);      // definimos hacia arriba (eje Y)    

		ETSIDI::setTextColor(1, 1, 0);
		ETSIDI::setFont("COMPARTIDO/fuentes/spaceranger.ttf", 44);
		ETSIDI::printxy("INSTRUCCIONES", 15, 50);
		ETSIDI::setFont("COMPARTIDO/fuentes/spaceranger.ttf", 25);
		ETSIDI::printxy("MUEVE LA NAVE CON LAS TECLAS WASD", 5, 42);
		ETSIDI::printxy("DISPARA A ENEMIGOS Y ASTEROIDES CON", 5, 32);
		ETSIDI::printxy("EL BOTÓN IZQUIERDO DEL RATÓN", 5, 27);
		ETSIDI::printxy("PAUSA EL JUEGO CON LA TECLA 'P'", 5, 17);
		ETSIDI::printxy("PULSA .ESC. PARA VOLVER AL MENU", 5, 7);
	}
	else if (estado == PAUSA) {
		ETSIDI::stopMusica();
		mundo.Dibuja();
		ETSIDI::setTextColor(1, 1, 0);
		ETSIDI::setFont("COMPARTIDO/fuentes/spaceranger.ttf", 44);
		ETSIDI::printxy("PAUSA", 30, 30);
		ETSIDI::setFont("COMPARTIDO/fuentes/spaceranger.ttf", 34);
		ETSIDI::printxy("Pulsa .Esc. para  volver", 9, 23);
		ETSIDI::printxy("al menu principal", 17, 18);

	}
	else if (estado == GAMEOVER) {
		gluLookAt(40, 30, GV::Distancia,  // posicion del ojo
			40, 30, 0,      // hacia que punto mira  
			0.0, 1.0, 0.0);      // definimos hacia arriba (eje Y)    

		ETSIDI::stopMusica();
		ETSIDI::setTextColor(1, 1, 0);
		ETSIDI::setFont("COMPARTIDO/fuentes/spaceranger.ttf", 50);
		ETSIDI::printxy("GAME OVER", 20, 50);
		ETSIDI::setFont("COMPARTIDO/fuentes/spaceranger.ttf", 34);
		ETSIDI::printxy("Pulsa .Esc. para  volver", 9, 10);
		ETSIDI::printxy("al menu principal", 17, 5);

		//////////////////////////

		ETSIDI::printxy(actual_player.Name.c_str(), 7, 30);


	}

}

void Gestor::Mueve(float t) {
	if (estado ==JUEGO)
		mundo.Mueve(t);


	if (estado == JUEGO && HP <= 0) {
		estado = GAMEOVER;
		ETSIDI::play("COMPARTIDO/sonidos/GAMEOVER.mp3");
		actual_player.Name = "";
		actual_player.Name.shrink_to_fit();
		//mundo.Inicializa(); //innecesario, ¿no?
	}//lo he quitado del Dibuja porque no tenía mucho sentido que estuviera ahí
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
		if (estado == OPCION1) {
			mundo.Inicializa();
			estado = JUEGO;
		
		}
		else if (estado == OPCION2)
			estado = INSTRUCCIONES;
		else if (estado == OPCION3)
			estado = PUNTUACIONES;
		else if (estado == OPCION4) {
			estado = SALIR;
			players.toFile("COMPARTIDO/boxscore.txt");
			glutDestroyWindow(1);		//ESTO ESTA MUY FEO. HAY QUE HACER EN EL GLUT:
			/*
			cuando se crea la ventana:
			int window=glutcreate....
			para luego poder llamar glutdestroywindow(window);
			*/
		}
	}
}

void Gestor::press(unsigned char key) {
	if ((key == 'p' || key == 'P') && estado == JUEGO)
		estado = PAUSA;
	else if ((key == 'p' || key == 'P') && estado == PAUSA) {
		estado = JUEGO;
		ETSIDI::playMusica("COMPARTIDO/sonidos/fondo.mp3", true);
	} //key 27 = escape
	else if (key == 27 && (estado == PAUSA || estado == INSTRUCCIONES || estado == PUNTUACIONES || estado == GAMEOVER)) {
		ETSIDI::playMusica("COMPARTIDO/sonidos/fondo.mp3", true);
		estado = INICIO;
	}
	else if (estado == JUEGO)
		mundo.teclado.press(key);
	else if (estado == GAMEOVER) {
		char aux_key = key;
		if (key == 8) { //BackSlash(
			if (actual_player.Name.size() > 0)
				actual_player.Name.pop_back();
		}
		else if (key == 13) { //Enter
			players.agregar(actual_player);
			players.ordenar();
			ETSIDI::playMusica("COMPARTIDO/sonidos/fondo.mp3", true);
			players.toFile("COMPARTIDO/boxscore.txt");
			estado = INICIO;
		}
		else if (valid_char(aux_key)) //comprueba si es válida la tecla introducida y la pasa a mayúsculas si es necesario
			actual_player.Name.push_back(aux_key);
		
	}
}

void Gestor::unpress(unsigned char key) {
	if (estado == JUEGO)
		mundo.teclado.unpress(key);
}

void Gestor::SetAuxTi(float aux) {
	auxTitulo = aux;
}

void Gestor::Inicializa(){
	mundo.Inicializa();
	players.fromFile("COMPARTIDO/boxscore.txt");
}