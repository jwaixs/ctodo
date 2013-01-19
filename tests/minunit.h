/* minunit.h from Jera Design and "learn c the hard way" */

#ifndef __minunit_h_
#define __minunit_h_

#include <stdio.h>
#include <stdlib.h>

#define mu_suite_start() char *message = NULL;

#define mu_assert(test, message) { if (!(test)) return message; }
#define mu_run_test(test) printf("TESTING %s\n", #test); \
	message = test(); tests_run++; if (message) return message;
#define RUN_TESTS(name) int main(int argc, char *argv[]) { \
	argc = 1; \
	printf("===== RUNNING: %s =====\n", argv[0]); \
	char *result = name(); \
	if (result != 0) { \
		printf("FAILED: %s\n", result); \
	} else { \
		printf("All tests passed!\n"); \
	}\
	printf("Tests run: %d\n", tests_run); \
	return result != 0; \
}

int tests_run;

#endif /*__minunit_h_ */
