#include <stdio.h>

#define TRUE 1
#define FALSE 0

/*
Write an alternate version of squeeze (s1, s2)
that deletes each character in s1 that matches
any character in the string s2.
*/

void squeeze(char s1[], char s2[]) {
	int write_pos=0;
	int read_pos=0;
	int search_pos=0;
	int found;
	char c, c_search;
	while((c = s1[read_pos]) != '\0') {
		found = FALSE;
		search_pos = 0;
		while( ((c_search = s2[search_pos]) != '\0') && !found) {
			found = (c == c_search);
			search_pos++;
		}

		// if (found) printf("found!\n");

		if (!found) {
			s1[write_pos] = c;
			write_pos++;
		}

		read_pos++;
	}

	s1[write_pos] = '\0';
}

int main() {
	char msg[] = "DEHUMANIZE YOURSELF and FACE TO BLOODSHED!";
	char badchars[] = "aeiouAEIOU";
	squeeze(msg, badchars);

	printf("%s\n", msg);
	return 0;
};