#include <iostream>
#include "Calculator.h"
#include "UserInterface.h"

int main() {
	Calculator calculator = Calculator();
	UserInterface ui = UserInterface();
	std::string input = "";
	do {
		ui.printQuery();
		input = ui.getUserInput();
		if (input != "quit") {
			calculator = Calculator();
			try {
				ui.printOutcome(calculator.simplify(input));
			}
			catch (std::invalid_argument e) {
				std::cout << e.what() << "\n\n\n";
			}
		}
	} while (input != "quit");
	return 0;
}