/*
 *  Function to remove duplicates in an integer array.
 */

/*
 * The algorithms can be splitted as follows:
 *  1. Read array[i]
 *  2. Check presence of array[i] in array_new
 *      3. If array[i] not in array_new[j]
 *      4. Insert array[i] to array_new[j]
 *      6. If array[i] present in array_new[j]
 *      7. continue.
 */

int check_presence(int check, int *arr, int size){
    int j;
    int flag;
    for(j=0; j<size; j++)
    {
        if(check == arr[j])
        {
            flag = 1;
            break;
        }
        else 
            flag = 0;
    }
    return flag;
}

#include <stdio.h>

int main(int argc, char **argv){
    int size;
    int i;
    static int buffer = 0;
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    int array[size];
    int array_new[size];
    
    printf("Enter the array elements: \n");
    for(i=0; i<size; i++)
    {
        printf("\t");
        scanf("%d", &array[i]);
    }
    
    for(i=0; i<size; i++){
        if(check_presence(array[i], array_new, size))
            continue;
        else
        {
            array_new[buffer] = array[i];
            buffer++;
        }
    }

    printf("The new array with removed duplicates is: ");
    for(i=0; i<buffer; i++)
        printf("%d ", array_new[i]);
    printf("\n");
    return 0;
}
