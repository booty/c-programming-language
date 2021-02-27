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
	int output_col_is_tabstop = 0;

	// printf("--------------|-----------------------------------------\n");
	// printf("              |01234567890123456789012345678901234567890\n");
	// printf("              |        T       T       T       T       T\n");
	// printf("              |-----------------------------------------\n");
	// printf("original line | %s", line);
	// printf("new ver       | ");
	printf("-----------------------------------------\n");
	printf("01234567890123456789012345678901234567890\n");
	printf("        T       T       T       T       T\n");
	printf("-----------------------------------------\n");
	printf("%s\n", line);

	while ((c = line[input_col]) != '\0') {
		/*
		current char is tab?
		output column is tabstop?
		current char is space?

		if the output column is a tab stop, then replace all
		previous spaces (if any) with a tab, and output the current char

		*/

		output_col_is_tabstop = (output_col % TAB_SIZE == 0);

		if (output_col_is_tabstop) {
			switch(consecutive_spaces) {
				case 0:
					// do nothing?
					break;
				case 1:
					putchar(' ');
					break;
				default:
					// putchar('!');
					putchar('\t');
			}
			consecutive_spaces=0;
			// output_col++;
		}

		switch(c) {
			case '\t':
				output_col = next_tab_column(output_col, tab_size);
				consecutive_spaces=0;
				putchar(c);
				break;
			case ' ':
				output_col++;
				consecutive_spaces++;
				break;
			default:
				output_col++;
				output_col += consecutive_spaces;
				for (int i=0; i<consecutive_spaces; i++) { putchar(' '); }

				consecutive_spaces=0;
				putchar(c);
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