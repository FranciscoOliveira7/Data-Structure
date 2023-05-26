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
Vertex* CreateVertex(int id, char* name) {

	//Creates a new space in memory to Allocate the Vertex
	Vertex* newVertex = (Vertex*)malloc(sizeof(Vertex));

	if (newVertex == NULL) {
		free(newVertex);
		return NULL;
	}

	VertexValues values = { 0 };
	values.id = id;
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
 * @brief Copy a vertex to a diferent graph.
 *
 * @param Graph Vertex
 * @param Vertex to copy
 * @return true - Copied successfully
 * @return false - Error creating vertex
 */
bool* CopyVertex(Vertex** graph, Vertex* source) {

	Vertex* vertex = CreateVertex(source->values.id, source->values.name);

	AddVertex(graph, vertex);
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
int AddEdge(Vertex* srcVertex, Vertex* destVertex, float weight) {

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
int AddEdgeByName(Vertex* graph, char* srcVertex, char* destVertex, float weight) {

	Vertex* v1 = SearchVertexByName(graph, srcVertex);
	Vertex* v2 = SearchVertexByName(graph, destVertex);

	AddEdge(v1, v2, weight);
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
int AddEdgeByCode(Vertex* graph, int srcVertex, int destVertex, float weight) {

	Vertex* v1 = SearchVertexByCode(graph, srcVertex);
	Vertex* v2 = SearchVertexByCode(graph, destVertex);

	AddEdge(v1, v2, weight);
	return 1;
}

/**
 * @author Francisco
 *
 * @brief Search Vertex by its id in a Recursive way.
 *
 * @param Graph Vertex
 * @param Vertex cdoe
 * @return Searched Vertex
 * @return Null if Vertex not found
 */
Vertex* SearchVertexByCode(Vertex* graph, int id) {

	if (graph == NULL) return NULL;
	if (graph->values.id == id) return graph;
	return SearchVertexByCode(graph->next, id);
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

	//No return value needed since u can literally see that nothing is printed ¯\_(ツ)_/¯
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
void DisplayGraph(Vertex* vertex) {
	
	if (vertex == NULL) return;

	printf("\n %s", vertex->values.name);
	if (!DisplayAdjs(vertex->adjacency))
		printf(" (No Edges)");
	printf("\n");
	DisplayGraph(vertex->next);
}

/**
 * @author Francisco
 *
 * @brief Displays Vertex Adjecencies on terminal in a recursive way.
 *
 * @param Vertex adjecency
 * @return true - There's at least one adjacency
 * @return false - The Vertex has no adjacencies
 */
bool DisplayAdjs(Adj* adjecency) {

	if (adjecency == NULL) return false;

	printf("\n - %s (%.1fkm)", adjecency->vertex->values.name, adjecency->weight);
	DisplayAdjs(adjecency->next);

	return true;
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
	Adj* currentA = NULL;
	AdjValues currentAdj = { 0 };

	FILE* file;
	fopen_s(&file, fileName, "wb");

	// Return 2 if the file wasn't open successfully
	if (file == NULL) return 2;

	int numOfVertexes = CountVertices(graph);
	
	fwrite(&numOfVertexes, sizeof(int), 1, file);

	// Save Vertices
	while (currentV != NULL) {
		fwrite(&(currentV->values), sizeof(VertexValues), 1, file);
		currentV = currentV->next;
	}

	currentV = graph;

	while (currentV != NULL) {
		Adj* currentA = currentV->adjacency;

		while (currentA != NULL) {

			currentAdj.source = currentV->values.id;
			currentAdj.destination = currentA->vertex->values.id;
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

		AddVertex(graph, CreateVertex(currentV.id, currentV.name));
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

	VertexValues currentV = { 0 };
	AdjValues currentA = { 0 };

	int count = 0;

	char buffer[256];

	// Read number of Vertices
	fgets(buffer, sizeof(buffer), file);
	if (buffer == NULL) return 3;
	count = atoi(buffer);

	// Read's all the Vertices
	for (int i = 0; i < count; i++) {
		fgets(buffer, sizeof(buffer), file);

		if (sscanf(buffer, "%d;%s\n", &currentV.id, currentV.name) != 2)
			return 3;

		AddVertex(graph, CreateVertex(currentV.id, currentV.name));
	}

	// Read's all the Edges

	while(fgets(buffer, sizeof(buffer), file) != NULL) {

		if (sscanf(buffer, "%d;%d;%f\n",
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

	while (last != NULL) {
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

	Adj* last = vertex->adjacency, *previous;

	while (last != NULL) {
		previous = last;
		last = last->next;
		free(previous);
	}
}

/**
 * @author Francisco
 *
 * @brief Removes all graph Vertices visited state.
 *
 * @param Graph
 * @return true - All Vertices reseted
 * @return false - Graph is empty
 */
bool ResetVisitedNodes(Vertex* graph) {

	if (graph == NULL) return false;

	Vertex* current = graph;

	while (current != NULL) {
		current->isVisited = false;
		current = current->next;
	}
	return true;
}

/**
 * @author Francisco
 *
 * @brief Checks if all the Vertices are visited.
 *
 * @param Graph
 * @return true - All Vertices are visited
 * @return false - Not All Vertices are visited
 */
bool AllVerticesVisited(Vertex* graph) {

	if (graph == NULL) return false;

	Vertex* current = graph;

	while (current != NULL) {
		if (!current->isVisited) return false;
		current = current->next;
	}
	return true;
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
 * @return false - if there's 
 * @return NULL - if the graph is empty
 */
bool IsTherePath(Vertex* graph, int source, int destination) {

	if (graph == NULL) return false;

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
			return IsTherePath(graph, currentV->values.id, destination);
		currentA = currentA->next;
	}

	return false;
}

/**
 * @author Francisco
 *
 * @brief Find all the shortest paths in a graph using Dijkstra's algorithm.
 *
 * @param graph
 * @param source Vertex
 * 
 * @return PathList
 */
PathList* FindShortestPath(Vertex* graph, int source) {

	// All the shortest paths will be contained in this list, we initialize so all the vertexes start with an "infinite" distance
	PathList* pathlist = InitializePathList(graph);

	// Set source Vertex distance to zero since it's we're already there
	if (SearchVertexByCode(graph, source) == NULL) return NULL;

	FindPathList(pathlist, source)->distance = 0;

	Vertex* currentV = SearchVertexByCode(graph, source);
	Adj* currentA = NULL;

	Path* currentpath = CreatePath(source);
	float distance = 0;
	
	while (!AllVerticesVisited(graph)) {

		currentA = currentV->adjacency;
		Adj* leastDistant = NULL; // Adjacency poiting to the Least distant vertex
		float leastDistantDistance = 0; // Adjacency poiting to the Least distant vertex
		while (currentA != NULL) {
			if (!currentA->vertex->isVisited) {
				// Checks if the current path is shorter than the current on the list and updates it
				if (distance + currentA->weight < FindPathList(pathlist, currentA->vertex->values.id)->distance) {
					PathList* path = FindPathList(pathlist, currentA->vertex->values.id);
					path->distance = distance + currentA->weight;
					path->path = CopyPath(currentpath);
					PushPath(&(path->path), CreatePath(currentA->vertex->values.id));
				}

				// Find the closest Vertex to the current one
				if (leastDistant == NULL || currentA->weight < leastDistantDistance) {
					leastDistant = currentA;
					leastDistantDistance = currentA->weight;
				}
			}

			currentA = currentA->next;
		}
		// Updates current vertex to the closest one to itself
		if (leastDistant != NULL) {
			currentV->isVisited = true;
			distance += leastDistant->weight;
			currentV = leastDistant->vertex;
			PushPath(&currentpath, CreatePath(currentV->values.id));
		}
		// If there's not any left, return to the previous one to check all the other options
		else if (currentV->values.id != source) {
			currentV->isVisited = true;
			PopPath(&currentpath);
			currentV = SearchVertexByCode(graph, TopPath(currentpath)->vertex);
		}
		// If all the possible paths were checks and still not visited all vertices, return the possible paths
		else break;
	}

	ResetVisitedNodes(graph);
	return pathlist;
}

/**
 * @author Francisco
 *
 * @brief Finds all Vertices in a determined radius.
 *
 * @param graph
 * @param source Vertex
 *
 * @return All the Vertices
 */
Vertex* FindVerticesInRadius(Vertex* graph, int source, float radius) {

	PathList* pathlist = FindShortestPath(graph, source);

	Vertex* vertices = NULL;

	while (pathlist != NULL) {

		if (pathlist->distance <= radius)
			CopyVertex(&vertices, SearchVertexByCode(graph, pathlist->vertex));

		pathlist = pathlist->next;
	}

	return vertices;
}

/**
 * @author Francisco
 *
 * @brief Initalizes a PathList with all the vertex for the Dijkstra algorithm
 *
 * @param Graph
 * @return New PathList
 * @return NULL - the graph is empty
 */
PathList* InitializePathList(Vertex* graph) {

	if (graph == NULL) return NULL;

	PathList* path = NULL;
	Vertex* current = graph;

	while (current != NULL) {

		AddPathList(&path, CreatePathList(current->values.id));

		current = current->next;
	}

	return path;
}