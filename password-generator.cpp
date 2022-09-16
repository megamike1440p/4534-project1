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
	writeToEncrypted();
}

void PasswordGenerator::writeToRaw(){
	while(getline(inFile, currentUser)){
		std::string trimmedUser = currentUser.substr(0, currentUser.find(" ", 0));
		outFile << trimmedUser << ' ' << generatePassword() << "\n";
	}
	inFile.close();
	outFile.close();
}

void PasswordGenerator::writeToEncrypted(){
	currentPassword = "";
	int spacePlace;
//	Cipher cipher;
	inFile.open("raw.txt");
	outFile.open("encrypted.txt");

	if(inFile.is_open() && outFile.is_open()){
		std::cout << "files opened successfully (2)" << std::endl;
	}

	while(getline(inFile, currentPassword)){
	
		std::string trimmedUserName = currentPassword.substr(0, currentUser.find(" ", 0));		
		std::string trimmedPassword = currentPassword.substr(currentPassword.find(" ", 0));
		Cipher cipher(trimmedPassword);1
		outFile << trimmedUserName << " " << trimmedPassworid << std::endl;
		

	}
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
