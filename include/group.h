#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h>

int createGroup(sqlite3* db, const char* tableName, const char* columns);
int deleteGroup(sqlite3* db, const char* tableName);
int insertStudentGroup(sqlite3* db, const char* tableName, const char* values);
int updateStudentGroup(sqlite3* db, const char* tableName, const char* columns, const char* condition);
int deleteStudentGroup(sqlite3* db, const char* tableName, const char* condition);
int selectStudentGroup(sqlite3* db, const char* tableName, const char* columns, const char* condition);