#include <iostream>
#include <cstring>

using namespace std;

// Function to perform encryption using Rail Fence cipher
void encrypt(char plaintext[], int rails) {
    int length = strlen(plaintext);
    char encryptedText[length];
    int index = 0;
    for (int i = 0; i < rails; i++) {
        for (int j = i; j < length; j += rails) {
            encryptedText[index++] = plaintext[j];
        }
    }
    encryptedText[index] = '\0';
    strcpy(plaintext, encryptedText);
}

// Function to perform decryption using Rail Fence cipher
void decrypt(char ciphertext[], int rails) {
    int length = strlen(ciphertext);
    char decryptedText[length];
    int index = 0;
    for (int i = 0; i < rails; i++) {
        for (int j = i; j < length; j += rails) {
            decryptedText[j] = ciphertext[index++];
        }
    }
    decryptedText[length] = '\0';
    strcpy(ciphertext, decryptedText);
}

int main() {
    int rails;
    cout << "Enter the number of rails: ";
    cin >> rails;

    cin.ignore(); // Clear the newline character from the buffer

    char text[100];
    cout << "Enter the text to be encrypted: ";
    cin.ignore();
    cin.getline(text, 100);

    // Encrypt the text
    encrypt(text, rails);
    cout << "Encrypted text: " << text << endl;

    // Decrypt the text
    decrypt(text, rails);
    cout << "Decrypted text: " << text << endl;

    return 0;
}
