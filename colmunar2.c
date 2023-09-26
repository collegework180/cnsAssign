#include <stdio.h>

#include <string.h>

#include <ctype.h>
 // Function to perform encryption using Columnar Transposition cipher
void encrypt(char plaintext[], char key[]) {
    int textLength = strlen(plaintext);
    int keyLength = strlen(key);
    int rows = (textLength + keyLength - 1) / keyLength;
    char matrix[rows][keyLength];
    int index = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < keyLength; j++) {
            if (index < textLength) {
                matrix[i][j] = plaintext[index++];
            } else {
                matrix[i][j] = 'X'; // Padding with 'X' if needed
            }
        }
    }
    for (int j = 0; j < keyLength; j++) {
        for (int i = 0; i < rows; i++) {
            printf("%c", matrix[i][key[j] - '1']);
        }
    }
    printf("\n");
}
void decrypt(char ciphertext[], char key[]) {
    int textLength = strlen(ciphertext);
    int keyLength = strlen(key);
    int rows = textLength / keyLength;
    char matrix[rows][keyLength];
    int index = 0;
    for (int j = 0; j < keyLength; j++) {
        for (int i = 0; i < rows; i++) {
            matrix[i][key[j] - '1'] = ciphertext[index++];
        }
    }
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < keyLength; j++) {
            printf("%c", matrix[i][j]);
        }
    }
    printf("\n");
}
int main() {
    char key[100];
    printf("Enter the columnar transposition key (e.g., 2314): ");
    scanf("%s", key);
    char text[100];
    printf("Enter the text to be encrypted/decrypted: ");
    scanf(" %[^\n]", text);
    int choice;
    printf("Choose an operation:\n1. Encrypt\n2. Decrypt\n");
    scanf("%d", & choice);
    switch (choice) {
    case 1:
        encrypt(text, key);
        break;
    case 2:
        decrypt(text, key);
        break;
    default:
        printf("Invalid choice.\n");
        return 1;
    }
    return 0;
}
