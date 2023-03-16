/*****************************************************************//**
 * @file   Manager.h
 * @brief  Manager structure and functions signature
 *
 * @author Francisco
 * @date   March 2023
 *********************************************************************/

#include <stdlib.h>
#include <stdbool.h>

#ifndef MANAGER_H_
#define MANAGER_H_

	#define NAME_SIZE 40
	#define EMAIL_SIZE 60
	#define PASSWORD_SIZE 30
	#define ADRESS_SIZE 80

	typedef struct {
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
	 * Appends a new Manager to the linked list.
	 *
	 * @param List Head
	 * @param Manager to insert
	 * @return true - Added Successfully
	 * @return false - Error allocating memory
	 */
	bool AddManager(ManagerList** head, Manager sourceManager);

	/**
	 * Gets the Manager pointer in a linked list by its index.
	 *
	 * @param List head
	 * @param Manager index
	 * @return Manager pointer with the specified index
	 */
	ManagerList* GetManager(ManagerList* head, int index);

#endif