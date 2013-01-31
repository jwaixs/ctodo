/*
 * NOTE: To install sqlite3 on ubuntu use the command:
 * 	> sudo apt-get install libsqlite3-dev
 */

#ifndef _DATABASE_H_
#define _DATABASE_H_

#include <structure.h>
#include <sqlite3.h>

sqlite3 *create_database(char *filename);
sqlite3 *open_database(char *filename);
ctodo_item *read_database(sqlite3 *database);
int write_database(sqlite3 *database, ctodo_item *project);
int close_database(sqlite3 *database);


#endif /* _DATABASE_H_ */
