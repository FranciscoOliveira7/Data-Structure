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
#include "Path.h"
#include "Rent.h"

int main() {
	time_t now = time(NULL);

	CustomerList* customers = NULL; //Costumer linked list inicialization
	ManagerList* managers = NULL; //Manager linked list inicialization
	TransportList* transports = NULL; //Transport linked list inicialization
	Rent* rents = NULL;

	Vertex* graph = NULL;
	//Vertex* v1 = CreateVertex(1, "Lisboa");
	//Vertex* v2 = CreateVertex(2, "Braga");
	//Vertex* v3 = CreateVertex(3, "Porto");
	//Vertex* v4 = CreateVertex(4, "Guimaraes");

	//AddVertex(&graph, v1);
	//AddVertex(&graph, v2);
	//AddVertex(&graph, v3);
	//AddVertex(&graph, v4);

	//AddEdgeByName(graph, "Lisboa", "Braga", 24);
	//AddEdgeByName(graph, "Lisboa", "Porto", 35);
	//AddEdgeByName(graph, "Braga", "Lisboa", 24);
	//AddEdgeByName(graph, "Porto", "Braga", 36);

	AddVertex(&graph, CreateVertex(1, "A"));
	AddVertex(&graph, CreateVertex(2, "B"));
	AddVertex(&graph, CreateVertex(3, "C"));
	AddVertex(&graph, CreateVertex(4, "D"));
	AddVertex(&graph, CreateVertex(5, "E"));

	AddEdgeByName(graph, "A", "B", 4);
	AddEdgeByName(graph, "A", "C", 2);
	AddEdgeByName(graph, "C", "B", 1);
	AddEdgeByName(graph, "B", "C", 3);
	AddEdgeByName(graph, "B", "D", 2);
	AddEdgeByName(graph, "B", "E", 3);
	AddEdgeByName(graph, "E", "D", 1);
	AddEdgeByName(graph, "C", "E", 5);
	AddEdgeByName(graph, "C", "D", 4);

	//WipeGraph(&graph);

	//LoadGraphTextFile(&graph, LOCATION_TEXT_DIR);

	//SaveGraphAsFile(graph, LOCATION_BIN_DIR);

	//PathList pathlist = FindShortestPath(graph, 1);

	//IsTherePath(graph, 3, 2);

	ResetVisitedNodes(graph);

	DisplayGraph(graph);

	PathList* pathlist = FindShortestPath(graph, 1);

	Rent* rent = RegisterRent(1, FindCustomer(customers, 1), FindTransport(transports, 1), pathlist, 2, 360);

	AddRent(&rents, rent);

	Vertex* locations = FindVerticesInRadius(graph, 1, 2);
	
	ReadCustomersFile(&customers, CUSTOMER_TEXT_DIR);
	ReadManagersFile(&managers, MANAGER_TEXT_DIR);
	ReadTransportsFile(&transports, TRANSPORT_TEXT_DIR);

	Customer c1 = { 1, "dwdw", "dwd", "dwdw", 69420 };
	//Customer c2 = { 2, "dydfy", "breb", "sdf", 12345 };
	//Customer c3 = { 3, "ehg", "ertg", "fwef", 8994 };
	//Customer c4 = { 4, "kym", "myu", "bn", 345 };

	AddCustomer(&customers, c1);

	TransportList* asf = FindTransportsInLocation(transports, "Lisboa");

	//while (1 + 1 == 2)
	//{
	//	2;
	//}

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