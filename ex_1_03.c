#include <stdio.h>

/*
Exercise l-3. Modify the temperature conversion program to print a heading above the table.
*/

int main() {
	float fahr, celc;
	float lower = 0;
	float upper = 300;
	float step = 20;

	fahr = lower;

	printf("%7s\t%7s\n", "F", "C");
	printf("%7s\t%7s\n", "-------", "-------");
	while (fahr <= upper) {
		celc = 5.0 * (fahr-32.0) / 9.0;
		printf("%7.1f\t%7.1f\n", fahr, celc);
		fahr += step;
	}

	return 0;
}
