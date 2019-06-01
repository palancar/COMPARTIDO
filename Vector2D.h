#pragma once

#define PI 3.1415926535

class Vector2D {
public:
	
	float x;
	float y;
	Vector2D(float x_, float y_) : x(x_), y(y_) { ; }
	Vector2D() : x(0), y(0) { ; }

	float modulo();
	float argumento();
	Vector2D unitario();
	Vector2D normal();
	Vector2D& fromArgMod(float arg, float mod = 1);
	Vector2D& rotar(float th);

	Vector2D operator + (Vector2D v2);
	Vector2D operator - (Vector2D v2);
	Vector2D operator * (float f);
	Vector2D operator / (float c);
	float operator % (Vector2D v2); //operador distancia jeje

	bool operator == (Vector2D v2);
	bool operator != (Vector2D v2);
	bool operator !();


	Vector2D& operator += (Vector2D v2);
	Vector2D& operator -= (Vector2D v2);
	Vector2D& operator *= (float c);
	Vector2D& operator /= (float c);

	friend Vector2D operator * (float c, Vector2D v2);
	friend float operator * (Vector2D v1, Vector2D v2);
	friend float operator ^ (Vector2D v1, Vector2D v2); //producto vectorial (no devuelve vector 
	//sino el resultado de la coordenada z. Equivalente a hacer el determinante de la matriz de 
	//los dos vectores fila o columna
};

typedef Vector2D vector2d;


