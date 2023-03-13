/*****************************************************************//**
 * @file   Costumer.h
 * @brief  Costumer structure and functions signature
 *
 * @author Francisco
 * @date   March 2023
 *********************************************************************/

#ifndef COSTUMER_H_
#define COSTUMER_H_

	#define NAME_SIZE 40
	#define NIF_SIZE 15
	#define ADRESS_SIZE 80

	typedef struct Costumer Costumer;
	struct Costumer {
		int id;
		char name[NAME_SIZE], nif[NIF_SIZE], adress[ADRESS_SIZE];
		float balance;
		Costumer* next;
	};


	void AddCostumer(Costumer* head, Costumer sourceCostumer);

#endif