/*****************************************************************//**
 * @file   ui.c
 * @brief  All terminal I/O functions
 *
 * @author Francisco
 * @date   March 2023
 *********************************************************************/

#include "ui.h"

/**
 * Displays array values on terminal.
 * 
 * @param array
 * @param size
 */
void displayArray(float *array, int size) {
	printf("\n Array: %f", *array);

	for (int i = 1; i < size; i++) {
		printf(", %f", *(array+i));
	}
	printf("\n\n");
}