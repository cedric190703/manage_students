#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h>

sqlite3* openOrCreateDatabase(const char* dbName);