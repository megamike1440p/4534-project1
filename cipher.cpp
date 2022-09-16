#include "cipher.hpp"

Cipher::Cipher(std::string passwordToEncrypt){
	char alphabet[26] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
	int numericKey[5] = {};
	numericKeyPtr = numericKey;
	alphabetPtr = alphabet;
	this->key = "jones";
	getNumericKey(key);
	std::cout << "constructor complete, beginning encryption of chosen password: " << passwordToEncrypt << std::endl;
	encrypt(passwordToEncrypt);
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

void Cipher::encrypt(std::string passwordToEncrypt){

	passwordEncrypted = "";
	char letterToSwap;
	for (int i = 0; i < 9; i++){
		for (int j = 0; j < 26; j++){
			if (passwordToEncrypt.at(i) == alphabetPtr[j]){
				letterToSwap = alphabetPtr[j];
				std::cout << "current letter to swap: " << letterToSwap << std::endl;
				passwordEncrypted += swapLetter(letterToSwap, i, j);
			}
		}
	}
	std::cout << passwordEncrypted << std::endl;
}

char Cipher::swapLetter(char letterToSwap, int passwordIndex, int alphabetIndex){
	std::cout << "begin swapLetter function" << std::endl;
	int cipherIndex;

	if (passwordIndex > 4)
	{
		passwordIndex = passwordIndex % 5;
	}

	//std::cout << "passwordIndex = " << passwordIndex << std::endl;

	for (int i = 0; i < 26; i++){
		//std::cout << "numericKeyPtr[passwordIndex] :" << numericKeyPtr[passwordIndex] << " alphabetPtr[i] : " << alphabetPtr[i] << std::endl;
		if(key.at(passwordIndex) == alphabetPtr[i])
		{
			cipherIndex = i;
			if(cipherIndex + alphabetIndex > 25)
			{
				//std::cout << "cipher index = " << cipherIndex << " alphabet index = " << alphabetIndex << std::endl;
				letterToSwap = alphabetPtr[(cipherIndex+alphabetIndex)-26];
				std::cout << "letter swapped with: " << letterToSwap << std::endl;
				return letterToSwap;
			}
			
			else
			{
				letterToSwap = alphabetPtr[cipherIndex+alphabetIndex];
				std::cout << "letter swapped with: " << letterToSwap << std::endl;
				return letterToSwap;
			}
		}
	}
	return letterToSwap;
}

std::string Cipher::getEncryptedPassword(){
    return passwordEncrypted;
}
