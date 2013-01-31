#include <stdlib.h>
#include <database.h>

sqlite3 *create_database(char *filename)
{
	char *sql_query;
	char *error_message = NULL;
	int rc;
	sqlite3 *database;

	database = open_database(filename);

	sql_query = "create table test(id int, name text)";
	rc = sqlite3_exec(database, sql_query, NULL, NULL, &error_message);
	check(rc == SQLITE_OK,
		"create_database: SQL error: %s", error_message);

	return database;
error:
	if (error_message)
		sqlite3_free(error_message);
	sqlite3_close(database);
	return NULL;
}

sqlite3 *open_database(char *filename)
{
	int rc;
	sqlite3 *database;

	rc = sqlite3_open(filename, &database);
	check(rc == 0,
		"open_databse: Cannot open database %s: %s",
		filename, sqlite3_errmsg(database));

	return database;
error:
	sqlite3_close(database);
	return NULL;
}

ctodo_item *read_database(sqlite3 *database)
{
	return NULL;
}

int write_database(sqlite3 *database, ctodo_item *project)
{
	return -1;
}

int close_database(sqlite3 *database)
{
	if (database)
		sqlite3_close(database);

	return 0;
}
