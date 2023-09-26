#include <iostream>
#include <string>

using namespace std;

// Function to perform encryption using Vernam cipher
void encrypt(string& plaintext, const string& key) {
    int length = plaintext.length();
    for (int i = 0; i < length; i++) {
        if (isalpha(plaintext[i])) {
            plaintext[i] = (toupper(plaintext[i]) - 'A' + key[i] - 'A') % 26 + 'A';
        }
    }
}

// Function to perform decryption using Vernam cipher
void decrypt(string& ciphertext, const string& key) {
    int length = ciphertext.length();
    for (int i = 0; i < length; i++) {
        if (isalpha(ciphertext[i])) {
            int decryptedChar = (ciphertext[i] - key[i] + 26) % 26;
            ciphertext[i] = decryptedChar + 'A';
        }
    }
}

int main() {
    string key;
    cout << "Enter the encryption key (same length as the text): ";
    cin >> key;

    cin.ignore(); // Clear the newline character from the buffer

    string text;
    cout << "Enter the text to be encrypted: ";
    cin.ignore();
    getline(cin, text);

    if (text.length() != key.length()) {
        cout << "Error: Key length must match text length." << endl;
        return 1;
    }

    // Encrypt the text
    encrypt(text, key);
    cout << "Encrypted text: " << text << endl;

    // Decrypt the text
    decrypt(text, key);
    cout << "Decrypted text: " << text << endl;

    return 0;
}
