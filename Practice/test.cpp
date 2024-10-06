#include<iostream>
#include<fstream>
#include<map>
#include<vector>
#include<string>



using namespace std;

string caesarenc(string ptext, int sh){
    string res ="";
    for(int i=0; i<ptext.length();i++){
        if(isupper(ptext[i])){
            res += char( (ptext[i] - 'A' + sh + 26 ) %26 + 'A');
        }
        else if(islower(ptext[i])){
            res += char( (ptext[i] - 'a' + sh + 26) % 26 + 'a');

        }
        else
            res += ptext[i];
    }
    return res;
}

string caesardec(string enc,int sh){
    sh = -sh;
    return caesarenc(enc, sh); 
}

string polyenc(string ptext){
    map<string,string> dict={{"abc","xyz"},{"ABC","XYZ"},{"def","uvw"},{"DEF","UVW"}};

    string res ="";
    for(int i=0; i<ptext.length(); i+=3){

        string block = ptext.substr(i,3);

        if(dict.count(block)){
            res += dict[block];

        }
        else 
            res += ptext;
    }
    return res;
}
string polydec(string enc){
    map<string,string>rev = {{"xyz", "abc"},{"XYZ","ABC"},{"uvw","def"},{"UVW","DEF"}};
    string res ="";
    for(int i=0; i<enc.length(); i+=3){

        string block = enc.substr(i,3);

        if(rev.count(block)){
            res += rev[block];

        }
        else 
            res += enc[i];
    }
    return res;


}

string transenc(string ptext, int width){

    string res ="";

    for(int i=0;i<width; i++) {
        for(int j=i; j<ptext.length(); j+= width){

            res += ptext[j];
        }
    }
    return res;
}

string transdec(string enc, int width){
    string res;
    res.resize(enc.length());
    int idx =0;
    for(int i=0;i<width; i++) {
        for(int j=i; j<enc.length(); j += width){
            res[j] =enc[idx++];
        }
    }
    return res;
}

string otpenc(string ptext, string key){
    string res="";

    for(int i=0;i<ptext.length();i++){
        if(isupper(ptext[i])){
            res += char((ptext[i] - 'A' + key[i] - 'a') %26 + 'A');
        }
        else if(islower(ptext[i])){
            res += char((ptext[i] - 'a' + key[i] - 'a') %26 + 'a');

        }
        else{
            res += ptext[i];
        }
    }
    return res;
}

string otpdec(string enc,string key){
    string res ="";
    for(int i=0;i<enc.length();i++){
        if(isupper(enc[i])){
            res += char((enc[i] - 'A' -( key[i] - 'a') +26) %26 + 'A');
        }
        else if(islower(enc[i])){
            res += char((enc[i] - 'a' - (key[i] - 'a')+ 26) %26 + 'a');

        }
        else{
            res += enc[i];
        }
    }
    return res;



}
//----------------------------RSA---------------------------------------------------------
//----------------------------RSA---------------------------------------------------------

vector<long long> messplit(string message,int bk){
    vector<long long> chunks;
    for(int i=0;i<message.length(); i+= bk){
        string chunk = message.substr(i,bk);
        chunks.push_back(stoll(chunk));

    }
    return chunks;
}

long long powermod(long long b, long long e, long long m){
    long long res = 1;
    while(e>0){
        if(e % 2 == 1){
            res = (res * b) % m;
        }
        b = ( b*b )% m;
        e /= 2;
    }
    return res;


}

//----------------------------RSA---------------------------------------------------------
//----------------------------RSA---------------------------------------------------------


int main(){
    //----------------------------RSA---------------------------------------------------------
    // 79
    // 1019
    // 3337
    // 6882326879666683
    long long e =79;
    long long d=1019;
    long long n=3337;
    string message = "6882326879666683";
    int block =3;

    vector<long long> chunks = messplit(message,block);

    vector<long long> enc;
    for(long long chunk: chunks){
        enc.push_back(powermod(chunk,e,n));
    }



    cout <<"Original Message : "<<message<<endl;
    vector<long long> dec;
    for(long long chunk: enc){
        dec.push_back(powermod(chunk,d,n));
    }
    cout<<"The encrypted RSA : ";
    for(long long en:enc){
        cout<<en<<" ";
    }
    cout<<endl;

    cout<<"The decrypted RSA : ";
    for(long long de:dec){
        cout<<de<<" ";
    }
    cout<<endl;


//----------------------------RSA---------------------------------------------------------

    // ifstream in("test.txt");
    // string ptext;
    // getline(in,ptext);

    // int shift =3,width = 5;

    // string key ="abcdefghijklmnopqrstuvwxyz";

    // string caesaren = caesarenc(ptext,shift);
    // string caesarde = caesardec(caesaren,shift);
    // string polyen = polyenc(ptext);
    // string polyde = polydec(polyen);
    // string transen = transenc(ptext, width);
    // string transde = transdec(transen, width);
    // string otpen = otpenc(ptext, key);
    // string otpde = otpdec(otpen, key);

    // cout<<"The message : "<<ptext<<endl;
    // cout<<"The caesar cipher : "<<caesaren<<endl;
    // cout<<"The original caesar : "<<caesarde<<endl;
    // cout<<"The Plogram Cipher : "<<polyen<<endl;
    // cout<<"The original Polygram : "<<polyde<<endl;
    // cout<<"The Transposition cipher : "<<transen<<endl;
    //cout<<"The original Transposition : "<<transde<<endl;
    // cout<<"The OTP cipher : "<<otpen<<endl;
    // cout<<"The original OTP : "<<otpde<<endl;







    return 0;
}

