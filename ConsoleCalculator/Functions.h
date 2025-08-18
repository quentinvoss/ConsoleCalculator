#pragma once
#include <string>
#include <cmath>
namespace Functions {
	const int numberOfFunctions = 4;
	const std::string names[numberOfFunctions] = { "sin","cos","tan","ln" };
	double sin(double input);
	double cos(double input);
	double tan(double input);
	double ln(double input);
}