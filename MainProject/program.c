/*****************************************************************//**
 * @file   Program.c
 * @brief  Calls other functions
 * 
 * @author Francisco
 * @date   March 2023
 *********************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Customer.h"
#include "Manager.h"
#include "Transport.h"

int main() {

	TransportType t = bus;

	Customer* customers = NULL; //Costumer linked list inicialization

	Customer c1 = { 69420, "dwdw", "dwd", "dwdw", 2, NULL };
	Customer c2 = { 12345, "dydfy", "breb", "sdf", 69, NULL };

	//Manager m2 = { 12345, "dydfy", "breb", 69, NULL };

	AddCustomer(&customers, c1);
	AddCustomer(&customers, c2);

	//while (1 + 1 == 2)
	//{
	//	2;
	//}

	//Customer c3;

	//c3 = FindCustomer(customers, 1);

	//printf("Balance: %.2f", costumers->balance);

	return GetCustomer(customers, 0)->id;
}