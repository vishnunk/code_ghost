/*
 *  Program to set, clear, toggle the bits in a given integer.
 */

#include <stdio.h>

int set_bit(int *ptr, int n){
	*ptr = *ptr | (1 << n);
	return *ptr;
}

int clear_bit(int *ptr, int n){
	*ptr = *ptr & ~(1 << n);
	return *ptr;
}

int main(int argc, char **argv){
	unsigned int x, operation, bit;
	int value;
	printf("Enter the integer value: ");
	scanf("%d", &x);
	printf("Enter the operation you want to perform:\n\t1. Set nth bit\n\t2. Clear nth bit\n\t3. Toggle nth bit\n");
	scanf("%d", &operation);
	printf("Enter the bit position where you want to perform the operation[0-7]: ");
	scanf("%d", &bit);

	if(operation == 1){
		printf("Performing set operation on %dth bit\n", bit);
		value = set_bit(&x, bit);
		printf("The integer value after set operation on %dth bit is: %d\n", bit, value);

	}
	else if(operation == 2){
		printf("Performing clear operation on %dth bit\n", bit);
		value = clear_bit(&x, bit);
		printf("The integer value after clear operation on %dth bit is: %d\n", bit, value);
	}
	else if(operation == 3){
		printf("Performing toggle operation on %dth bit\n", bit);
		//toggle_bit(&x, bit);
	}
	else
		printf("Invalid operation. Please run the program again with proper input.\n");
	return 0;
}
