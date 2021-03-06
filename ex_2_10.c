#include <stdio.h>

#define OFFSET 'a' - 'A'

/*
Rewrite the function "lower", which converts upper
case letters to lower case, with a conditional
expression instead of if-else
*/

char lower(c) {
	return ((c >= 'A') && (c <= 'Z'))
		?	(c + OFFSET)
		: c
	;
}

void test(char c) {
	printf("input:%c output:%c\n", c, lower(c));
}

int main() {
	test('A');
	test('a');
	test('0');
	test('J');
	return 0;
}