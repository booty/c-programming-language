#include <stdio.h>

/*
Exercise l-4. Write a program to print the corresponding Celsius to Fahrenheit table
*/

int main() {
	float lower = 0;
	float upper = 300;
	float step = 20;
	float celc = lower;
	float fahr;

	printf("%7s\t%7s\n", "C", "F");
	printf("%7s\t%7s\n", "-------", "-------");
	while(celc <= upper) {
		fahr = (celc) * (9.0 / 5.0) + 32.0;
		printf("%7.1f\t%7.1f\n", celc, fahr);
		celc += step;
	}
}
