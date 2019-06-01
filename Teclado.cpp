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