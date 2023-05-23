/*****************************************************************//**
 * @file   Transport.c
 * @brief  Transport structure functions
 *
 * @author Francisco
 * @date   March 2023
 *********************************************************************/

#include "Transport.h"

 /**
  * @author Francisco
  *
  * @brief Creates a new Transport in memory.
  *
  * @param Graph Transport
  * @param Transport to insert
  * @return New Transport
  * @return NULL - Error allocating memory
  */
TransportList* CreateTransport(int id, TransportType type, float batteryLife, float price, char* location) {

	//Creates a new space in memory to Allocate the Transport
	TransportList* newTransport = (TransportList*)malloc(sizeof(TransportList));

	if (newTransport == NULL) {
		free(newTransport);
		return NULL;
	}

	newTransport->transport.id = id;
	newTransport->transport.type = type;
	newTransport->transport.batteryLife = batteryLife;
	newTransport->transport.price = price;
	strcpy(newTransport->transport.location, location);
	newTransport->next = NULL;
	newTransport->previous = NULL;

	return newTransport;
}

/**
 * @author Francisco
 *
 * @brief Appends a new Transport to the head.
 *
 * @param head Transport
 * @param Transport to insert
 * @return true - Copied successfully
 * @return false - Error creating transport
 */
bool CopyTransport(TransportList** head, TransportList* source) {

	TransportList* transport = CreateTransport(source->transport.id, source->transport.type, source->transport.batteryLife, source->transport.price, source->transport.location);

	if (transport != NULL) {
		AddTransport(head, transport);
		return true;
	}
	return false;
}

/**
 * @brief Appends a new Transport to the linked list.
 *
 * @param List Head
 * @param Transport to insert
 * @return true - Added Successfully
 * @return false - Error allocating memory
 */
bool AddTransport(TransportList** head, TransportList* sourceTransport) {

	//If the list is empty, creates a new head to the list
	if (*head == NULL) {
		*head = sourceTransport;
		return true;
	}

	//Else finds the last element of the list
	TransportList* last = *head;

	while (last->next != NULL) {
		last = last->next;
	}
	last->next = sourceTransport;
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
	while (fgets(buffer, sizeof(buffer), file) != NULL) {

		if (sscanf(buffer, "%d;%d;%f;%f;%s\n",
			&current.id, &current.type, &current.batteryLife, &current.price, current.location) != 5)
			return 3;

		AddTransport(head, CreateTransport(current.id, current.type, current.batteryLife, current.price, current.location));
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

	do {
		fwrite(&(current->transport), sizeof(TransportList), 1, file);

		current = current->next;
	} while (current != NULL);

	fclose(file);
	return 1;
}

/**
 * @author Francisco
 *
 * @brief Get all the Transports from a Location
 *
 * @param List head
 * @param location
 * @return A list with all Transports in a location
 * @return NULL - the graph is empty
 */
TransportList* FindTransportsInLocation(TransportList* head, char* location) {

	TransportList* current = head;

	TransportList* transports = NULL;

	while (current != NULL) {

		if (strcmp(current->transport.location, location) == 0)
			CopyTransport(&transports, current);

		current = current->next;
	}

	return transports;
}