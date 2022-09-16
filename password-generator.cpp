#include "password-generator.hpp"
#include "cipher.hpp"
#include <cstdlib>

PasswordGenerator::PasswordGenerator(){
	char alphabet[26] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
	alphabetPtr = alphabet;
	inFile.open("lastNames.txt");
	outFile.open("raw.txt");
	if(inFile.is_open() && outFile.is_open()){
		std::cout << "files opened successfully" << std::endl;
	}
	writeToRaw();
}

void PasswordGenerator::writeToRaw(){
	std::cout << "reading from lastName.txt and writing to raw.txt...";
	while(getline(inFile, currentUser)){
		std::string trimmedUser = currentUser.substr(0, currentUser.find(" ", 0));
		outFile << trimmedUser << ' ' << generatePassword() << "\n";
	}
	inFile.close();
	inFile.clear();
	outFile.close();
	outFile.flush();
	outFile.clear();
	std::cout << " done." << std::endl;
	writeToEncrypted();

}

void PasswordGenerator::writeToEncrypted(){
	currentPassword = "";
	std::string trimmedUserName = "";
	std::ifstream inFile2;
	std::ofstream outFile2;
	inFile2.open("raw.txt");
	outFile2.open("encrypted.txt");

	if(inFile2.is_open() && outFile2.is_open()){
		std::cout << "files opened successfully (2)" << std::endl;
	}

	std::cout << "reading from raw.txt and writing to encrypted.txt...";

	while(getline(inFile2, currentPassword)){
	
		trimmedUserName = currentPassword.substr(0, currentPassword.find(' '));		
		std::string trimmedPassword = currentPassword.substr(currentPassword.find(" ", 0));
		Cipher *cipher = new Cipher(trimmedPassword);
		outFile2 << trimmedUserName << " " << cipher->getEncryptedPassword() << std::endl;
		delete cipher;
	}
	inFile2.close();
	outFile2.close();
	std::cout << " done." << std::endl;
}

std::string PasswordGenerator::generatePassword(){
	int passLength = 9;
	std::string password = "";
	for (int i = 0; i < passLength; i++)
	{
		password.append(1, alphabetPtr[rand()%26]);
	} 

	return password;
}
