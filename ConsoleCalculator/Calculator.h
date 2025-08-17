#pragma once
#include <vector>
#include "Token.h"
class Calculator {
private:
	std::vector<Token> tokens;
public:

	std::string evaluate(std::vector<Token> inputVector);
	std::string format(std::string input);
	std::string calculate(std::string input);

};