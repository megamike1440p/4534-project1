#ifndef PASSWORD_GENERATOR
#define PASSWORD_GENERATOR
#include <iostream>
#include <fstream>
#include "cipher.hpp"


class PasswordGenerator
	{
		private:
			fstream inFile;
			fstream outFile;
			std::string currentUser;
			std::string currentPassword;
			std::string encryptedPassword;

		public:
			std::string generatePassword();
			void read();
			void writeToRaw();
			void writeToEncrypted();
	};

#endif
