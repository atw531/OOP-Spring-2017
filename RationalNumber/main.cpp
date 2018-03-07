#include <iostream>
#include <stdexcept>
#include <assert.h>
#include "RationalNumber.hpp"

int main() {

	RationalNumber n1 = RationalNumber(1, 4);
	RationalNumber n2 = RationalNumber(1, 2);
	RationalNumber n3 = RationalNumber(2, 4);
	RationalNumber n4 = RationalNumber(3, 4);
	RationalNumber n5 = RationalNumber(4, 4);
	RationalNumber n6 = RationalNumber(5, 4);
	RationalNumber n7 = RationalNumber(6, 4);
	RationalNumber n8 = RationalNumber(7, 4);
	RationalNumber n9 = RationalNumber(8, 4);

	assert(n1 < n2);
	assert(n2 == n3);
	assert(n1 < n3);
	assert(n2 > n1);
	assert(n3 > n1);
	assert(n1 != n9);
	assert(n3 != n7);

	try {
		RationalNumber invalid = RationalNumber(1, 0);
	} catch (std::invalid_argument ex) {
		std::cout << "Invalid denominator (caught correctly)\n";
	}

	return 0;
}