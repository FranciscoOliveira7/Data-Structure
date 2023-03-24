/*****************************************************************//**
 * @file   Manager.c
 * @brief  Manager structure functions
 *
 * @author Francisco
 * @date   March 2023
 *********************************************************************/

#include "Manager.h"

/**
 * @author Francisco
 *
 * @brief Appends a new Manager to the linked list.
 *
 * @param List Head
 * @param Manager to insert
 * @return true - Added Successfully
 * @return false - Error allocating memory
 */
bool AddManager(ManagerList** head, Manager sourceManager) {

	//Creates a new space in memory to Allocate the manager
	ManagerList* newManager = (ManagerList*)malloc(sizeof(ManagerList));

	if (newManager == NULL) {
		free(newManager);
		return false;
	}

	newManager->manager = sourceManager;
	newManager->previous = NULL;
	newManager->next = NULL;

	//If the list is empty, creates a new head to the list
	if (*head == NULL) {
		*head = newManager;
		return true;
	}

	//Else finds the last element of the list
	ManagerList* last = *head;

	while (last->next != NULL) {
		last = last->next;
	}
	last->next = newManager;
	last->next->previous = last;
	return true;
}

/**
 * @author Francisco
 *
 * @brief Remove a Manager from the linked list.
 *
 * @param List head
 * @param Manager to remove
 * @return true - Removed Successfully
 * @return false - Manager doen't exist
 */
bool RemoveManager(ManagerList** head, ManagerList* sourceManager) {

	if (sourceManager == NULL) return false;

	// Points head to the next manager if removed
	if (*head == sourceManager) {
		*head = sourceManager->next;

		// sets previous pointer to NULL if there is a second manager
		if (*head != NULL) (*head)->previous = NULL;
	}
	else {
		// Updates previous manager next pointer
		sourceManager->previous->next = sourceManager->next;

		// Updates next manager previous pointer if it exists
		if (sourceManager->next != NULL)
			sourceManager->next->previous = sourceManager->previous;
	}

	free(sourceManager);

	return true;
}

/**
 * @author Francisco
 *
 * @brief Wipe a Managers linked list from memory.
 *
 * @param List head
 * @return true - List wiped Successfully
 * @return false - List is already empty
 */
bool WipeManagers(ManagerList** head) {

	if (head == NULL) return false;

	ManagerList* current = *head;
	ManagerList* previous = NULL;

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
 * @brief Sort Managers by id.
 *
 * @param List head
 * @return true - Sorted Successfully
 * @return false - Manager doen't exist
 */
bool SortManagersById(ManagerList* head) {

	if (head == NULL) return false;

	bool isSorted = false;
	ManagerList* current = NULL;

	while (!isSorted)
	{
		isSorted = true;
		current = head;
		while (current->next != NULL)
		{
			if (current->manager.id > current->next->manager.id) {
				SwapManager(current, current->next);
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
 * @brief Swaps between two Managers from linked list.
 *
 * @param Manager 1
 * @param Manager 2
 */
void SwapManager(ManagerList* manager1, ManagerList* manager2) {

	Manager aux = manager1->manager;
	manager1->manager = manager2->manager;
	manager2->manager = aux;
}

/**
 * @author Francisco
 *
 * @brief Edits a Manager from the linked list.
 *
 * @param Manager to edit
 * @param New Manager
 * @return true - Edited Successfully
 * @return false - Manager doen't exist
 */
bool EditManager(ManagerList* manager, Manager newManager) {

	if (manager == NULL) return false;

	manager->manager = newManager;

	return true;
}

/**
 * @author Francisco
 *
 * @brief Finds manager by its id.
 *
 * @param List Head
 * @param Manager id
 * @return Manager pointer with the specified id
 * @return NULL if not found
 */
ManagerList* FindManager(ManagerList* head, int id) {

	if (head == NULL) return NULL;

	ManagerList* current = head;

	while (current != NULL)
	{
		if (current->manager.id == id) return current;
		current = current->next;
	}

	return NULL;
}

/**
 * @author Francisco
 *
 * @brief Gets the Manager pointer in a linked list by its index.
 *
 * @param List head
 * @param Manager index
 * @return Manager pointer with the specified index
 * @return NULL if the index is invalid
 */
ManagerList* GetManager(ManagerList* head, int index) {

	//Checks if the list is empty
	if (head == NULL) return NULL;

	ManagerList* current = head;

	for (int i = 0; i < index; i++)
	{
		current = current->next;
	}

	return current;
}

/**
 * @author Francisco
 *
 * @brief Reads all the managers from a file into a list.
 *
 * @param List Head
 * @param File directory
 * @return 1 - Readed Successfully
 * @return 2 - Error opening file
 * @return 3 - Error on sscanf
 */
int ReadManagersFile(ManagerList** head, const char* fileName) {

	Manager current = { 0 };

	FILE* file;

	fopen_s(&file, fileName, "r");

	// Return 2 if the file wasn't open successfully
	if (file == NULL) return 2;

	char buffer[256];
	while (fgets(buffer, sizeof(buffer), file) != NULL)
	{
		if (sscanf(buffer, "%d;%[^;];%[^;];%s\n",
			&current.id, current.name, current.email, current.password) != 4)
			return 3;

		AddManager(head, current);
	}

	fclose(file);
	return 1;
}

/**
 * @author Francisco
 *
 * @brief Saves all the managers from a list into a file.
 *
 * @param List Head
 * @param File directory
 * @return 1 - Saved Successfully
 * @return 2 - Error opening file
 * @return 3 - The list is empty
 */
int SaveManagersAsFile(ManagerList* head, const char* fileName) {

	if (head == NULL) return 3;

	ManagerList* current = head;

	FILE* file;

	fopen_s(&file, fileName, "wb");

	// Return 2 if the file wasn't open successfully
	if (file == NULL) return 2;

	do
	{
		fwrite(&(current->manager), sizeof(ManagerList), 1, file);

		current = current->next;
	} while (current != NULL);

	fclose(file);
	return 1;
}