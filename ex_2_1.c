#include <stdio.h>
#include <limits.h>

/*
Exercise 2-1. Write a program to determine the ranges
of char, and long variables, both signed and
unsigned, by printing appropriate values from
standard headers and by direct computation. Harder if
you compute them: determine the ranges of the various
floating-point types.
*/


int main() {
	signed long cur=0, prev=0;

	// 8 bit on my machine
	printf("signed char min: %d\n", SCHAR_MIN);
	printf("signed char max: %d\n", SCHAR_MAX);

	// 16 bit on my machine
	printf("signed short min: %d\n", SHRT_MIN);
	printf("signed short max: %d\n", SHRT_MAX);

	// 32 bit on my machine
	printf("signed int min: %d\n", INT_MIN);
	printf("signed int max: %d\n", INT_MAX);

	// 64 bit on my machine
	printf("signed long min: %ld\n", LONG_MIN);
	printf("signed long max: %ld\n", LONG_MAX);

	// 8 bit on my machine
	printf("unsigned char max: %u\n", UCHAR_MAX);

	// 16 bit
	printf("unsigned short max: %u\n", USHRT_MAX);

	// 32 bit on my machine
	printf("unsigned int max: %u\n", UINT_MAX);

	// 64 bit on my machine
	printf("unsigned long max: %lu\n", ULONG_MAX);


	return 0;
}