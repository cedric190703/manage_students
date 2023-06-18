#include "../include/group.h"

int createGroup(sqlite3* db, const char* tableName, const char** columns, int columnCount) {
    // Prepare the SQL statement
    char sql[200];
    snprintf(sql, sizeof(sql), "CREATE TABLE IF NOT EXISTS %s (", tableName);
    
    // Add each column to the SQL statement
    for (int i = 0; i < columnCount; i++) {
        strcat(sql, columns[i]);
        
        // Add a comma if it's not the last column
        if (i < columnCount - 1) {
            strcat(sql, ",");
        }
    }
    
    strcat(sql, ")");

    // Execute the SQL statement
    int rc = sqlite3_exec(db, sql, 0, 0, 0);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", sqlite3_errmsg(db));
        return 1; // Return an error code
    }

    return 0; // Return success code
}

int deleteGroup(sqlite3* db, const char* tableName) {
    // Prepare the SQL statement
    char sql[100];
    snprintf(sql, sizeof(sql), "DROP TABLE IF EXISTS %s", tableName);

    // Execute the SQL statement
    int rc = sqlite3_exec(db, sql, 0, 0, 0);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", sqlite3_errmsg(db));
        return 1; // Return an error code
    }

    return 0; // Return success code
}

int insertStudentGroup(sqlite3* db, const char* tableName, const char** values) {
    // Prepare the SQL statement
    char sql[100];
    snprintf(sql, sizeof(sql), "INSERT INTO %s VALUES (", tableName);

    // Add each column to the SQL statement
    for (int i = 0; i < columnCount; i++) {
        strcat(sql, values[i]);
        
        // Add a comma if it's not the last column
        if (i < columnCount - 1) {
            strcat(sql, ",");
        }
    }
    
    strcat(sql, ")");

    // Execute the SQL statement
    int rc = sqlite3_exec(db, sql, 0, 0, 0);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", sqlite3_errmsg(db));
        return 1; // Return an error code
    }

    return 0; // Return success code
}

int updateStudentGroup(sqlite3* db, const char* tableName, const char** columns, const char* condition, int columnCount) {
    // Prepare the SQL statement
    char sql[100];
    snprintf(sql, sizeof(sql), "UPDATE %s SET (", tableName);

    // Add each column to the SQL statement
    for (int i = 0; i < columnCount; i++) {
        strcat(sql, values[i]);
        
        // Add a comma if it's not the last column
        if (i < columnCount - 1) {
            strcat(sql, ",");
        }
    }
    
    strcat(sql, ")");

    // Add condition in the SQL statement
    strcat(sql, " WHERE ");
    strcat(sql, condition);


    // Execute the SQL statement
    int rc = sqlite3_exec(db, sql, 0, 0, 0);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", sqlite3_errmsg(db));
        return 1; // Return an error code
    }

    return 0; // Return success code
}

int deleteStudentGroup(sqlite3* db, const char* tableName, const char* condition) {
    // Prepare the SQL statement
    char sql[100];
    snprintf(sql, sizeof(sql), "DELETE FROM %s WHERE %s", tableName, condition);

    // Execute the SQL statement
    int rc = sqlite3_exec(db, sql, 0, 0, 0);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", sqlite3_errmsg(db));
        return 1; // Return an error code
    }

    return 0; // Return success code
}

int selectStudentGroup(sqlite3* db, const char* tableName, const char** columns, const char* condition, int columnCount) {
    // Prepare the SQL statement
    char sql[100];
    snprintf(sql, sizeof(sql), "SELECT %s FROM (", tableName);

    for(int i = 0; i < columnCount; i++) {
        strcat(sql, columns[i]);

        if(i < columnCount - 1) {
            strcat(sql, ",");
        }
    }

    strcat(sql, ")");

    // Add condition to the SQL statement
    strcat(sql, "WHERE ");
    strcat(sql, condition);

    // Execute the SQL statement
    int rc = sqlite3_exec(db, sql, 0, 0, 0);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", sqlite3_errmsg(db));
        return 1; // Return an error code
    }

    return 0; // Return success code
}
