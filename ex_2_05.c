#include <stdio.h>

/*
Exercise 2-5. Write the function any(s1,s2), which
returns the first location in the string s1 where
any character from the string s2 occurs, or -1 if
s1 contains no characters from s2. (The standard
library function strpbrk does the same job but
returns a pointer to the location.)
*/


int any(char s1[], char s2[]) {
	for(int s1_pos=0; s1[s1_pos] != '\0'; s1_pos++) {
		for(int s2_pos=0; s2[s2_pos] != '\0'; s2_pos++) {
			if (s1[s1_pos] == s2[s2_pos]) return s1_pos;
		}
	}
	return -1;
}


void test(char haystack[], char needle[]) {
	printf(
		"haystack: %25s \tneedle: %s \t result: %4d\n",
		haystack,
		needle,
		any(haystack, needle)
	);
}

int main() {
	int result;

	char haystack1[] = "This is a test message";
	char haystack2[] = "";
	char needle1[] = "xyz";
	char needle2[] = "";
	char needle3[] = "s";

	test(haystack1, needle1);
	test(haystack1, needle2);
	test(haystack1, needle3);
	test(haystack2, needle1);
	test(haystack2, needle2);
	test(haystack2, needle3);
	test("yourmom", "y");
	test("yourmom!", "!");

	return 0;
}