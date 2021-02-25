#include <stdio.h>

/*
Exercise 1-10. Write a program to copy its input to its output,
replacing each tab by \t, each backspace by \b,
and each backslash by \\. This makes tabs and
backspaces visible in an unambiguous way.

(This isn't exactly what the exercise called for,
 but same spirit...)
*/

int main() {
	char c;

	while((c = getchar()) != EOF) {
		if (c == '\t')
			printf("🅣 ");
		if (c == '\b')
			printf("🅑 ");
		if (c == '\n')
		  printf("🅝 🅛\n");
		if (c == '\\')
		  printf("\\\\");
		else
			putchar(c);
	}

	return 0;
}
