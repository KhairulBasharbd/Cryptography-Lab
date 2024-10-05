#include<iostream>
#include<fstream>

using namespace std;
string caesaren(string ptext,int  shift){

    string res ="";
    for(int i=0;i<ptext.length(); i++){

        if(isupper(ptext[i])){
            res += char(int(ptext[i] - 'A' + shift +26) % 26 + 'A');

        }
        else if(islower(ptext[i])){
            res += char(int(ptext[i] - 'a' + shift +26) % 26 +'a');
        }
        else
            res += ptext[i];
    }

    return res;
}

string caesarde(string encrypted, int shift){

    shift = -shift;
    return caesaren(encrypted,shift);
}

int main(){

    ifstream infile("1.txt");
    string ptext;
    getline(infile,ptext);
    infile.close();

    cout <<"The Plain Text is : "<<ptext<<endl;
    int shift = 3;
    string encrypted = caesaren(ptext, shift);
    string decrypted = caesarde(encrypted, shift);
    cout <<"Encrypted Message Is : "<<encrypted<<endl;
    cout <<"Decrypted Message Is : "<<decrypted<<endl;
}