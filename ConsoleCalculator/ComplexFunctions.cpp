#include "ComplexFunctions.h"

ComplexNumber sin(ComplexNumber input) {
	ComplexNumber firstPart = EULERS_NUMBER ^ (ComplexNumber(0, 1) * input);
	ComplexNumber secondPart = EULERS_NUMBER ^ (ComplexNumber(0, -1) * input);
	return (firstPart - secondPart) / ComplexNumber(0,2);
}
ComplexNumber cos(ComplexNumber input) {
	ComplexNumber firstPart = EULERS_NUMBER ^ (ComplexNumber(0, 1) * input);
	ComplexNumber secondPart = EULERS_NUMBER ^ (ComplexNumber(0, -1) * input);
	return (firstPart + secondPart) / 2;
}
ComplexNumber tan(ComplexNumber input) {
	ComplexNumber sine = sin(input);
	ComplexNumber cosine = cos(input);
	return sine / cosine;
}
ComplexNumber ln(ComplexNumber input) {
	return log(input);
}