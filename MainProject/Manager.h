/*****************************************************************//**
 * @file   Manager.h
 * @brief  Manager structure and functions signature
 *
 * @author Francisco
 * @date   March 2023
 *********************************************************************/

#pragma warning(disable : 4996)

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#ifndef MANAGER_H_
#define MANAGER_H_

	#define MANAGER_TEXT_DIR "Data\\imported\\managers.txt"
	#define MANAGER_BIN_DIR "Data\\saved\\managers.txt"

	#define NAME_SIZE 40
	#define EMAIL_SIZE 60
	#define PASSWORD_SIZE 30

	typedef struct {
		int id;
		char name[NAME_SIZE];
		char email[EMAIL_SIZE];
		char password[PASSWORD_SIZE];
	} Manager;

	typedef struct ManagerList ManagerList;
	struct ManagerList {
		Manager manager;
		ManagerList* next;
	};

	/**
	 * @author Francisco
	 *
	 * @brief Appends a new Manager to the linked list.
	 *
	 * @param List Head
	 * @param Manager to insert
	 * @return true - Added Successfully
	 * @return false - Error allocating memory
	 */
	bool AddManager(ManagerList** head, Manager sourceManager);

	/**
	 * @author Francisco
	 *
	 * @brief Gets the Manager pointer in a linked list by its index.
	 *
	 * @param List head
	 * @param Manager index
	 * @return Manager pointer with the specified index
	 * @return NULL if the list is empty
	 */
	ManagerList* GetManager(ManagerList* head, int index);

	/**
	 * @author Francisco
	 *
	 * @brief Reads all the managers from a file into a list.
	 *
	 * @param List Head
	 * @param File directory
	 * @return 1 - Readed Successfully
	 * @return 2 - Error opening file
	 * @return 3 - Error on sscanf
	 */
	int ReadManagersFile(ManagerList** head, char* fileName);

	/**
	 * @author Francisco
	 *
	 * @brief Saves all the managers from a list into a file.
	 *
	 * @param List Head
	 * @param File directory
	 * @return 1 - Saved Successfully
	 * @return 2 - Error opening file
	 * @return 3 - The list is empty
	 */
	int SaveManagersAsFile(ManagerList* head, char* fileName);

#endif