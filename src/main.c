#include "../include/database.h"
#include "../include/group.h"
#include "../include/student.h"
#include "../include/ui.h"
#include <stdio.h>

// These functions call the appropriate functions
// It's like abstraction
void createGroups(sqlite3* db);
void listGroups(sqlite3* db);
void deleteGroup(sqlite3* db);
void viewGroupDetails(sqlite3* db);
void transferStudents(sqlite3* db);
void addStudent(sqlite3* db);
void viewStudentDetails(sqlite3* db);
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
            printf("7. View student details\n");
            printf("8. Update student info\n");
            printf("9. Delete student\n");
            printf("10. List students\n");
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
                    viewGroupDetails(db);
                    break;
                case 5:
                    transferStudents(db);
                    break;
                case 6:
                    addStudent(db);
                    break;
                case 7:
                    viewStudentDetails(db);
                    break;
                case 8:
                    updateStudentInfo(db);
                    break;
                case 9:
                    deleteStudent(db);
                    break;
                case 10:
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

}

void listGroups(sqlite3* db) {
    // TODO
}

void deleteGroup(sqlite3* db) {
    // TODO
}

void viewGroupDetails(sqlite3* db) {
    // TODO
}

void transferStudents(sqlite3* db) {
    // TODO
}

void addStudent(sqlite3* db) {
    // TODO
}

void viewStudentDetails(sqlite3* db) {
    // TODO
}

void updateStudentInfo(sqlite3* db) {
    // TODO
}

void deleteStudent(sqlite3* db) {
    // TODO
}

void listStudents(sqlite3* db) {
    // TODO
}
