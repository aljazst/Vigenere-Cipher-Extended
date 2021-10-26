#include "VigenereCipherExtended.hpp"
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

VigenereCipherExtended::VigenereCipherExtended(string message, string key): c_message(message), c_key(key) {}

VigenereCipherExtended::~VigenereCipherExtended() {}

string VigenereCipherExtended::getKey() {
    return c_key;
}
string VigenereCipherExtended::getMessage() {
    return c_message;
}

void VigenereCipherExtended::setKey(string key) {
    c_key = key;
}

void VigenereCipherExtended::setMessage(string message) {
    c_message = message;
}

string VigenereCipherExtended::generateKey() {
    int messageSize = c_message.size();

    if(c_key.size() <= messageSize){
	for (int i = 0; i< messageSize; i++)
	{
		if (c_key.size() == c_message.size())
			break;
		c_key.push_back(c_key[i]);
	}}
    else {
        c_key = c_key.substr(0,messageSize);
        cerr<< "\nYour key has been altered to the same lenght as the message.\n"<<endl;
    }
	return c_key;

}

string VigenereCipherExtended::encodeText() {
    vector<int> cipher_message_ASCII;
    int SUM;
    

	for (int i = 0; i < c_message.size(); i++){
       unsigned char intersection_text = c_message[i] - 33 + c_key[i];

        if(intersection_text > 126){
            intersection_text  = intersection_text - 94;
        }

        cipher_message_ASCII.push_back(intersection_text);
	}

 
    int MIN = *min_element(cipher_message_ASCII.begin(), cipher_message_ASCII.end());

    if( MIN > 9 ){
      
      SUM = findTheSingleDigit(MIN);

    }

    std::rotate(cipher_message_ASCII.begin(), cipher_message_ASCII.begin() + SUM, cipher_message_ASCII.end());

    string out_cipher_text(cipher_message_ASCII.begin(), cipher_message_ASCII.end());

	return out_cipher_text;
}

string VigenereCipherExtended::decodeText(string encodedMessage, string key) {
    vector<int> encodedASCII;
    int shift_value;
    string output_text;

	for (int i = 0 ; i < encodedMessage.size(); i++){
		int x = encodedMessage[i] ;
		encodedASCII.push_back(x);
	}
    int min = *min_element(encodedASCII.begin(), encodedASCII.end());
    

    shift_value = findTheSingleDigit(min);

    rotate(encodedASCII.rbegin() ,encodedASCII.rbegin()+ shift_value, encodedASCII.rend());



    for (int i = 0 ; i < encodedMessage.size(); i++){

       int intersection_text = encodedASCII[i] + 33 - key[i];

        if( intersection_text <= 33){
            intersection_text  = intersection_text + 94;
        }
        if(intersection_text >= 126){
            intersection_text  = intersection_text - 94;
        }
        output_text.push_back(intersection_text);
	}


	return output_text;
}
//We need to add the digits of the lowest ASCII number recursively to get the shift value. an eazy way would be n%9. But I think this recursion thing is kinda ok.
int VigenereCipherExtended::findTheSingleDigit(int n) {
   int sum = 0;
   while(n > 0 || sum > 9) {
      if(n == 0) {
         n = sum;
         sum = 0;
      }
      sum += n % 10;
      n /= 10;
   }
   return sum;
}
