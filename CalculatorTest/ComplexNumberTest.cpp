#include "pch.h"
#include "CppUnitTest.h"
#include "../ConsoleCalculator/ComplexNumber.h"
#include "../ConsoleCalculator/ComplexNumber.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace ComplexNumberTest {
	TEST_CLASS(ComplexNumberTest)
	{
	public:
		TEST_METHOD(Addition)
		{
			ComplexNumber num1(2, 3);
			ComplexNumber num2(4, 5);
			ComplexNumber result = num1 + num2;
			Assert::AreEqual(6.0, result.real());
			Assert::AreEqual(8.0, result.imaginary());

			num1 += num2;
			Assert::AreEqual(6.0, num1.real());
			Assert::AreEqual(8.0, num1.imaginary());
		}

		TEST_METHOD(AdditionWithDouble) {
			ComplexNumber num1(2, 3);
			double num2 = 4.0;
			ComplexNumber result = num1 + num2;
			Assert::AreEqual(6.0, result.real());
			Assert::AreEqual(3.0, result.imaginary());


			result = num2 + num1;
			Assert::AreEqual(6.0, result.real());
			Assert::AreEqual(3.0, result.imaginary());
		}
		TEST_METHOD(Subtraction)
		{
			ComplexNumber num1(5, 7);
			ComplexNumber num2(2, 3);
			ComplexNumber result = num1 - num2;
			Assert::AreEqual(3.0, result.real());
			Assert::AreEqual(4.0, result.imaginary());

			num1 -= num2;
			Assert::AreEqual(3.0, num1.real());
			Assert::AreEqual(4.0, num1.imaginary());
		}

		TEST_METHOD(SubtractionWithDouble) {
			ComplexNumber num1(5, 7);
			double num2 = 2.0;
			ComplexNumber result = num1 - num2;
			Assert::AreEqual(3.0, result.real());
			Assert::AreEqual(7.0, result.imaginary());

			result = num2 - num1;
			Assert::AreEqual(-3.0, result.real());
			Assert::AreEqual(-7.0, result.imaginary());
		}

		TEST_METHOD(Multiplication)
		{
			ComplexNumber num1(1, 2);
			ComplexNumber num2(3, 4);
			ComplexNumber result = num1 * num2;
			Assert::AreEqual(-5.0, result.real());
			Assert::AreEqual(10.0, result.imaginary());

			num1 *= num2;
			Assert::AreEqual(-5.0, num1.real());
			Assert::AreEqual(10.0, num1.imaginary());
		}

		TEST_METHOD(MultiplicationWithDouble) {
			ComplexNumber num1(1, 2);
			double num2 = 3.0;
			ComplexNumber result = num1 * num2;
			Assert::AreEqual(3.0, result.real());
			Assert::AreEqual(6.0, result.imaginary());

			result = num2 * num1;
			Assert::AreEqual(3.0, result.real());
			Assert::AreEqual(6.0, result.imaginary());
		}
		TEST_METHOD(Division)
		{
			ComplexNumber num1(5, 6);
			ComplexNumber num2(1, 2);
			ComplexNumber result = num1 / num2;
			Assert::AreEqual(3.4, result.real(), 0.0001);
			Assert::AreEqual(-0.8, result.imaginary(), 0.0001);
			num1 /= num2;
			Assert::AreEqual(3.4, num1.real(), 0.0001);
			Assert::AreEqual(-0.8, num1.imaginary(), 0.0001);
		}

		TEST_METHOD(DivisionWithDouble) {
			ComplexNumber num1(5, 6);
			double num2 = 2.0;
			ComplexNumber result = num1 / num2;
			Assert::AreEqual(2.5, result.real());
			Assert::AreEqual(3.0, result.imaginary());

			result = num2 / num1;
			Assert::AreEqual(0.163934, result.real(), 0.0001);
			Assert::AreEqual(-0.196721, result.imaginary(), 0.0001);
		}

		TEST_METHOD(Logarithm) {
			ComplexNumber num(1, 0);
			ComplexNumber result = log(num);
			Assert::AreEqual(0.0, result.real(), 0.0001);
			Assert::AreEqual(0.0, result.imaginary(), 0.0001);
			num = ComplexNumber(0, 1);
			result = log(num);
			Assert::AreEqual(0.0, result.real(), 0.0001);
			Assert::AreEqual(1.5708, result.imaginary(), 0.0001);
			num = ComplexNumber(-1, 0);
			result = log(num);
			Assert::AreEqual(0.0, result.real(), 0.0001);
			Assert::AreEqual(3.14159, result.imaginary(), 0.0001);
		}

		TEST_METHOD(Exponentiation) {
			ComplexNumber base(2, 0);
			ComplexNumber exponent(3, 0);
			ComplexNumber result = base ^ exponent;
			Assert::AreEqual(8.0, result.real(), 0.0001);
			Assert::AreEqual(0.0, result.imaginary(), 0.0001);
			
			base ^= exponent;
			Assert::AreEqual(8.0, base.real(), 0.0001);
			Assert::AreEqual(0.0, base.imaginary(), 0.0001);

			base = ComplexNumber(EULERS_NUMBER, 0);
			exponent = ComplexNumber(0, 3.1415926);
			result = base ^ exponent;
			Assert::AreEqual(-1.0, result.real(), 0.0001);
			Assert::AreEqual(0.0, result.imaginary(), 0.0001);

			base ^= exponent;
			Assert::AreEqual(-1.0, base.real(), 0.0001);
			Assert::AreEqual(0.0, base.imaginary(), 0.0001);
		}
	};
}