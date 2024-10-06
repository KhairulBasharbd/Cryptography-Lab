#include <iostream>
#include <cmath>
#include <string>
#include <vector>
using namespace std;

// // Function to calculate GCD
// long long gcd(long long a, long long b) {
//     if (b == 0) return a;
//     return gcd(b, a % b);
// }
// // We don't need this function, because It used during the key generation phase to calculate the private key 
// // d as the modular inverse of the public key exponent e modulo 𝜙(𝑛).
// // Function to calculate modular inverse
// long long modInverse(long long e, long long phi) {
//     long long t = 0, newT = 1;
//     long long r = phi, newR = e;
//     while (newR != 0) {
//         long long q = r / newR;
//         t = t - q * newT;
//         r = r - q * newR;
//         swap(t, newT);
//         swap(r, newR);
//     }
//     if (r > 1) return -1; // e is not invertible
//     if (t < 0) t = t + phi; // Ensure t is positive
//     return t;
// }

// Function for modular exponentiation
long long powerMod(long long base, long long exp, long long mod) {
    long long result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}

// Function to split the message into chunks
vector<long long> splitMessage(string message, int chunkSize) {
    vector<long long> chunks;
    for (size_t i = 0; i < message.length(); i += chunkSize) {
        string chunk = message.substr(i, chunkSize);
        chunks.push_back(stoll(chunk)); // Convert string chunk to long long
    }
    return chunks;
}

int main() {
    long long e = 79; // Public key exponent
    long long d = 1019; // Private key
    long long n = 3337; // Modulus

    string message = "6882326879666683"; // Message to encrypt

    // Split the message into chunks of size 3
    vector<long long> chunks = splitMessage(message, 3);
    //-------------------------------------------
    vector<long long> encryptedChunks; // Vector to hold encrypted chunks
    for (long long chunk : chunks) {
        long long encrypted = powerMod(chunk, e, n);
        encryptedChunks.push_back(encrypted); // Store encrypted chunk in vector
    }

    // Output the encrypted chunks
    cout << "Encrypted Chunks: ";
    for (long long encrypted : encryptedChunks) {
        cout << encrypted << " ";
    }
    cout << endl;

    // Decryption
    string decryptedString;
    for (long long encryptedChunk : encryptedChunks) {
        long long decrypted = powerMod(encryptedChunk, d, n);
        decryptedString += to_string(decrypted); // Append decrypted chunk to string
    }

    //-------------------------------------------

    cout << "Concatenated Decrypted String: " << decryptedString << endl;

    return 0;
}
