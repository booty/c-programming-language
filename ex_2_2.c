#include <stdio.h>

#define MAXLENGTH 100

/*
for (i=0; i<lim-1 && (c=getchar())!=EOF && c!='\n'; ++i) {
	s[i]=c;
}

Exercise 2-2. Write a loop equivalent to the for
loop above without using && or ||.
*/


// read a line into s, return length
int original_getline(char s[], int lim) {
	int c, i;

	for (i=0; i<lim-1 && (c=getchar())!=EOF && c!='\n'; ++i) {
		s[i]=c;
	}

	if (c == '\n') {
		s[i] =c;
		++i;
	}

	s[i] = '\0';
	return i;
}

int new_getline(char s[], int lim) {
	int ok = 1;
	int i = 0;
	char c;

	while(ok) {
		ok = 0;
		if (i < lim-1) {
			if ((c=getchar())!=EOF) {
				if (c!='\n') {
					s[i] = c;
					i++;
					ok = 1;
				}
			}
		}
	}

	if (c == '\n') {
		s[i] =c;
		++i;
	}

	s[i] = '\0';
	return i;
}

int main() {
	char line[MAXLENGTH];

	while (new_getline(line, MAXLENGTH) > 0) {
		printf("Got a line: %s", line);
	}

	return 0;
}