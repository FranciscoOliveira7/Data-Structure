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

	#include "Path.h"
	#include "Transport.h"

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
	 * @brief Appends a new Vertex to the Graph.
	 *
	 * @param Graph Vertex
	 * @param Vertex to insert
	 * @return true - Copied successfully
	 * @return false - Error creating vertex
	 */
	bool* CopyVertex(Vertex** graph, Vertex* source);

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
	void DisplayGraph(Vertex* vertex);

	/**
	 * @author Francisco
	 *
	 * @brief Displays Vertex Adjecencies on terminal in a recursive way.
	 *
	 * @param Vertex adjecency
	 * @return true - There's at least one adjacency
	 * @return false - The Vertex has no adjacencies
	 */
	bool DisplayAdjs(Adj* adjecency);

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
	 * @brief Find all the shortest paths in a graph using Dijkstra's algorithm.
	 *
	 * @param graph
	 * @param source Vertex
	 * 
	 * @return PathList
	 */
	PathList* FindShortestPath(Vertex* graph, int source);

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
	Vertex* FindVerticesInRadius(Vertex* graph, int id, float radius);

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

#endif