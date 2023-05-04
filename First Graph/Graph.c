/*****************************************************************//**
 * @file   Graph.c
 * @brief  Non oriented weighted graph implementation
 * 
 * @author Francisco
 * @date   April 2023
 *********************************************************************/

#include "Graph.h"

bool CreateGraph(Vertex vertexes, int nVertexes) {
	if (nVertexes > MAX_VERTEXS) return false;

	for (int i = 0; i < nVertexes; i++)
	{
		vertexes[i] = i;

	}
}