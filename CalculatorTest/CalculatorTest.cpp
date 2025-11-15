#include "pch.h"
#include "CppUnitTest.h"
#include "../ConsoleCalculator/Calculator.h"
#include "../ConsoleCalculator/Calculator.cpp"
#include "../ConsoleCalculator/Source.cpp"
#include "../ConsoleCalculator/Function.cpp"
#include "../ConsoleCalculator/ComplexFunctions.h"
#include "../ConsoleCalculator/FunctionHandler.h"
#include "../ConsoleCalculator/ComplexFunctions.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace CalculatorTest {

	TEST_CLASS(FunctionalityTest)
	{
	public:

		TEST_METHOD(BasicOperations)
		{
			Calculator calculator = Calculator();

			std::string expected;

			std::string result;

			expected = "7";
			result = calculator.simplify("3+4");
			Assert::AreEqual(expected, result);

			expected = "5";
			result = calculator.simplify("10-5");
			Assert::AreEqual(expected, result);

			expected = "24";
			result = calculator.simplify("6*4");
			Assert::AreEqual(expected, result);

			expected = "3";
			result = calculator.simplify("9/3");
			Assert::AreEqual(expected, result);

			expected = "8";
			result = calculator.simplify("2^3");
			Assert::AreEqual(expected, result);
		}

		TEST_METHOD(OrderOfOperations) {
			Calculator calculator = Calculator();

			std::string expected;

			std::string result;

			expected = "14";
			result = calculator.simplify("2+3*4");
			Assert::AreEqual(expected, result);

			expected = "20";
			result = calculator.simplify("(2+3)*4");
			Assert::AreEqual(expected, result);

			expected = "3";
			result = calculator.simplify("18/3-3");
			Assert::AreEqual(expected, result);

			expected = "27";
			result = calculator.simplify("3^(1+2)");
			Assert::AreEqual(expected, result);
		}

		TEST_METHOD(Format)
		{
			Calculator calculator = Calculator();

			std::string expected;

			std::string result;

			expected = "4";

			result = calculator.simplify("10+(-2)*3");

			Assert::AreEqual(expected, result);

			expected = "4";

			result = calculator.simplify("10 + ( - 2 ) * 3 ");

			Assert::AreEqual(expected, result);

			expected = "4";

			result = calculator.simplify("    10    +    (    -    2    )    *    3    ");

			Assert::AreEqual(expected, result);
		}
	};

	TEST_CLASS(FunctionTest)
	{
	public:
		TEST_METHOD(PreDefinedFunctions) {
			FunctionHandler::list.clear();
			FunctionHandler::init();
			Calculator calculator = Calculator();
			std::string expected;
			std::string result;

			expected = "0.841471";
			result = calculator.simplify("sin(1)");
			Assert::AreEqual(expected, result);

			expected = "0.540302";
			result = calculator.simplify("cos(1)");
			Assert::AreEqual(expected, result);

			expected = "1.557408";
			result = calculator.simplify("tan(1)");
			Assert::AreEqual(expected, result);

			expected = "0";
			result = calculator.simplify("ln(1)");
			Assert::AreEqual(expected, result);
		}

		TEST_METHOD(CustomFunctions) {
			FunctionHandler::list.clear();
			FunctionHandler::init();
			FunctionHandler::parse("define f(x) = x^2 + 2*x + 1");
			FunctionHandler::parse("define g(y) = sin(y) + cos(y)");
			Calculator calculator = Calculator();
			std::string expected;
			std::string result;
			expected = "16";
			result = calculator.simplify("f(3)");
			Assert::AreEqual(expected, result);
			expected = "1.381773";
			result = calculator.simplify("g(1)");
			Assert::AreEqual(expected, result);
			expected = "29";
			result = calculator.simplify("f(4) + f(1)");
			Assert::AreEqual(expected, result);
			expected = "1";
			result = calculator.simplify("f(0)");
			Assert::AreEqual(expected, result);

			expected = "2";
			result = calculator.simplify("g(0) + f(0)");
			Assert::AreEqual(expected, result);
		}

	};

	TEST_CLASS(CalculatorTest)
	{
	public:

		TEST_METHOD(FunkyResults)
		{
			Calculator calculator = Calculator();

			std::string expected = "";

			std::string result = "";

			//0^0

			expected = "Undefined Behaviour";

			try {
				calculator.simplify("0^0");
			}
			catch (std::invalid_argument e) {
				result = e.what();
			}

			Assert::AreEqual(expected, result);

			//1/0

			result = "";

			expected = "Division by Zero";

			try {
				calculator.simplify("1/0");
			}
			catch (std::invalid_argument e) {
				result = e.what();
			}

			Assert::AreEqual(expected, result);

			//0^(-1)

			result = "";

			expected = "Division by Zero";

			try {
				calculator.simplify("0^(-1)");
			}
			catch (std::invalid_argument e) {
				result = e.what();
			}

			Assert::AreEqual(expected, result);
		}

		TEST_METHOD(SyntaxErrors) {
			Calculator calculator = Calculator();

			std::string expected = "Syntax Error";

			std::string result = "";

			//to few closed brackets

			try {
				calculator.simplify("(3*(2-4)");
			}
			catch (std::invalid_argument e) {
				result = e.what();
			}

			Assert::AreEqual(expected, result);

			//to few open brackets

			result = "";

			try {
				calculator.simplify("3*(2-4))");
			}
			catch (std::invalid_argument e) {
				result = e.what();
			}

			Assert::AreEqual(expected, result);
		}
	};
}
