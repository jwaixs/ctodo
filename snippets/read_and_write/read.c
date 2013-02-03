#include <stdio.h>
#include <stdlib.h>

struct s1 {
	char *s1;
	char *s2;
};

struct s2 {
	struct s1 *structure;
	int data;
};

int main() {
	FILE *file2 = fopen("test.db", "r");
	struct s2 test3;

	size_t s1len, s2len;
	
	fread(&(test3.data), sizeof(int), 1, file2);
	fread(&s1len, sizeof(size_t), 1, file2);
	test3.structure = (struct s1 *)malloc(sizeof(struct s1));
	test3.structure->s1 = (char *)malloc(s1len + 1);
	fread(test3.structure->s1, s1len, 1, file2);
	fread(&s2len, sizeof(size_t), 1, file2);
	test3.structure->s2 = (char *)malloc(s2len + 1);
	fread(test3.structure->s2, s2len, 1, file2);

	fclose(file2);

	printf("%s\n%s\n%d\n", test3.structure->s1, test3.structure->s2,
		test3.data);

	return 0;
}
