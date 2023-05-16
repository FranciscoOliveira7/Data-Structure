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
#include "Graph.h"

int main() {
	CustomerList* customers = NULL; //Costumer linked list inicialization
	ManagerList* managers = NULL; //Manager linked list inicialization
	TransportList* transports = NULL; //Transport linked list inicialization

	Vertex* graph = NULL;
	Vertex* v1 = CreateVertex(1, "Lisboa");
	Vertex* v2 = CreateVertex(2, "Braga");
	Vertex* v3 = CreateVertex(3, "Porto");
	Vertex* v4 = CreateVertex(3, "Guimaraes");

	AddVertex(&graph, v1);
	AddVertex(&graph, v2);
	AddVertex(&graph, v3);
	AddVertex(&graph, v4);

	AddEdgeByName(graph, "Lisboa", "Braga", 24);
	AddEdgeByName(graph, "Lisboa", "Porto", 35);
	AddEdgeByName(graph, "Braga", "Lisboa", 24);
	AddEdgeByName(graph, "Porto", "Braga", 36);

	//printf(" %s", SearchVertexByName(graph, "Lisboa")->name);

	displayGraph(graph);

	ReadCustomersFile(&customers, CUSTOMER_TEXT_DIR);
	ReadManagersFile(&managers, MANAGER_TEXT_DIR);
	ReadTransportsFile(&transports, TRANSPORT_TEXT_DIR);

	Customer c1 = { 1, "dwdw", "dwd", "dwdw", 69420 };
	//Customer c2 = { 2, "dydfy", "breb", "sdf", 12345 };
	//Customer c3 = { 3, "ehg", "ertg", "fwef", 8994 };
	//Customer c4 = { 4, "kym", "myu", "bn", 345 };

	AddCustomer(&customers, c1);

	// TODO: FIX GETBYINDEX FUNCTIONS

	//while (1 + 1 == 2)
	//{
	//	2;
	//}

	//Customer c3;

	//c3 = FindCustomer(customers, 1);

	//printf("Balance: %.2f", costumers->balance);


	//printf("\n %d", SaveTransportsAsFile(transports, TRANSPORT_BIN_DIR));

	CustomerList* sample = FindCustomer(customers, 1);

	//EditCustomer(sample, c1);

	RemoveCustomer(&customers, sample);

	SwapCustomer(FindCustomer(customers, 1), FindCustomer(customers, 4));

	SortCustomersById(customers);

	SortTransportsByBatteryLife(transports);

	WipeCustomers(&customers);

	// return 0 to make sure the code runs until end when testing
	return 0;
}