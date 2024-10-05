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
    int numRows = (text.length() + width - 1) / width;
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
    ifstream inputFile("doubletranspocipher.txt");
    string plaintext;
    getline(inputFile, plaintext);
    inputFile.close();

    int width1, width2;
    cout << "Enter first width for Double Transposition Cipher: ";
    cin >> width1;
    cout << "Enter second width for Double Transposition Cipher: ";
    cin >> width2;

    string encryptedOnce = transpositionEncrypt(plaintext, width1);
    string encryptedTwice = transpositionEncrypt(encryptedOnce, width2);
    
    string decryptedOnce = transpositionDecrypt(encryptedTwice, width2);
    string decryptedTwice = transpositionDecrypt(decryptedOnce, width1);

    cout << "Encrypted Double Transposition Cipher: " << encryptedTwice << endl;
    cout << "Decrypted Double Transposition Cipher: " << decryptedTwice << endl;

    return 0;
}
