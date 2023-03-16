/*****************************************************************//**
 * @file   Transport.c
 * @brief  Transport structure functions
 *
 * @author Francisco
 * @date   March 2023
 *********************************************************************/

#include "Transport.h"

 /**
  * Appends a new Transport to the linked list.
  *
  * @param List Head
  * @param Transport to insert
  * @return true - Added Successfully
  * @return false - Error allocating memory
  */
bool AddTransport(TransportList** head, Transport sourceTransport) {

	//Creates a new space in memory to Allocate the customer
	TransportList* newTransport = (TransportList*)malloc(sizeof(Transport));

	if (newTransport == NULL) {
		free(newTransport);
		return false;
	}

	newTransport->transport = sourceTransport;
	newTransport->next = NULL;

	//If the list is empty, creates a new head to the list
	if (*head == NULL) {
		*head = newTransport;
		return true;
	}

	//Else finds the last element of the list
	TransportList* last = *head;

	while (last->next != NULL) {
		last = last->next;
	}
	last->next = newTransport;
	return true;
}

/**
 * Gets the Transport pointer in a linked list by its index.
 *
 * @param List head
 * @param Transport index
 * @return Transport pointer with the specified index
 */
TransportList* GetTransport(TransportList* head, int index) {

	//TODO Do something about Empty lists

	TransportList* current = head;

	for (int i = 0; i < index; i++)
	{
		current = current->next;
	}

	return current;
}