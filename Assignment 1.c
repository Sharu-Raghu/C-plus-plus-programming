//Sharanya Raghunath 11250416 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char value[100], which;

int count, length, number, decimal, binary;

int main() {
	printf("Type a number: ");
	gets(value);
	length = strlen(value);
	number = atoi(value);
	for (count = 0; count < length; count++) {
		if (value[count] >= 'a') {
			printf("That is an invalid number!\n");
			exit(9);
		}
		if ((value[count] == '0') || (value[count] == '1')) {
			which = 'd';
		} else {
			if ((number <= -1) || (number >= 256)) {
				printf("That is an invalid number!\n");
				exit(9);
			} else {
				which = 'b';
			}
		}
	}
	if (which == 'b') {
		printf("Converting decimal to binary. Answer is: ");
		for (count = 7; count >= 0; count--) {
			binary = number >> count;
			if (binary & 1) {
				printf("1");
			} else {
				printf("0");
			}
		}
		printf("\n");
	}
	if (which == 'd') {
		printf("Converting binary to decimal. Answer is: ");
		for (count = 0; count < length; count++) {
			decimal = decimal * 2 + (value[count] == '1' ? 1 : 0);
		}
		printf("%d\n", decimal);
	}
}
