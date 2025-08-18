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
	else if(op == "-") {
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

Token Calculator::evaluate(std::vector<Token> inputVector) {
	if (inputVector.size() == 3) {
		double outcome = calculate(inputVector[0].getContent(), inputVector[2].getContent(), inputVector[1].getContent());
		std::string content = (outcome == int(outcome) ? std::to_string(int(outcome)) : std::to_string(outcome));
		return Token(TokenType::NUMBER, content);
	}
}

std::string Calculator::format(std::string input) {
	return "";
}

std::string Calculator::simplify(std::string input) {
	tokenise(input + " ");
	if (tokens.size() == 1) {
		return tokens[0].getContent();
	}
	return evaluate(tokens).getContent();
}