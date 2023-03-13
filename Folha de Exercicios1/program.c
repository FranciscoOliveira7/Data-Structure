/*****************************************************************//**
 * @file   program.c
 * @brief  Calls all the other functions
 * 
 * @author Francisco
 * @date   March 2023
 *********************************************************************/

#include "calculator.h"

int main() {
	float x = 3, y = 5, z;
	float array[] = { 1, 5.4, 74, 29.5, 2 };
	const int arraySize = sizeof(array) / sizeof(float);

	displayArray(array, arraySize);

	return 0;
}