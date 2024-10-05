#include<iostream>
#include<fstream>

using namespace std;

    string transposeen(string ptext,int width){

        string res = "";
        for(int i=0;i<width; i++){
            for(int row =i;row<ptext.length(); row+=width){
                res += ptext[row];
            }
        }
        return res;
    }
    
    string transposede(string encrypted,int width){

        string res = "";
        res.resize(encrypted.length());
        int idx =0;
        for(int i=0;i<width;i++){
            for(int row=i;row<encrypted.length(); row+=width){

                res[row] = encrypted[idx++];
            }
        }
        return res;
    }



int main(){

    ifstream in("3.txt");

    string ptext;
    getline(in,ptext);

    int width=5;

    string encrypted = transposeen(ptext,width);
    //encrypted = transposeen(encrypted,width);

    string decrypted = transposede(encrypted,width);

    cout <<"The Plain Text is : "<<ptext<<endl;
    cout <<"The encrpted message : "<<encrypted<<endl;
    cout <<"The decrpted message : "<<decrypted<<endl;




}