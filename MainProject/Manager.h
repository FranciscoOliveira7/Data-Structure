/*****************************************************************//**
 * @file   Manager.h
 * @brief  Manager structure and functions signature
 *
 * @author Francisco
 * @date   March 2023
 *********************************************************************/

#include "Consts.h"

#ifndef MANAGER_H_
#define MANAGER_H_

	#define MANAGER_TEXT_DIR "Data\\imported\\managers.txt"
	#define MANAGER_BIN_DIR "Data\\saved\\managers.txt"

	typedef struct {
		int id;
		char name[NAME_SIZE];
		char email[EMAIL_SIZE];
		char password[PASSWORD_SIZE];
	} Manager;

	typedef struct ManagerList ManagerList;
	struct ManagerList {
		Manager manager;
		ManagerList* previous;
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
	 * @brief Remove a Manager from the linked list.
	 *
	 * @param List head
	 * @param Manager to remove
	 * @return true - Removed Successfully
	 * @return false - Manager doen't exist
	 */
	bool RemoveManager(ManagerList** head, ManagerList* sourceManager);

	/**
	 * @author Francisco
	 *
	 * @brief Wipe a Managers linked list from memory.
	 *
	 * @param List head
	 * @return true - List wiped Successfully
	 * @return false - List is already empty
	 */
	bool WipeManagers(ManagerList** head);

	/**
	 * @author Francisco
	 *
	 * @brief Sort Managers by id.
	 *
	 * @param List head
	 * @return true - Sorted Successfully
	 * @return false - Manager doen't exist
	 */
	bool SortManagersById(ManagerList* head);

	/**
	 * @author Francisco
	 *
	 * @brief Swaps between two Managers from linked list.
	 *
	 * @param Manager 1
	 * @param Manager 2
	 */
	void SwapManager(ManagerList* manager1, ManagerList* manager2);

	/**
	 * @author Francisco
	 *
	 * @brief Edits a Manager from the linked list.
	 *
	 * @param Manager to edit
	 * @param New Manager
	 * @return true - Edited Successfully
	 * @return false - Manager doen't exist
	 */
	bool EditManager(ManagerList* manager, Manager newManager);

	/**
	 * @author Francisco
	 *
	 * @brief Finds manager by its id.
	 *
	 * @param List Head
	 * @param Manager id
	 * @return Manager pointer with the specified id
	 * @return NULL if not found
	 */
	ManagerList* FindManager(ManagerList* head, int id);

	/**
	 * @author Francisco
	 *
	 * @brief Gets the Manager pointer in a linked list by its index.
	 *
	 * @param List head
	 * @param Manager index
	 * @return Manager pointer with the specified index
	 * @return NULL if not found
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
	int ReadManagersFile(ManagerList** head, const char* fileName);

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
	int SaveManagersAsFile(ManagerList* head, const char* fileName);

#endif