#include "../include/database.h"

sqlite3* openOrCreateDatabase(const char* dbName) {
    sqlite3* db;
    int exitCode = sqlite3_open(dbName, &db);

    if (exitCode != SQLITE_OK) {
        fprintf(stderr, "Error opening database: %s\n", sqlite3_errmsg(db));
        return NULL;
    }

    return db;
}