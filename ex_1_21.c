#include <stdio.h>

/*
Exercise 1-21. Write a program entab that replaces
strings of blanks by the minimum number of tabs and
blanks to achieve the same spacing. Use the same
tab stops as for detab. When either a tab or a single
blank would suffice to reach a tab stop, which should
be given preference?
*/

#define MAX_LENGTH 1000
#define TAB_SIZE 8
#define SPACE_CHAR ' ' // for debugging

int booty_getline(char line[], int maxlength);
void entab(char line[], int tab_size);
int next_tab_column(int current_col, int tab_size);

int main() {
	char line[MAX_LENGTH];
	int length;

	while ((length = booty_getline(line, MAX_LENGTH)) != 0) {
		entab(line, TAB_SIZE);
	}
	putchar('\n');
	return 0;
}

void entab(char line[], int tab_size) {
	int input_col=0;
	int output_col=0;
	char c=0;
	int until_next_tab = TAB_SIZE;
	int consecutive_spaces = 0;

	printf("original line | %s", line);
	printf("new ver       | ");
	while ((c = line[input_col]) != '\0') {
		if (c == '\t') {
			// jump to next tab stop
			// reset space counter
			putchar(c);
			consecutive_spaces = 0;
			output_col = next_tab_column(output_col, TAB_SIZE);
		}
		else if (output_col % TAB_SIZE == 0) {
			// this is a tab stop
			// if space counter > 0, output a tab to replace the
			// spaces we counted
			//
			consecutive_spaces = 0;
			output_col++;
		}
		else if (c == ' ') {
			consecutive_spaces++;
			output_col++;
		}
		else {
			// it's just a regular character
			// reset space counter
			// output the character
			putchar(c);
			consecutive_spaces = 0;
			output_col++;
		}

		input_col++;
	}
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