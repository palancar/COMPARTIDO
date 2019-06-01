#include <iostream>
#include "Choque.h"


bool dentro(Vector2D pos, Borde& b) {
	Vector2D lim1 = b.GetLim1();
	Vector2D lim2 = b.GetLim2();
	if (pos.x < lim1.x) return false;
	if (pos.x > lim2.x) return false;
	if (pos.y < lim1.y) return false;
	if (pos.y > lim2.y) return false;
	return true;
}

/*CHOQUES UNITARIOS*/

bool choque(Objeto& o, Borde& b) {
	return !dentro(o.GetPos(), b);
}

bool choque_nave(Nave &n, Borde &b) {
	bool ret_val = false;
	Vector2D lim1 = b.GetLim1();
	Vector2D lim2 = b.GetLim2();
	Vector2D pos = n.GetPos();
	float r = n.GetRadio();
	if (pos.x - r/2 < lim1.x) {
		n.SetPos(lim1.x + r/2, pos.y);
		n.SetVel(0, n.GetVel().y);
		ret_val = true;
	}
	else if (pos.x + r / 2 > lim2.x) {
		n.SetPos(lim2.x - r / 2, pos.y);
		ret_val = true;
		n.SetVel(0, n.GetVel().y);
	}
	if (pos.y - r / 2 < lim1.y) {
		n.SetPos(pos.x, lim1.y + r / 2);
		ret_val = true;
		n.SetVel(n.GetVel().x, 0);
	}
	else if (pos.y + r / 2 > lim2.y) {
		n.SetPos(pos.x, lim2.y - r / 2);
		ret_val = true;
		n.SetVel(n.GetVel().x, 0);
	}
	return ret_val;
}
/*CHOQUES DE LISTAS*/

bool choque_disparos(lista_disparos& ld, Borde& b) { 
	bool ret_val = false;
	for (int i = 0; i < ld.size(); i++) {
		if (choque(*ld[i], b)) {
			ld.erase(i);
			ret_val = true;
		}
	}
	return ret_val;
}