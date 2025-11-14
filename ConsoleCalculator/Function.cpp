#include "Function.h"
#include "Calculator.h"

Function::Function(std::string toName, Mapping toMap) {
	name = toName;
	map = toMap;
}

Function::Function(std::string toName, std::string toTerm) {
	custom = 1;
	name = toName;
	term = toTerm;
}

std::string insertNum(std::string input, double num) {
	std::string out = "";
	std::string numStr = std::to_string(num);
	if (num < 0) {
		numStr = "(" + numStr + ")";
	}
	for (char c : input) {
		if (c == '\\') {
			out += numStr;
		}
		else {
			out += c;
		}
	}
	return out;
}

Calculator calculator = Calculator();

double Function::transform(double input) {
	if (!custom) {
		return map(input);
	}
	else {
		return std::stod(calculator.simplify(insertNum(term, input)));
	}
}

std::string Function::getName() {
	return name;
}