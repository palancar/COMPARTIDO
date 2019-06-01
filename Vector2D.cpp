#include "Vector2D.h"
#include "math.h"

/*     ----------------------------
	 ---   FUNCIONES / MÉTODOS   ---
	   ----------------------------      */
float Vector2D::modulo() {
	return (float)sqrt(x*x + y * y);
}
float Vector2D::argumento() {
	return (float)atan2(y, x);
}
Vector2D Vector2D::unitario() {
	Vector2D retorno(x, y);
	float mod = modulo();
	if (mod > 0) {
		retorno /= mod;
	}  return retorno;
}
Vector2D Vector2D::normal() {
	return Vector2D(y, -x);
}
Vector2D& Vector2D::fromArgMod(float arg, float mod) {
	x = mod * cos(arg);
	y = mod * sin(arg);
	return *this;
}
Vector2D& Vector2D::rotar(float th) {
	float x_ = x;
	float y_ = y;

	x = x_ * cos(th) - y_ * sin(th);
	y = x_ * sin(th) + y_ * cos(th);
	return *this;
}

/*     ----------------------------
     --- SOBRECARGA DE OPERADORES ---
	   ----------------------------      */

Vector2D Vector2D::operator + (Vector2D v2) {
	return Vector2D(x + v2.x, y + v2.y);
}
Vector2D Vector2D::operator - (Vector2D v2) {
	return Vector2D(x - v2.x, y - v2.y);
}
Vector2D Vector2D::operator * (float f) {
	return Vector2D(x*f, y*f);
}
Vector2D Vector2D::operator / (float c) {
	return Vector2D(x / c, y / c);
}

bool Vector2D::operator == (Vector2D v2) {
	if (v2.x != x || v2.y != y) return false;
	return true;
}
bool Vector2D::operator != (Vector2D v2) {
	if (v2.x != x || v2.y != y) return true;
	return false;
}
bool Vector2D::operator !() {
	if (*this == Vector2D(0, 0)) return true;
	return false;
}

Vector2D& Vector2D::operator += (Vector2D v2) {
	x += v2.x;
	y += v2.y;
	return *this;
}
Vector2D& Vector2D::operator -= (Vector2D v2) {
	x -= v2.x;
	y -= v2.y;
	return *this;
}
Vector2D& Vector2D::operator *= (float c) {
	x *= c;
	y *= c;
	return *this;
}
Vector2D& Vector2D::operator /= (float c) {
	x /= c;
	y /= c;
	return *this;
}

Vector2D operator * (float c, Vector2D v2) {
	return Vector2D(c * v2.x, c * v2.y);
}
float operator * (Vector2D v1, Vector2D v2) {
	return v1.x * v2.x + v1.y * v2.y;
}
float operator ^ (Vector2D v1, Vector2D v2) {
	return v1.x * v2.y - v1.y * v2.x;
}