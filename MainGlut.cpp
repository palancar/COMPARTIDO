#include <iostream>
#include "MiMundo.h"
#include "Gestor.h"
#include "ETSIDI.h"

Gestor gestor;

//VARIABLES GLOBALES
float GV::Distancia = 82.5;
float GV::R_Generacion = 55.0;
float GV::R_Destruccion = 65.0;
float GV::V_Disparos = 40.0;
float GV::V_Nave = 20.0;
float GV::V_Nave_Mala = 9.0;
float GV::V_Asteroides = 15.0;
int GV::HP_Inicial = 3;
int GV::HP_Nave_Enemiga = 3;
float GV::T_Disparo_NaveEnemiga = 1.24;
float GV::T_Ciclo_Asteroides = 1.75;
float GV::T_Ciclo_Nave = 10.0;
float GV::R_Asteroide = 5.0;
float GV::V_Nave_elite = 5;
float GV::HP_Nave_elite = 10;
float GV::V_Disparo_elite = 30.0;
float GV::T_Disparo_Nave_elite = 2.1;
float GV::T_Ciclo_Nave_elite = 14.75;



//los callback, funciones que seran llamadas automaticamente por la glut
//cuando sucedan eventos
//NO HACE FALTA LLAMARLAS EXPLICITAMENTE
void OnDraw(void); //esta funcion sera llamada para dibujar
void OnTimer(int value); //esta funcion sera llamada cuando transcurra una temporizacion
void OnKeyboardDown(unsigned char key, int x, int y); //cuando se pulse una tecla	
void OnSpecialKeyboardDown(int key, int x, int y); //al pulsar una tecla especial (no se usa)
void OnMouseClick(int button, int state, int x, int y); //al pulsar el ratón
void OnMouseMove(int x, int y); //al mover el ratón
void OnRelease(unsigned char key, int x, int y); //cuando se suelta la tecla
void OnIdle(); //al no hacer nada (debe hacerse cuando se mantienen varias teclas pulsadas (???)


int main(int argc, char* argv[]) {

	//Inicializar el gestor de ventanas GLUT
	//y crear la ventana
	glutInit(&argc, argv);
	glutInitWindowSize(800, 600);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutCreateWindow("SPACE DESTROYERS");

	//habilitar luces y definir perspectiva
	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHTING);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_COLOR_MATERIAL);
	glMatrixMode(GL_PROJECTION);
	gluPerspective(40.0, 800 / 600.0f, 0.1, 150);

	//Hola

	glutSetCursor(GLUT_CURSOR_FULL_CROSSHAIR);
	
	//Registrar los callbacks
	glutDisplayFunc(OnDraw);
	glutTimerFunc(25, OnTimer, 0);//le decimos que dentro de 25ms llame 1 vez a la funcion OnTimer()
	glutKeyboardFunc(OnKeyboardDown); //al pulsar una tecla
	glutSpecialFunc(OnSpecialKeyboardDown); //gestion de los cursores 
	glutMouseFunc(OnMouseClick); //al pulsar el ratón
	glutPassiveMotionFunc(OnMouseMove); //al MOVER el ratón
	glutKeyboardUpFunc(OnRelease); //al dejar de pulsar la tecla
	glutIdleFunc(OnIdle);//cuando no se hace nada

	ETSIDI::playMusica("COMPARTIDO/sonidos/fondo.mp3", true);
	gestor.Inicializa();

	//pasarle el control a GLUT,que llamara a los callbacks
	glutMainLoop();

	return 0;
}

void OnDraw(void)
{
	//Borrado de la pantalla	
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//Para definir el punto de vista
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	/*---PRIMITIVAS DE DIBUJO---
	glutWireSphere( radius,  slices,  stacks);
	glutSolidSphere(radius,  slices,  stacks);
	glutWireCone( base,  height,  slices,  stacks);
	glutSolidCone( base,  height,  slices,  stacks);
	glutWireCube( size);
	glutSolidCube( size);
	glutWireTorus( innerRadius,  outerRadius,  sides,  rings);
	glutSolidTorus( innerRadius,  outerRadius,  sides,  rings);
	glutWireDodecahedron();
	glutSolidDodecahedron();
	glutWireTeapot( size);
	glutSolidTeapot( size);
	glutWireOctahedron();
	glutSolidOctahedron();
	glutWireTetrahedron();
	glutSolidTetrahedron();
	glutWireIcosahedron();
	glutSolidIcosahedron();
	*/

	gestor.Dibuja();
	
	//no borrar esta linea ni poner nada despues
	glutSwapBuffers();
}



void OnTimer(int value)
{
	static float aux=0;
	//poner aqui el código de animacion
	gestor.Mueve(0.025);
	gestor.Tecla();

	//no borrar estas lineas
	glutTimerFunc(25, OnTimer, 0);
	glutPostRedisplay();
}

void OnSpecialKeyboardDown(int key, int x, int y) {
	
}

void OnMouseClick(int b, int state, int x, int y) {
	
	gestor.MouseClick(b, state);
}

void OnMouseMove(int x, int y){
	gestor.Mouse(x, y);

	//glutPostRedisplay();
}

void OnKeyboardDown(unsigned char key, int x_t, int y_t)
{
	//poner aqui el código de teclado
	gestor.press(key);
	 //presionas la tecla del teclado

	glutPostRedisplay();
}

void OnRelease(unsigned char key, int x, int y) {
	 //sueltas la tecla del teclado
	gestor.unpress(key);
	glutPostRedisplay();
}


void OnIdle() {

	glutPostRedisplay();
}

