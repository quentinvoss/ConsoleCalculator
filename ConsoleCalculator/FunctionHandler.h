#pragma once
#include <string>
#include <cmath>
#include <vector>
#include <memory>
#include "Function.h"

class FunctionHandler {

public:
	static void init() {
		list.push_back(std::make_shared<Function>(Function(std::string("sin"), (Mapping)std::sin)));
		list.push_back(std::make_shared<Function>(Function(std::string("cos"), (Mapping)std::cos)));
		list.push_back(std::make_shared<Function>(Function(std::string("tan"), (Mapping)std::tan)));
		list.push_back(std::make_shared<Function>(Function(std::string("ln"), (Mapping)std::log)));
	}

	static std::vector<std::shared_ptr<Function>> list;
};

