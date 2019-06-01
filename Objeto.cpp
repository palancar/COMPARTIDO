#include "Objeto.h"
#include "glut.h"

void Objeto::SetPos(float a, float b) {
	pos = Vector2D(a, b);
}
void Objeto::SetVel(float a, float b)	{
	vel = Vector2D(a, b);
}
void Objeto::SetAcc(float a, float b) {
	acc = Vector2D(a, b);
}
void Objeto::SetPos(const Vector2D & v) {
	pos = v;
}
void Objeto::SetVel(const Vector2D & v) {
	vel = v;
}
void Objeto::SetAcc(const Vector2D & v) {
	acc = v;
}
void Objeto::SetColor(unsigned char r, unsigned char g, unsigned char b) {
	this->r = r;
	this->g = g;
	this->b = b;
}
void Objeto::SetRadio(float r) {
	radio = r;
}

Vector2D Objeto::GetPos() {
	return pos;
}
Vector2D Objeto::GetVel() {
	return vel;
}
Vector2D Objeto::GetAcc() {
	return acc;
}
float Objeto::GetRadio() {
	return radio;
}

void Objeto::Mueve(float t) {
	pos += vel * t;
	vel += acc * t;
}
