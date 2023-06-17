# manage_students
This project is a tool that allows the management of students in C and SQL.

# Project requirements :
### Create groups
### Listing groups
### Deleting groups
### Viewing groups details
### Transfering students to 2 differents groups
### Adding students to a group
### Viewing students details
### Updating students info
### Deleting students from a group
### Listing students
### Listing students from different groups

Structure of the project :
<pre>
.
├── db
│   └── student_manager.db
├── include
│   ├── database.h
│   ├── group.h
│   ├── student.h
│   ├── ui.h
│   └── utils.h
├── Makefile
├── README.md
├── src
│   ├── database.c
│   ├── group.c
│   ├── main.c
│   ├── student.c
│   └── utils.c
└── UI
    └── ui.c

4 directories, 14 files
</pre>

<hr>

<pre>
src/: This directory contains the source files of your program.

main.c: The main entry point of your program where the CLI interface and user input handling will be implemented.
database.c: This file will handle the database connection, SQL operations, and executing queries.
student.c: Contains functions related to managing student data, such as adding, updating, deleting, and listing students.
group.c: Contains functions related to managing groups, such as creating, deleting, transferring students, and listing group details.
utils.c: Contains utility functions that can be used across different modules, such as input validation or formatting.

include/: This directory contains the header files corresponding to the source files.

database.h: Header file declaring the functions related to the database and SQL operations.
student.h: Header file declaring the functions related to student management.
group.h: Header file declaring the functions related to group management.
utils.h: Header file declaring the utility functions.

db/: This directory store your SQLite database file (student_manager.db in this example).

UI/: This directory contains the logic of the UI for the CLI application.

Makefile: A Makefile that provides instructions for building the program, including compiling the source files and linking the necessary libraries.

README.md: A README file containing project documentation, instructions for setup, and usage guidelines.
</pre>

<hr>

## Technologies used :
<pre>
Programming languages: C and SQL for the management of the data and the logic.

C: Used for writing the core logic of the CLI application, handling user input, implementing database operations, and managing the program flow.

SQL: Used for interacting with the database, performing CRUD (Create, Read, Update, Delete) operations, and managing student and group data.

SQLite (or any other preferred database management system): Used as the database engine to store and retrieve student and group information.

Standard C library: Provides essential functions for input/output, string manipulation, memory management, and other core functionalities in the C programming language like GTK.

Database library (e.g., SQLite library): Allows the program to connect to the database, execute SQL queries, and retrieve query results.
</pre>

