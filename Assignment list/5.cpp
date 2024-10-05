#include<iostream>
#include<fstream>

using namespace std;

string onetimepaden(string ptext, string key){
    string res ="";

    for(int i=0;i<ptext.length(); i++){

        if(isupper(ptext[i])){

            res += char(((ptext[i] - 'A') + (key[i] - 'a') + 26 ) %26 + 'A');
        }
        else if (islower(ptext[i])){

            res += char(((ptext[i] - 'a') + (key[i] - 'a') + 26 ) %26 + 'a');
        }else
            res += ptext[i];
    }
    return res;

}
string onetimepaddec(string ptext, string key){
    string res ="";

    for(int i=0;i<ptext.length(); i++){

        if(isupper(ptext[i])){

            res += char(((ptext[i] - 'A') - (key[i] - 'a') + 26 ) %26 + 'A');
        }
        else if (islower(ptext[i])){

            res += char(((ptext[i] - 'a') - (key[i] - 'a') + 26 ) %26 + 'a');
        }else
            res += ptext[i];
    }
    return res;
}

int main(){

    ifstream in("5.txt");
    string ptext;
    getline(in,ptext);
    string key ="abcdefghijklmnopqrstuvwxyz";

    string encrypted = onetimepaden(ptext,key);
    string decrypted = onetimepaddec(encrypted,key);

    cout <<"The Plain Text is : "<<ptext<<endl;
    cout <<"The encrpted message : "<<encrypted<<endl;
    cout <<"The decrpted message : "<<decrypted<<endl;


}