/*****************************************************************//**
 * @file   Graph.h
 * @brief  
 * 
 * @author Francisco
 * @date   April 2023
 *********************************************************************/
#include <stdbool.h>

#ifndef _STRUCTS_H
#define _STRUCTS_H

	#define LOCATION_SIZE 20

	typedef struct {
		char location[LOCATION_SIZE];

	} Vertex;

	#define MAX_VERTEXS 10

	bool CreateGraph(Vertex vertexes[], int nVertexs);

	bool AddVertex(Vertex);

#endif