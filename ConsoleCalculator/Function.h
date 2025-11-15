#pragma once
#include <string>
#include "ComplexNumber.h"

typedef ComplexNumber(*Mapping)(ComplexNumber);

class Function {
private:
	bool custom = 0;
	Mapping map;
	std::string name = "";
	std::string term = "";
public:
	Function(std::string toName, Mapping toMap);
	Function(std::string toName, std::string toTerm);
	ComplexNumber transform(ComplexNumber input);
	std::string getName();
};
