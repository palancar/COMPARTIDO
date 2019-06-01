#pragma once
#include "Vector2D.h"
#include "Teclado.h"

class Objeto {
protected:
	unsigned char r, g, b; //colores
	Vector2D pos, vel, acc;
	float radio;
public:

	Objeto(float r) :pos(0, 0), vel(0, 0), acc(0, 0), radio(r), r(255), g(255), b (255) { ; }
	virtual ~Objeto() { ; }

	void SetPos(float a, float b);
	void SetVel(float a, float b);
	void SetAcc(float a, float b);
	void SetPos(const Vector2D & v);
	void SetVel(const Vector2D & v);
	void SetAcc(const Vector2D & v);
	void SetRadio(float r);
	void SetColor(unsigned char r, unsigned char g, unsigned char b);

	Vector2D GetPos();
	Vector2D GetVel();
	Vector2D GetAcc();
	float GetRadio();


	virtual void Mueve(float t);
	virtual void Dibuja() = 0;//si da errores, en vez de poner = 0, poner { ; }
	virtual void PointTo(float) { ; }
	//virtual void Mueve_Disp(float t, lista_disparos& dis) { ; }
};
