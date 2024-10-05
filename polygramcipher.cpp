#include <iostream>
#include <fstream>
#include <map>
using namespace std;

string polygramEncrypt(string text) {
    map<string, string> substitutionMap = {{"THE", "QWE"}, {"AND", "RTY"}, {"YOU", "ASD"}}; // Add more
    string result = "";
    
    for (size_t i = 0; i < text.length(); i += 3) {
        string block = text.substr(i, 3);
        if (substitutionMap.find(block) != substitutionMap.end())
            result += substitutionMap[block];
        else
            result += block;
    }
    return result;
}

string polygramDecrypt(string text) {
    map<string, string> substitutionMap = {{"QWE", "THE"}, {"RTY", "AND"}, {"ASD", "YOU"}}; // Add reverse map
    string result = "";
    
    for (size_t i = 0; i < text.length(); i += 3) {
        string block = text.substr(i, 3);
        if (substitutionMap.find(block) != substitutionMap.end())
            result += substitutionMap[block];
        else
            result += block;
    }
    return result;
}

int main() {
    ifstream inputFile("polygramcipher.txt");
    string plaintext;
    getline(inputFile, plaintext);
    inputFile.close();

    string encrypted = polygramEncrypt(plaintext);
    string decrypted = polygramDecrypt(encrypted);

    cout << "Encrypted Polygram Cipher: " << encrypted << endl;
    cout << "Decrypted Polygram Cipher: " << decrypted << endl;

    return 0;
}
