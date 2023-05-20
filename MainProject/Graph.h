/*****************************************************************//**
 * @file   Graph.h
 * @brief  Oriented Weighted Graph implementation using Adjacency List paradigm
 *
 * @author Francisco
 * @date   May 2023
 *********************************************************************/

#include "Consts.h"

#ifndef GRAPH_H_
#define GRAPH_H_

	#define LOCATION_TEXT_DIR "Data\\imported\\locations.txt"
	#define LOCATION_BIN_DIR "Data\\saved\\locations.txt"

	// ? This graph isn't generalized and was made to old a single code and name

	/**
	 * - Save Vertexs Graph to file sample -
	 * Number of Vertex
	 * (all the vertex)
	 * Number of Adjancencies
	 * (all the Adjancencies)
	 */

	/***** Data type definitions *****/

	typedef struct Vertex Vertex;
	typedef struct Adj Adj;

	// Vertex and Adjancency's values to easly save them into a file
	typedef struct {
		int id;					  // vertex code
		char name[LOCATION_SIZE]; // geocode
	} VertexValues;

	typedef struct {
		int source;
		int destination;
		float weight;
	} AdjValues;

	// Vertex vertex
	struct Vertex {
		VertexValues values;
		Vertex* next;
		Adj* adjacency;
		bool isVisited;
	};

	// Vertex Edge
	struct Adj {
		float weight; // Edge Weight
		Adj* next;
		Vertex* vertex;
	};

	typedef struct Path Path;
	typedef struct PathList PathList;

	struct Path {
		int vertex;
		Path* next; // Previous Vertex of the path
	};

	struct PathList {
		int vertex;
		int distance; // Total weigth of the path
		Path* path;
		PathList* next;
	};

	/***** All function signatures *****/

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
	Vertex* CreateVertex(int code, char* name);

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
	bool AddVertex(Vertex** graph, Vertex* srcVertex);

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
	int AddEdge(Vertex* srcVertex, Vertex* destVertex, float weight);

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
	int AddEdgeByName(Vertex* graph, char* srcVertex, char* destVertex, float weight);

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
	int AddEdgeByCode(Vertex* graph, int srcVertex, int destVertex, float weight);

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
	Vertex* SearchVertexByCode(Vertex* graph, int code);

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
	Vertex* SearchVertexByName(Vertex* graph, char* name);


	/**
	 * @author Francisco
	 *
	 * @brief Displays Graph vertexes and Adjecencies on terminal.
	 *
	 * @param Graph
	 */
	void displayGraph_Old(Vertex* graph);

	/**
	 * @author Francisco
	 *
	 * @brief Displays Graph vertexes and Adjecencies on terminal in a recursive way.
	 *
	 * @param Graph vertex
	 */
	void displayGraph(Vertex* vertex);

	/**
	 * @author Francisco
	 *
	 * @brief Displays Vertex Adjecencies on terminal in a recursive way.
	 *
	 * @param Vertex adjecency
	 */
	void displayAdjs(Adj* adjecency);

	/**
	 * @author Francisco
	 *
	 * @brief Saves all the Vertex from a list into a file.
	 *
	 * @param Graph
	 * @param File directory
	 * @return 1 - Saved Successfully
	 * @return 2 - Error opening file
	 * @return 3 - The list is empty
	 */
	int SaveGraphAsFile(Vertex* graph, const char* fileName);

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
	int LoadGraphFile(Vertex** graph, const char* fileName);

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
	int LoadGraphTextFile(Vertex** graph, const char* fileName);

	/**
	 * @author Francisco
	 *
	 * @brief Counts the number of vertices.
	 *
	 * @param Graph
	 * @return Number os vertices
	 */
	int CountVertices(Vertex* graph);

	/**
	 * @author Francisco
	 *
	 * @brief Counts the number of Edges on a graph.
	 *
	 * @param Graph
	 * @return Number os Edges
	 */
	int CountEdges(Vertex* graph);

	/**
	 * @author Francisco
	 *
	 * @brief Wipe a graph from memory.
	 *
	 * @param Graph adress
	 * @return true - Graph wiped Successfully
	 * @return false - Graph is already empty
	 */
	bool WipeGraph(Vertex** graph);

	/**
	 * @author Francisco
	 *
	 * @brief Removes all graph Vertecies visited state.
	 *
	 * @param Graph
	 * @return true - All Vertecies reseted
	 * @return false - Graph is empty
	 */
	bool ResetVisitedNodes(Vertex* graph);

	/**
	 * @author Francisco
	 *
	 * @brief Checks if all the Vertices are visited.
	 *
	 * @param Graph
	 * @return true - All Vertecies are visited
	 * @return false - Not All Vertecies are visited
	 */
	bool AllVerticesVisited(Vertex* graph);


	/**
	 * @author Francisco
	 *
	 * @brief Wipe a vertex Adjecencies from memory.
	 *
	 * @param Adjecency adress
	 */
	void WipeAdj(Vertex* vertex);

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
	bool IsTherePath(Vertex* graph, int source, int destination);

	/**
	 * @author Francisco
	 *
	 * @brief Find all the shortest paths between in a graph using Dijkstra's algorithm.
	 *
	 * @param graph
	 * @param source Vertex
	 */
	PathList* FindShortestPath(Vertex* graph, int source);











	#define BIG_NUMBER 100000

	/***** All function signatures *****/

	/**
	 * @author Francisco
	 *
	 * @brief Initalizes a PathList with all the vertex for the Dijkstra algorithm
	 *
	 * @param Graph
	 * @return New PathList
	 * @return NULL - the graph is empty
	 */
	PathList* InitializePathList(Vertex* graph);

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
	PathList* CreatePathList(int vertex);

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
	bool AddPathList(PathList** head, PathList* sourcePathList);

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
	PathList* FindPathList(PathList* head, int vertex);

	/**
	 * @author Francisco
	 *
	 * @brief Wipe a PathLists linked list from memory.
	 *
	 * @param List head
	 * @return true - List wiped Successfully
	 * @return false - List is already empty
	 */
	bool WipePathLists(PathList** head);


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
	Path* CreatePath(int vertex);

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
	bool AddPath(Path** head, Path* sourcePath);

	/**
	 * @author Francisco
	 *
	 * @brief Wipe a Paths linked list from memory.
	 *
	 * @param List head
	 * @return true - List wiped Successfully
	 * @return false - List is already empty
	 */
	bool WipePaths(Path** head);

#endif