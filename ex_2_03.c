#include <stdio.h>

#define MAXLENGTH 100
#define TRUE 1
#define FALSE 0

/*
Exercise 2-3. Write the function htoi (s), which converts
a string of hexa- decimal digits (including an optional 0x
or 0x) into its equivalent integer value. The allowable
digits are 0 through 9, a through f, and A through F.
*/

int our_crappy_getline(char s[], int lim) {
	int c, i;

	for (i=0; i<lim-1 && (c=getchar())!=EOF && c!='\n'; ++i) {
		s[i]=c;
	}

	if (c == '\n') {
		s[i++] =c;
	}

	s[i] = '\0';
	return i;
}

long htoi(char s[]) {
	int value;
	char c;
	int valid_hexdigit;
	long result = 0;
	int pos = 0;

	if ((s[0] != '\0') && (s[0] == '0')) {
		if ((s[0] != '\0') && (s[1] == 'x') || (s[1] == 'X')) {
			pos=2;
		}
	}

	for(int i=pos; s[i] != '\0'; i++) {
		c = s[i];
		value = 0;
		valid_hexdigit = TRUE;

		if ((c >= '0') && (c <= '9')) {
			value = c - '0';
		} else
		if ((c >= 'a') && (c <= 'f')) {
			value = c - 'a' + 10;
		} else
		if ((c >= 'A') && (c <= 'F')) {
			value = c - 'A' + 10;
		} else {
			valid_hexdigit = FALSE;
		}

		if (valid_hexdigit) {
			result = (result * 16) + value;
			// printf("%c = %d; now: %d\n", s[i], value, result);
		}
	}

	return result;
}


int main() {
	long result;
	char s[MAXLENGTH];

	while(our_crappy_getline(s, MAXLENGTH) > 0) {
		result = htoi(s);
		printf("%ld\n", result);
	}

	return 0;
}