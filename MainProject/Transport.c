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
bool AddTransport(Transport** head, Transport sourceTransport) {

	Transport* newTransport = (Transport*)malloc(sizeof(Transport));

	if (newTransport == NULL) {
		free(newTransport);
		return false;
	}

	*newTransport = sourceTransport;

	//If the list is empty, creates a new head to the list
	if (*head == NULL) {
		*head = newTransport;
		return true;
	}

	Transport* last = *head;

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
Transport* GetTransport(Transport* head, int index) {

	//TODO Do something about Empty lists

	Transport* current = head;

	for (int i = 0; i < index; i++)
	{
		current = current->next;
	}

	return current;
}