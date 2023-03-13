/*****************************************************************//**
 * @file   Customer.h
 * @brief  Customer structure and functions signature
 *
 * @author Francisco
 * @date   March 2023
 *********************************************************************/

#ifndef CUSTOMER_H_
#define CUSTOMER_H_

	#define NAME_SIZE 40
	#define NIF_SIZE 15
	#define ADRESS_SIZE 80

	typedef struct Customer Customer;
	struct Customer {
		int id;
		char name[NAME_SIZE], nif[NIF_SIZE], adress[ADRESS_SIZE];
		float balance;
		Customer* next;
	};


	void AddCustomer(Customer** head, Customer sourceCostumer);

	Customer FindCustomer(Customer* head, int index);

#endif