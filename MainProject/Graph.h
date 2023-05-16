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

	#define CUSTOMER_TEXT_DIR "Data\\imported\\locations.txt"
	#define CUSTOMER_BIN_DIR "Data\\saved\\locations.txt"

	/***** Data type definitions *****/

	/*	- Save Vertexs Graph to text sample -
	*	Lisboa;Braga;Porto;Leiria (All the vertexes first)
	* 
	*	Lisboa; (vertex and adjancencies below)
	*	Braga;443; (Their adjacencies)
	*	Porto;98
	*	
	*	Leiria;
	*	Lisboa;30
	*/

	/**
	 * - Save Vertexs Graph to Binary sample -
	 * Number of Vertex
	 * (all the vertex)
	 * Number of Vertexes with Adjancencies
	 * (For each vertex) {
	 *	 Number of Adjancencies of the Vertex
	 *	 (It's Adjancencies)
	 * }
	 */

	typedef struct Vertex Vertex;
	typedef struct Adj Adj;

	typedef struct {
		int code;				  // vertex code
		char name[LOCATION_SIZE]; // geocode
	} VertexValues;

	// Vertex vertex
	struct Vertex {
		VertexValues values;
		Vertex* next;
		Adj* adjacency;
	};

	// Vertex Edge
	struct Adj {
		float weight; // Edge Weight
		Adj* next;
		Vertex* vertex;
	};

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
	int AddEdge(Vertex* srcVertex, Vertex* destVertex, int weight);

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
	int AddEdgeByName(Vertex* graph, char* srcVertex, char* destVertex, int weight);

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
	 * @brief Counts the number of vertices.
	 *
	 * @param Graph
	 * @param File directory
	 * @return Number os vertices
	 */
	int CountVertices(Vertex* graph);

#endif