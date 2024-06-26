// Write a program in C to implement Caeser Cipher 
#include<stdio.h>
#include<string.h>
#include<ctype.h>

int main() {

    char text[500], ch;
    int key;

    // Taking user input.
    printf("Enter a message to encrypt: ");
    scanf("%s", text);

    printf("Enter the key: ");
    scanf("%d", & key);

    // Visiting character by character.
    int length = strlen(text);

    for (int i = 0; i<length; i++) {

        ch = text[i];
        // Check for valid characters ie, alphanumeric
        if (isalnum(ch)) {
            //Lowercase characters.
            if (islower(ch)) {
                ch = (ch - 'a' + key) % 26 + 'a';
            }
            // Uppercase characters.
            if (isupper(ch)) {
                ch = (ch - 'A' + key) % 26 + 'A';
            }
            // Numbers.
            if (isdigit(ch)) {
                ch = (ch - '0' + key) % 10 + '0';
            }
        }
        // Invalid character.
        else {
            printf("Invalid Message");
        }

        // Adding encoded answer.
        text[i] = ch;

    }
    printf("Encrypted message: %s", text);
    return 0;
}
