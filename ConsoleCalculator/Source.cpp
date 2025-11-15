#include <iostream>
#include "Calculator.h"
#include "UserInterface.h"
#include "FunctionHandler.h"

std::vector<std::shared_ptr<Function>> FunctionHandler::list;

bool isBlank(std::string str) {
	for (int i = 0; i < str.length(); i++) {
		if (str[i] != ' ') {
			return 0;
		}
	}
	return 1;
}

int main() {
	FunctionHandler::init();
	Calculator calculator = Calculator();
	UserInterface ui = UserInterface();
	std::string input = "";
	do {
		ui.printQuery();

		input = ui.getUserInput();
		if (input.empty() || isBlank(input)) {
			std::cout << "\n\n";
			continue;
		}
		if (input != "quit") {
			try {
				if (input.size() >= 6 && input.substr(0, 6) == "define") {
					FunctionHandler::parse(input);
					ui.printSpace();
				}
				else {
					ui.printOutcome(calculator.simplify(input));
				}
			}
			catch (std::invalid_argument e) {
				std::cout << e.what() << "\n\n\n";
			}
		}
	} while (input != "quit");
	return 0;
}