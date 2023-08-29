/* *******************************************************/
/*  operations.h - Header file for module operations     */
/*                                                       */
/*   Author: Dicu Maria-Floriana                         */
/*   Version: 1.0                                        */
/*   Copyright (C) 2020 Dicu Maria-Floriana              */
/*                                                       */
/* *******************************************************/


#ifndef operations_h
#define operations_h

#include <stdio.h>

#include "recordlist.h"

/* Function prototypes: */

void searchFirstName(char *first_name);
void searchLastName(char *last_name);
void searchCity(char *city);
void searchSalary(int salary);

void searchAge(int age);
bool deleteByAge(int age);
int deleteAllByAge(int age);

#endif /* operations_h */
