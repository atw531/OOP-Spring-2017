#pragma once

#include <algorithm>
#include <stdexcept>

class RationalNumber {

public:

	int num;
	int den;

	RationalNumber(int numerator, int denominator)
		: num(numerator), den(denominator) {

		// Check valid denominator
		if (denominator == 0) {
			// Invalid - Cannot divide by zero
			throw std::invalid_argument("Invalid Denominator - Cannot divide by zero");
		}

		// Set isNegative flag
		if (num < 0 && den > 0) {
			isNegative = true;
			num *= -1;
		} else if (num > 0 && den < 0) {
			isNegative = true;
			den *= -1;
		} else if (num < 0 && den < 0) {
			isNegative = false;
			num *= -1;
			den *= -1;
		} else {
			isNegative = false;
		}

		// Simplify the rational number
		int gcd = std::__gcd(num, den);
		num /= gcd;
		den /= gcd;

	}

	bool operator<(RationalNumber b);
	bool operator>(RationalNumber b);
	bool operator==(RationalNumber b);
	bool operator!=(RationalNumber b);

private:
	bool isNegative;

};