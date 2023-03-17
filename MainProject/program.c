/*****************************************************************//**
 * @file   Program.c
 * @brief  Calls other functions
 * 
 * @author Francisco
 * @date   March 2023
 *********************************************************************/

#include "Customer.h"
#include "Manager.h"
#include "Transport.h"

int main() {

	CustomerList* customers = NULL; //Costumer linked list inicialization
	ManagerList* managers = NULL; //Manager linked list inicialization
	TransportList* transports = NULL; //Transport linked list inicialization

	Customer c1 = { "dwdw", "dwd", "dwdw", 69420 };
	Customer c2 = { "dydfy", "breb", "sdf", 12345 };


	// TODO: FIX GETBYINDEX FUNCTIONS


	//Manager m2 = { 12345, "dydfy", "breb", 69, NULL };

	//AddCustomer(&customers, c1);
	//AddCustomer(&customers, c2);

	//while (1 + 1 == 2)
	//{
	//	2;
	//}

	//Customer c3;

	//c3 = FindCustomer(customers, 1);

	//printf("Balance: %.2f", costumers->balance);

	printf("\n %d", ReadTransportsFile(&transports, TRANSPORT_TEXT_DIR));

	printf("\n %d", SaveTransportsAsFile(transports, TRANSPORT_BIN_DIR));

	return (int)GetTransport(transports, 4)->transport.id;
}