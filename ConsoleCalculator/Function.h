#pragma once
#include <string>

typedef double(*Mapping)(double);

class Function {
private:
	bool custom = 0;
	Mapping map;
	std::string name = "";
	std::string term = "";
public:
	Function(std::string toName, Mapping toMap);
	double transform(double input);
	std::string getName();
};
