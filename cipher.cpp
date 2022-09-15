#include "cipher.hpp"

Cipher::Cipher(std::string passwordToEncrypt){
	char alphabet[26] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
	int numericKey[5] = {};
	numericKeyPtr = numericKey;
	alphabetPtr = alphabet;
	this->key = "jones";
	getNumericKey(key);
	std::cout << "constructor complete" << std::endl;
}

void Cipher::getNumericKey(std::string key){
	std::cout << "numericKey = " << numericKeyPtr << std::endl;
	for(int i = 0; i < 5; i++)
	{
		for (int j = 0; j <  26; j++)
		{
			if (key.at(i) == alphabetPtr[j])
			{
				std::cout << "alphabet index 0: " << alphabetPtr[0] << " alphabet index 25: " << alphabetPtr[25];
				std::cout << "i = " << i << " j = " << j << " alphabetPtr[j] = " << alphabetPtr[j] << " key.at(i) = " << key.at(i);
				numericKeyPtr[i] = j;
				std::cout << "numericKey: " << numericKeyPtr[i] << std::endl;
			}
		}
	}
}

void Cipher::shuffleCipher(char cipherbet[26], char alphabet[26], std::string key)
{

}

std::string Cipher::encrypt(std::string passwordToEncrypt, char alphabet[26], char cipherbet[26]){
return "";


}
