#include <stdio.h>

/*
Exercise 1-15. Rewrite the temperature conversion
program of Section 1.2 to use a function for conversion.
*/

float f_to_c(int f) {
	return 5.0 * (f - 32.0) / 9.0;
}

void ex_1_15() {
	for(float temp = 0.0; temp <= 100; temp += 1.0) {
		printf("%7.1f%7.1f\n", temp, f_to_c(temp));
	}
}