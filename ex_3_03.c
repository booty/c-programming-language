/*
Exercise 3-3. Write a function expand(s1,s2) that expands shorthand
notations like a-z in the string s 1 into the equivalent complete list
abc...xyz in s2. Allow for letters of either case and digits, and be
prepared to handle cases like a-b-c and a-z0-9 and -a-z. Arrange that a
leading or trailing - is taken literally.
*/

#include <stdio.h>

#define MAXLENGTH 30  // maximum length of the expanded string

/*
Loop through src until c==\0 or dstpos <= maxlength
	is srcpos < 2?
		if yes
			do nothing
		if no
			is the current character the END of a shorthand?
				if yes
					output the expanded characters
						for each one,
							increment destpos and ensure we haven't exceeded maxlength
				if no
					output src[srcpos-2] and increment destpos unless destpos = maxlen
output src[srcpos-1] and src[srcpos] if not null and < maxlength

the current character is the END of a shorthand, if...
	current character is between ! and ~
	previous character is -
	prevprev character is betwen ! and ~
*/


int is_expansion_char(char c) {
	return ((c != '-') && (c >= '!') && (c <= '~'));
}

// This is extremely ASCII-specific
void ascii_expand(char src[], char dst[], int maxlength) {
	int src_pos = 0;
	int dst_pos = 0;
	int should_perform_expansion;
	char prev_prev_char;
	char c; // current char from src
	int last_expansion_end_pos = -999;

	while (((c = src[src_pos]) != '\0') && (dst_pos < maxlength)) {
		if (src_pos < 2) {
			src_pos++;
			continue;
		}

		prev_prev_char = src[src_pos - 2];

		should_perform_expansion = (
			(src[src_pos-1] == '-') &&
			is_expansion_char(c) &&
			is_expansion_char(prev_prev_char)
		);

		if (should_perform_expansion) {
			last_expansion_end_pos = src_pos;
			// ascending expansion
			if (prev_prev_char <= c) {
				for(char c2 = prev_prev_char; ((c2<=c) && (dst_pos < maxlength)); c2++)
					dst[dst_pos++] = c2;
			}
			// descending expansion
			else {
				for(char c2 = prev_prev_char; ((c2>=c) && (dst_pos < maxlength)); c2--)
					dst[dst_pos++] = c2;
			}
		}
		else {
			if (src_pos-2 > last_expansion_end_pos)
				dst[dst_pos++] = prev_prev_char;
		}

		src_pos++;
	}

	if (src_pos-3 > last_expansion_end_pos) {
		if ((src_pos > 1) && (dst_pos < maxlength)) dst[dst_pos++] = src[src_pos-2];
		if ((src_pos > 0) && (dst_pos < maxlength)) dst[dst_pos++] = src[src_pos-1];
	}
	dst[dst_pos] = '\0';
}


void test_expand(char src[]) {
	char dst[MAXLENGTH];

	ascii_expand(src, dst, MAXLENGTH);

	printf("----------------------------------------------\n");
	printf("      0123456789012345678901234567890123456789\n");
	printf("src: [%s]\n", src);
	printf("dst: [%s]\n", dst);
}

int main() {
	test_expand("a");
	test_expand("ab");
	test_expand("abc");
	test_expand("Hello world");
	test_expand("01234567890123456789012345678901234567890123456789012345678901234567890123456789");
	test_expand("");
	test_expand(" ");
	test_expand("  ");
	test_expand("a-g");
	test_expand("3-8");
	test_expand("a-z");
	test_expand("z-a");
	test_expand("a-a");
	test_expand("I know my 1-3 and my a-c.");
	test_expand("But do I know a-f1-6?");
	test_expand("Nobody knows 9-5 or f-a or Z-M");
	test_expand("a-b-c");
	test_expand("a-z");
	test_expand("a-");
	test_expand("-z");
	test_expand("--z");
	test_expand("--z");
	test_expand("a-c1-3");
	return 0;
}