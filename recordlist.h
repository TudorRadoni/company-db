/* *******************************************************/
/*  recordlist.h - Header file for module recordlist     */
/*                                                       */
/*   Author: Dicu Maria-Floriana                         */
/*   Version: 1.0                                        */
/*   Copyright (C) 2020 Dicu Maria-Floriana              */
/*                                                       */
/* *******************************************************/


#ifndef recordlist_h
#define recordlist_h

#include <stdio.h>
#include <stdlib.h>

/*
 * Constants definitions:
 *
 * These constants hold the maximum length for (in order):
 * - the first name of the person
 * - the last name of the person
 * - the address of residence
 */
#define MAX_FNAME_LENGTH 30
#define MAX_LNAME_LENGTH 20
#define MAX_ADDRESS_LENGTH 25

/*
 * Record structure
 *
 * The "Person" structure can store information about:
 * - an employee's first and last name
 * - the address of residence
 * - the birth date
 * - the salary
 */
typedef struct person {
    char firstName[MAX_FNAME_LENGTH];
    char lastName[MAX_LNAME_LENGTH];
    char city[MAX_ADDRESS_LENGTH];
    int age;
    int salary;

    struct person *next;
} Person;

/*
 * Pointer to the head of the list
 */
extern Person *head;

/* Function prototypes: */

void initializePerson(Person *ps);
void addPerson(Person *in);
void removePerson(char *last_name);
void printPerson(Person *ps);
void printList(void);
void freeList(void);
int getRecordCount(void);

#endif /* recordlist_h */
