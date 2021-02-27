#include <stdio.h>

/*
Exercise 1-20. Write a program detab that replaces
tabs in the input with the proper number of blanks
to space to the next tab stop. Assume a fixed set
of tab stops, say every n columns. Should n be a
variable or a symbolic parameter?
*/

#define MAX_LENGTH 1000
#define TAB_SIZE 8
#define SPACE_CHAR ' ' // for debugging

int next_tab_column(int current_col, int tab_size);
int booty_getline(char line[], int maxlength);
void detab(char line[], int tab_size);
void putspaces(int num);


// hmmm, this might only handle leading spaces properly?

int main() {
	char line[MAX_LENGTH];
	int length;

	while ((length = booty_getline(line, MAX_LENGTH)) != 0) {
		detab(line, TAB_SIZE);
	}
	putchar('\n'); // needed?
	return 0;
}

void detab(char line[], int tab_size) {
	int col=0;
	char c=0;

	// printf("original line | %s", line);
	// printf("new ver       | ");
	while ((c = line[col]) != '\0') {
		if (c == ' ') {
			putchar(' ');
		}
		else if (c == '\t') {
			putspaces(next_tab_column(col, tab_size) - col);
		}
		else {
			putchar(c);
		}
		col++;
	}
}

void putspaces(int num) {
	for (int i=0; i<num; i++) { putchar(SPACE_CHAR); };
}

int next_tab_column(int current_col, int tab_size) {
	return current_col + (tab_size - current_col % tab_size);
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