#pragma once
#include "Token.h"
#include "FunctionHandler.h"
#include <stdexcept>
class Converter {
private:
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
public:

	Token toToken(std::string input) {
		if (input.empty()) {
			throw std::invalid_argument("Syntax Error");
		}
		if (input.length() == 1 && OPERATORS.find(input) != std::string::npos) {
			return Token(TokenType::OPERATOR, input);
		}
		else {
			//Funtion check
			for (int i = 0; i < FunctionHandler::list.size(); i++) {
				if (input == FunctionHandler::list[i]->getName()) {
					return Token(TokenType::FUNCTION, input);
				}
			}
			//Number check
			std::string allowedChars = "1234567890.i";
			for (int i = 0; i < input.length(); i++) {
				if (!(allowedChars.find(input[i] != std::string::npos)) && !('-' == input[i] && input.length() == 1)) {
					throw std::invalid_argument("Syntax Error");
				}
			}
			return Token(TokenType::NUMBER, input);
		}
	}

	ComplexNumber toNumber(std::string input) {
		bool plusOrMinusSeen = 0;
		int operatorIndex = -1;
		bool iSeen = 0;
		for (int i = 0; i < input.length(); i++) {
			if (input[i] == '+' || (input[i] == '-')) {
				plusOrMinusSeen = 1;
				operatorIndex = i;
			}
			if (input[i] == 'i') {
				if(i != input.length() - 1) {
					throw std::invalid_argument("Invalid complex number format");
				}
				iSeen = 1;
			}
		}
		if(plusOrMinusSeen && input.length() == 1) {
			throw std::invalid_argument("Lone Plus or Minus");
		}
		if (plusOrMinusSeen && !iSeen) {
			if (operatorIndex == 0) {
				return ComplexNumber(toNum(input));
			}
			throw std::invalid_argument("Operation parsed as complex number");
		}
		if (iSeen && !plusOrMinusSeen) {
			input = input.substr(0, input.length() - 1);
			return ComplexNumber(0, toNum(input));
		}
		if (!iSeen && !plusOrMinusSeen) {
			return ComplexNumber(toNum(input));
		}
		std::string realPart = input.substr(0, operatorIndex-1);
		std::string imaginaryPart = input.substr(operatorIndex+2, input.length() - operatorIndex +1);
		return ComplexNumber(toNum(realPart), (input[operatorIndex] == '-' ? -1 : 1) * toNum(imaginaryPart));
	}

};