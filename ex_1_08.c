#include <stdio.h>

/*
Exercise 1-8. Write a program to count blanks, tabs,
and newlines.
*/

int main() {
	double nblanks = 0;
	double ntabs = 0;
	double nnewlines = 0;
	int c;

	while((c = getchar()) != EOF) {
		if (c == ' ') { nblanks++; }
		if (c == '\t') { ntabs++; }
		if (c == '\n') { nnewlines++; }
	}

	printf("blanks:%.0f tabs:%.0f newlines:%.0f", nblanks, ntabs, nnewlines);

	return 0;
}