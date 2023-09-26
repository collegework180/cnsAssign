#include <iostream>
#include <cmath>

using namespace std;

// Function to calculate (base^exponent) % modulus
long long int power(long long int base, long long int exponent, long long int modulus) {
    if (exponent == 0) return 1;
    if (exponent % 2 == 0) {
        long long int half_pow = power(base, exponent / 2, modulus);
        return (half_pow * half_pow) % modulus;
    } else {
        return (base * power(base, exponent - 1, modulus)) % modulus;
    }
}

int main() {
    long long int p, g, privateA, privateB;
    cout << "Enter prime number (p): ";
    cin >> p;
    cout << "Enter primitive root (g): ";
    cin >> g;

    // Alice's private key
    cout << "Alice's private key (a): ";
    cin >> privateA;

    // Bob's private key
    cout << "Bob's private key (b): ";
    cin >> privateB;

    // Calculate public keys
    long long int publicA = power(g, privateA, p);
    long long int publicB = power(g, privateB, p);

    cout << "\nPublicly exchanged values:\n";
    cout << "Alice sends: " << publicA << "\n";
    cout << "Bob sends: " << publicB << "\n";

    // Simulating the Man-In-The-Middle attack
    long long int interceptedA, interceptedB;
    cout << "\n--Man-In-The-Middle Attack--\n";
    cout << "Enter intercepted value sent by Alice: ";
    cin >> interceptedA;
    cout << "Enter intercepted value sent by Bob: ";
    cin >> interceptedB;

    // Calculate the shared secret key by the attacker
    long long int sharedSecretA = power(interceptedB, privateA, p);
    long long int sharedSecretB = power(interceptedA, privateB, p);

    cout << "\nShared Secret Key calculated by the Attacker:\n";
    cout << "Shared Secret Key for Alice: " << sharedSecretA << "\n";
    cout << "Shared Secret Key for Bob: " << sharedSecretB << "\n";

    return 0;
}
