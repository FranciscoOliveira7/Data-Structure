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
	newVertex->isVisited = false;

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
int AddEdgeByCode(Vertex* graph, int srcVertex, int destVertex, int weight) {

	Vertex* v1 = SearchVertexByCode(graph, srcVertex);
	Vertex* v2 = SearchVertexByCode(graph, destVertex);

	AddEdge(v1, v2, weight);
}

/**
 * @author Francisco
 *
 * @brief Search Vertex by its code in a Recursive way.
 *
 * @param Graph Vertex
 * @param Vertex cdoe
 * @return Searched Vertex
 * @return Null if Vertex not found
 */
Vertex* SearchVertexByCode(Vertex* graph, int code) {

	if (graph == NULL) return NULL;
	if (graph->values.code == code) return graph;
	return SearchVertexByCode(graph->next, code);
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

	Vertex* currentV = graph;
	Adj* currentA;
	AdjValues currentAdj;

	FILE* file;
	fopen_s(&file, fileName, "wb");

	// Return 2 if the file wasn't open successfully
	if (file == NULL) return 2;

	int numOfVertexes = CountVertices(graph);
	
	fwrite(&numOfVertexes, sizeof(int), 1, file);

	//save graph
	while (currentV != NULL) {
		fwrite(&(currentV->values), sizeof(VertexValues), 1, file);
		currentV = currentV->next;
	}

	currentV = graph;

	while (currentV != NULL) {
		Adj* currentA = currentV->adjacency;

		while (currentA != NULL) {

			currentAdj.source = currentV->values.code;
			currentAdj.destination = currentA->vertex->values.code;
			currentAdj.weight = currentA->weight;

			fwrite(&currentAdj, sizeof(currentAdj), 1, file);
			currentA = currentA->next;
		}
		currentV = currentV->next;
	}

	fclose(file);
	return 1;
}

/**
 * @author Francisco
 *
 * @brief Loads a graph from a binary file.
 *
 * @param Graph adress
 * @param File directory
 * @return 1 - Loaded Successfully
 * @return 2 - Error opening file
 * @return 3 - Error reading file
 */
int LoadGraphFile(Vertex** graph, const char* fileName) {

	FILE* file;
	fopen_s(&file, fileName, "rb");

	// Return 2 if the file wasn't open successfully
	if (file == NULL) return 2;

	// Values currently reading
	VertexValues currentV;
	AdjValues currentA;

	int count = 0;

	fread(&count, sizeof(int), 1, file);
	if (count <= 0) return 3;

	// Reads all the Vertexes
	for (int i = 0; i < count; i++) {
		fread(&currentV, sizeof(VertexValues), 1, file);

		AddVertex(graph, CreateVertex(currentV.code, currentV.name));
	}

	// Read's all the Edges
	while (fread(&currentA, sizeof(AdjValues), 1, file) == 1) {
		AddEdgeByCode(*graph, currentA.source, currentA.destination, currentA.weight);
	}

	fclose(file);
	return 1;
}

/**
 * @author Francisco
 *
 * @brief Loads a graph from a binary file.
 *
 * @param Graph adress
 * @param File directory
 * @return 1 - Loaded Successfully
 * @return 2 - Error opening file
 * @return 3 - Error reading file
 */
int LoadGraphTextFile(Vertex** graph, const char* fileName) {

	FILE* file;
	fopen_s(&file, fileName, "r");

	// Return 2 if the file wasn't open successfully
	if (file == NULL) return 2;

	VertexValues currentV;
	AdjValues currentA;

	int count = 0;

	char buffer[256];

	// Read number of Vertices
	fgets(buffer, sizeof(buffer), file);
	if (buffer == NULL) return NULL;
	count = atoi(buffer);

	// Read's all the Vertices
	for (int i = 0; i < count; i++) {
		fgets(buffer, sizeof(buffer), file);

		if (sscanf(buffer, "%d;%s\n", &currentV.code, currentV.name) != 2)
			return 3;

		AddVertex(graph, CreateVertex(currentV.code, currentV.name));
	}

	// Read's all the Edges

	while(fgets(buffer, sizeof(buffer), file) != NULL) {

		if (sscanf(buffer, "%d;%d;%d\n",
			&currentA.source, &currentA.destination, &currentA.weight) != 3)
		return 3;

		AddEdgeByCode(*graph, currentA.source, currentA.destination, currentA.weight);
	}

	fclose(file);
	return 1;
}

/**
 * @author Francisco
 *
 * @brief Counts the number of Vertices.
 *
 * @param Graph
 * @return Number os Vertices
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

/**
 * @author Francisco
 *
 * @brief Counts the number of Edges on a graph.
 *
 * @param Graph
 * @return Number os Edges
 */
int CountEdges(Vertex* graph) {

	if (graph == NULL) return 0;

	Vertex* vertex = graph;

	int count = 0;
	while (vertex != NULL) {
		Adj* current = vertex->adjacency;

		while (current != NULL) {
			count++;
			current = current->next;
		}
		vertex = vertex->next;
	}

	return count;
}

/**
 * @author Francisco
 *
 * @brief Wipe a graph from memory.
 *
 * @param Graph adress
 * @return true - Graph wiped Successfully
 * @return false - Graph is already empty
 */
bool WipeGraph(Vertex** graph) {

	if (*graph == NULL) return false;

	Vertex* last = *graph, *previous;

	while (last->next != NULL) {
		previous = last;
		last = last->next;
		WipeAdj(previous);
		free(previous);
	}
	free(last);

	*graph = NULL;
	return true;
}


/**
 * @author Francisco
 *
 * @brief Wipe a vertex Adjecencies from memory.
 *
 * @param Adjecency adress
 */
void WipeAdj(Vertex* vertex) {

	if (vertex->adjacency == NULL) return;

	Adj* last = vertex->adjacency, *previous;

	while (last->next != NULL) {
		previous = last;
		last = last->next;
		free(previous);
	}
}

/**
 * @author Francisco
 *
 * @brief Depth First Search algorithm that returns if there's a path from a Vertex to another
 *
 * @param Graph
 * @param Source Vertex
 * @param Destination Vertex
 * @return true - if there's a path
 * @return false - if there's not
 */
bool DepthFirstSearch(Vertex* graph, int source, int destination) {

	/* Since it's recursive, if the source and destination are the same it mean
	   the source reached the destination and there's a path between them */
	if (source == destination) return true;

	Vertex* currentV = SearchVertexByCode(graph, source);
	currentV->isVisited = true;

	Adj* currentA = currentV->adjacency;

	// Searches all the paths from all the currentV Adjancencies
	while (currentA != NULL) {
		currentV = currentA->vertex;
		if (!currentV->isVisited)
			return DepthFirstSearch(graph, currentV->values.code, destination);
		currentA = currentA->next;
	}
}