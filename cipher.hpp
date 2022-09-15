#ifndef CIPHER_HPP
#define CIPHER_HPP
#include <iostream>

class Cipher
	{
		private:
			extern char alphabet[26];
			extern char cipherbet[26];
			char *cipherbetPtr;
			char *alphabetPtr;
			std::string passwordToEncrypt;
			std::string passwordEncrypted;
			std::string key;
			std::string numericKey;
		
		public:
			Cipher(std::string passwordToEncrypt);
			std::string getNumericKey(std::string key);
			void shuffleCipher(char cipherbet[26], char alphabet[26], std::string key);
			std::string encrypt(std::string passwordToEncrypt, char alphabet[26], char cipherbet[26]);
	};

#endif
