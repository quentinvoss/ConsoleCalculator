#pragma once
#include <string>
#include <iostream>
class UserInterface {
public:
	void printOutcome(std::string out) {
		std::cout << "That makes: " << out << "\n\n\n";
	}

	void printQuery() {
		std::cout << "Enter the term you want simplified!\n(Type \"quit\" to quit)\nInput: ";
	}
	std::string getUserInput() {
		std::string out = "";
		std::getline(std::cin, out);
		return out;
	}
};