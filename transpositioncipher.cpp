#include <iostream>
#include <fstream>
using namespace std;

string transpositionEncrypt(string text, int width) {
    string result = "";
    for (int i = 0; i < width; i++) {
        for (int j = i; j < text.length(); j += width) {
            result += text[j];
        }
    }
    return result;
}

string transpositionDecrypt(string text, int width) {
   // int numRows = (text.length() + width - 1) / width;
    string result(text.length(), ' ');
    int idx = 0;
    
    for (int i = 0; i < width; i++) {
        for (int j = i; j < text.length(); j += width) {
            result[j] = text[idx++];
        }
    }
    return result;
}

int main() {
    ifstream inputFile("transpositioncipher.txt");
    string plaintext;
    getline(inputFile, plaintext);
    inputFile.close();

    int width;
    cout << "Enter width for Transposition Cipher: ";
    cin >> width;

    string encrypted = transpositionEncrypt(plaintext, width);
    string decrypted = transpositionDecrypt(encrypted, width);

    cout << "Encrypted Transposition Cipher: " << encrypted << endl;
    cout << "Decrypted Transposition Cipher: " << decrypted << endl;

    return 0;
}
