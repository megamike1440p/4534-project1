#include "password-generator.hpp"

PasswordGenerator::PasswordGenerator(){
	inFile.open("lastNames.txt");
	outFile.open("raw.txt");
	if(inFile.is_open() && outFile.is_open()){
		std::cout << "files opened successfully" << std::endl;
	}
	writeToRaw();
}

void PasswordGenerator::writeToRaw(){
	while(getline(inFile, currentUser, '\t')){
		outFile << currentUser << '\n';
	}
}
