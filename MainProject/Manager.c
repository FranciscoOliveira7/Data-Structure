/*****************************************************************//**
 * @file   Manager.c
 * @brief  Manager structure functions
 * 
 * @author Francisco
 * @date   March 2023
 *********************************************************************/

#include "Manager.h"

/**
 * Appends a new Manager to the linked list.
 *
 * @param List Head
 * @param Manager to insert
 * @return true - Added Successfully
 * @return false - Error allocating memory
 */
bool AddManager(Manager** head, Manager sourceManager) {

	Manager* newManager = (Manager*)malloc(sizeof(Manager));

	if (newManager == NULL) {
		free(newManager);
		return false;
	}

	*newManager = sourceManager;

	//If the list is empty, creates a new head to the list
	if (*head == NULL) {
		*head = newManager;
		return true;
	}

	Manager* last = *head;

	while (last->next != NULL) {
		last = last->next;
	}
	last->next = newManager;
	return true;
}

/**
 * Gets the Manager pointer in a linked list by its index.
 * 
 * @param List head
 * @param Manager index
 * @return Manager pointer with the specified index
 */
Manager* GetManager(Manager* head, int index) {

	//TODO Do something about Empty lists

	Manager* current = head;

	for (int i = 0; i < index; i++)
	{
		current = current->next;
	}

	return current;
}