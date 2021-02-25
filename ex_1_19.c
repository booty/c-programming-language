#include <stdio.h>

#define MAXLENGTH 1000

/*
Write a function reverse (s} that reverses the character string s. Use it to write a program that reverses its input a line at a time.
*/

int booty_getline(char line[], int maxlength);

int main() {
	char line[MAXLENGTH];
	int length;

	while ((length = booty_getline(line, MAXLENGTH)) != 0) {
		for (int pos = length-2; pos >= 0; pos--) {
			putchar(line[pos]);
		}
		putchar('\n');
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