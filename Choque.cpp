#include "Choque.h"
#include <math.h>
#include <iostream>
#include "ETSIDI.h"

bool Choque::dentro(Vector2D pos, Borde& b) {
	Vector2D lim1 = b.GetLim1();
	Vector2D lim2 = b.GetLim2();
	if (pos.x < lim1.x) return false;
	if (pos.x > lim2.x) return false;
	if (pos.y < lim1.y) return false;
	if (pos.y > lim2.y) return false;
	return true;
}





bool Choque::dentro(Vector2D pos, float radio) {
	pos.x -= 40; //para centrarlo
	pos.y -= 30;
	if (sqrt(pos.x*pos.x + pos.y*pos.y) >= GV::R_Destruccion) return false;
	return true;
}

/*CHOQUES UNITARIOS*/

bool Choque::choque(Objeto& ob1, Objeto& ob2) {
	vector2d v1 = ob1.GetPos();
	vector2d v2 = ob2.GetPos();
	// el operador % que me he inventado simplemente indica la distancia
	if (ob1.GetRadio() + ob2.GetRadio() > v1 % v2) return true;
	return false;
}

bool Choque::rebote(Nave &n, Borde &b) {
	bool ret_val = false;
	Vector2D lim1 = b.GetLim1();
	Vector2D lim2 = b.GetLim2();
	Vector2D pos = n.GetPos();
	float r = n.GetRadio();
	if (pos.x - r / 2 < lim1.x) {
		n.SetPos(lim1.x + r / 2, pos.y);
		n.SetVel(0, n.GetVel().y);
		ret_val = true;
	}
	else if (pos.x + r / 2 > lim2.x) {
		n.SetPos(lim2.x - r / 2, pos.y);
		n.SetVel(0, n.GetVel().y);
		ret_val = true;
	}
	if (pos.y - r / 2 < lim1.y) {
		n.SetPos(pos.x, lim1.y + r / 2);
		n.SetVel(n.GetVel().x, 0);
		ret_val = true;
	}
	else if (pos.y + r / 2 > lim2.y) {
		n.SetPos(pos.x, lim2.y - r / 2);
		n.SetVel(n.GetVel().x, 0);
		ret_val = true;
	}
	return ret_val;
}

bool Choque::rebote(Objeto &o1, Objeto &o2) {
	if (!choque(o1, o2)) return false;
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
	return true;
}

/*CHOQUES DE LISTAS*/

void Choque::choque_lista(lista<Disparo>& ld, Borde& b) {
	for (unsigned int i = 0; i < ld.size(); i++) {
		if (!dentro(ld[i].GetPos(), b)) {
			ld.erase(i);
		}
	}

}

void Choque::choque_lista(lista<Asteroide>& la, float radio) {
	for (unsigned int i = 0; i < la.size(); i++) {
		if (!dentro(la[i].GetPos(), radio)) {
			la.erase(i);
		}
	}

}

void Choque::choque_lista(lista<Disparo>& ld, lista<Asteroide>& la,long int &puntos,lista<Vida>& lv) {
	for (unsigned int i = 0; i < ld.size(); i++) {
		for (unsigned int j = 0; j < la.size(); j++) {
			if (choque(ld[i], la[j])) {

				ld.erase(i);
				la[j].SetRadio(la[j].GetRadio() - 1.5);
				ETSIDI::play("COMPARTIDO/sonidos/HIT.wav");
				puntos += 20;
				if (la[j].GetRadio() < 1) {
					if (ETSIDI::lanzaDado(1, 20) == 20) {//probabilidad de 1 / 20 de que salga una vida
						lv.push_back(new Vida());
						lv.back()->SetPos((la[j].GetPos()));
					}
					la.erase(j);
					puntos += 20;
				}
				break; //importante
			}
		}
	}
}

void Choque::choque_lista(lista<Disparo>& ld, lista<Asteroide>& la) {
	for (int i = 0; i < ld.size(); i++) {
		for (int j = 0; j < la.size(); j++) {
			if (choque(ld[i], la[j])) {
				ld.erase(i);
				la[j].SetRadio(la[j].GetRadio() - 1.5);
				ETSIDI::play("COMPARTIDO/sonidos/HIT.wav");
				if (la[j].GetRadio() < 1) {
					la.erase(j);
				}
				break; //importante
			}
		}
	}
}

