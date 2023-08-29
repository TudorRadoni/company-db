//
// database.c
// This source file is part of the ComRecord application.
// It contains functions which work with files.
//
// Author: Tudor - Calin Radoni
// Version: 1.0
// Copyright (C) 2020 Tudor - Calin Radoni
//

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#include "database.h"
#include "recordlist.h"

/**
 * @brief Buffer which is used when reading from file.
 */
char record_buf[MAX_LINE_LENGTH];

/**
 * @brief Creates a record from a line read from the file.
 *
 * This function is called by readDatabase after each read line.
 */
bool lineToPerson()
{
    Person ps;
    initializePerson(&ps);

    char *token;
    token = strtok(record_buf, ",");
    if (token != NULL)
        strncpy(ps.firstName, token, MAX_FNAME_LENGTH);
    token = strtok(NULL, ",");
    if (token != NULL)
        strncpy(ps.lastName, token, MAX_LNAME_LENGTH);
    token = strtok(NULL, ",");
    if (token != NULL)
        strncpy(ps.city, token, MAX_ADDRESS_LENGTH);
    token = strtok(NULL, ",");
    if (token != NULL)
        ps.age = atoi(token);
    token = strtok(NULL, ",");
    if (token != NULL)
        ps.salary = atoi(token);

    addPerson(&ps);

    return true;
}

/***************************************************************
 * @brief Reads all the lines from file and creates records.
 *
 * @param filename Represents the name of the file which must be
 *                 opened for reading.
 */
bool readDatabase(char *filename)
{
    if (filename == NULL)
        return false;

    FILE *input_file = NULL;
    input_file = fopen(filename, "r");

    if (input_file == NULL)
        return false;

    bool done = false;
    bool err = false;
    while (!done)
    {
        if (fgets(record_buf, MAX_LINE_LENGTH, input_file) != NULL)
        {
            // process record_buf
            lineToPerson();
        }
        else
        {
            done = true;
            err = !feof(input_file);
        }
    }
    fclose(input_file);

    return !err;
}

/***************************************************************
 * @brief Adds a record from user input.
 **************************************************************/
bool stdinToPerson()
{
    // From keyboard to Person
    Person ps;
    initializePerson(&ps);

    char buffer[30];
    printf("First name: ");
    scanf("%s", buffer);
    strncpy(ps.firstName, buffer, MAX_FNAME_LENGTH);

    printf("Last name: ");
    scanf("%s", buffer);
    strncpy(ps.lastName, buffer, MAX_LNAME_LENGTH);

    printf("City: ");
    scanf("%s", buffer);
    strncpy(ps.city, buffer, MAX_ADDRESS_LENGTH);

    int buffer_int;
    printf("Age: ");
    scanf("%d", &buffer_int);
    ps.age = buffer_int;

    printf("Salary: ");
    scanf("%d", &buffer_int);
    ps.salary = buffer_int;

    addPerson(&ps);

    return true;
}

/***************************************************************
 * @brief Converts a record to a line.
 **************************************************************/
bool personToLine(Person *ps)
{
    if (ps == NULL)
        return false;
    int res = snprintf(record_buf, MAX_LINE_LENGTH, "%s,%s,%s,%d,%d\n",
                       ps->firstName,
                       ps->lastName,
                       ps->city,
                       ps->age,
                       ps->salary);
    if (res < 0)
        return false;
    if (res >= MAX_LINE_LENGTH)
        return false;
    return true;
}

/***************************************************************
 * @brief Saves the database to file.
 **************************************************************/
bool saveDatabase(char *filename)
{
    if (filename == NULL)
        return false;

    FILE *output_file = NULL;
    output_file = fopen(filename, "w");
    if (output_file == NULL)
        return false;

    Person *node;
    node = head;
    while (node != NULL)
    {
        if (personToLine(node))
        {
            fputs(record_buf, output_file);
        }
        node = node->next;
    }

    fclose(output_file);
    return true;
}
