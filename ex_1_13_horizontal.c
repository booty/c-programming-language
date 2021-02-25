#include <stdio.h>

#define IN 1
#define OUT 0
#define MAX_WORD_LENGTH 5
#define MAX_BAR_WIDTH 10


/*
Exercise l-13. Write a program to print a histogram of the lengths of words in its input. It is easy to draw the histogram with the bars horizontal; a vertical orientation is more challenging.

(This is the "horizontal orientation" version)
*/

int main() {
	int word_lengths[MAX_WORD_LENGTH + 1];
	int current_len;
	int current_state = OUT;
	int c;

	for(int i=0; i < MAX_WORD_LENGTH; i++) {
		word_lengths[i] = 0;
	}

	while ((c = getchar()) != EOF) {
		if (c == ' ' || c == '\n' || c == '\t') {
			if ((current_state == IN) && (current_len <= MAX_WORD_LENGTH)) {
				word_lengths[current_len]++;
			}
			current_state = OUT;
		}
		else if (current_state == IN) {
			current_len++;
		}
		else {
			current_state = IN;
			current_len = 1;
		}
	}

	printf("Length   Count\n");
	printf("------   -----\n");
	for(int i=1; i <= MAX_WORD_LENGTH; i++) {
		if (word_lengths[i] > 0) {
			printf("%6i   %5i\t", i, word_lengths[i]);

			for(int j=1; ((j <= word_lengths[i]) && (j <= MAX_BAR_WIDTH)); j++) {
				putchar('*');
			}
			putchar('\n');
		}
	}
}