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




// Write a program in C to implement Monoalphabetic substitution cipher

#include<stdio.h>

char monocipher_encr(char);
char alpha[26][2] = { { 'a', 'f' }, { 'b', 'a' }, { 'c', 'g' }, { 'd', 'u' }, {
        'e', 'n' }, { 'f', 'i' }, { 'g', 'j' }, { 'h', 'k' }, { 'i', 'l' }, {
        'j', 'm' }, { 'k', 'o' }, { 'l', 'p' }, { 'm', 'q' }, { 'n', 'r' }, {
        'o', 's' }, { 'p', 't' }, { 'q', 'v' }, { 'r', 'w' }, { 's', 'x' }, {
        't', 'y' }, { 'u', 'z' }, { 'v', 'b' }, { 'w', 'c' }, { 'x', 'd' }, {
        'y', 'e' }, { 'z', 'h' } };

char str[20];
int main() {
    char str[20], str2[20];
    int i;
    printf("\n Enter String..");
    gets(str);
    for (i = 0; str[i]; i++) {
        str2[i] = monocipher_encr(str[i]);
    }
    str2[i] = '\0';
    printf("\n Before Decryption..%s", str);
    printf("\n After Decryption..%s\n", str2);
}

char monocipher_encr(char a) {
    int i;
    for (i = 0; i < 27; i++) {
        if (a == alpha[i][0])
            break;
    }
    return alpha[i][1];
} 





// Write a program in C to implement Vigenere (Polyalphabetic ) Cipher

#include<stdio.h>
#include<string.h>
 
int main(){
    char msg[] = "THECRAZYPROGRAMMER";
    char key[] = "HELLO";
    int msgLen = strlen(msg), keyLen = strlen(key), i, j;
 
    char newKey[msgLen], encryptedMsg[msgLen], decryptedMsg[msgLen];
    printf("Length of message:%ld\n",strlen(msg));
    printf("Length of key:%ld\n",strlen(key));
 
    //generating new key
    for(i = 0, j = 0; i < msgLen; ++i, ++j){
        if(j == keyLen)
            j = 0;
 
        newKey[i] = key[j];
    }
 
    newKey[i] = '\0';
 
    //encryption
    for(i = 0; i < msgLen; ++i)
        encryptedMsg[i] = ((msg[i] + newKey[i]) % 26) + 'A';
 
    encryptedMsg[i] = '\0';
 
    //decryption
    for(i = 0; i < msgLen; ++i)
        decryptedMsg[i] = (((encryptedMsg[i] - newKey[i]) + 26) % 26) + 'A';
 
    decryptedMsg[i] = '\0';
 
    printf("Original Message: %s", msg);
    printf("\nKey: %s", key);
    printf("\nNew Generated Key: %s", newKey);
    printf("\nEncrypted Message: %s", encryptedMsg);
    printf("\nDecrypted Message: %s", decryptedMsg);
 
return 0;
}




// Exp 9: Implementation and analysis of RSA cryptosystem and RSA/ElGamel

// RSA Algorithm
// 1.	Request two prime numbers from the user and verify them.
// 2.	Put the prime numbers in different variables.
// 3.	Determine n = pq.
// 4.	Calculate (n) = (p - 1)(q - 1)after the above step.
// 5.	Select a random number e that is close to being prime to both n and 1 e n.
// 6.	Determine d = e-1 mod n.
// 7.	Print out the private and public keys.
// 8.	Request a message from the user and then save it in a variable.
// 9.	Use the public key to encrypt the message.
// 10.	Using the private key, decrypt the message.
// 11.	Print the message, both encrypted and decrypted.
// Source Code: 
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

long int p, q, n, t, flag, e[100], d[100], temp[100], j, m[100], en[100], i;
char msg[100];

int prime(long int pr);
void ce();
long int cd(long int);
void encrypt();
void decrypt();

int main() {
    printf("\nENTER FIRST PRIME NUMBER: ");
    scanf("%ld", &p);
    flag = prime(p);
    if (flag == 0) {
        printf("\nWRONG INPUT\n");
        exit(1);
    }

    printf("\nENTER ANOTHER PRIME NUMBER: ");
    scanf("%ld", &q);
    flag = prime(q);
    if (flag == 0 || p == q) {
        printf("\nWRONG INPUT\n");
        exit(1);
    }

    printf("\nENTER MESSAGE: ");
    scanf("%s", msg);

    for (i = 0; msg[i] != '\0'; i++)
        m[i] = msg[i];

    n = p * q;
    t = (p - 1) * (q - 1);
    ce();

    printf("\nPOSSIBLE VALUES OF e AND d ARE\n");
    for (i = 0; i < j - 1; i++)
        printf("\n%ld\t%ld", e[i], d[i]);

    encrypt();
    decrypt();
    
    return 0;
}

