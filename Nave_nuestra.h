#pragma once
#include "Nave.h"

class Nave_nuestra : public Nave {
protected:
	Vector2D XYpoint; //el punto al que apunta
public:
	Nave_nuestra();
	virtual ~Nave_nuestra() { ; }

	void Tecla(Teclado &t);
	void SetXYpoint(Vector2D XY) { 
		XYpoint = XY; 
	};
	Vector2D GetXYpoint() {
		return XYpoint;
	}
};