/*
 *  Program to reverse the words in a given line.(Without reversing the letters.)
 */

#include <stdio.h>
#include <string.h>

int main(int argc, char **argv){
    char str[100];
    printf("Enter the line to reverse words: ");
    fgets(str, 100, stdin);

    int len = strlen(str);
    char str_new[len];
    static int space, buffer, end;
    int i,j,k;
    end = len-2;
    int start = 0;
    for(i=len-2; i>=0; i--){
        if(str[i]==' '){
            space = i;
            start = space+1;

            for(j=start; j<=end; j++)
            {
                str_new[buffer] = str[j];
                buffer++;
            }
            str_new[buffer] = ' ';
            buffer++;
            end = space-1;
            continue;
        }
        else if(i==0){
            for(j=i; j<=end; j++){
                str_new[buffer] = str[j];
                buffer++;
            }
            str_new[buffer] = '\0';
        }
    }
    printf("Reversed string is: %s\n", str_new);
    return 0;
}
