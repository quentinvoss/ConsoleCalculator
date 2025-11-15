#include "ComplexNumber.h"

static ComplexNumber operator+(const ComplexNumber& first,const ComplexNumber& second) {
	return ComplexNumber(first.real() + second.real(), first.imaginary() + second.imaginary());
}

static ComplexNumber operator-(const ComplexNumber& first, const ComplexNumber& second) {
	return ComplexNumber(first.real() - second.real(), first.imaginary() - second.imaginary());
}

static ComplexNumber operator*(const ComplexNumber& first, const ComplexNumber& second) {
	return ComplexNumber(first.real() * second.real() - first.imaginary() * second.imaginary(),
		first.real() * second.imaginary() + first.imaginary() * second.real());
}

static ComplexNumber operator/(const ComplexNumber& first, const ComplexNumber& second) {
	double firstReal = first.real();
	double firstImaginary = first.imaginary();
	double secondReal = second.real();
	double secondImaginary = second.imaginary();
	double real = ((firstReal * secondReal) / (secondReal * secondReal + secondImaginary * secondImaginary)) + ((firstImaginary * secondImaginary) / (secondReal * secondReal + secondImaginary * secondImaginary));
	double imaginary = ((firstImaginary * secondReal) / (secondReal * secondReal + secondImaginary * secondImaginary)) - ((firstReal * secondImaginary) / (secondReal * secondReal + secondImaginary * secondImaginary));
	return ComplexNumber(real, imaginary);
}

static ComplexNumber operator^(const double& base, const ComplexNumber& exponent) {
	double firstPart = exp(log(base) * exponent.real());
	ComplexNumber secondPart = ComplexNumber(cos(log(base) * exponent.imaginary()),sin(log(base) * exponent.imaginary()));
	return firstPart * secondPart;
}

static ComplexNumber operator^(const ComplexNumber& base, const ComplexNumber& exponent) {
	ComplexNumber tempExponent = log(base) * exponent;
	return EULERS_NUMBER ^ tempExponent;
}

ComplexNumber& ComplexNumber::operator+=(const ComplexNumber& other) {
	ComplexNumber result = *this + other;
	realPart = result.real();
	imaginaryPart = result.imaginary();
	magnitudeNumber = sqrt(realPart * realPart + imaginaryPart * imaginaryPart);
	return *this;
}
ComplexNumber& ComplexNumber::operator-=(const ComplexNumber& other) {
	ComplexNumber result = *this - other;
	realPart = result.real();
	imaginaryPart = result.imaginary();
	magnitudeNumber = sqrt(realPart * realPart + imaginaryPart * imaginaryPart);
	return *this;
}
ComplexNumber& ComplexNumber::operator*=(const ComplexNumber& other) {
	ComplexNumber result = *this * other;
	realPart = result.real();
	imaginaryPart = result.imaginary();
	magnitudeNumber = sqrt(realPart * realPart + imaginaryPart * imaginaryPart);
	return *this;
}
ComplexNumber& ComplexNumber::operator/=(const ComplexNumber& other) {
	ComplexNumber result = *this / other;
	realPart = result.real();
	imaginaryPart = result.imaginary();
	magnitudeNumber = sqrt(realPart * realPart + imaginaryPart * imaginaryPart);
	return *this;
}
ComplexNumber& ComplexNumber::operator^=(const ComplexNumber& other) {
	ComplexNumber result = *this ^ other;
	realPart = result.real();
	imaginaryPart = result.imaginary();
	magnitudeNumber = sqrt(realPart * realPart + imaginaryPart * imaginaryPart);
	return *this;
}


static ComplexNumber log(const ComplexNumber& number) {
	double magnitude = number.magnitude();
	double angle = atan2(number.imaginary(), number.real());
	return ComplexNumber(log(magnitude), angle);
}