/*****************************************************************//**
 * @file   Rent.c
 * @brief  Rent structure functions
 *
 * @author Francisco
 * @date   March 2023
 *********************************************************************/

#include "Rent.h"

 /**
  * @author Francisco
  *
  * @brief Appends a new Rent to the linked list.
  *
  * @param List Head
  * @param Rent to insert
  * @return true - Added Successfully
  * @return false - Error allocating memory
  */
bool AddRent(RentList** head, Rent sourceRent) {

	//Creates a new space in memory to Allocate the rent
	RentList* newRent = (RentList*)malloc(sizeof(RentList));

	if (newRent == NULL) {
		free(newRent);
		return false;
	}

	newRent->rent = sourceRent;
	newRent->previous = NULL;
	newRent->next = NULL;

	//If the list is empty, creates a new head to the list
	if (*head == NULL) {
		*head = newRent;
		return true;
	}

	//Else finds the last element of the list
	RentList* last = *head;

	while (last->next != NULL) {
		last = last->next;
	}
	last->next = newRent;
	last->next->previous = last;
	return true;
}

/**
 * @author Francisco
 *
 * @brief Remove a Rent from the linked list.
 *
 * @param List head
 * @param Rent to remove
 * @return true - Removed Successfully
 * @return false - Rent doen't exist
 */
bool RemoveRent(RentList** head, RentList* sourceRent) {

	if (sourceRent == NULL) return false;

	// Points head to the next rent if removed
	if (*head == sourceRent) {
		*head = sourceRent->next;

		// sets previous pointer to NULL if there is a second rent
		if (*head != NULL) (*head)->previous = NULL;
	}
	else {
		// Updates previous rent next pointer
		sourceRent->previous->next = sourceRent->next;

		// Updates next rent previous pointer if it exists
		if (sourceRent->next != NULL)
			sourceRent->next->previous = sourceRent->previous;
	}

	free(sourceRent);

	return true;
}

/**
 * @author Francisco
 *
 * @brief Wipe a Rents linked list from memory.
 *
 * @param List head
 * @return true - List wiped Successfully
 * @return false - List is already empty
 */
bool WipeRents(RentList** head) {

	if (*head == NULL) return false;

	RentList* current = *head;
	RentList* previous = NULL;

	*head = NULL;

	while (current != NULL)
	{
		previous = current;
		current = current->next;
		free(previous);
	}

	return true;
}

/**
 * @author Francisco
 *
 * @brief Sort Rents by id.
 *
 * @param List head
 * @return true - Sorted Successfully
 * @return false - The list is empty
 */
bool SortRentsById(RentList* head) {

	if (head == NULL) return false;

	bool isSorted = false;
	RentList* current = NULL;

	while (!isSorted)
	{
		isSorted = true;
		current = head;
		while (current->next != NULL)
		{
			if (current->rent.id > current->next->rent.id) {
				SwapRent(current, current->next);
				isSorted = false;
			}
			current = current->next;
		}
	}
	return true;
}

/**
 * @author Francisco
 *
 * @brief Swaps between two Rents from linked list.
 *
 * @param Rent 1
 * @param Rent 2
 * @return true - Swaped Successfully
 * @return false - Invalid Rents
 */
bool SwapRent(RentList* rent1, RentList* rent2) {

	if (rent1 && rent2)
	{
		Rent aux = rent1->rent;
		rent1->rent = rent2->rent;
		rent2->rent = aux;
		return true;
	}
	return false;
}

/**
 * @author Francisco
 *
 * @brief Edits a Rent from the linked list.
 *
 * @param Rent to edit
 * @param New Rent
 * @return true - Edited Successfully
 * @return false - Rent doen't exist
 */
bool EditRent(RentList* rent, Rent newRent) {

	if (rent == NULL) return false;

	rent->rent = newRent;

	return true;
}

/**
 * @author Francisco
 *
 * @brief Finds rent by its id.
 *
 * @param List Head
 * @param Rent id
 * @return Rent pointer with the specified id
 * @return NULL if not found
 */
RentList* FindRent(RentList* head, int id) {

	if (head == NULL) return NULL;

	RentList* current = head;

	while (current != NULL)
	{
		if (current->rent.id == id) return current;
		current = current->next;
	}

	return NULL;
}

/**
 * @author Francisco
 *
 * @brief Gets the Rent pointer in a linked list by its index.
 *
 * @param List head
 * @param Rent index
 * @return Rent pointer with the specified index
 * @return NULL if not found
 */
RentList* GetRent(RentList* head, int index) {

	//Checks if the list is empty
	if (head == NULL) return NULL;

	RentList* current = head;

	for (int i = 0; i < index; i++)
	{
		current = current->next;
	}

	return current;
}

/**
 * @author Francisco
 *
 * @brief Reads all the rents from a file into a list.
 *
 * @param List Head
 * @param File directory
 * @return 1 - Readed Successfully
 * @return 2 - Error opening file
 * @return 3 - Error on sscanf
 */
int ReadRentsFile(RentList** head, const char* fileName) {

	Rent current = { 0 };

	FILE* file;

	fopen_s(&file, fileName, "r");

	// Return 2 if the file wasn't open successfully
	if (file == NULL) return 2;

	char buffer[256];
	while (fgets(buffer, sizeof(buffer), file) != NULL)
	{
		if (sscanf(buffer, "%d;%d;%d;%f\n",
			&current.id, &current.customer, &current.transport, &current.price) != 4)
			return 3;

		AddRent(head, current);
	}

	fclose(file);
	return 1;
}

/**
 * @author Francisco
 *
 * @brief Saves all the rents from a list into a file.
 *
 * @param List Head
 * @param File directory
 * @return 1 - Saved Successfully
 * @return 2 - Error opening file
 * @return 3 - The list is empty
 */
int SaveRentsAsFile(RentList* head, const char* fileName) {

	if (head == NULL) return 3;

	RentList* current = head;

	FILE* file;

	fopen_s(&file, fileName, "wb");

	// Return 2 if the file wasn't open successfully
	if (file == NULL) return 2;

	do {
		fwrite(&current->rent, sizeof(RentList), 1, file);

		current = current->next;
	} while (current != NULL);

	fclose(file);
	return 1;
}