/*****************************************************************//**
 * @file   Transport.c
 * @brief  Transport structure functions
 *
 * @author Francisco
 * @date   March 2023
 *********************************************************************/

#include "Transport.h"

/**
 * @brief Appends a new Transport to the linked list.
 *
 * @param List Head
 * @param Transport to insert
 * @return true - Added Successfully
 * @return false - Error allocating memory
 */
bool AddTransport(TransportList** head, Transport sourceTransport) {

	//Creates a new space in memory to Allocate the transport
	TransportList* newTransport = (TransportList*)malloc(sizeof(TransportList));

	if (newTransport == NULL) {
		free(newTransport);
		return false;
	}

	newTransport->transport = sourceTransport;
	newTransport->previous = NULL;
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
	last->next->previous = last;
	return true;
}

/**
 * @author Francisco
 *
 * @brief Remove a Transport from the linked list.
 *
 * @param List head
 * @param Transport to remove
 * @return true - Removed Successfully
 * @return false - Transport doen't exist
 */
bool RemoveTransport(TransportList** head, TransportList* sourceTransport) {

	if (sourceTransport == NULL) return false;

	// Points head to the next transport if removed
	if (*head == sourceTransport) {
		*head = sourceTransport->next;

		// sets previous pointer to NULL if there is a second transport
		if (*head != NULL) (*head)->previous = NULL;
	}
	else {
		// Updates previous transport next pointer
		sourceTransport->previous->next = sourceTransport->next;

		// Updates next transport previous pointer if it exists
		if (sourceTransport->next != NULL)
			sourceTransport->next->previous = sourceTransport->previous;
	}

	free(sourceTransport);

	return true;
}

/**
 * @author Francisco
 *
 * @brief Wipe a Transports linked list from memory.
 *
 * @param List head
 * @return true - List wiped Successfully
 * @return false - List is already empty
 */
bool WipeTransports(TransportList** head) {

	if (head == NULL) return false;

	TransportList* current = *head;
	TransportList* previous = NULL;

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
 * @brief Sort Transports by id.
 *
 * @param List head
 * @return true - Sorted Successfully
 * @return false - Transport doen't exist
 */
bool SortTransportsById(TransportList* head) {

	if (head == NULL) return false;

	bool isSorted = false;
	TransportList* current = NULL;

	while (!isSorted)
	{
		isSorted = true;
		current = head;
		while (current->next != NULL)
		{
			if (current->transport.id > current->next->transport.id) {
				SwapTransport(current, current->next);
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
 * @brief Sort Transports by battery life.
 *
 * @param List head
 * @return true - Sorted Successfully
 * @return false - Transport doen't exist
 */
bool SortTransportsByBatteryLife(TransportList* head) {

	if (head == NULL) return false;

	bool isSorted = false;
	TransportList* current = NULL;

	while (!isSorted)
	{
		isSorted = true;
		current = head;
		while (current->next != NULL)
		{
			if (current->transport.batteryLife < current->next->transport.batteryLife) {
				SwapTransport(current, current->next);
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
 * @brief Swaps between two Transports from linked list.
 *
 * @param Transport 1
 * @param Transport 2
 */
void SwapTransport(TransportList* transport1, TransportList* transport2) {

	Transport aux = transport1->transport;
	transport1->transport = transport2->transport;
	transport2->transport = aux;
}

/**
 * @author Francisco
 *
 * @brief Edits a Transport from the linked list.
 *
 * @param Transport to edit
 * @param New Transport
 * @return true - Edited Successfully
 * @return false - Transport doen't exist
 */
bool EditTransport(TransportList* transport, Transport newTransport) {

	if (transport == NULL) return false;

	transport->transport = newTransport;

	return true;
}

/**
 * @author Francisco
 *
 * @brief Finds transport by its id.
 *
 * @param List Head
 * @param Transport id
 * @return Transport pointer with the specified id
 * @return NULL if not found
 */
TransportList* FindTransport(TransportList* head, int id) {

	if (head == NULL) return NULL;

	TransportList* current = head;

	while (current != NULL)
	{
		if (current->transport.id == id) return current;
		current = current->next;
	}

	return NULL;
}

/**
 * @author Francisco
 *
 * @brief Gets the Transport pointer in a linked list by its index.
 *
 * @param List head
 * @param Transport index
 * @return Transport pointer with the specified index
 * @return NULL if not found
 */
TransportList* GetTransport(TransportList* head, int index) {

	//Checks if the list is empty
	if (head == NULL) return NULL;

	TransportList* current = head;

	for (int i = 0; i < index; i++)
	{
		current = current->next;
	}

	return current;
}

/**
 * @author Francisco
 *
 * @brief Reads all the transports from a file into a list.
 *
 * @param List Head
 * @param File directory
 * @return 1 - Readed Successfully
 * @return 2 - Error opening file
 * @return 3 - Error on sscanf
 */
int ReadTransportsFile(TransportList** head, const char* fileName) {

	Transport current = { 0 };

	FILE* file;

	fopen_s(&file, fileName, "r");

	// Return 2 if the file wasn't open successfully
	if (file == NULL) return 2;

	char buffer[256];
	while (fgets(buffer, sizeof(buffer), file) != NULL)
	{
		if (sscanf(buffer, "%d;%d;%f;%f;%[^;];%d\n",
			&current.id, &current.type, &current.batteryLife, &current.price, current.location, &current.renter) != 6)
			return 3;

		AddTransport(head, current);
	}

	fclose(file);
	return 1;
}

/**
 * @author Francisco
 *
 * @brief Saves all the transports from a list into a file.
 *
 * @param List Head
 * @param File directory
 * @return 1 - Saved Successfully
 * @return 2 - Error opening file
 * @return 3 - The list is empty
 */
int SaveTransportsAsFile(TransportList* head, const char* fileName) {

	if (head == NULL) return 3;

	TransportList* current = head;

	FILE* file;

	fopen_s(&file, fileName, "wb");

	// Return 2 if the file wasn't open successfully
	if (file == NULL) return 2;

	do
	{
		fwrite(&(current->transport), sizeof(TransportList), 1, file);

		current = current->next;
	} while (current != NULL);

	fclose(file);
	return 1;
}