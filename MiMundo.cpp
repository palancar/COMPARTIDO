#include <iostream>
#include "MiMundo.h"
#include <math.h>
#include "GlobalVar.h"
#include "Asteroide.h"
#include "glut.h"
#include "Loop_Generator.h"

Mundo::Mundo() : ojo{ 40, 30, GV::Distancia }, mira{ 40, 30, 0 }, borde(0, 0, 80, 60){
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
	naves_enemigas.Dibuja();
	disparo_good.Dibuja();
	disparo_bad.Dibuja();
	asteroids.Dibuja();
}

void Mundo::Mueve(float t)
{
	nave.PointTo((nave.GetXYpoint() - nave.GetPos()).argumento());//la nave apunta a donde debe)
	
	
	
	//CREACI�N DE OBJETOS	
	LG::Crear_asteroides(asteroids, t, GV::T_Ciclo_Asteroides, Asteroide());
	LG::Crear_naves(naves_enemigas, t, GV::T_Ciclo_Nave, Nave_mala());
	LG::Naves_disparan(naves_enemigas, disparo_bad, t, GV::T_Disparo_NaveEnemiga);
	LG::Naves_apuntan(naves_enemigas, nave);
	//cosas se mueven
	nave.Mueve(t);
	naves_enemigas.Mueve(t);
	disparo_good.Mueve(t);
	disparo_bad.Mueve(t);
	asteroids.Mueve(t);

	//Interacciones
	Interacciones(t);
}

void Mundo::Interacciones(float t) {
	Choque::choque_lista(disparo_good, borde); //CQ es nuestra particular abreviatura de Choque
	Choque::choque_lista(disparo_bad, borde);
	CQ::rebote(nave, borde);
	CQ::choque_lista(asteroids, GV::R_Destruccion);
	CQ::choque_lista(disparo_good, asteroids,Puntos);		//se suman tambien los puntos
	CQ::choque_lista(disparo_bad, asteroids,NoPuntos);
	CQ::choque_lista(asteroids, nave);
	CQ::rebote_lista(asteroids);
	CQ::rebote_lista(naves_enemigas, borde);
	CQ::rebote_lista(naves_enemigas, asteroids);
	CQ::choque_lista(disparo_good, naves_enemigas,Puntos); //se suman tambien los puntos
	CQ::rebote_lista(naves_enemigas);
	CQ::choque_lista(disparo_bad, nave);
}
void Mundo::Inicializa()
{
	naves_enemigas.resize(0);
	naves_enemigas.shrink_to_fit();
	disparo_good.resize(0);
	disparo_good.shrink_to_fit();
	asteroids.resize(0);
	asteroids.shrink_to_fit();
	disparo_bad.resize(0);
	disparo_bad.shrink_to_fit();
	nave.SetPos(40, 30);
	nave.SetHP(GV::HP_Inicial);
}

void Mundo::Tecla() {//CAMBIAR ESTO PLZ
	nave.Tecla(teclado);
}


void Mundo::Mouse(int x, int y) {
	Vector2D ratonp(x / 10, 60 - y / 10);
	nave.SetXYpoint(ratonp);//el punto al que apunta la nave

}

void Mundo::MouseClick(int b, int state) {
	if (b == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
		nave.Dispara(disparo_good, 0, 176, 246);
		ETSIDI::play("COMPARTIDO/sonidos/disparo1.mp3");
	}
}

