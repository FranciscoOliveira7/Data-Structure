/*****************************************************************//**
 * @file   Customer.h
 * @brief  Customer structure and functions signature
 *
 * @author Francisco
 * @date   March 2023
 *********************************************************************/

#pragma warning(disable : 4996)

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#ifndef CUSTOMER_H_
#define CUSTOMER_H_

	#define CUSTOMER_TEXT_DIR "Data\\ReadOnly\\customers.txt"
	#define CUSTOMER_BIN_DIR "Data\\Saved\\customers.txt"

	#define NAME_SIZE 40
	#define NIF_SIZE 15
	#define ADRESS_SIZE 80

	typedef struct {
		char name[NAME_SIZE];
		char nif[NIF_SIZE];
		char adress[ADRESS_SIZE];
		float balance;
	} Customer;

	typedef struct CustomerList CustomerList;
	struct CustomerList {
		Customer customer;
		CustomerList* next;
	};

	/**
	 * Appends a new Customer to the linked list.
	 *
	 * @param List Head
	 * @param Customer to insert
	 * @return true - Added Successfully
	 * @return false - Error allocating memory
	 */
	bool AddCustomer(CustomerList** head, Customer sourceCustomer);

	/**
	 * Gets the Customer pointer in a linked list by its index.
	 *
	 * @param List head
	 * @param Customer index
	 * @return Customer pointer with the specified index
	 * @return NULL if the list is empty
	 */
	CustomerList* GetCustomer(CustomerList* head, int index);

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
	int ReadCostumersFile(CustomerList** head);

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
	int SaveCustomersAsFile(CustomerList* head);

#endif