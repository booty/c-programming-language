#include <stdio.h>

/*
Modify the temperature conversion program to print the table in reverse order, that is, from 300 degrees to 0.
*/

int main() {
	for (int fahr = 300; fahr >= 0; fahr -= 20) {
		int celc = 5 * (fahr-32) / 9;
		printf("f:%5i\tc:%5i\n", fahr, celc);
	}

	return 0;
}
