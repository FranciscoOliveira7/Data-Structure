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
	Adj* currentA = NULL;
	AdjValues currentAdj = { 0 };

	FILE* file;
	fopen_s(&file, fileName, "wb");

	// Return 2 if the file wasn't open successfully
	if (file == NULL) return 2;

	int numOfVertexes = CountVertices(graph);
	
	fwrite(&numOfVertexes, sizeof(int), 1, file);

	// Save Vertecies
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
 * @brief Removes all graph Vertecies visited state.
 *
 * @param Graph
 * @return true - All Vertecies reseted
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
 * @return true - All Vertecies are visited
 * @return false - Not All Vertecies are visited
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
 * @brief Find all the shortest paths between in a graph using Dijkstra's algorithm.
 *
 * @param graph
 * @param source Vertex
 */
PathList* FindShortestPath(Vertex* graph, int source) {
	
	int numOfVertices = CountVertices(graph);

	PathList* pathlist = InitializePathList(graph);
	FindPathList(pathlist, source)->distance = 0;

	Vertex* currentV = SearchVertexByCode(graph, source);
	Adj* currentA = NULL;

	//AddPath(&pathlist->path, CreatePath(source));

	Path* currentpath = CreatePath(source);
	int distance = 0;

	//Work in Progress...
	
	while (!AllVerticesVisited(graph)) {

		currentA = currentV->adjacency;
		int leastDistant = -1; // Least distante vertex
		while (currentA != NULL) {
			// Checks if the 
			if (distance + currentA->weight < FindPathList(pathlist, currentA->vertex->values.id)->distance)
			{
				// Find the closest Vertex to the current one
				if (leastDistant == -1 || currentA->weight < FindPathList(pathlist, leastDistant)->distance)
					leastDistant = currentA->vertex->values.id;

				FindPathList(pathlist, currentA->vertex->values.id)->distance = distance + currentA->weight;
			}

			currentA = currentA->next;
		}
		// Updates current vertex to the closest one to itself
		if (leastDistant != -1) {
			currentV->isVisited = true;
			distance += currentA->weight;
			currentV = SearchVertexByCode(graph, leastDistant);
		}
	}

	return pathlist;
}





/************************************************************
 ******               PATHLIST FUNCTIONS               ******
 ************************************************************/




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

/**
 * @author Francisco
 *
 * @brief Appends a new PathList to the Graph.
 *
 * @param Graph PathList
 * @param PathList to insert
 * @return New PathList
 * @return NULL - Error allocating memory
 */
PathList* CreatePathList(int vertex) {

	//Creates a new space in memory to Allocate the PathList
	PathList* newPathList = (PathList*)malloc(sizeof(PathList));

	if (newPathList == NULL) {
		free(newPathList);
		return NULL;
	}
	newPathList->distance = BIG_NUMBER;
	newPathList->vertex = vertex;
	newPathList->next = NULL;
	newPathList->path = NULL;

	return newPathList;
}

/**
 * @author Francisco
 *
 * @brief Appends a new PathList to the linked list.
 *
 * @param List Head
 * @param PathList to insert
 * @return true - Added Successfully
 * @return false - Error allocating memory
 */
bool AddPathList(PathList** head, PathList* sourcePathList) {

	if (sourcePathList == NULL) {
		free(sourcePathList);
		return false;
	}

	sourcePathList->next = NULL;

	//If the list is empty, creates a new head to the list
	if (*head == NULL) {
		*head = sourcePathList;
		return true;
	}

	//Else finds the last element of the list
	PathList* last = *head;

	while (last->next != NULL) {
		last = last->next;
	}
	last->next = sourcePathList;
	return true;
}

/**
 * @author Francisco
 *
 * @brief Finds pathList by its id.
 *
 * @param List Head
 * @param PathList id
 * @return PathList pointer with the specified id
 * @return NULL if not found
 */
PathList* FindPathList(PathList* head, int vertex) {

	if (head == NULL) return NULL;

	PathList* current = head;

	while (current != NULL) {
		if (current->vertex == vertex) return current;
		current = current->next;
	}

	return NULL;
}

/**
 * @author Francisco
 *
 * @brief Wipe a PathLists linked list from memory.
 *
 * @param List head
 * @return true - List wiped Successfully
 * @return false - List is already empty
 */
bool WipePathLists(PathList** head) {

	if (*head == NULL) return false;

	PathList* current = *head;
	PathList* previous = NULL;

	*head = NULL;

	while (current != NULL)
	{
		previous = current;
		current = current->next;
		free(previous);
	}

	return true;
}


/************************************************************
 ******                 PATH FUNCTIONS                 ******
 ************************************************************/

 /**
  * @author Francisco
  *
  * @brief Appends a new Path to the Graph.
  *
  * @param Graph Path
  * @param Path to insert
  * @return New Path
  * @return NULL - Error allocating memory
  */
Path* CreatePath(int vertex) {

	//Creates a new space in memory to Allocate the Path
	Path* newPath = (Path*)malloc(sizeof(Path));

	if (newPath == NULL) {
		free(newPath);
		return NULL;
	}
	newPath->vertex = vertex;
	newPath->next = NULL;

	return newPath;
}

/**
 * @author Francisco
 *
 * @brief Appends a new Path to the linked list.
 *
 * @param List Head
 * @param Path to insert
 * @return true - Added Successfully
 * @return false - Error allocating memory
 */
bool AddPath(Path** head, Path* sourcePath) {

	//If the list is empty, creates a new head to the list
	if (*head == NULL) {
		*head = sourcePath;
		return true;
	}

	//Else finds the last element of the list
	Path* last = *head;

	while (last->next != NULL) {
		last = last->next;
	}
	last->next = sourcePath;
	return true;
}

/**
 * @author Francisco
 *
 * @brief Wipe a Paths linked list from memory.
 *
 * @param List head
 * @return true - List wiped Successfully
 * @return false - List is already empty
 */
bool WipePaths(Path** head) {

	if (*head == NULL) return false;

	Path* current = *head;
	Path* previous = NULL;

	*head = NULL;

	while (current != NULL)
	{
		previous = current;
		current = current->next;
		free(previous);
	}

	return true;
}