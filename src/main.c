#include "../include/database.h"
#include "../include/group.h"
#include "../include/student.h"
#include <stdio.h>

// I never tried this project but it have a good structure
// These functions call the appropriate functions
// It's like abstraction
void createGroups(sqlite3* db);
void listGroups(sqlite3* db);
void deleteGroup(sqlite3* db);
void viewGroupDetails(sqlite3* db);
void transferStudents(sqlite3* db);
void addStudent(sqlite3* db);
void updateStudentInfo(sqlite3* db);
void deleteStudent(sqlite3* db);
void listStudents(sqlite3* db);

int main() {
    // Create or open the database
    const char* dbName = "../db/student_manager.db";
    sqlite3* db = openOrCreateDatabase(dbName);

    if (db != NULL) {
        printf("Database opened or created successfully.\n");

        while (1) {
            printf("Welcome! What would you like to do today?\n");
            printf("1. Create groups\n");
            printf("2. List groups\n");
            printf("3. Delete group\n");
            printf("4. View group details\n");
            printf("5. Transfer students\n");
            printf("6. Add student\n");
            printf("7. Update student info\n");
            printf("8. Delete student\n");
            printf("9. List students\n");
            printf("0. Exit\n");
            printf("Enter your choice: ");

            int choice;
            scanf("%d", &choice);

            switch (choice) {
                case 1:
                    createGroups(db);
                    break;
                case 2:
                    listGroups(db);
                    break;
                case 3:
                    deleteGroup(db);
                    break;
                case 4:
                    transferStudents(db);
                    break;
                case 5:
                    addStudent(db);
                    break;
                case 6:
                    viewStudentDetails(db);
                    break;
                case 7:
                    updateStudentInfo(db);
                    break;
                case 8:
                    deleteStudent(db);
                    break;
                case 9:
                    listStudents(db);
                    break;
                case 0:
                    sqlite3_close(db);
                    return 0;
                default:
                    printf("Invalid choice. Please try again.\n");
            }

            printf("\n");
        }
    } else {
        printf("Failed to open or create the database.\n");
    }

    return 0;
}

void createGroups(sqlite3* db) {
    printf("Name of the group: \n");
    char group[100];
    scanf("%s", group);

    char** cols = NULL;
    char answer;
    int size = 0;
    while(1) {
        size++;
        cols = (char**)realloc(cols, size * sizeof(char*));
        printf("Name of the column: \n");
        char col[100];
        scanf("%s", col);
        cols[size-1] = strdup(col); // Allocate memory and copy the column name
        printf("Do you want to add another column? (yes = Y, no = N): \n");
        scanf(" %c", &answer);
        
        if(answer == 'N') {
            break;
        }
    }
    
    int res = createGroup(db, group, cols);

    if(res) {
        printf("Group successfully created!\n");
    } else {
        printf("Failed to create the group!\n");
    }

    // Free the memory allocated for each column name
    for (int i = 0; i < size; i++) {
        free(cols[i]);
    }

    free(cols);
}

void listGroups(sqlite3* db) {
    printf("Name of the group: \n");
    char group[100];
    scanf("%s", &group);
    
    int size = 0;
    char** cols = NULL;
    char answer;
    while(1) {
        size++;
        cols = (char**)realloc(cols, size*sizeof(char*));
        printf("Name of the column: \n");
        char col[100];
        scanf("%s", col);
        cols[size-1] = strdup(col); // Allocate memory and copy the column name
        printf("Do you want to add another column? (yes = Y, no = N): \n");
        scanf(" %c", &answer);
        
        if(answer == 'N') {
            break;
        }
    }

    printf("Give a condition\n");
    chazr condition[100];
    scanf("%s", condition);

    int res = selectStudentGroup(db, group, cols, condition);
    
    if(res) {
        printf("Group succesfully created !\n");
    } else {
        pritnf("Failed to create the group !\n");
    }

    for(int i = 0; i < size; i++) {
        free(cols[i]);
    }

    free(cols);
}

void deleteGroup(sqlite3* db) {
    printf("Name of the group: \n");
    char group[100];
    scanf("%s", &group);

    printf("Give a condition\n");
    char condition[100];
    scanf("%s", condition);

    int res = deleteGroup(db, group, condition);
    
    if(res) {
        printf("Group succesfully created !\n");
    } else {
        pritnf("Failed to create the group !\n");
    }
}

