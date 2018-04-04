#pragma once

#include <algorithm>
#include <stdexcept>
#include <iostream>

class RationalNumber {

public:
	int num;
	int den;

	RationalNumber() {

	}

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

	// Copy constructor
	RationalNumber& operator=(const RationalNumber& b) {
		this->num = b.num;
		this->den = b.den;

		return *this;
	}

	// Equality operators
	bool operator<(const RationalNumber& b);
	bool operator>(const RationalNumber& b);
	bool operator==(const RationalNumber& b);
	bool operator!=(const RationalNumber& b);
	bool operator<=(const RationalNumber& b);
	bool operator>=(const RationalNumber& b);

	// Arithmetic operators
	RationalNumber operator*(const RationalNumber& b);
	RationalNumber operator/(const RationalNumber& b);
	RationalNumber operator-(const RationalNumber& b);
	RationalNumber operator+(const RationalNumber& b);

	// Input/Output
	friend std::ostream &operator<<(std::ostream& stream, const RationalNumber& numb);
	friend std::istream &operator>>(std::istream& stream, RationalNumber& numb);

private:
	bool isNegative;

};

/*
RationalNumber operator-(RationalNumber a, RationalNumber b) {

	int lcm = lcm(a.den, b.den);

	return RationalNumber((a.num * lcm) - (b.num * lcm), lcm);

};

RationalNumber operator+(RationalNumber a, RationalNumber b) {

	int lcm = lcm(a.den, b.den);

	return RationalNumber((a.num * lcm) - (b.num * lcm), lcm)

};

int lcm(int a, int b) {

	int gcd = std::__gcd(a, b);
	int lcm = gcd ? (a / gcd * b) : 0;

};
*/