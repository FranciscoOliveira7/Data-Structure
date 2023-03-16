/*****************************************************************//**
 * @file   Transport.h
 * @brief  Transport structure and functions signature
 *
 * @author Francisco
 * @date   March 2023
 *********************************************************************/

#include <stdlib.h>
#include <stdbool.h>

#ifndef TRANSPORT_H_
#define TRANSPORT_H_

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
		TransportType type;
		float cargaBateria;
		float custoAluguer;
		char localizacao[LOCATION_SIZE];
	} Transport;

	typedef struct TransportList TransportList;
	struct TransportList {
		Transport transport;
		TransportList* next;
	};

	/**
	 * Appends a new Transport to the linked list.
	 *
	 * @param List Head
	 * @param Transport to insert
	 * @return true - Added Successfully
	 * @return false - Error allocating memory
	 */
	bool AddTransport(TransportList** head, Transport sourceTransport);

	/**
	 * Gets the Transport pointer in a linked list by its index.
	 *
	 * @param List head
	 * @param Transport index
	 * @return Transport pointer with the specified index
	 */
	TransportList* GetTransport(TransportList* head, int index);

#endif