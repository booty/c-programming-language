/*
Exercise 3-2. Write a function escape (s, t) that converts characters
like newline and tab into visible escape sequences like \n and \ t as
it copies the string t to s. Use a switch.

Write a function for the other direction as well, converting escape
sequences into the real characters.
*/

#include <stdio.h>

#define MAXLENGTH 100
#define TRUE 1
#define FALSE 0


// convert newline and tab into visible escape sequences
void escape(char src[], char dest[], int maxlength) {
	int src_pos = 0;
	int dest_pos = 0;
	char c;

	while (((c = src[src_pos]) != '\0') && (dest_pos < maxlength)) {
		switch (c) {
			case '\n':
				dest[dest_pos++] = '\\';
				dest[dest_pos++] = 'n';
				break;
			case '\t':
				dest[dest_pos++] = '\\';
				dest[dest_pos++] = 'n';
				break;
			default:
				dest[dest_pos++] = c;
				break;
		}
		src_pos++;
	}
	dest[dest_pos] = '\0';
}

void test_escape(char src[]) {
	char dest[MAXLENGTH];

	escape(src, dest, MAXLENGTH);

	printf("------------------------------------------\n");
	printf("src: [%s]\n", src);
	printf("dest: [%s]\n", dest);
}

// convert escape sequences into real characters
// works, but the one in the answer book is much more succinct
void unescape(char src[], char dest[], int maxlength) {
	int src_pos = 0;
	int dest_pos = 0;
	char c = src[0];
	int prev_was_backslash = FALSE;

	while (((c = src[src_pos++]) != '\0') && (src_pos < maxlength)) {
		if (prev_was_backslash) {
			switch(c) {
				case 'n':
					dest[dest_pos++] = '\n';
					break;
				case 't':
					dest[dest_pos++] = '\t';
					break;
				default:
					dest[dest_pos++] = '\\';
					dest[dest_pos++] = c;
			}
			prev_was_backslash = FALSE;
		}
		else {
			switch(c) {
				case '\\':
					prev_was_backslash = TRUE;
					break;
				default:
					prev_was_backslash = FALSE;
					dest[dest_pos++] = c;
			}
		} // if prev_was_backslash
	}
	if (prev_was_backslash) dest[dest_pos++] = '\\';
	dest[dest_pos] = '\0';
}

void test_unescape(char src[]) {
	char dest[MAXLENGTH];

	unescape(src, dest, MAXLENGTH);

	printf("\n------------------------------------------\n");
	printf("src: [%s]\n", src);
	printf("dest: [%s]\n\n\n", dest);
}

int main() {
	char escape1[] = "tabs \t \t \t and newlines \n \n \n";
	char escape2[] = "just a boring string";
	char escape3[] = "way too long! tabs \t \t \t and newlines \n \n \n way too long! tabs \t \t \t and newlines \n \n \n way too long! tabs \t \t \t and newlines \n \n \n way too long! tabs \t \t \t and newlines \n \n \n";

	test_escape(escape1);
	test_escape(escape2);
	test_escape(escape3);

	char unescape1[] = "hello";
	char unescape2[] = "hello, three backslashes\\\\\\";
	char unescape3[] = "here are some newlines\\n\\n\\nok cool";
	char unescape4[] = "\\n\\nthose were newlines";
	char unescape5[] = "\\t\\t\\t<-- drank some Tab";
	char unescape6[] = "";
	char unescape7[] = "\\";
	char unescape8[] = "backslash at the end\\";
	char unescape9[] = "too long too long too long too long too long too long too long too long too long too long too long too long too long too long too long too long too long too long too long too long too long";

	test_unescape(unescape1);
	test_unescape(unescape2);
	test_unescape(unescape3);
	test_unescape(unescape4);
	test_unescape(unescape5);
	test_unescape(unescape6);
	test_unescape(unescape7);
	test_unescape(unescape8);
	test_unescape(unescape9);


	return 0;
}
