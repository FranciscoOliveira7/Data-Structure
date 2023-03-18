/*****************************************************************//**
 * @file   Consts.h
 * @brief  Global Constants definition & other aspects
 *
 * @author Francisco
 * @date   March 2023
 *********************************************************************/

#ifndef CONSTS_H_
#define CONSTS_H_

	#pragma warning(disable : 4996)

	#define str(x) #x
	#define xstr(x) str(x)

	// Default libraries
	#include <stdlib.h>
	#include <stdio.h>
	#include <stdbool.h>

	// All string sizes
	#define NAME_SIZE 40
	#define NIF_SIZE 15

	#define EMAIL_SIZE 60
	#define PASSWORD_SIZE 30

	#define ADRESS_SIZE 80
	#define LOCATION_SIZE 80

#endif