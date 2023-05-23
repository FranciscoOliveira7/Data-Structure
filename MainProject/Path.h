/*****************************************************************//**
 * @file   Path.h
 * @brief  Path structure and functions signature
 *
 * @author Francisco
 * @date   March 2023
 *********************************************************************/

#include "Consts.h"

#ifndef PATH_H_
#define PATH_H_

	typedef struct Path Path;
	typedef struct PathList PathList;

	struct Path {
		int vertex;
		Path* previous; // Previous Vertex of the path
		Path* next;		// Next Vertex of the path
	};

	struct PathList {
		int vertex;
		float distance; // Total weigth of the path
		Path* path;
		PathList* next;
	};

	#define BIG_NUMBER 100000

	 /***** All function signatures *****/

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
	bool PushPath(Path** head, Path* sourcePath);

	/**
	 * @author Francisco
	 *
	 * @brief Remove a Path from the linked list.
	 *
	 * @param List head
	 * @param Path to remove
	 * @return true - Poped Successfully
	 * @return false - Path is already Empty
	 */
	bool PopPath(Path** head);

	/**
	 * @author Francisco
	 *
	 * @brief Shows the last Path in the stack.
	 *
	 * @param Path List head
	 * @return true - Poped Successfully
	 * @return false - Path is already Empty
	 */
	Path* TopPath(Path* head);

	/**
	 * @author Francisco
	 *
	 * @brief Copies path to a new space in memory.
	 *
	 * @param Original path
	 * @return true - New path
	 */
	Path* CopyPath(Path* original);

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