/*****************************************************************//**
 * @file   Rent.h
 * @brief  Rent structure and functions signature
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
	} Rent;

	typedef struct RentList RentList;
	struct RentList {
		Rent customer;
		RentList* previous;
		RentList* next;
	};

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
	bool AddRent(RentList** head, Rent sourceRent);

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
	bool RemoveRent(RentList** head, RentList* sourceRent);

	/**
	 * @author Francisco
	 *
	 * @brief Wipe a Rents linked list from memory.
	 *
	 * @param List head
	 * @return true - List wiped Successfully
	 * @return false - List is already empty
	 */
	bool WipeRents(RentList** head);

	/**
	 * @author Francisco
	 *
	 * @brief Sort Rents by id.
	 *
	 * @param List head
	 * @return true - Sorted Successfully
	 * @return false - Rent doen't exist
	 */
	bool SortRentsById(RentList* head);

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
	bool SwapRent(RentList* customer1, RentList* customer2);

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
	bool EditRent(RentList* customer, Rent newRent);

	/**
	 * @author Francisco
	 *
	 * @brief Finds customer by its id.
	 *
	 * @param List Head
	 * @param Rent id
	 * @return Rent pointer with the specified id
	 * @return NULL if not found
	 */
	RentList* FindRent(RentList* head, int id);

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
	RentList* GetRent(RentList* head, int index);

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
	int ReadRentsFile(RentList** head, const char* fileName);

	/**
	 * @author Francisco
	 *
	 * @brief Saves all the customers from a list into a file.
	 *
	 * @param List Head
	 * @param File directory
	 * @return 1 - Saved Successfully
	 * @return 2 - Error opening file
	 * @return 3 - The graph is empty
	 */
	int SaveRentsAsFile(RentList* head, const char* fileName);

#endif