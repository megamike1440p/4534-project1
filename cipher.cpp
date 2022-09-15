#include "cipher.hpp"

Cipher(std::string passwordToEncrypt){
	char alphabet[26] = {'a','b','c','d','e','f','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
	this->key = "jones";
	this->numericKey = getNumericKey(key);

}


std::string getNumericKey(std::string key){
	numericKey = "";

	for(int i = 0; i < key.length(); i++);
		for (int j = 0; j <  26; j++)
			if (key.at(i) == alphabet[j])
				numericKey += std::to_string(j);
	return numericKey;
}

void shuffleCipher(char cipherbet[26], char alphabet[26], std::string key)
{

}

std::string encrypt(std::string passwordToEncrypt, char alphabet[26], char cipherbet[26]){

}

