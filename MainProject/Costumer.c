/*****************************************************************//**
 * @file   Costumer.c
 * @brief  Costumer structure functions
 * 
 * @author Francisco
 * @date   March 2023
 *********************************************************************/

#include "Costumer.h"
#include <stdlib.h>

/**
 * Adds a new Costumer to the linked list.
 * 
 * @param List Head
 * @param Costumer to insert
 */
void AddCostumer(Costumer* head, Costumer sourceCostumer) {
	Costumer* newCostumer = (Costumer*)malloc(sizeof(Costumer));

	*newCostumer = sourceCostumer;
	
	Costumer* currentCostumer = head;

	while (currentCostumer->next != NULL)
	{
		currentCostumer = currentCostumer->next;
	}

	currentCostumer->next = newCostumer;

	//newCostumer->id = 2;
	//exit(newCostumer->id);

	//Costumer* current = head;
	///* finds the last member of the list */
	//while (current->next != NULL) {
	//	current = current->next;
	//}

	//current->next = (Costumer*)malloc(sizeof(Costumer));

	//*(current->next) = sourceCostumer;
}