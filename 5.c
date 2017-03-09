/*
 *  Implement sizeof operator.
 */

#include <stdio.h>

#define do_sizeof(x) (char *)(&x + 1) - (char *)(&x)

int main(int argc, char **argv){
    int integer;
    double double_var;
    char c;
    printf("Size of int is    : %d\n", do_sizeof(integer));
    printf("Size of double is : %d\n", do_sizeof(double_var));
    printf("Size of char is    : %d\n", do_sizeof(c));
    return 0;
}
