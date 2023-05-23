/*****************************************************************//**
 * @file   Rent.h
 * @brief  Rent structure and functions signature
 *
 * @author Francisco
 * @date   March 2023
 *********************************************************************/

#include "Consts.h"

#ifndef RENT_H_
#define RENT_H_

	#include "Transport.h"
	#include "Path.h"
	#include "Graph.h"
	#include "Customer.h"
	#include "Transport.h"

	#define RENT_TEXT_DIR "Data\\imported\\rents.txt"
	#define RENT_BIN_DIR "Data\\saved\\rents.txt"

	typedef struct {
		int id;
		int customer;
		int transport;
		float price;
		float distance; // Distance in km
		time_t start;   // Time in seconds from: 1 jan 1900 00:00
		int duration;   // Duration in seconds
	} Rent;

	typedef struct RentList RentList;
	struct RentList {
		Rent rent;
		RentList* previous;
		RentList* next;
	};

	/**
	 * @author Francisco
	 *
	 * @brief Registers a new Rent in the current time
	 *
	 * @param rent id
	 * @param customer id
	 * @param transport id
	 * @param source location name
	 * @param destination location name
	 * @return New Rent
	 * @return NULL - Invalid info
	 */
	Rent* RegisterRent(int id, Customer* customer, Transport* transport, PathList* source, int destination, int duration);

	/**
	 * @author Francisco
	 *
	 * @brief Appends a new Rent to the Graph.
	 *
	 * @param Graph Rent
	 * @param Rent to insert
	 * @return New Rent
	 * @return NULL - Error allocating memory
	 */
	float CalculatePrice(int distance, int duration, float price);

	/**
	 * @author Francisco
	 *
	 * @brief Allocates a new Rent o memory.
	 *
	 * @return New Rent
	 * @return NULL - Error allocating memory
	 */
	Rent* CreateEmptyRent();

	/**
	 * @author Francisco
	 *
	 * @brief Appends a new Rent to the List.
	 *
	 * @param Graph Rent
	 * @param Rent to insert
	 * @return New Rent
	 * @return NULL - Error allocating memory
	 */
	Rent* CreateRent(int id, int customer, int transport, float distance, time_t start, int duration);

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
	bool AddRent(RentList** head, Rent *sourceRent);

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
	bool SwapRent(RentList* rent1, RentList* rent2);

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
	bool EditRent(RentList* rent, Rent newRent);

	/**
	 * @author Francisco
	 *
	 * @brief Finds rent by its id.
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
	 * @brief Reads all the rents from a file into a list.
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
	 * @brief Saves all the rents from a list into a file.
	 *
	 * @param List Head
	 * @param File directory
	 * @return 1 - Saved Successfully
	 * @return 2 - Error opening file
	 * @return 3 - The graph is empty
	 */
	int SaveRentsAsFile(RentList* head, const char* fileName);

#endif