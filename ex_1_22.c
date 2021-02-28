#include <stdio.h>

/*
Exercise 1-22. Write a program to "fold" long input
lines into two or more shorter lines after the last
non-blank character that occurs before the n-th
column of input. Make sure your program does something
intelligent with very long lines, and if there are no
blanks or tabs before the specified column.
*/

#define MAX_LENGTH 40
#define NEWLINE '\n'
#define NO_SPACES_FOUND -1

/*
Algorithm:
- read characters until we hit an EOF
	- is it a newline?
		- yes:
			- print the buffer
			- reset the buffer
			- reset the column num to 0
			- reset buffer position of last space to -1
	- is character a space?
		- yes: record the buffer position of the last space
	- regardless of space/nonspace:
		- add it to the buffer
		- increment the buffer "pointer"
	- have we reached MAX_LENGTH?
		- no:
			- okay, nothing to do
		- yes:
			- is buffer position of last space == -1?
				- yes:
					- guess there were no spaces
					- just dump the buffer. we can't break this in a friendly way
				- no:
					- dump the buffer until the last space
					- copy the remnants of the buffer to the front of the buffer, noting the last space character
*/

int is_whitespace(char c) {
	return (c == ' ');
}

void dump_and_reset_buffer(char buffer[], int *buffer_position, int *buffer_last_space_position) {
	int remnant_length;

	if ((*buffer_position < MAX_LENGTH) || (*buffer_last_space_position == NO_SPACES_FOUND)) {
		// there were no spaces, or it's just a short line. so, print the whole thing
		for(int i=0; i < *buffer_position; i++) {
			putchar(buffer[i]);
		}
		*buffer_position = 0;
		*buffer_last_space_position = NO_SPACES_FOUND;
	}
	else {
		// print until the last space, then copy the rest to the beginning of the buffer
		for(int i=0; i < *buffer_last_space_position; i++) {
			putchar(buffer[i]);
		}

		remnant_length = MAX_LENGTH - *buffer_last_space_position;
		int startpos = *buffer_last_space_position + 1;  // add 1 so we skip the space
		int endpos = *buffer_position;
		*buffer_last_space_position = NO_SPACES_FOUND;

		for(int oldpos = startpos; oldpos < endpos; oldpos++) {
			int newpos = oldpos - startpos;
			buffer[newpos] = buffer[oldpos];
			if (is_whitespace(buffer[oldpos])) *buffer_last_space_position = newpos;
		}

		*buffer_position = MAX_LENGTH - startpos;
	}
	putchar(NEWLINE);
}

// doesn't handle tabs at this time =)
int main() {
	char buffer[MAX_LENGTH];
	int buffer_position = 0;
	int buffer_last_space_position = 0;
	int column = 0;
	char c;

	printf("01234567890123456789012345678901234567890123456789\n");
	while ((c = getchar()) != EOF) {
		if (c == NEWLINE) {
			dump_and_reset_buffer(buffer, &buffer_position, &buffer_last_space_position);
		}
		else {
			if (is_whitespace(c)) buffer_last_space_position = buffer_position;

			buffer[buffer_position++] = c;

			if (buffer_position == MAX_LENGTH) {
				dump_and_reset_buffer(buffer, &buffer_position, &buffer_last_space_position);
			}
		}
	}

	return 0;
}