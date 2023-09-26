#include <iostream>
#include <cmath>

using namespace std;

int power_modulo(int base, int exponent, int mod) {
    int result = 1;
    base %= mod;

    while (exponent > 0) {
        if (exponent % 2 == 1)
            result = (result * base) % mod;

        exponent >>= 1;
        base = (base * base) % mod;
    }

    return result;
}

int main() {
    int p, g, a, b, e;

    // Get public parameters from the user
    cout << "Enter the prime number (p): ";
    cin >> p;

    cout << "Enter the primitive root modulo p (g): ";
    cin >> g;

    // Get secret keys from Alice, Bob, and the attacker
    cout << "Enter Alice's secret key (a): ";
    cin >> a;

    cout << "Enter Bob's secret key (b): ";
    cin >> b;

    cout << "Enter the attacker's secret key (e): ";
    cin >> e;

    // Compute A and B
    int A = power_modulo(g, a, p);
    int B = power_modulo(g, b, p);

    // Simulate interception by the man-in-the-middle
    int intercepted_A = power_modulo(g, e, p);
    int intercepted_B = power_modulo(g, e, p);

    // Calculate the shared secret key for Alice and the attacker
    int secret_key_alice = power_modulo(intercepted_B, a, p);

    // Calculate the shared secret key for the attacker and Bob
    int secret_key_attacker = power_modulo(intercepted_A, e, p);

    // Display the simulated intercepted and manipulated values
    cout << "Intercepted A (by attacker): " << intercepted_A << endl;
    cout << "Intercepted B (by attacker): " << intercepted_B << endl;

    // Display the shared secret keys (Alice and attacker, and attacker and Bob)
    cout << "Shared secret key calculated by Alice (with attacker): " << secret_key_alice << endl;
    cout << "Shared secret key calculated by attacker (with Bob): " << secret_key_attacker << endl;

    return 0;
}
