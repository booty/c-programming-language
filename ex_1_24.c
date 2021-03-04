#include <stdio.h>

/*
Exercise 1-24. Write a program to check a C program
for rudimentary syntax errors like unbalanced parentheses,
brackets and braces. Don't forget about quotes, both single
and double, escape sequences, and comments. (This program
is hard if you do it in full generality.)
*/

#define TRUE 1
#define FALSE 0
#define BOF 0
#define BLOCK_START_CHAR '/'
#define BLOCK_END_CHAR '/'
#define MAX_NESTING 10

struct location {
	int line;
	int col;
};

struct location make_location(int line, int col) {
	struct location temp;
	temp.line = line;
	temp.col = col;
	return temp;
}

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

	int paren_nesting_level = 0;
	int single_quote_nesting_level = 0;
	int double_quote_nesting_level = 0;
	int bracket_nesting_level = 0;
	int num_errors = 0;
	int current_column = 1;
	int current_line = 1;
	struct location paren_start[MAX_NESTING];
	struct location bracket_start[MAX_NESTING];

	while ((c = getchar()) != EOF) {

		check_block_comment(c, last_char, inside_character_constant, inside_string_literal, inside_line_comment, &inside_block_comment, &was_inside_any_comment);

		check_line_comment(c, last_char, inside_character_constant, inside_string_literal, inside_block_comment, &inside_line_comment, &was_inside_any_comment);

		inside_any_comment = inside_line_comment || inside_block_comment;

		check_string_literal(c, last_char, inside_any_comment, inside_character_constant, &inside_string_literal);

		check_character_constant(c, inside_any_comment, inside_string_literal, &inside_character_constant);

		if (!inside_any_comment && !inside_string_literal && !inside_character_constant) {
			switch(c) {
				case '(':
					if (paren_nesting_level < MAX_NESTING) {
						paren_start[paren_nesting_level] = make_location(current_line, current_column);
					}
					paren_nesting_level++;
					break;
				case ')':
					paren_nesting_level--;
					if (paren_nesting_level < 0) {
						printf("Err: wacky right parenthesis at %d:%d\n", current_line, current_column);
						num_errors++;
						paren_nesting_level = 0;
					}
					break;
				case '[':
					if (bracket_nesting_level < MAX_NESTING) {
						bracket_start[paren_nesting_level] = make_location(current_line, current_column);
					}
					bracket_nesting_level++;
					break;
				case ']':
					bracket_nesting_level--;
					if (bracket_nesting_level < 0) {
						printf("Err: wayward right bracket at %d:%d\n", current_line, current_column);
						num_errors++;
						bracket_nesting_level = 0;
					}
					break;
			}
		}

		// housekeeping
		if (c == '\n') {
			current_line++;
			current_column = 1;
		}
		else {
			current_column++;
		}
		was_was_inside_any_comment = was_inside_any_comment;
		was_inside_any_comment = inside_any_comment;
		last_char = c;
	}

	for (int i = 0; ((i < paren_nesting_level) && (i < MAX_NESTING - 1)); i++) {
		num_errors++;
		printf("Err: scandalous left parenthesis at %d:%d\n",
			paren_start[i].line,
			paren_start[i].col
		);
	}

	for (int i = 0; ((i < bracket_nesting_level) && (i < MAX_NESTING - 1)); i++) {
		num_errors++;
		printf("Err: abhorrent left bracket at %d:%d\n",
			paren_start[i].line,
			paren_start[i].col
		);
	}

	printf("%d error(s) found.\n", num_errors);
	return 0;
}