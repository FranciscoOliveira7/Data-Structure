/*****************************************************************//**
 * @file   Customer.c
 * @brief  Customer structure functions
 * 
 * @author Francisco
 * @date   March 2023
 *********************************************************************/

#include "Customer.h"

/**
 * Appends a new Customer to the linked list.
 *
 * @param List Head
 * @param Customer to insert
 * @return true - Added Successfully
 * @return false - Error allocating memory
 */
bool AddCustomer(CustomerList** head, Customer sourceCustomer) {

	//Creates a new space in memory to Allocate the customer
	CustomerList* newCustomer = (CustomerList*)malloc(sizeof(CustomerList));

	if (newCustomer == NULL) {
		free(newCustomer);
		return false;
	}

	newCustomer->customer = sourceCustomer;
	newCustomer->next = NULL;

	//If the list is empty, creates a new head to the list
	if (*head == NULL) {
		*head = newCustomer;
		return true;
	}

	//Else finds the last element of the list
	CustomerList* last = *head;

	while (last->next != NULL) {
		last = last->next;
	}
	last->next = newCustomer;
	return true;
}

/**
 * Gets the Customer pointer in a linked list by its index.
 * 
 * @param List head
 * @param Customer index
 * @return Customer pointer with the specified index
 * @return NULL if the list is empty
 */
CustomerList* GetCustomer(CustomerList* head, int index) {

	//Checks if the list is empty
	if (head == NULL) return NULL;

	CustomerList* current = head;

	for (int i = 0; i < index; i++)
	{
		current = current->next;
	}

	return current;
}

/**
 * @author Francisco
 *
 * Reads all the customers from a file into a list.
 *
 * @param List Head
 * @return 1 - Readed Successfully
 * @return 2 - Error opening file
 * @return 3 - Error on sscanf
 */
int ReadCostumersFile(CustomerList** head) {

	Customer current = { 0 };

	FILE* file;

	fopen_s(&file, CUSTOMER_TEXT_DIR, "r");

	// Return 2 if the file wasn't open successfully
	if (file == NULL) return 2;

	char buffer[256];
	while (fgets(buffer, sizeof(buffer), file) != NULL)
	{
		if (sscanf(buffer, "%[^;];%[^;];%[^;];%f\n",
			current.name, current.nif, current.adress, &current.balance) != 4)
			return 3;

		AddCustomer(head, current);
	}

	fclose(file);
	return 1;
}

/**
 * @author Francisco
 *
 * Saves all the customers from a list into a file.
 *
 * @param List Head
 * @return 1 - Saved Successfully
 * @return 2 - Error opening file
 * @return 3 - The list is empty
 */
int SaveCustomersAsFile(CustomerList* head) {

	if (head == NULL) return 3;

	CustomerList* current = head;

	FILE* file;

	fopen_s(&file, CUSTOMER_BIN_DIR, "wb");

	// Return 2 if the file wasn't open successfully
	if (file == NULL) return 2;

	do
	{
		fwrite(&(current->customer), sizeof(CustomerList), 1, file);

		current = current->next;
	} while (current != NULL);

	fclose(file);
	return 1;
}