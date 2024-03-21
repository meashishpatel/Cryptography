// Exp1: Write a C program that contains a string (charpointer) with a value\Hello World’.
// The program should XOR each character in this string with 0 and display the result.
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
    
    char string[] = "Hello World";
    char string1[11];
    int length = strlen(string);
    for(int i = 0; i < length; i++){
        string1[i] = string[i]^0;
        printf("%c", string1[i]);
    }
    printf("\n");
    return 0;
}