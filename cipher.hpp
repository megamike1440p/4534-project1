#ifndef CIPHER_HPP
#define CIPHER_HPP
#include <iostream>

class Cipher
	{
		private:
			char *alphabetPtr;
			//char *cipherbetPtr;
			std::string passwordToEncrypt;
			std::string passwordEncrypted;
			std::string key;
			int* numericKeyPtr;

		public:

			Cipher(std::string passwordToEncrypt);
			//~Cipher();
			std::string getEncryptedPassword();
			void getNumericKey(std::string key);
			void shuffleCipher(char cipherbet[26], char alphabet[26], std::string key);
			void encrypt(std::string passwordToEncrypt);
			char swapLetter(char letterToSwap, int passwordIndex, int alphabetIndex);
	};

#endif
