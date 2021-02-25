#include <stdio.h>

/*
Write a program to remove trailing blanks and tabs from each line of
input, and to delete entirely blank lines.
*/

int booty_getline(char line[], int maxlength);

int main() {
	char myline[1000];
	int last_good_char=0;
	int mylen;
	int c;

	mylen = booty_getline(myline, 1000);

	for(int pos=1; pos < mylen; pos++) {
		c = myline[pos];

		if((c!=' ') && (c!='\t') && (c!='\n'))  {
			last_good_char = pos;
		}
	}

	printf("your trimmed string: ---");
	for(int pos=0; pos<=last_good_char; pos++) {
		putchar(myline[pos]);
	}
	printf("---\n");

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

1000