void transferStudents(sqlite3* db) {
    printf("Name of the group: \n");
    char group[100];
    scanf("%s", &group);
    
    int size = 0;
    char** cols = NULL;
    char answer;
    while(1) {
        size++;
        cols = (char**)realloc(cols, size*sizeof(char*));
        printf("Name of the column: \n");
        char col[100];
        scanf("%s", col);
        cols[size-1] = strdup(col); // Allocate memory and copy the column name
        printf("Do you want to add another column? (yes = Y, no = N): \n");
        scanf(" %c", &answer);
        
        if(answer == 'N') {
            break;
        }
    }

    printf("Give a condition\n");
    char condition[100];
    scanf("%s", condition);

    int res = selectStudentGroup(db, group, cols, condition);
    
    if(res) {
        printf("Group succesfully created !\n");
    } else {
        pritnf("Failed to create the group !\n");
    }
}

void addStudent(sqlite3* db) {
    printf("Name of the goup: \n");
    char group[100];
    scanf("%s", &group);
    
    int size = 0;
    char** cols = NULL;
    char answer;
    while(1) {
        size++;
        cols = (char**)realloc(cols, size*sizeof(char*));
        printf("Name of the column: \n");
        char col[100];
        scanf("%s", col);
        cols[size-1] = strdup(col); // Allocate memory and copy the column name
        printf("Do you want to add another column? (yes = Y, no = N): \n");
        scanf(" %c", &answer);
        
        if(answer == 'N') {
            break;
        }
    }

    int res = insertStudents(db, group, cols);

    if(res) {
        printf("Group succesfully created !\n");
    } else {
        pritnf("Failed to create the group !\n");
    }
}

void viewStudentDetails(sqlite3* db) {
    printf("Name of the student: \n");
    char group[100];
    scanf("%s", &group);
    
    int size = 0;
    char** cols = NULL;
    char answer;
    while(1) {
        size++;
        cols = (char**)realloc(cols, size*sizeof(char*));
        printf("Name of the column: \n");
        char col[100];
        scanf("%s", col);
        cols[size-1] = strdup(col); // Allocate memory and copy the column name
        printf("Do you want to add another column? (yes = Y, no = N): \n");
        scanf(" %c", &answer);
        
        if(answer == 'N') {
            break;
        }
    }

    printf("Give a condition\n");
    char condition[100];
    scanf("%s", condition);

    int res = selectStudents(db, group, cols, condition);

    if(res) {
        printf("Group succesfully created !\n");
    } else {
        pritnf("Failed to create the group !\n");
    }
}

void updateStudentInfo(sqlite3* db) {
    printf("Name of the student: \n");
    char group[100];
    scanf("%s", &group);
    
    int size = 0;
    char** cols = NULL;
    char answer;
    while(1) {
        size++;
        cols = (char**)realloc(cols, size*sizeof(char*));
        printf("Name of the column: \n");
        char col[100];
        scanf("%s", col);
        cols[size-1] = strdup(col); // Allocate memory and copy the column name
        printf("Do you want to add another column? (yes = Y, no = N): \n");
        scanf(" %c", &answer);
        
        if(answer == 'N') {
            break;
        }
    }

    printf("Give a condition\n");
    char condition[100];
    scanf("%s", condition);

    int res = updateStudents(db, group, cols, condition);

    if(res) {
        printf("Group succesfully created !\n");
    } else {
        pritnf("Failed to create the group !\n");
    }
}

void deleteStudent(sqlite3* db) {
    printf("Name of the student: \n");
    char group[100];
    scanf("%s", &group);

    printf("Give a condition\n");
    char condition[100];
    scanf("%s", condition);

    int res = deleteStudents(db, group, condition);

    if(res) {
        printf("Group succesfully created !\n");
    } else {
        pritnf("Failed to create the group !\n");
    }
}

void listStudents(sqlite3* db) {
    printf("Name of the student: \n");
    char group[100];
    scanf("%s", &group);

    int size = 0;
    char** cols = NULL;
    char answer;
    while(1) {
        size++;
        cols = (char**)realloc(cols, size*sizeof(char*));
        printf("Name of the column: \n");
        char col[100];
        scanf("%s", col);
        cols[size-1] = strdup(col); // Allocate memory and copy the column name
        printf("Do you want to add another column? (yes = Y, no = N): \n");
        scanf(" %c", &answer);
        
        if(answer == 'N') {
            break;
        }
    }

    printf("Give a condition\n");
    char condition[100];
    scanf("%s", condition);

    int res = selectStudents(db, group, cols, condition);

    if(res) {
        printf("Group succesfully created !\n");
    } else {
        pritnf("Failed to create the group !\n");
    }
}