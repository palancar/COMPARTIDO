#include "Teclado.h"

void Teclado::press(unsigned char c) {
	state[c] = true;
}
void Teclado::unpress(unsigned char c) {
	state[c] = false;
}
bool Teclado::verify(unsigned char c) {
	return state[c];
}

void Teclado::inicializa() {
	for (int i = 0; i < 256; i++)
		state[i] = false;
}