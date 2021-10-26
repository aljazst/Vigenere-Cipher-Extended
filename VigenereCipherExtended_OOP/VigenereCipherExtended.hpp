#ifndef VIGENERECIPHEREXTENDED_H_
#define VIGENERECIPHEREXTENDED_H_
#include <string>

class VigenereCipherExtended {

    //member variable (c for cipher)
    std::string c_message;
    std::string c_key;

public:
    // Constructor
    VigenereCipherExtended(std::string message, std::string key);

    // Destructor
    ~VigenereCipherExtended();

    // Getters
	std::string getMessage();
	std::string getKey();

	// Setters
	void setMessage(std::string message);
	void setKey(std::string key);

    std::string generateKey();
    std::string encodeText();
    
    std::string decodeText(std::string encodedMessage, std::string key);

    int findTheSingleDigit(int n); 


};

#endif // VIGENERECIPHEREXTENDED_H_