void Choque::choque_lista(lista<Asteroide>& la, Nave& n) {
	for (int i = 0; i < la.size(); i++) {
		if (choque(n, la[i])) {
			la.erase(i);
			n.operator --();
			ETSIDI::play("COMPARTIDO/sonidos/unamenos.wav");
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

void Choque::rebote_lista(lista<Nave_mala>& ln, Borde& b) {
	for (int i = 0; i < ln.size(); i++) {
		if (!ln[i].dentro) {
			ln[i].dentro = CQ::dentro(ln[i].pos, b);
			if (ln[i].dentro)
				ETSIDI::play("COMPARTIDO/sonidos/nuevanave.mp3");  //sonido nave enemiga ha entrado
		}
		else {
			if (rebote(ln[i], b)) {
				ln[i].GoTo(ETSIDI::lanzaDado(b.GetLim1().x, b.GetLim2().x), ETSIDI::lanzaDado(b.GetLim1().y, b.GetLim2().y));
			}
		}
	}
}

void Choque::rebote_lista(lista<Nave_mala>& ln, lista<Asteroide>& la) {
	for (int i = 0; i < ln.size(); i++) {
		if (ln[i].dentro) {
			ln[i].radio += 1; //se usa un radio mayor para los rebotes con asteroides
			for (int j = 0; j < la.size(); j++) {
				if (rebote(ln[i], la[j])) {
					ln[i].GoTo(ETSIDI::lanzaDado(0.0, 80.0), ETSIDI::lanzaDado(0.0, 60.0));
				}
			}
			ln[i].radio -= 1;
		}
	}
}

void Choque::rebote_lista(lista<Nave_mala>& ln) {
	for (int i = 0; i < ln.size(); i++) {
		for (int j = i + 1; j < ln.size(); j++) {

			if (rebote(ln[i], ln[j]))
				ln[i].GoTo(ETSIDI::lanzaDado(0.0, 80.0), ETSIDI::lanzaDado(0.0, 60.0));
		}
	}
}

void Choque::rebote_lista(lista<Nave_mala>& ln, Nave& n) {
	for (int i = 0; i < ln.size(); i++) {
		if (rebote(ln[i], n)) {
			ln[i].GoTo(ETSIDI::lanzaDado(0.0, 80.0), ETSIDI::lanzaDado(0.0, 60.0));
			n.operator--();
		}
	}
}

bool Choque::choque_lista(lista<Disparo>& ld, Nave& n) {
	for (int i = 0; i < ld.size(); i++) {
		if (choque(ld[i], n)) {
			ld.erase(i); 
			n.operator--(); //le resta 1 vida a la nave //no sé por qué no funciona solo n--
			ETSIDI::play("COMPARTIDO/sonidos/golpealenemigo.wav");
			return true;
		}
	}
	return false;
}

void Choque::choque_lista(lista<Disparo>& ld, lista<Nave_mala>& ln, long int &puntos, float &x,float &y,bool &explosion,lista<Vida>& lv) {
	explosion = 0;
	for (int i = 0; i < ln.size(); i++) {
		if (choque_lista(ld, ln[i])) {
			if (ln[i].GetHP() <= 0) {
				puntos += ln[i].puntos;
				if (ETSIDI::lanzaDado(1, 10) == 10) {//probabilidad de 1 / 10 de que salga una vida
					lv.push_back(new Vida());
					lv.back()->SetPos((ln[i].GetPos()));
				}
				x = ln[i].pos.x;
				y = ln[i].pos.y;
				explosion = 1;
				ln.erase(i);
				ETSIDI::play("COMPARTIDO/sonidos/ExploNave.wav");
				break;
			}
		}
	}
}

void Choque::choque_lista(lista<Vida>& lv, Nave& n) {
	for (int i = 0; i < lv.size(); i++) {
		if (choque(lv[i], n)) {
			lv.erase(i);
			n.operator++(); //le suma 1 vida a la nave
		}
	}
}
