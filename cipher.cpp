#include "cipher.hpp"

Cipher::Cipher(std::char passwordToEncrypt){
	std::cout<<"default constructor called [cipher]" << std::endl;
	char alphabet[26] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
	int numericKey[5] = {};
	numericKeyPtr = numericKey;
	alphabetPtr = alphabet;
	this->key = "jones";
	getNumericKey(key);
	encrypt(passwordToEncrypt);
}

void Cipher::getNumericKey(std::string key){
	for(int i = 0; i < 5; i++)
	{
		for (int j = 0; j <  26; j++)
		{
			if (key.at(i) == alphabetPtr[j])
			{
				numericKeyPtr[i] = j;
				std::cout << numericKeyPtr[i] << std::endl;
			}
		}
	}
}

void Cipher::shuffleCipher(char cipherbet[26], char alphabet[26], std::string key)
{
}

std::string Cipher::encrypt(std::string passwordToEncrypt){
	std::cout << "encrypt called" << std::endl << ", password to encrypt: " << passwordToEncrypt << std::endl;

	std::string encryptedPassword = "";
	char letterToSwap;
	for (int i = 0; i < 9; i++){
		for (int j = 0; j < 26; j++){
			if (passwordToEncrypt.at(i) == alphabetPtr[j]){
				letterToSwap = alphabetPtr[j];
				encryptedPassword += swapLetter(letterToSwap, i, j);

				std::cout << encryptedPassword << std::endl;
			}
		}
	}
	std::cout << "encrypted password = " << encryptedPassword;
	return encryptedPassword;
}

char Cipher::swapLetter(char letterToSwap, int passwordIndex, int alphabetIndex){
	int cipherIndex;

	if (passwordIndex > 4)
	{
		passwordIndex = passwordIndex % 5;
	}

	for (int i = 0; i < 26; i++){
		if(key.at(passwordIndex) == alphabetPtr[i])
		{
			cipherIndex = i;
			if(cipherIndex + alphabetIndex > 25)
			{
				letterToSwap = alphabetPtr[(cipherIndex+alphabetIndex)-26];
				return letterToSwap;
			}
			
			else
			{
				letterToSwap = alphabetPtr[cipherIndex+alphabetIndex];
				return letterToSwap;
			}
		}
	}
	return letterToSwap;
}
