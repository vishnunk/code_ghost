/*
 *  Function to remove duplicates in an integer array.
 */

#include <stdio.h>

int main(int argc, char **argv){
    int size;
    int i;
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    int array[size];
    printf("Enter the array elements: \n");

    for(i=0; i<size; i++)
    {
        printf("\t");
        scanf("%d", &array[i]);
    }
    
    return 0;
}
