#pragma once
#include <string>
#include "ComplexNumber.h"

typedef double(*Mapping)(double);

class Function {
private:
	bool custom = 0;
	Mapping map;
	std::string name = "";
	std::string term = "";
public:
	Function(std::string toName, Mapping toMap);
	Function(std::string toName, std::string toTerm);
	double transform(double input);
	std::string getName();
};
