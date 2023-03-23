/*****************************************************************//**
 * @file   Customer.c
 * @brief  Customer structure functions
 * 
 * @author Francisco
 * @date   March 2023
 *********************************************************************/

#include "Customer.h"

/**
 * @author Francisco
 *
 * @brief Appends a new Customer to the linked list.
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
	newCustomer->previous = NULL;
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
	last->next->previous = last;
	return true;
}

/**
 * @author Francisco
 * 
 * @brief Remove a Customer from the linked list.
 * 
 * @param List head
 * @param Customer to remove
 * @return true - Removed Successfully
 * @return false - Customer doen't exist
 */
bool RemoveCustomer(CustomerList** head, CustomerList* sourceCustomer) {

	if (sourceCustomer == NULL) return false;

	if (*head == sourceCustomer) { 
		*head = sourceCustomer->next;
		(*head)->previous = NULL;
	}
	else {
		if (sourceCustomer->previous != NULL)
			sourceCustomer->previous->next = sourceCustomer->next;

		if (sourceCustomer->next != NULL)
			sourceCustomer->next->previous = sourceCustomer->previous;
	}

	free(sourceCustomer);

	return true;
}

/**
 * @author Francisco
 * 
 * @brief Clear a Customers linked list.
 * 
 * @param List head
 * @return true - List cleared Successfully
 */
bool ClearCustomers(CustomerList** head) {

	CustomerList* current = (*head)->previous;
	*head = NULL;

	while (current != NULL)
	{
		free(current->previous);
		current = current->next;
	}

	return NULL;
}

/**
 * @author Francisco
 * 
 * @brief Sort Customers by id.
 * 
 * @param List head
 * @return true - Sorted Successfully
 * @return false - Customer doen't exist
 */
bool SortCustomersById(CustomerList* head) {
	
	if (head == NULL) return false;

	bool isSorted = false;
	CustomerList* current = NULL;

	while (!isSorted)
	{
		isSorted = true;
		current = head;
		while (current->next != NULL)
		{
			if (current->customer.id > current->next->customer.id) {
				SwapCustomer(current, current->next);
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
 * @brief Swaps between two Customers from linked list.
 * 
 * @param Customer 1
 * @param Customer 2
 */
void SwapCustomer(CustomerList* customer1, CustomerList* customer2) {
	
	Customer aux = customer1->customer;
	customer1->customer = customer2->customer;
	customer2->customer = aux;
}

/**
 * @author Francisco
 *
 * @brief Edits a Customer from the linked list.
 *
 * @param Customer to edit
 * @param New Customer
 * @return true - Edited Successfully
 * @return false - Customer doen't exist
 */
bool EditCustomer(CustomerList* customer, Customer newCustomer) {

	if (customer == NULL) return false;

	customer->customer = newCustomer;

	return true;
}

/**
 * @author Francisco
 * 
 * @brief Finds customer by its id.
 * 
 * @param List Head
 * @param Customer id
 * @return Customer pointer with the specified id
 * @return NULL if not found
 */
CustomerList* FindCustomer(CustomerList* head, int id) {

	if (head == NULL) return NULL;

	CustomerList* current = head;

	while (current != NULL)
	{
		if (current->customer.id == id) return current;
		current = current->next;
	}

	return NULL;
}

/**
 * @author Francisco
 *
 * @brief Gets the Customer pointer in a linked list by its index.
 * 
 * @param List head
 * @param Customer index
 * @return Customer pointer with the specified index
 * @return NULL if not found
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
 * @brief Reads all the customers from a file into a list.
 *
 * @param List Head
 * @param File directory
 * @return 1 - Readed Successfully
 * @return 2 - Error opening file
 * @return 3 - Error on sscanf
 */
int ReadCustomersFile(CustomerList** head, const char* fileName) {

	Customer current = { 0 };

	FILE* file;

	fopen_s(&file, fileName, "r");

	// Return 2 if the file wasn't open successfully
	if (file == NULL) return 2;

	char buffer[256];
	while (fgets(buffer, sizeof(buffer), file) != NULL)
	{
		if (sscanf(buffer, "%d;%[^;];%[^;];%[^;];%f\n",
			&current.id, current.name, current.nif, current.adress, &current.balance) != 5)
			return 3;

		AddCustomer(head, current);
	}

	fclose(file);
	return 1;
}

/**
 * @author Francisco
 *
 * @brief Saves all the customers from a list into a file.
 *
 * @param List Head
 * @param File directory
 * @return 1 - Saved Successfully
 * @return 2 - Error opening file
 * @return 3 - The list is empty
 */
int SaveCustomersAsFile(CustomerList* head, const char* fileName) {

	if (head == NULL) return 3;

	CustomerList* current = head;

	FILE* file;

	fopen_s(&file, fileName, "wb");

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