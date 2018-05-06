//Sharanya Raghunath 11250416 

#include <stdio.h>
#include <string.h>

unsigned int number1, number2, number3, count;

char instruction[5];

unsigned int arithmetic_shift_right(unsigned int a, unsigned int b);
unsigned int rotate_left(unsigned int a, unsigned int b);
unsigned int rotate_right(unsigned int a, unsigned int b);

int main() {
	printf("Type in an expression: ");
	scanf("%x %s %x", &number1, instruction, &number2);
	if (strcmp (instruction, "add") == 0) {
		number3 = number1 + number2;
		printf("The answer is: %x\n", number3);
	}
	if (strcmp (instruction, "sub") == 0) {
		number3 = number1 - number2;
		printf("The answer is: %x\n", number3);
	}
	if (strcmp (instruction, "and") == 0) {
		number3 = number1 & number2;
		printf("The answer is: %x\n", number3);
	}
	if (strcmp (instruction, "or") == 0) {
		number3 = number1 | number2;
		printf("The answer is: %x\n", number3);
	}
	if (strcmp (instruction, "xor") == 0) {
		number3 = number1 ^ number2;
		printf("The answer is: %x\n", number3);
	}
	if (strcmp (instruction, "shl") == 0) {
		for (count = 0; count < number2; count++) {
			number3 = number1 << number2;
		}
		printf("The answer is: %x\n", number3);
	}
	if (strcmp (instruction, "shr") == 0) {
		for (count = 0; count < number2; count++) {
			number3 = number1 >> number2;
		}
		printf("The answer is: %x\n", number3);
	}
	if (strcmp (instruction, "asr") == 0) {
		number3 = arithmetic_shift_right(number1, number2);
		printf("The answer is: %x\n", number3);
	}
	if (strcmp (instruction, "rol") == 0) {
		number3 = rotate_left(number1, number2);
		printf("The answer is: %x\n", number3);
	}
	if (strcmp (instruction, "ror") == 0) {
		number3 = rotate_right(number1, number2);
		printf("The answer is: %x\n", number3);
	}
}

unsigned int arithmetic_shift_right(unsigned int a, unsigned int b) {
	if (a < 0 && b > 0) {
		return a >> b | ~ (~0U >> b);
	} else {
		return a >> b;
	}
}

unsigned int rotate_left(unsigned int a, unsigned int b) {
	return ((a << b) | (a >> (32 - b)));
}

unsigned int rotate_right(unsigned int a, unsigned int b) {
	return ((a >> b) | (a << (32 - b)));
}
