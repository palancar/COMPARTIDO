#include <iostream>
#include "MiMundo.h"
#include <math.h>
#include "GlobalVar.h"
#include "Asteroide.h"
#include "glut.h"

Mundo::Mundo() : time(0), ojo{ 40, 30, GV::Distancia }, mira{ 40, 30, 0 }, borde(0, 0, 80, 60), 
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
	time += t;
	nave.Mueve(t);
	disparo_good.Mueve(t);
	asteroids.Mueve(t);
	
	if (time >= 1) { //cada segundo, se crea un asteroide
		float ang = circulo(generator);
		asteroids.push_back(new Asteroide(3.0));
		asteroids.back()->SetPos(Vector2D().fromArgMod(ang, GV::R_Generacion) + Vector2D(40, 30));
		asteroids.back()->SetVel(Vector2D().fromArgMod(ang + PI + cuartocirculo(generator), 15));
		time = 0;
	}
	Interacciones();
}

void Mundo::Interacciones() {
	choque_disparos(disparo_good, borde);
	choque_nave(nave, borde);
}
void Mundo::Inicializa()
{

}

void Mundo::Tecla() {//CAMBIAR ESTO PLZ
	nave.Tecla(teclado);
}


void Mundo::Mouse(int x, int y) {
	Vector2D ratonp(x / 10, 60 - y / 10);
	float dif = (ratonp - nave.GetPos()).argumento();
	nave.PointTo(dif); //la nave apunta a donde debe
}

void Mundo::MouseClick(int b, int state) {
	if (b == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
		nave.Dispara(disparo_good);
	}
}