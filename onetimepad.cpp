#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
using namespace std;

// Function to generate a random key of the same length as the plaintext
string generateRandomKey(int length) {
    string key = "";
    srand(time(0)); // Seed the random number generator
    for (int i = 0; i < length; i++) {
        key += char(rand() % 127); // Generate random ASCII character
    }
    return key;
}

string oneTimePadEncrypt(string text, string key) {
    string result = "";
    for (int i = 0; i < text.length(); i++) {
        result += char(text[i] ^ key[i]);
    }
    return result;
}

string oneTimePadDecrypt(string text, string key) {
    return oneTimePadEncrypt(text, key); // XOR operation is symmetric
}

int main() {
    ifstream inputFile("onetimepad.txt");
    string plaintext;
    getline(inputFile, plaintext);
    inputFile.close();

    // Generate random key
    string key = generateRandomKey(plaintext.length());

    // cout << "Enter the key for One-Time Pad (same length as plaintext): ";
    // getline(cin, key);

    string encrypted = oneTimePadEncrypt(plaintext, key);
    string decrypted = oneTimePadDecrypt(encrypted, key);


    cout << "Generated Key: " << key << endl;
    cout << "Encrypted One-Time Pad Cipher: " << encrypted << endl;
    cout << "Decrypted One-Time Pad Cipher: " << decrypted << endl;

    return 0;
}
