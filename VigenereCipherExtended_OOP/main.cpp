#include <iostream>
#include "VigenereCipherExtended.hpp"

using namespace std;

int main(){

    cout<<"This is OOP version of a Vigenere Cipher extended to support ASCII values from 32 to 126"<<endl;

    VigenereCipherExtended* cipher = new VigenereCipherExtended("Email: testing@gmail.com Pw:Y0M4ma%","Y0M4ma%");


    cout<<"Key: "<< cipher->getKey()<<endl;
    string key = cipher->getKey();

    cout<<"Message: "<< cipher->getMessage()<<endl;

    cout<<"Generated key: "<< cipher->generateKey()<<endl;
    string generatedKey = cipher->generateKey();

    cout<<"Encoded message :"<< cipher->encodeText()<<endl;
    string encodedMessage = cipher->encodeText(); 
    
    cout<<"Original: "<<endl;
    cout<< cipher->decodeText(encodedMessage,generatedKey);

    delete cipher;

    return 0;
    
}