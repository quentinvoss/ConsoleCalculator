#pragma once
#include <string>
#include <cmath>
#include <vector>
#include <memory>
#include <algorithm>
#include "Function.h"
#include "ComplexFunctions.h"

class FunctionHandler {

public:
	static void init() {
		list.push_back(std::make_shared<Function>(Function(std::string("sin"), (Mapping)sin)));
		list.push_back(std::make_shared<Function>(Function(std::string("cos"), (Mapping)cos)));
		list.push_back(std::make_shared<Function>(Function(std::string("tan"), (Mapping)tan)));
		list.push_back(std::make_shared<Function>(Function(std::string("ln"), (Mapping)ln)));
	}

	static std::vector<std::shared_ptr<Function>> list;

	static void parse(std::string input) {
		std::string name = "";
		std::string term = "";
		char variable = ' ';
		int i = 6;
		for (; input[i] != '='; i++) {
			if (input[i + 1] == '(') {
				variable = input[i + 2];
				if (variable == 'i') {
					throw std::invalid_argument("i cannot be used as variable");
				};
				if (variable == ')') {
					throw std::invalid_argument("No variable specified");
				};
				break;
			}
		}
		for (; input[i] != ' '; i--) {
			name += input[i];
		}
		for (; input[i] != '='; i++) {}
		term = input.substr(i + 2);
		std::replace(term.begin(), term.end(), variable, '\\');
		list.push_back(std::make_shared<Function>(Function(name, term)));
	}
};

