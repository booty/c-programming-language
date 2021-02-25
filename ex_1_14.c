#include <stdio.h>

/*
Exercise l-14. Write a program to print a histogram of the frequencies of different characters in its input.
*/

#define MAX_VAL 123

int main() {
	char c;
	int tallies[MAX_VAL];
	int tally;

	for(int i=0; i<=MAX_VAL; ++i) { tallies[i] = 0; }

	while((c = getchar()) != EOF) {
		tallies[c]++;
	}

	printf("      char  num\n");
	printf("---------- ----\n");
	for(int i=0; i<=MAX_VAL; ++i) {
		if (tallies[i] > 0) {
			if (i == ' ') { printf("%10s", "space"); }
			else if (i == '\n') { printf("%10s", "newline"); }
			else if (i == '\t') { printf("%10s", "tab"); }
			else { printf("%10c", i); }

			printf("%5i\n", tallies[i]);
		}
	}

	return 0;
}