/*****************************************************************//**
 * @file   program.c
 * @brief  
 * 
 * @author Francisco
 * @date   March 2023
 *********************************************************************/

#include <stdio.h> //para o printf
#include "functions.h"

int main() {
	int x = 2, y = 3;
	int x2 = 2, y2 = 3;

	troca(&x, &y);

	printf("\n x: %d"
		   "\n y: %d\n\n", x, y);
	
	//sem pointers
	trocaSemPointers(x2, y2);

	printf("\n sem apontadores"
		   "\n x2: %d"
		   "\n y2: %d\n\n", x2, y2);
}