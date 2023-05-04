/*****************************************************************//**
 * @file   Graph.h
 * @brief  Oriented Weighted Graph implementation
 *
 * @author Francisco
 * @date   March 2023
 *********************************************************************/

#include "Consts.h"

#ifndef GRAPH_H_
#define GRAPH_H_

	/***** Data type definitions *****/

	/*	- Save Vertexs Graph to text sample -
	*	Lisboa;Braga;Porto;Leiria (All the vertexes first)
	* 
	*	Lisboa;Braga;443;Porto;98 (Their adjacencies)
	*	Leiria;Lisboa;30
	*/

	// Vertex vertex
	typedef struct Vertex Vertex;
	struct Vertex {
		int code;   // vertex code
		char* name; // geocode
		Vertex* next;
		Adj* adjacency;
	};

	// Vertex Edge
	typedef struct Adj Adj;
	struct Adj {
		int code;
		int weight; // Edge Weight
		Adj* next;
		Vertex* vertex;
	};

#endif