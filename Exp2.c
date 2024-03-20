// Write a C program that contains a string (char pointer) with a value \Hello World’. 
// The program should AND and XOR each character in this string with 127 and 255 respectively display the result.

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){

    char str[] = "Hello World";
    char str1[11];
    char str2[11];

    int length = strlen(str);
    for(int i = 0; i<length; i++){
        str1[i] = str[i]&127;
        printf("%c", str1[i]);
    }
    printf("\n");


    for(int i = 0; i<length; i++){
        str2[i] = str[i]^255;
        printf("%c", str2[i]);
    }

    return 0;
}