// C++ code for RSA encryption and decryption (key generation included)
#include <iostream>
#include <cmath>
using namespace std;

long long gcd(long long a, long long b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

long long modInverse(long long e, long long phi) {
    long long t = 0, newT = 1;
    long long r = phi, newR = e;
    while (newR != 0) {
        long long q = r / newR;
        t = t - q * newT;
        r = r - q * newR;
        swap(t, newT);
        swap(r, newR);
    }
    if (r > 1) return -1;
    if (t < 0) t = t + phi;
    return t;
}

long long powerMod(long long base, long long exp, long long mod) {
    long long result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) result = (result * base) % mod;
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}

int main() {
    long long p = 61, q = 53; // Two large prime numbers
    long long n = p * q;
    long long phi = (p - 1) * (q - 1);

    long long e = 17; // Public key exponent
    while (gcd(e, phi) != 1) e++;

    long long d = modInverse(e, phi); // Private key

    string plaintext;
    cout << "Enter plaintext: ";
    cin >> plaintext;

    long long encrypted = powerMod(plaintext[0], e, n); // Encrypt first char
    long long decrypted = powerMod(encrypted, d, n); // Decrypt

    cout << "Encrypted RSA: " << encrypted << endl;
    cout << "Decrypted RSA: " << char(decrypted) << endl;

    return 0;
}
