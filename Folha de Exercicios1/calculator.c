/*****************************************************************//**
 * @file   calculator.c
 * @brief  Calculator functions
 * 
 * @author Francisco
 * @date   March 2023
 *********************************************************************/

#include "calculator.h"

/**
 * @brief Adds two floats.
 * 
 * @param a
 * @param b
 * @param sum
 */
void addTwoNumbers(float a, float b, float* sum) {
	*sum = a + b;
}

/**
 * @brief Finds the greatest numbers between two floats.
 * 
 * @param a
 * @param b
 * @param greatest
 */
bool findGreatest(float a, float b, float* greatest) {
	if (a == b)	return false;

	*greatest = a > b ? a : b;
	return true;
}

void swapValues(float *a, float *b) {
	float tmp = *a;
	*a = *b;
	*b = tmp;
}