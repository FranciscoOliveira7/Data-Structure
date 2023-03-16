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
bool AddCustomer(Customer** head, Customer sourceCustomer) {

	//Creates a new space in memory to Allocate the customer
	Customer* newCustomer = (Customer*)malloc(sizeof(Customer));

	if (newCustomer == NULL) {
		free(newCustomer);
		return false;
	}

	*newCustomer = sourceCustomer;

	//If the list is empty, creates a new head to the list
	if (*head == NULL) {
		*head = newCustomer;
		return true;
	}

	//Else finds the last element of the list
	Customer* last = *head;

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
 */
Customer* GetCustomer(Customer* head, int index) {

	//TODO Do something about Empty lists

	Customer* current = head;

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
 * @return 2 - Error on sscanf_s
 * @return 3 - Error opening file
 */
int ReadCostumerFiles(Customer** head) {
	Customer current = { 0 };

	FILE* file;

	if (fopen_s(&file, CUSTOMER_DIR, "r"))
	{
		return 3;
	}

	char buffer[256];
	while (fgets(buffer, sizeof(buffer), file) != NULL)
	{
		if (sscanf_s(buffer, "%[^;];%[^;];%[^;];%f\n",
			&current.name, &current.nif, &current.adress, &current.balance) == 2)

			return 2;

		current.next = NULL;
		AddCustomer(head, current);
	}

	fclose(file);
	return 1;
}