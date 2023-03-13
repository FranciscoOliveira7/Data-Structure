/*****************************************************************//**
 * @file   Program.c
 * @brief  Calls other functions
 * 
 * @author Francisco
 * @date   March 2023
 *********************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Costumer.h"

int main() {
	float numero2 = 3;

	Costumer c1 = { 1, "dwdw", "dwd", "dwdw", 2, NULL };
	Costumer c2 = { 2, "dydfy", "breb", "sdf", 69, NULL };

	Costumer* costumers = (Costumer*)malloc(sizeof(Costumer));
	*costumers = c2;

	AddCostumer(costumers, c1);

	costumers->balance = numero2;

	printf("Balance: %.2f", costumers->balance);
}