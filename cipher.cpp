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
	for (int i = 0; i < 5; i++){
	
	}

}

std::string Cipher::encrypt(std::string passwordToEncrypt, char alphabet[26], char cipherbet[26]){

	std::string encryptedPassword = "";
	char letterToSwap;
	for (int i = 0; i < 9; i++){
		for (int j = 0; j < 26; j++){
			if (passwordToEncrypt.at(i) == alphabet[j]){
				letterToSwap = alphabet[j];
				std::cout << "current letter to swap: " << letterToSwap << std::endl;
				encryptedPassword += swapLetter(letterToSwap, i, j);
			}
		}
	}
	std::cout << encryptedPassword << endl;
	return encryptedPassword;
}

char swapLetter(char letterToSwap, int passwordIndex, int alphabetIndex){
	int cipherIndex;
	if (passwordIndex > 4)
	{
		passwordIndex = passwordIndex % 5;
	}

	for (int i = 0; i < 26; i++){
		if(numericKeyPtr[passwordIndex] == alphabetPtr[i])
		{
			cipherIndex = i;
			if(i + j > 25)
			{
				letterToSwap = alphabetPtr[(i+j)-25];
			}
			else
			{
				letterToSwap = alphabetPtr[i+j];
			}
			
		}
	}
	return letterToSwap;
}
