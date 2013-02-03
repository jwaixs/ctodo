#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct s1 {
	char *s1;
	char *s2;
};

struct s2 {
	struct s1 *structure;
	int data;
};

int main() {
	struct s1 test1;
	test1.s1 = "This is the first string.";
	test1.s2 = "This is the second string.";

	struct s2 test2;
	test2.structure = &test1;
	test2.data = 37;

	FILE *file1 = fopen("test.db", "w");
	size_t s1len = strlen(test2.structure->s1);
	size_t s2len = strlen(test2.structure->s2);	

	fwrite(&(test2.data), sizeof(int), 1, file1);
	fwrite(&(s1len), sizeof(size_t), 1, file1);
	fwrite(test2.structure->s1, s1len, 1, file1);
	fwrite(&(s2len), sizeof(size_t), 1, file1);
	fwrite(test2.structure->s2, s2len, 1, file1);

	fclose(file1);

	return 0;
}
