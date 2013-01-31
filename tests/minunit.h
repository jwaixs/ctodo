/* minunit.h from Jera Design and "learn c the hard way" */

#ifndef __minunit_h_
#define __minunit_h_

#include <stdio.h>
#include <stdlib.h>

#define mu_suite_start()					\
	tests_run = 0;						\
	tests_failures = 0; 					\
	tests_successes = 0;

#define mu_assert(test, message) 				\
{ 								\
	tests_run++;						\
	if (!(test)) {						\
		printf("FAILED: %s\n", message);		\
		tests_failures++;				\
	} else {						\
		tests_successes++;				\
	}							\
}

#define mu_run_test(test)					\
{								\
	printf("TESTING %s\n", #test); 				\
	test();							\
}

#define RUN_TESTS(name) 					\
int main(int argc, char *argv[]) 				\
{ 								\
	argc = 1; 						\
	printf("===== RUNNING: %s =====\n", argv[0]); 		\
	name();		 					\
	printf("Tests run: %d\n", tests_run); 			\
	printf("Successes: %d\n", tests_successes);		\
	printf("Failures: %d\n", tests_failures);		\
	if (tests_failures == 0) {				\
		printf("All tests passed!\n");			\
		return 0;					\
	}							\
	return 1;	 					\
}

int tests_run;
int tests_failures;
int tests_successes;

#endif /*__minunit_h_ */
