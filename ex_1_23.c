#include <stdio.h>

/*
Exercise 1-23. Write a program to remove all
comments from a C program. Don't forget to handle
quoted strings and character constants properly.
C comments do not nest.
*/

#define TRUE 1
#define FALSE 0
#define BOF 0
#define BLOCK_START_CHAR '/'
#define BLOCK_END_CHAR '/'

int main() {
	int inside_string_literal = FALSE;
	int inside_character_constant = FALSE;
	int inside_block_comment = FALSE;
	int inside_line_comment = FALSE;
	int inside_comment;
	int was_inside_comment = FALSE;
	int was_was_inside_comment = FALSE;
	char last_char = BOF;
	char c;

	while ((c = getchar()) != EOF) {

		if (!inside_line_comment && !inside_string_literal && !inside_character_constant) {
			// are we entering a block comment?
			if ((c == '*') && (last_char == BLOCK_START_CHAR)) {
				inside_block_comment = TRUE;
			}
			// are we leaving a block comment?
			else if ((c == BLOCK_END_CHAR) && (last_char == '*')) {
				was_inside_comment = TRUE;
				inside_block_comment = FALSE;
				// putchar('!');
			}
		}

		if (!inside_block_comment && !inside_string_literal && !inside_character_constant) {
			if ((c == '/') && (last_char == '/')) {
				inside_line_comment = TRUE;
				was_inside_comment = TRUE;
			}
			else if (c == '\n') {
				inside_line_comment = FALSE;
				was_inside_comment = FALSE;
			}
		}

		inside_comment = inside_line_comment || inside_block_comment;

		if (!inside_comment && !inside_character_constant && (c == '"')) {
			if (inside_string_literal && (last_char != '\\')) {
				inside_string_literal = FALSE;
			}
			else {
				inside_string_literal = TRUE;
			}
		}

		if (!inside_comment && !inside_string_literal && (c == '\'')) {
			inside_character_constant = !inside_character_constant;
		}

		if (!inside_comment && !was_was_inside_comment && (last_char != BOF)) {
			putchar(last_char);
		}

		was_was_inside_comment = was_inside_comment;
		was_inside_comment = inside_comment;
		last_char = c;
	}
	putchar(last_char);
	return 0;
}