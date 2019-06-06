#pragma once

class Teclado {
	bool state[256]; //true = pulsada, false = no pulsada
public:
	Teclado() {for (int i = 0; i < 256; i++) state[i] = false;}

	void press(unsigned char c);
	void unpress(unsigned char c);
	bool verify(unsigned char c);
	void inicializa();
};
