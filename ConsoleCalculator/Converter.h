#pragma once
#include "Token.h"
#include <stdexcept>
class Converter {
public:

	Token toToken(std::string input) {
		if (input.empty()) {
			throw std::invalid_argument("Syntax Error");
		}
		std::string ops = "+-*/()^";
		if (input.length() == 1 && ops.find(input) != std::string::npos) {
			return Token(TokenType::OPERATOR, input);
		}
		else {
			std::string allowedChars = "1234567890.";
			for (int i = 0; i < input.length(); i++) {
				if (!(allowedChars.find(input[i] != std::string::npos)) && !('-' == input[i] && input.length() == 1)) {
					throw std::invalid_argument("Syntax Error");
				}
			}
			return Token(TokenType::NUMBER, input);
		}
	}

	double toNum(std::string input) {
		bool dotSeen = 0;
		for (int i = 0; i < input.length(); i++) {
			if (input[i] == '.') {
				if (dotSeen) {
					throw std::invalid_argument("Syntax Error");
				}
				else {
					dotSeen = 1;
				}
			}
		}
		if (dotSeen && input.length() == 1) {
			throw std::invalid_argument("Lone decimal point");
		}
		if (dotSeen) {
			return std::stod(input);
		}
		else {
			return std::stoi(input);
		}
	}

};