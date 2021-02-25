#include <stdio.h>

#define IN 1 /* inside a word */
#define OUT 0 /* outside a word */

/*
Exercise 1-12. Write a program that prints its input one word per line.
*/

int main() {
	int c;
	int current_state = IN;

	while ((c = getchar()) != EOF) {
		if (c == ' ' || c == '\n' || c == '\t') {
			current_state = OUT;
		}
		else if (current_state == IN) {
			putchar(c);
		}
		else {
			putchar('\n');
			putchar(c);
			current_state = IN;
		}
	}

	return 0;
}
