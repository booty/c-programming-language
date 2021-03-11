#include <stdio.h>
#include <string.h>
#include <limits.h>

#define abs(x) ((x) < 0 ? -(x) : (x))

/*
Exercise 3-4. In a two's complement number representation, our version
of itoa does not handle the largest negative number, that is, the
value of n equal to -(2^(wordsize-l)). Explain why not. Modify it to
print that value correctly, regardless of the machine on which it
runs.
*/


/*

-----[ Background Because I Forgot All This Crap 25 Years Ago ]-----

-- What is two's complement? --

https://www.cs.cornell.edu/~tomf/notes/cps104/twoscomp.html

Two's complement is the way every computer I know of chooses to represent integers.

To reverse the sign of an integer, you:

1. write out the number in binary
2. invert the digits
3. add one to the result

Suppose we want to find out how -28 would be expressed in two's compliment.

Write +28 in binary: 0011100
Flip the bits: 1100011
Add one: 11100100


-- How to tell if a number is negative? --

If it (binary) starts with a 1, it's negative.


-- Why? --

One of the nice properties of two's complement is that addition and subtraction is made very simple. With a system like two's complement, the circuitry for addition and subtraction can be unified, whereas otherwise they would have to be treated as separate operations.


-----[ Answer to the Exercise's Question]----

A: Subtracting 1 from the smallest possible two's compliment number causes it to "wrap around" and become the highest possible number.  Example:

We start with:

  Decimal: -2147483648 (INT_MIN)
  Binary: 10000000000000000000000000000000

We subtract 1 and it becomes:

  Binary: 01111111111111111111111111111111
  Decimal: 2147483649 (INT_MAX)

*/

void reverse(char s[]) {
  int c, i, j;

  for(i = 0, j = strlen(s)-1; i < j; i++, j--) {
    c = s[i];
    s[i] = s[j];
    s[j] = c;
  }
}



/* itoa: convert n to characters in s */

void itoa_book_version(int n, char s[]) {
  int i, sign;

  if ((sign = n) < 0)           /* record sign */
    n = -n;                     /* make n positive */

  i = 0;

  do {                          /* generate digits in reverse order */
    s[i++] = n % 10 + '0';      /* get next digit */
  } while ((n = n/10) > 0);     /* delete it */

  if (sign < 0) s[i++] = '-';

  s[i] ='\0';

  reverse(s);
}

/* Disclaimer: had to use the answer book for this one */

void itoa_new_version(int n, char s[]) {
  int i, is_negative;

  is_negative = (n < 0);

  i = 0;

  do {                               /* generate digits in reverse order */
    s[i++] = abs(n % 10) + '0';      /* get next digit */
  } while ((n = n/10) != 0);          /* delete it */

  if (is_negative) s[i++] = '-';

  s[i] ='\0';

  reverse(s);
}

void test_itoa(int n) {
  printf("---[Book version]-----------------\n");
  printf("input: %d\n", n);

  char result_book[50];
  char result_new[50];
  itoa_book_version(n, result_book);
  itoa_new_version(n, result_new);

  printf("book ver. output: %s\n", result_book);
  printf("new ver. output:  %s\n", result_new);
}



int main() {
  printf("signed int min: %d\n", INT_MIN);
  printf("signed int max: %d\n", INT_MAX);
  test_itoa(1);
  test_itoa(-123);
  test_itoa(42);
  test_itoa(0);
  test_itoa(-99999);
  test_itoa(INT_MIN);


  return 0;

}