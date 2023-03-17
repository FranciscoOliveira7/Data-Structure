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
	return true;
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
int ReadManagersFile(ManagerList** head, char* fileName) {

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
int SaveManagersAsFile(ManagerList* head, char* fileName) {

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