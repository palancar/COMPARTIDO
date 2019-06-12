#include "Gestor.h"

using namespace std;

bool valid_char(char& key) {
	if (key >= '0' && key <= '9') return true;
	else if (key >= 'A' && key <= 'Z') return true;
	else if (key >= 'a' && key <= 'z') { 
		key += 'A' - 'a'; //lo pasa a mayúsculas
		return true;
	}
	else if (key = ' ') return true; //se cambia luego a '@' al imprimirlo; 
	else if (key == '_' || key == '-') return true;
	return true;
	return false;
}

Gestor::Gestor() {
	estado = INICIO;
	Inicializa();
	players.fromFile("COMPARTIDO/boxscore.txt");
}

////////////////////////////////
////		DIBUJAR			////
///////////////////////////////

void Gestor::Dibuja() {

	if (estado == INICIO||estado==OPCION1 || estado == OPCION2 || estado == OPCION3 || estado == OPCION4) {
		DibujaFondo();
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

		//OPCIONES DEL MENU
		ETSIDI::setTextColor(1, 1, 0);
		ETSIDI::setFont("COMPARTIDO/fuentes/spaceranger.ttf", 44);
		ETSIDI::printxy("SPACE DESTROYERS", 9, 45);
		ETSIDI::setFont("COMPARTIDO/fuentes/spaceranger.ttf", 25);
		ETSIDI::printxy("JUGAR", 20, 35,2);
		ETSIDI::printxy("INSTRUCCIONES", 20, 30);
		ETSIDI::printxy("PUNTUACIONES", 20, 25);
		ETSIDI::printxy("SALIR", 20, 20);
		ETSIDI::setFont("COMPARTIDO/fuentes/spaceranger.ttf", 18);
		ETSIDI::printxy("PABLO GARCÍA PERIS _53310", 36, 10);
		ETSIDI::printxy("RAÚL PALANCAR G. _53323", 36, 7);
		
	}
	else if (estado == JUEGO) {
	
		mundo.Dibuja();
		HP=mundo.GetHP();
		if (vidas > HP) {			//flanco de bajada en HP
			ETSIDI::play("COMPARTIDO/sonidos/glass.mp3");		//se emite un sonido al perder una vida
			vidas = HP;
		}

		char txt[100];
		snprintf(txt, 100, "VIDAS: %d", HP);  

		actual_player.Puntos = mundo.GetPuntos();
		char TXT[100];
		snprintf(TXT, 100, "PUNTOS: %li", actual_player.Puntos);

		ETSIDI::setTextColor(1, 1, 0);
		ETSIDI::setFont("COMPARTIDO/fuentes/spaceranger.ttf", 20);
		ETSIDI::printxy(txt, 55, 55);			//mostramos las vidas en pantalla
		ETSIDI::printxy(TXT, 10, 55);			//mostramos los puntos en pantalla

	}
	
	//	INSTRUCCIONES

	else if (estado == INSTRUCCIONES) {
		DibujaFondo();

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

	//		PAUSA		///

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

	//		PANTALLA DE GAMEOVER   ///
	
	else if (estado == GAMEOVER) {

		DibujaFondo();
	
		char TXT[100];
		snprintf(TXT, 100, "PUNTOS: %li", actual_player.Puntos);		

		ETSIDI::stopMusica();
		ETSIDI::setTextColor(1, 1, 0);
		ETSIDI::setFont("COMPARTIDO/fuentes/spaceranger.ttf", 55);
		ETSIDI::printxy("GAME OVER", 17, 50);
		ETSIDI::setFont("COMPARTIDO/fuentes/spaceranger.ttf", 30);
		ETSIDI::printxy(TXT, 26,42);				//Mostramos los puntos al jugador
		ETSIDI::printxy("Introduce tu nombre y ", 15, 20);
		ETSIDI::printxy("pulsa enter para volver", 11, 15);
		ETSIDI::printxy("al menu de inicio", 22, 10);
		ETSIDI::printxy(actual_player.Name.c_str(), 20, 30);	//Nombre del jugador
	}


	//   PUNTUACIONES  ////


	else if (estado == PUNTUACIONES) {
		DibujaFondo();
		ETSIDI::setTextColor(1, 1, 0);
		ETSIDI::setFont("COMPARTIDO/fuentes/spaceranger.ttf", 38);
		ETSIDI::printxy("NOMBRE", 12, 45);
		ETSIDI::printxy("PUNTOS", 50, 45);
		ETSIDI::setFont("COMPARTIDO/fuentes/spaceranger.ttf", 34);
		ETSIDI::printxy("Pulsa .Esc. para  volver", 9, 15);
		ETSIDI::printxy("al menu principal", 17, 12);

		//IMPRIME POR ORDEN LOS MEJORES JUGADORES JUNTO CON SU PUNTUACIÓN

		for (int i = 0; i<5&& i < players.size(); i++) {		//Los jugadores ya se almcenan ordenados
			ETSIDI::setFont("COMPARTIDO/fuentes/spaceranger.ttf", 30);		//por lo que solo hay que mostrarlos en orden
			char char_array[100]="";

			snprintf(char_array, 100, "%d.  %s:", i+1,players[i].Name.c_str()); //posicion en el ranking y nombre
			ETSIDI::printxy(char_array, 10, 40-4*i);
			snprintf(char_array, 100, "%d", players[i].Puntos);		//puntos
			ETSIDI::printxy(char_array, 53, 40 - 4 * i);
		
		}
	}
}



void Gestor::Mueve(float t) {
	if (estado ==JUEGO)
		mundo.Mueve(t);


	if (estado == JUEGO && HP == 0) {
		estado = GAMEOVER;
		ETSIDI::play("COMPARTIDO/sonidos/GAMEOVER.mp3");
		actual_player.Name = "";
		actual_player.Name.shrink_to_fit();
		mundo.Inicializa(); //se inicializa el mundo
	}
}


// GESTIÓN DEL RATON

//Se incluyen tambien los cambios de estado producidos con sus acciones

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

//Clicks del Raton con sus respectivas acciones y cambios de estado producidos

void Gestor::MouseClick(int b, int state) {
	if (estado == JUEGO)
		mundo.MouseClick(b, state);		//durante el juego la clase Mundo se ocupa del ratón

	else if(b == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {		//hacer click en las opciones te lleva a las distintos menus
		if (estado == OPCION1) {
			Inicializa();
			estado = JUEGO;
		}
		else if (estado == OPCION2)
			estado = INSTRUCCIONES;
		else if (estado == OPCION3)
			estado = PUNTUACIONES;
		else if (estado == OPCION4) {
			players.toFile("COMPARTIDO/boxscore.txt");	//guardamos los jugadores antes de salir
			estado = SALIR;		//desde el mainglut se lee este estado y se cierra la ventana
		}
	}
}

//	ACCIONES DEL TECLADO
//Se incluyen tambien los cambios de estado que producen

void Gestor::press(unsigned char key) {
	if ((key == 'p' || key == 'P') && estado == JUEGO)
		estado = PAUSA;
	else if ((key == 'p' || key == 'P') && estado == PAUSA) {
		estado = JUEGO;
		ETSIDI::playMusica("COMPARTIDO/sonidos/fondo.mp3", true);
	} 

	//key 27 = escape
	else if (key == 27 && (estado == PAUSA || estado == GAMEOVER)) {
		estado = INICIO;
		ETSIDI::playMusica("COMPARTIDO/sonidos/fondo.mp3", true);
	}
	else if (key == 27 && (estado == INSTRUCCIONES || estado == PUNTUACIONES))
		estado = INICIO;

	else if (estado == JUEGO)
		mundo.teclado.press(key);	//durante juego mundo se ocupa de las teclas, si no son las anteriores

	else if (estado == GAMEOVER) {	//escritura del nombre del jugador y guardado
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
		else if (valid_char(aux_key) && actual_player.Name.size()<12) //comprueba si es válida la tecla introducida y la pasa a mayúsculas si es necesario
			actual_player.Name.push_back(aux_key);
	}
}

void Gestor::unpress(unsigned char key) {
	if (estado == JUEGO)
		mundo.teclado.unpress(key);
}


// VARÍA LA DIFICULTAD EN FUNCIÓN DE LOS PUNTOS

void Gestor::Dificultad() {
	if (AuxPuntos < actual_player.Puntos) {
		
		if (GV::T_Disparo_NaveEnemiga > 0.95)
			GV::T_Disparo_NaveEnemiga -= 0.05;
		if (GV::T_Ciclo_Nave > 6)
			GV::T_Ciclo_Nave -= 0.5;
		if (GV::V_Nave_Mala < 12)
			GV::V_Nave_Mala += 0.2;
		if (GV::V_Asteroides < 20)
			GV::V_Asteroides += 0.5;
		if (GV::T_Ciclo_Nave_elite > 11)
			GV::T_Ciclo_Nave_elite-= 1.0;
		GV::HP_Nave_legendaria += 1;
		AuxPuntos += 4000;
		
	}
	cout << GV::T_Disparo_NaveEnemiga << " ";
}

void Gestor::Inicializa() {
	
	mundo.Inicializa();
	vidas = mundo.GetHP();
	HP = mundo.GetHP();
	GV::T_Disparo_NaveEnemiga = 1.5;
	GV::T_Ciclo_Nave = 12.2;
	GV::V_Nave_Mala = 9.0;
	GV::V_Asteroides = 15.0;
	GV::T_Ciclo_Nave_elite = 28.3;
	AuxPuntos = 4000;	//puntos a partir de los cuales empieza a subir la dificultad
}

void Gestor::DibujaFondo() {

	gluLookAt(40, 30, GV::Distancia,  // posicion del ojo
		40, 30, 0,      // hacia que punto mira  
		0.0, 1.0, 0.0);      // definimos hacia arriba (eje Y)    
	glEnable(GL_LIGHTING);

	glEnable(GL_TEXTURE_2D);

	glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("COMPARTIDO/imagenes/superfondo.png").id);
	glDisable(GL_LIGHTING);
	glBegin(GL_POLYGON);
	glColor3f(255, 255, 255);

	glTexCoord2d(0, 1);		glVertex3f(-2, -2, -2.1);
	glTexCoord2d(1, 1);		glVertex3f(82, -2, -2.1);
	glTexCoord2d(1, 0);		glVertex3f(82, 62, -2.1);
	glTexCoord2d(0, 0);		glVertex3f(-2, 62, -2.1);
	glEnd();

	glDisable(GL_LIGHTING);
	glDisable(GL_TEXTURE_2D);
}