#include <stdio.h>

/*
Write a program to print all input lines that are longer than 80 characters.
(Well, some length. We'll use 10.)
*/

#define MAX_STORAGE_LENGTH 1000
#define WHAT_IS_LONG 10

int booty_getline(char line[], int maxlength);

int main() {
	int current_len;
	char current_line[MAX_STORAGE_LENGTH];

	while((current_len = booty_getline(current_line, MAX_STORAGE_LENGTH)) > 0) {
		if (current_len > WHAT_IS_LONG) {
			printf("%s", current_line);
		}
	}

	return 0;
}

int booty_getline(char line[], int maxlength) {
	int c, i;

	for (i=0; i<maxlength-1 && (c=getchar())!=EOF && c!='\n'; ++i) {
		line[i] = c;
	}
	if (c == '\n') {
		line[i++] = c;
	}
	line[i] = '\0';
	return i;
}