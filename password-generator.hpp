#ifndef PASSWORD_GENERATOR
#define PASSWORD_GENERATOR
#include <iostream>
#include <fstream>
#include "cipher.hpp"
class PasswordGenerator
	{
		private:
			char* alphabetPtr;
			std::ifstream inFile;
			std::ofstream outFile;
			std::string currentUser;
			std::string currentPassword;
			std::string encryptedPassword;

		public:
			PasswordGenerator();
			std::string generatePassword();
			void read();
			void writeToRaw();
			void writeToEncrypted();
	};

#endif
