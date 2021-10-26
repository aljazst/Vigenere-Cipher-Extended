#include <iostream>
#include <string>
#include <vector>
#include <algorithm>


using namespace std;
 
class VigenereCipher {
    string message, key;
    public:
    string generateKey(string, string);
    string encodeText(string, string);
    string decodeText(string, string);
    int findTheSingleDigit(int);

};

string VigenereCipher::generateKey(string message, string key){
    int messageSize = message.size();

    if(key.size() <= messageSize){
	for (int i = 0; i< messageSize; i++)
	{
		if (key.size() == message.size())
			break;
		key.push_back(key[i]);
	}}
    else {
        key = key.substr(0,messageSize);
        cerr<< "\nYour key has been altered to the same lenght as the message.\n"<<endl;
    }
	return key;
}

string VigenereCipher::encodeText(string message, string key){

    vector<int> cipher_message_ASCII;
    int SUM;
    

	for (int i = 0; i < message.size(); i++){
        int intersection_text = message[i] - 33 + key[i];
        if(intersection_text > 126){
            intersection_text  = intersection_text - 94;
        }

        cipher_message_ASCII.push_back(intersection_text);
	}
 
    int MIN = *min_element(cipher_message_ASCII.begin(), cipher_message_ASCII.end());
    

    if( MIN > 9 ){
      
      SUM = findTheSingleDigit(MIN);
    }
    
    rotate(cipher_message_ASCII.begin(), cipher_message_ASCII.begin() + SUM, cipher_message_ASCII.end());
      
    string out_cipher_text(cipher_message_ASCII.begin(), cipher_message_ASCII.end());
    
	return out_cipher_text;
}

int VigenereCipher::findTheSingleDigit(int n) {
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



string VigenereCipher::decodeText(string encodedMessage, string key){

    vector<int> encodedASCII;
    int shift_value;
    string output_text;

	for (int i = 0 ; i < encodedMessage.size(); i++){
		int x = encodedMessage[i] ;
		encodedASCII.push_back(x);
	}
    int min = *min_element(encodedASCII.begin(), encodedASCII.end());
    

    shift_value = findTheSingleDigit(min);

    rotate(encodedASCII.rbegin(),encodedASCII.rbegin()+shift_value,encodedASCII.rend());



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



int main()
{
    VigenereCipher test;
    string text="tes 42#!dsAAbraka?abra";

    string generatedKey = test.generateKey(text, "samplePw123");
    cout << "Generated key: "<< generatedKey<<endl ;
    string encodedText= test.encodeText(text, generatedKey) ;
    cout << "Encrypted text: "<<encodedText<<endl ;

    string decodedtext = test.decodeText(encodedText, generatedKey);

    cout << "Original: "<<decodedtext ;
    return 0;

}