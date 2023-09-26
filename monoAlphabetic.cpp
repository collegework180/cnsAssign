#include <iostream>
#include <string>

using namespace std;

// Function to perform encryption using monoalphabetic cipher
void encrypt(string& plaintext, const string& key) {
    int length = plaintext.length();
    for (int i = 0; i < length; i++) {
        if (isalpha(plaintext[i])) {
            char originalChar = tolower(plaintext[i]);
            int index = originalChar - 'a';
            plaintext[i] = isupper(plaintext[i]) ? toupper(key[index]) : key[index];
        }
    }
}

// Function to perform decryption using monoalphabetic cipher
void decrypt(string& ciphertext, const string& key) {
    int length = ciphertext.length();
    for (int i = 0; i < length; i++) {
        if (isalpha(ciphertext[i])) {
            char encryptedChar = tolower(ciphertext[i]);
            for (int j = 0; j < 26; j++) {
                if (encryptedChar == tolower(key[j])) {
                    ciphertext[i] = isupper(ciphertext[i]) ? toupper('a' + j) : 'a' + j;
                    break;
                }
            }
        }
    }
}

int main() {
    string key;
    cout << "Enter the substitution key (26 letters in any order): ";
    cin >> key;

    string text;
    cin.ignore(); // Clear the newline character from the buffer
    cout << "Enter the text to be encrypted: ";
    getline(cin, text);

    // Encrypt the text
    encrypt(text, key);
    cout << "Encrypted text: " << text << endl;

    // Decrypt the text
    decrypt(text, key);
    cout << "Decrypted text: " << text << endl;

    return 0;
}
