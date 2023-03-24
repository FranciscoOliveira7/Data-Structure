/*****************************************************************//**
 * @file   Customer.h
 * @brief  Customer structure and functions signature
 *
 * @author Francisco
 * @date   March 2023
 *********************************************************************/

#include "Consts.h"

#ifndef CUSTOMER_H_
#define CUSTOMER_H_

	#define CUSTOMER_TEXT_DIR "Data\\imported\\customers.txt"
	#define CUSTOMER_BIN_DIR "Data\\saved\\customers.txt"

	typedef struct {
		int id;
		char name[NAME_SIZE];
		char nif[NIF_SIZE];
		char adress[ADRESS_SIZE];
		float balance;
	} Customer;

	typedef struct CustomerList CustomerList;
	struct CustomerList {
		Customer customer;
		CustomerList* previous;
		CustomerList* next;
	};

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
	bool AddCustomer(CustomerList** head, Customer sourceCustomer);

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
	bool RemoveCustomer(CustomerList** head, CustomerList* sourceCustomer);

	/**
	 * @author Francisco
	 *
	 * @brief Wipe a Customers linked list from memory.
	 *
	 * @param List head
	 * @return true - List wiped Successfully
	 * @return false - List is already empty
	 */
	bool WipeCustomers(CustomerList** head);

	/**
	 * @author Francisco
	 *
	 * @brief Sort Customers by id.
	 *
	 * @param List head
	 * @return true - Sorted Successfully
	 * @return false - Customer doen't exist
	 */
	bool SortCustomersById(CustomerList* head);

	/**
	 * @author Francisco
	 *
	 * @brief Swaps between two Customers from linked list.
	 *
	 * @param Customer 1
	 * @param Customer 2
	 * @return true - Swaped Successfully
	 * @return false - Invalid Customers
	 */
	bool SwapCustomer(CustomerList* customer1, CustomerList* customer2);

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
	bool EditCustomer(CustomerList* customer, Customer newCustomer);

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
	CustomerList* FindCustomer(CustomerList* head, int id);

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
	CustomerList* GetCustomer(CustomerList* head, int index);

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
	int ReadCustomersFile(CustomerList** head, const char* fileName);

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
	int SaveCustomersAsFile(CustomerList* head, const char* fileName);

#endif