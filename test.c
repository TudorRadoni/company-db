//
// test.c
// This source file is part of the ComRecord application.
// It contains functions which are used to test the application.
//
// Author: Tudor - Calin Radoni
// Version: 1.0
// Copyright (C) 2020 Tudor - Calin Radoni
//

#include <time.h>
#include <string.h>

#include "test.h"
#include "database.h"

/**
 * @brief Number of names and cities in the following pools of names and cities.
 */
const int rnd_data_cnt = 10;

/**
 * @brief Pools of names and cities.
 *
 * These are three arrays of strings, containing:
 * - first names
 * - last names
 * - cities
 *
 * They are used for generating random records.
 */
const char *test_first_name[] = { "James", "William", "Tyler", "David", "Michael", "Susan", "Lily", "Madison", "Jennifer", "Amy" };
const char *test_last_name[] = { "Smith", "Johnson", "Anderson", "Moore", "Jackson", "Lopez", "Lee", "Clark", "Robinson", "Young" };
const char *test_city[] = { "Chicago", "Boston", "Seattle", "Austin", "Detroit", "Denver", "Dallas", "Philadelphia", "Houston", "Portland" };

/*****************************************************************
 * @brief Adds a random record.
 *
 * This function creates a random record and adds it to the list.
 ****************************************************************/
void test_addRandomRecord() {
    Person ps;
    int idx = rand() % rnd_data_cnt;

    strncpy(ps.firstName, test_first_name[idx], MAX_FNAME_LENGTH);
    idx = rand() % rnd_data_cnt;
    strncpy(ps.lastName, test_last_name[idx], MAX_LNAME_LENGTH);
    idx = rand() % rnd_data_cnt;
    strncpy(ps.city, test_city[idx], MAX_ADDRESS_LENGTH);
    idx = rand() % rnd_data_cnt;
    ps.age = rand() % 200;
    ps.salary = rand() % 2000;

    addPerson(&ps);
}

/*****************************************************************
 * @brief Adds a random number of records.
 *
 * This function calls the above function ('test_addRandomRecord')
 * a random amount of times, adding that many random records.
 ****************************************************************/
bool test_addRndCntRecords() {
    int cnt_start = getRecordCount();
    int cnt_new = 5 + rand() % 20;

    printf("Adding %d records ... ", cnt_new);

    for (int i = 0; i < cnt_new; ++i) {
        test_addRandomRecord();
    }
    int cnt_end = getRecordCount();

    if (cnt_new != (cnt_end - cnt_start + 1)) {
        printf("Successfully added %d records.\n\n", cnt_new);
        return true;
    }
    else {
        printf("Failed!\n\n");
        return false;
    }
}

/*****************************************************************
 * @brief Deletes the first record.
 *
 * This function deletes the first record from the list and
 * verifies if it has been successfully removed.
 *
 * @warning the first record has been chosen as it is the
 *          head of the list and it is treated separately.
 ****************************************************************/
bool test_delFirstRecord() {
    if (head == NULL) return false;

    printf("Deleting first record ...\n");
    compact_print(head);
    compact_print(head->next);

    char *last_name = head->lastName;
    Person *saved = head->next;
    removePerson(last_name);

    printf("After removal:\n");
    compact_print(head);

    if (saved == head) {
        printf("Done.\n\n");
        return true;
    }
    else {
        printf("Failed!\n\n");
        return false;
    }
}

/*****************************************************************
 * @brief Deletes the third record.
 *
 * This function deletes the third record from the list and
 * verifies if it has been successfully removed.
 *
 * @warning the third record does not represent anything, it has
 *          been arbitrarily chosen.
 ****************************************************************/
bool test_delThirdRecord() {
    if(getRecordCount() < 4) return false;

    printf("Deleting third record ...\n");
    compact_print(head);
    compact_print(head->next);
    compact_print(head->next->next);
    compact_print(head->next->next->next);

    char *last_name = head->next->next->lastName;
    Person *saved = head->next->next->next;
    removePerson(last_name);

    printf("After removal:\n");
    compact_print(head);
    compact_print(head->next);
    compact_print(head->next->next);

    if (saved == head->next->next) {
        printf("Done.\n\n");
        return true;
    }
    else {
        printf("Failed!\n\n");
        return false;
    }
}

/*****************************************************************
 * @brief Tests if database has been saved correctly.
 *
 * This function saves the database, frees the list from the
 * memory and then reloads the database back into the memory,
 * testing if the record count is the same.
 ****************************************************************/
bool test_saveDatabase() {
    int cnt_start = getRecordCount();

    saveDatabase("testdb.csv");
    freeList();
    readDatabase("testdb.csv");

    int cnt_new = getRecordCount();

    if(cnt_start != cnt_new) {
            printf("Database save failed!\n");
            return false;
    }
    else {
        printf("Database saved correctly.\n");
        return true;
    }
}

/*****************************************************************
 * @brief Runs all the tests.
 ****************************************************************/
void test_run() {
    srand(time(NULL));

    freeList();

    test_addRndCntRecords();

    printList();

    test_delFirstRecord();

    test_delThirdRecord();

    test_saveDatabase();

    freeList();
}

/*****************************************************************
 * @brief Prints a record in a compact way.
 *
 * @param ps Refers to the record which will be printed.
 ****************************************************************/
void compact_print(Person *ps)
{
    if (ps == NULL) {
        printf("NULL record!");
        return;
    }
    printf("compact_print : %s %s (age: %d), %s, %d\n", ps->firstName, ps->lastName, ps->age, ps->city, ps->salary);
}
