#include "Choque.h"
#include <math.h>
#include <iostream>

bool Choque::dentro(Vector2D pos, Borde& b) {
	Vector2D lim1 = b.GetLim1();
	Vector2D lim2 = b.GetLim2();
	if (pos.x < lim1.x) return false;
	if (pos.x > lim2.x) return false;
	if (pos.y < lim1.y) return false;
	if (pos.y > lim2.y) return false;
	return true;
}

bool  Choque::dentro(Vector2D pos, float radio) {
	pos.x -= 40; //para centrarlo
	pos.y -= 30;
	if (sqrt(pos.x*pos.x + pos.y*pos.y) >= GV::R_Destruccion) return false;
	return true;
}

/*CHOQUES UNITARIOS*/

bool  Choque::choque(Objeto& ob1, Objeto& ob2) {
	vector2d v1 = ob1.GetPos();
	vector2d v2 = ob2.GetPos();
	// el operador % que me he inventado simplemente indica la distancia
	if (ob1.GetRadio() + ob2.GetRadio() > v1 % v2) return true;
	return false;
}

void  Choque::rebote(Nave &n, Borde &b) {
	Vector2D lim1 = b.GetLim1();
	Vector2D lim2 = b.GetLim2();
	Vector2D pos = n.GetPos();
	float r = n.GetRadio();
	if (pos.x - r / 2 < lim1.x) {
		n.SetPos(lim1.x + r / 2, pos.y);
		n.SetVel(0, n.GetVel().y);

	}
	else if (pos.x + r / 2 > lim2.x) {
		n.SetPos(lim2.x - r / 2, pos.y);
		n.SetVel(0, n.GetVel().y);
	}
	if (pos.y - r / 2 < lim1.y) {
		n.SetPos(pos.x, lim1.y + r / 2);
		n.SetVel(n.GetVel().x, 0);
	}
	else if (pos.y + r / 2 > lim2.y) {
		n.SetPos(pos.x, lim2.y - r / 2);
		n.SetVel(n.GetVel().x, 0);
	}
}

void  Choque::rebote(Objeto &o1, Objeto &o2) {
	if (!choque(o1, o2)) return;
	Vector2D dir = o1.GetPos() - o2.GetPos();
	float r1 = o1.GetRadio();
	float r2 = o2.GetRadio();
	float m1 = r1 * r1;
	float m2 = r2 * r2;
	float dif = dir.modulo() - r1 - r2;
	o1.SetPos(o1.GetPos() - dir.unitario() * dif / 2);
	o2.SetPos(o2.GetPos() + dir.unitario() * dif / 2);

	//objeto1;
	float thN = dir.argumento();
	Vector2D u1 = o1.GetVel(); //velocidad 1 pero girado
	u1.rotar(-thN);
	float u1x_0 = u1.x;

	//esfera2
	Vector2D u2 = o2.GetVel();//velocidad 2 pero girado (cambio de ejes)
	u2.rotar(-thN);
	float u2x_0 = u2.x;

	float e = 0.4; //coeficiente de restitución ( 1 = elástico, 0 = completamente inelástico)
	//solo hay choque en el eje x

	u1.x = ((m1 - m2 * e) * u1x_0 + m2 * (1 + e) * u2x_0) / (m1 + m2);
	u2.x = ((m2 - m1 * e) * u2x_0 + m1 * (1 + e) * u1x_0) / (m1 + m2);
	u1.rotar(+thN);
	u2.rotar(+thN);
	o1.SetVel(u1);
	o2.SetVel(u2);
}

/*CHOQUES DE LISTAS*/

void  Choque::choque_lista(lista<Disparo>& ld, Borde& b) {
	for (int i = 0; i < ld.size(); i++) {
		if (!dentro(ld[i].GetPos(), b)) {
			ld.erase(i);
		}
	}

}

void  Choque::choque_lista(lista<Asteroide>& la, float radio) {
	for (int i = 0; i < la.size(); i++) {
		if (!dentro(la[i].GetPos(), radio)) {
			la.erase(i);
		}
	}

}

void  Choque::choque_lista(lista<Disparo>& ld, lista<Asteroide>& la) {
	for (int i = 0; i < ld.size(); i++) {
		for (int j = 0; j < la.size(); j++) {
			if (choque(ld[i], la[j])) {
				ld.erase(i);
				la[j].SetRadio(la[j].GetRadio() - 1.5);
				if (la[j].GetRadio() < 1) {
					la.erase(j);
				}
				break; //importante
			}
		}
	}
}

void  Choque::choque_lista(lista<Asteroide>& la, Nave& n) {
	for (int i = 0; i < la.size(); i++) {
		if (choque(n, la[i])) {
			la.erase(i);
		}
	}
}

void Choque::rebote_lista(lista<Asteroide>& la) {
	for (int i = 0; i < la.size(); i++) {
		for (int j = i + 1; j < la.size(); j++) {
			rebote(la[i], la[j]);
		}
	}
}

