#pragma once
#include <cmath>
#include <string>
#include <iostream>
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
		if (abs(realPart) <= 0.00001 && abs(imaginaryPart) <= 0.00001) {
			return "0";
		}
		std::string out = "";
		if (abs(realPart) > 0.00001) {
			if (abs(realPart - round(realPart)) <= 0.00001 ) {
				out += std::to_string(int(round(realPart)));
			}
			else {
				out += std::to_string(realPart);
			}
		}
		if (abs(imaginaryPart) > 0.00001) {
			if (out.length() > 0) {
				out += imaginaryPart > 0 ? " + " : " - ";
			}
			if (abs(imaginaryPart - round(imaginaryPart)) <= 0.00001) {
				out += std::to_string(abs(int(round(imaginaryPart)))) + "i";
			}
			else {
				out += std::to_string(abs(imaginaryPart)) + "i";
			}
		}
		return out;
	}
	ComplexNumber& operator+=(const ComplexNumber& other);
	ComplexNumber& operator-=(const ComplexNumber& other);
	ComplexNumber& operator*=(const ComplexNumber& other);
	ComplexNumber& operator/=(const ComplexNumber& other);
	ComplexNumber& operator^=(const ComplexNumber& other);
};

ComplexNumber operator+(const ComplexNumber& first, const ComplexNumber& second);
ComplexNumber operator-(const ComplexNumber& first, const ComplexNumber& second);
ComplexNumber operator*(const ComplexNumber& first, const ComplexNumber& second);
ComplexNumber operator/(const ComplexNumber& first, const ComplexNumber& second);
ComplexNumber operator^(const ComplexNumber& base, const ComplexNumber& exponent);
bool operator==(const ComplexNumber& first, const ComplexNumber& second);
bool operator!=(const ComplexNumber& first, const ComplexNumber& second);

static ComplexNumber log(const ComplexNumber& number);