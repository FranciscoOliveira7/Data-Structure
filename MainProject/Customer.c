/*****************************************************************//**
 * @file   Customer.c
 * @brief  Customer structure functions
 * 
 * @author Francisco
 * @date   March 2023
 *********************************************************************/

#include <stdlib.h>
#include <stdbool.h>
#include "Customer.h"

/**
 * Appends a new Customer to the linked list.
 *
 * @param List Head
 * @param Customer to insert
 * @return true - Added Successfully
 * @return false - Error allocating memory
 */
bool AddCustomer(Customer** head, Customer sourceCustomer) {

	Customer* newCustomer = (Customer*)malloc(sizeof(Customer));

	if (newCustomer == NULL) {
		free(newCustomer);
		return false;
	}

	*newCustomer = sourceCustomer;

	//If the list is empty, creates a new head to the list
	if (*head == NULL) {
		*head = newCustomer;
		return true;
	}

	Customer* last = *head;

	while (last->next != NULL) {
		last = last->next;
	}
	last->next = newCustomer;
	return true;
}

/**
 * Finds the Customer in a linked list by its index.
 * 
 * @param List head
 * @param Customer index
 * @return Customer with the specified index
 */
Customer FindCustomer(Customer* head, int index) {

	//TODO Do something about Empty lists

	Customer* current = head;

	for (int i = 0; i < index; i++)
	{
		current = current->next;
	}

	return *current;
}