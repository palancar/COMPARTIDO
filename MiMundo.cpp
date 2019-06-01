#include <iostream>
#include "MiMundo.h"
#include <math.h>
#include "GlobalVar.h"
#include "Asteroide.h"
#include "glut.h"


/*VERDADERO*/

Mundo::Mundo() : ojo{ 40, 30, GV::Distancia }, mira{ 40, 30, 0 }, borde(0, 0, 80, 60), 
 generator(std::chrono::system_clock::now().time_since_epoch().count()), circulo(-PI, PI), cuartocirculo(0, PI/2) { 
	;
}

void Mundo::Dibuja()
{
	gluLookAt(ojo[0], ojo[1], ojo[2],  // posicion del ojo
		mira[0], mira[1], mira[2],      // hacia que punto mira  
		0.0, 1.0, 0.0);      // definimos hacia arriba (eje Y)    
	glEnable(GL_LIGHTING);

	glEnable(GL_TEXTURE_2D);

	glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("COMPARTIDO/imagenes/superfondo.png").id);
	glDisable(GL_LIGHTING);
	glBegin(GL_POLYGON);
	glColor3f(1, 1, 1);

	glTexCoord2d(0, 1);		glVertex3f(0, 0, -0.1);
	glTexCoord2d(1, 1);		glVertex3f(80, 0, -0.1);
	glTexCoord2d(1, 0);		glVertex3f(80, 60, -0.1);
	glTexCoord2d(0, 0);		glVertex3f(0, 60, -0.1);
	glEnd();

	glEnable(GL_LIGHTING);
	glDisable(GL_TEXTURE_2D);

	borde.Dibuja();
	nave.Dibuja();
	disparo_good.Dibuja();
	asteroids.Dibuja();
}

void Mundo::Mueve(float t)
{
	//Gesti�n de los tiempos incrementales
	static float floattime = 0; //milisegundos que han pasado
	static int inttime = 0; //segundos que han pasado, acumulados
	static bool flancotime = false; //indica flanco de que acaba de pasar un segundo
	if (floattime >= 1) { //cada segundo, reinicia el tiempo float (milisegundos)
		floattime = 0;
		flancotime = true; //adem�s, indica que hay un flanco
		inttime++;
	}
	else flancotime = false;
	floattime += t;


	if (flancotime) { //cada segundo, se crea un asteroide
		float ang = circulo(generator);
		asteroids.push_back(new Asteroide(5.0));
		asteroids.back()->SetPos(Vector2D().fromArgMod(ang, GV::R_Generacion) + Vector2D(40, 30));
		asteroids.back()->SetVel(Vector2D().fromArgMod(ang + PI + cuartocirculo(generator), 15));
	}

	nave.Mueve(t);
	naves_enemigas.Mueve(t);


	naves_enemigas.back()->PointTo(1/*(nave.GetPos() - naves_enemigas.back()->GetPos()).argumento()*/);

	disparo_good.Mueve(t);
	disparo_bad.Mueve(t);
	asteroids.Mueve(t);

	Interacciones();
}

void Mundo::Interacciones() {
	Choque::choque_disparos(disparo_good, borde); //CQ es nuestra particular abreviatura de Choque
	CQ::choque_nave(nave, borde);
	CQ::choque_asteroides(asteroids, GV::R_Destruccion);
	CQ::choque_disparos_asteroides(disparo_good, asteroids);
	CQ::choque_asteroides_nave(asteroids, nave);
	CQ::rebote_lista(asteroids);
}
void Mundo::Inicializa()
{
	naves_enemigas.push_back(new Nave);
	naves_enemigas.back()->SetPos(60, 45);
}

void Mundo::Tecla() {//CAMBIAR ESTO PLZ
	nave.Tecla(teclado);
}


void Mundo::Mouse(int x, int y) {
	Vector2D ratonp(x / 10, 60 - y / 10);
	//float dif = (ratonp - nave.GetPos()).argumento();
	float dif = 1;
	nave.PointTo(dif); //la nave apunta a donde debe
}

void Mundo::MouseClick(int b, int state) {
	if (b == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
		nave.Dispara(disparo_good, 0, 176, 246);
	}
}