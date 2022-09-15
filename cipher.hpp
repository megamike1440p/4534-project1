#ifndef CIPHER_HPP
#define CIPHER_HPP
#include <iostream>

class Cipher
	{
		private:
			char alphabet[26];
			char cipherbet[26];
			char *cipherbetPtr;
			char *alphabetPtr;
			std::string passwordToEncrypt;
			std::string passwordEncrypted;
			std::string key;
			int numericKey;
		
		public:
			Cipher(std::string passwordToEncrypt);
			int getNumericKey(std::string key);
			void shuffleCipher(char cipherbet[26], char alphabet[26], std::string key);
			std::string encrypt(std::string passwordToEncrypt, char alphabet[26], char cipherbet[26]);
	};

#endif
