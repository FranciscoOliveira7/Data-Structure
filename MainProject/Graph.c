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
 * @return New Vertex
 * @return NULL - Error allocating memory
 */
Vertex* CreateVertex(int code, char* name) {

	//Creates a new space in memory to Allocate the Vertex
	Vertex* newVertex = (Vertex*)malloc(sizeof(Vertex));

	if (newVertex == NULL) {
		free(newVertex);
		return NULL;
	}

	VertexValues values;
	values.code = code;
	strcpy(values.name, name);

	newVertex->values = values;
	newVertex->next = NULL;
	newVertex->adjacency = NULL;

	return newVertex;
}

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
bool AddVertex(Vertex** graph, Vertex* srcVertex) {

	if (srcVertex == NULL) return false;

	//If the graph is empty, creates a new vertex to it
	if (*graph == NULL) {
		*graph = srcVertex;
		return true;
	}

	//Else, finds the last element of the list
	Vertex* previous = *graph;
	Vertex* last = *graph;

	while (last != NULL && strcmp(last->values.name, srcVertex->values.name) < 0) {
		previous = last;
		last = last->next;
	}
	if (last == *graph) {
		srcVertex->next = *graph;
		*graph = srcVertex;
	}
	else {
		srcVertex->next = last;
		previous->next = srcVertex;
	}

	return true;
}

/**
 * @author Francisco
 *
 * @brief Appends a new Adjecency to a Vertex.
 *
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
int AddEdgeByName(Vertex* graph, char* srcVertex, char* destVertex, int weight) {

	Vertex* v1 = SearchVertexByName(graph, srcVertex);
	Vertex* v2 = SearchVertexByName(graph, destVertex);

	AddEdge(v1, v2, weight);
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
	if (strcmp(graph->values.name, name) == 0) return graph;
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
		printf("\n %s\n", currentVertex->values.name);

		Adj* currentAdj = currentVertex->adjacency;
		if (currentAdj != NULL)
			while (currentAdj != NULL) {
				printf(" - %s\n", currentAdj->vertex->values.name);

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

	printf("\n %s\n", vertex->values.name);
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

	printf(" - %s (%.1fkm)\n", adjecency->vertex->values.name, adjecency->weight);
	displayAdjs(adjecency->next);
}

/**
 * @author Francisco
 *
 * @brief Saves all the Vertex from a list into a file.
 *
 * @param Graph
 * @param File directory
 * @return 1 - Saved Successfully
 * @return 2 - Error opening file
 * @return 3 - The graph is empty
 */
int SaveGraphAsFile(Vertex* graph, const char* fileName) {

	if (graph == NULL) return 3;

	Vertex* current = graph;

	FILE* file;
	fopen_s(&file, fileName, "wb");

	// Return 2 if the file wasn't open successfully
	if (file == NULL) return 2;
	
	fwrite(CountVertices(graph), sizeof(int), 1, file);

	while (true) {

	}

	fclose(file);
	return 1;
}

/**
 * @author Francisco
 *
 * @brief Counts the number of vertices.
 *
 * @param Graph
 * @param File directory
 * @return Number os vertices
 */
int CountVertices(Vertex* graph) {

	int count = 0;
	Vertex* current = graph;

	while (current != NULL) {
		count++;
		current = current->next;
	}

	return count;
}