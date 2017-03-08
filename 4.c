/*
 *	Program to check whether the current machine is little-endian or big-endian.
 */

#include <stdio.h>

int main(int argc, char **argv){
	int check = 0x12345678;

	//Pointing address of check to char*.
	char *ptr = (char *) &check;

	if(*ptr == 0x12)
		printf("The machine is Big-endian\n");
	else 
		printf("The machine is Little-endian\n");

	return 0;
}
