/***************************************************************
  Student Name: Michael Whitten
  File Name: Cipher.cpp
  Assignment number: Project #1

  This class contains the methods the encrypt a password using the vinegere cipher. Unfortunantly, when reading from a file, the key index is offset by one,
  meaning that, when reading from a file, the key is effectively "onesj". This problem does not occur when encrypting a password directly. I believe I am reading in
  a leading whitespace or something like that.
***************************************************************/
#include "cipher.hpp"

Cipher::Cipher(std::string passwordToEncrypt){
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
			}
		}
	}
}

void Cipher::encrypt(std::string passwordToEncrypt){

	passwordEncrypted = "";
	char letterToSwap;
	for (int i = 0; i < 9; i++){
		for (int j = 0; j < 26; j++){
			if (passwordToEncrypt.at(i) == alphabetPtr[j]){
				letterToSwap = alphabetPtr[j];
				passwordEncrypted += swapLetter(letterToSwap, i, j);
			}
		}
	}
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
				letterToSwap = alphabetPtr[(cipherIndex+alphabetIndex)-25];
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

std::string Cipher::getEncryptedPassword(){
    return passwordEncrypted;
}
