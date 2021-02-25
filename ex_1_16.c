#include <stdio.h>

#define MAX_LENGTH_ALLOWED 20


int booty_getline(char line[], int maxlength);
void booty_copy(char dst[], char src[]);
void ex_1_16();

int main() {
	ex_1_16();
	return 0;
}

/*
Exercise 1-16. Revise the main routine of the longest-line program so it will correctly print the length of arbitrarily long input lines, and as much as possible of the text.
*/

// 123456789012345678901234567890

void ex_1_16() {
	char current_line[MAX_LENGTH_ALLOWED];
	char longest_line[MAX_LENGTH_ALLOWED];
	int current_len;
	int max_len=0;

	while ((current_len = booty_getline(current_line, MAX_LENGTH_ALLOWED)) > 0) {
		printf("max_len:%d current_len:%d\n", max_len, current_len);
		if (current_len >= max_len) {
			printf("a new winner!\n");
			max_len = current_len;
			booty_copy(longest_line, current_line);
		}
	}

	printf("longest line was...\n%s\n", longest_line);
}

int booty_getline(char line[], int max_allowed) {
	int c, pos;

	for (pos=0; ((c=getchar())!=EOF && c!='\n'); ++pos) {
		if (pos < max_allowed - 1) {
			line[pos] = c;
		}
	}

	if (pos < max_allowed) {
		line[pos+1] = '\0';
	}
	else {
		line[max_allowed] = '\0';
	}

	return pos;
}

// not safe; assumes we have a valid null terminated string
void booty_copy(char to[], char from[]) {
	int i=0;

	while((to[i] = from[i]) != '\0')
		++i;
}