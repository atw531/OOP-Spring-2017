#include "RationalNumber.hpp"

bool RationalNumber::operator<(const RationalNumber& b) {

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

bool RationalNumber::operator>(const RationalNumber& b) {

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

bool RationalNumber::operator==(const RationalNumber& b) {

	return this->isNegative == b.isNegative && this->num == b.num && this->den == b.den;

}

bool RationalNumber::operator<=(const RationalNumber& b) {

	if (*this == b) {
		return true;
	}

	return *this < b;

}

bool RationalNumber::operator>=(const RationalNumber& b) {

	if (*this == b) {
		return true;
	}

	return *this > b;

}

bool RationalNumber::operator!=(const RationalNumber& b) {

	return !(*this == b);

}

RationalNumber RationalNumber::operator*(const RationalNumber& b) {

	return RationalNumber(this->num * b.num, this->den * b.den);

}

RationalNumber RationalNumber::operator/(const RationalNumber& b) {

	return RationalNumber(this->num * b.den, this->den * b.num);

}

RationalNumber RationalNumber::operator-(const RationalNumber& b) {

	int gcd = std::__gcd(this->den, b.den);
	int lcm = gcd ? (this->den / gcd * b.den) : 0;

	return RationalNumber((this->num * (lcm / this->den)) - (b.num * (lcm / b.den)), lcm);

}

RationalNumber RationalNumber::operator+(const RationalNumber& b) {

	int gcd = std::__gcd(this->den, b.den);
	int lcm = gcd ? (this->den / gcd * b.den) : 0;

	return RationalNumber((this->num * (lcm / this->den)) + (b.num * (lcm / b.den)), lcm);

}

std::ostream &operator<<(std::ostream& stream, const RationalNumber& numb) {

	return stream << numb.num << "/" << numb.den;

}

std::istream &operator>>(std::istream& stream, RationalNumber& numb) {

	std::string numerator, denominator;
	std::getline(stream, numerator, '/');
	std::getline(stream, denominator);

	int num = std::atoi(numerator.c_str());
	int den = std::atoi(denominator.c_str());

	numb = RationalNumber(num, den);

	return stream;

}