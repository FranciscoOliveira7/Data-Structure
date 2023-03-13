/*****************************************************************//**
 * @file   calculator.h
 * @brief  Calculator functions signature
 * 
 * @author Francisco
 * @date   March 2023
 *********************************************************************/

#ifndef CALC
#define CALC

#include <stdbool.h>

/**
 * Adds two numbers.
 */
void addTwoNumbers(float a, float b, float* sum);

/**
 * Finds the greatest value between two.
 */
bool findGreatest(float a, float b, float* greatest);

/**
 * Swaps two values.
 */
void swapValues(float* a, float* b);

#endif