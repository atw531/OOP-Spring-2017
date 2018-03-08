#pragma once

#include <algorithm>
#include <stdexcept>

class RationalNumber {

public:
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

	// Equality operators
	bool operator<(RationalNumber b);
	bool operator>(RationalNumber b);
	bool operator==(RationalNumber b);
	bool operator!=(RationalNumber b);
	bool operator<=(RationalNumber b);
	bool operator>=(RationalNumber b);

	// Arithmetic operators
	RationalNumber operator*(RationalNumber b);
	RationalNumber operator/(RationalNumber b);

private:
	int num;
	int den;
	bool isNegative;

};