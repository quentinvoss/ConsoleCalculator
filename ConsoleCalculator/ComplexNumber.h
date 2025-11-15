#pragma once
#include <cmath>
#include <string>
#define EULERS_NUMBER 2.71828182845904523536028

class ComplexNumber {
private:
	double realPart;
	double imaginaryPart;
	double magnitudeNumber;
public:
	ComplexNumber(double toReal, double toImaginary = 0) : realPart(toReal), imaginaryPart(toImaginary) {
		magnitudeNumber = sqrt(realPart * realPart + imaginaryPart * imaginaryPart);
	}
	double real() const {
		return realPart;
	}
	double imaginary() const {
		return imaginaryPart;
	}
	double magnitude() const {
		return magnitudeNumber;
	}
	std::string toString() const {
		std::string out = "";
		out += std::to_string(realPart);
		if (std::to_string(imaginaryPart) != "0") {
			out += " + " + std::to_string(imaginaryPart) + "i";
		}
		return out;
	}
	ComplexNumber& operator+=(const ComplexNumber& other);
	ComplexNumber& operator-=(const ComplexNumber& other);
	ComplexNumber& operator*=(const ComplexNumber& other);
	ComplexNumber& operator/=(const ComplexNumber& other);
	ComplexNumber& operator^=(const ComplexNumber& other);
};

static ComplexNumber log(const ComplexNumber& number);