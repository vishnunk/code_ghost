/*
 * Create a function to dynamically allocate memory for a 2D array in C.
 */

#include <stdio.h>

void allocate(int ***array, int r, int c){
    int i;
    *array = (int **)malloc(r * sizeof(int*));
    for(i=0; i<r; i++)
        (*array)[i] = (int*)malloc(c * sizeof(int));
    printf("Allocated memory dynamically for array[%d][%d]\n", r, c);
}

void deallocate(int ***array, int r){
    int i;
    for(i=0; i<r; i++)
        free((*array)[i]);
    free(*array);
    printf("Deallocated memory for array\n");
}

int main(int argc, char **argv){
    int **array;
    int row, coloumn;
    printf("Enter the number of rows: ");
    scanf("%d", &row);
    printf("Enter the number of coloumns: ");
    scanf("%d", &coloumn);
    allocate(&array, row, coloumn);
    array[2][3] = 5;
    printf("The value in array[2][3] is: %d\n", array[2][3]);
    deallocate(&array, row);
    printf("The value in array[2][3] is: %d\n", array[2][3]);
    return 0;
}
