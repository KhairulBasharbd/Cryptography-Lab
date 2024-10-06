#include<iostream>
#include<cmath>
#include<string>
#include<vector>
using namespace std;
    vector<long long> splitmes(string mess,int size){  

        vector<long long> chunks;
        for(size_t i=0; i<mess.length();i+=size){
            string chunk = mess.substr(i,size);
            chunks.push_back(stoll(chunk));
        }
        return chunks;
    }
    long long powermod(long long base, long long e, long long mod){
        long long res =1;
        while(e>0){
            if( e % 2 == 1){
                res = (res * base ) % mod;
            }
            base = (base * base ) % mod;
            e /= 2;
        }
        return res;
    }



int main(){
    long long e =79;
    long long d = 1019;
    long long n = 3337;
    string message = "6882326879666683";

    vector<long long> chunks ;
    chunks = splitmes(message,3);

    vector<long long> encryptedChunks;

    for(long long chunk : chunks){
        long long encrypted = powermod(chunk,e,n);
        encryptedChunks.push_back(encrypted);

    }

    vector<long long> decryptedChunks;
    for(long long chunk : encryptedChunks){
        long long decrypted = powermod(chunk,e,n);
        decryptedChunks.push_back(decrypted);

    }










    cout << "Encrypted Chunks: ";
    for (long long encrypted : encryptedChunks) {
        cout << encrypted << " ";
    }
    cout << endl;


    cout << "Decrypted Chunks: ";
    for (long long decrypted : decryptedChunks) {
        cout << decrypted << " ";
    }
    cout << endl;






}