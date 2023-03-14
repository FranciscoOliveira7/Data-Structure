/*****************************************************************//**
 * @file   Customer.c
 * @brief  Customer structure functions
 * 
 * @author Francisco
 * @date   March 2023
 *********************************************************************/

#include "Customer.h"
#include <stdlib.h>

/**
 * Adds a new Costumer to the linked list.
 * 
 * @param List Head
 * @param Costumer to insert
 */
void AddCustomer(Customer** head, Customer sourceCostumer) {

	Customer* newCostumer = (Customer*)malloc(sizeof(Customer));

	newCostumer = &sourceCostumer;

	//If the list is empty, creates a new head to the list
	if (*head == NULL) {
		*head = &sourceCostumer;
		return;
	}

	Customer* last = *head;

	while (last->next != NULL) {
		last = last->next;
	}
	last->next = &sourceCostumer;
}

Customer FindCustomer(Customer* head, int index) {

	//TODO Do something about Empty lists

	Customer* current = head;

	for (int i = 0; i < index; i++)
	{
		current = current->next;
	}

	return *current;
}