/*****************************************************************//**
 * @file   Graph.c
 * @brief  Oriented Weighted Graph structure and functions using Adjacency List paradigm
 *
 * @author Francisco
 * @date   May 2023
 *********************************************************************/

#include "Graph.h"

/*
//Brainless activity, I'll keep it here to remember my mistakes
Vertex* CreateGraph() {

	Vertex* graph = (Vertex*)malloc(sizeof(Vertex));

	if (graph == NULL) {
		free(graph);
		return NULL;
	}

	graph = NULL;
	return graph;
}*/

 /**
  * @author Francisco
  *
  * @brief Appends a new Vertex to the Graph.
  *
  * @param Graph Vertex
  * @param Vertex to insert
  * @return true - Added Successfully
  * @return false - Error allocating memory
  */
bool AddVertex(Vertex** graph, Vertex srcVertex) {
	//Creates a new space in memory to Allocate the Vertex
	Vertex* newVertex = (Vertex*)malloc(sizeof(Vertex));

	if (newVertex == NULL) {
		free(newVertex);
		return false;
	}

	*newVertex = srcVertex;
	newVertex->next = NULL;
	newVertex->adjacency = NULL;

	//If the graph is empty, creates a new vertex to it
	if (*graph == NULL) {
		*graph = newVertex;
		return true;
	}

	//Else, finds the last element of the list
	Vertex* previous = *graph;
	Vertex* last = *graph;

	while (last != NULL && strcmp(last->name, newVertex->name) < 0) {
		previous = last;
		last = last->next;
	}
	if (last == *graph) {
		newVertex->next = *graph;
		*graph = newVertex;
	}
	else {
		newVertex->next = last;
		previous->next = newVertex;
	}

	return true;
}

/**
 * @author Francisco
 *
 * @brief Appends a new Adjecency to a Vertex.
 *
 * @param Graph Vertex
 * @param Source Vertex
 * @param Destination Vertex
 * @param Edge Weight
 * @return 1 - Added Successfully
 * @return 2 - Error allocating memory
 * @return 3 - Invalid Vertexes
 */
int AddEdge(Vertex* srcVertex, Vertex* destVertex, int weight) {

	if (srcVertex == NULL || destVertex == NULL) return 3;

	//Creates a new space in memory to Allocate the Vertex
	Adj* newAdj = (Adj*)malloc(sizeof(Adj));

	if (newAdj == NULL) {
		free(newAdj);
		return 2;
	}

	newAdj->weight = weight;
	newAdj->next = NULL;
	newAdj->vertex = destVertex;

	//If the vertex has no Adjecencies, adds as the first one
	if (srcVertex->adjacency == NULL) {
		srcVertex->adjacency = newAdj;
		return 1;
	}
	//Else, finds the last element of the list
	Adj* last = srcVertex->adjacency;
	while (last->next != NULL) last = last->next;
	last->next = newAdj;

	return 1;
}

/**
 * @author Francisco
 *
 * @brief Search Vertex by its name in a Recursive way.
 *
 * @param Graph Vertex
 * @param Vertex name
 * @return Searched Vertex
 * @return Null if Vertex not found
 */
Vertex* SearchVertexByName(Vertex* graph, char* name) {
	 
	if (graph == NULL) return NULL;
	if (graph->name == name) return graph;
	return SearchVertexByName(graph->next, name);
}

/**
 * @author Francisco
 *
 * @brief Displays Graph vertexes and Adjecencies on terminal.
 *
 * @param Graph
 */
void displayGraph_Old(Vertex* graph) {

	//No return value needed since u can literally see that nothing is printed .-.
	if (graph == NULL) return;

	Vertex* currentVertex = graph;

	while (currentVertex != NULL) {
		printf("\n %s\n", currentVertex->name);

		Adj* currentAdj = currentVertex->adjacency;
		if (currentAdj != NULL)
			while (currentAdj != NULL) {
				printf(" - %s\n", currentAdj->vertex->name);

				currentAdj = currentAdj->next;
			}

		currentVertex = currentVertex->next;
	}
}

/**
 * @author Francisco
 *
 * @brief Displays Graph vertexes and Adjecencies on terminal in a recursive way.
 *
 * @param Graph vertex
 */
void displayGraph(Vertex* vertex) {
	
	if (vertex == NULL) return;

	printf("\n %s\n", vertex->name);
	displayAdjs(vertex->adjacency);
	displayGraph(vertex->next);
}

/**
 * @author Francisco
 *
 * @brief Displays Vertex Adjecencies on terminal in a recursive way.
 *
 * @param Vertex adjecency
 */
void displayAdjs(Adj* adjecency) {

	if (adjecency == NULL) return;

	printf(" - %s\n", adjecency->vertex->name);
	displayAdjs(adjecency->next);
}