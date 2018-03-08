#include "RationalNumber.hpp"
#include <iostream>
#include <algorithm>

bool RationalNumber::operator<(RationalNumber b) {

	if (this->isNegative && !b.isNegative) {
		return true;
	} else if (!this->isNegative && b.isNegative) {
		return false;
	} else if (this->isNegative && b.isNegative) {
		return ((double)this->num / this->den) > ((double)b.num / b.den);
	} else {
		return ((double)this->num / this->den) < ((double)b.num / b.den);
	}

}

bool RationalNumber::operator>(RationalNumber b) {

	if (this->isNegative && !b.isNegative) {
		return false;
	} else if (!this->isNegative && b.isNegative) {
		return true;
	} else if (this->isNegative && b.isNegative) {
		return ((double)this->num / this->den) < ((double)b.num / b.den);
	} else {
		return ((double)this->num / this->den) > ((double)b.num / b.den);
	}

}

bool RationalNumber::operator==(RationalNumber b) {

	return this->isNegative == b.isNegative && this->num == b.num && this->den == b.den;
	
}

bool RationalNumber::operator<=(RationalNumber b) {

	if (*this == b) {
		return true;
	}

	return *this < b;

}

bool RationalNumber::operator>=(RationalNumber b) {

	if (*this == b) {
		return true;
	}

	return *this > b;

}

bool RationalNumber::operator!=(RationalNumber b) {

	return !(*this == b);

}

RationalNumber RationalNumber::operator*(RationalNumber b) {

	return RationalNumber(this->num * b.num, this->den * b.den);

}

RationalNumber RationalNumber::operator/(RationalNumber b) {

	return RationalNumber(this->num * b.den, this->den * b.num);

}

RationalNumber RationalNumber::operator-(RationalNumber b) {

	int gcd = std::__gcd(this->den, b.den);
	int lcm = gcd ? (this->den / gcd * b.den) : 0;

	return RationalNumber((this->num * (lcm / this->den)) - (b.num * (lcm / b.den)), lcm);

}

RationalNumber RationalNumber::operator+(RationalNumber b) {

	int gcd = std::__gcd(this->den, b.den);
	int lcm = gcd ? (this->den / gcd * b.den) : 0;

	return RationalNumber((this->num * (lcm / this->den)) + (b.num * (lcm / b.den)), lcm);

}