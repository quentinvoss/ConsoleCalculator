#pragma once
#include <vector>
#include "Token.h"
#include "Converter.h"

const std::string OPERATORS = "+-*/()^";

class Calculator {
private:
	std::vector<Token> tokens;
	Converter converter = Converter();
	void tokenise(std::string input);
	double calculate(std::string number1, std::string number2, std::string op /*operator*/);
	Token evaluate(std::vector<Token> inputVector);
	std::string format(std::string input);
public:
	std::string simplify(std::string input);
};