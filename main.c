#include <stdio.h>
#include <stdlib.h>

#include <string.h>
#include <stdbool.h>

#include "recordlist.h"
#include "database.h"
#include "operations.h"
#include "test.h"

const char *menu = "\
\n  -----------------------------------\n\
 | Options:                          |\n\
 |    1. Print Database              |\n\
 |    2. Search Person               |\n\
 |    3. Add Person From Keyboard    |\n\
 |    4. Remove Person From Database |\n\
 |    5. Delete all by age           |\n\
 |    6. Do a test run               |\n\
 |    7. Exit                        |\n\
  -----------------------------------\n\
   Choice: ";

const char *searchMenu = "\
\n   ----------------------------------\n\
 | Search by:                        |\n\
 |      1. First name                |\n\
 |      2. Last name                 |\n\
 |      3. City                      |\n\
 |      4. Age                       |\n\
 |      5. Salary                    |\n\
 |      6. Back                      |\n\
  -----------------------------------\n\
   Choice: ";

int main() {
    puts("\n\t~ Welcome to ComRecord! ~\n");

    // Reading the name of the database
    char filename[MAX_FILENAME_LENGTH];
    puts("Filename? ");
    scanf("%s", filename);

    // Opening and storing database to list
    if (!readDatabase(filename)) {
        return 1;
    }

    // Starting the work with the menu
    int choice = 0;
    bool run = true;

    char char_buffer[MAX_FNAME_LENGTH];
    int int_buffer;

    while (run) {
        printf("%s", menu);
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                // Printing list
                printf("\n\tThis is the list:\n");
                printf("====================================\n");
                printList();
                printf("====================================\n");
                break;
            case 2:
                //Search person by first name, last name, city, age, salary
                printf("%s", searchMenu);
                scanf("%d", &choice);

                switch(choice) {
                    case 1:
                        // Search person by first name
                        printf("\nEnter first name: ");
                        scanf("%s", char_buffer);
                        printf("\nThese are the results of your search:\n");
                        searchFirstName(char_buffer);
                        break;
                    case 2:
                        // Search person by last name
                        printf("\nEnter last name: ");
                        scanf("%s", char_buffer);
                        printf("\nThese are the results of your search:\n");
                        searchLastName(char_buffer);
                        break;
                    case 3:
                        // Search person by city
                        printf("\nEnter city: ");
                        scanf("%s", char_buffer);
                        printf("\nThese are the results of your search:\n");
                        searchCity(char_buffer);
                        break;
                    case 4:
                        // Search person by age
                        printf("\nEnter age: ");
                        scanf("%d", &int_buffer);
                        printf("\nThese are the results of your search:\n");
                        searchAge(int_buffer);
                        break;
                    case 5:
                        // Search person by salary
                        printf("\nEnter salary: ");
                        scanf("%d", &int_buffer);
                        printf("\nThese are the results of your search:\n");
                        searchSalary(int_buffer);
                        break;
                    case 6:
                        break;
                    default:
                        printf("Invalid option \"%d\"!\n", choice);
                }
                break;
            case 3:
                // Adding person from keyboard
                stdinToPerson();
                printf("\nSuccessfully added!\n");
                break;
            case 4:
                // Removing last_name from list
                printf("Who is the person you want to remove?\n(Last name): ");
                scanf("%s", char_buffer);
                removePerson(char_buffer);
                break;
            case 5:
                // Deleting the persons with the same age
                printf("Enter the age: ");
                scanf("%d", &int_buffer);
                printf("\nSuccessfully deleted %d people!\n", deleteAllByAge(int_buffer));
                break;
            case 6:
                // RUNNING SOME TESTS
                // Saving database before starting tests
                saveDatabase(filename);

                // Running the tests
                test_run();

                // Reloading database into memory
                readDatabase(filename);
                break;
            case 7:
                printf("\nExiting!\n");
                saveDatabase(filename);
                freeList();
                run = false;
                break;
            default:
                printf("Invalid option \"%d\"!\n", choice);
        }
    }
    return 0;
}
