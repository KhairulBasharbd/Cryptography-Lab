// #include<bits/stdc++.h>

#include<iostream>
#include<fstream>
#include<map>
using namespace std;

string polygramen(string ptext){
    map<string,string>dict = {{"abc","xyz"},{"ABC","XYZ"},{"def","uvw"},{"DEF","UVW"}};
    string res="";

    for(int i=0; i<ptext.length(); i+=3){
        string bk =ptext.substr(i,3);

        if(dict.count(bk)){

            res += dict[bk];
        }
        else 
            res += bk;
    }
    return res;

}

string polygramde(string etext){
    map<string,string>rev = {{"xyz", "abc"},{"XYZ","ABC"},{"uvw","def"},{"UVW","DEF"}};
    string res = "";
    for(int i=0; i<etext.length(); i+=3){
        string bk = etext.substr(i,3);

        if(rev.count(bk)){
            res += rev[bk];
        }else
            res += bk;
    }

    return res;
}

 int main(){

    ifstream in("2.txt");

    string ptext;
    getline(in,ptext);

    string encrypted = polygramen(ptext);
    string decrypted = polygramde(encrypted);


    cout <<"The Plaintext is : "<<ptext<<endl;
    cout <<"The Encrypted message is : "<<encrypted<<endl;
    cout <<"The decrypted message is : "<<decrypted<<endl;


    return 0;
 }
