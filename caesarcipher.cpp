#include <iostream>
#include <fstream>
using namespace std;

string caesarEncrypt(string text, int shift) {
    string result = "";
    for (int i = 0; i < text.length(); i++) {
        if (isupper(text[i]))
            result += char(int(text[i] + shift - 65) % 26 + 65);
        else if (islower(text[i]))
            result += char(int(text[i] + shift - 97) % 26 + 97);
        else
            result += text[i]; // Non-alphabet characters remain the same
    }
    return result;
}

string caesarDecrypt(string text, int shift) {
    return caesarEncrypt(text, 26 - shift); // Reverse is shifting by 26 - shift
}

int main() {
    ifstream inputFile("caesar.txt");
    string plaintext;
    getline(inputFile, plaintext);
    inputFile.close();

    int shift = 3; // Caesar cipher shift
    string encrypted = caesarEncrypt(plaintext, shift);
    string decrypted = caesarDecrypt(encrypted, shift);

    cout << "Encrypted Caesar Cipher: " << encrypted << endl;
    cout << "Decrypted Caesar Cipher: " << decrypted << endl;

    return 0;
}
