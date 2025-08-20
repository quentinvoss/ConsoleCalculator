#include "Function.h"

Function::Function(std::string toName, Mapping toMap) {
	name = toName;
	map = toMap;
}

double Function::transform(double input) {
	if (!custom) {
		return map(input);
	}
}

std::string Function::getName() {
	return name;
}