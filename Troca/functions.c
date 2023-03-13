
#include "functions.h"

/*
 Troca os valores de dois inteiros
 atrav�s de pointers
*/

void troca(int* x, int* y) {
	int tmp; //vari�vel temporaria

	tmp = *x;
	*x = *y;
	*y = tmp;
}

/*
 Troca os valores de dois inteiros
 sem usar pointers
*/
void trocaSemPointers(int x, int y) {
	int tmp;

	tmp = x;
	x = y;
	y = tmp;
}