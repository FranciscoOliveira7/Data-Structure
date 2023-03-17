/*****************************************************************//**
 * @file   Transport.h
 * @brief  Transport structure and functions signature
 *
 * @author Francisco
 * @date   March 2023
 *********************************************************************/

#pragma warning(disable : 4996)

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#ifndef TRANSPORT_H_
#define TRANSPORT_H_

	#define TRANSPORT_TEXT_DIR "Data\\imported\\transport.txt"
	#define TRANSPORT_BIN_DIR "Data\\saved\\transport.txt"

	#define NAME_SIZE 40
	#define EMAIL_SIZE 60
	#define PASSWORD_SIZE 30
	#define ADRESS_SIZE 80
	#define LOCATION_SIZE 80

	 //#define str(x) #x
	 //#define xstr(x) str(x)

	typedef enum {
		bus,
		bicycle,
		scooter
	} TransportType;

	typedef struct {
		int id;
		TransportType type;
		float batteryLife;
		float price;
		char localizacao[LOCATION_SIZE];
	} Transport;

	typedef struct TransportList TransportList;
	struct TransportList {
		Transport transport;
		TransportList* next;
	};

	/**
	 * @author Francisco
	 *
	 * @brief Appends a new Transport to the linked list.
	 *
	 * @param List Head
	 * @param Transport to insert
	 * @return true - Added Successfully
	 * @return false - Error allocating memory
	 */
	bool AddTransport(TransportList** head, Transport sourceTransport);

	/**
	 * @author Francisco
	 *
	 * @brief Gets the Transport pointer in a linked list by its index.
	 *
	 * @param List head
	 * @param Transport index
	 * @return Transport pointer with the specified index
	 * @return NULL if the list is empty
	 */
	TransportList* GetTransport(TransportList* head, int index);

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
	int ReadTransportsFile(TransportList** head, char* fileName);

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
	int SaveTransportsAsFile(TransportList* head, char* fileName);

#endif