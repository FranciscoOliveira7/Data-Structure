/*****************************************************************//**
 * @file   Path.c
 * @brief  Path structure functions
 *
 * @author Francisco
 * @date   March 2023
 *********************************************************************/

#include "Path.h"

/**
 * @author Francisco
 *
 * @brief Allocates a new PathList o memory.
 *
 * @param Vertex id
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
	newPath->previous = NULL;

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
bool PushPath(Path** head, Path* sourcePath) {

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
	sourcePath->previous = last;
	return true;
}

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
bool PopPath(Path** head) {

	if (*head == NULL) return false;

	if ((*head)->next == NULL) {
		free(*head);
		*head = NULL;
	}
	else {
		Path* current = *head;
		Path* previous = current;

		while (current->next != NULL) {
			previous = current;
			current = current->next;
		}

		free(current);
		previous->next = NULL;
	}

	return true;
}

/**
 * @author Francisco
 *
 * @brief Shows the last Path in the stack.
 *
 * @param Path List head
 * @return true - Poped Successfully
 * @return false - Path is already Empty
 */
Path* TopPath(Path* head) {

	Path* current = head;

	while (current->next != NULL) current = current->next;

	return current;
}

/**
 * @author Francisco
 *
 * @brief Copies path to a new space in memory.
 *
 * @param Original path
 * @return true - New path
 */
Path* CopyPath(Path* original) {

	Path* currentO = original;
	Path* newpath = NULL;

	while (currentO != NULL) {

		PushPath(&newpath, CreatePath(currentO->vertex));

		currentO = currentO->next;
	}

	return newpath;
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