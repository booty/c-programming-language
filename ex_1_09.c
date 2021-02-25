#include <stdio.h>

/*
Write a program to copy its input to its output, replacing
each string of one or more blanks by a single blank.
*/

int main() {
	int last_char_was_blank = 0;
	char c;

	while((c = getchar()) != EOF) {
		int this_char_blank = (c == ' ');

		if (!(last_char_was_blank && this_char_blank)) {
			putchar(c);
		}
		last_char_was_blank = this_char_blank;
	}

	return 0;
}