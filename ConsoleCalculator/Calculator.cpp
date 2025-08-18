#include "Calculator.h"
#include <stdexcept>
#include <math.h>

void Calculator::tokenise(std::string input) {
	while (input.find(' ') != std::string::npos) {
		int i = 0;
		for (; i < input.length(); i++) {
			if (input[i] == ' ') {
				break;
			}
		}
		tokens.push_back(converter.toToken(input.substr(0, i)));
		input = input.substr(i + 1);
	}
}

double Calculator::calculate(std::string number1, std::string number2, std::string op /*operator*/) {
	double num1 = converter.toNum(number1);
	double num2 = converter.toNum(number2);
	double out = 0;
	if (op == "+") {
		out = num1 + num2;
	}
	else if (op == "-") {
		out = num1 - num2;
	}
	else if (op == "*") {
		out = num1 * num2;
	}
	else if (op == "/") {
		if (num2 == 0) {
			throw std::invalid_argument("Division by Zero");
		}
		out = num1 / num2;
	}
	else if (op == "^") {
		if (num1 == 0 && num2 <= 0) {
			if (num2 == 0) {
				throw std::invalid_argument("Undefined Behaviour");
			}
			else {
				throw std::invalid_argument("Division by Zero");
			}
		}
		if (num1 < 0 && num2 != int(num2)) {
			throw std::invalid_argument("Non real outcome");
		}
		out = pow(num1, num2);
	}
	else {
		throw std::invalid_argument("Unknown operator" + op);
	}
}

std::vector<Token> Calculator::prioritiseOperators(std::vector<Token> inputVector, std::string operators) {
	if (inputVector.size() == 1) {
		return inputVector;
	}
	if (inputVector.size() != 3) {
		bool containsOperators;
		do {
			containsOperators = 0;
			std::vector<Token> temp;
			for (int i = 0; i < inputVector.size() - 1; i++) {
				if (inputVector[i + 1].getType() == TokenType::OPERATOR && operators.find(inputVector[i + 1].getContent()) != std::string::npos) {
					containsOperators = 1;
					std::vector<Token> toEvaluate;
					for (int j = 0; j < 3; j++) {
						toEvaluate.push_back(inputVector[i + j]);
					}
					temp.push_back(evaluate(toEvaluate));
					i += 2;
				}
				else {
					temp.push_back(inputVector[i]);
					if (i == inputVector.size() - 2) {
						temp.push_back(inputVector[i + 1]);
					}
				}
			}
			inputVector = temp;
		} while (containsOperators && inputVector.size() >= 3);
	}
	return inputVector;
}

Token Calculator::evaluate(std::vector<Token> inputVector) {

	inputVector = prioritiseOperators(inputVector, "^");
	inputVector = prioritiseOperators(inputVector, "*/");

	while (inputVector.size() > 3) {
		std::vector<Token> temp;
		std::vector<Token> toEvaluate;
		for (int i = 0; i < 3; i++) {
			toEvaluate.push_back(inputVector[i]);
		}
		temp.push_back(evaluate(toEvaluate));
		for (int i = 3; i < inputVector.size(); i++) {
			temp.push_back(inputVector[i]);
		}
		inputVector = temp;
	}
	if (inputVector.size() == 3) {
		double outcome = calculate(inputVector[0].getContent(), inputVector[2].getContent(), inputVector[1].getContent());
		std::string content = (outcome == int(outcome) ? std::to_string(int(outcome)) : std::to_string(outcome));
		return Token(TokenType::NUMBER, content);
	}
	else {
		return inputVector[0];
	}
}

std::string Calculator::format(std::string input) {
	for (int i = 0; i < input.length()-1; i++) {
		if (input[i] == ' ') {
			int j = 1;
			for (int j = 1; i + j < input.length(); j++) {
				if (input[i + j] != ' ') {
					break;
				}
			}
			input = input.substr(0,i) + input.substr(i + j);
		}
	}
	if (OPERATORS.find(input[0]) != std::string::npos && input[1] != ' ') {
		input = input.substr(0, 1) + " " + input.substr(1);
	}
	for (int i = 0; i < input.length() - 2; i++) {
		if (OPERATORS.find(input[i+1]) != std::string::npos && input[i] != ' ') {
			input = input.substr(0, i+1) + " " + input.substr(i+1);
		}
		if (OPERATORS.find(input[i + 1]) != std::string::npos && input[i+2] != ' ') {
			input = input.substr(0, i + 2) + " " + input.substr(i + 2);
		}
	}
	if (OPERATORS.find(input[input.length()-1]) != std::string::npos && input[input.length()-2] != ' ') {
		input = input.substr(0, input.length() - 1) + " " + input.substr(input.length() - 1);
	}
	if (input[input.length() - 1] != ' ') {
		input += " ";
	}
	return input;
}

std::string Calculator::simplify(std::string input) {
	input = format(input);
	tokenise(input);
	if (tokens.size() == 1) {
		return tokens[0].getContent();
	}
	return evaluate(tokens).getContent();
}