int prime(long int pr) {
    int i, j;
    j = sqrt(pr);
    for (i = 2; i <= j; i++) {
        if (pr % i == 0)
            return 0;
    }
    return 1;
}

void ce() {
    int k;
    k = 0;
    for (i = 2; i < t; i++) {
        if (t % i == 0)
            continue;
        flag = prime(i);
        if (flag == 1 && i != p && i != q) {
            e[k] = i;
            flag = cd(e[k]);
            if (flag > 0) {
                d[k] = flag;
                k++;
            }
            if (k == 99)
                break;
        }
    }
}

long int cd(long int x) {
    long int k = 1;
    while (1) {
        k = k + t;
        if (k % x == 0)
            return (k / x);
    }
}

void encrypt() {
    long int pt, ct, key = e[0], k, len;
    i = 0;
    len = strlen(msg);
    while (i != len) {
        pt = m[i];
        pt = pt - 96;
        k = 1;
        for (j = 0; j < key; j++) {
            k = k * pt;
            k = k % n;
        }
        temp[i] = k;
        ct = k + 96;
        en[i] = ct;
        i++;
    }
    en[i] = -1;
    printf("\nTHE ENCRYPTED MESSAGE IS\n");
    for (i = 0; en[i] != -1; i++)
        printf("%c", en[i]);
}

void decrypt() {
    long int pt, ct, key = d[0], k;
    i = 0;
    while (en[i] != -1) {
        ct = temp[i];
        k = 1;
        for (j = 0; j < key; j++) {
            k = k * ct;
            k = k % n;
        }
        pt = k + 96;
        m[i] = pt;
        i++;
    }
    m[i]= -1;
    printf("\nTHE DECRYPTED MESSAGE IS\n");
    for (i = 0; m[i] != -1; i++)
        printf("%c", m[i]);
}


// Input & Output:
// 1.	ENTER FIRST PRIME NUMBER: 5  
// 2.	ENTER ANOTHER PRIME NUMBER: 17  
// 3.	ENTER MESSAGE: Jitendra  
// 4.	POSSIBLE VALUES OF e AND d ARE:  
// 5.	 5   65  
// 6.	11  59  
// 7.	13  25  
// 8.	17  89  
// 9.	23  47  
// 10.	29  41  
// 11.	31  7  
// 12.	37  73  
// 13.	41  29  
// 14.	THE ENCRYPTED MESSAGE IS:  
// 15.	I?j?x??a  
// 16.	THE DECRYPTED MESSAGE IS:  
// 17.	Jitendra  




// Exp 10. Implementation of Diffie/Hellman Key exchange algorithm.

#include<math.h>
#include<stdio.h>
 
// Power function to return value of a ^ b mod P
long long int power (long long int a, long long int b,long long int P)
{
    if (b == 1)
        return a;
 
    else
        return (((long long int) pow (a, b)) % P);
}
 
// Driver program
int main ()
{
    long long int P, G, x, a, y, b, ka, kb;
 
    // Both the persons will be agreed upon the
    // public keys G and P
    P = 23; // A prime number P is taken
    printf("The value of P : %lld\n", P);
 
    G = 9; // A primitive root for P, G is taken
    printf("The value of G : %lld\n\n", G);
 
    // Alice will choose the private key a
    a = 4; // a is the chosen private key
    printf("The private key a for Alice : %lld\n", a);
    x = power(G, a, P); // gets the generated key
 
    // Bob will choose the private key b
    b = 3; // b is the chosen private key
    printf("The private key b for Bob : %lld\n\n", b);
    y = power (G, b, P); // gets the generated key
 
    // Generating the secret key after the exchange
    // of keys
    ka = power (y, a, P); // Secret key for Alice
    kb = power (x, b, P); // Secret key for Bob
 
    printf("Secret key for the Alice is : %lld\n", ka);
    printf("Secret Key for the Bob is : %lld\n", kb);
 
    return 0;
}


// Input & Output: 
 
// The value of P: 23
// The value of G: 9

// The private key a for Alice: 4
// The private key b for Bob: 3

// Secret key for the Alice is: 9
// Secret Key for the Bob is: 9
