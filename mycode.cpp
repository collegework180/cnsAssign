#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>

using namespace std;

class InnovativeCipher {
public:
    InnovativeCipher(int shift) : shift_(shift % 26) {}

    string encrypt(const string &plaintext) {
        string shiftedText = caesarShift(plaintext, shift_);
        return convertToHex(shiftedText);
    }

    string decrypt(const string &ciphertext) {
        string asciiText = convertFromHex(ciphertext);
        return caesarShift(asciiText, 26 - shift_);
    }

private:
    string caesarShift(const string &text, int shift) {
        string result = "";
        for (char c : text) {
            if (isalpha(c)) {
                char base = isupper(c) ? 'A' : 'a';
                c = (c - base + shift) % 26 + base;
            }
            result += c;
        }
        return result;
    }

    string convertToHex(const string &text) {
        stringstream ss;
        for (char c : text) {
            ss << std::hex << std::setw(2) << std::setfill('0') << (int)(unsigned char)c;
        }
        return ss.str();
    }

    string convertFromHex(const string &hexText) {
        string asciiText = "";
        for (size_t i = 0; i < hexText.length(); i += 2) {
            string byte = hexText.substr(i, 2);
            char c = static_cast<char>(stoi(byte, nullptr, 16));
            asciiText += c;
        }
        return asciiText;
    }

    int shift_;
};

int main() {
    InnovativeCipher cipher(3);  // Shift of 3
    string plaintext = "Hello, World!";
    
    string ciphertext = cipher.encrypt(plaintext);
    cout << "Encrypted: " << ciphertext << endl;

    string decryptedText = cipher.decrypt(ciphertext);
    cout << "Decrypted: " << decryptedText << endl;

    return 0;
}
