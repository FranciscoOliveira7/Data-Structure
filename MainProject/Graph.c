/*****************************************************************//**
 * @file   Graph.c
 * @brief  Graph structure functions
 *
 * @author Francisco
 * @date   March 2023
 *********************************************************************/

#include "Graph.h"

Vertex* CreateGraph() {

	Vertex* graph = (Vertex*)malloc(sizeof(Vertex));

	if (graph == NULL) {
		free(graph);
		return NULL;
	}

	graph = NULL;
	return graph;
}