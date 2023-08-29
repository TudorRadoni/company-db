/* **********************************************************/
/*  recordlist.c - See recordlist.c for copyright and info  */
/* **********************************************************/


#include <string.h>

#include "recordlist.h"

/*
 * Pointer to the head of the list
 */
Person *head = NULL;

/* ***************************************************************************/
/* FUNCTION NAME: initializePerson                                           */
/*                                                                           */
/* DESCRIPTION: This function initializes fields with known values, so that  */
/* no random values appear throughout the database.                          */
/*                                                                           */
/* DEFAULTS:                                                                 */
/* - strings and numbers: 0                                                  */
/* - pointers: NULL                                                          */
/*                                                                           */
/* ARGUMENT:                                                                 */
/* - ps->refers to the person which needs to be initialized.                 */
/* ***************************************************************************/

void initializePerson(Person *ps)
{
    memset(ps->firstName, 0, MAX_FNAME_LENGTH);
    memset(ps->lastName, 0, MAX_LNAME_LENGTH);
    memset(ps->city, 0, MAX_ADDRESS_LENGTH);
    ps->age = 0;
    ps->salary = 0;
    ps->next = NULL;
}

/*****************************************************************************/
/* FUNCTION NAME: addPerson                                                  */
/*                                                                           */
/* DESCRIPTION: This function adds a person at the beginning of the list.    */
/*                                                                           */
/* ARGUMENT:                                                                 */
/* - in->represents input data                                               */
/* ***************************************************************************/

void addPerson(Person *in)
{
    Person *node;
    node = (Person*)malloc(sizeof(Person));

    strncpy(node->firstName, in->firstName, MAX_FNAME_LENGTH);
    strncpy(node->lastName, in->lastName, MAX_LNAME_LENGTH);
    strncpy(node->city, in->city, MAX_ADDRESS_LENGTH);
    node->age = in->age;
    node->salary = in->salary;

    node->next = head;
    head = node;
}

/* ****************************************************************************/
/* FUNCTION NAME: removePerson                                                */
/*                                                                            */
/* DESCRIPTION: Given a last name, this function deletes the first occurrence */
/* of the last name in the list. If no occurrence of the last name is found,  */
/* nothing happens.                                                           */
/*                                                                            */
/* ARGUMENT:                                                                  */
/* - last_name->is contained in the record that will be removed               */
/* ****************************************************************************/

void removePerson(char *last_name)
{
    Person *node = head;
    Person *prev = NULL;

    // If the list is empty
    if (head == NULL) return;

    // If head has last_name which must be removed
    if (strcmp(head->lastName, last_name) == 0) {
        head = head->next;
        free(node);
        return;
    }

    // Searching for last_name, keeping track of the prev node
    while ((node != NULL) && (strcmp(node->lastName, last_name) != 0)) {
        prev = node;
        node = node->next;
    }

    // If last_name was not present in linked list
    if (node == NULL) return;

    // Unlink the node from linked list
    prev->next = node->next;
    free(node);
}

/* ***********************************************************/
/* FUNCTION NAME: printPerson                                */
/*                                                           */
/* DESCRIPTION: Prints the given record.                     */
/*                                                           */
/* ARGUMENT:                                                 */
/* - ps->refers to the person which will be printed          */
/* ***********************************************************/

void printPerson(Person *ps) {
    if (ps == NULL) return;
    printf("\nFirst Name : %s\n", ps->firstName);
    printf("Last Name : %s\n", ps->lastName);
    printf("City : %s\n", ps->city);
    printf("Age : %d\n", ps->age);
    printf("Salary : %d\n\n", ps->salary);
}

/* **********************************************************/
/* FUNCTION NAME: printList                                 */
/*                                                          */
/* DESCRIPTION: Prints the whole list.                      */
/*                                                          */
/* ARGUMENT:                                                */
/*  -                                                       */
/* **********************************************************/

void printList()
{
    Person *node;
    node = head;
    while (node != NULL) {
        printPerson(node);
        node = node->next;
    }
}

/* *******************************************************************/
/* FUNCTION NAME: freeList                                           */
/*                                                                   */
/* DESCRIPTION: Deallocates the memory in which the list is stored.  */
/*                                                                   */
/* ARGUMENT:                                                         */
/*  -                                                                */
/* *******************************************************************/

void freeList()
{
    Person *node;
    while (head != NULL) {
        node = head;
        head = head->next;
        free(node);
    }
}

/* **********************************************************/
/* FUNCTION NAME: getRecordCount                            */
/*                                                          */
/* DESCRIPTION: counts the numbers of records in the list.  */
/*                                                          */
/* ARGUMENT:                                                */
/*  -                                                       */
/* **********************************************************/

int getRecordCount() {
    Person *node = head;
    int cnt = 0;
    while(node != NULL) {
        cnt++;
        node = node->next;
    }
    return cnt;
}
