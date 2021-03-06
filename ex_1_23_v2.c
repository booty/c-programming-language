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


void check_block_comment(
	char c,
	char last_char,
	int inside_character_constant,
	int inside_string_literal,
	int inside_line_comment,
	int *inside_block_comment,
	int *was_inside_comment) {

	if (inside_character_constant) return;
	if (inside_string_literal) return;
	if (inside_line_comment) return;

	// are we entering a block comment?
	if ((c == '*') && (last_char == BLOCK_START_CHAR)) {
		*inside_block_comment = TRUE;
		return;
	}

	// are we leaving a block comment?
	if ((c == BLOCK_END_CHAR) && (last_char == '*')) {
		*was_inside_comment = TRUE;
		*inside_block_comment = FALSE;
	}
}

void check_line_comment(
	char c,
	char last_char,
	int inside_character_constant,
	int inside_string_literal,
	int inside_block_comment,
	int *inside_line_comment,
	int *was_inside_comment) {

	if (inside_character_constant) return;
	if (inside_string_literal) return;
	if (inside_block_comment) return;

	if ((c == '/') && (last_char == '/')) {
		*inside_line_comment = TRUE;
		*was_inside_comment = TRUE;
		return;
	}

	if (c == '\n') {
		*inside_line_comment = FALSE;
		*was_inside_comment = FALSE;
	}
}

void check_string_literal(char c, char last_char, int inside_any_comment, int inside_character_constant, int *inside_string_literal) {
	if (inside_any_comment) return;

	if (!inside_character_constant && (c == '"')) {
		if (last_char == '\\') return;

		if (*inside_string_literal) {
			// printf("\033[31;1m[OUT %c]\033[0m", last_char);
			*inside_string_literal = FALSE;
		}
		else {
			// printf("\033[31;1m[IN %c]\033[0m", last_char);
			*inside_string_literal = TRUE;
		}
	}
}

void check_character_constant(char c, int inside_any_comment, int inside_string_literal, int *inside_character_constant) {
	if (inside_any_comment) return;
	if (inside_string_literal) return;

	if (c == '\'') {
		*inside_character_constant = !*inside_character_constant;
	}
}

int main() {
	int inside_string_literal = FALSE;
	int inside_character_constant = FALSE;
	int inside_block_comment = FALSE;
	int inside_line_comment = FALSE;
	int inside_any_comment;
	int was_inside_any_comment = FALSE;
	int was_was_inside_any_comment = FALSE;
	char last_char = BOF;
	char c;

	while ((c = getchar()) != EOF) {

		check_block_comment(c, last_char, inside_character_constant, inside_string_literal, inside_line_comment, &inside_block_comment, &was_inside_any_comment);

		check_line_comment(c, last_char, inside_character_constant, inside_string_literal, inside_block_comment, &inside_line_comment, &was_inside_any_comment);

		inside_any_comment = inside_line_comment || inside_block_comment;

		check_string_literal(c, last_char, inside_any_comment, inside_character_constant, &inside_string_literal);

		check_character_constant(c, inside_any_comment, inside_string_literal, &inside_character_constant);

		if (!inside_any_comment && !was_was_inside_any_comment && (last_char != BOF)) {
			putchar(last_char);
		}

		was_was_inside_any_comment = was_inside_any_comment;
		was_inside_any_comment = inside_any_comment;
		last_char = c;
	}
	putchar(last_char);
	return 0;
}
