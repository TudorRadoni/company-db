/* **********************************************************/
/*  operations.c - See operations.c for copyright and info  */
/* **********************************************************/

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#include "recordlist.h"
#include "operations.h"

/* ********************************************************************/
/* FUNCTION NAME: searchFirstName                                     */
/*                                                                    */
/* DESCRIPTION: Prints all the records with specified first name.     */
/*                                                                    */
/* ARGUMENT:                                                          */
/* - first_name->refers to the first name of the person you want      */
/*               to find                                              */
/* ********************************************************************/

void searchFirstName(char *first_name) {
    Person *node = head;

    while (node != NULL) {
        if (strcmp(node->firstName, first_name) == 0) {
            printPerson(node);
        }
        node = node->next;
    }

}
/* *******************************************************************/
/* FUNCTION NAME: searchLastName                                     */
/*                                                                   */
/* DESCRIPTION: Prints all the records with specified last name.     */
/*                                                                   */
/* ARGUMENT:                                                         */
/* - last_name->refers to the last name of the person you want       */
/*               to find                                             */
/* *******************************************************************/

void searchLastName(char *last_name) {
    Person *node = head;

    while (node != NULL) {
        if (strcmp(node->lastName, last_name) == 0) {
            printPerson(node);
        }
        node = node->next;
    }

}

/* *******************************************************************/
/* FUNCTION NAME: searchCity                                         */
/*                                                                   */
/* DESCRIPTION: Prints all the records with specified city.          */
/*                                                                   */
/* ARGUMENT:                                                         */
/* - city->refers to the city of the person you want to find         */
/* *******************************************************************/

void searchCity(char *city) {
    Person *node = head;

    while (node != NULL) {
        if (strcmp(node->city, city) == 0) {
            printPerson(node);
        }
        node = node->next;
    }

}

/* ********************************************************************/
/* FUNCTION NAME: searchAge                                           */
/*                                                                    */
/* DESCRIPTION: Prints all the records with specified age.            */
/*                                                                    */
/* ARGUMENT:                                                          */
/* - age->refers to the age of the person you want to find            */
/* ********************************************************************/

void searchAge(int age) {
    Person *node = head;

    while (node != NULL) {
        if (node->age == age) {
            printPerson(node);
        }
        node = node->next;
    }
}

/* ********************************************************************/
/* FUNCTION NAME: searchSalary                                        */
/*                                                                    */
/* DESCRIPTION: Prints all the records with specified salary.         */
/*                                                                    */
/* ARGUMENT:                                                          */
/* - salary->refers to the salary of the person you want to find      */
/* ********************************************************************/

void searchSalary(int salary) {
    Person *node = head;

    while (node != NULL) {
        if (node->salary == salary) {
            printPerson(node);
        }
        node = node->next;
    }
}

/* ********************************************************************/
/* FUNCTION NAME: deleteByAge                                         */
/*                                                                    */
/* DESCRIPTION: Deletes first record containing age in list.          */
/*                                                                    */
/* ARGUMENT:                                                          */
/* - age->refers to the age of the person you want to delete.         */
/* ********************************************************************/

bool deleteByAge(int age) {
    Person *node = head;
    Person *prev = NULL;


    // If the list is empty
    if (head == NULL) return false;

    // If head must be removed
    if (head->age == age) {
        head = head->next;
        free(node);
        return true;
    }

    // Searching for age, keeping track of the prev node
    while ((node != NULL) && (node->age != age)) {
        prev = node;
        node = node->next;
    }

    // If age was not present in linked list
    if (node == NULL) return false;

    // Unlink the node from linked list
    prev->next = node->next;
    free(node);
    return true;
}

/* ********************************************************************/
/* FUNCTION NAME: deleteAllByAge                                      */
/*                                                                    */
/* DESCRIPTION: Deletes all records which have age.                   */
/*                                                                    */
/* ARGUMENT:                                                          */
/* - age->refers to the age of the person you want to delete.         */
/* ********************************************************************/

int deleteAllByAge(int age) {
    int cnt = 0;
    bool res = true;
    while (res) {
        res = deleteByAge(age);
        if (res) {
            cnt++;
        }
    }
    return cnt; // returns how many records have been deleted
}
