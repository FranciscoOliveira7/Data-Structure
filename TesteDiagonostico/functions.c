#include "functions.h"

float averageDistance(float distances[], int size) {
	float sum = 0;

	for (int i = 0; i < size; i++) {
		sum += distances[i];
	}

	return sum;
}