#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h>

int createTableStudent(sqlite3* db, const char* tableName, const char* columns);
int insertStudents(sqlite3* db, const char* tableName, const char* values);
int updateStudents(sqlite3* db, const char* tableName, const char* columns, const char* condition);
int deleteStudents(sqlite3* db, const char* tableName, const char* condition);
int selectStudents(sqlite3* db, const char* tableName, const char* columns, const char* condition);